#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "string.h"
#include "utn.h"

#define LEN_NOMBRE 128


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile = NULL;

	pFile = fopen (path, "r");

	if (pFile != NULL && pArrayListEmployee != NULL)
	{
		parser_EmployeeFromText(pFile , pArrayListEmployee);
		printf ("\n\n\nSe cargo el archivo \"data.csv\" correctamente\n\n\n");
	}
	else
	{
		printf("Error al abrir el archivo\n");
	}

	fclose(pFile);

    return 1;
}


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile = NULL;

	pFile = fopen(path, "rb");

	if (pFile != NULL && pArrayListEmployee != NULL)
	{
		parser_EmployeeFromBinary(pFile, pArrayListEmployee);
		printf("\n\n\nSe cargo el archivo \"data.dat\" correctamente\n\n\n");
	}
	else
	{
		printf("Error al abrir el archivo\n");
	}

	fclose(pFile);

    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* id)
{
		Employee* pEmployee = NULL;
		int retorno = -1;
		int horasTrabajadas, sueldo;
		char nombre [LEN_NOMBRE];

		pEmployee = employee_new();

		if (pArrayListEmployee != NULL && pEmployee != NULL)
		{
			if (!utn_getNombre (nombre, LEN_NOMBRE, "Ingrese el nombre del empleado: \n", "ERROR\n", 2)
			&& !utn_getNumero (&horasTrabajadas, "Ingrese las horas trabajadas: \n", "ERROR\n", 1, 100000, 2)
			&& !utn_getNumero (&sueldo, "Ingrese el sueldo: \n", "ERROR\n", 1, 300000, 2))
			{
				retorno = 0;
				employee_setNombre(pEmployee, nombre);
				employee_setHorasTrabajadas(pEmployee, horasTrabajadas);
				employee_setSueldo(pEmployee, sueldo);
				employee_setId(pEmployee, *id);
				(*id)++;

				ll_add(pArrayListEmployee, pEmployee);
			}
		}
		if (retorno != 0)
		{
			free(pEmployee);
		}
		return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	Employee* pEmployee = NULL;
	int retorno = -1;
	int idMod, indexMod, size, i;

	size = ll_len(pArrayListEmployee);

	if (pArrayListEmployee != NULL)
	{
		utn_getNumero (&idMod, "Ingrese el id que desea modificar: \n", "ERROR\n", 1, 100000, 2);

		for (i=0;i<size;i++)
		{
			pEmployee = ll_get(pArrayListEmployee, i);
			indexMod = ll_indexOf(pArrayListEmployee, pEmployee);

			if (indexMod == idMod-1)
			{
				menuEmployee(pEmployee);
			}

			else
			{
				printf("No se ha encontrado el id del empleado\n");
			}

		}

	}

    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	Employee* pEmployee = NULL;
	int retorno = -1;
	int idMod;


	if (pArrayListEmployee != NULL)
	{
		utn_getNumero (&idMod, "Ingrese el id que desea eliminar: \n", "ERROR\n", 1, 100000, 2);

		pEmployee = ll_pop(pArrayListEmployee, idMod-1);
		free(pEmployee);
	}

    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
		Employee* auxEmployee;
		int retorno = -1;
		int i;
		int id, horasTrabajadas, sueldo, size;
		char nombre[20];

		size = ll_len(pArrayListEmployee);
		if (pArrayListEmployee != NULL)
		{
			printf("\tID\t\t NOMBRE\t\t HORAS DE TRABAJO\t\t SUELDO\n\n");
			for (i=0;i<size;i++)
			{
				auxEmployee = (Employee*)ll_get(pArrayListEmployee, i);
				employee_getId(auxEmployee,&id);
				employee_getNombre(auxEmployee,nombre);
				employee_getHorasTrabajadas(auxEmployee,&horasTrabajadas);
				employee_getSueldo(auxEmployee,&sueldo);
				printf ("%11d %19s %19d %28d\n", id, nombre, horasTrabajadas, sueldo);
				retorno = 0;
			}
		}
		return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int opcion, orden;

	do
	{
	utn_getNumero(&opcion, "1.ID\n"
						   "2.Nombre\n"
						   "3.Horas de Trabajo\n"
						   "4.Sueldo\n"
						   "5.No ordenar y salir\n"
						   "Que campo desea ordenar: \n", "ERROR\n", 1, 4, 2);

	utn_getNumero(&orden, "0.Orden Ascendente\n"
						  "1.Orden Descendente\n"
						  "Elige el orden: \n",
						  "ERROR\n", 0, 1, 2);

			switch(opcion)
			{
			case 1:
				ll_sort(pArrayListEmployee, compareById, orden);
				break;
			case 2:
				ll_sort(pArrayListEmployee, compareByName, orden);
				break;
			case 3:
				ll_sort(pArrayListEmployee, compareByHoursWorked, orden);
				break;
			case 4:
				ll_sort(pArrayListEmployee, compareBySalary, orden);
				break;
			case 5:
				break;

				retorno = 0;
			}
	}while(0);


return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	Employee* pEmployee;
	int retorno = -1;
	int i, size;
	int id, horasTrabajadas, sueldo;
	char nombre[100];

	if(path != NULL && pArrayListEmployee != NULL)
	{

	pFile = fopen(path, "w");

	if (pFile != NULL)
    {
        fprintf(pFile, "id, nombre, horasTrabajadas, sueldo\n");

        size = ll_len(pArrayListEmployee);
        for(i=0; i<size; i++)
        {
            pEmployee = (Employee*)ll_get(pArrayListEmployee, i);

            if(employee_getId(pEmployee, &id) == 1
            && employee_getNombre(pEmployee, nombre)==1
            && employee_getHorasTrabajadas(pEmployee, &horasTrabajadas)==1
			&& employee_getSueldo(pEmployee, &sueldo)==1)
            {
                fprintf(pFile, "%d, %s, %d, %d\n", id, nombre, horasTrabajadas, sueldo);
                retorno = 0;
            }
        }
        fclose(pFile);

    }
	}
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
		FILE* pFile;
		Employee* pEmployee;
		int retorno = -1;
		int i, size;

		if(path != NULL && pArrayListEmployee != NULL)
		{

		pFile = fopen(path, "wb");

		if (pFile != NULL)
		{
	        size = ll_len(pArrayListEmployee);
	        for(i=0; i<size; i++)
	        {
	            pEmployee = (Employee*)ll_get(pArrayListEmployee, i);

	            fwrite(pEmployee, sizeof(Employee), 1, pFile);
	        }
	        fclose(pFile);

	    }
		}
	    return retorno;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

/** \brief Crea un nuevo empleado en memoria
 * \return el empleado creado
 */
Employee* employee_new()
{
	Employee* pEmployee;

	pEmployee = (Employee*)malloc(sizeof (Employee));

	return pEmployee;
}

/** \brief Asigna parametros al empleado
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return el empleado parametrizado
 *
 */
Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* pEmployee = NULL;

	pEmployee = employee_new();

	if (pEmployee != NULL)
	{
			employee_setId(pEmployee, atoi(idStr));
			employee_setNombre(pEmployee, nombreStr);
			employee_setHorasTrabajadas(pEmployee, atoi(horasTrabajadasStr));
			employee_setSueldo(pEmployee, atoi(sueldoStr));
	}
	return pEmployee;
}

/** \brief entrega el valor buscado
 * \param  this Employee*
 * \param id int*
 * \return si tuvo exito(1) sino (0)
 *
 */
int employee_getId(Employee* this, int* id)
{
	int exito = 0;

	if (this != NULL)
	{
		*id = this->id;
		exito = 1;
	}

	return exito;
}

/** \brief setea al valor que se le pasa por parametro
 * \param  this Employee*
 * \param id int*
 * \return si tuvo exito(1) sino (0)
 *
 */
int employee_setId(Employee* this, int id)
{
	int exito = 0;

	if (this != NULL)
	{
		this->id = id;
		exito = 1;
	}

	return exito;
}

/** \brief entrega el valor buscado
 * \param  this Employee*
 * \param nombre char*
 * \return si tuvo exito(1) sino (0)
 *
 */
int employee_getNombre(Employee* this, char* nombre)
{
	int exito = 0;

	if (this != NULL)
	{
		strcpy(nombre, this->nombre);
		exito = 1;
	}

	return exito;
}

/** \brief setea al valor que se le pasa por parametro
 * \param  this Employee*
 * \param nombre char*
 * \return si tuvo exito(1) sino (0)
 *
 */
int employee_setNombre(Employee* this, char* nombre)
{
	int exito = 0;

	if (this != NULL)
	{
		strcpy(this->nombre, nombre);
		exito = 1;
	}

	return exito;
}

/** \brief entrega el valor buscado
 * \param  this Employee*
 * \param horasTrabajadas int*
 * \return si tuvo exito(1) sino (0)
 *
 */
int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
	int exito = 0;

	if (this != NULL)
	{
	*horasTrabajadas = this->horasTrabajadas;
	exito = 1;
	}
	return exito;
}

/** \brief setea al valor que se le pasa por parametro
 * \param  this Employee*
 * \param horasTrabajadas int*
 * \return si tuvo exito(1) sino (0)
 *
 */
int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
	int exito = 0;

	if (this != NULL)
	{
	this->horasTrabajadas = horasTrabajadas;
	exito = 1;
	}
	return exito;
}

/** \brief entrega un valor buscado
 * \param  this Employee*
 * \param sueldo int*
 * \return si tuvo exito(1) sino (0)
 *
 */
int employee_getSueldo(Employee* this, int* sueldo)
{
	int exito = 0;

	if (this != NULL)
	{
	*sueldo = this->sueldo;
	exito = 1;
	}
	return exito;
}

/** \brief setea al valor que se le pasa por parametro
 * \param  this Employee*
 * \param sueldo int*
 * \return si tuvo exito(1) sino (0)
 *
 */
int employee_setSueldo(Employee* this, int sueldo)
{
	int exito = 0;

	if (this != NULL)
	{
	this->sueldo = sueldo;
	exito = 1;
	}
	return exito;
}

/** \brief elimina un empleado
 * \param  this Employee*
 * \return void
 */
void employee_delete(Employee* pEmployee)
{
	if (pEmployee != NULL)
	{
	free(pEmployee);
	}
}

/** \brief compara dos empleados por id
 * \param  this1 void*
 * \param  this2 void*
 * \return int (0) para ordenar ascendente y (1) descendente
 */
int compareById(void* this1, void* this2)
{
	Employee* auxThis1;
	Employee* auxThis2;
	int id1, id2;
	int retorno = -1;

	if (this1 != NULL && this2 != NULL)
	{
		auxThis1 = (Employee*)this1;
		auxThis2 = (Employee*)this2;

		employee_getId(auxThis1, &id1);
		employee_getId(auxThis2, &id2);

		if (id1 > id2)
		{
			retorno = 0;
		}
		else
		{
			retorno = 1;
		}
	}
	return retorno;
}

/** \brief compara dos empleados por nombre
 * \param  this1 void*
 * \param  this2 void*
 * \return int (0) para ordenar ascendente y (1) descendente
 */
int compareByName(void* this1, void* this2)
{
	Employee* auxThis1;
	Employee* auxThis2;
	char nombre1[100], nombre2 [100];
	int retorno = -1;

	if (this1 != NULL && this2 != NULL)
	{
		auxThis1 = (Employee*)this1;
		auxThis2 = (Employee*)this2;

		employee_getNombre(auxThis1, nombre1);
		employee_getNombre(auxThis2, nombre2);

		retorno = strcmp(nombre1, nombre2);
	}
	return retorno;
}

/** \brief compara dos empleados por horas trabajadas
 * \param  this1 void*
 * \param  this2 void*
 * \return int (0) para ordenar ascendente y (1) descendente
 */
int compareByHoursWorked(void* this1, void* this2)
{
	Employee* auxThis1;
	Employee* auxThis2;
	int horas1, horas2;
	int retorno = -1;

	if (this1 != NULL && this2 != NULL)
	{
		auxThis1 = (Employee*)this1;
		auxThis2 = (Employee*)this2;

		employee_getHorasTrabajadas(auxThis1, &horas1);
		employee_getHorasTrabajadas(auxThis2, &horas2);

		if (horas1 > horas2)
		{
			retorno = 0;
		}
		else
		{
			retorno = 1;
		}
	}
	return retorno;
}

/** \brief compara dos empleados por sueldo
 * \param  this1 void*
 * \param  this2 void*
 * \return int (0) para ordenar ascendente y (1) descendente
 */
int compareBySalary(void* this1, void* this2)
{
	Employee* auxThis1;
	Employee* auxThis2;
	int sueldo1, sueldo2;
	int retorno = -1;

	if (this1 != NULL && this2 != NULL)
	{
		auxThis1 = (Employee*)this1;
		auxThis2 = (Employee*)this2;

		employee_getSueldo(auxThis1, &sueldo1);
		employee_getSueldo(auxThis2, &sueldo2);

		if (sueldo1 > sueldo2)
		{
			retorno = 0;
		}
		else
		{
			retorno = 1;
		}
	}
	return retorno;
}

/** \brief despliega el menu modificar
 * \param  pEmployee Employee*
 * \return int (0) para ordenar ascendente y (1) descendente
 */
int menuEmployee(Employee* pEmployee)
{
	int retorno = -1;
	int opcion;
	char nombre [128];
	int horasTrabajadas, sueldo;

	do
	{
	utn_getNumero(&opcion, "1.Nombre\n"
						   "2.Horas de Trabajo\n"
						   "3.Sueldo\n"
						   "4.No modificar y salir\n"
						   "Que campo desea modificar: \n", "ERROR\n", 1, 4, 2);

			switch(opcion)
			{
			case 1:
				utn_getNombre(nombre, 128, "Ingrese el nuevo nombre: \n", "ERROR\n", 2);
				if (employee_setNombre(pEmployee, nombre) == 1)
				{
					printf ("\n\n\nEl campo nombre ha sido modificado\n\n\n");
				}
				else
				{
					printf("\n\n\nNo se pudo modificar el campo nombre\n\n\n");
				}
				break;
			case 2:
				utn_getNumero(&horasTrabajadas, "Ingrese la horas trabajadas: \n", "ERROR\n", 1, 10000, 2);
				if (employee_setHorasTrabajadas(pEmployee, horasTrabajadas) == 1)
				{
					printf ("\n\n\nEl campo horas trabajadas ha sido modificado\n\n\n");
				}
				else
				{
					printf("\n\n\nNo se pudo modificar el campo horas trabajadas\n\n\n");
				}
				break;
			case 3:
				utn_getNumero(&sueldo, "Ingrese el nuevo sueldo: \n", "ERROR\n", 1, 1000000, 2);
				if (employee_setSueldo(pEmployee, sueldo) == 1)
				{
					printf ("\n\n\nEl campo sueldo ha sido modificado\n\n\n");
				}
				else
				{
					printf("\n\n\nNo se pudo modificar el campo sueldo\n\n\n");
				}
				break;
			case 4:
				break;

				retorno = 0;
			}
	}while(0);


return retorno;
}

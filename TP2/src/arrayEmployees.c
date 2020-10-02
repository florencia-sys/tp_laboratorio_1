/*
 * Empleado.c
 *
 *  Created on: 14 may. 2020
 *      Author: flors
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployees.h"
#include "utn.h"

#define NAME_ELEMENTS 51
#define LASTNAME_ELEMENTS 51

#define TRUE 1
#define FALSE 0

/** \brief  Imprime las posiciones del array ocupadas
 * \param   list Employee* Puntero al array de Employees
 * \param   len int Longitud del array
 * \return  int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (0) si no hay Error * *
  */
int printArray (Employee* list, int len)
{
	int retorno = -1;
	int i;

	if (list != NULL && len > 0)
	{
		for (i=0;i<len;i++)
		{
			if (list[i].isEmpty == 0)
			{
			retorno = 0;
			printf ("Id: %7d - Nombre: %7s - Apellido: %7s - Salario: %.2f - Sector: %7d\n", list[i].id, list[i].name, list[i].lastName, list[i].salary, list[i].sector);
			}
		}
	}
	return retorno;
}
/** \brief  Indica que posicion del array esta libre,
 *  		esta funcion pone la bandera (isEmpty) en TRUE en todas
 * 			las posiciones del array
 * \param   list Employee* Puntero al array de Employees
 * \param   len int Longitud del array
 * \return  int Return (-1) si hay un Error [Longitud invalida o puntero NULL]
 * 			o (0) si no hay Error * *
 *
 */
int initEmployees(Employee* list, int len)
{
	int retorno = -1;
	int i;

	if (list != NULL && len >= 0)
	{
		for (i=0;i<len;i++)
		{
		list[i].isEmpty = 1;
		}
		retorno = 0;
	}
	return retorno;
}

/** \brief  Indica que posicion del array esta libre,
 *  		esta funcion pone la bandera (isEmpty) en TRUE en todas
 * 			las posiciones del array
 * \param   list Employee* Puntero al array de Employees
 * \param   len int Longitud del array
 * \return  int Return (-1) si hay un Error [Longitud invalida o puntero NULL]
 * 			o el indice del primer elemento del array encontrado libre
 */
int getEmptyIndex (Employee* list, int len)
{
	int index = -1;
	int i;

	if (list != NULL && len > 0)
	{
		for (i=0;i<len;i++)
		{
			if (list[i].isEmpty == 1)
			{
				index = i;
				break;
			}
		}
	}
	return index;
}

/** \brief  Indica si el array esta libre
 * \param   list Employee* Puntero al array de Employees
 * \param   len int Longitud del array
 * \return  int Return (-1) si hay un Error [Longitud invalida o puntero NULL]
 * 			o (0) si al menos una posicion del array esta ocupada
 */
int allEmpty (Employee* list, int len)
{
	int retorno = -1;
	int i;

	if (list != NULL && len > 0)
	{
		for (i=0;i<len;i++)
		{
			if (list[i].isEmpty == 0)
			{
				retorno = 0;
				break;

			}
		}
	}

	return retorno;
}

/** \brief   Crea un empleado en memoria
 * \param    list Employee* Puntero al array de Employees
 * \param    len int Longitud del array
 * \param    *id int Puntero al id del empleado
 * \param    name* char Nombre del empleado
 * \param    lastName* char Apellido del empleado
 * \param    salary float Salario del empleado
 * \param    sector int Sector del empleado
 * \param    indice int Indice del array donde se va a crear el empleado
 * \return   int Return (-1) si hay un Error [Longitud invalida o puntero NULL]
 * 			 o (0) si no hay Error * *
 *
 */
int addEmployee(Employee* list, int len, int *id, char name[],char lastName[],float salary,int sector, int indice)
{
	int retorno = -1;
	Employee bufferEmployee;

	if (list != NULL && len > 0 && id != NULL && indice<len && len > 0)
	{
		if (!utn_getNombre(bufferEmployee.name, NAME_ELEMENTS, "Nombre: \n", "ERROR\n", 2) &&
		!utn_getNombre(bufferEmployee.lastName, LASTNAME_ELEMENTS, "Apellido: \n", "ERROR\n", 2) &&
		!utn_getNumeroFlotante(&bufferEmployee.salary, "Salario: \n", "ERROR\n", 1, 1000000, 2) &&
		!utn_getNumero(&bufferEmployee.sector, "Sector: \n", "ERROR\n", 1, 60, 2))
			{
				retorno = 0;
				bufferEmployee.isEmpty = 0;
				bufferEmployee.id = *id;
				list[indice] = bufferEmployee;
				(*id)++;
			}
	}
return retorno;
}
/** \brief  Busca un empleado por id y devuelve su indice
 * \param   list Employee* Puntero al array de Employees
 * \param   len int Longitud del array
 * \param   id* int Puntero al id del empleado buscado
 * \return  int Return (-1) si hay un Error [Longitud invalida o puntero NULL]
 * 			o (0) si encontro el indice * *
 *
 */
int findEmployeeById ( Employee* list, int len, int* id)
{
	int index = -1;
	int i;

	if (list != NULL && len > 0)
	{
		for (i=0;i<len;i++)
		{
			if ( list[i].id == *id )
			{
				index = i;
				break;
			}
		}
	}
	return index;
}

/** \brief  modifica el array
 * \param   list Employee* Puntero al array de Employees
 * \param   len int Longitud del array
 * \param   indice int Indice a modificar
 * \return  int Return (-1) si hay un Error [Longitud invalida o puntero NULL]
 * 			o (0) si no hay Error * *
 *
 */
int modifyEmployee(Employee* list, int len, int indice)
{
	int retorno = -1;
	Employee bufferEmployee;

	if (list != NULL && len > 0 && indice<len && len > 0 && list[indice].isEmpty == 0)
	{
		if (!utn_getNombre(bufferEmployee.name, NAME_ELEMENTS, "Nombre: \n", "ERROR", 2) &&
		!utn_getNombre(bufferEmployee.lastName, LASTNAME_ELEMENTS, "Apellido: \n", "ERROR", 2) &&
		!utn_getNumeroFlotante(&bufferEmployee.salary, "Salario: \n", "ERROR", 1, 1000000, 2) &&
		!utn_getNumero(&bufferEmployee.sector, "Sector: \n", "ERROR", 1, 60, 2))
			{
				retorno = 0;
				bufferEmployee.isEmpty = 0;
				bufferEmployee.id = list[indice].id;
				list[indice] = bufferEmployee;
			}
	}
return retorno;
}
/** \brief  Elimina un empleado del array
 * \param   list Employee* Puntero al array de Employees
 * \param   len int Longitud del array
 * \param   id* int Puntero al id del empleado que sera removido
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL]
 * 			o (0) si no hay Error * *
 *
 */
int removeEmployee (Employee* list, int len, int* id)
{
	int retorno = -1;
	int i;

	if (list != NULL && len > 0)
	{
		for (i=0;i<len;i++)
		{
			if ( list[i].id == *id )
				{
				list[i].isEmpty = 1;
				retorno = 0;
				break;
				}
		}
	}
	return retorno;
}
/** \brief  Ordena los empleados segun un criterio preestablecido
 * \param   list Employee* Puntero al array de Employees
 * \param   len int Longitud del array
 * \param   order int Criterio de ordenamiento (Ascendente o Descendente)
 * \return  int Return (-1) si hay un Error [Longitud invalida o puntero NULL]
 * 			o (0) si no hay Error * *
 *
 */
int sortEmployeesByLastName(Employee* list, int len, int order)
{
	Employee auxEmployee;
	int retorno = -1;
	int i, j;

 if (list != NULL && len > 0)
 {

  if (order == 1)
  {
	for(i=0;i<len-1;i++)
	{
		for(j=i+1;j<len;j++)
		{
			if (strcmp(list[i].lastName,list[j].lastName) > 0)
			{
				auxEmployee = list[i];
				list[i] = list[j];
				list[j] = auxEmployee;
			}
		}
	 }
  }
  else{
			   for(i=0;i<len-1;i++)
			   {
			  		for(j=i+1;j<len;j++)
			  		{
			  			if (strcmp(list[i].lastName,list[j].lastName) < 0)
						{
						  auxEmployee = list[i];
						  list[i] = list[j];
						  list[j] = auxEmployee;
						}
			  		}
	    		}
	   }
			   for(i=0;i<len-1;i++)
			   {
					for(j=i+1;j<len;j++)
					{
						if (strcmp(list[i].lastName, list[j].lastName) == 0 && order == 1)
						{
							if (list[i].sector > list[j].sector)
							{
								auxEmployee = list[i];
								list[i] = list[j];
								list[j] = auxEmployee;
							}
						}
					}
				}
				for(i=0;i<len-1;i++)
				{
					for(j=i+1;j<len;j++)
					{
						if (strcmp(list[i].lastName, list[j].lastName) == 0 && order == 0)
						{
							if (list[i].sector < list[j].sector)
							{
								auxEmployee = list[i];
								list[i] = list[j];
								list[j] = auxEmployee;
							}
						}
					}
				}
 }
	return retorno;
}
/** \brief  Informa sobre los sueldos de los empleados
 * \param   list Employee* Puntero al array de Employees
 * \param   len int Longitud del array
 * \return  int Return (-1) si hay un Error [Longitud invalida o puntero NULL]
 * 			o (0) si no hay Error * *
 *
 */
int reportPromedy(Employee* list, int len)
{
	int retorno = -1;
	int i;
	float suma = 0;
	int contador = 0;
	int contadorMax = 0;
	float promedio;

  if (list != NULL && len > 0)
  {

	for (i=0;i<len;i++)
	{
		if (list[i].isEmpty == 0)
		{
			suma = list[i].salary + suma;
			contador++;
		}
	}
	promedio = suma / contador;

	for (i=0;i<len;i++)
	{
		if (list[i].isEmpty == 0 && promedio < list[i].salary)
		{
			contadorMax++;
		}
	}

	printf ("Total de salarios: %.2f\n", suma);
	printf ("Promedio salarios: %.2f\n", promedio);
	printf ("La cantidad de salarios que superan el promedio es: %d\n", contadorMax);
  }
	return retorno;
}

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* pEmployee = NULL;
	int r;
	char idAux[100], nombreAux[100], horasAux[100], sueldoAux[100];

	if (pFile != NULL && pArrayListEmployee != NULL)
	{
	do{
		r = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idAux, nombreAux, horasAux, sueldoAux);

		if (pEmployee != NULL)
		{
		pEmployee = employee_newParametros(idAux, nombreAux, horasAux, sueldoAux);
		ll_add(pArrayListEmployee, pEmployee);
		}

		if(r == 4)
		{
			printf("Lei: %s %s %s %s\n", idAux, nombreAux, horasAux, sueldoAux);
		}
		else
			break;

		}while (!feof(pFile));

	}

    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* pEmployee;

	if (pFile != NULL && pArrayListEmployee != NULL)
	{
		do
		{
			if (pEmployee != NULL)
			{
				pEmployee = employee_new();
				if (fread(pEmployee, sizeof(Employee), 1, pFile) == 1)

				ll_add(pArrayListEmployee, pEmployee);
			}

		}while(!feof(pFile));

	}

	return 1;
}

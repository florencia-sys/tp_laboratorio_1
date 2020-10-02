/*
 ============================================================================
 Name        : TP2.c
 Author      : Florencia
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "arrayEmployees.h"
#include "utn.h"

#define NAME_ELEMENTS 51
#define LASTNAME_ELEMENTS 51
#define ELEMENTS 1000

int main(void) {

	setbuf (stdout, NULL);

	Employee arrayEmployees[ELEMENTS];
	int opcion;
	int respuesta;
	int idEmployee = 1;
	char name[NAME_ELEMENTS];
	char lastName [LASTNAME_ELEMENTS];
	float salary = 0;
	int sector = 0;
	int orden;
	int id;
	int auxIndice;

	if (!initEmployees (arrayEmployees, ELEMENTS))
	{
		printf("INICIALIZACION OK\n");
	}
	do
	{
		utn_getNumero(&opcion, 	"\n1.ALTA\n"
								"2.MODIFICAR\n"
								"3.BAJA\n"
								"4.INFORMAR\n"
								"5.SALIR\n"
								"Elige una opcion: \n", "ERROR", 1, 5, 2);

		switch(opcion)
		{
		case 1:
			auxIndice = getEmptyIndex (arrayEmployees, ELEMENTS);
			if (!addEmployee(arrayEmployees, ELEMENTS, &idEmployee, name, lastName, salary, sector, auxIndice))
			{
				printf("Carga Exitosa");
			}
			else
			{
				printf("No Se Pudo Cargar");
			}
			break;
		case 2:
			if (!allEmpty (arrayEmployees, ELEMENTS))
			{
			printArray (arrayEmployees, ELEMENTS);
			utn_getNumero(&idEmployee, "Ingrese el ID a modificar: \n", "ERROR", 1, 1000, 2);
			id = findEmployeeById (arrayEmployees, ELEMENTS, &idEmployee);
				if (!modifyEmployee(arrayEmployees, ELEMENTS, id))
				{
					printf("Modificacion Exitosa");
				}
				else
				{
					printf("No se ha podido modificar");
				}
			}
			else
			{
				printf ("No hay empleados cargados\n");
			}
			break;
		case 3:
			if (!allEmpty (arrayEmployees, ELEMENTS))
			{
			printArray (arrayEmployees, ELEMENTS);
			utn_getNumero(&idEmployee, "Ingrese el ID a eliminar: \n", "ERROR", 1, 1000, 2);
				if (!removeEmployee (arrayEmployees, ELEMENTS, &idEmployee))
				{
					printf ("Empleado eliminado con exito");
				}
				else
				{
					printf ("No se pudo eliminar");
				}
			}
			else
			{
				printf ("No hay empleados cargados\n");
			}
			break;
		case 4:
			do
			{
				utn_getNumero(&respuesta, "1. Listar empleados por apellido y sector\n"
							  	  	  	  "2. Total, promedio de salario y cantidad de empleados que superan el salario promedio\n"
										  "3. Salir\n"
										  "Elige una opcion: \n",
							  	  	  	  "ERROR\n", 1, 3, 2);
			switch (respuesta)
			{
			case 1:
				utn_getNumero(&orden, "Ingrese opcion [1: ASCENDENTE / 0: DESCENDENTE]\n", "ERROR\n", 0, 1, 2);
				sortEmployeesByLastName(arrayEmployees, ELEMENTS, orden);
				printArray (arrayEmployees, ELEMENTS);
				break;
			case 2:
				reportPromedy(arrayEmployees, ELEMENTS);
				break;
			}
			}while(respuesta != 3);
			break;
		}
	}while( opcion != 5);
	return EXIT_SUCCESS;
}

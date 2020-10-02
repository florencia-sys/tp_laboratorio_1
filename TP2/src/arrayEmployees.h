/*
 * Empleado.h
 *
 *  Created on: 14 may. 2020
 *      Author: flors
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

typedef struct{
	int id;
	char name [51];
	char lastName [51];
	float salary;
	int sector;
	int isEmpty;
}Employee;

int printArray (Employee* list, int len);
//int printEmployee (Employee* pElement, int len);
int initEmployees(Employee* list, int len);
int getEmptyIndex (Employee* list, int len);
int findEmployeeById (Employee* list, int len, int* id);
int addEmployee(Employee* list, int len, int *id, char name[],char lastName[],float salary,int sector, int indice);
int modifyEmployee(Employee* list, int len, int indice);
int removeEmployee (Employee* list, int len, int* id);
int sortEmployeesByLastName(Employee* list, int len, int order);
int allEmpty (Employee* list, int len);
int reportPromedy(Employee* list, int len);

#endif /* ARRAYEMPLOYEES_H_ */

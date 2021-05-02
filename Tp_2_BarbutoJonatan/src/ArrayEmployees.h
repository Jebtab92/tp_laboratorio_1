/*
 * ArrayEmployees.h
 *
 *  Created on: May 2, 2021
 *      Author: Jonatan Barbuto
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}Employee;

int initEmployees(Employee list[], int size);
int addEmployee(Employee list[], int id, char name[], char lastName[], float salary, int sector, int size);
int findEmployeeById(Employee list[],int id, int size);
int removeEmployee(Employee list[], int id, int size);
int sortEmployees(Employee list[], int order, int size);
int printEmployees(Employee list[], int size);

#endif /* ARRAYEMPLOYEES_H_ */

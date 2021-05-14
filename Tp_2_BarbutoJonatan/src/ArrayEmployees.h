/*
 * ArrayEmployees.h
 *
 *  Created on: May 14, 2021
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

void harcodeoDatos(Employee list[], int size, int* lastID);
int initEmployees(Employee list[], int size);
int searchSlot(Employee list[], int size);
int addEmployee(Employee list[], int size, int id, char name[], char lastName[], float salary, int sector);
int getEmployee(Employee list[], int size, int* lastID);
int printEmployees(Employee list[], int size);
int ModifyEmployee(Employee list[], int size);
int removeEmployee(Employee list[], int size, int id);
int sortEmployees(Employee list[], int size, int order);
int findEmployeeById(Employee list[], int size, int id);
float averageSalary(Employee list[], int size, float* total, int* cantEmp);
int arrayEmpty(Employee list[], int size);
int searchId(Employee list[], int size);
void printAverageInfo(float* promedio, float* total, int* cantEncimaDelPromedio);

#endif /* ARRAYEMPLOYEES_H_ */


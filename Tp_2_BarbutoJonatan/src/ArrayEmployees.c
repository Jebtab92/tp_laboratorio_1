/*
 * ArrayEmployees.c
 *
 *  Created on: May 2, 2021
 *      Author: Jonatan Barbuto
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"

/** \brief To indicate that all position in the array are empty, this function put the flag (isEmpty) in TRUE in all position of the array
* \param list[] Employee Pointer to array of employees
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int initEmployees(Employee list[], int size)
{
	int i;
	int ret = -1;

	if(list != NULL && size > 0)
	{
		for(i = 0; i < size; i++)
		{
			list[i].isEmpty = 1;
		}
		ret = 0;
	}
	return ret;
}

/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list[] employee
* \param size int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
*	free space] - (0) if Ok
*/
int addEmployee(Employee list[], int id, char name[], char lastName[], float salary, int sector, int size)
{
	int index;

	if(list != NULL && size > 0)
	{
		// Automatic id
		list[index].id = index;

		printf("\nPlease enter name -->");
		fflush(stdin);
		gets(name);

		printf("\nPlease enter lastname -->");
		fflush(stdin);
		gets(lastName);

		printf("\nPlease enter salary -->");
		scanf("%d", &salary);

		printf("\nPlease enter sector -->");
		scanf("%d", &sector);

		list[index].isEmpty = 0;
	}
	return 0;
}

/** \brief find an Employee by Id en returns the index position in array.
*
* \param list[] Employee
* \param size int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/

int findEmployeeById(Employee list[], int id, int size)
{
	int i;
	int ret = -1;

	if(list != NULL && size > 0)
	{
		printf("\nPlease enter ID to search -->");
		scanf("%d", &id);

		for(i = 0; i < size; i++)
		{
			if(i == id)
			{
				ret = id;
				break;
			}
		}
	}
	return ret;
}

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list[] Employee
* \param size int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee list[], int id, int size)
{
	if(list != NULL && size > 0)
	{
		int i;
		char answer;

		printf("\nPlease enter id to delete -->");
		scanf("%d", &id);

		for(i = 0; i < size; i++)
		{
			if(i == id)
			{
				printf("\nYou will delete to %s-%s", list[i].name, list[i].lastName);
				printf("\nPlease enter 'y' if you want to continue");
				fflush(stdin);
				scanf("%c", &answer);
				if(answer == 'y')
				{
					list[id].isEmpty = 1;
					break;
				}
			}
		}
	}
	return 0;
}

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list[] Employee
* \param size int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(Employee list[], int order, int size)
{
	if(list != NULL && size > 0)
	{

	}
	return 0;
}

/** \brief print the content of employees array
*
* \param list[] Employee
* \param size int
* \return int
*
*/
int printEmployees(Employee list[], int size)
{
	if(list != NULL && size > 0)
	{

	}
	return 0;
}

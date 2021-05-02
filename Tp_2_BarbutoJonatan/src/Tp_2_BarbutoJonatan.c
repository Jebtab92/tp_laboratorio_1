/*
 ============================================================================
 Name        : Tp_2_BarbutoJonatan.c
 Author      : Jonatan Barbuto
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#define QUANTITY 5

int main(void) {

	setbuf(stdout, NULL);
	int option;
	int flag1 = 0;
	Employee listEmployee[QUANTITY];

	initEmployee(listEmployee, QUANTITY);
	do
	{
		printf("\n--Main Menu--");
		printf("");
		printf("");
		printf("");
		printf("");
		printf("");

		switch (option)
		{
			case 1:
			{

				flag1 = 1;
				break;
			}
			case 2:
			{
				if(flag1 == 1)
				{

				}
				break;
			}
			case 3:
			{
				if(flag1 == 1)
				{

				}
				break;
			}
			case 4:
			{
				if(flag1 == 1)
				{


					switch(option)
					{
						case 1:
						{
							break;
						}
						case 2:
						{
							break;
						}
					}
				}
				break;
			}
			case 5:
			{
				break;
			}
		}

	}while(option != 5);



	return 0;
}

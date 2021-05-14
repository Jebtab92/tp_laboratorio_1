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
#include "BibliotecaTp2.h"
#define QUANTITY 1000

int main(void)
{
	setbuf(stdout, NULL);
	int opcionMenu;
	int lastId = 0;
	float totalSueldos;
	float promedioSueldos;
	int arribadelPromedio;
	Employee Empleados[QUANTITY];
	initEmployees(Empleados, QUANTITY);

	do
	{
		switch(opcionMenu = utn_GetNumber("--Menu Principal-- \n\n"
				"-1- Nuevo Empleado\n"
				"-2- Modificar Empleado\n"
				"-3- Eliminar Empleado\n"
				"-4- Informar Empleados \n"
				"-5- Salir\n"
				"Opcion: -->", "Error, Opcion no valida.\n", 1, 5))
		{
			case 1:
			{
				getEmployee(Empleados, QUANTITY, &lastId);
				system("pause");
				break;
			}
			case 2:
			{
				if(arrayEmpty(Empleados, QUANTITY) != 0)
				{
					printEmployees(Empleados, QUANTITY);
					if(ModifyEmployee(Empleados, QUANTITY))
					{
						printf("Modificado Correctamente.\n");
					}
					else
					{
						printf("Algo salio mal Reintente.\n");
					}
					system("pause");
				}
				else
				{
					printf("\nNo es posible modificar por que no hay empleados.\n");
					system("pause");
				}
				break;
			}
			case 3:
			{
				if(arrayEmpty(Empleados, QUANTITY) != 0)
				{
					printEmployees(Empleados, QUANTITY);
					if(removeEmployee(Empleados, QUANTITY, utn_GetNumber(
									"Ingrese el ID del empleado a eliminar: ",
									"ID Fuera de rango.", 1,
									searchId(Empleados, QUANTITY))))
					{
						printf("\nUups. Algo salio mal Reintente.\n");
					}
					else
					{
						printf("\nEliminado Correctamente.\n");
						system("pause");
					}
				}else
				{
					printf("\nNo es posible modificar por que no hay empleados.\n");
					system("pause");
				}
				break;
			}
			case 4:
			{
				if(arrayEmpty(Empleados, QUANTITY) != 0)
				{
					switch(utn_GetNumber(
							"-1- Lista de Empleados.\n"
									"-2- Total y Promedio, Empleados por encima del promedio.\n"
									"-3- Volver al menu anterior.\n"
									"--Opcion: ", "Error, Opcion no valida.", 1, 3))
					{
						case 1:
						{
							sortEmployees(Empleados, QUANTITY, 0);
							printEmployees(Empleados, QUANTITY);
							system("pause");
							break;
						}
						case 2:
						{
							promedioSueldos = averageSalary(Empleados, QUANTITY, &totalSueldos, &arribadelPromedio);
							printAverageInfo(&promedioSueldos, &totalSueldos, &arribadelPromedio);
							break;
						}
						case 3:
						{
							break;
						}
					}
				}
				else
				{
					printf("\nNo es posible mostrar por que no hay empleados.\n");
					system("pause");
				}
				break;
			}
			case 5:
			{
				printf("--Nos vemos--");
				break;
			}
		}
	}while(opcionMenu != 5);

	return 0;
}

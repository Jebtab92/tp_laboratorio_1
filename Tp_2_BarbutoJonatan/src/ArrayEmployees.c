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
#include "BibliotecaTp2.h"

#define VACIO 0
#define OCUPADO 1


void harcodeoDatos(Employee list[],int size,int* lastID)
{
	*lastID=5;
	int id[5]={1,2,3,4,5};
	char name[][51]={"Juan","Sasha","Facundo","German","Octavio"};
	char lastName[][51]={"Chico","Lospalluto","Chico","Scarafilo","Villegas"};
	float salary[5]={34000.00,35000.00,34000.00,45000.00,65000.00};
	int sector[5]={1,1,1,3,3};
	int isEmpty[5]={1,1,1,1,1};
	for (int i = 0; i < 5; ++i){
		list[i].id=id[i];
		strcpy(list[i].name,name[i]);
		strcpy(list[i].lastName,lastName[i]);
		list[i].salary=salary[i];
		list[i].sector=sector[i];
		list[i].isEmpty=isEmpty[i];
	}
}

/**
 * \brief To indicate that all position in the array are empty,
 * \this function put the flag (isEmpty) in TRUE in all*position of the array
 * \param list Employee* Pointer to array of employees
 * \param size int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int initEmployees(Employee list[], int size)
{
	int reply=0;
	if(size>0){
		for (int i = 0; i < size; ++i){
			list[i].isEmpty=0;
		}
	}else{
		reply=-1;
	}
	return reply;
}

/**
 * \brief add in a existing list of employees the values received as parameters
 * \in the first empty position
 * \param list employee*
 * \param size int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 */
int addEmployee(Employee list[], int size, int id, char name[], char lastName[], float salary, int sector)
{
	int place =	searchSlot(list, size);

	if(place>=0){
		list[place].id=id;
		strcpy(list[place].name,name);
		strcpy(list[place].lastName,lastName);
		list[place].salary=salary;
		list[place].sector=sector;
		list[place].isEmpty=OCUPADO;
	}
	return 0;
}

/**
 * \brief recibe la lista de Employees y busca un lugar disponible.
 *  \param recibe la lista
 *  \param recibe el tamanio
 *  \return En caso de encontrar lugar retorna el indice de la lista que se encuentra disponible
 *  		 0 en caso de No encontrar lugar
 *  		 y -1 en caso de error en algun parametro.
 */
int searchSlot(Employee list[], int size)
{
	int reply=-2;

	if(size>0){
		for (int i = 0; i < size; ++i)
		{
			if(list[i].isEmpty==VACIO)
			{
				reply=i;
				break;
			}
			else
			{
				reply=-1;
			}
		}
	}
	return reply;
}

/**
 * \brief	Recorre la lista de Empleados buscando el ID mas grande.
 *  \param	lista a recorrer.
 *  \param	Tamanio de la lista.
 *  \return Retorna el ID mas grande ocupado hasta el momento, o -1 en caso de no haber.
 */
int searchId(Employee list[], int size)
{
	int reply=-1;

	for (int i = 0; i < size; ++i)
	{
		if(list[i].isEmpty==OCUPADO)
		{
			if(list[i].id > reply)
			{
				reply=list[i].id;
			}
		}
	}
	return reply;
}

/**
 * \brief Recorre un array corroborando si esta se encuentra llena o no.
 * \param recibe la lista de la cual se desea saber si esta llena.
 * \param recibe el largo de la lista.
 * \return Retorna 0 en caso de que esta se encuentra completa o la cantidad de espacios disponibles osea > a cero.
 */
int arrayEmpty(Employee* list,int size)
{
	int reply=0;

	for (int i = 0; i < size; ++i)
	{
		if(list[i].isEmpty == 1)
		{
			reply++;
		}
	}
	return reply;
}

/**
 * \brief Pide los datos necesarios para la carga de un Empleado.
 *  \param Lista de Empleados.
 *  \param Tamanio de la lista.
 *  \return	Devuelve -1 en caso de no haber lugar para este nuevo empleado, o Cero en caso de poder realizar el pedido por que hay lugar disponible.
 */
int getEmployee(Employee list[], int size, int* lastID)
{
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int reply = 0;
	int id;

	if(searchSlot(list, size)<=-1)
	{
		printf("No hay lugares Disponibles para nuevos empleados.\n");
		reply = -1;
	}
	else
	{
		id = *lastID + 1;
		utn_GetName(name, "Ingrese Nombre del empleado: ", "Error, sin numeros", 51);
		formatName(name, 51);
		utn_GetName(lastName, "Ingrese Apellido del empleado: ", "Error, sin numeros", 51);
		formatName(lastName, 51);
		salary = utn_GetNumberFloat("Ingrese Salario del empleado: ","Error, No valido: ", 1, 999999);
		sector = utn_GetNumber("Ingrese Sector al que pertenece el empleado: ","Sector no valido: ", 1, 10);
		addEmployee(list, size, id, name, lastName, salary, sector);
		*lastID = id;
		reply = 0;
	}
	if(reply == 0)
	{
		printf("La carga se realizo con exito. \n");
	}
	return reply;
}

/**
 * \brief print the content of employees array
 * \param list Employee*
 * \param length int
 * \return int
 */
int printEmployees(Employee list[], int size)
{
	printf("*******************************************************************************\n");
	printf("|%10s  %20s  %20s  %10s %10s| \n","ID","NOMBRE","APELLIDO","SUELDO","SECTOR");
	printf("*******************************************************************************\n");
	if(size>0){
		for (int i = 0; i < size; ++i)
		{
			if(list[i].isEmpty==1)
			{
				printf("|%10d|  %20s|  %20s|  %10.2f| %6d| \n",list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
			}
		}
	}
	printf("*******************************************************************************\n");
	return 0;
}

/**
 * \brief Realiza la modificacion un elemento del array de Empleados.
 * \param Recibe la lista de Empleados.
 * \param Recibe el tamanio de esa lista.
 * \return Retorna 0 en caso de no poder Imprimir en pantalla, o 1 si imprimio correctamente.
 */
int ModifyEmployee(Employee list[],int size)
{
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int reply = 0;
	int id = utn_GetNumber("Ingrese El ID del empleado: ","Error id fuera de rango", 1, size+1);
	int aux = findEmployeeById(list, size, id);
	if(aux>=0)
	{
		printf("Se modificara el empleado: \n");
		printf("*******************************************************************************\n");
		printf("|%10s  %20s  %20s  %10s %10s| \n","ID","NOMBRE","APELLIDO","SUELDO","SECTOR");
		printf("*******************************************************************************\n");
		printf("|%10d|  %20s|  %20s|  %10.2f| %6d| \n",list[aux].id,list[aux].name,list[aux].lastName,list[aux].salary,list[aux].sector);
		printf("*******************************************************************************\n");
		for (int i = 0; i <size; ++i)
		{
			if(list[i].id == id)
			{
				switch(utn_GetNumber("Que campo desea modificar?\n"
									  "-1- Nombre\n"
									  "-2- Apellido\n"
									  "-3- Salario\n"
									  "-4- Sector\n"
									  "Ingrese Opcion: -->","\nError, Reintente: -->",1,4))
				{
					case 1:
					{
						utn_GetName(name, "Ingrese Nombre: ", "Error, sin numeros", 51);
						strcpy(list[i].name,name);
						break;
					}
					case 2:
					{
						utn_GetName(lastName, "Ingrese Apellido: ", "Error, sin numeros", 51);
						strcpy(list[i].lastName,lastName);
						break;
					}
					case 3:
					{
						salary=utn_GetNumberFloat("Ingrese Salario: ","Error, No valido: ",1,999999);
						list[i].salary=salary;
						break;
					}
					case 4:
					{
						sector=utn_GetNumber("Ingrese Sector: ","Sector no valido: ",1,10);
						list[i].sector=sector;
						break;
					}
				}
				reply=1;
			}
		}
	}
	return reply;
}

/**
 * \brief find an Employee by Id en returns the index position in array.
 * \param list Employee*
 * \param size int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 */
int findEmployeeById(Employee list[], int size, int id)
{
	int reply = -1;

	if(size > 0)
	{
		for (int i = 0; i < size; ++i)
		{
			if(list[i].id==id && list[i].isEmpty==1)
			{
				//reply=id;
				reply=i;
			}
		}
	}
	return reply;
}

/**
 * \brief Remove a Employee by Id (put isEmpty Flag in 1)
 * \param list Employee*
 * \param size int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
 */
int removeEmployee(Employee list[], int size, int id){
	int reply = -1;
	int position = findEmployeeById(list, size, id);

	if(position != -1)
	{
		if(list[position].isEmpty == OCUPADO)
		{
			list[position].isEmpty=VACIO;
			reply=0;
		}
	}
	return reply;
}

/**
 * \brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order
 * \param list Employee*
 * \param size int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int sortEmployees(Employee list[], int size, int order)
{
	int flagSwap;
	int counter = 0;
	int reply = -1;
	Employee aux;

	if(list != NULL && size >= 0)
	{
		do
		{
			flagSwap = 0;
			for(int i = 0; i < size-1; ++i)
			{
				if(order == 0)
				{
					if(strcmp(list[i].lastName,list[i+1].lastName)>0)
					{
						flagSwap=1;
						aux=list[i];
						list[i]=list[i+1];
						list[i+1]=aux;
					}
					else
					{
						if(strcmp(list[i].lastName,list[i+1].lastName)==0 && list[i].sector > list[i+1].sector)
						{
							flagSwap=1;
							aux=list[i];
							list[i]=list[i+1];
							list[i+1]=aux;
						}
					}
				}
				else if(order == 1)
				{
					if(strcmp(list[i+1].lastName,list[i].lastName)>0)
					{
						flagSwap=1;
						aux=list[i];
						list[i]=list[i+1];
						list[i+1]=aux;
					}
					else
					{
						if(strcmp(list[i].lastName,list[i+1].lastName)==0 && list[i+1].sector > list[i].sector)
						{
							flagSwap=1;
							aux=list[i];
							list[i]=list[i+1];
							list[i+1]=aux;
						}
					}
				}
				counter++;
			}
		}while(flagSwap);

		reply = counter;
	}
	return reply;
}

/**
 * \brief Calcula el promedio del sueldo de la nomina de empleados, y tambien el total de todos los sueldos.
 * \param recibe la lista de empleados.
 * \param recibe la cantidad de elementos de esa lista.
 * \param Direccion de memoria donde se va a guardar el total de sueldos.
 * \param Direccion de memoria donde se va a guardar la cantidad de empleados que superen el promedio.
 * \return retorna el promedio de todos los sueldos de la nomina.
 */
float averageSalary(Employee list[], int size, float* total, int* cantEmp)
{
	float reply = -1;
	float accum = 0;
	int conter = 0;
	int cantidadEmpleados = 0;

	if(list != NULL && size >= 0)
	{
		for(int i = 0; i < size; ++i)
		{
			if(list[i].isEmpty == 1)
			{
				accum+=list[i].salary;
				conter++;
			}
		}
		*total = accum;
		reply = ((float)accum/(float)conter);

		for(int i = 0; i < size; ++i)
		{
			if(list[i].salary > reply && list[i].isEmpty == 1)
			{
				cantidadEmpleados++;
			}
		}
		*cantEmp = cantidadEmpleados;
	}
	return reply;
}

/**
 * \brief recibe informacion de la nomina y la muestra formateada por pantalla.
 * \param recibe la direccion de memoria del promedio de los sueldos.
 * \param recibe la direccion de memoria del la suma total de los sueldos.
 * \param Recibe la direccion de memoria de la cantidad de empleados por encima del promerio.
 * \return no retorna nada, simplemente muestra por pantalla la informacion.
 */
void printAverageInfo(float* promedio, float* total, int* cantEncimaDelPromedio)
{
	printf("DATOS DE SUELDOS TOTAL Y PROMEDIO DE LA NOMINA DE EMPLEADOS: \n");
	printf("**************************************************************************************\n");
	printf("|%1s      | %-25s  | %20s | \n"," PROMEDIO "," TOTAL "," EMPLEADOS POR ARRIBA DEL PROMEDIO  ");
	printf("**************************************************************************************\n");
	printf("| %-15.2f|  %-26.2f|  %21d               |\n",*promedio,*total,*cantEncimaDelPromedio);
	printf("**************************************************************************************\n");
	system("pause");
}

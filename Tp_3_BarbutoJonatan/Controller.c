#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Parser.h"
#include "Biblioteca.h"
#include "Controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee, int* lastID)
{
    FILE* f;
    int retorno = -1;
    f = fopen(path, "r");
    if(ll_len(pArrayListEmployee) == 0)
    {
		if(f == NULL)
		{
			printf("Error al abrir el archivo de texto, Corrobore si existe. \n\n");
			system("pause");
		}
		else
		{
			retorno = 0;
			printf("Archivo abierto correctamente.\n\n");
			retorno = parser_EmployeeFromText(f, pArrayListEmployee, lastID);
			system("pause");
		}
    }
    else
    {
    	printf("El archivo ya fue cargado!.\n\n");
    	system("pause");
    }
    fclose(f);
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* f;
    int retorno = -1;
    f = fopen(path, "rb");
    if(ll_len(pArrayListEmployee) == 0)
    {
		if(f == NULL)
		{
			retorno = 0;
			printf("Error al abrir el archivo de Binary, Corrobore si existe.\n");
		}
		else
		{
			retorno = 1;
			retorno = parser_EmployeeFromBinary(f, pArrayListEmployee);
			printf("Archivo de texto abierto\n");
		}
    }
    else
    {
    	printf("El archivo ya fue cargado!.\n\n");
    	system("pause");
    }
    fclose(f);
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \param puntero contador ID.
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* contadorID)
{
    Employee* empleadoNuevo;
	int retorno = -1;
    int id;
    int sueldo;
    int horasTrabajadas;

    char idS[100];
    char nombre[100];
    char sueldoS[100];
    char horasTrabajadasS[100];

    if(ll_len(pArrayListEmployee) != 0)
    {

		Get_OnlyAlphabetString("\nIngrese Nombre: ", "\nError reingrese: ", nombre, 100, 3);
		horasTrabajadas = Get_IntPositive("\nIngrese Horas Trabajadas: ", "\nError, reingrese: ", 3);
		sueldo = Get_IntRange("\nIngrese Sueldo: ", "\nError, reingrese: ", 1, 999999, 3);

		sprintf(sueldoS, "%d", sueldo);
		sprintf(horasTrabajadasS, "%d", horasTrabajadas);
		(*contadorID)++;
		id = *contadorID;
		sprintf(idS, "%d", id);

		empleadoNuevo = employee_newParametros(idS, nombre, horasTrabajadasS, sueldoS);
		ll_add(pArrayListEmployee, empleadoNuevo);
		retorno = 0;
		printf("\n\ndatos cargados correctamente!\n");
    }
    else
    {
    	printf("\n\nNo es posible dar de alta Nuevos empleados...\n");
    }
	return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* empleado;
    int id, i, idAuxiliar;
    int flag = 0;
    int menu;
    char nombre[100];
    int sueldo;
    int horasTrabajadas;
    if(ll_len(pArrayListEmployee) != 0)
    {
		printf("\n Ingrese el ID del empleado a modificar: ");
		scanf("%d", &id);
		for(i = 0; i < ll_len(pArrayListEmployee); i++)
		{
			empleado = (Employee*)ll_get(pArrayListEmployee, i);
			employee_getId(empleado, &idAuxiliar);
			if(empleado != NULL && id == idAuxiliar)
			{
		    	printf("\n+-----------------------------------------------------------------------+\n");
		    	printf("|%10s  %20s  %20s  %10s     | \n","ID","NOMBRE","HORAS","SUELDO");
		    	printf("+-----------------------------------------------------------------------+\n");
				employee_printEmployee(pArrayListEmployee, i);
				switch(menu = Get_IntRange("\n\n------------------------------Menu de Modificaciones----------------------------------- \n\n"
							  "1) Nombre\n"
							  "2) Cantidad de horas trabajadas\n"
							  "3) Sueldo\n"
							  "4) Salir\n"
							  "Opcion: ", "\nError, reingrese: ", 1, 4, 3))
				{
					case 1:
						Get_OnlyAlphabetString("\nIngrese Nombre: ", "\nError, reingrese: ", nombre, 100, 3);
						employee_setNombre(empleado, nombre);
						printf("\nNombre cambiado con exito\n");
				    	printf("\n+-----------------------------------------------------------------------+\n");
				    	printf("|%10s  %20s  %20s  %10s     | \n","ID","NOMBRE","HORAS","SUELDO");
				    	printf("+-----------------------------------------------------------------------+\n");
						employee_printEmployee(pArrayListEmployee, i);
						system("pause");
						break;
					case 2:
						horasTrabajadas = Get_IntPositive("\nIngrese Horas Trabajadas: ", "\nError, reingrese: ", 3);
						employee_setHorasTrabajadas(empleado, horasTrabajadas);
						printf("\nHoras trabajadas cambiado con exito\n");
				    	printf("\n+-----------------------------------------------------------------------+\n");
				    	printf("|%10s  %20s  %20s  %10s     | \n","ID","NOMBRE","HORAS","SUELDO");
				    	printf("+-----------------------------------------------------------------------+\n");
						employee_printEmployee(pArrayListEmployee, i);
						system("pause");
						break;
					case 3:
						sueldo = Get_IntRange("\nIngrese Sueldo: ", "\nError, reingrese: ", 1, 999999, 3);
						employee_setSueldo(empleado, sueldo);
						printf("\nSueldo cambiado con exito\n");
				    	printf("\n+-----------------------------------------------------------------------+\n");
				    	printf("|%10s  %20s  %20s  %10s     | \n","ID","NOMBRE","HORAS","SUELDO");
				    	printf("+-----------------------------------------------------------------------+\n");
						employee_printEmployee(pArrayListEmployee, i);
						system("pause");
						break;
					case 4:
						break;
				}
				flag = 1;
			}
		}
		if(flag == 0)
		{
			printf("\nEmpleado no encontrado\n");
		}
    }
    else
    {
    	printf("\n\nNo es posible modificar empleados...\nCargue un archivo previamente.\n\n");
    }
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int empleadoEliminar;
    int len;
    int i;
    int retorno = -1;
    int encontro = 0;
    Employee* empleado;
    len = ll_len(pArrayListEmployee);

    if(ll_len(pArrayListEmployee) != 0)
    {
		printf("Ingrese el ID que desea eliminar\n");
		scanf("%d", &empleadoEliminar);
		for(i = 0; i < len; i++)
		{
			empleado = (Employee*) ll_get(pArrayListEmployee, i);
			if((*empleado).id == empleadoEliminar)
			{
		    	printf("+-----------------------------------------------------------------------+\n");
		    	printf("|%10s  %20s  %20s  %10s     | \n","ID","NOMBRE","HORAS","SUELDO");
		    	printf("+-----------------------------------------------------------------------+\n");
		    	employee_printEmployee(pArrayListEmployee, i);

				if(Validate_Exit_SN("Desea continuar con la baja? Si[s] - No[n]: ", "\nError, reingrese: ", 3) == 1)
				{
					ll_remove(pArrayListEmployee, i);
					printf("\nEmpleado eliminado correctamente\n");
					retorno = 0;
					encontro = 1;
					break;
				}
				else
				{
					printf("\n No se pudo eliminar el empleado\n");
					break;
				}
			}
		}
		if(encontro == 0)
		{
			printf("\nNo se encontro ID\n");
		}
    }
    else
    {
    	printf("\n\nNo es borrar empleados...\nCargue un archivo previamente.\n\n");
    }
    system("pause");
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i, len;
    len = ll_len(pArrayListEmployee);
    if(pArrayListEmployee != NULL && len > 0)
    {
    	printf("+-----------------------------------------------------------------------+\n");
    	printf("|%10s  %20s  %20s  %10s     | \n","ID","NOMBRE","HORAS","SUELDO");
    	printf("+-----------------------------------------------------------------------+\n");
        for(i = 0; i < len; i++)
        {
            employee_printEmployee(pArrayListEmployee, i);
            printf("+-----------------------------------------------------------------------+\n");
            retorno = 0;
        }
    }
    else
    {
    	printf("No hay datos a mostrar.\n");
    }
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int menu;
	int len;
	len = ll_len(pArrayListEmployee);
	if(pArrayListEmployee != NULL && len > 0)
	{
		system("cls");
		switch(menu = Get_IntRange("------------------------------Menu de Ordenamiento-----------------------------------\n"
									"1) ID ascendente\n"
									"2) ID descendente\n"
									"3) Horas de trabajo ascendente\n"
									"4) Horas de trabajo descendente\n"
									"5) Sueldo de ascendente\n"
									"6) Sueldo de descendente\n"
									"7) Salir\n"
									"Opcion: ","\nError, Reintente \n", 1, 7, 3))
		{
			case 1:
				printf("Ordenando espere por favor\n");
				if(ll_sort(pArrayListEmployee, employee_OrdenarID, 1) == 0)
				{
					printf("Ordenado correctamente\n");
				}
				else
				{
					printf("Hubo un error, reintente\n");
				}
				break;
			case 2:
				printf("Ordenando espere por favor\n");
				if(ll_sort(pArrayListEmployee, employee_OrdenarID, 0) == 0)
				{
					printf("Ordenado correctamente\n");
				}
				else
				{
					printf("Hubo un error, reintente\n");
				}
				break;
			case 3:
				printf("Ordenando espere por favor\n");
				if(ll_sort(pArrayListEmployee, employee_OrdenarHoras, 1) == 0)
				{
					printf("Ordenado correctamente\n");
				}
				else
				{
					printf("Hubo un error, reintente\n");
				}
				break;
			case 4:
				printf("Ordenando espere por favor\n");
				if(ll_sort(pArrayListEmployee, employee_OrdenarHoras, 0) == 0)
				{
					printf("Ordenado correctamente\n");
				}
				else
				{
					printf("Hubo un error, reintente\n");
				}
				break;
			case 5:
				printf("Ordenando espere por favor\n");
				if(ll_sort(pArrayListEmployee, employee_OrdenarSueldo, 1) == 0)
				{
					printf("Ordenado correctamente\n");
				}
				else
				{
					printf("Hubo un error, reintente\n");
				}
				break;
			case 6:
				printf("Ordenando espere por favor\n");
				if(ll_sort(pArrayListEmployee, employee_OrdenarSueldo, 0) == 0)
				{
					printf("Ordenado correctamente\n");
				}
				else
				{
					printf("Hubo un error, reintente\n");
				}
				break;
			case 7:
				break;
		}
	}
	else
	{
		printf(" \nNo hay datos para ordenar \n");
		system("pause");
	}
	return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* f;
    Employee* empleadoAux;
    int retorno = -1;
    int i, len, id, sueldo, horasTrabajadas;
    char nombre[100];

    f = fopen(path, "w");
    if(f != NULL && ll_len(pArrayListEmployee) > 0)
    {
        len = ll_len(pArrayListEmployee);
        fprintf(f, "id,nombre,horasTrabajadas,Sueldo\n");
        for(i=0; i<len; i++)
        {
            empleadoAux = (Employee*)ll_get(pArrayListEmployee, i);
            employee_getId(empleadoAux, &id);
            employee_getSueldo(empleadoAux, &sueldo);
            employee_getHorasTrabajadas(empleadoAux, &horasTrabajadas);
            employee_getNombre(empleadoAux, nombre);

            fprintf(f,"%d,%s,%d,%d\n", id, nombre, horasTrabajadas, sueldo);
        }
        printf(" \nArchivo guardado\n\n");
        system("pause");
        retorno = 0;
    }
    else
    {
        printf(" \nNo se pudo guardar el archivo\n");
        system("pause");
    }
    fclose(f);
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int i;
    int retorno = -1;
    int len;
    FILE* f;
    Employee* empleado;
    f = fopen(path, "wb");

    if(f != NULL && ll_len(pArrayListEmployee))
    {
        len = ll_len(pArrayListEmployee);
        for(i = 0; i < len; i++)
        {
            empleado = ll_get(pArrayListEmployee, i);
            fwrite(empleado, sizeof(Employee), 1, f);
        }
        printf(" \nArchivo binario guardado con exito\n");
        system("pause");
        retorno = 1;
    }
    else
    {
        printf(" \nNo se pudo guardar el archivo\n");
        system("pause");
    }
    fclose(f);
    return retorno;
}

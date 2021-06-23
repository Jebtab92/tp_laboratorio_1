#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"
#include "LinkedList.h"
#include "Employee.h"

/* \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee, int* lastID)
{

    int retorno = 0;
    Employee *pElement;
    char id[100];
    char nombre[100];
    char horasTrabajadas[100];
    char sueldo[100];
    int auxLastId = -1;

    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", id, id, id, id);

        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);

            pElement = employee_newParametros(id, nombre, horasTrabajadas, sueldo);

            if(pElement != NULL)
            {
                if(ll_add(pArrayListEmployee, pElement) == 0)
                {
                	if(atoi(id) > auxLastId)
                	{
                		auxLastId = atoi(id);
                	}
                    retorno++;
                }
            }
        }
    }
    if(retorno > 0)
    {
    	*lastID = auxLastId;
    }
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
	int retorno = 0;
    Employee empleado;
    Employee* pEmpleado;
    char id[100];
    char sueldo[100];
    char horasTrabajadas[100];
    int aux;

    if(pFile != NULL)
    {
        while(!feof(pFile))
        {
            aux = fread(&empleado, sizeof(Employee), 1, pFile);
            if(aux == 1)
            {
                if(feof(pFile))
                {
                    break;
                }
                else
                {
                    sprintf(id,"%d",empleado.id);
                    sprintf(horasTrabajadas, "%d",empleado.horasTrabajadas);
                    sprintf(sueldo,"%d",empleado.sueldo);
                    pEmpleado = employee_newParametros(id, empleado.nombre ,horasTrabajadas,sueldo);
                    ll_add(pArrayListEmployee, pEmpleado);
                }
            }
        }
    }
    return retorno;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "Biblioteca.h"


/*
 * \brief Crea el espacio en memoria dinamica con tamanio employee
 * \param void
 * \return puntero a employee
 */
Employee* employee_new()
{
    return (Employee*) malloc(sizeof (Employee));
}

/*
 * \brief Crea el espacio en memoria dinamica y completa los campos
 * \param *id, *nombre, *horas, *sueldo llama a las funciones setter
 * \return nueva direccion donde se encuentra el employee
 */
Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* aux;
    aux = employee_new();

    if(aux !=  NULL)
    {
        employee_setId(aux , atoi(idStr));
        employee_setNombre(aux, nombreStr);
        employee_setHorasTrabajadas(aux, atoi(horasTrabajadasStr));
        employee_setSueldo(aux, atoi(sueldoStr));
    }
    return aux;
}

/*
 * \brief Setea el id del employee
 * \param * a employee, id
 * \return 0 si funcion, -1 si hubo un error
 */
int employee_setId(Employee* this, int id)
{
    int Retorno = -1;

    if(this != NULL && id > 0)
    {
        (*this).id = id;
        Retorno = 0;
    }
    return Retorno;
}

/*
 * \brief Obtiene id del employee
 * \param * a un employee, *para escribir el id
 * \return 0 si funciono, -1 si hubo un error
 */
int employee_getId(Employee* this, int* id)
{
    int Retorno = -1;

    if(this != NULL && id != NULL)
    {
        *id = (*this).id;
        Retorno = 0;
    }
    return Retorno;
}

/*
 * \brief Setea el nombre del employee
 * \param * a employee, * a nombre
 * \return 0 si funcion, -1 si hubo un error
 */
int employee_setNombre(Employee* this, char* nombre)
{
    int Retorno = -1;

    if(this != NULL)
    {
         strcpy((*this).nombre, nombre);
    }
    return Retorno;
}

/*
 * \brief Obtiene nombre del employee
 * \param * a un employee, *para escribir el nombre
 * \return 0 si funciono, -1 si hubo un error
 */
int employee_getNombre(Employee* this, char* nombre)
{
    int Retorno = -1;

    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, (*this).nombre);
        Retorno = 1;
    }
    return Retorno;
}

/*
 * \brief Setea las horas trabajadas del employee
 * \param * a employee, horas trabajadas
 * \return 0 si funcion, -1 si hubo un error
 */
int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
    int Retorno = -1;

    if(this != NULL && horasTrabajadas > 0)
    {
        (*this).horasTrabajadas = horasTrabajadas;
        Retorno = 0;
    }
    return Retorno;
}

/*
 * \brief Obtiene horas trabajadas del employee
 * \param * a un employee, *para escribir las horas trabajadas
 * \return 0 si funciono, -1 si hubo un error
 */
int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
    int Retorno = -1;

    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = (*this).horasTrabajadas;
        Retorno=0;
    }
    return Retorno;
}

/*
 * \brief Setea sueldo del employee
 * \param * a employee, sueldo
 * \return 0 si funcion, -1 si hubo un error
 */
int employee_setSueldo(Employee* this, int sueldo)
{
    int Retorno = -1;

    if(this != NULL && sueldo > 0)
    {
        (*this).sueldo = sueldo;
        Retorno = 0;
    }
    return Retorno;
}

/*
 * \brief Obtiene sueldo del employee
 * \param * a un employee, *para escribir el sueldo
 * \return 0 si funciono, -1 si hubo un error
 */
int employee_getSueldo(Employee* this, int* sueldo)
{
    int Retorno=-1;

    if(this != NULL && sueldo != NULL)
    {
        *sueldo = (*this).sueldo;
        Retorno = 0;
    }
    return Retorno;
}

/*
 * \brief recibe un puntero al employee y la cambia a vacio
 * \param * a employee
 * \return void
 */
void employee_delete(Employee* lista)
{
    if(lista !=  NULL)
    {
        (*lista).id = 0;
        (*lista).horasTrabajadas = 0;
        (*lista).sueldo = 0;
        strcpy((*lista).nombre, "");
    }
    free(lista);
}

/*
 * \brief Imprime empleado
 * \param * a la lista de empleados, index a imprimir
 * \return 0 si funciono, -1 si hubo un error
 */
int employee_printEmployee(LinkedList* pArrayListEmployee, int index)
{
    Employee* empleadoAux;
    int id;
    char nombre[100];
    int horasTrabajadas;
    int sueldo;
    int Retorno = -1;

    if(pArrayListEmployee != NULL && index >= 0 && index < ll_len(pArrayListEmployee))
    {
        empleadoAux = (Employee*)ll_get(pArrayListEmployee, index);
        employee_getId(empleadoAux, &id);
        employee_getNombre(empleadoAux, nombre);
        employee_getHorasTrabajadas(empleadoAux, &horasTrabajadas);
        employee_getSueldo(empleadoAux, &sueldo);
        printf("|%10d | %20s | %20d | %10d  |\n", id, nombre, horasTrabajadas, sueldo);
        Retorno = 0;
    }
    return Retorno;
}

/*
 * \brief Ordenar por ID
 * \param recibe dos punteros a dos elementos
 * \return 1 si el puntero a es mayor al b o -1 si el puntero b es mayor al a, 0 si hubo error
 */
int employee_OrdenarID(void* elementoA, void* elementoB)
{
    int Retorno = 0;
    Employee* empleadoA;
    Employee* empleadoB;
    empleadoA = (Employee*)elementoA;
    empleadoB = (Employee*)elementoB;

    if((*empleadoA).id > (*empleadoB).id)
    {
        Retorno = 1;
    }
    else if((*empleadoA).id < (*empleadoB).id)
    {
        Retorno = -1;
    }
    return Retorno;
}

/*
 * \brief Ordenar por horas
 * \param recibe dos punteros a dos elementos
 * \return 1 si el puntero a es mayor al b o -1 si el puntero b es mayor al a, 0 si hubo error
 */
int employee_OrdenarHoras(void* elementoA, void* elementoB)
{
    int Retorno = 0;
    Employee* empleadoA;
    Employee* empleadoB;
    empleadoA = (Employee*)elementoA;
    empleadoB = (Employee*)elementoB;

    if((*empleadoA).horasTrabajadas > (*empleadoB).horasTrabajadas)
    {
        Retorno = 1;
    }
    else if((*empleadoA).horasTrabajadas < (*empleadoB).horasTrabajadas)
    {
        Retorno = -1;
    }
    return Retorno;
}

/*
 * \brief Ordenar por sueldo
 * \param recibe dos punteros a dos elementos
 * \return 1 si el puntero a es mayor al b o -1 si el puntero b es mayor al a, 0 si hubo error
 */
int employee_OrdenarSueldo(void* elementoA, void* elementoB)
{
    int Retorno = 0;
    Employee* empleadoA;
    Employee* empleadoB;
    empleadoA = (Employee*)elementoA;
    empleadoB = (Employee*)elementoB;

    if((*empleadoA).sueldo > (*empleadoB).sueldo)
    {
        Retorno = 1;
    }
    else if((*empleadoA).sueldo < (*empleadoB).sueldo)
    {
        Retorno = -1;
    }
    return Retorno;
}

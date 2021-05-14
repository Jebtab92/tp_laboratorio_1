/*
 * BibliotecaTp2.c
 *
 *  Created on: May 14, 2021
 *      Author: Jonatan Barbuto
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "BibliotecaTp2.h"

/**
 * \Brief Ingresa Texto para pedido, texto para error y un rango
 * \param Texto
 * \param Texto que corresponde al error(Ej: "La edad ingresada no existe. Intente nuevamente: ").
 * \return Numero ingresado
 */
int utn_GetNumber(char texto[], char textoError[], int min, int max)
{
	int auxMenu;
	int validacion = 1;

	do{
		printf("\n%s", texto);
		fflush(stdin);
		if(scanf("%d", &auxMenu))
		{
			if(ValidaMinMax(auxMenu, min, max))
			{
				validacion = 0;
			}
			else
			{
				printf("%s", textoError);
			}
		}
		else
		{
			printf("%s", textoError);
		}
	}while(validacion);

	return auxMenu;
}

/**
 * \Brief Ingresa numero y rango del mismo
 * \param Valida si el numero esta en rango
 * \return (0) para verdadero o (-1) para falso
 */
int ValidaMinMax(int numero, int min, int max)
{
    int valido = -1;

    if(numero > min && numero < max)
    {
        valido = 1;
    }
    return valido;
}

/**
 * \Brief Pide un flotante por pantalla, valida que se encuentre dentro de un rango.
 * \param Texto que corresponde al pedido(Ej: "Ingrese Suledo: ").
 * \param Texto que corresponde al error(Ej: "El sueldo ingresada no corresponde. Intente nuevamente: ").
 * \return Retorna el valor correspondiente al pedido.
 */
float utn_GetNumberFloat(char texto[], char textoError[], float min, float max)
{
	float datoIngresado;
	int validacion = 1;

	do
	{
		printf("\n%s", texto);
		fflush(stdin);

		if(scanf("%f", &datoIngresado))
		{
			if(ValidaMinMaxFloat(datoIngresado, min, max))
			{
				validacion = 0;
			}
			else
			{
				printf("%s",textoError);
			};
		}
		else
		{
			printf("%s",textoError);
		};

	}while(validacion);

	return datoIngresado;
}
/**
 * \Brief Valida el numero ingresado en TomaFlotante(); que se encuentre entre el min y max.
 * \param Numero flotante Ingresado por el Usuario.
 * \param Numero flotante minimo permitido.
 * \param Numero flotante maximo permitido.
 * \return (0) para verdadero o (-1) para falso
 */
int ValidaMinMaxFloat(float numero, float min, float max)
{
    int valido = -1;

    if(numero > min && numero < max)
    {
        valido = 1;
    }
    return valido;
}

/**
 * \brief Pide el ingreso de un dato string (cadena de char).
 * \param direccion donde guardara el array de char.
 * \param Texto que interactuara con el usuario.
 * \param tamanio del array
 * \return void
 */
void utn_GetName(char name[], char text[], char error[], int size)
{
	int validacion;

	do
	{
		printf("%s", text);
		fflush(stdin);
		scanf("%[^\n]", name);
		if(isName(name, size) != 1)
		{
			validacion = 0;
		}
		else
		{
			printf("%s\n", error);
			//validacion = 1;
		}

	}while(validacion);
}

/**
 * \brief valida lo ingresado en utn_GetName que efectivamente sean caracteres alfabeticos correspondientes a un nombre en castellano.
 * \param direccion de memoria del array donde se guardo el nombre.
 * \param cantidad limite de caracteres que pueden usarse sin desbordar el array name.
 * \return retorna 0 en caso de error o 1 en caso contrario.
 */
int isName(char* cadena, int limite)
{
	int retorno = 0;
	int i ;

	if(strlen(cadena) > 0)
	{
		for(i = 0; i < strlen(cadena); i++)
		{
			if(isalpha(cadena[i]) == 0)
			{
				retorno = 1;
				break;
			}
		}
	}

/*	for(i = 0 ; i<=limite && cadena[i] != '\0'; i++)
	{
		if((cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z') && (cadena[i]=='\0'))
		{
			retorno = 1;
			break;
		}
	}
	*/
	return retorno;
}
/**
 * \Brief Recorre un array y inicializa todas las posiciones en 0, liberando el espacion de posible basura.
 * \param Recibe el array que se desea inicializar
 * \param Numero entero correspondiente al tamanio del array.
 * \return void
 */
void utn_InitArrayInt(int array[], int size)
{

	for(int i = 0;  i < size ; i++)
	{
		array[i]=0;
	}
}

/**
 * \Brief Carga la primera posicion disponible de un array de enteros.
 * \param Recibe el array que se desea cargar.
 * \param Numero entero correspondiente al tamanio del array
 * \param Numero entero que se desea cargar en el array
 * \returnRetorna 1 en caso de carga exitosa o 0 en el caso contrario.
 */
int CargaSecuencialArrayInt(int array[], int size, int dato)
{
	int respuesta = 0;

	for (int i = 0; i < size; i++)
	{
		if(array[i] == 0)
		{
			array[i] = dato;
			respuesta = 1;
			break;
		}
	}
	return respuesta;
}

/**
 * \Brief Carga un dato en un array en la posicion indicada por el usuario.
 * \param Numero correspondiente al tamanio del array
 * \param Numero correspondiente al dato que se quiere cargar en el array
 * \param Numero correspondiente a la posicion en la que se desa cargar el array
 * \return Retorna 1 en caso de que la carga este correcta o cero en caso contrario.
 */
int CargaAleatoriaArrayInt(int array[], int size, int dato, int posicion)
{
	int respuesta = 0;

	for(int i = 0; i < size; i++)
	{
		if(posicion == i && array[i] == 0)
		{
			array[i] = dato;
			respuesta = 1;
			break;
		}
	}
	return respuesta;
}

/**
 * \Brief Recibe un array de enteros y lo muestra por pantalla mostrando su ID o posicion en el array
 * \param Array que se desea mostrar.
 * \param Texto correspondiente al dato que se va a mostrar
 * \return retorna 1 si existen datos para mostrar, o cero en caso contrario.
 */
int MostrarArrayInt(int array[], char text[], int size)
{
	int respuesta = 0;

	if(array != NULL && size >= 0)
	{
		respuesta = 1;

		for(int i = 0; i < size; i++)
		{
			printf("\nID: %d - %s: %d", i, text, array[i]);
		}
	}
	return respuesta;
}

/**
 * \Brief Ordena un array de mayor a menor por burbujeo
 * \param Recibe el array que se desea ordenar.
 * \param Recibe el tamanio del array a ordenar/
 * \return Retorna la cantidad de iteraciones que fueron necesarias para acomodar el array
 * \return o -1 en caso de no poder ordenarlo por algun error en el proseso de ordenado.
 */
int ordenarArrayInt(int array[], int size)
{
	int flagSwap;
	int contador = 0;
	int resultado = -1;
	int buffer;

	if(array != NULL && size >= 0)
	{
		do
		{
			flagSwap = 0;
			for(int i = 0; i < size-1; i++)
			{
				if(array[i] < array[i+1])
				{
					flagSwap = 1;
					buffer = array[i];
					array[i] = array[i+1];
					array[i+1] = buffer;
				}
				contador++;
			}
		}while(flagSwap);

		resultado = contador;
	}
	return resultado;
}

/**
 * \brief Realiza el formateo de un string colocando la primera letra en mayuscula
 * \param recibe la cadena a formatear
 * \param recibe el tamanio de la cadena a formatear
 * \return void
 */
void formatName(char name[], int size)
{
	char auxName[51];
	strcpy(auxName,name);

	for(int i = 0; i < 51; i++)
	{
		auxName[i] = tolower(auxName[i]);
	}
	auxName[0] = toupper(auxName[0]);
	strcpy(name,auxName);
}

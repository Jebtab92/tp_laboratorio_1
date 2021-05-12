/*
 * utn_library.h
 *
 *  Created on: May 9, 2021
 *      Author: Jonatan Barbuto
 */

#ifndef BIBLIOTECATP2_H_
#define BIBLIOTECATP2_H_

int utn_GetNumber(char texto[], char textoError[], int min, int max);
int ValidaMinMax(int numero, int min, int max);
float utn_GetNumberFloat(char texto[], char textoError[], float min, float max);
int ValidaMinMaxFloat(float dato, float min, float max);
void utn_GetName(char name[], char text[], char error[], int size);
int isName(char*cadena, int limite);
void utn_InitArrayInt(int array[], int size);
int CargaSecuencialArrayInt(int array[], int size, int dato);
int CargaAleatoriaArrayInt(int array[], int size, int dato, int posicion);
int MostrarArrayInt(int array[], char text[], int size);
int ordenarArrayInt(int array[], int size);
void formatName(char name[], int size);

#endif /* BIBLIOTECATP2_H_ */

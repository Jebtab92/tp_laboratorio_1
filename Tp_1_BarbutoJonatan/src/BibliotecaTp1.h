/*
 * BibliotecaTp1.h
 *
 *  Created on: 31 ago. 2019
 *      Author: Jonatan Barbuto
 */

#ifndef BIBLIOTECATP1_H_
#define BIBLIOTECATP1_H_
#include <stdio.h>

int mostrarMenu(int* eleccionMenu, int* numeroA, int* numeroB);
int sumar(int pNumeroA, int pNumeroB, int* pSuma);
int restar(int pNumeroA, int pNumeroB, int* pResta);
int multiplicar(int pNumeroA, int pNumeroB, int* pMultiplicacion);
int dividir(int pNumeroA, int pNumeroB, float* pDivision);
int factorizar(int pNumeroA, int pNumeroB,int* pFactorialA, int* pFactorialB);

#endif /* BIBLIOTECATP1_H_ */

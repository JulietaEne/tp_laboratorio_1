/*
 * arrays.h
 *
 *  Created on: 12 abr. 2022
 *      Author: julieta_enee
 */

#ifndef ARRAYS_H_
#define ARRAYS_H_

int array_inicializar(int unArray[], int sizeArray, int inicializar);
int array_asignarValorAUnaPosicion(int unArray[], int unaPosicion, int valor);
int array_imprimirArrayCompleto(int unArray[], int sizeArray);
int array_imprimirArraySinInicializados(int unArray[], int sizeArray);
int array_imprimirPosicionArray(int unArray[], int unaPosicion);
int array_cargarSecuencial(int unArray[], int sizeArray, int minimoPosible, int maximoPosible, int reintentos);
int array_cargarAleatorio(int unArray[], int sizeArray, int* indice, int valor);
int array_acumuladorPositivos(int unArray[], int sizeArray, int* acumuladorPositivos);
int array_acumuladorNegativos(int unArray[], int sizeArray, int* acumuladorNegativos);
int array_identificarMenorNumero(int unArray[], int sizeArray, int* menorNumero);

#endif /* ARRAYS_H_ */

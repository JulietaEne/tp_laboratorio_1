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
int array_imprimirArray(int unArray[], int sizeArray);
int array_imprimirPosicionArray(int unArray[], int unaPosicion);
int array_cargaSecuencial(int unArray[], int sizeArray, int minimoPosible, int maximoPosible, int reintentos);

#endif /* ARRAYS_H_ */

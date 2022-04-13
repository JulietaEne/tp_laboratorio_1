/*
 ============================================================================
 Name        : guias.c
 Author      : Julieta Nakasone
 Version     : 1
 Copyright   : Your copyright notice
 Description : guia de ejercicios
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "tp.h"
#include "arrays.h"

#define ARRAY 3
#define INICIALIZAR 0
#define MINIMO 0
#define MAXIMO 100
#define REINTENTOS 1

int array_cargarAleatorio(int unArray[], int sizeArray, int* indice, int valor);

int main(void) {

	int arrayNum[ARRAY];
	int ind;
	int valorIngresado;
	ind = 0;

	if(array_inicializar(arrayNum, ARRAY, INICIALIZAR)==0)
	{
		array_imprimirArray(arrayNum, ARRAY);
	}

	printf("\nCARGA DE VALORES PARA ARRAY (%d posiciones)\n", ARRAY);
	/*if(array_cargarSecuencial(arrayNum, ARRAY, MINIMO, MAXIMO, REINTENTOS)==0)
	{
		array_imprimirArray(arrayNum, ARRAY);
	}*/
	if(!utn_GetNumeroInt(&valorIngresado, "ingrese valor: ", "ERROR", MINIMO, MAXIMO, REINTENTOS)
			&& !array_cargarAleatorio(arrayNum, ARRAY, &ind, valorIngresado))
	{
		array_imprimirArray(arrayNum, ARRAY);
	}


}

int array_cargarAleatorio(int unArray[], int sizeArray, int* indice, int valor)
{
	int retorno;
	retorno = -1;

	if(unArray != NULL)
	{
		unArray[*indice] = valor;
		retorno = 0;
		*indice = *indice+1;
	}

	return retorno;
}






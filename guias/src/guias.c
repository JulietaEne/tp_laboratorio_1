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



int main(void) {

	int arrayNum[ARRAY];

	if(array_inicializar(arrayNum, ARRAY, INICIALIZAR)==0)
	{
		array_imprimirArray(arrayNum, ARRAY);
	}

	printf("\nCARGA DE VALORES PARA ARRAY (%d posiciones)\n", ARRAY);
	if(array_cargaSecuencial(arrayNum, ARRAY, MINIMO, MAXIMO, REINTENTOS)==0)
	{
		array_imprimirArray(arrayNum, ARRAY);
	}


}

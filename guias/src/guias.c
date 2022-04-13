/*
 ============================================================================
 Name        : guias.c
 Author      : Julieta Nakasone
 Version     : 1
 Copyright   : Your copyright notice
 Description : Ejercicio 5-3
			   Realizar un programa que permita el ingreso de 10 números enteros distintos de cero.
			   La carga deberá ser aleatoria (todos los elementos se inicializan en cero por default).

			   Determinar el promedio de los positivos,
			   y del menor de los negativos la suma de los antecesores
			   (Según la recta numérica de los reales, hasta llegar a cero).

			   Utilizar funciones y vectores.


1- identificar el menor negativo
2- sumar todos los negativos, restarles el menor de los negativos
 ============================================================================
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"
#include "tp.h"
#include "arrays.h"

#define ARRAY 5
#define INICIALIZAR 0
#define MINIMO -100
#define MAXIMO 100
#define REINTENTOS 1


//int identificarMenorNumero(int numeroAnalizado, int** menorNumero);

int main(void) {

	int arrayNum[ARRAY];
	int ind;
	int valorIngresado;
	int respuesta;
	int acumuladorPositivos;
	int cantidadPositivos;
	float promedio;
	int menorNumero;
	int acumuladorNegativos;

	ind = 0;
	acumuladorPositivos = 0;
	acumuladorNegativos = 0;

//inicializo el array
	if(array_inicializar(arrayNum, ARRAY, INICIALIZAR)==0)
	{
		array_imprimirArraySinInicializados(arrayNum, ARRAY);
	}

//carga de datos
	do{
		if(!utn_GetNumeroInt(&valorIngresado, "Ingrese valor: ", "ERROR", MINIMO, MAXIMO, REINTENTOS))
		{
			if(valorIngresado != 0 && !array_cargarAleatorio(arrayNum, ARRAY, &ind, valorIngresado))
			{
				array_imprimirArrayCompleto(arrayNum, ARRAY);
			}
			else
			{
				printf("ERROR el valor debe ser distinto de 0\n");
			}
		}
		respuesta= continuarY("\npresione 'Y' para cargar otro. Presione cualquier tecla para cancelar");

	}while(respuesta);

//analisis de datos
	cantidadPositivos= array_acumuladorPositivos(arrayNum, ARRAY, &acumuladorPositivos);
	if(cantidadPositivos>0)
	{
		//promedio= acumuladorPositivos/cantidadPositivos;
		promedio = (float)acumuladorPositivos/cantidadPositivos;
	}
	array_identificarMenorNumero(arrayNum, ARRAY, &menorNumero);
	array_acumuladorNegativos(arrayNum, ARRAY, &acumuladorNegativos);
	//printf("DEBUG Acumulador negativos: %d", acumuladorNegativos);
	acumuladorNegativos= acumuladorNegativos-menorNumero;

//Informes
	printf("\npromedio positivos: %.2f", promedio);
	//printf("menor numero: %d\n", menorNumero);
	printf("Sumatoria de negativos menos el menor numero: %d", acumuladorNegativos);



	return EXIT_SUCCESS;
}


/*int identificarMenorNumero(int numeroAnalizado, int** menorNumero)
{
	int retorno;
	retorno = -1;
	if(*menorNumero != NULL)
	{
		retorno =0;
		if(**menorNumero > numeroAnalizado)
		{
			**menorNumero = numeroAnalizado;
		}
	}
	return retorno;
}*/

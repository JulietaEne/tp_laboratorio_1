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

	float arrayNum[ARRAY];
	int indice;
	float valorIngresado;
	int respuesta;
	float acumuladorPositivos;
	float cantidadPositivos;
	float promedio;
	float menorNumero;
	float acumuladorNegativos;

	indice = 0;
	acumuladorPositivos = 0;
	acumuladorNegativos = 0;

//inicializo el array
	if(array_floatInicializar(arrayNum, ARRAY, INICIALIZAR)==0)
	{
		array_floatImprimirArraySinInicializados(arrayNum, ARRAY);
	}

//carga de datos
	do{
		if(!utn_GetNumeroFloat(&valorIngresado, "\nIngrese valor: ", "ERROR", MINIMO, MAXIMO, REINTENTOS))
		{
			if(valorIngresado != 0 && !array_floatCargarAleatorio(arrayNum, ARRAY, &indice, valorIngresado))
			{
				array_floatImprimirArrayCompleto(arrayNum, ARRAY);
			}
			else
			{
				printf("ERROR el valor debe ser distinto de 0\n");
				indice--;
			}
		}
		respuesta= continuarY("\npresione 'Y' para cargar otro. Presione cualquier tecla para cancelar");

		if(indice == ARRAY)
		{
			printf("\n****el array ha sido completamente cargado****\n");
			break;
		}
	}while(respuesta);

//analisis de datos
	cantidadPositivos= array_floatAcumuladorPositivos(arrayNum, ARRAY, &acumuladorPositivos);
	if(cantidadPositivos>0)
	{
		//promedio= acumuladorPositivos/cantidadPositivos;
		promedio = (float)acumuladorPositivos/cantidadPositivos;
	}
	array_floatIdentificarMenorNumero(arrayNum, ARRAY, &menorNumero);
	array_floatAcumuladorNegativos(arrayNum, ARRAY, &acumuladorNegativos);
	printf("\nDEBUG Acumulador negativos: %.2f - menor numero: %.2f\n", acumuladorNegativos, menorNumero);
	acumuladorNegativos= acumuladorNegativos-menorNumero;

//Informes
	printf("\nINFORMES\npromedio positivos: %.2f", promedio);
	//printf("menor numero: %d\n", menorNumero);
	printf("\nSumatoria de negativos menos el menor numero: %.2f", acumuladorNegativos);



	return EXIT_SUCCESS;
}

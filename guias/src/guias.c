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
#include <stdio_ext.h>
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
int opcionContinuar(char* mensaje);

int main(void) {

	int arrayNum[ARRAY];
	int ind;
	int valorIngresado;
	int respuesta;
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

	do{
		/*do
		{
			utn_GetNumeroInt(&valorIngresado, "Ingrese valor: ", "ERROR", MINIMO, MAXIMO, REINTENTOS);
		}while(valorIngresado == 0);PROBAR SI PODEMOS */

		if(!utn_GetNumeroInt(&valorIngresado, "Ingrese valor: ", "ERROR", MINIMO, MAXIMO, REINTENTOS))
		{
			if(valorIngresado != 0 && !array_cargarAleatorio(arrayNum, ARRAY, &ind, valorIngresado))
			{
				array_imprimirArray(arrayNum, ARRAY);
			}
			else
			{
				printf("ERROR el valor debe ser distinto de 0\n");
			}
		}

		respuesta= opcionContinuar("\npresione 'Y' para cargar otro. Presione cualquier tecla para cancelar");


	}while(!respuesta);
	printf("\nFINALIZANDO");



	return EXIT_SUCCESS;
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


int opcionContinuar(char* mensaje)
{
	int retorno;
	char respuesta;
	retorno = -1;

	printf("%s\nOpcion: ", mensaje);
	__fpurge(stdin);
	scanf("%c", &respuesta);
	if(respuesta == 'Y')
	{
		respuesta = 'y';
	}
	if(respuesta == 'y')
	{
		retorno = 0;
	}
	return retorno;
}

/*
		 * int opcionContinuar(char* mensaje, char respuesta)
		{
			int retorno;
			char buffer;
			int bufferInt;
			int respuestaInt;
			retorno =-1;

			printf("%s", mensaje);
			__fpurge(stdin);
			scanf("%c", &buffer);
			bufferInt= atoi(buffer);
			respuestaInt= atoi(respuesta);
			if(bufferInt+32 == respuestaInt)
			{

			}

			return retorno;
		}*/




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
#define MINIMO 0
#define MAXIMO 100
#define REINTENTOS 1


int array_acumuladorPositivos(int unArray[], int sizeArray, int* acumuladorPositivos);


int main(void) {

	int arrayNum[ARRAY];
	int ind;
	int valorIngresado;
	int respuesta;
	int acumuladorPositivos;
	int cantidadPositivos;
	float promedio;

	ind = 0;
	acumuladorPositivos = 0;

//inicializo el array
	if(array_inicializar(arrayNum, ARRAY, INICIALIZAR)==0)
	{
		array_imprimirArray(arrayNum, ARRAY);
	}

//carga de datos
	do{
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
		respuesta= continuarY("\npresione 'Y' para cargar otro. Presione cualquier tecla para cancelar");

	}while(respuesta);

//analisis de datos
	cantidadPositivos= array_acumuladorPositivos(arrayNum, ARRAY, &acumuladorPositivos);
	if(cantidadPositivos>0)
	{
		//promedio= acumuladorPositivos/cantidadPositivos;
		promedio = (float)acumuladorPositivos/cantidadPositivos;
	}


//Informes
	printf("acumulador: %d\n cantidad: %d\npromedio positivos: %.2f", acumuladorPositivos, cantidadPositivos, promedio);




	return EXIT_SUCCESS;
}

/*
 * \breif recorre el array recibido para acumular los numeros positivos
 * \param unArray[] Recibe por referencia el array sobre el cual trabajara
 * \param sizeArray Recibe por valor el tamaño del array con el que trabaja
 * \param *acumuladorPositivos Recibe por referencia un espacio de memoria para almacenar el acumulado de los valores positivos
 * \return retorna -1 si hubo un error en los parametros recibidos
 * 		   		    0 si no existen numeros positivos
 * 			   		>0 si existen positivos (la cantidad de positivos que se encontraron)
 *
 */
int array_acumuladorPositivos(int unArray[], int sizeArray, int* acumuladorPositivos)
{
	int i;
	int positivos;

	positivos = -1;

	if(unArray!= NULL && sizeArray>0)
	{
		positivos = 0;
		for(i=0; i<sizeArray; i++)
		{
			if(unArray[i]!= 0 && esPositivo(unArray[i])==1)
			{
				*acumuladorPositivos = *acumuladorPositivos+unArray[i];
				positivos++;
			}
		}
	}

	return positivos;
}



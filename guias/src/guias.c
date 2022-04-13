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

#define ARRAY 3
#define INICIALIZAR 0
#define MINIMO 0
#define MAXIMO 100
#define REINTENTOS 1


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

	//printf("\nCARGA DE VALORES PARA ARRAY (%d posiciones)\n", ARRAY);
	/*if(array_cargarSecuencial(arrayNum, ARRAY, MINIMO, MAXIMO, REINTENTOS)==0)
	{
		array_imprimirArray(arrayNum, ARRAY);
	}*/

	do{
		/*do
		{
			utn_GetNumeroInt(&valorIngresado, "Ingrese valor: ", "ERROR", MINIMO, MAXIMO, REINTENTOS);
		}while(valorIngresado == 0);PROBAR SI PODEMOS PONER OTRO MENSAJE EN OPCION CONTINUAR SI CARGO EL NUMERO 0*/

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
	printf("\nFINALIZANDO");



	return EXIT_SUCCESS;
}



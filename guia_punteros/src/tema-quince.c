/*
 ============================================================================
 Name        : tema-quince.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Nakasone Julieta
Ejercicio 15-5


 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "passenger.h"
#include "utn.h"
#include "arrays.h"
#include "tp.h"

#define QTY_ARRAY 10
#define QTY_VECTOR 5

int punteros_ordenarMenorMayor(int* numeroA, int* numeroB);
int array_informarSiEsContenidoEnArray(int* arrayContenedor, int sizeContenedor, int* arrayContenido, int sizeContenido);



int main(void) {

	/*
	 EJERCICIO 15-1
	 Realizar el ordenamiento de un vector de enteros.
 	 Para ello deberán crear una función que se encargue de realizar el intercambio de los dos valores
 	 que se van a ordenar (función swap), que solo puede recibir dos parámetros.


	int arrayEnteros[QTY_ARRAY]= {5, 1, 18, 3, 2, 21, 12, 9, 4, 15};
	printf("array cargado: \n");
	arrayInt_imprimirArrayCompleto(arrayEnteros, QTY_ARRAY);

	arrayInt_sortNumerosSinCriterio(arrayEnteros, QTY_ARRAY);
	printf("array ordenado: \n");
	arrayInt_imprimirArrayCompleto(arrayEnteros, QTY_ARRAY); */

	/*
	 EJERCICIO 15-2
	 Realizar una función que reciba como parámetro un puntero a entero.
	 La función le pedirá al usuario que cargue un valor por medio del puntero.
	 Retornará si pudo cargarlo o no.

	printf("***************************************************\n\n");
	int unNumero;
	int retornoFuncion;
	retornoFuncion = puntero_cargarInt(&unNumero);

	if(retornoFuncion==0)
	{
		printf("\nEl numero ingresado se ha cargado exitosamente");
	}
	else
	{
		printf("\nERROR**** No se ha podido cargar el numero ingresado");
	}*/

	/*
	 EJERCICIO 15-5
	 Escriba una función que reciba dos números enteros y los devuelva ordenados.
	 Es decir que en el primer parámetro debe devolver el menor valor y en el 2do. el mayor.

	printf("\n\n***************************************************\n\n");
	int numeroMenor= 10;
	int numeroMayor= 9;
	printf("\nDEBUG variable menor: %d, variable mayor: %d", numeroMenor, numeroMayor);

	punteros_ordenarMenorMayor(&numeroMenor, &numeroMayor);
	printf("\n\nnumero menor: %d, numero mayor: %d", numeroMenor, numeroMayor); */


	/*
	 EJERCICIO 15-5
	 Realizar una función que reciba como parámetros dos vectores.
	 La función deberá determinar si el segundo vector está contenido en el primero.

	printf("\n\n***************************************************\n\n");

	int arrayInt[QTY_ARRAY]= {5, 1, 18, 3, 2, 21, 12, 9, 4, 15};
	int vectorDentroDeArray[QTY_VECTOR]= {18, 3, 2, 21, 12};
	int vectorNoDentroDeArray[QTY_VECTOR]= {1,2,3,4,11};

	printf("\nprimer array: ");
	arrayInt_imprimirArrayCompleto(arrayInt, QTY_ARRAY);

	printf("\n\nsegundo array: ");
	arrayInt_imprimirArrayCompleto(vectorDentroDeArray, QTY_VECTOR);
	if(!array_informarSiEsContenidoEnArray(arrayInt, QTY_ARRAY, vectorDentroDeArray, QTY_VECTOR))
	{
		printf("el segundo array es contenido por el primero");
	}
	printf("\n\ntercer array: ");
	arrayInt_imprimirArrayCompleto(vectorNoDentroDeArray, QTY_VECTOR);
	if(!array_informarSiEsContenidoEnArray(arrayInt, QTY_ARRAY, vectorNoDentroDeArray, QTY_VECTOR))
	{
		printf("el tercer array es contenido por el primero");
	}
	else
	{
		printf("el tercer array no es contenido por el primero");
	}*/

	/*
		 EJERCICIO 15-5 ANEXO1
			Realizar una función que reciba un puntero a char y dos char.
			La función deberá reemplazar en la cadena cada ocurrencia del primer carácter recibido,
			por el segundo. Retornando la cantidad de reemplazos o -1 en caso de error.


		printf("\n\n***************************************************\n\n");
		char unString[QTY_ARRAY]={"maraton"} ;
		int retornoFuncion;

		printf("array: '%s'\n", unString);
		retornoFuncion=arrayChar_reemplazarCaracter(unString, QTY_ARRAY, 'a', 'x');
		printf("Cantidad de reemplazos: %d -  array con reemplazos: '%s'\n", retornoFuncion, unString);*/

		/*
		 EJERCICIO 15-5 ANEXO2
		 	Realizar una función que reciba como parámetros un array de enteros y un entero por referencia.
			La función calculará el valor máximo de ese array y utilizará el valor por referencia para retornar ese valor.
		 */

		printf("\n\n***************************************************\n\n");
		int arrayInt[QTY_ARRAY]= {5, 1, 18, 3, 2, 21, 12, 9, 4, 15};
		int mayorNumeroHallado;

		arrayInt_imprimirArrayCompleto(arrayInt, QTY_ARRAY);
		array_identificarMenorNumero(arrayInt, QTY_ARRAY, &mayorNumeroHallado);
		printf("mayor numero del array: %d", mayorNumeroHallado);
}

/*
 * \breif Analiza dos cadenas para indicar si la segunda está contenida dentro de la primera
 * \param int* arrayContenedor Recibe por referencia el array que analizara
 * \param int sizeContenedor Recibe por valor el tamaño del array que analizara
 * \param int* arrayContenido Recibe por valor array que usara para la comparacion del analisis
 * \param int sizeContenido Recibe por valor el tamaño del array que analizara
 * 																	 2 ordena de forma descendente
 * \return retorna -1 si hubo un error en los parametros recibidos
 * 		   		   -2 si el segundo array no es contenido dentro del primero
 * 			   	   0 si el array analizado es contenedor del array comparado
 *
 */
int array_informarSiEsContenidoEnArray(int* arrayContenedor, int sizeContenedor, int* arrayContenido, int sizeContenido)
{
	int retorno;
	int i;
	int j;
	int contador;

	retorno = -1;
	contador = 0;
	if(arrayContenedor!= NULL && sizeContenedor >0 && arrayContenido != NULL && sizeContenido >0 && sizeContenido<sizeContenedor)
	{
		retorno = -2;
		for(i=0; i<sizeContenedor; i++)
		{
			for(j=0;j<sizeContenido; j++)
			{
				if(arrayContenedor[i]== arrayContenido[j])
				{
					contador++;
				}
			}
		}
		if(contador == sizeContenido)
		{
			retorno = 0;
		}
	}
	return retorno;
}


int punteros_ordenarMenorMayor(int* numeroA, int* numeroB)
{
	int retorno;
	int aux;

	retorno = -1;
	if(numeroA != NULL && numeroB != NULL)
	{
		if(*numeroB < *numeroA)
		{
			aux = *numeroB;
			*numeroB = *numeroA;
			*numeroA = aux;
		}
		retorno =0;
	}
	return retorno;
}

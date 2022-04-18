/*
 ============================================================================
 Name        : guias.c
 Author      : Julieta Nakasone
 Version     : 1
 Copyright   : Your copyright notice
 Description : 	Ejercicio 6-3:
				Pedirle al usuario su nombre y apellido (en variables separadas, una para el nombre y otra para el apellido).
				Ninguna de las dos variables se puede modificar.

				Debemos lograr guardar en una tercer variable el apellido y el nombre con el siguiente formato:
				Por ejemplo ->	Si el nombre es juan ignacio y el apellido es gOmEz, la salida debería ser:

				Gomez, Juan Ignacio

 ============================================================================
 */
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "tp.h"
#include "arrays.h"
#include "validaciones.h"

#define STR 41
#define STR2 81
#define INICIALIZAR -101
#define MINIMO -100
#define MAXIMO 100
#define REINTENTOS 1


int main(void)
{

	char nombre[STR];
	//int retorno;
	char apellido[STR];
	char apellidoNombre[STR2];

	if(	!utn_ingresarAlfabetica(nombre, STR, "nombre: ", "ingrese un dato valido", REINTENTOS)
		&& !utn_ingresarAlfabetica(apellido, STR, "apellido: ", "**ERROR** por favor ingrese un apellido\n", REINTENTOS)
		&& validaciones_esNombre(nombre, STR)>0
		&& validaciones_esNombre(apellido, STR)>0)
	{
		array_visualizarApellidoNombre(nombre, apellido, apellidoNombre, STR2);
		printf("%s", apellidoNombre);
	}


	return EXIT_SUCCESS;
}


/*
 *
 * utn_ingresarAlfabetica(nombre, STR, "nombre: ", "**ERROR** por favor ingrese un nombre\n", REINTENTOS);
	utn_ingresarAlfabetica(apellido, STR, "apellido: ", "**ERROR** por favor ingrese un apellido\n", REINTENTOS);
	//if(		!utn_ingresarAlfabetica(nombre, STR, "nombre: ", "**ERROR** por favor ingrese un nombre\n", REINTENTOS)
		//	&& !utn_ingresarAlfabetica(apellido, STR, "apellido: ", "**ERROR** por favor ingrese un apellido\n", REINTENTOS))
	{
		printf("\n todo ok nombre: %s, apellido: %s", nombre, apellido);
		array_visualizarApellidoNombre(nombre, apellido, apellidoYNombre, STR*2);
	}
 *
 *
 *
 ============================================================================
 Name        : guias.c
 Author      : Julieta Nakasone
 Version     : 1
 Copyright   : Your copyright notice
 Description :  Ejercicio 6-2:

                Realizar un programa que permita el ingreso de 10 números enteros
                (positivos y negativos).

                Necesito generar un listado de los números positivos de manera creciente
                y negativos de manera decreciente.

                (Como máximo 5 estructuras repetitivas)
                Ejemplo:


                Listado 1 : 4, 5, 6, 10, 18, 29
                Listado 2 : -1,-5,-9,-12


 ============================================================================


#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"
#include "tp.h"
#include "arrays.h"

#define ARRAY 5
#define INICIALIZAR -101
#define MINIMO -100
#define MAXIMO 100
#define REINTENTOS 1



//int identificarMenorNumero(int numeroAnalizado, int** menorNumero);

int main(void)
{
	int numEnteros[ARRAY];
	int numPositivos[ARRAY];
	int numNegativos[ARRAY];
	int flag;
	int i;
	int indicePositivos;
	int indiceNegativos;
	indicePositivos=0;
	indiceNegativos=0;
	flag = 0;

	if(!array_cargarSecuencial(numEnteros, ARRAY, MINIMO, MAXIMO, REINTENTOS))//carga de datos
	{
	    flag=1;
	   // printf("[DEBUG]array cargado\n");
	}
	if( !array_inicializar(numPositivos, ARRAY, INICIALIZAR) &&
        !array_inicializar(numNegativos, ARRAY, INICIALIZAR) &&
        flag == 1)
    {
        //printf("[DEBUG]inicializados\n");
        flag=2;
    }
    if(flag == 2)
    {
        flag =3; //analisis de datos
        for(i=0; i<ARRAY; i++)
        {
           // printf("DEBUG EN EL FOR\n");
            if(esPositivo(numEnteros[i]))
            {
               // printf("hay positivos\n");
                array_cargarAleatorio(numPositivos, ARRAY, &indicePositivos, numEnteros[i]);
            }
            else
            {
                if(numEnteros[i]!=0)
                {
                    array_cargarAleatorio(numNegativos, ARRAY, &indiceNegativos, numEnteros[i]);
                }
                //printf("hay negativos\n");
            }
        }
    }
    //falta ordenar los positivos y los negativos
    printf("\nINFORME\n");

    if(indicePositivos >0 && !array_sortNumeros(numPositivos, ARRAY, 1))
    {
        printf("positivos en forma creciente: \n");
        array_imprimirArraySinInicializados(numPositivos, ARRAY);
    }
    else
    {
        printf("no hay numeros positivos\n");
    }

    if(indiceNegativos >0 && !array_sortNumeros(numNegativos, ARRAY, 2))
    {
        printf("negativos en forma decreciente: \n");
        array_imprimirArraySinInicializados(numNegativos, ARRAY);
    }
    else
    {
        printf("no hay numeros negativos\n");
    }


	return EXIT_SUCCESS;
}*/


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
	//printf("\nDEBUG Acumulador negativos: %.2f - menor numero: %.2f\n", acumuladorNegativos, menorNumero);
	acumuladorNegativos= acumuladorNegativos-menorNumero;

//Informes
	printf("\nINFORMES\npromedio positivos: %.2f", promedio);
	//printf("menor numero: %d\n", menorNumero);
	printf("\nSumatoria de negativos menos el menor numero: %.2f", acumuladorNegativos);



	return EXIT_SUCCESS;
}
 */

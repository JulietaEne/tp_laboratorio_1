/*
 * arrays.c
 *
 *  Created on: 12 abr. 2022
 *      Author: julieta_enee
 */
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "tp.h"
#include "arrays.h"


/*
 * \breif recorre el array recibido para asignar el valor indicado en cada posicion (se sirve de funcion asignarValor..)
 * \param unArray[] Recibe por referencia el array sobre el cual trabajara
 * \param sizeArray Recibe por valor el tamaño del array con el que trabaja
 * \param inicializar Recibe por valor el dato que se asigna a cada posicion
 * \return retorna -1 si hubo un error en los parametros recibidos
 * 		   retorna 0 si no hubo error
 *
 */
int array_inicializar(int unArray[], int sizeArray, int inicializar)
{
	int retorno;
	int i;
	retorno = -1;

	if(unArray != NULL && sizeArray>0)
	{
		retorno = 0;
		for (i=0; i<sizeArray; i++)
		{
			array_asignarValorAUnaPosicion(unArray, i, inicializar);
		}
	}

	return retorno;
}

/*
 * \breif asigna un valor a la posicion indicada del array
 * \param unArray[] Recibe por referencia el array sobre el cual trabajara
 * \param unaPosicion Recibe por valor el indice sobre el cual se asignara el dato
 * \param valor Recibe por valor el dato que se asigna
 * \return retorna -1 si hubo un error en los parametros recibidos
 * 		   retorna 0 si opero exitosamente
 *
 */
int array_asignarValorAUnaPosicion(int unArray[], int unaPosicion, int valor)
{
	int retorno;
	retorno = -1;

	if(unArray!= NULL)
	{
		unArray[unaPosicion] = valor;
		retorno = 0;
	}

	return retorno;
}

/*
 * \breif asigna un valor a la posicion indicada del array
 * \param unArray[] Recibe por referencia el array sobre el cual trabajara
 * \param unaPosicion Recibe por valor el indice sobre el cual se asignara el dato
 * \param valor Recibe por valor el dato que se asigna
 * \return retorna -1 si hubo un error en los parametros recibidos
 * 		   retorna 0 si opero exitosamente
 *
 */
int array_imprimirArray(int unArray[], int sizeArray)
{
	int retorno;
	int i;
	retorno = -1;

	if(unArray!= NULL && sizeArray >0)
	{
		retorno = 0;
		for (i = 0; i<sizeArray; i++)
		{
			printf("%d ", unArray[i]);
			//array_imprimirPosicionArray(unArray, i);

			/*if(i== sizeArray-1)
			{
				printf("\n");
			}*/
		}
	}

	return retorno;
}

/*
int array_imprimirArray(int unArray[], int sizeArray)
{
	int retorno;
	int i;
	retorno = -1;

	if(unArray!= NULL && sizeArray >0)
	{
		retorno = 0;
		for (i = 0; i<sizeArray; i++)
		{
			if(i==0)
			{
				printf("\n");
			}
			printf("%d ", unArray[i]);

			if(i== sizeArray-1)
			{
				printf("\n");
			}
		}
	}

	return retorno;
}
 */


int array_imprimirPosicionArray(int unArray[], int unaPosicion)
{
	int retorno;
	retorno = -1;

	if(unArray!= NULL)
	{
		retorno = 0;
		/*if(unaPosicion==0)
		{
			printf("\n");
		}*/
		printf("%d ", unArray[unaPosicion]);
	}

	return retorno;
}

int array_cargaSecuencial(int unArray[], int sizeArray, int minimoPosible, int maximoPosible, int reintentos)
{
	int retorno;
	int i;
	retorno = -1;

	if(unArray != NULL && sizeArray>0)
	{
		retorno = 0;
		for (i=0; i<sizeArray; i++)
		{
			printf("%d ", i+1);
			utn_GetNumeroInt(&unArray[i], "ingrese valor: ", "[ERROR] ", minimoPosible, maximoPosible, reintentos);
		}
	}

	return retorno;
}

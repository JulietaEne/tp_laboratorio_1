/*
 * fly.c
 *
 *  Created on: 27 abr. 2022
 *      Author: julieta_enee
 */


#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "arrays.h"
#include "tp.h"

//Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’
/**
 * recorro el array
 * 	guardo el primer codigo de .flycode
 *
 *
 */
int pass_mostrarListadoCodigosVuelo(Passenger* listPass, int sizeArray)
{
	int retorno;
	int i;
	char auxCod[SIZE_CODE];
	int comparacion;
	retorno =-1;
	if(listPass!= NULL && sizeArray>0)
	{
		retorno =0;
		for (i=0; i<sizeArray; i++)
		{
			/*if(i==0)
			{
				strncpy(auxCod, listPass[i].flycode, SIZE_CODE);
				printf("");
			}
			comparacion= strncmp(auxCod, listPass[i+1].flycode, SIZE_CODE);*/
	}
	return retorno;
}


int pass_ordenarArrayPorCodigo(Passenger* listPass, int sizeArray, int criterio)//sortPassengersByCode
{
	int retorno;
	retorno =-1;
	if(listPass!= NULL && sizeArray>0)
	{
		retorno =0;
	}
	return retorno;
}

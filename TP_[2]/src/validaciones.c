/*
 * validaciones.c
 *
 *  Created on: 17 abr. 2022
 *      Author: julieta_enee
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "tp.h"
#include "arrays.h"

#define STR 41
#define LEN_MINIMO_NOMBRE 3

static int eliminarEspaciosAdelante(char unString[], int sizeString);
static int eliminarEspaciosExtra(char unString[], int sizeString);
static int convertirASustantivoPropio(char unString[], int sizeString);

/*
 * retorna 1 si encontro espacios adelante del nombre
 */
static int eliminarEspaciosAdelante(char unString[], int sizeString)
{
	int retorno;
	int i;
	int j;
	retorno = -1;
	if(unString != NULL && sizeString > 0)
	{
		retorno = 0;
		for(i = 0; i < sizeString; i++)
		{
			if(i==0)
			{
				while(unString[i]== ' ')
				{
					retorno = 1;
					for(j = 0; j < sizeString; j++)
					{
						unString[j]=unString[j+1];
					}
				}
			}
		}
	}

	return retorno;
}
/*
 * retorna 1 si encontro al menos un espacio extra
 */
static int eliminarEspaciosExtra(char unString[], int sizeString)
{
	int retorno;
	int i;
	int j;
	retorno = -1;
	if(unString != NULL && sizeString >0)
	{
		retorno = 0;
		for(i = 0; i < sizeString; i++)
		{
			if(unString[i]== ' ')
			{
				while(unString[i+1]== ' ')
				{
					retorno=1;
					for(j = i; j < sizeString; j++)
					{
						unString[j]=unString[j+1];
					}
				}
			}
		}
	}
	return retorno;
}

/*
 * retorna 0 si trabajo correctamente
 * 		   >0 si encontro mas de 1 palabra (el valor que retorne sera la cantidad de palabras que encontro)
 */
static int convertirASustantivoPropio(char unString[], int sizeString)
{
	int retorno;
	int i;
	retorno = -1;
	if(unString != NULL && sizeString >0)
	{
		retorno =0;
		for(i = 0; i < sizeString; i++)
		{
			if(i==0)
			{
				convertirAMayuscula(&unString[i]);
				retorno=1;
			}
			if(unString[i] == ' ')
			{
				convertirAMayuscula(&unString[i+1]);
				retorno++;
			}
		}
	}
	return retorno;
}

/*
 *
 * \breif analiza la cadena recibida para dar formato de nombre y
 * 		  validar que no contenga más de 3 palabras y que contenga al menos 3 letras
 * \param unString recibe la direccion de memoria del primer elemento del array que se analizara
 * \param sizeString Recibe por valor el tamaño del array
 * \return retorna -1 si hubo un error en los parametros recibidos
 * 		   retorna -2 si hubo un error en la interaccion con el usuario
 * 		   retorna 0 si la operacion se realizo correctamente
 *
 */
int validaciones_esNombre(char unString[], int sizeString)
{
	int retorno;
	//int j;
	//int cuenta;

	retorno = -1;
	if(unString != NULL && sizeString > 0)
	{
		retorno =0;
		if(strlen(unString)>=LEN_MINIMO_NOMBRE)
		{
			retorno =1;
			eliminarEspaciosAdelante(unString, sizeString);
			eliminarEspaciosExtra(unString, sizeString);
			array_convertirStringMinuscula(unString, sizeString);
			if(convertirASustantivoPropio(unString, sizeString)>3)
			{
				retorno=-2;
			}
		}
	}
	return retorno;
}



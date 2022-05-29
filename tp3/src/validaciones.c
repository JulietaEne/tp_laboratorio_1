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
#define LEN_MINIMO_NOMBRE 2

static int eliminarEspaciosAdelante(char unString[], int sizeString);
static int eliminarEspaciosExtra(char unString[], int sizeString);
//static int convertirASustantivoPropio(char unString[], int sizeString);

/*
 * \brief Analiza el array recibido y en caso de encontrar espacios antes del primer caracter, los sobreexcribe con los caracteres correspondientes
 * \param unString char[] Recibe la direccion de memoria del array a analizar
 * \param sizeListPass int Recibe por valor el tamaño del array
 * \return retorna -1 si hubo un error en los parametros recibidos
 * 		    0 si realizo la operacion pero no encontro espacios
 *		    1 si elimino espacios (al menos uno)
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
 * \brief Analiza el array recibido y en caso de encontrar espacios en cualquier posicion de la cadena, los sobreesccribe con el caracter correspondiente
 * \param unString char[] Recibe la direccion de memoria del array a analizar
 * \param sizeListPass int Recibe por valor el tamaño del array
 * \return retorna -1 si hubo un error en los parametros recibidos
 * 		    0 si realizo la operacion pero no encontro espacios
 *		    1 si elimino espacios (al menos uno)
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
 *
 * \breif analiza la cadena recibida para dar formato de nombre y
 * 		  validar que no contenga más de 3 palabras y que contenga al menos 3 letras
 * \param unString recibe la direccion de memoria del primer elemento del array que se analizara
 * \param sizeString Recibe por valor el tamaño del array
 * \return retorna -1 si hubo un error en los parametros recibidos
 * 		   -2 si hubo un error en la interaccion con el usuario
 *		   -3 si se trata de una cadena compuesta por mas de 3 palabras
 * 		   0 si la operacion se realizo correctamente
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
		retorno =-2;
		if(strlen(unString)>=LEN_MINIMO_NOMBRE)
		{
			retorno =0;
			eliminarEspaciosAdelante(unString, sizeString);
			eliminarEspaciosExtra(unString, sizeString);
			arrayChar_convertirStringMinuscula(unString, sizeString);
			if(arrayChar_convertirASustantivoPropio(unString, sizeString)>3)
			{
				retorno=-3;
			}
		}
	}
	return retorno;
}


/**
 * \brief valida si la variable recibida contiene un valor identico al del segundo parámetro
 * \param variable Recibe por valor la variable que sera analizada
 * \param valor Recibe por valor el dato contra el cual se compara
 * \return Retorna 0 si es falso
 * 		   1 si es verdadero
 *
 */
int validacionesInt_sonIdenticos(int variable, int valor)
{
	int retorno;
	retorno = 0;
	if(variable == valor)
	{
		retorno = 1;
	}
	return retorno;
}

int validaciones_EsCodigoTresLetrasYNumero(char unString[], int sizeString)
{
	int retorno;
	//int j;
	//int cuenta;

	retorno = -1;
//	printf("es codigo letra y numero");
	if(unString != NULL && sizeString > 0)
	{
		retorno =-2;
		if(strlen(unString)>=LEN_MINIMO_NOMBRE)
		{

			eliminarEspaciosAdelante(unString, sizeString);
			eliminarEspaciosExtra(unString, sizeString);
			arrayChar_convertirStringMinuscula(unString, sizeString);
			if(!arrayChar_plusInt(unString, sizeString))
			{
				retorno =0;
				//printf("hola");
			}
		}
	}
	return retorno;
}

/**
 * \brief 	Verifica si cada dato de la cadena ingresada es un dato numerico int (contempla negativos)
 * \param pCadena char* Cadena de caracteres a ser analizada
 * \param limite int Indica la longitud de la cadena trabajada
 * \return Retorna 1(verdadero) si la cadena es numerica
 *		   0(falso) si no lo es
 * 			//PORQUE LAS FUNCIONES QUE SON TIPO PREGUNTA, DEVUELVEN SI ES V(1) Ó F(0)
 */
int validaciones_esNumeroInt(char* pCadena, int limite)
{
	int retorno= 1;
	int flagFlotante=0;
	int i;
	for (i=0; i<limite && pCadena[i] != '\0'; i++) //LIMITE POR DOBLE CRITERIO: voy a recorrer mientras no me haya pasado del límite y mientras no encuentre un \0
	{
		if(i==0 && (pCadena[i] == '+' || pCadena[i]== '-'))
		{
			continue; //ejecuta de nuevo el for
		}
		if(pCadena[i] < '0' || pCadena [i] > '9')
		{
			//printf("estoy en el %d : %c - %d\n", i , pCadena[i], pCadena[i]);
			retorno=0;
			break;
		}
	}
	if (flagFlotante > 1)
	{
		retorno = 0;//acá hay muchos puntitos
	}
	//printf("retorno función esEntero %d", retorno);
	return retorno;
}

/**
 * \brief 	Verifica si cada dato de la cadena ingresada es un dato flotante (contempla negativos)
 * \param pCadena char* Cadena de caracteres a ser analizada
 * \param limite int Indica la longitud de la cadena trabajada
 * \return Retorna 1(verdadero) si la cadena es numerica
 *		  		   0(falso) si no lo es
 *
 */
int validaciones_esNumeroFlotante(char* pCadena, int limite)
{
	int retorno= 1;
	int contadorFlotante=0;
	int i;

	for (i=0; i<limite && pCadena[i] != '\0'; i++) //LIMITE POR DOBLE CRITERIO: voy a recorrer mientras no me haya pasado del límite y mientras no encuentre un \0
	{
		if(i==0 && (pCadena[i] == '+' || pCadena[i]== '-'))
		{
			continue; //ejecuta de nuevo el for
		}
		if(pCadena[i] < '0' || pCadena [i] > '9')
		{
			if(pCadena[i]=='.' && contadorFlotante ==0)
			{
				contadorFlotante++;
			}
			else
			{
				//printf("estoy en el %d : %c - %d\n", i , pCadena[i], pCadena[i]);
				retorno=0;
				break;
			}
		}
	}
	//printf("retorno función esFlotante %d", retorno);
	return retorno;
}

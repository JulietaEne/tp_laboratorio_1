/*
 * utn.c
 *
 *  Created on: 3 ago. 2021
 *      Author: julieta_enee
 */

#include <stdio_ext.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

//firmas para funciones internas

static int esEntero(char* pCadena, int limite);
static int esFlotante(char* pCadena, int limite);
static int getInt(int* pRespuesta);
static int getFloat(float* pRespuesta);

//a partir de aca desarrollo mis funciones

/**
 * \brief 	Lee el stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * 			un maximo de 'longitud - 1' caracteres. EN ÉSTA FUNCION, MARCA ERROR SI EL USUARIO
 *          INGRESA MAS CARACTERES DE LO SOLICITADO.######TAMBIEN ME SIRVE PARA LEVANTAR UN ARRAY CHAR :D###########
 * \param *cadena Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Indica la longitud de la cadena trabajada
 * \return Retorna 0 si se obtiene la cadena exitosamente, y -1 si ha encontrado un error.
 *
 */
int myGets_prueba(char* pCadena, int len)
{
	int retorno= -1;
	char bufferString [4096]; //**********************
	if(pCadena != NULL && len >0)
	{
		__fpurge(stdin);
		//fflush(stdin); windows
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1]=='\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= len)
			{
				strncpy(pCadena, bufferString, len);
				//retorno = printf("entro a mygets, obvio --->");
				retorno =0;
			}
		}
	}
	//printf("retorno funcion myGets %d", retorno);
	return retorno;
}

/**
 * \brief 	Verifica si cada dato de la cadena ingresada es un dato flotante (contempla negativos)
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1(verdadero) si la cadena es numerica y 0(falso) si no lo es
 *
 */
static int esFlotante(char* pCadena, int limite)
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
	//printf("retorno funcion esFlotante %d", retorno);
	return retorno;
}

/**
 * #####probando con myGets_prueba
 * \brief 	Solicita un dato desde la terminal (se sirve de myGets) y
 * 			busca haber obtenido un numero flotante (se sirve de esNumerica)
 * \param *pRespuesta Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 si se obtiene un numero entero exitosamente y -1 si ha encontrado un error.
 *
 */
static int getFloat(float* pRespuesta)
{
	int retorno= -1;
	char buffer[4096]; // por que en la clase 7 se usa un buffer de 128?
	if(pRespuesta!=NULL)
	{
		if(myGets_prueba(buffer, sizeof(buffer))==0 && esFlotante(buffer,sizeof(buffer))==1)
			{
				//retorno=printf("\nentro a getFloat");
				retorno=0;
				*pRespuesta = atof(buffer);
			}
	}

	//printf("--->retorno funcion getFloat: %d", retorno);
	return retorno;
}

/**
 * \brief 	Solicita un numero al usuario(se sirve de getFloat), luego de verificarlo devuelve el resultado
 * \param *pRespuesta Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param *mensaje Es el mensaje a ser mostrado
 * \param *mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero minimo a ser aceptado
 * \param maximo Es el numero maximo a ser aceptado
 * \param reintentos Cantidad de reintentos posibles, luego del primer uso de la funcion
 * \return Retorna 0 si se obtuvo exitosamente el numero y -1 si no se obtuvo
 *
 */
int utn_GetNumeroFloat(float* pRespuesta, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	int retorno=-1;
	float bufferFloat;


	if(pRespuesta != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s", mensaje);
			__fpurge(stdin);
			//fflush(stdin); windows

			//scanf("%f", &bufferFloat);
			if(getFloat(&bufferFloat)==0 && bufferFloat >= minimo && bufferFloat <= maximo)
			{
				*pRespuesta= bufferFloat;
				//retorno=printf("\nentro a getNumeroFloat");
				retorno = 0;
				break;
			}
			printf("%s", mensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}
	//printf("--->retorno de funcion %d", retorno);
	return retorno;
}

/**
 * \brief 	Verifica si cada dato de la cadena ingresada es un dato numerico int (contempla negativos)
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1(verdadero) si la cadena es numerica y 0(falso) si no lo es
 * 			//PORQUE LAS FUNCIONES QUE SON TIPO PREGUNTA, DEVUELVEN SI ES V(1) Ó F(0)
 */
static int esEntero(char* pCadena, int limite) //tengo que hacer uno para flotante
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
		retorno = 0;//aca hay muchos puntitos
	}
	//printf("retorno funcion esEntero %d", retorno);
	return retorno;
}

/** #####probando con myGets_prueba + ARREGLOS
 * \brief 	Solicita un dato desde la terminal (se sirve de myGets) y
 * 			busca haber obtenido un numero entero (se sirve de esNumerica)
 * \param *pRespuesta Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 si se obtiene un numero entero exitosamente y -1 si ha encontrado un error.
 *
 */
static int getInt(int* pRespuesta)
{
	int retorno= -1;
	char bufferString[4096];
	if (pRespuesta != NULL &&
		myGets_prueba(bufferString, sizeof(bufferString))==0 &&	 //recordar que es lo mismo myGets_prueba(bufferString, sizeof(bufferString))==0 y !myGets_prueba(bufferString, sizeof(bufferString))
		esEntero(bufferString,sizeof(bufferString)))
	{
			retorno=0;
			*pRespuesta = atoi(bufferString); //convierto el dato (array de string) en numero integrer con ¡ atoi !
	}
	return retorno;
}

/**
 * \brief 	Solicita un numero al usuario(se sirve de getInt), luego de verificarlo devuelve el resultado
 * \param *pRespuesta Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param *mensaje Es el mensaje a ser mostrado
 * \param *mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero minimo a ser aceptado
 * \param maximo Es el numero maximo a ser aceptado
 * \param reintentos Cantidad de reintentos posibles, luego del primer uso de la funcion
 * \return Retorna 0 si se obtuvo exitosamente el numero y -1 si no se obtuvo
 *
 */
int utn_GetNumeroInt(int* pRespuesta, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno=-1; //devuelve el error en la primer instancia
	int bufferInt;

	if(pRespuesta != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s", mensaje);
			__fpurge(stdin);
			//fflush(stdin); windows
			if(getInt(&bufferInt)==0 &&
				bufferInt >= minimo &&
				bufferInt <= maximo)
			{
				*pRespuesta= bufferInt;
				retorno = 0;
				break; //porque ya no precisaria continuar el bucle do-while ya que llegue al caso de exito
			}
			printf("%s", mensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}
	return retorno;
}




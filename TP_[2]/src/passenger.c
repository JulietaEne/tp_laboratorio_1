/*
 * passenger.c
 *
 *  Created on: 23 abr. 2022
 *      Author: julieta_enee
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "tp.h"
#include "arrays.h"
#include "validaciones.h"
#include "passenger.h"

#define REINTENTOS 2
#define MAX_PRECIO 200000
#define MIN_PRECIO 10000
#define MIN_ESTADO_VUELO 0
#define MAX_ESTADO_VUELO 3
#define IS_EMPTY 0

/*
 * \brief Recorre el array recibido para asignar valor inicial al campo isEmpty
 * \param listPass recibe la direccion de memoria del array sobre el cual va a operar
 * \param sizeListPass Recibe por valor el tamaño del array
 * \return retorna -1 si hubo un error en los parametros recibidos
 * 		   retorna 0 si la operacion se realizo correctamente
 *
 */
int pass_initArray(Passenger* listPass, int sizeListPass)
{
	int retorno;
	int i;

	retorno = -1;

	if(listPass!= NULL && sizeListPass>0)
	{
		retorno = 0;
		for(i=0; i<sizeListPass; i++)
		{
			passenger_initAPossition(listPass, i, IS_EMPTY);
		}
	}
	return retorno;
}

/*
 * \breif To assign a init value to array's a particular possition
 * \param listPassenger ePassenger* receives the array which will be operated
 * \param unaPosicion Recibe por valor el indice sobre el cual se asignara el dato
 * \param valor Recibe por valor el dato que se asigna
 * \return retorna -1 si hubo un error en los parametros recibidos
 * 		   retorna 0 si opero exitosamente
 *
*/
int passenger_initAPossition(Passenger* listPass, int indice, int valorInicial)
{
	int retorno;
	retorno = -1;

	if(listPass!= NULL)
	{
		listPass[indice].isEmpty = valorInicial;
		retorno = 0;
	}

	return retorno;
}

int pass_printArray(Passenger* listPass, int sizeListPass)
{
	int retorno;
	int i;

	retorno = -1;
	if(listPass!= NULL && sizeListPass>0)
	{
		retorno = 0;
		for(i=0; i<sizeListPass; i++)
		{
			if(!validacionesInt_sonIdenticos(listPass[i].isEmpty,IS_EMPTY))
			{
				if(i==0)
				{
					printf("\nID\tNOMBRE\t\tAPELLIDO\tPRECIO\t\tCODIGO VUELO\tTIPO PASAJERO\n");
				}
				//printf("DEBUG** print pasajeros\n");
				passenger_printOneIndice(listPass, i);
			}
		}
	}
	return retorno;
}

int passenger_printOneIndice(Passenger* listPass, int indice)
{
	int retorno;
	retorno = -1;

	if(listPass!= NULL && indice >=0)
	{
		retorno = 0;

		//printf("DEBUG*** print un pasajero\n");
		printf("%d %13s %16s %15.2f %12s %11d\n",
				listPass[indice].id,
				listPass[indice].name,
				listPass[indice].lastName,
				listPass[indice].price,
				listPass[indice].flycode,
				listPass[indice].typePassenger);
	}

	return retorno;
}


////////////////////////***************GETTERS***************////////////////////////
/*
 * \brief interactua con el usuario para solicitar el nombre del cliente
 * \param nombre recibe la direccion de memoria del array donde se guardara el dato ingresado
 * \param sizeNombre Recibe por valor el tamaño del array
 * \return retorna -1 si hubo un error en los parametros recibidos
 * 		   retorna -2 si hubo un error en la interaccion con el usuario
 * 		   retorna 0 si la operacion se realizo correctamente
 *
 */
int pass_pedirNombre(char* nombre, int sizeNombre)
{
	int retorno;
	char auxNombre[sizeNombre];
	retorno = -1;
	if(nombre!= NULL && sizeNombre >0)
	{
		retorno=-2;
		if( utn_ingresarAlfabetica(auxNombre, sizeNombre, "Nombre: ", "Ingrese un dato valido", REINTENTOS)
			&& validaciones_esNombre(auxNombre, sizeNombre))
		{
			strncpy(nombre, auxNombre, sizeNombre);
			retorno = 0;
		}
	}

	return retorno;
}

/*
 * \brief interactua con el usuario para solicitar el apellido del cliente
 * \param apellido recibe la direccion de memoria del array donde se guardara el dato ingresado
 * \param sizeApellido Recibe por valor el tamaño del array
 * \return retorna -1 si hubo un error en los parametros recibidos
 * 		   retorna -2 si hubo un error en la interaccion con el usuario
 * 		   retorna 0 si la operacion se realizo correctamente
 *
 */
int pass_pedirApellido(char* apellido, int sizeApellido)
{
	int retorno;
	char auxApellido[sizeApellido];
	retorno = -1;
	if(apellido!= NULL && sizeApellido >0)
	{
		retorno=-2;
		if( utn_ingresarAlfabetica(auxApellido, sizeApellido, "Apellido: ", "Ingrese un dato valido", REINTENTOS)
			&& validaciones_esNombre(auxApellido, sizeApellido))
		{
			strncpy(apellido, auxApellido, sizeApellido);
			retorno = 0;
		}
	}

	return retorno;
}

/*
 * \brief interactua con el usuario para solicitar el precio
 * \param precio recibe la direccion de memoria de la variable donde se guardara el dato ingresado
 * \param sizeApellido Recibe por valor el tamaño del array
 * \return retorna -1 si hubo un error en los parametros recibidos
 * 		   retorna -2 si hubo un error en la interaccion con el usuario
 * 		   retorna >0 si la operacion se realizo correctamente
 *
 */
float pass_pedirPrecio(float* precio)
{
	//int retorno;
	float auxPrecio;
	auxPrecio = -1;
	if(precio!= NULL)
	{
		auxPrecio=-2;
		if( utn_GetNumeroFloat(&auxPrecio, "ingrese el precio", "ingrese un dato valido", MIN_PRECIO, MAX_PRECIO, REINTENTOS))
		{
			*precio = auxPrecio;
		}
	}

	return auxPrecio;
}

/*
 * \brief interactua con el usuario para solicitar el codigo del vuelo
 * \param codigoVuelo recibe la direccion de memoria del array donde se guardara el dato ingresado
 * \param sizeCodigoVuelo Recibe por valor el tamaño del array
 * \return retorna -1 si hubo un error en los parametros recibidos
 * 		   retorna -2 si hubo un error en la interaccion con el usuario
 * 		   retorna 0 si la operacion se realizo correctamente
 *
 */
int pass_pedirCodigoVuelo(char* codigoVuelo, int sizeCodigoVuelo)
{
	int retorno;
	char auxCodigoVuelo[sizeCodigoVuelo];
	retorno = -1;
	if(codigoVuelo!= NULL && sizeCodigoVuelo >0)
	{
		retorno=-2;
		if( utn_getAlfaNumerica(auxCodigoVuelo, sizeCodigoVuelo, "Codigo de vuelo: ", "Ingrese un dato valido", REINTENTOS)
			&& arrayChar_convertirStringMayuscula(codigoVuelo, sizeCodigoVuelo))
		{
			strncpy(codigoVuelo, auxCodigoVuelo, sizeCodigoVuelo);
			retorno = 0;
		}
	}
	return retorno;
}



/*
 * \brief interactua con el usuario para solicitar el estado del vuelo
 * \param estadoVuelo recibe la direccion de memoria de la variable donde se guardara el dato ingresado
 * \return retorna -1 si hubo un error en los parametros recibidos
 * 		   retorna -2 si hubo un error en la interaccion con el usuario
 * 		   retorna >0 si la operacion se realizo correctamente
 *
 */
int pass_pedirEstadoVuelo(int* estadoVuelo)
{
	//int retorno;
	int auxEstadoVuelo;
	auxEstadoVuelo = -1;
	if(estadoVuelo!= NULL)
	{
		auxEstadoVuelo=-2;
		if( utn_GetNumeroInt(&auxEstadoVuelo, "Estado de vuelo: ", "Ingrese un dato valido", MIN_ESTADO_VUELO, MAX_ESTADO_VUELO, REINTENTOS))
		{
			*estadoVuelo = auxEstadoVuelo;
		}
	}

	return auxEstadoVuelo;
}


/*
 * \brief interactua con el usuario para solicitar el tipo de pasajero del cliente
 * \param tipoPasajero recibe la direccion de memoria de la variable donde se guardara el dato ingresado
 * \return retorna -1 si hubo un error en los parametros recibidos
 * 		   retorna -2 si hubo un error en la interaccion con el usuario
 * 		   retorna >0 si la operacion se realizo correctamente
 *
 */
int pass_pedirTipoPasajero(int* tipoPasajero)
{
	//int retorno;
	int auxTipoPasajero;
	auxTipoPasajero = -1;
	if(tipoPasajero!= NULL)
	{
		auxTipoPasajero=-2;
		if( utn_GetNumeroInt(&auxTipoPasajero, "Estado de vuelo: ", "Ingrese un dato valido", MIN_ESTADO_VUELO, MAX_ESTADO_VUELO, REINTENTOS))
		{
			*tipoPasajero = auxTipoPasajero;
		}
	}

	return auxTipoPasajero;
}
////////////////////////***************GETTERS***************////////////////////////

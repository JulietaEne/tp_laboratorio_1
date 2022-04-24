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
#define NOT_EMPTY 1
#define SIZE_STR 51
#define SIZE_CODE 10
#define ID_INICIAL 100
#define ID_MAXIMO 2200


/*
 * \brief Recorre el array recibido para asignar valor inicial al campo isEmpty
 * \param listPass recibe la direccion de memoria del array sobre el cual va a operar
 * \param sizeListPass Recibe por valor el tamaño del array
 * \return retorna -1 si hubo un error en los parametros recibidos
 * 		   retorna 0 si la operacion se realizo correctamente
 *
 */
int pass_initArray(Passenger* listPass, int sizeListPass)//init passengers
{
	int retorno;
	int i;

	retorno = -1;

	if(listPass!= NULL && sizeListPass>0)
	{
		retorno = 0;
		for(i=0; i<sizeListPass; i++)
		{
			pass_initAPossition(listPass, i, IS_EMPTY);
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
int pass_initAPossition(Passenger* listPass, int indice, int valorInicial)
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

/*
 * \brief Recorre el array recibido para imprimir los indices que estan cargados
 * \param listPass recibe la direccion de memoria del array sobre el cual va a trabajar
 * \param sizeListPass Recibe por valor el tamaño del array
 * \return retorna -1 si hubo un error en los parametros recibidos
 * 		   retorna 0 si la operacion se realizo correctamente
 *
 */
int pass_printArray(Passenger* listPass, int sizeListPass) //printPassenger
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
					pass_printRotulo();
				}
				//printf("DEBUG** print pasajeros\n");
				pass_printOneIndice(listPass, i);
			}
		}
	}
	return retorno;
}

void pass_printRotulo(void)
{
	printf("\nID\tNOMBRE\t\tAPELLIDO\tPRECIO\t\tCODIGO VUELO\tTIPO PASAJERO\tESTADO VUELO\n");
}
/*
 * \brief Recibe un array de estructuras e imprime una estructura segun el indice recibido
 * \param listPass recibe la direccion de memoria del array sobre el cual va a trabajar
 * \param indice Recibe por valor la posicion del array del cual imprimira los valores de sus campos
 * \return retorna -1 si hubo un error en los parametros recibidos
 * 		   retorna 0 si la operacion se realizo correctamente
 *
 */
int pass_printOneIndice(Passenger* listPass, int indice)
{
	int retorno;
	retorno = -1;

	if(listPass!= NULL && indice >=0)
	{
		retorno = 0;

		//printf("DEBUG*** print un pasajero\n");
		printf("%d %13s %16s %15.2f %12s %11d %12d\n",
				listPass[indice].id,
				listPass[indice].name,
				listPass[indice].lastName,
				listPass[indice].price,
				listPass[indice].flycode,
				listPass[indice].typePassenger,
				listPass[indice].statusFlight);
	}

	return retorno;
}

/**
* \brief add in a existing list of employees the values received as parameters in the first empty position
* \param list employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or withoufree space] - (0) if Ok
*
 Interactúa con el usuario para pedir los datos a ingresar
 Luego se sirve de la función addEmployee para agregar un empleado con los datos recibidos
*
*/
int pass_pedirNuevoPasajero(Passenger* listPass, int sizePass, int ultimoId)
{
	int retorno;
	char nombre[SIZE_STR];
	char apellido[SIZE_STR];
	float precio;
	char codigoVuelo[SIZE_CODE];
	int tipoPasajero;
	int estadoVuelo;

	retorno =-1;
	if(listPass != NULL && sizePass >0 && ultimoId >= 0)
	{
		if(    !pass_pedirNombre(nombre, SIZE_STR)
			&& !pass_pedirApellido(apellido, SIZE_STR)
			&& pass_pedirPrecio(&precio)>0
			&& !pass_pedirCodigoVuelo(codigoVuelo, SIZE_CODE)
			&& pass_pedirTipoPasajero(&tipoPasajero)>0
			&& pass_pedirEstadoVuelo(&estadoVuelo)>0)
		{
			pass_agregarPasajeroAlArray(listPass, sizePass, ultimoId, nombre, apellido, precio, codigoVuelo, tipoPasajero, estadoVuelo);
			retorno = 0;
		}
	}
	return retorno;
}

/**
* \brief Recibe un array de estructuras para recorrerlo en el campo isEmpty hasta encontrar el valor 0,
* 		 retornando el valor del indice hayado
* \param listPass employee* recibe la direccion de memoria del array a analizar
* \param sizePass int recibe por valor el tamaño del array

* \return int Return (-1) if Error [Invalid length or NULL pointer or withoufree space]
* 					 (>0) if Ok - el valor del indice que se encontro
*
*
*/
int pass_encontrarPrimerIndiceIsEmpty(Passenger* listPass, int sizePass)
{
	int retorno;
	int i;
	retorno = -1;
	if(listPass != NULL && sizePass >0)
	{
		for(i=0; i<sizePass; i++)
		{
			if(validacionesInt_sonIdenticos(listPass[i].isEmpty, IS_EMPTY))
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}

/**
* \brief Recibe un array de estructuras el cual sera analizado para cargar en un indice determinado los datos de las variables recibidas por parametro
* \param listPass employee* recibe la direccion de memoria del array a analizar
* \param sizePass int recibe por valor el tamaño del array
* \param ultimoId int recibe una copia del valor indicado como id
* \param nombre char* recibe la direccion de memoria del primer elemento correspondiente al nombre
* \param apellido char* recibe la direccion de memoria del primer elemento correspondiente al apellido
* \param precio float recibe una copia del valor indicado para el campo price
* \param codigoVuelo char* recibe la direccion de memoria del primer elemento correspondiente campo flyCode
* \param tipoPasajero int recibe una copia del valor indicado para el campo typePassenger
* \param estadoVuelo int recibe una copia del valor indicado para el campo statusFlight

* \return int Return (-1) if Error [Invalid length or NULL pointer or withoufree space]
* 					 (>0) if Ok - el valor del indice que se encontro
*
*
*/
//addPassenger
int pass_agregarPasajeroAlArray(Passenger* listPass, int sizePass, int ultimoId, char* nombre, char* apellido, float precio, char* codigoVuelo, int tipoPasajero, int estadoVuelo)
{
	int retorno;
	int primerIndiceLibre;

	retorno = -1;
	if(listPass!= NULL && sizePass>0 && nombre!= NULL && apellido!= NULL && codigoVuelo!= NULL)
	{
		retorno = -2;
		primerIndiceLibre= pass_encontrarPrimerIndiceIsEmpty(listPass, sizePass);
		if(primerIndiceLibre >= 0)
		{
			strncpy(listPass[primerIndiceLibre].name, nombre, SIZE_STR);
			strncpy(listPass[primerIndiceLibre].lastName, apellido, SIZE_STR);
			listPass[primerIndiceLibre].id = ultimoId;//este id proviene de una variable autoincremental
			listPass[primerIndiceLibre].price = precio;
			listPass[primerIndiceLibre].typePassenger = tipoPasajero;
			strncpy(listPass[primerIndiceLibre].flycode, codigoVuelo, SIZE_CODE);
			listPass[primerIndiceLibre].statusFlight = estadoVuelo;
			listPass[primerIndiceLibre].isEmpty = NOT_EMPTY;
			retorno=0;
		}

	}
	return retorno;
}

/**
* \brief Recibe un array de estructuras para ingresar a la posicion indicada por el parametro recibido y cambiar el dato en el campo name
* \param listPass employee* recibe la direccion de memoria del array a analizar
* \param sizePass int recibe por valor el tamaño del array

* \return int Retorna -1 si hubo un error en los parametros recibidos
* 					  -2 si hubo un error en la interaccion con el usuario
* 					  0 si pudo operar exitosamente
*
*
*/
int pass_cambiarNombre(Passenger* listPass, int idCambio)
{
	int retorno;
	char nuevoNombre[SIZE_STR];
	retorno = -1;
	if(listPass != NULL)
	{
		retorno = -2;
		if(!pass_pedirNombre(nuevoNombre, SIZE_STR))
		{
			strncpy(listPass[idCambio].name, nuevoNombre, SIZE_STR);
			retorno = 0;
		}
	}
	return retorno;
}

/**
* \brief Recibe un array de estructuras para ingresar a la posicion indicada por el parametro recibido
* 				y cambiar el dato en el campo lastName
* \param listPass employee* recibe la direccion de memoria del array a analizar
* \param sizePass int recibe por valor el tamaño del array

* \return int Retorna -1 si hubo un error en los parametros recibidos
* 					  -2 si hubo un error en la interaccion con el usuario
* 					  0 si pudo operar exitosamente
*
*
*/
int pass_cambiarApellido(Passenger* listPass, int idCambio)
{
	int retorno;
	char nuevoApellido[SIZE_STR];
	retorno = -1;
	if(listPass != NULL)
	{
		retorno = -2;
		if(!pass_pedirApellido(nuevoApellido, SIZE_STR))
		{
			strncpy(listPass[idCambio].lastName, nuevoApellido, SIZE_STR);
			retorno = 0;
		}
	}
	return retorno;
}

/**
* \brief Recibe un array de estructuras para ingresar a la posicion indicada por el parametro recibido
* 				y cambiar el dato en el campo price
* \param listPass employee* recibe la direccion de memoria del array a analizar
* \param sizePass int recibe por valor el tamaño del array

* \return int Retorna -1 si hubo un error en los parametros recibidos
* 					  -2 si hubo un error en la interaccion con el usuario
* 					  0 si pudo operar exitosamente
*
*
*/
int pass_cambiarPrecio(Passenger* listPass, int idCambio)
{
	int retorno;
	float nuevoPrecio;
	retorno = -1;
	if(listPass != NULL)
	{
		retorno = -2;
		if(pass_pedirPrecio(&nuevoPrecio)>0)
		{
			listPass[idCambio].price = nuevoPrecio;
			retorno = 0;
		}
	}
	return retorno;
}

/**
* \brief Recibe un array de estructuras para ingresar a la posicion indicada por el parametro recibido
* 				y cambiar el dato en el campo typePassenger
* \param listPass employee* recibe la direccion de memoria del array a analizar
* \param sizePass int recibe por valor el tamaño del array

* \return int Retorna -1 si hubo un error en los parametros recibidos
* 					  -2 si hubo un error en la interaccion con el usuario
* 					  0 si pudo operar exitosamente
*
*
*/
int pass_cambiarTipoPasajero(Passenger* listPass, int idCambio)
{
	int retorno;
	int nuevoTipo;
	retorno = -1;
	if(listPass != NULL)
	{
		retorno = -2;
		if(pass_pedirTipoPasajero(&nuevoTipo)>0)
		{
			listPass[idCambio].typePassenger = nuevoTipo;
			retorno = 0;
		}
	}
	return retorno;
}

/**
* \brief Recibe un array de estructuras para ingresar a la posicion indicada por el parametro recibido
* 				y cambiar el dato en el campo flycode
* \param listPass employee* recibe la direccion de memoria del array a analizar
* \param sizePass int recibe por valor el tamaño del array

* \return int Retorna -1 si hubo un error en los parametros recibidos
* 					  -2 si hubo un error en la interaccion con el usuario
* 					  0 si pudo operar exitosamente
*
*
*/
int pass_cambiarCodigoVuelo(Passenger* listPass, int idCambio)
{
	int retorno;
	char nuevoCodigoVuelo[SIZE_CODE];
	retorno = -1;
	if(listPass != NULL)
	{
		retorno = -2;
		if(!pass_pedirCodigoVuelo(nuevoCodigoVuelo, SIZE_CODE))
		{
			strncpy(listPass[idCambio].flycode, nuevoCodigoVuelo, SIZE_CODE);
			retorno = 0;
		}
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
		if( !utn_ingresarAlfabetica(auxNombre, sizeNombre, "Nombre: ", "Ingrese un dato valido", REINTENTOS)
			&& !validaciones_esNombre(auxNombre, sizeNombre))
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
		if( !utn_ingresarAlfabetica(auxApellido, sizeApellido, "Apellido: ", "Ingrese un dato valido", REINTENTOS)
			&& !validaciones_esNombre(auxApellido, sizeApellido))
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
		if( !utn_GetNumeroFloat(&auxPrecio, "ingrese el precio: ", "ingrese un dato valido", MIN_PRECIO, MAX_PRECIO, REINTENTOS))
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
		if( !utn_getAlfaNumerica(auxCodigoVuelo, sizeCodigoVuelo, "Codigo de vuelo: ", "Ingrese un dato valido", REINTENTOS)
			&& !arrayChar_convertirStringMayuscula(auxCodigoVuelo, sizeCodigoVuelo))
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
		if( !utn_GetNumeroInt(&auxEstadoVuelo, "Estado de vuelo: ", "Ingrese un dato valido", MIN_ESTADO_VUELO, MAX_ESTADO_VUELO, REINTENTOS))
		{
			*estadoVuelo = auxEstadoVuelo;
			//printf("**DEBUG** estadoAux: %d - estado:%d", auxEstadoVuelo, *estadoVuelo);
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
		if(! utn_GetNumeroInt(&auxTipoPasajero, "Tipo de pasajero: ", "Ingrese un dato valido", 1, 3, REINTENTOS))
		{
			*tipoPasajero = auxTipoPasajero;
		}
	}

	return auxTipoPasajero;
}
////////////////////////***************GETTERS***************////////////////////////

int pass_pedirIdConsulta(int idUltimo)
{
	int retorno;
	int auxIdConsulta;
	retorno = -1;
	if( !utn_GetNumeroInt(&auxIdConsulta, "ingrese ID de cliente: ", "ingrese un ID valido", ID_INICIAL, ID_MAXIMO, REINTENTOS)
		&& auxIdConsulta<= idUltimo)
	{
		retorno = auxIdConsulta;
	}

	return retorno;
}

/** \brief find a Passenger by Id and returns the index position in array.
*
* \param listPass Passenger* recibe la direccion de memoria del array sobre el cual va a trabajar
* \param sizeListPass int Recibe por valor el tamaño del array
* \param idConsulta int recive por valor el dato contra el cual compara
* \return Return >=0 passenger index position
* 				(-1) if [Invalid length or
*				(-2) pointer received or passenger not found]
*
*/
int pass_encontrarPasajeroPorId(Passenger* listPass, int sizePass, int idConsulta)
{
	int retorno;
	int i;

	retorno = -1;
	if(listPass!= NULL && sizePass>0)
	{
		retorno = -2;
		for(i=0; i<sizePass; i++)
		{
			if(validacionesInt_sonIdenticos(listPass[i].id, idConsulta))
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}


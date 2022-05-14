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

#include "arrays.h"
#include "validaciones.h"
#include "passenger.h"
#include "tp.h"
//#include "typePass.h"



/**
 * \brief Recorre el array recibido para asignar valor inicial al campo isEmpty de todos sus elementos
 * \param listPass Passenger* Recibe la direccion de memoria del array sobre el cual va a operar
 * \param sizeListPass int Recibe por valor el tamaño del array
 * \return retorna int -1 si hubo un error en los parametros recibidos
 * 			0 si la operacion se realizo correctamente
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

/**
 * \breif To assign a init value to array's a particular possition
 * \param listPassenger Passenger* receives the array which will be operated
 * \param indice int receives the value who indicates where the data will be assigned
 * \param valorInicial int Receives by value the data that is assigned
 * \return retorna int -1 if  Error [Invalid length or NULL pointer or withoufree space]
 * 			0 if Ok - el valor del indice que se encontro
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
 * \brief Recorre el array recibido para analizar el campo id y encontrar el id Mayor.
 * \param listPass Passenger* Recibe la direccion de memoria del array sobre el cual va a trabajar
 * \param sizeListPass int Recibe por valor el tamaño del array
 * \return retorna int -1 si hubo un error en los parametros recibidos
 * 			           >=ID_INICIAL si la operacion se realizo correctamente
 *
 */
int pass_indicarUltimoId(Passenger* listPass, int sizeListPass)//, int* ultimoId)
{
	int auxMayorId;
	int i;
	auxMayorId = -1;
	if(listPass!= NULL && sizeListPass >0 )//&& ultimoId != NULL)
	{
		auxMayorId=ID_INICIAL;
		for (i=0; i<sizeListPass; i++)
		{
			if(listPass[i].isEmpty== NOT_EMPTY && listPass[i].id>auxMayorId)
			{
				auxMayorId=listPass[i].id;
			}
		}
		//*ultimoId = auxMayorId;
		//printf("\nULTIMO ID: %d\n", *ultimoId);
	}

	return auxMayorId;
}

/*
 * \brief Recorre el array recibido para analizar si el campo isEmpty está usado, y si lo está los contabiliza
 * \param listPass Passenger* Recibe la direccion de memoria del array sobre el cual va a trabajar
 * \param sizeListPass int Recibe por valor el tamaño del array
 * \param cantidadCargados int* Recibe la direccion de memoria de una variable donde alojar el resultado
 * \return retorna int -1 si hubo un error en los parametros recibidos
 * 					   0 si no contabilizó pasajeros cargados
 * 					   >0 si encontro pasajeros cargados(retorna la cantidad contabilizada)
 *
 */
int pass_contadorPasajerosCargados(Passenger* listPass, int sizeListPass, int* cantidadCargados)
{
	int i;
	int contador;
	contador=-1;
	if(listPass!= NULL && sizeListPass>0) //&& cantidadCargados!= NULL)
	{
		contador=0;
		for(i=0; i<sizeListPass; i++)
		{
			if(listPass[i].isEmpty == NOT_EMPTY)
			{
				contador++;
			}
		}
		*cantidadCargados=contador;
	}
	return contador;
}

/*
 * \brief Recorre el array recibido para imprimir los indices que estan cargados
 * \param listPass Passenger* Recibe la direccion de memoria del array sobre el cual va a trabajar
 * \param sizeListPass int Recibe por valor el tamaño del array
 * \return retorna int -1 si hubo un error en los parametros recibidos
 * 			0 si la operacion se realizo correctamente
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
		pass_printRotulo();
		for(i=0; i<sizeListPass; i++)
		{
			if( listPass[i].isEmpty != IS_EMPTY
				&& listPass[i].isEmpty != DELETED)
			{
				//printf("DEBUG** print pasajeros\n");
				pass_printOneIndice(listPass, i);
			}
		}
	}
	return retorno;
}

/*
 * \brief Recorre el array recibido para imprimir los indices que estan cargados
 * \param listPass Passenger* Recibe la direccion de memoria del array sobre el cual va a trabajar
 * \param sizeListPass int Recibe por valor el tamaño del array
 * \param listaTipoPasajeros typePass* Recibe la direccion de memoria de la lista secundaria
 * \param sizeTipoPasajeros int Recibe por valor el tamaño de la lista secundaria
 * \return retorna int -1 si hubo un error en los parametros recibidos
 * 			0 si la operacion se realizo correctamente
 *
 */
int pass_printArrayConTipoPasajero(Passenger* listPass, int sizeListPass, typePass* listaTipoPasajeros, int sizeTipoPasajeros) //printPassenger
{
	int retorno;
	int i;

	retorno = -1;
	if(listPass!= NULL && sizeListPass>0)
	{
		retorno = 0;
		pass_printRotulo();
		for(i=0; i<sizeListPass; i++)
		{
			if( listPass[i].isEmpty != IS_EMPTY
				&& listPass[i].isEmpty != DELETED)
			{
				//printf("DEBUG** print pasajeros\n");
				pass_printOneIndice(listPass, i);
				typePass_printTipoPasajeroSegunId(listaTipoPasajeros, sizeTipoPasajeros, listPass[i].idTypePass);
			}
		}
	}
	return retorno;
}

/**
 * \brief Imprime el encabezado de la planilla
 * \return void
 *
 */
void pass_printRotulo(void)
{
	printf("\nID\tNOMBRE\t\tAPELLIDO\tPRECIO\t\tCODIGO VUELO\tESTADO VUELO\tTIPO PASAJERO\n");
}

/**
 * \brief Recibe un array de estructuras e imprime una estructura segun el indice recibido
 * \param listPass *Passenger recibe la direccion de memoria del array sobre el cual va a trabajar
 * \param indice int Recibe por valor la posicion del array del cual imprimira los valores de sus campos
 * \return retorna int -1 si hubo un error en los parametros recibidos
 * 			0 si la operacion se realizo correctamente
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
		printf("%d %13s %16s %15.2f %12s %12d\t\t",
				listPass[indice].id,
				listPass[indice].name,
				listPass[indice].lastName,
				listPass[indice].price,
				listPass[indice].flycode,
				//listPass[indice].typePassenger,
				listPass[indice].statusFlight);
	}

	return retorno;
}

////////////////////////***************GETTERS***************////////////////////////
/**
 * \brief interactua con el usuario para solicitar el nombre del cliente
 * \param nombre char* Recibe la direccion de memoria del array donde se guardara el dato ingresado
 * \param sizeNombre int Recibe por valor el tamaño del array
 * \return retorna -1 si hubo un error en los parametros recibidos
 * 		   -2 si hubo un error en la interaccion con el usuario
 * 		   0 si la operacion se realizo correctamente
 *
 */
int pass_getNombre(char* nombre, int sizeNombre)
{
	int retorno;
	char auxNombre[sizeNombre];
	//int flagNombre;

	//flagNombre =0;
	retorno = -1;
	if(nombre!= NULL && sizeNombre >0)
	{
		retorno=-2;
		/*do //aca tendria que ver como hacer para que se valide por si sola
		{
		    utn_ingresarAlfabetica(auxNombre, sizeNombre, "Nombre: ", "Ingrese un dato valido", REINTENTOS);
		    if(!validaciones_esNombre(auxNombre, sizeNombre))

		}while(!flagNombre)*/

		if( !utn_ingresarAlfabetica(auxNombre, sizeNombre, "Nombre: ", "Ingrese un dato valido", REINTENTOS)
			&& !validaciones_esNombre(auxNombre, sizeNombre))
		{
			strncpy(nombre, auxNombre, sizeNombre);
			retorno = 0;
		}
	}

	return retorno;
}

/**
 * \brief interactua con el usuario para solicitar el apellido del cliente
 * \param apellido char* Recibe la direccion de memoria del array donde se guardara el dato ingresado
 * \param sizeApellido int Recibe por valor el tamaño del array
 * \return retorna -1 si hubo un error en los parametros recibidos
 * 		   -2 si hubo un error en la interaccion con el usuario
 * 		   0 si la operacion se realizo correctamente
 *
 */
int pass_getApellido(char* apellido, int sizeApellido)
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
 * \param precio float* Recibe la direccion de memoria de la variable donde se guardara el dato ingresado
 * \param sizeApellido Recibe por valor el tamaño del array
 * \return retorna -1 si hubo un error en los parametros recibidos
 * 		   -2 si hubo un error en la interaccion con el usuario
 * 		   >0 si la operacion se realizo correctamente
 *
 */
float pass_getPrecio(float* precio)
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
 * \param codigoVuelo char* recibe la direccion de memoria del array donde se guardara el dato ingresado
 * \param sizeCodigoVuelo int Recibe por valor el tamaño del array
 * \return retorna -1 si hubo un error en los parametros recibidos
 * 		   -2 si hubo un error en la interaccion con el usuario
 * 		   0 si la operacion se realizo correctamente
 *
 */
int pass_getCodigoVuelo(char* codigoVuelo, int sizeCodigoVuelo)
{
	int retorno;
	char auxCodigoVuelo[sizeCodigoVuelo];
	retorno = -1;
	if(codigoVuelo!= NULL && sizeCodigoVuelo >0)
	{
		retorno=-2;
		do{
			utn_getAlfaNumerica(auxCodigoVuelo, sizeCodigoVuelo, "Codigo de vuelo(3 letras + numeros): ", "Ingrese un dato valido", REINTENTOS);
			if(!validaciones_EsCodigoTresLetrasYNumero(auxCodigoVuelo, sizeCodigoVuelo))
			{
				strncpy(codigoVuelo, auxCodigoVuelo, sizeCodigoVuelo);
				retorno = 0;
			}

		}while(retorno);
		//if( !utn_getAlfaNumerica(auxCodigoVuelo, sizeCodigoVuelo, "Codigo de vuelo: ", "Ingrese un dato valido", REINTENTOS)
		//	&& !validaciones_EsCodigoTresLetrasYNumero(auxCodigoVuelo, sizeCodigoVuelo))
		//{
		//	strncpy(codigoVuelo, auxCodigoVuelo, sizeCodigoVuelo);
		//	retorno = 0;
		//}
	}
	return retorno;
}

/*
 * \brief interactua con el usuario para solicitar el estado del vuelo
 * \param estadoVuelo char* Recibe la direccion de memoria de la variable donde se guardara el dato ingresado
 * \return retorna -1 si hubo un error en los parametros recibidos
 * 		   -2 si hubo un error en la interaccion con el usuario
 * 		   >0 si la operacion se realizo correctamente
 *
 */
int pass_getEstadoVuelo(int* estadoVuelo)
{
	//int retorno;
	int auxEstadoVuelo;
	auxEstadoVuelo = -1;
	if(estadoVuelo!= NULL)
	{
		auxEstadoVuelo=-2;
		if( !utn_GetNumeroInt(&auxEstadoVuelo, "Estado de vuelo(1 Activo, 2 Cancelado, 3 Demorado): ", "Ingrese un dato valido", MIN_ESTADO_VUELO, MAX_ESTADO_VUELO, REINTENTOS))
		{
			*estadoVuelo = auxEstadoVuelo;
			//printf("**DEBUG** estadoAux: %d - estado:%d", auxEstadoVuelo, *estadoVuelo);
		}
	}

	return auxEstadoVuelo;
}


/*
 * \brief interactua con el usuario para solicitar el tipo de pasajero del cliente
 * \param tipoPasajero int* Recibe la direccion de memoria de la variable donde se guardara el dato ingresado
 * \param listaTipoPasajeros typePass* Recibe la direccion de memoria de la lista con la cual trabajara
 * \param sizeTipoPasajeros int Recibe por valor el tamaño de la lista
 * \return retorna -1 si hubo un error en los parametros recibidos
 * 		   -2 si hubo un error en la interaccion con el usuario
 * 		   >0 si la operacion se realizo correctamente
 *
 */
int pass_getTipoPasajero(int* tipoPasajero, typePass* listaTipoPasajeros, int sizeTipoPasajeros)
{
	//int retorno;
	int auxTipoPasajero;
	auxTipoPasajero = -1;
	if(tipoPasajero!= NULL && listaTipoPasajeros != NULL && sizeTipoPasajeros > 0)
	{
		auxTipoPasajero = typePass_getTipoPasajero(listaTipoPasajeros, sizeTipoPasajeros);
		if(auxTipoPasajero > 0)
		{
			*tipoPasajero = auxTipoPasajero;
		}
	}
	return auxTipoPasajero;
}


///////////////////////////////////

/**
* \brief Recibe un array de estructuras para recorrerlo en el campo isEmpty hasta encontrar el valor 0,
* 		 retornando el valor del indice hayado
* \param listPass employee* recibe la direccion de memoria del array a analizar
* \param sizePass int recibe por valor el tamaño del array
* \return int Return (-1) si hubo un error en los parametros recibidos
* 					 (-2) si no encontr ningun index libre
* 		     		 (>0) si opero correctamente - el valor del indice que se encontro
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
			else
			{
				if(validacionesInt_sonIdenticos(listPass[i].isEmpty,DELETED))
				{
					retorno=i;
					//printf("DEBUG*** entramos solo cuando ya no queda espacio libre, y tenemos que sobreescribir un cliente eliminado");
					break;
				}
				else
				{
					retorno = -2;
				}
			}
		}
		//printf("DEBUG******** RETORNO %d\n", retorno);
	}
	return retorno;
}

/**
* \brief add in a existing list of passenger the values received as parameters in the first empty position(with pass_agregarPasajeroAlArray)
* \param listPass Passenger* receives the list where will write the struct
* \param sizePass int to indicate array size
* \param ultimoId int receives by value that data that will assigned in .id
* \param listaTipoPasajeros typePass* Recibe la direccion de memoria de la lista secundaria
* \param sizeTipoPasajeros int Recibe por valor el tamaño de la lista secundaria
* \return int Return (-1) if Error [Invalid length or NULL pointer or withoufree space]
*			(0) if Ok
*
*/
int pass_getNuevoPasajero(Passenger* listPass, int sizePass, int ultimoId, typePass* listaTipoPasajeros, int sizeListaTipoPasajeros)
{
	int retorno;
	char nombre[SIZE_STR];
	char apellido[SIZE_STR];
	float precio;
	char codigoVuelo[SIZE_CODE];
	int tipoPasajero;
	int estadoVuelo;

	//int cargarCliente;

	retorno =-1;
	if(listPass != NULL && sizePass >0 && ultimoId >= 0)
	{
		pass_getNombre(nombre, SIZE_STR);
		pass_getApellido(apellido, SIZE_STR);
		pass_getPrecio(&precio);
		pass_getCodigoVuelo(codigoVuelo, SIZE_CODE);
		pass_getTipoPasajero(&tipoPasajero, listaTipoPasajeros, sizeListaTipoPasajeros);
	    pass_getEstadoVuelo(&estadoVuelo);
		if(!pass_agregarPasajeroAlArray(listPass, sizePass, nombre, apellido, precio, codigoVuelo, tipoPasajero, estadoVuelo))
		{
		    retorno = 0;
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
* \return int Return (-1) si hubo un error en los parametros recibidos
* 		     (-2) si hubo un error al buscar un indice libre
* 		     (0) si opero correctamente
*
*/
//addPassenger
int pass_agregarPasajeroAlArray(Passenger* listPass, int sizePass, char* nombre, char* apellido, float precio, char* codigoVuelo, int tipoPasajero, int estadoVuelo)
{
	int retorno;
	int ultimoId;
	int indexCarga;

	retorno = -1;
	if(listPass!= NULL && sizePass>0 && nombre!= NULL && apellido!= NULL && codigoVuelo!= NULL)
	{
		retorno = -2;
		ultimoId = pass_indicarUltimoId(listPass, sizePass);
		ultimoId = ultimoId+1;

		indexCarga = pass_encontrarPrimerIndiceIsEmpty(listPass, sizePass);

		if(indexCarga >= 0)
		{
			strncpy(listPass[indexCarga].name, nombre, SIZE_STR);
			strncpy(listPass[indexCarga].lastName, apellido, SIZE_STR);
			listPass[indexCarga].id = ultimoId;//este id proviene de una variable autoincremental
			listPass[indexCarga].price = precio;
			listPass[indexCarga].idTypePass = tipoPasajero;
			strncpy(listPass[indexCarga].flycode, codigoVuelo, SIZE_CODE);
			listPass[indexCarga].statusFlight = estadoVuelo;
			listPass[indexCarga].isEmpty = NOT_EMPTY;
			retorno=0;
		}

	}
	return retorno;
}


/**
* \brief Interactua con el usuario para solicitar un id y validar que contenga datos, si lo hace, lo retorna
* \param idConsulta int* Recibe por valor el dato contra el cual compara para validar el dato ingresado
* \param listPass Passenger* Recibe la direccion de memoria de la lista principal a analizar
* \param sizeListPass int Recibe por valor el tamaño de la lista principal
* \param listaTipoPasajeros typePass* Recibe la direccion de memoria de la lista secundaria
* \param sizeTipoPasajeros int Recibe por valor el tamaño de la lista secundaria
* \return Return >=0 si opero correctamente
* 				(-1) si hubo un error en el dato ingresado
*				(-2) si el id no corresponde a un cliente valido
*
*/
int pass_pedirIdConsulta(int* idConsulta, Passenger* listPass, int sizeListPass, typePass* listaTipoPasajeros, int sizeListaTipoPasajeros)
{
	int retorno;
	int auxIdConsulta;
	int ultimoId;

	retorno = -1;

	if(idConsulta != NULL && listPass != NULL && sizeListPass >0)
	{
	    retorno = 0;
	    utn_GetNumeroInt(&auxIdConsulta, "ingrese ID de cliente: ", "ingrese un ID valido", ID_INICIAL, ID_MAXIMO, REINTENTOS);
        ultimoId = pass_indicarUltimoId(listPass, sizeListPass);
        if( auxIdConsulta <= ultimoId)
        {
            *idConsulta = auxIdConsulta;
        }
        else
        {
            printf("ingrese el codigo de un album existente");
            pass_printArrayConTipoPasajero(listPass, sizeListPass, listaTipoPasajeros, sizeListaTipoPasajeros);
        }
	}
	return retorno;
}




/**
* \brief Recibe un array de estructuras para ingresar a la posicion indicada por el parametro recibido y cambiar el dato en el campo .name
* \param listPass employee* recibe la direccion de memoria del array a analizar
* \param indexCambio int recibe por valor la posicion del array en la que se realiza el cambio
* \return int Retorna -1 si hubo un error en los parametros recibidos
* 		      -2 si hubo un error en la interaccion con el usuario
* 		       0 si pudo operar exitosamente
*
*
*/
int pass_setNombre(Passenger* listPass, int indexCambio)
{
	int retorno;
	char nuevoNombre[SIZE_STR];
	retorno = -1;
	if(listPass != NULL)
	{
		retorno = -2;
		if(!pass_getNombre(nuevoNombre, SIZE_STR))
		{
			strncpy(listPass[indexCambio].name, nuevoNombre, SIZE_STR);
			retorno = 0;
		}
	}
	return retorno;
}

/**
* \brief Recibe un array de estructuras para ingresar a la posicion indicada por el parametro recibido y cambiar el dato en el campo .lastName
* \param listPass employee* recibe la direccion de memoria del array a analizar
* \param indexCambio int recibe por valor la posicion del array en la que se realiza el cambio
* \return int Retorna -1 si hubo un error en los parametros recibidos
* 		      -2 si hubo un error en la interaccion con el usuario
* 		       0 si pudo operar exitosamente
*
*/
int pass_setApellido(Passenger* listPass, int indexCambio)
{
	int retorno;
	char nuevoApellido[SIZE_STR];
	retorno = -1;
	if(listPass != NULL)
	{
		retorno = -2;
		if(!pass_getApellido(nuevoApellido, SIZE_STR))
		{
			strncpy(listPass[indexCambio].lastName, nuevoApellido, SIZE_STR);
			retorno = 0;
		}
	}
	return retorno;
}

/**
* \brief Recibe un array de estructuras para ingresar a la posicion indicada por el parametro recibido y cambiar el dato en el campo .price
* \param listPass employee* recibe la direccion de memoria del array a analizar
* \param indexCambio int recibe por valor la posicion del array en la que se realiza el cambio
* \return int Retorna -1 si hubo un error en los parametros recibidos
* 		      -2 si hubo un error en la interaccion con el usuario
* 		       0 si pudo operar exitosamente
*
*/
int pass_setPrecio(Passenger* listPass, int indexCambio)
{
	int retorno;
	float nuevoPrecio;
	retorno = -1;
	if(listPass != NULL)
	{
		retorno = -2;
		if(pass_getPrecio(&nuevoPrecio)>0)
		{
			listPass[indexCambio].price = nuevoPrecio;
			retorno = 0;
		}
	}
	return retorno;
}

/**
* \brief Recibe un array de estructuras para ingresar a la posicion indicada por el parametro recibido y cambiar el dato en el campo .typePassenger
* \param listPass employee* recibe la direccion de memoria del array a analizar
* \param indexCambio int recibe por valor la posicion del array en la que se realiza el cambio
* \param listaTipoPasajeros typePass* Recibe la direccion de memoria de la lista secundaria
* \param sizeTipoPasajeros int Recibe por valor el tamaño de la lista secundaria
* \return int Retorna -1 si hubo un error en los parametros recibidos
* 		      -2 si hubo un error en la interaccion con el usuario
* 		       0 si pudo operar exitosamente
*
*/
int pass_setTipoPasajero(Passenger* listPass, int indexCambio, typePass* listaTipoPasajeros, int sizeListaTipoPasajeros)
{
	int retorno;
	int nuevoTipo;
	retorno = -1;
	if(listPass != NULL)
	{
		retorno = -2;
		if(pass_getTipoPasajero(&nuevoTipo, listaTipoPasajeros, sizeListaTipoPasajeros)>0)
		{
			listPass[indexCambio].idTypePass = nuevoTipo;
			retorno = 0;
		}
	}
	return retorno;
}

/**
* \brief Recibe un array de estructuras para ingresar a la posicion indicada por el parametro recibido y cambiar el dato en el campo .flycode
* \param listPass employee* recibe la direccion de memoria del array a analizar
* \param indexCambio int recibe por valor la posicion del array en la que se realiza el cambio
* \return int Retorna -1 si hubo un error en los parametros recibidos
* 		      -2 si hubo un error en la interaccion con el usuario
* 		       0 si pudo operar exitosamente
*
*/
int pass_setCodigoVuelo(Passenger* listPass, int indexCambio)
{
	int retorno;
	char nuevoCodigoVuelo[SIZE_CODE];
	retorno = -1;
	if(listPass != NULL)
	{
		retorno = -2;
		if(!pass_getCodigoVuelo(nuevoCodigoVuelo, SIZE_CODE))
		{
			strncpy(listPass[indexCambio].flycode, nuevoCodigoVuelo, SIZE_CODE);
			retorno = 0;
		}
	}
	return retorno;
}


/** 
* \brief find a Passenger by Id and returns the index position in array.
* \param listPass Passenger* receives the array's memory adress that will operate
* \param sizeListPass int to indicate array size
* \param idConsulta int receives the value that compare with .id
* \return Return >=0 passenger index position
* 		(-1) if error about the parameters
*		(-2) if passenger not found
*
*/
int pass_findIndexSegunId(Passenger* listPass, int sizePass, int idConsulta)
{
	int indexPosition;
	int i;

	indexPosition = -1;
	if(listPass!= NULL && sizePass>0)
	{
		indexPosition = -2;
		for(i=0; i<sizePass; i++)
		{
			if(validacionesInt_sonIdenticos(listPass[i].id, idConsulta))
			{
				indexPosition = i;
				break;
			}
		}
	}
	return indexPosition;
}

/**
* \brief interactua con el usuario para pedir un id, si es valido busca el index que ocupa
* \param listPass Passenger* Recibe la direccion de memoria del primer elemento del array que analiza
* \param sizePass int Recibe por valor el tamaño del array
* \param listaTipoPasajeros typePass* Recibe la direccion de memoria de la lista secundaria
* \param sizeTipoPasajeros int Recibe por valor el tamaño de la lista secundaria
* \return Return >=0 si opero correctamente (el index hayado)
* 				(-1) si hubo un error en los parametros recibidos
*
*/
int pass_pedirIdYDevolverIndex(Passenger* listPass, int sizePass, typePass* listaTipoPasajeros, int sizeListaTipoPasajeros)
{
    int retorno;
    int idConsulta;
    int indexConsulta;

    retorno = -1;
    if(listPass != NULL && sizePass >0)
    {
        pass_pedirIdConsulta(&idConsulta,listPass, sizePass, listaTipoPasajeros, sizeListaTipoPasajeros);
        if(idConsulta >0)
        {
            indexConsulta = pass_findIndexSegunId(listPass, sizePass, idConsulta);
            ///pass_printOneIndice(listPass, indexConsulta);
            retorno = indexConsulta;
        }
    }
    return retorno;
}

/** 
* \brief Asigna valor -2(removido) en campo .isEmpty del array recibido, segun el index indicado por parametro
* \param arrayPasajeros Passenger* Recibe la direccion de memoria del primer elemento del array sobre el cual se operara
* \param indexIdConsulta int Recibe por valor el index en el cual se hara la asignacion
* \return Return 0 si opero correctamente
* 				(-1) si hubo un error en los parametros recibidos
*
*/
int pass_removerSegunId(Passenger* arrayPasajeros, int indexIdConsulta)
{
	int retorno;
	retorno = -1;
	if( arrayPasajeros != NULL && indexIdConsulta >=0)
	{
		retorno = -2;
		if(arrayPasajeros[indexIdConsulta].isEmpty==NOT_EMPTY)
		{
			arrayPasajeros[indexIdConsulta].isEmpty=DELETED;
			retorno = 0;
		}

	}
	return retorno;
}

/**
 * recibe el array y su tamaño y un valor para que, en caso de que sea -1, invoque al initArray y retorne 0
 *
 */
int pass_prepararArray(Passenger* pArray, int sizeArray, int clientesCargados)
{
	int retorno;
	retorno = -1;
	if(pArray!= NULL && sizeArray>0 && clientesCargados == -1)
	{
		pass_initArray(pArray, sizeArray);
		retorno = 0;
	}
	return retorno;
}

/**
 * llama a la funcion cambiar el nombre para interactuar con el usuario y luego imprime los datos del cliente con los cambios
 * \param pArray Passenger* Recibe la direccion de memoria del primer elemento del array sobre el cual se operara
 * \param index int Recibe por valor el index en el cual se hara la asignacion
 * \return void
 */
void pass_cambiarNombreEImprimir(Passenger* pArray, int index)
{
	if(pArray!= NULL)
	{
		if(!pass_setNombre(pArray, index))
		{
			pass_printRotulo();
			pass_printOneIndice(pArray, index);
		}
		else
		{
			tp_MensajeError("ERROR** Ha habido un error al modificar el dato. Vuelva a intentar\n");
		}
	}
	else
	{
		tp_MensajeErrorGenerico(-1);
	}
}

/**
 * llama a la funcion cambiar el nombre para interactuar con el usuario y luego imprime los datos del cliente con los cambios
 * \param pArray Passenger* Recibe la direccion de memoria del primer elemento del array sobre el cual se operara
 * \param index int Recibe por valor el index en el cual se hara la asignacion
 * \return void
 */
void pass_cambiarApellidoEImprimir(Passenger* pArray, int index)
{
	if(pArray!= NULL)
	{
		if(!pass_setApellido(pArray, index))
		{
			pass_printRotulo();
			pass_printOneIndice(pArray, index);
		}
		else
		{
			tp_MensajeError("ERROR** Ha habido un error al modificar el dato. Vuelva a intentar\n");
		}
	}
	else
	{
		tp_MensajeErrorGenerico(-1);
	}
}

/**
 * llama a la funcion cambiar el nombre para interactuar con el usuario y luego imprime los datos del cliente con los cambios
 * \param pArray Passenger* Recibe la direccion de memoria del primer elemento del array sobre el cual se operara
 * \param index int Recibe por valor el index en el cual se hara la asignacion
 * \return void
 */
void pass_cambiarPrecioEImprimir(Passenger* pArray, int index)
{
	if(pArray!= NULL)
	{
		if(!pass_setPrecio(pArray, index))
		{
			pass_printRotulo();
			pass_printOneIndice(pArray, index);
		}
		else
		{
			tp_MensajeError("ERROR** Ha habido un error al modificar el dato. Vuelva a intentar\n");
		}
	}
	else
	{
		tp_MensajeErrorGenerico(-1);
	}
}

/**
 * llama a la funcion cambiar el nombre para interactuar con el usuario y luego imprime los datos del cliente con los cambios
 * \param pArray Passenger* Recibe la direccion de memoria del primer elemento del array sobre el cual se operara
 * \param index int Recibe por valor el index en el cual se hara la asignacion
 * \param listaTipoPasajeros typePass* Recibe la direccion de memoria de la lista secundaria
 * \param sizeTipoPasajeros int Recibe por valor el tamaño de la lista secundaria
 * \return void
 */
void pass_cambiarTipoPasajeroEImprimir(Passenger* pArray, int index, typePass* listaTipoPasajeros, int sizeListaTipoPasajeros)
{
	if(pArray!= NULL)
	{
		if(!pass_setTipoPasajero(pArray, index, listaTipoPasajeros, sizeListaTipoPasajeros))
		{
			pass_printRotulo();
			pass_printOneIndice(pArray, index);
		}
		else
		{
			tp_MensajeError("ERROR** Ha habido un error al modificar el dato. Vuelva a intentar\n");
		}
	}
	else
	{
		tp_MensajeErrorGenerico(-1);
	}
}

/**
 * llama a la funcion cambiar el nombre para interactuar con el usuario y luego imprime los datos del cliente con los cambios
 * \param pArray Passenger* Recibe la direccion de memoria del primer elemento del array sobre el cual se operara
 * \param index int Recibe por valor el index en el cual se hara la asignacion
 * \return void
 */
void pass_cambiarCodigoVueloEImprimir(Passenger* pArray, int index)
{
	if(pArray!= NULL)
	{
		if(!pass_setCodigoVuelo(pArray, index))
		{
			pass_printRotulo();
			pass_printOneIndice(pArray, index);
		}
		else
		{
			tp_MensajeError("ERROR** Ha habido un error al modificar el dato. Vuelva a intentar\n");
		}
	}
	else
	{
		tp_MensajeErrorGenerico(-1);
	}
}


/**
 * retorna el valor ingresado por teclado
 * \param pArray Passenger* Recibe la direccion de memoria del primer elemento del array sobre el cual se operara
 * \param sizeArray int Recibe por valor el tamaño de la lista
 * \param indexConsulta int Recibe por valor el index en el cual se hara la asignacion
 * \param listaTipoPasajeros typePass* Recibe la direccion de memoria de la lista secundaria
 * \param sizeTipoPasajeros int Recibe por valor el tamaño de la lista secundaria
 * \return Return -1 si hubo un error en los parametros
 * 				  >0 si opero correctamente (retorna el valor ingresado por teclado)
 */
int pass_interaccionMenuSecundario(Passenger* pArray, int sizeArray, int indexConsulta, typePass* listaTipoPasajeros, int sizeListaTipoPasajeros)
{
	//int retorno;
	int menu;
	menu = -1;
	if(pArray!= NULL && sizeArray>0 && indexConsulta>=0)
	{
		menu = tp_ImprimirMenuSeisOpciones("\nMODIFICAR - Indique el dato que desea modificar", "1- Nombre", "2- Apellido", "3- Precio", "4- Tipo Pasajero", "5- Codigo Vuelo", "6- Regresar atras");
		switch(menu)
		{
			case 1:
				pass_cambiarNombreEImprimir(pArray, indexConsulta);
				break;
			case 2:
				pass_cambiarNombreEImprimir(pArray, indexConsulta);
				break;
			case 3:
				pass_cambiarPrecioEImprimir(pArray, indexConsulta);
				break;
			case 4:
				pass_cambiarTipoPasajeroEImprimir(pArray, indexConsulta, listaTipoPasajeros, sizeListaTipoPasajeros);
				break;
			case 5:
				pass_cambiarCodigoVueloEImprimir(pArray, indexConsulta);
				break;
		}
	}
	return menu;
}

/**
* \brief intercambia el contenido de dos variables tipo Passenger
* \param arrayPasajeros Passenger* Recibe la direccion de memoria del primer elemento del array sobre el cual se operara
* \param index1 int Recibe por valor el index en el que se encuentra la variable a intercambiar
* \param index2 int Recibe por valor el index en el que se encuentra la variable por la cual se intercambiara
* \return Return 0 si opero correctamente
* 				(-1) si hubo un error en los parametros recibidos
*
*/
int pass_swap(Passenger* listPass, int index1, int index2)
{
	int retorno;
	Passenger auxPass;
	retorno = -1;
	if(listPass!= NULL)
	{
		auxPass= listPass[index1];
		listPass[index1]= listPass[index2];
		listPass[index2]= auxPass;
		retorno=0;
	}
	return retorno;
}

/**
* \brief ordena la lista recibida alfabeticamente segun el codigo del vuelo y muestra los correspondientes a VUELOS ACTIVOS
* \param listPass Passenger* Recibe la direccion de memoria de la lista con la que operara
* \param sizeArray int Recibe por valor el tamaño de la lista
* \param listaTipoPasajeros typePass* Recibe la direccion de memoria de la lista secundaria con la que tiene que operar
* \param sizeListaTipoPasajeros int Recibe por valor el tamaño de la lista lista secundaria
* \return Return 0 si opero correctamente
* 				(-1) si hubo un error en los parametros recibidos
*
*/
int pass_ordenarVuelosActivos(Passenger* listPass, int sizeArray, typePass* listaTipoPasajeros, int sizeListaTipoPasajeros)
{
	int retorno;
	int i;
	retorno = -1;
	if(listPass!= NULL && sizeArray >0)
	{
		retorno = 0;
		pass_ordenarArrayPorCodigoVuelo(listPass, sizeArray);
		printf("\nVUELOS ACTIVOS Ordenados por codigo de vuelo\n");
		for(i=0; i<sizeArray; i++)
		{
			if(listPass[i].isEmpty == NOT_EMPTY && listPass[i].statusFlight == 1)
			{
				pass_printOneIndice(listPass, i);
				printf("\n");
			}
		}

	}
	return retorno;
}

/**
* \brief ordena la lista recibida alfabeticamente segun el codigo del vuelo
* \param listPass Passenger* Recibe la direccion de memoria de la lista con la que operara
* \param sizeArray int Recibe por valor el tamaño de la lista
* \return Return 0 si opero correctamente
* 				(-1) si hubo un error en los parametros recibidos
*
*/
int pass_ordenarArrayPorCodigoVuelo(Passenger* listPass, int sizeArray)
{
	int retorno;
	int nuevoLimite;
	int flagSwap;
	int i;
	int strCompare;

	retorno = -1;
	if(listPass!= NULL && sizeArray >0 )
	{
		nuevoLimite = sizeArray -1;
		do
		{
			flagSwap = 0;
			for(i=0; i<nuevoLimite; i++)
			{
				if(	listPass[i].isEmpty == NOT_EMPTY && listPass[i+1].isEmpty == NOT_EMPTY)
				{
					strCompare=strncmp(listPass[i].lastName, listPass[i+1].lastName, SIZE_STR);
					if(strCompare < 0)
					{
						pass_swap(listPass, i, i+1);
						flagSwap = 1;
					}
				}
			}
			nuevoLimite --;
		}while(flagSwap);
		retorno = 0;
	}
	return retorno;
}

/**
* \brief muestra el listado de pasajeros ordenado alfabeticamente y por tipo de pasajero (si tienen el mismo apellido, muestra primero el pasajero de clase mas alta)
* \param arrayPasajeros Passenger* Recibe la direccion de memoria del primer elemento del array sobre el cual se operara
* \param sizeArray int Recibe por valor tamaño de la lista
* \param criterio int Recibe por valor el indicador del criterio con el cual se hara el ordenamiento
* \return Return 0 si opero correctamente
* 				(-1) si hubo un error en los parametros recibidos
*
*/
int pass_ordenarArrayPorNombreOTipo(Passenger* listPass, int sizeArray, int criterio)//sortPassengers
{
	int retorno;
	int i;
	int strCompare;
	int flagSwap;
	int nuevoLimite;

	//printf("DEBUG UN PASAJERO: %s", auxPass.lastName );
	retorno = -1;
	if(listPass!= NULL && sizeArray>0)
	{
		nuevoLimite = sizeArray-1;

		do
		{
			flagSwap = 0;
			for(i=0; i<nuevoLimite; i++)
			{
				if(listPass[i].isEmpty == NOT_EMPTY && listPass[i+1].isEmpty == NOT_EMPTY )
				{
					if( !arrayChar_convertirStringMayuscula(listPass[i].lastName, strlen(listPass[i].lastName))
						&&	!arrayChar_convertirStringMayuscula(listPass[i+1].lastName, strlen(listPass[i+1].lastName)))
					{
						strCompare=strncmp(listPass[i].lastName, listPass[i+1].lastName, SIZE_STR);
						arrayChar_convertirASustantivoPropio(listPass[i].lastName, strlen(listPass[i].lastName));
						arrayChar_convertirASustantivoPropio(listPass[i+1].lastName, strlen(listPass[i+1].lastName));
					}
						//printf("DEBUG***** transformamos a camelcase?");
					else
					{
						printf("[ERROR***] Ha habido un error en el analisis de los datos");
					}
					//printf("\nDEBUG*** %s - %s = %d", listPass[i].lastName, listPass[i+1].lastName, strCompare);
					switch (criterio)
					{
						case 1:
							if(strCompare>0)
							{
								/*printf("\nDEBUG*** %d > 0 => cambio el orden", strCompare);
								if(!pass_swap(listPass, i, i+1))
								{
									printf("CAMBIO OK\n");
								}*/
								pass_swap(listPass, i, i+1);
								flagSwap = 1;
							}
							else
							{
								if(strCompare == 0 && listPass[i].idTypePass > listPass[i+1].idTypePass)//mostrar primero el tipo de pasajero con idTypo menor
								{
									/*printf("\nDEBUG*** %d == 0 y tipo[%d]=%d < tipo[%d]=%d", strCompare, i,listPass[i].typePassenger , i+1, listPass[i+1].typePassenger );
									if(!pass_swap(listPass, i, i+1))
									{
										printf("CAMBIO OK\n");
									}*/
									pass_swap(listPass, i, i+1);
									flagSwap = 1;
								}
							}
							break;
						case 2:
							if(strCompare<0)
							{
								pass_swap(listPass, i, i+1);
								flagSwap = 1;
							}
							else
							{
								if(strCompare == 0 && listPass[i].idTypePass > listPass[i+1].idTypePass)//mostrar primero el tipo de pasajero con idTypo menor
								{
									pass_swap(listPass, i, i+1);
									flagSwap = 1;
								}
							}
							break;
					}
				}
			}
			nuevoLimite--;
		}while(flagSwap);
		retorno = 0;
	}

	return retorno;
}


/**
* \brief realiza un hardcodeo de 5 elementos a cargar en el array de tipo Passenger
* \param arrayPasajeros Passenger* Recibe la direccion de memoria del primer elemento del array sobre el cual se operara
* \param sizeArray int Recibe por valor tamaño de la lista
* \return Return 0 si opero correctamente
* 				(-1) si hubo un error en los parametros recibidos
*
*/
int pass_cargaForzadaDeDatos(Passenger* listPass, int sizeArray)
{
	int retorno;
	int i;
	Passenger cargaPasajeros[] = {
								{101, "Julieta", "Nakasone", 15006, "DHJ109", 1, 2, NOT_EMPTY},
								{102, "Amalia", "Nakasone", 15004, "ASD18", 2, 2, NOT_EMPTY},
								{103, "Habib", "Gramondi", 15012, "ASJ9", 3, 1, NOT_EMPTY},
								{104, "Lautaro", "Almafuerte", 15015, "XCZ239", 1, 1, NOT_EMPTY},
								{105, "Micaela", "Juarez", 15000, "ZXC159", 1, 2, NOT_EMPTY}
							};
	retorno = -1;
	if(listPass!= NULL && sizeArray>0)
	{
		retorno = -2;
		for(i=0; i<5; i++)
		{
			listPass[i]= cargaPasajeros[i];
		}
		retorno = 0;
	}

	return retorno;
}

/**
* \brief pide un criterio de ordenamiento para enlistar el array recibido
* \param arrayPasajeros Passenger* Recibe la direccion de memoria del primer elemento del array sobre el cual se operara
* \param sizeArray int Recibe por valor tamaño de la lista
* \param listaTipoPasajeros typePass* Recibe la direccion de memoria de la lista secundaria
* \param sizeTipoPasajeros int Recibe por valor el tamaño de la lista secundaria
* \return Return 0 si opero correctamente
* 				(-1) si hubo un error en los parametros recibidos
*
*/
int pass_consignaCuatroUno(Passenger* listPass, int sizeArray, typePass* listaTipoPasajeros, int sizeListaTipoPasajeros)
{
	int retorno;
	int criterio;
	retorno = -1;
	if(listPass!= NULL && sizeArray>0)
	{
		retorno = 0;
		if(!utn_GetNumeroInt(&criterio, "1- Forma ascendente \n2- Forma descendente", "ingrese un dato valido", 1, 2, REINTENTOS)
			&& !pass_ordenarArrayPorNombreOTipo(listPass, sizeArray, criterio))
		{
			pass_printArrayConTipoPasajero(listPass, sizeArray, listaTipoPasajeros, sizeListaTipoPasajeros);
		}
		else
		{
			tp_MensajeError("Ha habido un error");
		}

	}
	return retorno;
}





/**
* \brief Calcula el total y el promedio de los precios de pasajeros e informa:
* 		  - total de precios de los pasajes
* 		  - promedio de precios de los pasajes
* 		  - cantidad de pasajeros que superan el precio promedio
*
* \param arrayPasajeros Passenger* Recibe la direccion de memoria del primer elemento del array sobre el cual se operara
* \param sizeArray int Recibe por valor tamaño de la lista
* \return Return  0 si opero correctamente
* 				(-1) si hubo un error en los parametros recibidos
*
*/
int pass_consignaCuatroDos(Passenger* listPass, int sizeArray)
{
	int retorno;
	float preciosAcumulado;
	int contadorPrecios;
	float promedio;
	int superanPromedio;
	retorno =-1;

	if(listPass!= NULL && sizeArray>0)
	{
		printf("\n\nInformes acerca de los precios:\n ");
		contadorPrecios= pass_acumuladorTotalPreciosCargados(listPass, sizeArray, &preciosAcumulado);
		//printf("DEBUG******* contador: %d", contadorPrecios);
		if(contadorPrecios)
		{
			//printf("DEBUG******* acumulador: %.2f / contador precios: %d", preciosAcumulado, contadorPrecios);
			promedio= tp_calcularPromedio(preciosAcumulado, contadorPrecios);
			superanPromedio = pass_contadorPreciosSuperanPromedio(listPass, sizeArray, promedio);

			printf("a) Total de precios de pasajes: %.2f \nb) Promedio de precios de pasajes: %.2f\nc) Cantidad de pasajeros que superan el precio promedio: %d\n\n",
						preciosAcumulado, promedio, superanPromedio);
		}
		else
		{
			tp_MensajeErrorGenerico(contadorPrecios);
		}

		retorno =0;
	}
	return retorno;
}

/**
* \brief recorre el array en el campo .price para acumular los precios de los elementos cargados como NOT EMPTY e indica la cantidad
* \param arrayPasajeros Passenger* Recibe la direccion de memoria del primer elemento del array sobre el cual se operara
* \param sizeArray int Recibe por valor tamaño de la lista
* \param acumuladorPrecios *float Recibe una direccion de memoria donde guardar el valor acumulado de precios
* \return Return >0 si encontro elementos(retorna la cantidad de elementos encontrados)
* 				  0 si opero correctamente pero no encontro elementos
* 				(-1) si hubo un error en los parametros recibidos
*
*/
int pass_acumuladorTotalPreciosCargados(Passenger* listPass, int sizeArray, float* acumuladorPrecios)
{
	int contador;
	int i;

	contador =-1;
	if(listPass!= NULL && sizeArray>0)
	{
		//printf("entre en el if");
		contador =0;
		*acumuladorPrecios = 0;
		for(i=0; i<sizeArray; i++)
		{
			if(listPass[i].isEmpty == NOT_EMPTY)
			{
				//printf("estoy en el not empty");
				*acumuladorPrecios = *acumuladorPrecios + listPass[i].price;
				contador++;
			}
		}
	}
	return contador;
}


/**
* \brief recorre el array para comprar los valores de .price que sean mayor al promedio recibido y contarlos
* \param arrayPasajeros Passenger* Recibe la direccion de memoria del primer elemento del array sobre el cual se operara
* \param sizeArray int Recibe por valor tamaño de la lista
* \param promedio float Recibe por valor el dato contra el cual compara
* \return Return >0 si encontro elementos(retorna la cantidad de elementos encontrados)
* 				  0 si opero correctamente pero no encontro elementos
* 				(-1) si hubo un error en los parametros recibidos
*
*/
int pass_contadorPreciosSuperanPromedio(Passenger* listPass, int sizeArray, float promedio)
{
	int contador;
	int i;
	contador =-1;
	if(listPass!= NULL && sizeArray>0)
	{
		contador =0;
		for(i=0; i<sizeArray; i++)
		{
			if(listPass[i].isEmpty == NOT_EMPTY && listPass[i].price<promedio)
			{
				contador ++;
			}
		}
	}
	return contador;
}

/**
* \brief recorre la lista recibida en el campo .id para analizar sus valores y devolver el mayor numero encontrado
* \param arrayPasajeros Passenger* Recibe la direccion de memoria del primer elemento del array sobre el cual se operara
* \param sizeArray int Recibe por valor tamaño de la lista
* \param ultimoId int* Recibe por la direccion de memoria donde alojara el valor hallado
* \return Return >0 si encontro elementos(retorna la cantidad de elementos encontrados)
* 				  0 si opero correctamente pero no encontro elementos
* 				(-1) si hubo un error en los parametros recibidos
*
*/
int pass_encontrarMayorId(Passenger* listPass, int sizeArray, int* ultimoId)
{
	int retorno;
	//int ultimoId;
	retorno =-1;
	if(listPass!= NULL && sizeArray>0)
	{
		retorno=0;
		for(int i=0; i<sizeArray; i++)
		{
			if(listPass[i].isEmpty== NOT_EMPTY)
			{
				if(i==0)
				{
					*ultimoId=ID_INICIAL;
				}
				else
				{
					if(listPass[i].id>*ultimoId)
					{
						*ultimoId=listPass[i].id;
					}
				}
			}
		}
		*ultimoId= *ultimoId+1;

	}
	return retorno;
}

/**
* \brief recorre la lista recibida y contabiliza las posiciones que han sido cargadas
* \param arrayPasajeros Passenger* Recibe la direccion de memoria del primer elemento del array sobre el cual se operara
* \param sizeArray int Recibe por valor tamaño de la lista
* \param contador int* Recibe por la direccion de memoria donde alojara la cantidad contabilizada
* \return Return >0 si encontro elementos(retorna la cantidad de elementos encontrados)
* 				  0 si opero correctamente pero no encontro elementos
* 				(-1) si hubo un error en los parametros recibidos
*
*/
int pass_contadorClientesCargados(Passenger* listPass, int sizeArray, int* contador)
{
	int retorno;
	retorno =-1;
	if(listPass!= NULL && sizeArray>0)
	{
		retorno =0;
		*contador = 0;
		for(int i=0; i<sizeArray; i++)
		{
			if(listPass[i].isEmpty== NOT_EMPTY)
			{
				//printf("i = %d - id: %d", i, listPass[i].id);
				*contador= *contador+1;
			}
		}
	}
	return retorno;
}

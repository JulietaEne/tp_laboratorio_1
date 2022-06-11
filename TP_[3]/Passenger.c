/*
 * Passenger.c
 *
 *  Created on: 24 may. 2022
 *      Author: Julieta Nakasone
 */
#include "Passenger.h"
#include "parser.h"


//---------------------CONSTRUCTORES (from str, from ninary, from buffer)---------------------//

/** \brief Reserva espacio en el heap para una variable del tipo ePassenger
 *
 * \return ePassenger* retorna NULL si no encontro espacio en heap para crear una variable del tipo ePassenger
 * 					   		   *ePassenger (direccion de memoria al tipo ePassenger) si realizo la operacion correctamente
 *
 */
ePassenger* Passenger_new(void)
{
	return (ePassenger*) malloc(sizeof(ePassenger));
}

/** \brief Crea un pasajero en memoria dinamica seteando en sus campos los datos recibidos por parametro (modo texto)
 *
 * \param char* id recibe el valor correspondiente para el campo id
 * \param char* nombre recibe la referencia a la cadena correspondiente para el campo nombre
 * \param char* precio recibe el valor correspondiente al campo precio
 * \param char* codigoVuelo recibe la referencia a la cadena correspondiente para el campo FlyCode
 * \param char* tipoPasajero recibe la referencia a la cadena correspondiente para el campo Tipo Pasajero
 * \param char* estadoVuelo recibe la referencia a la cadena correspondiente para el campo tipo pasajero
 * \return ePassenger* retorna NULL si hubo un error al realizar la operacion
 * 					   		   *ePassenger si logro crear y setear a la variable del tipo estructura(retorna la direccion de memoria en donde se creo al pasajero)
 *
 */
ePassenger* Passenger_newParametrosStringAll(char* idStr,char* nombreStr,char* apellidoStr, char* precioStr, char* codigoVueloStr, char* tipoPasajeroStr, char* estadoVueloStr)
{
	ePassenger* this = NULL;
	if(idStr != NULL && nombreStr != NULL && tipoPasajeroStr != NULL)
	{
		this = Passenger_new();
		if(this != NULL)
		{
			Passenger_setIdStr(this, idStr);
			Passenger_setNombre(this, nombreStr);
			Passenger_setLastName(this, apellidoStr);
			Passenger_setPriceStr(this, precioStr);
			Passenger_setCodigoVuelo(this, codigoVueloStr);
			Passenger_setTipoPasajero(this, tipoPasajeroStr);
			Passenger_setStatusFlight(this, estadoVueloStr);
		}
		else
		{
			passenger_delete(this);
		}
	}
	return this;
}

/** \brief Crea un pasajero en memoria dinamica seteando en sus campos los datos recibidos por parametro (modo binario)
 *
 * \param int id recibe el valor correspondiente para el campo id
 * \param char* nombre recibe la referencia a la cadena correspondiente para el campo nombre
 * \param float* precio recibe el valor correspondiente al campo precio
 * \param char* codigoVuelo recibe la referencia a la cadena correspondiente para el campo FlyCode
 * \param char* tipoPasajero recibe la referencia a la cadena correspondiente para el campo Tipo Pasajero
 * \param char* estadoVuelo recibe la referencia a la cadena correspondiente para el campo tipo pasajero
 * \return ePassenger* retorna NULL si hubo un error al realizar la operacion
 * 					   		   *ePassenger si logro crear y setear a la variable del tipo estructura(retorna la direccion de memoria en donde se creo al pasajero)
 *
 */
ePassenger* Passenger_newParametrosAllBinary(int id,char* nombre,char* apellido, float precio, char* codigoVuelo, char* tipoPasajero, char* estadoVuelo)
{
	ePassenger* this = NULL;
	int cargaCorrecta;

	//int retornoFuncion;
	if(nombre != NULL && tipoPasajero != NULL)
	{
		this = Passenger_new();
		if(this != NULL)
		{
			cargaCorrecta = 0;
			Passenger_setIdBinary(this, id);
			Passenger_setNombre(this, nombre);
			Passenger_setTipoPasajero(this, tipoPasajero);
			Passenger_setLastName(this, apellido);
			Passenger_setCodigoVuelo(this, codigoVuelo);
			Passenger_setPrecio(this, precio);
			Passenger_setStatusFlight(this, estadoVuelo);
			cargaCorrecta = 1;

			if(!cargaCorrecta)
			{
				passenger_delete(this);
				printf("ERROR AL CARGAR EL DATO %d , %s, %s", id, nombre, tipoPasajero);
			}
		}
	}
	return this;
}

/** \brief Crea un pasajero en memoria dinamica seteando en sus campos los datos recibidos por parametro
 *
 * \param int id recibe el valor correspondiente para el campo id
 * \param char* nombre recibe la referencia a la cadena correspondiente para el campo nombre
 * \param float* precio recibe el valor correspondiente al campo precio
 * \param char* codigoVuelo recibe la referencia a la cadena correspondiente para el campo FlyCode
 * \param char* tipoPasajero recibe la referencia a la cadena correspondiente para el campo Tipo Pasajero
 * \param char* estadoVuelo recibe la referencia a la cadena correspondiente para el campo tipo pasajero
 * \param int controlLista recibe el valor de una bandera que indica si es el primer elemento cargado por buffer
 * \return ePassenger* retorna NULL si hubo un error al realizar la operacion
 * 					   		   *ePassenger si logro crear y setear a la variable del tipo estructura(retorna la direccion de memoria en donde se creo al pasajero)
 *
 */
ePassenger* Passenger_newParametrosAll(int id,char* nombre,char* apellido, float precio, char* codigoVuelo, char* tipoPasajero, char* estadoVuelo, int controlLista)
{
	ePassenger* this = NULL;
	int cargaCorrecta;

	//int retornoFuncion;
	if(nombre != NULL && tipoPasajero != NULL)
	{
		this = Passenger_new();
		if(this != NULL)
		{
			cargaCorrecta = 0;
			Passenger_setId(this, id, controlLista);
			Passenger_setNombre(this, nombre);
			Passenger_setTipoPasajero(this, tipoPasajero);
			Passenger_setLastName(this, apellido);
			Passenger_setCodigoVuelo(this, codigoVuelo);
			Passenger_setPrecio(this, precio);
			Passenger_setStatusFlight(this, estadoVuelo);

			cargaCorrecta = 1;

			if(!cargaCorrecta)
			{
				passenger_delete(this);
				printf("ERROR AL CARGAR EL DATO %d , %s, %s", id, nombre, tipoPasajero);
			}
		}
	}
	return this;
}
//------------------------------------------------

/** \brief valida que el pasajero recibido contenga el idBusqueda en su campo ID, si es correcto, retorna el pasajero
 *
 * \param ePassenger* this Recibe la direccion de memoria del elemento a analizar
 * \param int idBusqueda Recibe por valor el dato contra el cual se compara
 * \return ePassenger* NULL si no hay coincidencia
 * 			   			retorna el puntero al pasajero correspondiente, si hay coincidencia
 *
 */
ePassenger* Passenger_findIndexById(ePassenger* this, int idBusqueda)
{
	ePassenger* thisCorrecto=NULL;
	if (this != NULL)
	{
		if(this->id== idBusqueda)
		{
			thisCorrecto = this;
		}
	}
	return thisCorrecto;
}

/** \brief elimina de memoria dinamica pasajero recibido por parametros
 *
 * \param ePassenger* this recibe el puntero al elemento sobre el cual se va a realizar la operacion
 * \return int  retorna -1 si hubo un error en los parametros recibidos
 * 						-2 si se cancela la operacion
 * 						0 si elimino correctamente
 *
 */
int passenger_delete(ePassenger* this)
{
	int retorno;
	int confirmar;

	retorno = -1;//si hay error en los parametros
	confirmar =0;

	if(this != NULL)
	{
		retorno=-2; // si se cancela la eliminacion
		printf("pasajero id: %d - nombre: %s\n", this->id, this->nombre);
		confirmar=tp_continuar("confirma la baja del pasajero? (Y/N)");
		if(confirmar)
		{
			free(this);
			retorno=0;// si se borra correctamente
		}
	}
	return retorno;
}

//------------------------- PRINT -------------------------//
/** \brief recibe un pasajero e imprime los datos de sus campos
 *
 * \param ePassenger* this recibe el puntero al elemento sobre el cual se va a realizar la operacion
 * \return int  retorna -1 si hubo un error en los parametros recibidos
 * 						0 si opero correctamente
 *
 */
int Passenger_printPasajero(ePassenger* this)
{
	int retorno;
	retorno=-1;
	if(this != NULL)
	{
		printf("%d %13s %17s %15.2f %15s %18s %15s\n",
												this->id,
												this->nombre,
												this->apellido,
												this->precio,
												this->flyCode,
												this->tipoPasajero,
												this->estadoVuelo);
		retorno =0;
	}
	return retorno;
}

/** \brief Imprime el encabezado de la lista
 *
 * \return void
 *
 */
void Passenger_printEncabezado(void)
{
	printf("ID\tNOMBRE\t\tAPELLIDO\tPRECIO\t\tCODIGO VUELO\tTIPO PASAJERO\tESTADO VUELO\n");
}

/** \brief Imprime un mensaje con el ID del pasajero recibido por parametros
 *
 * \param char* mensaje recibe el mensaje a imprimir
 * \param ePassenger* this recibe el puntero al elemento sobre el cual se va a realizar la operacion
 * \return void
 *
 */
void Passenger_printMensajeConId(char* mensaje, ePassenger* pAuxPasajero)
{
	if(mensaje != NULL)
	{
		printf("%s ID %d\n", mensaje, pAuxPasajero->id);
	}
}
//------------------------- SETTERS -------------------------//
/** \brief recibe un valor de id, lo valida y lo copia en el campo ID del elemento
 *
 * \param ePassenger* this recibe el puntero al elemento sobre el cual se va a realizar la operacion
 * \param int id recibe por valor el dato correspondiente al id
 * \param int controlLista bandera para controlar si es el primer elemento cargado manualmente
 * \return int  retorna -1 si hubo un error en los parametros recibidos
 * 						-2 si el valor recibido como id no corresponde al rango esperado
 * 						0 si realizo la operacion correctamente
 *
 */
int Passenger_setId(ePassenger* this,int id, int controlLista)
{
	int retorno;
	int auxId;
	int mantenerIdArchivo;
	int fromFile;

	retorno =-1;
	fromFile = 1;
	if(this != NULL)
	{
		if(!controlLista)
		{
			do
			{
				mantenerIdArchivo=tp_continuar("Aun no hay datos cargados manualmente en el sistema. \n Presione Y para aceptar comenzar por el ID 1001? Y/N");
			}while(!mantenerIdArchivo);
			if(mantenerIdArchivo)
			{
				auxId = ID_MIN;
				parser_saveIdIntoFile(auxId);
			}
			else
			{
				auxId = id;
			}
			fromFile = 0;
		}
		else
		{
			auxId=0;
			auxId = parser_proximoId(auxId);//si hay archivos cargados,si o si tengo que ser correlativa al id del archivo
		}
		this->id=auxId;
		retorno=0;

		if(fromFile && auxId < FILE_ID_MIN)
		{
			retorno = -2;
			printf("\n[DEBUG] ***WARNING*** el id recibido esta fuera de los parametros esperados para un id. Valor: %d - maximoId: %d\n", auxId, ID_MAX);
		}
	}
	return retorno;
}

/** \brief recibe un valor de id desde el archivo (binario), lo valida y lo copia en el campo ID del elemento
 *
 * \param ePassenger* this recibe el puntero al elemento sobre el cual se va a realizar la operacion
 * \param int id recibe por valor el dato correspondiente al id
 * \return int  retorna -1 si hubo un error en los parametros recibidos
 * 						-2 si el valor recibido como id no corresponde al rango esperado
 * 						0 si realizo la operacion correctamente
 *
 */
int Passenger_setIdBinary(ePassenger* this,int id)
{
	int retorno;
	int auxId;
	//int mantenerIdArchivo;

	auxId = id;
	retorno =-1;

	if(this != NULL)
	{
		this->id=auxId;
		retorno=0;

		if(auxId < FILE_ID_MIN && auxId > ID_MIN)
		{
			retorno = -2;
			printf("\n[DEBUG] ***WARNING*** el id recibido esta fuera de los parametros esperados para un id recibido de archivo. Valor: %d - maximoId: %d\n", auxId, ID_MIN);
		}
	}
	return retorno;
}

/** \brief parsea el valor recibido por parametro y lo setea en this, dentro de su campo id
 *
 * \param ePassenger* this recibe el puntero al elemento sobre el cual se va a realizar la operacion
 * \param char* idStr recibe la referencia de la cadena a la cual se validara como id para setearla en el campo correspondiente
 * \return int  retorna -1 si hubo un error en los parametros recibidos
 * 						-2 si el valor recibido como id no corresponde al rango esperado
 * 						0 si realizo la operacion correctamente
 *
 */
int Passenger_setIdStr(ePassenger* this,char* idStr)
{
	int retorno;
	int auxId;

	retorno =-1;
	if(this != NULL && idStr != NULL && !validaciones_esNumeroInt(idStr, strlen(idStr)))
	{
		auxId = atoi(idStr);
		this->id=auxId;//como proviene de un archivo, guarda el valor en el campo para evitar que quede vacío pero luego avisa si hubo un problema
		retorno=0;
		if(auxId < FILE_ID_MIN && auxId > ID_MIN)
		{
			retorno = -2;
			printf("\n[DEBUG] ***WARNING*** el id recibido esta fuera de los parametros esperados para un id recibido de archivo. Valor: %d - maximoId: %d\n", auxId, ID_MIN);
		}
	}
	return retorno;
}

/** \brief recibe un nombre y lo carga en el campo correspondiente. Lo valida, y si no es correcto, ofrece la posibilidad de cargarlo manualmente
 *
 * \param ePassenger* this recibe el puntero al elemento sobre el cual se va a realizar la operacion
 * \param char* nombre recibe la referencia de la cadena a la cual se validara como nombre para setearla en el campo correspondiente
 * \return int  retorna -1 si hubo un error en los parametros recibidos
 * 						0 si realizo la operacion correctamente
 *
 */
int Passenger_setNombre(ePassenger* this,char* nombre)
{
	int retorno;
	int lenString;
	int cargaManual;

	lenString=strlen(nombre);
	retorno =-1;
	if(this != NULL && nombre != NULL)
	{
		strncpy(this->nombre, nombre, lenString);
		if(!validaciones_esNombre(nombre, lenString))
		{
			retorno=0;
		}
		else
		{
			printf("Error al cargar pasajero nombre:%s id:%d. ", this->nombre, this->id);
			cargaManual= tp_continuar("Desea cargar manualmente? Y/N");
			if(cargaManual)
			{
				parser_getNameToBuffer(nombre, SIZE_STR);
			}
		}
	}
	return retorno;
}

/** \brief recibe un apellido y lo carga en el campo correspondiente. Lo valida, y si no es correcto, ofrece la posibilidad de cargarlo manualmente
 *
 * \param ePassenger* this recibe el puntero al elemento sobre el cual se va a realizar la operacion
 * \param char* apellido recibe la referencia de la cadena a la cual se validara como apellido para setearla en el campo correspondiente
 * \return int  retorna -1 si hubo un error en los parametros recibidos
 * 						0 si realizo la operacion correctamente
 *
 */
int Passenger_setLastName(ePassenger* this,char* apellidoStr)
{
	int retorno;
	int lenString;
	int cargaManual;

	lenString=strlen(apellidoStr);
	retorno =-1;
	//printf("puntero nombre: %s", nombre);
	if(this != NULL && apellidoStr != NULL && !validaciones_esNombre(apellidoStr, lenString))
	{
		//printf("**********estamos en nombre\n");
		strncpy(this->apellido, apellidoStr, lenString);
		if(!validaciones_esNombre(apellidoStr, lenString))
		{
			retorno=0;
		}
		else
		{
			printf("Error al cargar pasajero apellido:%s id:%d. ", this->apellido, this->id);
			cargaManual= tp_continuar("Desea cargar manualmente? Y/N");
			if(cargaManual)
			{
				parser_getLastNameToBuffer(apellidoStr, SIZE_STR);
			}
		}
	}
		return retorno;
}

/** \brief recibe un precio y lo carga en el campo correspondiente. Lo valida, y si no es correcto, ofrece la posibilidad de cargarlo manualmente
 *
 * \param ePassenger* this recibe el puntero al elemento sobre el cual se va a realizar la operacion
 * \param float precio recibe por valor el dato que se validara como precio para setearlo en el campo correspondiente
 * \return int  retorna -1 si hubo un error en los parametros recibidos
 * 						0 si realizo la operacion correctamente
 *
 */
int Passenger_setPrecio(ePassenger* this,float precio)
{
	int retorno;
	int cargaManual;
	///int auxId;
	retorno =-1;

	if(this != NULL)
	{
		this->precio=precio;
		retorno=0;
		 if((precio<MIN_PRICE && precio!= INIT_PRICE) || precio>MAX_PRICE )
		 {
			 retorno = -2;
			 printf("\n[DEBUG SET PRICE] ***WARNING*** el precio ingresado esta fuera de los parametros esperados. Valor: %.2f debe ser mayor a %d y menor a %d\n", precio, MIN_PRICE, MAX_PRICE);
			 cargaManual= tp_continuar("Desea cargar manualmente? Y/N");
			if(cargaManual)
			{
				parser_getPriceToBuffer(&precio);
			}
		 }
	}
	return retorno;
}

/** \brief recibe una cadena, valida que corresponda al formato precio y lo carga en el campo correspondiente.
 * Lo valida, y si no es correcto, ofrece la posibilidad de cargarlo manualmente
 *
 * \param ePassenger* this recibe el puntero al elemento sobre el cual se va a realizar la operacion
 * \param char* priceStr recibe por referencia la cadena que se validara como precio para setearlo en el campo correspondiente
 * \return int  retorna -1 si hubo un error en los parametros recibidos
 * 						-2 si el dato seteado no pertenece al rango correspondiente
 * 						0 si realizo la operacion correctamente
 *
 */
int Passenger_setPriceStr(ePassenger* this,char* priceStr)
{
	int retorno;
	float auxPrecio;
	int cargaManual;

	retorno =-1;
	if(this != NULL && priceStr != NULL && validaciones_esNumeroFlotante(priceStr, strlen(priceStr)))
	{
		auxPrecio = atof(priceStr);
		this->precio=auxPrecio;
		retorno=0;
		if(auxPrecio < ID_MIN)
		{
			retorno = -2;
			printf("\n[DEBUG] ***WARNING*** el precio recibido esta fuera de los parametros esperados para un precio. Valor: %.2f\n", auxPrecio);
			cargaManual= tp_continuar("Desea cargar manualmente? Y/N");
			if(cargaManual)
			{
				parser_getPriceToBuffer(&auxPrecio);
			}
		}
	}
	return retorno;
}

/** \brief recibe un codigo de Vuelo y lo carga en el campo correspondiente. Lo valida, y si no es correcto, ofrece la posibilidad de cargarlo manualmente
 *
 * \param ePassenger* this recibe el puntero al elemento sobre el cual se va a realizar la operacion
 * \param char* codigoVuelo recibe la referencia de la cadena a la cual se validara como codigoVuelo para setearla en el campo correspondiente
 * \return int  retorna -1 si hubo un error en los parametros recibidos
 * 						0 si realizo la operacion correctamente
 *
 */
int Passenger_setCodigoVuelo(ePassenger* this,char* codigoVuelo)
{
	int retorno;
	int lenString;
	int cargaManual;

	lenString=strlen(codigoVuelo);
	retorno =-1;
	if(this != NULL && codigoVuelo != NULL )
	{
		strncpy(this->flyCode, codigoVuelo, lenString);
		retorno=0;
		if(!validaciones_EsCodigoTresLetrasYNumero(codigoVuelo, lenString) && strcmp(codigoVuelo,"-"))
		{
			retorno = -2;
			printf("\n[DEBUG SET FLYCODE] ***WARNING*** el codigo ingresado para %s %s id %d no es un codigo valido. Codigo %s debe contener 2 caracteres alfabeticos al comienzo\n", this->nombre, this->apellido, this->id, codigoVuelo);
			cargaManual= tp_continuar("Desea cargar manualmente? Y/N");
			if(cargaManual)
			{
				parser_getFlyCodeToBuffer(codigoVuelo, SIZE_STR);
			}
		}
	}
	return retorno;
}

/** \brief recibe un estado de Vuelo y lo carga en el campo correspondiente.
 *
 * \param ePassenger* this recibe el puntero al elemento sobre el cual se va a realizar la operacion
 * \param char* estadoVuelo recibe la referencia de la cadena
 * \return int  retorna -1 si hubo un error en los parametros recibidos
 * 						0 si realizo la operacion correctamente
 *
 */
int Passenger_setStatusFlight(ePassenger* this,char*estadoVueloStr)
{
	int retorno;
	int lenString;

	lenString=strlen(estadoVueloStr);
	retorno =-1;
	if(this != NULL && estadoVueloStr != NULL)
	{
		validaciones_eliminarUltimoEnter(estadoVueloStr, SIZE_STR);
		strncpy(this->estadoVuelo, estadoVueloStr, lenString);
		retorno=0;
	}

	return retorno;
}

/** \brief recibe un tipo de Pasajero y lo carga en el campo correspondiente.
 *
 * \param ePassenger* this recibe el puntero al elemento sobre el cual se va a realizar la operacion
 * \param char* tipoPasajero recibe la referencia de la cadena
 * \return int  retorna -1 si hubo un error en los parametros recibidos
 * 						0 si realizo la operacion correctamente
 *
 */
int Passenger_setTipoPasajero(ePassenger* this,char* tipoPasajero)
{
	int retorno;

	retorno =-1;
	if(this != NULL && tipoPasajero != NULL)
	{
		strcpy(this->tipoPasajero, tipoPasajero);
		retorno=0;
	}
	return retorno;
}

//--------------------------------- GETTERS ---------------------------------//
/** \brief recibe un pasajero y devuelve por referencia los datos obtenidos de sus campos
 *
 * \param int* id recibe un espacio de memoria donde alojar el contenido del campo ID
 * \param char* nombre recibe la referencia donde alojar la cadena correspondiente al campo nombre
 * \param char* apellido recibe la referencia donde alojar la cadena correspondiente al campo apellido
 * \param float* precio  recibe un espacio de memoria donde alojar el contenido del campo precio
 * \param char* codigoVuelo recibe la referencia donde alojar la cadena correspondiente al campo FlyCode
 * \param char* tipoPasajero recibe la referencia donde alojar la cadena correspondiente al campo Tipo Pasajero
 * \param char* estadoVuelo recibe la referencia donde alojar la cadena correspondiente al campo estado de Vuelo
 *
 * \return int  retorna -1 si hubo un error en los parametros recibidos
 * 						0 si realizo la operacion correctamente
 *
 */
int Passenger_getDatosDePasajero(ePassenger* this, int* id,char* nombre,char* apellido,float* precio, char* codigoVuelo, char* tipoPasajero,char* estadoVuelo)
{
	int retorno;

	retorno = -1;
	if(this!= NULL && id!= NULL && nombre != NULL && apellido != NULL && precio!= NULL && codigoVuelo != NULL && tipoPasajero != NULL &&  tipoPasajero != NULL)
	{
		retorno = 0;
		*id= Passenger_getId(this);
		Passenger_getNombre(this, nombre);
		Passenger_getApellido(this, apellido);
		*precio= Passenger_getPrice(this);
		Passenger_getCodigoVuelo(this, codigoVuelo);
		Passenger_getEstadoVuelo(this, estadoVuelo);
		Passenger_getTipoPasajero(this, tipoPasajero);
	}

	return retorno;
}

/** \brief analiza un elemento del tipo ePassenger y devuelve por referencia el dato alojado en el campo id
 *
 * \param ePassenger* this recibe el puntero al elemento sobre el cual se va a realizar la operacion
 * \return int  retorna -1 si hubo un error en los parametros recibidos
 * 						>0 si realizo la operacion correctamente (retorna el id correspondiente)
 *
 */
int Passenger_getId(ePassenger* this)
{
	int retorno;
	retorno =-1;
	if(this!= NULL)
	{
		retorno =this->id;
	}
	return retorno;
}

/** \brief analiza un elemento del tipo ePassenger y devuelve por referencia el dato alojado en el campo nombre
 *
 * \param ePassenger* this recibe el puntero al elemento sobre el cual se va a realizar la operacion
 * \param char* nombre recibe la referencia donde alojar el valor hallado
 * \return int  retorna -1 si hubo un error en los parametros recibidos
 * 						0 si realizo la operacion correctamente
 *
 */
int Passenger_getNombre(ePassenger* this,char* nombre)
{
	int retorno;
	retorno =-1;
	if(this!= NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		retorno =0;
	}
	return retorno;
}

/** \brief analiza un elemento del tipo ePassenger y devuelve por referencia el dato alojado en el campo nombre
 *
 * \param ePassenger* this recibe el puntero al elemento sobre el cual se va a realizar la operacion
 * \param char* apellido recibe la referencia donde alojar el valor hallado
 * \return int  retorna -1 si hubo un error en los parametros recibidos
 * 						0 si realizo la operacion correctamente
 *
 */
int Passenger_getApellido(ePassenger* this,char* apellido)
{
	int retorno;

	retorno =-1;
	if(this!= NULL && apellido != NULL)
	{
		strcpy(apellido, this->apellido);
		retorno =0;
	}
	return retorno;
}

/** \brief analiza un elemento del tipo ePassenger y devuelve por referencia el dato alojado en el campo codigo Vuelo
 *
 * \param ePassenger* this recibe el puntero al elemento sobre el cual se va a realizar la operacion
 * \param char* codigoVuelo recibe la referencia donde alojar el valor hallado
 * \return int  retorna -1 si hubo un error en los parametros recibidos
 * 						0 si realizo la operacion correctamente
 *
 */
int Passenger_getCodigoVuelo(ePassenger* this,char* codigoVuelo)
{
	int retorno;

	retorno =-1;
	if(this!= NULL && codigoVuelo != NULL)
	{
		strcpy(codigoVuelo, this->flyCode);
		retorno =0;
	}
	return retorno;
}

/** \brief analiza un elemento del tipo ePassenger y retorna el dato alojado en el campo precio
 *
 * \param ePassenger* this recibe el puntero al elemento sobre el cual se va a realizar la operacion
 * \return int  retorna -1 si hubo un error en los parametros recibidos
 * 						0 si realizo la operacion correctamente
 *
 */
float Passenger_getPrice(ePassenger* this)
{
	float retorno;
	retorno =-1;
	if(this!= NULL)
	{
		retorno =this->precio;
	}
	return retorno;
}

/** \brief analiza un elemento del tipo ePassenger y devuelve por referencia el dato alojado en el campo tipoPasajero
 *
 * \param ePassenger* this recibe el puntero al elemento sobre el cual se va a realizar la operacion
 * \param int* tipoPasajero recibe la referencia donde alojar el valor hallado
 * \return int  retorna -1 si hubo un error en los parametros recibidos
 * 						0 si realizo la operacion correctamente
 *
 */
int Passenger_getTipoPasajero(ePassenger* this,char* tipoPasajero)
{
	int retorno;
	retorno =-1;

	//int lenString;

	//lenString=strlen(tipoPasajero);
	retorno =-1;
	if(this!= NULL && tipoPasajero != NULL)
	{
		strcpy(tipoPasajero, this->tipoPasajero);//si uso el strNcpy me copia mal
		retorno =0;
	}
	return retorno;
}

/** \brief analiza un elemento del tipo ePassenger y devuelve por referencia el dato alojado en el campo tipoPasajero
 *
 * \param ePassenger* this recibe el puntero al elemento sobre el cual se va a realizar la operacion
 * \param int* tipoPasajero recibe la referencia donde alojar el valor hallado
 * \return int  retorna -1 si hubo un error en los parametros recibidos
 * 						0 si realizo la operacion correctamente
 *
 */
int Passenger_getEstadoVuelo(ePassenger* this,char* estadoVuelo)
{
	int retorno;
	retorno =-1;

	//int lenString;

	//lenString=strlen(tipoPasajero);
	retorno =-1;
	if(this!= NULL && estadoVuelo != NULL)
	{
		strcpy(estadoVuelo, this->estadoVuelo);//si uso el strNcpy me copia mal
		retorno =0;
	}
	return retorno;
}

//--------------------------------- SORT ---------------------------------//
/** \brief recibe dos elementos y los compara segun el campo id
 *
 * \param ePassenger* this recibe el puntero al elemento que se comparara
 * \param ePassenger* that recibe el puntero al elemento contra el cual se comparara
 * \return int retorna -1 si el primer elemento es menor que el segundo
 * 						0 si son iguales
 * 						1 si el primer elemento es mayor que el segundo
 *
 */
int Passenger_compareById(void* this, void* that)
{
	int comparacion;
	int id1;
	int id2;
	ePassenger* pPasajero1;
	ePassenger* pPasajero2;
	comparacion = 0;
	if(this != NULL && that != NULL)
	{
		pPasajero1 = (ePassenger*)this;
		pPasajero2 = (ePassenger*)that;

		id1= Passenger_getId(pPasajero1);
		id2= Passenger_getId(pPasajero2);
		if(id1 < id2)
		{
			comparacion = -1;
		}
		else
		{
			if(id1 > id2)
			{
				comparacion = 1;
			}
		}
	}
	return comparacion;
}

/** \brief recibe dos elementos y los compara segun el campo precio
 *
 * \param ePassenger* this recibe el puntero al elemento que se comparara
 * \param ePassenger* that recibe el puntero al elemento contra el cual se comparara
 * \return int retorna -1 si el primer elemento es menor que el segundo
 * 						0 si son iguales
 * 						1 si el primer elemento es mayor que el segundo
 *
 */
int Passenger_comparePrice(void* this, void* that)
{
	int comparacion;
	ePassenger* pPasajero1;
	ePassenger* pPasajero2;
	float precio1;
	float precio2;
	comparacion =-1;
	if(this != NULL && that != NULL)
	{
		pPasajero1 = (ePassenger*) this;
		pPasajero2 = (ePassenger*) that;

		precio1=Passenger_getPrice(pPasajero1);
		precio2=Passenger_getPrice(pPasajero2);

		if(precio1 < precio2)
		{
			comparacion = -1;
		}
		else
		{
			if(precio1 > precio2)
			{
				comparacion = 1;
			}
		}
	}
	return comparacion;
}

/** \brief recibe dos elementos y los compara segun el campo nombre
 *
 * \param ePassenger* this recibe el puntero al elemento que se comparara
 * \param ePassenger* that recibe el puntero al elemento contra el cual se comparara
 * \return int retorna -100 si hay un error en los parametros
 * 						<0 si el primer elemento es menor
 * 						0 si ambos son iguales
 * 						>0 si el segundo elemento es menor
 *
 */
int Passenger_compareByName(void* this, void* that)
{
	int retorno;
	char nombre1[SIZE_STR];
	char nombre2[SIZE_STR];
	ePassenger* pPasajero1;
	ePassenger* pPasajero2;
	retorno = -100;
	if(this != NULL && that != NULL)
	{
		pPasajero1 = (ePassenger*)this;
		pPasajero2 = (ePassenger*)that;

		Passenger_getNombre(pPasajero1, nombre1);
		Passenger_getNombre(pPasajero2, nombre2);

		retorno= strcmp(nombre1, nombre2);
	}
	return retorno;
}



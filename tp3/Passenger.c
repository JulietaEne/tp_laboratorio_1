/*
 * Passenger.c
 *
 *  Created on: 24 may. 2022
 *      Author: Julieta Nakasone
 */
#include "Passenger.h"
//#include "parser.h"

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

/** \brief Crea un pasajero en memoria dinamica seteando en sus campos ID NOMBRE TIPO PASAJERO los datos recibidos por parametro (modo texto)
 *
 * \param char* idStr recibe la referencia a la cadena correspondiente para el campo id
 * \param char* nombreStr recibe la referencia a la cadena correspondiente para el campo nombre
 * \param char* tipoPasajeroStr recibe la referencia a la cadena correspondiente para el campo tipo pasajero
 * \return ePassenger* retorna NULL si hubo un error al realizar la operacion
 * 					   		   *ePassenger si logro crear y setear a la variable del tipo estructura(retorna la direccion de memoria en donde se creo al pasajero)
 *
 */
ePassenger* Passenger_newParametrosString(char* idStr,char* nombreStr,char* tipoPasajeroStr)
{
	ePassenger* this = NULL;
	if(idStr != NULL && nombreStr != NULL && tipoPasajeroStr != NULL)
	{

		this = Passenger_new();
		if(this != NULL)
		{
			Passenger_setIdStr(this, idStr);
			Passenger_setNombre(this, nombreStr);
			//Passenger_setLastName(this, apellidoStr);
			//Passenger_setPrice(this, priceStr);
			Passenger_setTipoPasajero(this, tipoPasajeroStr);
			//Passenger_setStatusFlight(this, estadoVueloStr);
		}
	}
	return this;
}

/** \brief Crea un pasajero en memoria dinamica seteando en sus campos ID NOMBRE TIPO PASAJERO los datos recibidos por parametro (modo texto)
 *
 * \param char* idStr recibe la referencia a la cadena correspondiente para el campo id
 * \param char* nombreStr recibe la referencia a la cadena correspondiente para el campo nombre
 * \param char* tipoPasajeroStr recibe la referencia a la cadena correspondiente para el campo tipo pasajero
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
		//printf("PRECIO: %s\n", precioStr);
		if(this != NULL)
		{
			Passenger_setIdStr(this, idStr);
			Passenger_setNombre(this, nombreStr);
			Passenger_setLastName(this, apellidoStr);
			Passenger_setPrice(this, precioStr);
			Passenger_setCodigoVuelo(this, codigoVueloStr);
			Passenger_setTipoPasajero(this, tipoPasajeroStr);
			Passenger_setStatusFlight(this, estadoVueloStr);
		}
	}
	return this;
}

/** \brief Crea un pasajero en memoria dinamica seteando en sus campos ID NOMBRE TIPO PASAJERO los datos recibidos por parametro (modo texto)
 *
 * \param char* idStr recibe la referencia a la cadena correspondiente para el campo id
 * \param char* nombreStr recibe la referencia a la cadena correspondiente para el campo nombre
 * \param char* tipoPasajeroStr recibe la referencia a la cadena correspondiente para el campo tipo pasajero
 * \return ePassenger* retorna NULL si hubo un error al realizar la operacion
 * 					   		   *ePassenger si logro crear y setear a la variable del tipo estructura(retorna la direccion de memoria en donde se creo al pasajero)
 *
 */
ePassenger* Passenger_newParametros(int id,char* nombre,char* tipoPasajero)
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

			if( !Passenger_setId(this, id) &&
				!Passenger_setNombre(this, nombre) &&
				!Passenger_setTipoPasajero(this, tipoPasajero))
			{
			/*	Passenger_getApellido(this, apellido);
				Passenger_setCodigoVuelo(this, codigoVuelo);
				Passenger_setEstadoVuelo(this, estadoVuelo);*/
				cargaCorrecta = 1;
			}
			if(!cargaCorrecta)
			{
				this = NULL;
				printf("ERROR AL CARGAR EL DATO %d , %s, %s", id, nombre, tipoPasajero);
			}
		}
	}
	return this;
	/*ePassenger* this = NULL;
		if(nombre != NULL && tipoPasajero != NULL)
		{
			this = Passenger_new();
			if(this != NULL)
			{
				Passenger_setId(this, id);
				Passenger_setNombre(this, nombre);
				Passenger_setTipoPasajero(this, tipoPasajero);
			}
		}
		return this;*/
}

/** \brief Crea un pasajero en memoria dinamica seteando en sus campos ID NOMBRE TIPO PASAJERO los datos recibidos por parametro (modo texto)
 *
 * \param char* idStr recibe la referencia a la cadena correspondiente para el campo id
 * \param char* nombreStr recibe la referencia a la cadena correspondiente para el campo nombre
 * \param char* tipoPasajeroStr recibe la referencia a la cadena correspondiente para el campo tipo pasajero
 * \return ePassenger* retorna NULL si hubo un error al realizar la operacion
 * 					   		   *ePassenger si logro crear y setear a la variable del tipo estructura(retorna la direccion de memoria en donde se creo al pasajero)
 *
 */
ePassenger* Passenger_newParametrosAll(int id,char* nombre,char* apellido, float precio, char* codigoVuelo, char* tipoPasajero, char* estadoVuelo)
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
			printf("en new, id: %d ---------- ", id);
			Passenger_setId(this, id);
			Passenger_setNombre(this, nombre);
			Passenger_setTipoPasajero(this, tipoPasajero);
			Passenger_setApellido(this, apellido);
			Passenger_setCodigoVuelo(this, codigoVuelo);
			Passenger_setPrecio(this, precio);
			Passenger_setEstadoVuelo(this, estadoVuelo);

			/*	Passenger_getApellido(this, apellido);
				Passenger_setCodigoVuelo(this, codigoVuelo);
				Passenger_setEstadoVuelo(this, estadoVuelo);*/
				cargaCorrecta = 1;

			if(!cargaCorrecta)
			{
				this = NULL;
				printf("ERROR AL CARGAR EL DATO %d , %s, %s", id, nombre, tipoPasajero);
			}
		}
	}
	return this;
	/*ePassenger* this = NULL;
		if(nombre != NULL && tipoPasajero != NULL)
		{
			this = Passenger_new();
			if(this != NULL)
			{
				Passenger_setId(this, id);
				Passenger_setNombre(this, nombre);
				Passenger_setTipoPasajero(this, tipoPasajero);
			}
		}
		return this;*/
}

/** \brief recibe una lista para recorrerla
 *
 * \param ePassenger* this recibe el puntero al elemento sobre el cual se va a realizar la operacion
 * \param int* id recibe la referencia donde alojar el valor hallado
 * \return int  retorna -1 si hubo un error en los parametros recibidos
 * 						0 si realizo la operacion correctamente
 *
 */
int Passenger_getDatosDePasajero(ePassenger* this, int* id, char* nombre, char* typePasajero)
{
	int retorno;


	retorno = -1;
	if(id!= NULL && nombre != NULL && typePasajero != NULL && this != NULL)
	{
		retorno = 0;
		*id= Passenger_getId(this/*, &id*/);
		//printf("[GETTER ID] this.id: %d -- id: %d\n", this->id,*id);
		Passenger_getNombre(this, nombre);
		//printf("[GETTER NAME] this.name: %s -- name: %s\n", this->nombre,nombre);
		Passenger_getTipoPasajero(this, typePasajero);
		//printf("[GETTER TYPE] this.tipo: %s -- typePass: %s\n", this->tipoPasajero,typePasajero);
	}

	return retorno;
}

/** \brief elimina pasajero recibido por parametros
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

		//preguntar si quiero mostrar todos los pasajeros / si dice que si, muestra la lista
		printf("pasajero id: %d - nombre: %s\n", this->id, this->nombre);
		confirmar=tp_continuar("confirma la baja del pasajero? (Y/N)");
		if(confirmar)
		{
			free(this);
			retorno=0;// si se borra correctamente
			//printf("\n El pasajero %d - %s ha sido eliminado exitosamente\n", this->id, this->nombre);
		}
	}
	return retorno;
}

/** \brief inicializa los campos del pasajero recibido por parametro
 *
 * \param ePassenger* this recibe el puntero al elemento sobre el cual se va a realizar la operacion

 * \return int  retorna -1 si hubo un error en los parametros recibidos
 * 						0 si elimino correctamente
 *
 */
int Passenger_initPasajero(ePassenger* this)
{
	int retorno;
	retorno=-1;
	if(this != NULL)
	{
		Passenger_setCodigoVuelo(this, "-");
		Passenger_setNombre(this, "-");
		Passenger_setLastName(this, "-");
		Passenger_setEstadoVuelo(this, "-");
		Passenger_setPrecio(this, INIT_PRICE);
		Passenger_setId(this, ID_INIT);
		retorno =0;
	}
	return retorno;
}

/** \brief inicializa los campos del pasajero recibido por parametro
 *
 * \param ePassenger* this recibe el puntero al elemento sobre el cual se va a realizar la operacion

 * \return int  retorna -1 si hubo un error en los parametros recibidos
 * 						0 si elimino correctamente
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
void Passenger_printEncabezado()
{
	printf("ID\tNOMBRE\t\tAPELLIDO\tPRECIO\t\tCODIGO VUELO\tTIPO PASAJERO\tESTADO VUELO\n");
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
int Passenger_setId(ePassenger* this,int id, LinkedList* pArrayListPassenger)
{
	int retorno;
	int auxId;
	int mantenerIdArchivo;
	retorno =-1;

	if(this != NULL)
	{
		if(!parser_controlListaPasajeros(pArrayListPassenger))
		{
			mantenerIdArchivo=tp_continuar("Aun no hay datos cargados en el sistema. Desea mantener el codigo ID del archivo en la carga? Y/N");
			if(!mantenerIdArchivo)
			{
				auxId = ID_MIN;
				parser_saveIntIntoFile(auxId);
			}
			else
			{
				auxId = id;
			}

		}
		else
		{
			auxId = parser_analizarId(auxId);//si hay archivos cargados,si o si tengo que ser correlativa al id del archivo
		}
		this->id=auxId;
		retorno=0;

		if(/*auxId > ID_MAX ||*/ auxId < ID_MIN)
		{
			retorno = -2;
			printf("\n[DEBUG] ***WARNING*** el id recibido esta fuera de los parametros esperados para un id. Valor: %d - maximoId: %d\n", auxId, ID_MAX);
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
int Passenger_setIdStr(ePassenger* this,char* idStr, LinkedList* pArrayListPassenger)
{
	int retorno;
	int auxId;
	int mantenerIdArchivo;
	//int auxIdControl;
	retorno =-1;
	//printf("3-1-1 set id\n");
	if(this != NULL && idStr != NULL && !validaciones_esNumeroInt(idStr, strlen(idStr)))
	{
		if(!parser_controlListaPasajeros(pArrayListPassenger))
		{
			mantenerIdArchivo=tp_continuar("Aun no hay datos cargados en el sistema. Desea mantener el codigo ID del archivo en la carga? Y/N");
			if(!mantenerIdArchivo)
			{
				auxId = ID_MIN;
				parser_saveIntIntoFile(auxId);
			}
			else
			{
				auxId = atoi(idStr);
			}

		}
		else
		{
			auxId = parser_analizarId(auxId);
		}
		this->id=auxId;
		retorno=0;
		if(/*auxId > ID_MAX ||*/ auxId < ID_MIN)
		{
			retorno = -2;
			printf("\n[DEBUG] ***WARNING*** el id recibido esta fuera de los parametros esperados para un id. Valor: %d - maximoId: %d\n", auxId, ID_MAX);
		}
	}
	return retorno;
}

/** \brief analiza un elemento del tipo ePassenger y devuelve por referencia el dato alojado en el campo id
 *
 * \param ePassenger* this recibe el puntero al elemento sobre el cual se va a realizar la operacion
 * \param int* id recibe la referencia donde alojar el valor hallado
 * \return int  retorna -1 si hubo un error en los parametros recibidos
 * 						0 si realizo la operacion correctamente
 *
 */
int Passenger_getId(ePassenger* this/*,int* id*/)
{
	int retorno;
	retorno =-1;
	if(this!= NULL /*&& id != NULL*/)
	{

		retorno =this->id;
	}
	return retorno;
}

/** \brief valida el valor recibido por parametro y lo setea en this, dentro de su campo nombre
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
	//printf("puntero nombre: %s", nombre);
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
	//int lenString;

	//lenString=strlen(this->nombre);
	//printf("****name previo: %s - len: %d - campo nombre: %s\n", nombre, lenString, this->nombre);
	retorno =-1;
	if(this!= NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre); //aca con strNcpy me copia muchas cosas de mas y no se por que :(
		retorno =0;
	}
	return retorno;
}

int Passenger_setApellido(ePassenger* this,char* apellido)
{
	int retorno;
	int lenString;

	lenString=strlen(apellido);
	retorno =-1;
	//printf("puntero nombre: %s", nombre);
	if(this != NULL && apellido != NULL && !validaciones_esNombre(apellido, lenString))
	{
		//printf("**********estamos en nombre\n");
		strncpy(this->apellido, apellido, lenString);
		retorno=0;
	}

	return retorno;
}

int Passenger_setPrecio(ePassenger* this,float precio)
{
	int retorno;
	///int auxId;
	retorno =-1;

	if(this != NULL)
	{
		this->precio=precio;
		//printf("*********\nthis.id %d -- id: %d\n", this->id, id);
		retorno=0;
		 if((precio<MIN_PRICE && precio!= INIT_PRICE) || precio>MAX_PRICE )
		 {
			 retorno = -2;
			 printf("\n[DEBUG SET PRICE] ***WARNING*** el precio ingresado esta fuera de los parametros esperados. Valor: %.2f debe ser mayor a %d y menor a %d\n", precio, MIN_PRICE, MAX_PRICE);
			 parser_getPriceToBuffer(&precio);
		 }
	}
	return retorno;
}

int Passenger_setCodigoVuelo(ePassenger* this,char* codigoVuelo)
{
	int retorno;
	int lenString;
	int cargaManual;

	lenString=strlen(codigoVuelo);
	retorno =-1;
	if(this != NULL && codigoVuelo != NULL )
	{
		//printf("**********estamos en nombre\n");
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

int Passenger_setEstadoVuelo(ePassenger* this,char* estadoVuelo)
{
	int retorno;
	int lenString;

	lenString=strlen(estadoVuelo);
	retorno =-1;
	//printf("puntero nombre: %s", nombre);
	if(this != NULL && estadoVuelo != NULL )
	{
		//printf("**********estamos en nombre\n");
		strncpy(this->estadoVuelo, estadoVuelo, lenString);
		retorno=0;
	}

	return retorno;
}

/** \brief parsea el valor recibido por parametro y lo setea en this, dentro de su campo tipoPasajero
 *
 * \param ePassenger* this recibe el puntero al elemento sobre el cual se va a realizar la operacion
 * \param char* tipoPasajero recibe la referencia de la cadena a la cual se validara como Tipo Pasajero para setearla en el campo correspondiente
 * \return int  retorna -1 si hubo un error en los parametros recibidos
 * 						-2 si el valor recibido como tipo Pasajero no corresponde al rango esperado
 * 						0 si realizo la operacion correctamente
 *
 */
int Passenger_setTipoPasajero(ePassenger* this,char* tipoPasajero)
{
	int retorno;
	//int lenString;
	retorno =-1;
	//lenString = sizeof(tipoPasajero);
	//printf("*********\nauxTipoPasajero: %s\n", tipoPasajero);
	if(this != NULL && tipoPasajero != NULL)
	{
		strcpy(this->tipoPasajero, tipoPasajero);//aca uso strNcpy y tengo error porq se copia menos de lo que debe. Pero sin eso, se copian muchas letras al final :(
		//printf("tipoPasajero en estructura: %s\n*************\n",this->tipoPasajero);
		retorno=0;
	}
	return retorno;
}


/** \brief valida el valor recibido por parametro y lo setea en this, dentro de su campo tipoPasajero
 *
 * \param ePassenger* this recibe el puntero al elemento sobre el cual se va a realizar la operacion
 * \param char* tipoPasajero recibe la referencia de la cadena a la cual se validara como Tipo Pasajero para setearla en el campo correspondiente
 * \return int  retorna -1 si hubo un error en los parametros recibidos
 * 						-2 si el valor recibido como tipo Pasajero no corresponde al rango esperado
 * 						0 si realizo la operacion correctamente
 *
int Passenger_setTipoPasajero(ePassenger* this,int tipoPasajero)
{
	int retorno;
	//int auxTipoPasajero;
	retorno =-1;
	if(this != NULL)
	{
		//auxTipoPasajero = atoi(tipoPasajero);
		this->tipoPasajero=tipoPasajero;
		retorno=0;
		if(tipoPasajero > PASS_TYPE_MAX || tipoPasajero < PASS_TYPE_MIN)
		{
			retorno = -2;
			printf("\n[DEBUG] ***WARNING*** el valor recibido esta fuera de los parametros esperados para un TipoPasajero. Valor: %d\n", tipoPasajero);
		}
	}
	return retorno;
}*/

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


int Passenger_setPrice(ePassenger* this,char* priceStr)
{
	int retorno;
	float auxPrecio;
	int cargaManual;

	retorno =-1;
	//printf("3-1-1 set id\n");
	if(this != NULL && priceStr != NULL && validaciones_esNumeroFlotante(priceStr, strlen(priceStr)))
	{
		auxPrecio = atof(priceStr);
		this->precio=auxPrecio;
		retorno=0;
		if(/*auxId > ID_MAX ||*/ auxPrecio < ID_MIN)
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


int Passenger_setStatusFlight(ePassenger* this,char*estadoVueloStr)
{
	int retorno;
	int lenString;

	lenString=strlen(estadoVueloStr);
	retorno =-1;
	//printf("puntero nombre: %s", nombre);
	if(this != NULL && estadoVueloStr != NULL)
	{
		 validaciones_eliminarUltimoEnter(estadoVueloStr, SIZE_STR);
		//printf("**********estamos en nombre\n");
		strncpy(this->estadoVuelo, estadoVueloStr, lenString);
		retorno=0;
	}

	return retorno;
}

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

int Passenger_comparePassengersByName(ePassenger* this, ePassenger* that)
{
	int retorno;
	char nombre1[SIZE_STR];
	char nombre2[SIZE_STR];
	retorno = -1;
	if(this != NULL && that != NULL)
	{

		Passenger_getNombre(this, nombre1);
		Passenger_getNombre(that, nombre2);

		arrayChar_convertirStringMayuscula(nombre1, strlen(nombre1));
		arrayChar_convertirStringMayuscula(nombre2, strlen(nombre2));
		//printf("estamos en passenger compare\n");
		//printf("nombre1: %s - nombre2: %s\n", nombre1, nombre2);
		retorno= strcmp(nombre1, nombre2);
		//printf("retorno : %d", retorno);
	}
	return retorno;
}


/*
 * Passenger.c
 *
 *  Created on: 24 may. 2022
 *      Author: Julieta Nakasone
 */
#include "Passenger.h"

/** \brief Reserva espacio en heap para una variable del tipo ePassenger
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
			Passenger_setNombreStr(this, nombreStr);
			Passenger_setTipoPasajeroStr(this, tipoPasajeroStr);
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
ePassenger* Passenger_newParametros(int* id,char* nombre,int* tipoPasajero)
{
	ePassenger* this = NULL;
	if(id != NULL && nombre != NULL && tipoPasajero != NULL)
	{
		this = Passenger_new();
		if(this != NULL)
		{
			Passenger_setId(this, id);
			Passenger_setNombre(this, nombre);
			Passenger_setTipoPasajero(this, tipoPasajero);
		}
	}
	return this;
}

/** \brief recibe una lista para recorrerla
 *
 * \param ePassenger* this recibe el puntero al elemento sobre el cual se va a realizar la operacion
 * \param int* id recibe la referencia donde alojar el valor hallado
 * \return int  retorna -1 si hubo un error en los parametros recibidos
 * 						0 si realizo la operacion correctamente
 *
 */
int Passenger_getDatosDePasajero(ePassenger* this, int* id, char* nombre, int* typePasajero)
{
	int retorno;


	retorno = -1;
	if(id!= NULL && nombre != NULL && typePasajero != NULL && this != NULL)
	{
		retorno = 0;
		Passenger_getId(this, id);
		Passenger_getNombre(this, nombre);
		Passenger_getTipoPasajero(this, typePasajero);
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
int Passenger_setId(ePassenger* this,int id);
{
	int retorno;
	int aux;
	retorno =-1;

	if(this != NULL && id != NULL && validaciones_esNumeroInt(idStr, strlen(idStr)))
	{
		auxId = atoi(idStr);
		 this->id=auxId;
		 retorno=0;
		 if(/*auxId > ID_MAX ||*/ auxId < ID_MIN)
		 {
			 retorno = -2;
			 printf("\n[DEBUG] ***WARNING*** el id recibido esta fuera de los parametros esperados para un id. Valor: %d\n", auxId);
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
	if(this != NULL && idStr != NULL && validaciones_esNumeroInt(idStr, strlen(idStr)))
	{
		auxId = atoi(idStr);
		this->id=auxId;
		retorno=0;
		if(/*auxId > ID_MAX ||*/ auxId < ID_MIN)
		{
			retorno = -2;
			printf("\n[DEBUG] ***WARNING*** el id recibido esta fuera de los parametros esperados para un id. Valor: %d\n", auxId);
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
int Passenger_getId(ePassenger* this,int* id)
{
	int retorno;
	retorno =-1;
	if(this!= NULL && id != NULL)
	{
		this->id= *id;
		retorno =0;
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
int Passenger_setNombreStr(ePassenger* this,char* nombre)
{
	int retorno;
	int lenString;

	lenString=strlen(nombre);
	retorno =-1;
	if(this != NULL && nombre != NULL && validaciones_esNombre(nombre, lenString))
	{
		strncpy(this->nombre, nombre, lenString);
		retorno=0;
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
	int lenString;

	lenString=strlen(this->nombre);
	retorno =-1;
	if(this!= NULL && nombre != NULL)
	{
		strncpy(this->nombre, nombre, lenString);
		retorno =0;
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
int Passenger_setTipoPasajeroStr(ePassenger* this,char* tipoPasajero)
{
	int retorno;
	int auxTipoPasajero;
	retorno =-1;
	if(this != NULL && tipoPasajero != NULL && validaciones_esNumeroInt(tipoPasajero, strlen(tipoPasajero)))
	{
		auxTipoPasajero = atoi(tipoPasajero);
		this->tipoPasajero=auxTipoPasajero;
		retorno=0;
		if(auxTipoPasajero > PASS_TYPE_MAX || auxTipoPasajero < PASS_TYPE_MIN)
		{
			retorno = -2;
			printf("\n[DEBUG] ***WARNING*** el valor recibido esta fuera de los parametros esperados para un TipoPasajero. Valor: %d\n", auxTipoPasajero);
		}
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
int Passenger_getTipoPasajero(ePassenger* this,int* tipoPasajero)
{
	int retorno;
	retorno =-1;
	if(this!= NULL && tipoPasajero != NULL)
	{
		this->tipoPasajero= *tipoPasajero;
		retorno =0;
	}
	return retorno;
}

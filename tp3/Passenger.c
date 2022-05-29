/*
 * Passenger.c
 *
 *  Created on: 24 may. 2022
 *      Author: Julieta Nakasone
 */
#include "Passenger.h"


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
			Passenger_setTipoPasajero(this, tipoPasajeroStr);
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





/** \brief parsea el valor recibido por parametro y lo setea en this, dentro de su campo id
 *
 * \param ePassenger* this recibe el puntero al elemento sobre el cual se va a realizar la operacion
 * \param char* idStr recibe la referencia de la cadena a la cual se validara como id para setearla en el campo correspondiente
 * \return int  retorna -1 si hubo un error en los parametros recibidos
 * 						-2 si el valor recibido como id no corresponde al rango esperado
 * 						0 si realizo la operacion correctamente
 *
 */
int Passenger_setId(ePassenger* this,int id)
{
	int retorno;
	///int auxId;
	retorno =-1;

	if(this != NULL)
	{
		this->id=id;
		printf("*********\nthis.id %d -- id: %d\n", this->id, id);
		retorno=0;
		 if(/*auxId > ID_MAX ||*/ id <ID_MIN)
		 {
			 retorno = -2;
			 printf("\n[DEBUG SET ID] ***WARNING*** el id recibido esta fuera de los parametros esperados para un id. Valor: %d<%d\n", id, ID_MIN);
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
	//printf("3-1-1 set id\n");
	if(this != NULL && idStr != NULL && !validaciones_esNumeroInt(idStr, strlen(idStr)))
	{
		//if()
		auxId = atoi(idStr);
		this->id=auxId;
		//printf("3-1-1 ****setId id-> %d --- this.id->%d\n\n", auxId, this->id);
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

	lenString=strlen(nombre);
	retorno =-1;
	//printf("puntero nombre: %s", nombre);
	if(this != NULL && nombre != NULL && !validaciones_esNombre(nombre, lenString))
	{
		//printf("**********estamos en nombre\n");
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


#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"



/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param pFile FILE* recibe el puntero al archivo sobre el cual realizara la operacion
 * \param pArrayListPassenger LinkedList* recibe la lista donde alojara los elementos parseados
 * \return int retorna -1 si no pudo operar.
 * 						0 si no leyo
 * 						>0 si leyo (retorna la cantidad de lecturas que hizo)
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno;

	ePassenger* pAuxPasajero=NULL;
	char auxId[SIZE_INT];
	char auxNombre[SIZE_STR];
	char auxApellido[SIZE_STR];
	char auxPrice[SIZE_STR];
	char auxFlyCode[SIZE_STR];
	char auxTipoPasajero[SIZE_STR];
	char auxStatusFlight[SIZE_STR];
	int i;

	retorno = -1;
	i=0;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		retorno =0;
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",auxId, auxNombre, auxApellido, auxPrice, auxFlyCode, auxTipoPasajero, auxStatusFlight);
		while(!feof(pFile))
		{
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",auxId, auxNombre, auxApellido, auxPrice, auxFlyCode, auxTipoPasajero, auxStatusFlight);
			//pAuxPasajero = Passenger_newParametrosString(auxId, auxNombre, auxTipoPasajero);
			pAuxPasajero = Passenger_newParametrosStringAll(auxId, auxNombre, auxApellido, auxPrice, auxFlyCode, auxTipoPasajero, auxStatusFlight);//acá ya tendría un pasajero en la lista de punteros
			i++;
			if(pAuxPasajero != NULL)
			{
				ll_add(pArrayListPassenger, (ePassenger*)pAuxPasajero);//guarda en la lista linkedList cada elemento
			}
			else
			{
				break;
			}
		}
		retorno = i;
		//printf("se pudo leer hasta la linea %d",i);
	}
    return retorno;
}

/** \brief Parsea los datos de los pasajeros desde el archivo data.bin (modo binario).
 *
 * \param pFile FILE* recibe el puntero al archivo sobre el cual realizara la operacion
 * \param pArrayListPassenger LinkedList* recibe la lista donde alojara los elementos parseados
 int retorna -1 si no pudo operar.
 * 						0 si no leyo
 * 						>0 si leyo (retorna la cantidad de lecturas que hizo)
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	ePassenger unPasajero;
	ePassenger* pAuxPasajero;
	int retorno;
	int lectura;

	retorno = -1;
	if(pFile!= NULL && pArrayListPassenger != NULL)
	{
		retorno =0;
		do{
			//printf("entramos al do OK\n");

			lectura=fread(&unPasajero, sizeof(ePassenger), 1, pFile);
			//printf("lectura: %d", lectura);
			pAuxPasajero = Passenger_newParametros(unPasajero.id, unPasajero.nombre, unPasajero.tipoPasajero);
			if(pAuxPasajero != NULL)
			{
				//printf("se cargó en lista");
				ll_add(pArrayListPassenger, (ePassenger*)pAuxPasajero);
				printf("%d - %s - %s\n", pAuxPasajero->id, pAuxPasajero->nombre, pAuxPasajero->tipoPasajero);
				retorno ++;
			}
			else
			{
				printf("ha habido un error en la lectura de los datos del archivo.\n");
				break;
			}

			/*printf("%d -- %s -- %s\n",
					pAuxPasajero->id,
					pAuxPasajero->nombre,
					pAuxPasajero->tipoPasajero);*/

		}while(lectura!= 0);
	}
	return retorno;
}


/** \brief Transcribe al archivo binario los datos alojados en memoria
 *
 * \param FILE* pFile recibe el puntero al archivo sobre el cual realizara la operacion
 * \param pArrayListPassenger LinkedList* recibe la lista donde alojara los elementos parseados
 * \return int retorno -1 si hubo un error en los parametros
 *						0 si la lista de la cual se copia los datos no contiene datos
 *						>0 si logro realizar el pasaje (retorna la cantidad de datos tipo ePassenger* pudo pasar)
 *
 */
int parser_BinaryFromPassenger(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno;
	int lenPArrayListaPassenger;
	int i;
	ePassenger* this=NULL;
	//int auxId;
	//char auxNombre[SIZE_STR];
	//int auxTypePassenger;

	retorno = -1;
	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		retorno =0;
		lenPArrayListaPassenger = ll_len(pArrayListPassenger);
		if(lenPArrayListaPassenger >0)
		{
			for(i=0; i<lenPArrayListaPassenger; i++)
			{
				this = ll_get(pArrayListPassenger, i);//tengo que obtener los datos alojados en cada puntero de la lista
				fwrite(this, sizeof(ePassenger), 1,pFile);
				retorno ++;
			}
		}
		else
		{
			printf("\n[DEBUG] ERROR la lista ingresada no contiene elementos\n");
		}
	}
	//printf("retorno binario desde archivo --> %d", retorno);
	return retorno;
}

/** \brief Transcribe al archivo .csv los datos alojados en memoria
 *
 * \param FILE* pFile recibe el puntero al archivo sobre el cual realizara la operacion
 * \param pArrayListPassenger LinkedList* recibe la lista donde alojara los elementos parseados
 * \return int retorno -1 si hubo un error en los parametros
 *						0 si la lista de la cual se copia los datos no contiene datos
 *						>0 si logro realizar el pasaje (retorna la cantidad de datos tipo ePassenger* pudo pasar)
 *
 */
int parser_TextFromPassenger(FILE* pFile, LinkedList* pArrayListPassenger)
{
	int retorno;
	int lenPArray;
	ePassenger* this;
	int i;
	int auxId;
	char auxNombre[SIZE_STR];
	char auxTipoPasajero[SIZE_STR];

	retorno = -1;

	if(pFile!= NULL && pArrayListPassenger != NULL)
	{
		retorno = 0;
		lenPArray = ll_len(pArrayListPassenger);
		if(lenPArray >0)
		{
			for(i=0; i<lenPArray; i++)
			{
				this=ll_get(pArrayListPassenger, i);
				Passenger_getDatosDePasajero(this, &auxId, auxNombre, auxTipoPasajero);
				//printf("%d) %d - %s - %s\n", i, auxId, auxNombre, auxTipoPasajero);
				fprintf(pFile, "%d,%s,%s\n", auxId, auxNombre, auxTipoPasajero);
				retorno++;
			}
		}
		else
		{
			printf("\n[DEBUG] ERROR la lista ingresada no contiene elementos\n");
		}
	}
	return retorno;
}

/** \brief recibe por teclado los datos de un nuevo pasajero, crea un nuevo pasajero en memoria con los datos y si son correctos, lo agrega a la lista de pasajeros
 *
 * \param pArrayListPassenger LinkedList* recibe la lista donde alojara los elementos parseados
 * \return int retorno -1 si hubo un error en los parametros
 *					   -2 si no pudo crear el pasajero en memoria
 *						0 si opero correctamente
 *
 */
int parser_passengerFromBuffer(LinkedList* pArrayListPassenger)
{
	int retorno;
	int auxId=1099;
	char auxNombre[SIZE_STR];
	char auxApellido[SIZE_STR];
	float auxPrice;
	char auxCodigoVuelo[SIZE_STR];
	char auxTipoPass[SIZE_STR];
	char auxEstadoVuelo[SIZE_STR];
	ePassenger* pAuxPasajero;
	int contador;
	retorno = -1;
	contador =0;
	if(pArrayListPassenger != NULL)
	{
		retorno = -2;
		do//mientras que los datos no estén correctamente cargados, vuelvo a pedir datos
		{
			parser_getIdToBuffer(&auxId, pArrayListPassenger);// NO SE COMO HACER QUE ANDE :(
			parser_getNameToBuffer(auxNombre, SIZE_STR);
			parser_getLastNameToBuffer(auxApellido, SIZE_STR);
			parser_getPriceToBuffer(&auxPrice);
			parser_getFlyCodeToBuffer(auxCodigoVuelo, SIZE_STR);
			parser_getTypePassToBuffer(auxTipoPass, SIZE_STR);
			parser_getStatusFlightToBuffer(auxEstadoVuelo, SIZE_STR);
			//voy a pedir los datos que el usuario quiere cargar.
			//pAuxPasajero=Passenger_newParametros(auxId, auxNombre, auxTipoPass);//voy a crear un nuevo pasajero
			pAuxPasajero=Passenger_newParametrosAll(auxId, auxNombre, auxApellido, auxPrice, auxCodigoVuelo, auxTipoPass, auxEstadoVuelo);
			//int id,char* nombre,char* apellido, float precio, char* codigoVuelo, char* tipoPasajero, char* estadoVuelo
			if(pAuxPasajero!= NULL)
			{
				ll_add(pArrayListPassenger, (ePassenger*)pAuxPasajero);
				retorno=0;
			}
			contador++;
		}while(pAuxPasajero==NULL /*|| contador!=5*/);
	}
	return retorno;
}


int parser_getNameToBuffer(char* name, int lenName)
{
	int retorno;
	retorno =-1;
	if(name != NULL && lenName>0)
	{
		utn_ingresarAlfabetica(name, lenName, "Nombre de pasajero: ", "Ingrese un dato valido", REINTENTOS);
		retorno=0;
	}
	return retorno;
}

int parser_getLastNameToBuffer(char* lastName, int lenLastName)
{
	int retorno;
	retorno =-1;
	if(lastName != NULL && lenLastName>0)
	{
		utn_ingresarAlfabetica(lastName, lenLastName, "Apellido de pasajero: ", "Ingrese un dato valido", REINTENTOS);
		retorno=0;
	}
	return retorno;
}


int parser_getPriceToBuffer(float* price)
{
	int retorno;
	float auxPrice;
	retorno =-1;
	if(price != NULL)
	{
		utn_GetNumeroFloat(&auxPrice, "Ingrese precio de vuelo: $", "ingrese un dato valido", MIN_PRICE, MAX_PRICE, REINTENTOS);
		*price = auxPrice;
		retorno=0;
	}
	return retorno;
}

int parser_getFlyCodeToBuffer(char* flyCode, int lenFlyCode)
{
	int retorno;
	retorno =-1;
	if(flyCode != NULL && lenFlyCode>0)
	{
		utn_getAlfaNumerica(flyCode, lenFlyCode,  "Codigo de vuelo: ", "Ingrese un dato valido", REINTENTOS);
		retorno=0;
	}
	return retorno;
}

int parser_getStatusFlightToBuffer(char* statusFlight, int lenStatusFlight)
{
	int retorno;
	retorno =-1;
	if(statusFlight != NULL && lenStatusFlight>0)
	{
		utn_ingresarAlfabetica(statusFlight, lenStatusFlight, "Estado del vuelo: ", "Ingrese un dato valido", REINTENTOS);
		retorno=0;
	}
	return retorno;
}

int parser_getIdToBuffer(int* id, LinkedList* pArrayListPassenger)
{
	int retorno;
	int auxId;
	retorno =-1;
	if(id != NULL)
	{
		//voy a buscar el id mas alto en los datos dentro de mi array de punteros
		auxId = controller_findLastIdValue(pArrayListPassenger);
		if(auxId >0)
		{
			*id = auxId+1;
		}
		else
		{
			printf("[ERROR ID]ha habido un error en la lectura de los datos del archivo\n");
		}
		retorno=0;
	}
	return retorno;
}

int parser_getTypePassToBuffer(char* typePass, int lenName)
{
	int retorno;
	retorno =-1;
	if(typePass != NULL && lenName >0)
	{
		utn_ingresarAlfabetica(typePass, lenName, "ingrese tipo de pasajero (FirstClass,ExecutiveClass,EconomyClass)", "ingrese un dato valido", REINTENTOS);
		retorno=0;
	}
	return retorno;
}


/** \brief se encarga de pedir el id del pasajero a editar, e interactuar con el usuario para efectuar el cambio del dato indicado
 *
 * \param pArrayListPassenger LinkedList* recibe la lista donde alojara los elementos parseados
 * \return int retorno -1 si hubo un error en los parametros
 *					   -2 si no pudo crear el pasajero en memoria
 *						0 si opero correctamente
 *
 */
int parser_passengerToEdit(LinkedList* pArrayListPassenger)
{
	int idSolicitado;
	ePassenger* pAuxPassenger=NULL;
	//char auxNombre[SIZE_STR];
	int indexHallado;
	int retorno;
	retorno = -1;
	if(pArrayListPassenger != NULL)
	{
		pAuxPassenger=controller_findIndexById(pArrayListPassenger, &idSolicitado, &indexHallado);//OK YO CREO QUE DEBERIA IR EN PARSER si encuentra igualdad, me decuelve el puntero que encapsula ese id
		if(pAuxPassenger != NULL)
		 {
			controller_chooseCampToEdit(pAuxPassenger, idSolicitado);//yo creo que este tendria que ir en passenger
			printf("editado: %s", pAuxPassenger->nombre);
		 }
		else
		{
			retorno=-2;
			//printf("no se ha encontrado coincidencias con el valor ingresado\n");
		}
		retorno=0;
	}
    return retorno;
}

/** \brief se encarga de pedir el id del pasajero a eliminar, e interactuar con el usuario para efectuar la baja
 *
 * \param pArrayListPassenger LinkedList* recibe la lista donde alojara los elementos parseados
 * \return int retorno -1 si hubo un error en los parametros
 *					   -2 si no encontro el id solicitado
 *					   -3 si no se realizo el delet
 *						0 si opero correctamente
 *
 */
int parser_passengerToDelete(LinkedList* pArrayListPassenger)
{
	int retorno;
	int idSolicitado;
	int indexHallado;
	ePassenger* pAuxPassenger;

	retorno=1;

	if(pArrayListPassenger!= NULL)
	{
		retorno =2;
		pAuxPassenger=controller_findIndexById(pArrayListPassenger, &idSolicitado, &indexHallado);
		if(pAuxPassenger!= NULL)
		{
			retorno=0;
			if(passenger_delete(pAuxPassenger)==-2)
			{
				retorno =-3;
			}
			ll_remove(pArrayListPassenger, indexHallado);
		}
	}
	return retorno;
}


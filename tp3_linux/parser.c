#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

#define SIZE_STR 51
#define SIZE_INT 6

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
	char auxPrice[SIZE_INT];
	char auxTipoPasajero[SIZE_STR];
	char auxStatusFlight[SIZE_STR];
	int i;

	retorno = -1;
	i=0;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		retorno =0;
		//lectura fantasma
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",auxId, auxNombre, auxApellido, auxPrice, auxTipoPasajero, auxStatusFlight);

		//guarda los datos y parsea el ID, NOMBRE, TIPO PASAJERO
		while(!feof(pFile))
		{
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",auxId, auxNombre, auxApellido, auxPrice, auxTipoPasajero, auxStatusFlight);
			pAuxPasajero = Passenger_newParametros(auxId, auxNombre, auxTipoPasajero);//acá ya tendría un pasajero en la lista de punteros
			if(pAuxPasajero != NULL)
			{
				ll_add(pArrayListPassenger, pAuxPasajero);//guarda en la lista linkedList cada elemento
			}
			i++;
		}
		retorno = i;
	}
    return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno;
	int lectura;
	ePassenger* pAuxPasajero=NULL;
	int auxId;
	char auxNombre[SIZE_STR];
	int auxTipoPasajero;

	lectura = 1;
	do{
		lectura = fread(&pAuxPasajero, sizeof(ePassenger),1, pFile);
		if(lectura==1)
		{
			pAuxPasajero = Passenger_newParametros(auxId, auxNombre, auxTipoPasajero);
		}
	}while(lectura);

	return retorno;
}


/** \brief
 *
 * \param FILE* pFile recibe el puntero al archivo sobre el cual realizara la operacion
 * \param pArrayListPassenger LinkedList* recibe la lista donde alojara los elementos parseados
 * \return int
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
				//Passenger_getDatosDePasajero(this, &auxId, auxNombre, &auxTypePassenger);//los guardo en una variable aux
				//printf("%d) %d - %s - %d\n", i, auxId, auxNombre, auxTypePassenger);
				//fprintf(pFile, "%d,%s,%d\n", auxId, auxNombre, auxTypePassenger);

				//fwrite(this, sizeof(ePassenger), 1, pFile);				//los voy tomando los datos y pasando a un archivo binario
			}
		}
	}
	else
	{
		retorno =-2;
		printf("\n[DEBUG] ERROR la lista ingresada no contiene elementos\n");
	}
	return retorno;
}

int parser_TextFromPassenger(FILE* pFile, LinkedList* pArrayListPassenger)
{
	int retorno;
	int lenPArray;
	ePassenger* this;
	int i;
	int auxId;
	char auxNombre;
	int auxTipoPasajero;

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
				Passenger_getDatosDePasajero(this, &auxId, auxNombre, &auxTipoPasajero);
				printf("%d) %d - %s - %d\n", i, auxId, auxNombre, auxTipoPasajero);
				fprintf(pFile, "%d,%s,%d\n", auxId, auxNombre, auxTipoPasajero);
			}
		}
		else
		{
			retorno =-2;
			printf("\n[DEBUG] ERROR la lista ingresada no contiene elementos\n");
		}
	}
	return retorno;
}
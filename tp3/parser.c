#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

#define SIZE_STR 128
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
		//lectura fantasma
		//printf("2- hacemos lectura fantasma \n");
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",auxId, auxNombre, auxApellido, auxPrice, auxFlyCode, auxTipoPasajero, auxStatusFlight);
		//printf("%s, %s, %s, %s, %s, %s, %s", auxId, auxNombre, auxApellido,auxPrice, auxFlyCode, auxTipoPasajero, auxStatusFlight);
		//guarda los datos y parsea el ID, NOMBRE, TIPO PASAJERO
		while(!feof(pFile))
		{
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",auxId, auxNombre, auxApellido, auxPrice, auxFlyCode, auxTipoPasajero, auxStatusFlight);
			pAuxPasajero = Passenger_newParametrosString(auxId, auxNombre, auxTipoPasajero);//acá ya tendría un pasajero en la lista de punteros

			if(pAuxPasajero != NULL)
			{
				ll_add(pArrayListPassenger, pAuxPasajero);//guarda en la lista linkedList cada elemento

			}
			i++;
		}
		retorno = i;
		//printf("5- retorno funcion pasaje a memoria: %d", i);
	}
    return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
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
				ll_add(pArrayListPassenger, pAuxPasajero);
			}
			else
			{
				printf("ha habido un error en la lectura de los datos del archivo.\n");
				break;
			}

			printf("%d -- %s -- %s\n",
					pAuxPasajero->id,
					pAuxPasajero->nombre,
					pAuxPasajero->tipoPasajero);

		}while(lectura!= 0);
	}
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
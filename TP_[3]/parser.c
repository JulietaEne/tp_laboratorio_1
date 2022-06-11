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
 * 						>0 si leyo (retorna la cantidad de lineas que leyo)
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
		retorno = 0;
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",auxId, auxNombre, auxApellido, auxPrice, auxFlyCode, auxTipoPasajero, auxStatusFlight);
		while(!feof(pFile))
		{
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",auxId, auxNombre, auxApellido, auxPrice, auxFlyCode, auxTipoPasajero, auxStatusFlight);
			pAuxPasajero = Passenger_newParametrosStringAll(auxId, auxNombre, auxApellido, auxPrice, auxFlyCode, auxTipoPasajero, auxStatusFlight);//acá ya tendría un pasajero en la lista de punteros

			if(pAuxPasajero != NULL)
			{
				ll_add(pArrayListPassenger, (ePassenger*)pAuxPasajero);//guarda en la lista linkedList cada elementoç
				i++;
			}
			else
			{
				passenger_delete(pAuxPasajero);
				break;
			}
		}
		retorno = i;
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
			lectura=fread(&unPasajero, sizeof(ePassenger), 1, pFile);
			pAuxPasajero = Passenger_newParametrosAllBinary(unPasajero.id, unPasajero.nombre, unPasajero.apellido, unPasajero.precio, unPasajero.flyCode, unPasajero.tipoPasajero, unPasajero.estadoVuelo);
			if(pAuxPasajero != NULL)
			{
				ll_add(pArrayListPassenger, (ePassenger*)pAuxPasajero);
				retorno ++;
			}
			else
			{
				passenger_delete(pAuxPasajero);
				break;
			}
		}while(lectura!= 0);
	}
	return retorno;
}

/** \brief recibe por teclado los datos de un nuevo pasajero y lo transforma en un elemento *ePasajero dentro de la lista
 *
 * \param pArrayListPassenger LinkedList* recibe la lista donde alojara los elementos parseados
 * \return int retorno -1 si hubo un error en los parametros
 *					   -2 si no pudo crear el pasajero en memoria
 *						0 si opero correctamente
 *
 */
int parser_passengerFromBuffer(LinkedList* pArrayListPassenger, int controlPasajeros)
{
	int retorno;
	int auxId=0;
	char auxNombre[SIZE_STR];
	char auxApellido[SIZE_STR];
	float auxPrice;
	char auxCodigoVuelo[SIZE_STR];
	char auxTipoPass[SIZE_STR];
	char auxEstadoVuelo[SIZE_STR];
	ePassenger* pAuxPasajero;
	int contador;
	int controlLista;

	retorno = -1;
	contador =0;
	if(controlPasajeros<1)
	{
		controlLista =0;
	}
	else
	{
		controlLista = parser_controlListaPasajeros(pArrayListPassenger);

	}
	if(pArrayListPassenger != NULL)
	{
		retorno = -2;
		do//mientras que los datos no estén correctamente cargados, vuelvo a pedir datos
		{
			parser_getNameToBuffer(auxNombre, SIZE_STR);
			parser_getLastNameToBuffer(auxApellido, SIZE_STR);
			parser_getPriceToBuffer(&auxPrice);
			parser_getFlyCodeToBuffer(auxCodigoVuelo, SIZE_STR);
			parser_getTypePassToBuffer(auxTipoPass, SIZE_STR);
			parser_getStatusFlightToBuffer(auxEstadoVuelo, SIZE_STR);

			pAuxPasajero=Passenger_newParametrosAll(auxId, auxNombre, auxApellido, auxPrice, auxCodigoVuelo, auxTipoPass, auxEstadoVuelo, controlLista);
			if(pAuxPasajero!= NULL)
			{
				ll_add(pArrayListPassenger, (ePassenger*)pAuxPasajero);
				Passenger_printMensajeConId("Se ha cargado correctamente el pasajero ", pAuxPasajero);
				retorno=0;
			}
			contador++;
		}while(pAuxPasajero==NULL);
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
	int indexHallado;
	int retorno;
	retorno = -1;
	if(pArrayListPassenger != NULL)
	{
		pAuxPassenger=parser_findIndexById(pArrayListPassenger, &idSolicitado, &indexHallado);//OK YO CREO QUE DEBERIA IR EN PARSER si encuentra igualdad, me decuelve el puntero que encapsula ese id
		if(pAuxPassenger != NULL)
		 {
			controller_chooseCampToEdit(pAuxPassenger, idSolicitado);//yo creo que este tendria que ir en passenger
			printf("El pasajero %d ha sido editado exitosamente\n", pAuxPassenger->id);//ATENCION :B
			retorno=0;
		 }
		else
		{
			retorno=-2;
		}
	}
    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo bin (modo binario).
 *
 * \param pArrayListPassenger LinkedList* Recibe la direccion de memoria del primer elemento del array de punteros a memoria dinamica
 * \return int -1 si hubo un error en los parametros recibidos
 * 			   -2 si no se pudo crear el archivo (no se encontró espacio en memoria)
 * 			   0 si opero exitosamente
 *
 */

//recorro el linkedlist para desencapsular cada *Passenger
			//** en biblio Passenger**
				// recibo cada puntero y recibo el id ingresado
				// y analizo igualdad en this->id == idIngresado
				//cuando encuentro, retorno el index donde se encontro
	//rompo el bucle de busqueda
ePassenger* parser_findIndexById(LinkedList* pArrayListPassenger, int* idIngresado, int* indexHallado)
{
	//int retorno;
	int i;
	int lenArray;
	//int auxId;
	ePassenger* pAuxPass = NULL;

	//retorno =-1;
	lenArray=ll_len(pArrayListPassenger);
	if(pArrayListPassenger!= NULL && idIngresado != NULL && indexHallado!= NULL && lenArray >0)
	{
		*idIngresado = parser_getIdToBuffer(pArrayListPassenger);
		for(i=0; i<lenArray; i++)
		{
			pAuxPass = ll_get(pArrayListPassenger, i);
			pAuxPass= Passenger_findIndexById(pAuxPass, *idIngresado);
			if(pAuxPass!= NULL)
			{
				*indexHallado = i;
				break;
			}
		}
	}
	return pAuxPass;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param pFile FILE* recibe el puntero al archivo sobre el cual realizara la operacion
 * \param pArrayListPassenger LinkedList* recibe la lista donde alojara los elementos parseados
 * \return int retorna -1 si no pudo operar.
 * 						0 si no leyo
 * 						>0 si leyo (retorna la cantidad de lineas que leyo)
 *
*/
int parser_controlListaPasajeros(LinkedList* pArrayListPassenger)
{
	int retorno;
	int cantElementos;
	retorno=-1;
	if(pArrayListPassenger != NULL)
	{
		//retorno=0;
		cantElementos = ll_len(pArrayListPassenger);
		retorno = cantElementos;
	}
	return retorno;
}



/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param pFile FILE* recibe el puntero al archivo sobre el cual realizara la operacion
 * \param pArrayListPassenger LinkedList* recibe la lista donde alojara los elementos parseados
 * \return int retorna -1 si no pudo operar.
 * 						0 si no leyo
 * 						>0 si leyo (retorna la cantidad de lineas que leyo)
 *

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
	int controlLista;
	int aceptarModificarId;

	retorno = -1;
	i=0;
	controlLista = parser_controlListaPasajeros(pArrayListPassenger);
	//printf("[DEBUGGGGG]control lista: %d", controlPrimerCarga);
	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		retorno =0;
		if(controlLista)
		{
			printf("Ya hay datos guardados en el programa. Es posible que modifique el dato ID del archivo recibido. Desea continuar?");
			aceptarModificarId=tp_continuar("Y/N");
			if(aceptarModificarId)
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",auxId, auxNombre, auxApellido, auxPrice, auxFlyCode, auxTipoPasajero, auxStatusFlight);
			//pAuxPasajero = Passenger_newParametrosString(auxId, auxNombre, auxTipoPasajero);
			//printf("status fly: %s", auxStatusFlight); //TIENE UN ENTER QUE YO NO SE LO PUSE :(
			//printf("parser ok\n");
			pAuxPasajero = Passenger_newParametrosStringAll(auxId, auxNombre, auxApellido, auxPrice, auxFlyCode, auxTipoPasajero, auxStatusFlight, &controlLista);//acá ya tendría un pasajero en la lista de punteros

			if(pAuxPasajero != NULL)
			{
				fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",auxId, auxNombre, auxApellido, auxPrice, auxFlyCode, auxTipoPasajero, auxStatusFlight);
				//parser_countLenFile(pFile);

				while(!feof(pFile))
				{
					fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",auxId, auxNombre, auxApellido, auxPrice, auxFlyCode, auxTipoPasajero, auxStatusFlight);
					//pAuxPasajero = Passenger_newParametrosString(auxId, auxNombre, auxTipoPasajero);
					//printf("status fly: %s", auxStatusFlight); //TIENE UN ENTER QUE YO NO SE LO PUSE :(
					pAuxPasajero = Passenger_newParametrosStringAll(auxId, auxNombre, auxApellido, auxPrice, auxFlyCode, auxTipoPasajero, auxStatusFlight, &controlLista);//acá ya tendría un pasajero en la lista de punteros

					if(pAuxPasajero != NULL)
					{
						ll_add(pArrayListPassenger, (ePassenger*)pAuxPasajero);//guarda en la lista linkedList cada elementoç
						i++;
					}
					else
					{
						//printf("Error en la lectura de la linea %d", i);
						break;
					}
				}
				retorno = i;
			}
			else
			{
				printf("se ha cancelado la lectura del archivo. Se sugiere hacer backUp de los datos del archivo antes de volver a intentar la lectura");
			}
		}
		else
		{
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",auxId, auxNombre, auxApellido, auxPrice, auxFlyCode, auxTipoPasajero, auxStatusFlight);
			//parser_countLenFile(pFile);

			while(!feof(pFile))
			{
				fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",auxId, auxNombre, auxApellido, auxPrice, auxFlyCode, auxTipoPasajero, auxStatusFlight);
				//pAuxPasajero = Passenger_newParametrosString(auxId, auxNombre, auxTipoPasajero);
				//printf("status fly: %s", auxStatusFlight); //TIENE UN ENTER QUE YO NO SE LO PUSE :(
				pAuxPasajero = Passenger_newParametrosStringAll(auxId, auxNombre, auxApellido, auxPrice, auxFlyCode, auxTipoPasajero, auxStatusFlight, &controlLista);//acá ya tendría un pasajero en la lista de punteros

				if(pAuxPasajero != NULL)
				{
					ll_add(pArrayListPassenger, (ePassenger*)pAuxPasajero);//guarda en la lista linkedList cada elementoç
					i++;
				}
				else
				{
					//printf("Error en la lectura de la linea %d", i);
					break;
				}
			}
			retorno = i;
		}


		//printf("se pudo leer hasta la linea %d",i);
	}
    return retorno;
}*/

/*int parser_countLenFile(FILE* pFile)
{
	int retorno;
	int contadorLineas;
	char auxChar[1500];

	retorno = -1;
	contadorLineas=0;
	if(pFile!= NULL)
	{
		do{
			fscanf(pFile,"%[^\n]",auxChar);
			contadorLineas++;
		}while(!feof(pFile));
		retorno = contadorLineas;
		printf("contador de lineas: %d", contadorLineas);
	}
	return retorno;
}*/



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
	char auxApellido[SIZE_STR];
	float auxPrecio;
	char auxCodigoVuelo[SIZE_STR];
	char auxTipoPasajero[SIZE_STR];
	char auxEstadoVuelo[SIZE_STR];

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
				//Passenger_getDatosDePasajero(this, &auxId, auxNombre, auxTipoPasajero);
				Passenger_getDatosDePasajero(this, &auxId, auxNombre, auxApellido, &auxPrecio, auxCodigoVuelo, auxTipoPasajero, auxEstadoVuelo);
				//printf("%d) %d - %s - %s\n", i, auxId, auxNombre, auxTipoPasajero);
				fprintf(pFile, "%d,%s,%s,%.2f,%s,%s,%s\n", auxId, auxNombre, auxApellido, auxPrecio, auxCodigoVuelo, auxTipoPasajero, auxEstadoVuelo);
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












/** \brief se encarga de pedir el id del pasajero a eliminar, e interactuar con el usuario para efectuar la baja
 *
 * \param pArrayListPassenger LinkedList* recibe la lista donde alojara los elementos parseados
 * \return int retorno -1 si hubo un error en los parametros
 *					   -2 si no encontro el id solicitado ( o sea, si me dio NULL)
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


	retorno=-1;

	if(pArrayListPassenger!= NULL)
	{
		retorno =-2;

		pAuxPassenger=parser_findIndexById(pArrayListPassenger, &idSolicitado, &indexHallado);

		if(pAuxPassenger!= NULL)
		{

			if(!passenger_delete(pAuxPassenger))
			{
				ll_remove(pArrayListPassenger, indexHallado);
				retorno=0;
			}
			else
			{
				retorno =-3;
			}

		}
	}
	return retorno;
}




int parser_saveIdIntoFile(int ultimoId)
{
	int retorno;
	FILE* pFileLastId;

	retorno=-1;
	pFileLastId = fopen("ultimoId.bin", "wb");
	if(pFileLastId != NULL)
	{
		fwrite(&ultimoId, sizeof(int), 1, pFileLastId); //escribe el idRecibido en archivo
		fclose(pFileLastId);
		retorno =0;
	}
	return retorno;
}

int parser_loadIdFromFile()
{
	int retorno;
	int getId;
	FILE* pFileIdDeleted;

	getId=0;
	retorno=-1;
	pFileIdDeleted = fopen("ultimoId.bin", "rb");

	if(pFileIdDeleted != NULL)
	{
		fread(&getId, sizeof(int), 1, pFileIdDeleted);
		fclose(pFileIdDeleted);
		printf("getId/retorno: %d",getId);
		retorno = getId;//retorna el id leido en el archivo
	}
	/*else
	{
		printf("DEBUG ERROR DE LECTURA ARCHIVO ULTIMOID");
	}*/

	return retorno;
}

int parser_proximoId(int idRecibido)
{
	int retorno;
	int idLeido;

	retorno=-1;
	idLeido= parser_loadIdFromFile();//me trae el idLeido

	//printf("id recibido:%d - ", idRecibido);
	if(idLeido == idRecibido)
	{
		retorno= idRecibido+1;
		printf("nuevo id:%d", retorno);
		parser_saveIdIntoFile(retorno);
	}
	else
	{
		if(idLeido>idRecibido)
		{
			retorno = idLeido+1;
			parser_saveIdIntoFile(retorno);
		}
		else
		{
			retorno=idRecibido;
			parser_saveIdIntoFile(retorno);
		}
	}
		/*if(idLeido < idRecibido)
		{
			printf("valor leido %d es menor al valor recibido %d", idLeido, idRecibido);
			retorno = idRecibido+1;
			parser_saveIdIntoFile(retorno);
			printf(" sobreescribo el archivo\n");
		}
		else //si idRecibido es menor entonces el ultimo id fue el idLeido
		{
			printf("valor leido %d es mayor al valor recibido %d", idRecibido, idLeido);
			if(idLeido == idRecibido)
			{
				retorno = idLeido+1;
				parser_saveIdIntoFile(retorno);
				printf(" son iguales asi que le +1 = retorno: %d\n", retorno);
				//parser_saveIdIntoFile(retorno);
			}
			else
			{
				printf(" el valor leido %d es mayor al recibido %d , entonces devuelvo el valor del archivo +1 = retorno %d\n",idRecibido, idLeido, retorno);
				retorno = idLeido; //retorna >0 si levantò el ultimoId
			}
		}*/
	//}
	return retorno;
}

//---------------------Getters que interactuan con el usuario---------------------//
/** \brief se encarga de solicitar al usuario un id
 *
 * \param pArrayListPassenger LinkedList* recibe la lista donde alojara los elementos parseados
 * \return int retorno -1 si hubo un error
 *						>0 si opero correctamente (retorna el id ingresado)
 *
 */
int parser_getIdToBuffer(LinkedList* pArrayListPassenger)
{
	int idIngresado;
	if(pArrayListPassenger != NULL)
	{
		controller_askToViewList(pArrayListPassenger);
		utn_GetNumeroInt(&idIngresado, "ingrese un id: ", "dato incorrecto", FILE_ID_MIN, ID_MAX, REINTENTOS);
	}
	return idIngresado;
}

/** \brief se encarga de solicitar al usuario el nombre del pasajero a cargar
 *
 * \param char* name Recibe la direccion de memoria de la variable donde se alojará el dato recibido
 * \param int lenName Recibe el tamaño de la cadena
 * \return int retorno -1 si hubo un error
 *						0 si opero correctamente
 *
 */
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

/** \brief se encarga de solicitar al usuario el apellido del pasajero a cargar
 *
 * \param char* lastName Recibe la direccion de memoria de la variable donde se alojará el dato recibido
 * \param int lenLastName Recibe el tamaño de la cadena
 * \return int retorno -1 si hubo un error
 *						0 si opero correctamente
 *
 */
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

/** \brief se encarga de solicitar al usuario el precio para el pasajero a cargar
 *
 * \param float* price Recibe la direccion de memoria de la variable donde se alojará el dato recibido
 * \return int retorno -1 si hubo un error
 *						0 si opero correctamente
 *
 */
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

/** \brief se encarga de solicitar al usuario el codigo de vuelo del pasajero a cargar
 *
 * \param char* flyCode Recibe la direccion de memoria de la variable donde se alojará el dato recibido
 * \param int lenFlyCode Recibe el tamaño de la cadena
 * \return int retorno -1 si hubo un error
 *						0 si opero correctamente
 *
 */
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

/** \brief se encarga de solicitar al usuario el estado de vuelo del pasajero a cargar
 *
 * \param char* statusFlight Recibe la direccion de memoria de la variable donde se alojará el dato recibido
 * \param int lenStatusFlight Recibe el tamaño de la cadena
 * \return int retorno -1 si hubo un error
 *						0 si opero correctamente
 *
 */
int parser_getStatusFlightToBuffer(char* statusFlight, int lenStatusFlight)
{
	int retorno;
	int codTipoPasajero;
	retorno =-1;
	if(statusFlight != NULL && lenStatusFlight  >0)
	{
		codTipoPasajero=tp_ImprimirMenuTresOpciones("indique tipo pasajero: ", "1- Aterrizado", "2- En Horario", "3- En Vuelo");
		switch (codTipoPasajero) {
			case 1:
				strcpy(statusFlight,"Aterrizado   ");
				break;
			case 2:
				strcpy(statusFlight,"En Horario   ");
				break;
			case 3:
				strcpy(statusFlight,"En Vuelo    ");
				break;
		}
		retorno=0;
	}
	return retorno;
}

/** \brief se encarga de solicitar al usuario el tipo de pasajero del pasajero a cargar
 *
 * \param char* typePass Recibe la direccion de memoria de la variable donde se alojará el dato recibido
 * \param int lenName Recibe el tamaño de la cadena
 * \return int retorno -1 si hubo un error
 *						0 si opero correctamente
 *
 */
int parser_getTypePassToBuffer(char* typePass, int lenName)
{
	int retorno;
	int codTipoPasajero;
	retorno =-1;
	if(typePass != NULL && lenName >0)
	{
		codTipoPasajero=tp_ImprimirMenuTresOpciones("indique tipo pasajero: ", "1- EconomyClass", "2- ExecutiveClass", "3- FirstClass");
		switch (codTipoPasajero) {
			case 1:
				strcpy(typePass,"EconomyClass");
				break;
			case 2:
				strcpy(typePass,"ExecutiveClass");
				break;
			case 3:
				strcpy(typePass,"FirstClass   ");
				break;
		}
		retorno=0;
	}
	return retorno;
}

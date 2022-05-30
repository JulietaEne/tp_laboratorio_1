
#include "Controller.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char* recibe como cadena de caracteres la ruta donde se encuentra el archivo o donde se lo creara
 * \param pArrayListPassenger LinkedList* Recibe la direccion de memoria del primer elemento del array de punteros a memoria dinamica
 * \return int -1 si hubo un error en los parametros recibidos
 * 			   -2 si no pudo abrir el archivo
 * 			   0 si pudo realizar lectura (retorna la cantidad de lineas que leyo del archivo)
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)//fopen read
{
	FILE* pFile;
	int retorno;

	retorno = -1;
	if(path != NULL && pArrayListPassenger != NULL)
	{
		retorno = -2;
		pFile = fopen(path, "r");
		if(pFile != NULL)
		{
			parser_PassengerFromText(pFile, pArrayListPassenger);
			retorno = 0;
			printf("Se han obtenido todos los datos del archivo\n");
		}
		else
		{
			printf("Error al abrir archivo. Verifique que la ruta de acceso sea correcta.\n");
		}
	}
    return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile;
	int retorno;
	//printf("HOLAAAAAA 1 \n");
	retorno = -1;
	if(path != NULL && pArrayListPassenger != NULL)
	{
		//printf("HOLAAAAAA 2 \n");
		retorno = 0;
		pFile = fopen(path, "rb");
		//printf("1A- puntero archivo nulo");
		if(pFile != NULL)
		{
			//printf("1B- abrimos el archivo");
			retorno = parser_PassengerFromBinary(pFile, pArrayListPassenger);//ESTO HACE QUE POR ALGUNA RAZON NO ENTRE DIRECTAMENTE AL CONTROLLER LOAD
			//printf("retorno: %d\n", retorno);
			printf("todos los datos han sido pasados a memoria para trabajar\n");
		}
		else
		{
			printf("Error al abrir archivo. Verifique que la ruta de acceso sea correcta.\n");
		}
	}
	return retorno;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 */

int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int retorno;
	int auxId=1099;
	char auxNombre[SIZE_STR];
	char auxTipoPass[SIZE_STR];
	//char auxApellido[SIZE_STR];
	//float auxPrice;
	//char codigoVuelo[SIZE_STR];
	//char estadoVuelo[SIZE_STR];
	ePassenger* pAuxPasajero;
	retorno = -1;
	if(pArrayListPassenger != NULL)
	{
		retorno = 0;
		do//mientras que los datos no estén correctamente cargados, vuelvo a pedir datos
		{
			//controller_getIdToBuffer(&auxId, pArrayListPassenger);// NO SE COMO HACER QUE ANDE :(
			controller_getNameToBuffer(auxNombre, SIZE_STR);
			//controller_getLastNameToBuffer(auxApellido, SIZE_STR);
			//controller_getPriceToBuffer(auxPrice);
			//controller_getSFlyCodeToBuffer(codigoVuelo, SIZE_STR);
			controller_getTypePassToBuffer(auxTipoPass, SIZE_STR);
			//controller_getFlyCodeToBuffer(flyCode, lenFlyCode);
			//voy a pedir los datos que el usuario quiere cargar.
			pAuxPasajero=Passenger_newParametros(auxId, auxNombre, auxTipoPass);//voy a crear un nuevo pasajero
			if(pAuxPasajero!= NULL)
			{
				ll_add(pArrayListPassenger, (ePassenger*)pAuxPasajero);
			}
		}while(pAuxPasajero==NULL);
		retorno = 0;
	}
	return retorno;
}

/** \brief Recorre el array de punteros para analizar sus campos id y hallar el id mas alto
 *
 * \param pArrayListPassenger LinkedList* Recibe la direccion de memoria del primer elemento del array de punteros a memoria dinamica
 * \return int retorno -1 si hubo un error en los parametros
 * 						0 si no hallo datos
 * 						>0 si pudo operar(retorna el valor del ultimo id)
 *

int Controller_findLastIdValue(LinkedList* pArrayListPassenger)
{
	int retorno;
	int i;
	int lenArray;
	int ultimoId;
	ePassenger* pAuxPasajero1;
	//ePassenger* pAuxPasajero2;

	retorno =-1;
	lenArray = ll_len(pArrayListPassenger);
	if(pArrayListPassenger!= NULL && lenArray>0)
	{
		retorno=0;
		//recorro la lista y busco el id mas alto
		for(i=0; i<lenArray; i++)
		{
			pAuxPasajero1= *(pArrayListPassenger+i); //quiero desencapsular el contenido de la posicion i del array de punteros :(
			//pAuxPasajero2= pArrayListPassenger[i+1];
			if(i==0)
			{
				ultimoId = pAuxPasajero1->id;
			}
			if(ultimoId < pAuxPasajero1->id)
			{
				ultimoId = pAuxPasajero1->id;
			}
		}
		retorno = ultimoId;
	}
	return retorno;
}*/

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int idSolicitado;
	ePassenger* pAuxPassenger=NULL;
	char auxNombre[SIZE_STR];
	int indexHallado;
	// muestro la lista de pasajeros
	//interactuo con el usuario pidiendo un id

	utn_GetNumeroInt(&idSolicitado, "ingrese un id: ", "dato incorrecto", ID_MIN, ID_MAX, REINTENTOS);
	//recorro el linkedlist para desencapsular cada *Passenger
	pAuxPassenger=controller_findIndexById(pArrayListPassenger, idSolicitado, &indexHallado);//si encuentra igualdad, me decuelve el puntero que encapsula ese id
	if(pAuxPassenger != NULL)
	 {
		 controller_getNameToBuffer(auxNombre, SIZE_STR);
		 Passenger_setNombre(pAuxPassenger, auxNombre);
		 printf("editado: %s", pAuxPassenger->nombre);
	 }
    return 1;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *

int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int retorno;
	int idSolicitado;
	ePassenger* pAuxPassenger;
	retorno=-1;
	if(pArrayListPassenger!= NULL)
	{
		utn_GetNumeroInt(&idSolicitado, "ingrese un id: ", "dato incorrecto", ID_MIN, ID_MAX, REINTENTOS);
		pAuxPassenger=controller_findIndexById(pArrayListPassenger, idSolicitado);
		if(pAuxPassenger!= NULL)
		{
			ll_remove(pArrayListPassenger, index)
		}
		retorno=0;

	}
    return 1;
} */

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile;
	int retorno;
	retorno = -1;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		pFile = fopen(path, "w");
		if(pFile != NULL)
		{
			//aca tiene que ir algo que guarde de memoria a archivo
			parser_TextFromPassenger(pFile, pArrayListPassenger);
			fclose(pFile);
			retorno = 0;
			printf("Se ha guardado correctamente\n");
		}
		else
		{
			printf("ERROR. No se ha crear abrir el archivo");
			retorno = -2;
		}
	}
	return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile;
	int retorno;
	retorno = -1;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		pFile = fopen(path, "wb");
		if(pFile != NULL)
		{
			parser_BinaryFromPassenger(pFile, pArrayListPassenger);//aca tiene que ir algo que guarde de memoria a archivo
			fclose(pFile);
			retorno = 0;
			printf("Se ha guardado correctamente como binario\n");
		}
		else
		{
			printf("ERROR. No se ha podido crear el archivo binario");
			retorno = -2;
		}
	}
	return retorno;
}

int controller_getNameToBuffer(char* name, int lenName)
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

int controller_getLastNameToBuffer(char* lastName, int lenLastame)
{
	int retorno;
	retorno =-1;
	if(lastName != NULL && lenLastame>0)
	{
		utn_ingresarAlfabetica(lastName, lenLastame, "Apellido de pasajero: ", "Ingrese un dato valido", REINTENTOS);
		retorno=0;
	}
	return retorno;
}

int controller_getPriceToBuffer(float* price)
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

int controller_getFlyCodeToBuffer(char* flyCode, int lenFlyCode)
{
	int retorno;
	retorno =-1;
	if(flyCode != NULL && lenFlyCode>0)
	{
		utn_ingresarAlfabetica(flyCode, lenFlyCode, "Codigo de vuelo: ", "Ingrese un dato valido", REINTENTOS);
		retorno=0;
	}
	return retorno;
}

int controller_getStatusFlightToBuffer(char* statusFlight, int lenStatusFlight)
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
/*
int controller_getIdToBuffer(int* id, LinkedList* pArrayListPassenger)
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
}*/

int controller_getTypePassToBuffer(char* typePass, int lenName)
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

//recorro el linkedlist para desencapsular cada *Passenger
			//** en biblio Passenger**
				// recibo cada puntero y recibo el id ingresado
				// y analizo igualdad en this->id == idIngresado
				//cuando encuentro, retorno el index donde se encontro
	//rompo el bucle de busqueda
ePassenger* controller_findIndexById(LinkedList* pArrayListPassenger, int idIngresado, int* indexHallado)
{
	//int retorno;
	int i;
	int lenArray;
	ePassenger* pAuxPass = NULL;

	//retorno =-1;
	lenArray=ll_len(pArrayListPassenger);
	if(pArrayListPassenger!= NULL && idIngresado>0 && lenArray>0)
	{
		//retorno =-2; //si no encontro ningun elemento
		for(i=0; i<lenArray; i++)
		{
			pAuxPass = ll_get(pArrayListPassenger, i);
			//printf("%d) %s\n", i+1, pAuxPass->nombre);
			pAuxPass= Passenger_findIndexById(pAuxPass, idIngresado);
			if(pAuxPass!= NULL)
			{
				*indexHallado = i;
				break;
			}
		}
	}
	return pAuxPass;
}

/*int controller_recorrerArray(LinkedList* pArrayListPassenger, ePassenger* pAuxPass)
{
	int i;
	int lenArray;
	int retorno;
	//ePassenger* pAuxPass = NULL;
	retorno=-1;
	if(pArrayListPassenger!= NULL)
	{
		lenArray = ll_len(pArrayListPassenger);
		for(i=0; i<lenArray; i++)
		{
			pAuxPass = ll_get(pArrayListPassenger, i);
			retorno=i;
		}
	}
	return retorno;
}*/

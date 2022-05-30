
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
	retorno = -1;
	if(pArrayListPassenger != NULL)
	{
		retorno = -2;
		parser_passengerFromBuffer(pArrayListPassenger); // esta funcion se encarga de levantar por teclado la info y de agregarla al linkedlist en un puntero tipo *ePassenger
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
 * \param pArrayListPassenger LinkedList* Recibe la direccion de memoria del primer elemento del array de punteros a memoria dinamica
 * \return int -1 si hubo un error en los parametros recibidos
 * 				0 si opero exitosamente
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int retorno;
	int retornoFuncion;
	retorno = -1;
	if(pArrayListPassenger != NULL)
	{
		retornoFuncion = parser_passengerToEdit(pArrayListPassenger);
		switch (retornoFuncion) {
			case -1:
				printf("error -1\n");
				break;
			case -2:
				printf("[Error -2] No se ha encontrado coincidencias con el valor ingresado\n");
				break;
		}
		retorno=0;
	}
	else
	{
		tp_MensajeErrorGenerico('4');
	}
    return retorno;
}

/** \brief Baja de pasajero
 *
 * \param pArrayListPassenger LinkedList* Recibe la direccion de memoria del primer elemento del array de punteros a memoria dinamica
 * \return int -1 si hubo un error en los parametros recibidos
 * 				0 si opero exitosamente
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int retorno;
	int retornoFuncion;

	retorno=-1;
	if(pArrayListPassenger!= NULL)
	{
		retornoFuncion = parser_passengerToDelete(pArrayListPassenger);
		switch (retornoFuncion)
		{
			case -1:
				printf("\nError -1\n");
				break;
			case -2:
				printf("\nError el id solicitado no se encuentra en la lista\n");
				break;
			case -3:
				printf("\nNo se pudo realizar la baja del pasajero\n");
				break;
			case 0:
				printf("\nEl pasajero indicado se ha eliminado correctamente\n");
				break;
		}
		retorno=0;
	}
	else
	{
		tp_MensajeErrorGenerico('5');
	}
    return retorno;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int retorno;
	int i;
	ePassenger* pAuxPass = NULL;
	int lenArray;

	retorno =-1;
	if(pArrayListPassenger!= NULL)
	{
		lenArray = ll_len(pArrayListPassenger);
		retorno =0;
		for(i=0; i<lenArray; i++)
		{
			pAuxPass = ll_get(pArrayListPassenger, i);
			printf("%d, %s, %s\n", pAuxPass->id, pAuxPass->nombre, pAuxPass->tipoPasajero);
		}
	}
    return retorno;
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

//recorro el linkedlist para desencapsular cada *Passenger
			//** en biblio Passenger**
				// recibo cada puntero y recibo el id ingresado
				// y analizo igualdad en this->id == idIngresado
				//cuando encuentro, retorno el index donde se encontro
	//rompo el bucle de busqueda
ePassenger* controller_findIndexById(LinkedList* pArrayListPassenger, int* idIngresado, int* indexHallado)
{
	//int retorno;
	int i;
	int lenArray;
	int auxId;
	ePassenger* pAuxPass = NULL;

	//retorno =-1;
	lenArray=ll_len(pArrayListPassenger);
	if(pArrayListPassenger!= NULL && idIngresado>0 && lenArray>0)
	{
		utn_GetNumeroInt(&auxId, "ingrese un id: ", "dato incorrecto", ID_MIN, ID_MAX, REINTENTOS);
		*idIngresado = auxId;
		//retorno =-2; //si no encontro ningun elemento
		for(i=0; i<lenArray; i++)
		{
			pAuxPass = ll_get(pArrayListPassenger, i);
			//printf("%d) %s\n", i+1, pAuxPass->nombre);
			pAuxPass= Passenger_findIndexById(pAuxPass, *idIngresado);
			if(pAuxPass!= NULL)
			{
				*indexHallado = i;
				//printf("%d: %s OK \n", pAuxPass->id, pAuxPass->nombre);
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

/** \brief Interactua con el usuario para indicar el campo a modificar
 *
 * \param ePassenger* pPasajero recibe el pasajero sobre el cual se hara la modificacion
 * \param int idPasajero recive por valor el id del pasajero indicado
 * \return int retorna -1 si hubo un error en los parametros recibidos
 * 						0 si opero correctamente
 *
 */
int controller_chooseCampToEdit(ePassenger* pPasajero, int idPasajero)
{
	int retorno;
	int opcion;
	char auxNombre[SIZE_STR];
	char auxTipoPasajero[SIZE_STR];

	retorno =-1;
	if(pPasajero!= NULL)
	{
		do{
			opcion= tp_ImprimirMenuTresOpciones("1- Cambiar nombre", "2- Cambiar Tipo de Pasajero", "3- Volver atrás", "");

			switch (opcion)
			{
				case 1:
					parser_getNameToBuffer(auxNombre, SIZE_STR);
					Passenger_setNombre(pPasajero, auxNombre);
					printf("Ha modificado el nombre del pasajero %d\n\n", idPasajero);
					break;
				case 2:
					parser_getTypePassToBuffer(auxTipoPasajero, SIZE_STR);
					Passenger_setNombre(pPasajero, auxTipoPasajero);
					printf("Ha modificado el Tipo de Pasajero del pasajero %d\n\n", idPasajero);
					break;
				case 3:
					printf("Volviendo al menu principal\n\n");
					break;
			}
		}while(opcion!= 3);
		retorno =0;
	}
	return retorno;
}

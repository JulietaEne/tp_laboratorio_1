
#include "Controller.h"

/** \brief Interactua con el usuario para determinar el archivo de texto sobre el cual se trabajará
 *
 * \param pArrayListPassenger LinkedList* Recibe la direccion de memoria del primer elemento del array de punteros a memoria dinamica
 * \return int -1 si hubo un error
 * 			   0 si pudo operar exitosamente
 *
 */
int controller_optionsToOpenCsv(LinkedList* pArrayListPassenger)
{
	int cambiarPath;
	char path[SIZE_STR]="data.csv";
	int retorno;

	retorno = -1;
	if(pArrayListPassenger != NULL)
	{
		cambiarPath= tp_continuar("Ubicacion de archivo './data.csv' Desea cambiar el path de apertura? Y/N");
		if(cambiarPath)
		{
			utn_getAlfaNumerica(path, SIZE_STR, "ingrese nuevo path: ", "ingrese un dato valido", REINTENTOS);
		}
		controller_loadFromText(path,pArrayListPassenger);
		retorno = 0;
	}
	return retorno;
}

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
	int retornoFuncion;

	retorno = -1;
	if(path != NULL && pArrayListPassenger != NULL)
	{
		retorno = -2;
		pFile = fopen(path, "r");
		if(pFile != NULL)
		{
			//printf("load ok\n");
			retornoFuncion=parser_PassengerFromText(pFile, pArrayListPassenger);
			retorno = 0;
			printf("\nSe han obtenido los datos del archivo hasta la linea %d del archivo %s\n", retornoFuncion, path);
		}
		else
		{
			printf("[ERROR]No existe archivo %s.\n", path);
		}
	}
    return retorno;
}

/** \brief Interactua con el usuario para determinar el archivo binario sobre el cual se trabajará
 *
 * \param pArrayListPassenger LinkedList* Recibe la direccion de memoria del primer elemento del array de punteros a memoria dinamica
 * \return int -1 si hubo un error
 * 			   0 si pudo operar exitosamente
 *
 */
int controller_optionsToOpenBin(LinkedList* pArrayListPassenger)
{
	int cambiarPath;
	char path[SIZE_STR]="data-procesado.bin";
	int retorno;

	retorno = -1;
	if(pArrayListPassenger != NULL)
	{
		cambiarPath= tp_continuar("Ubicacion de archivo './data-procesado.bin' Desea cambiar el path de apertura? Y/N");
		if(cambiarPath)
		{
			utn_getAlfaNumerica(path, SIZE_STR, "ingrese nuevo path: ", "ingrese un dato valido", REINTENTOS);
		}
		controller_loadFromBinary(path,pArrayListPassenger);
		retorno = 0;
	}
	return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data-procesado.bin (modo binario).
 *
 * \param path char* recibe como cadena de caracteres la ruta donde se encuentra el archivo o donde se lo creara
 * \param pArrayListPassenger LinkedList* Recibe la direccion de memoria del primer elemento del array de punteros a memoria dinamica
 * \return int -1 si hubo un error en los parametros recibidos
 * 			   -2 si no pudo abrir el archivo
 * 			   0 si pudo realizar lectura (retorna la cantidad de lineas que leyo del archivo)
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile;
	int retorno;
	int retornoFuncion;
	retorno = -1;
	if(path != NULL && pArrayListPassenger != NULL)
	{
		retorno = 0;
		pFile = fopen(path, "rb");	//printf("1A- puntero archivo nulo");
		if(pFile != NULL)
		{
			//printf("1B- abrimos el archivo");
			retornoFuncion = parser_PassengerFromBinary(pFile, pArrayListPassenger);//ESTO HACE QUE POR ALGUNA RAZON NO ENTRE DIRECTAMENTE AL CONTROLLER LOAD
			retorno =0;
			printf("\nSe han obtenido los datos del archivo hasta la linea%d del archivo %s\n", retornoFuncion, path);
		}
		else
		{
			printf("\n[ERROR] No existe archivo%s\n", path);
		}
	}
	return retorno;
}

/** \brief Alta de pasajero
 *
 * \param LinkedList* pArrayListPassenger Recibe la direccion de memoria del primer elemento del array de punteros a memoria dinamica
 * \param int controlPasajeros indica a la funcion si ya se han cargado datos a partir de un archivo
 * \return int -1 si hubo un error en los parametros recibidos
 * 			   -2 si no pudo solicitar exitosamente los datos a cargar
 * 			   0 si opero exitosamente
 */

int controller_addPassenger(LinkedList* pArrayListPassenger, int controlPasajeros)
{
	int retorno;
	retorno = -1;
	if(pArrayListPassenger != NULL)
	{
		retorno = -2;
		parser_passengerFromBuffer(pArrayListPassenger, controlPasajeros); // esta funcion se encarga de levantar por teclado la info y de agregarla al linkedlist en un puntero tipo *ePassenger
		retorno = 0;
	}
	return retorno;
}

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
				printf("\nLa baja del pasajero no se ha realizado\n");
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
 * \param pArrayListPassenger LinkedList* Recibe la direccion de memoria del primer elemento del array de punteros a memoria dinamica
 * \return int -1 si hubo un error
 * 				0 si opero exitosamente
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger, int controlOrden)
{
	int retorno;
	int i;
	ePassenger* pAuxPass = NULL;
	int lenArray;

	retorno =-1;
	if(pArrayListPassenger!= NULL)
	{
		lenArray = ll_len(pArrayListPassenger);
		if(!controlOrden)
		{
			printf("leyendo Datos... \n");
			ll_sort(pArrayListPassenger, Passenger_compareById, 1);
		}
		Passenger_printEncabezado();
		for(i=0; i<lenArray; i++)
		{
			pAuxPass = ll_get(pArrayListPassenger, i);
			Passenger_printPasajero(pAuxPass);
		}
		retorno =0;
	}
    return retorno;
}

/** \brief Ordenar pasajeros
 *
 * \param pArrayListPassenger LinkedList* Recibe la direccion de memoria del primer elemento del array de punteros a memoria dinamica
 * \return int -1 si hubo un error
 * 				0 si opero exitosamente
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int retorno;
	int opcionIngresada;
	int tipoOrden;
	//int (*compareByName)(void*, void*);
	retorno = -1;
	//compareByName = Passenger_compareByName;
	if(pArrayListPassenger!= NULL)
	{
		opcionIngresada=tp_ImprimirMenuTresOpciones("Ordenar parajeros según:", "1- ordenar por ID", "2- ordenar por precio", "3- ordenar por nombre");
		switch (opcionIngresada) {
			case 1:
				tipoOrden= tp_continuar("Ordenar ID de forma decreciente? Y/N");
				printf("ordenando...\n");
				ll_sort(pArrayListPassenger, Passenger_compareById, tipoOrden);
				break;
			case 2:
				tipoOrden= tp_continuar("Ordenar precios de forma decreciente? Y/N");
				printf("ordenando...");
				ll_sort(pArrayListPassenger, Passenger_comparePrice, tipoOrden);

				break;
			case 3:
				tipoOrden= tp_continuar("Imprimr por orden alfabetico nombre? Y/N");
				printf("ordenando...");
				ll_sort(pArrayListPassenger, Passenger_compareByName, tipoOrden);
				break;
		}
		tipoOrden= tp_continuar("ORDENADO\nDesea imprimir la lista ordenada? Y/N");
		if(tipoOrden)
		{
			controller_ListPassenger(pArrayListPassenger, 1);
		}
		retorno =0;
	}
    return retorno;
}

/** \brief Interactua con el usuario para determinar donde se guardara el archivo de texto
 *
 * \param pArrayListPassenger LinkedList* Recibe la direccion de memoria del primer elemento del array de punteros a memoria dinamica
 * \return int -1 si hubo un error
 * 			   0 si pudo operar exitosamente
 *
 */
int controller_optionsToSaveCsv(LinkedList* pArrayListPassenger)
{
	int cambiarPath;
	char path[SIZE_STR]="data-procesado.csvtxt";
	int retorno;

	retorno = -1;
	if(pArrayListPassenger != NULL)
	{
		cambiarPath= tp_continuar("Ubicacion de archivo './data-procesado.csv' Desea guardar en otro path? Y/N");
		if(cambiarPath)
		{
			utn_getAlfaNumerica(path, SIZE_STR, "ingrese nuevo path: ", "ingrese un dato valido", REINTENTOS);
		}
		controller_saveAsText(path,pArrayListPassenger);
		retorno = 0;
	}
	return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param pArrayListPassenger LinkedList* Recibe la direccion de memoria del primer elemento del array de punteros a memoria dinamica
 * \return int -1 si hubo un error en los parametros recibidos
 * 			   -2 si no se pudo crear el archivo (no se encontró espacio en memoria)
 * 			   0 si opero exitosamente
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
			printf("[ERROR] No se ha crear el archivo");
			retorno = -2;
		}
	}
	return retorno;
}

/** \brief Interactua con el usuario para determinar donde se guardara el archivo binario
 *
 * \param pArrayListPassenger LinkedList* Recibe la direccion de memoria del primer elemento del array de punteros a memoria dinamica
 * \return int -1 si hubo un error
 * 			   0 si pudo operar exitosamente
 *
 */
int controller_optionsToSaveBin(LinkedList* pArrayListPassenger)
{
	int cambiarPath;
	char path[SIZE_STR]="data-procesado.bin";
	int retorno;

	retorno = -1;
	if(pArrayListPassenger != NULL)
	{
		cambiarPath= tp_continuar("Ubicacion de archivo './data-procesado.bin' Desea guardar en otro path? Y/N");
		if(cambiarPath)
		{
			utn_getAlfaNumerica(path, SIZE_STR, "ingrese nuevo path: ", "ingrese un dato valido", REINTENTOS);
		}
		controller_saveAsBinary(path,pArrayListPassenger);
		retorno = 0;
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



/** \brief Consulta al usuario para mostrar la lista completa
 *
 * \param pArrayListPassenger LinkedList* Recibe la direccion de memoria del primer elemento del array de punteros a memoria dinamica
 * \return void
 *
 */
void controller_askToViewList(LinkedList* pArrayListPassenger)
{
	int verLista;
	if(pArrayListPassenger!= NULL)
	{
		verLista = tp_continuar("Imprimir lista de pasajeros? Y/N");
		if(verLista)
		{
			controller_ListPassenger(pArrayListPassenger, 1);
		}
	}
}

/** \brief Consulta al usuario el campo a modificar
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
	char auxChar[SIZE_STR];
	float auxPrecio;

	retorno =-1;
	if(pPasajero!= NULL)
	{
		do{
			opcion= tp_ImprimirMenuDiezOpciones("elija el campo que desea editar", "1- Cambiar nombre", "2- Cambiar Apellido", "3- Cambiar Precio", "4- Cambiar código vuelo", "5- Cambiar Tipo Pasajero", "6- Cambiar Estado Vuelo", "7- Volver atrás", "", "", "");

			switch (opcion)
			{
				case 1:
					parser_getNameToBuffer(auxChar, SIZE_STR);
					Passenger_setNombre(pPasajero, auxChar);
					printf("Ha modificado el nombre del pasajero %d\n\n", idPasajero);
					break;
				case 2:
					parser_getLastNameToBuffer(auxChar, SIZE_STR);
					Passenger_setLastName(pPasajero, auxChar);
					printf("Ha modificado el apellido del pasajero %d\n\n", idPasajero);
					break;
				case 3:
					parser_getPriceToBuffer(&auxPrecio);
					Passenger_setPrecio(pPasajero, auxPrecio);
					printf("Ha modificado el precio en el pasajero %d\n\n", idPasajero);
					break;
				case 4:
					parser_getFlyCodeToBuffer(auxChar, SIZE_STR);
					Passenger_setCodigoVuelo(pPasajero, auxChar);
					printf("Ha modificado el Código de Vuelo del pasajero %d\n\n", idPasajero);
					break;
				case 5:
					parser_getTypePassToBuffer(auxChar,  SIZE_STR);
					Passenger_setTipoPasajero(pPasajero, auxChar);
					printf("Ha modificado el Tipo de Pasajero del pasajero %d\n\n", idPasajero);
					break;
				case 6:
					parser_getStatusFlightToBuffer(auxChar,  SIZE_STR);
					Passenger_setStatusFlight(pPasajero, auxChar);
					printf("Ha modificado el Estado de Vuelo del pasajero %d\n\n", idPasajero);
					break;
				case 7:
					printf("Volviendo al menu principal\n\n");
					break;
			}
		}while(opcion!= 7);
		retorno =0;
	}
	return retorno;
}



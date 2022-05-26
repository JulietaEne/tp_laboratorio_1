
#include "Controller.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char* recibe como cadena de caracteres la ruta donde se encuentra el archivo o donde se lo creara
 * \param pArrayListPassenger LinkedList* Recibe la direccion de memoria del primer elemento del array de punteros a memoria dinamica
 * \return int -1 si hubo un error en los parametros recibidos
 * 			   0 si opero correctamente
 * 			   >0 si pudo realizar lectura (retorna la cantidad de lineas que leyo del archivo)
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)//fopen read
{
	FILE* pFile;
	int retorno;

	retorno = -1;
	if(path != NULL && pArrayListPassenger != NULL)
	{
		retorno = 0;
		pFile = fopen(path, "r");
		if(pFile != NULL)
		{
			retorno = parser_PassengerFromText(pFile, pArrayListPassenger);
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

	retorno = -1;
	if(path != NULL && pArrayListPassenger != NULL)
	{
		retorno = 0;
		pFile = fopen(path, "rb");
		if(pFile != NULL)
		{
			retorno = parser_PassengerFromBinary(pFile, pArrayListPassenger);
		}
	}
	return retorno;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
    return 1;
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
		}
		else
		{
			printf("ERROR. No se ha podido crear el archivo binario");
			retorno = -2;
		}
	}
	return retorno;
}


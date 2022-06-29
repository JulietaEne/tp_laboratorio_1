/*
 * Controller.c
 *
 *  Created on: 28 jun. 2022
 *      Author: julieta_enee
 */


#include "../inc/LinkedList.h"
#include "validaciones.h"
#include "tp.h"
#include "arrays.h"
#include "utn.h"
#include "Computer.h"



/** \brief Interactua con el usuario para determinar el archivo de texto sobre el cual se trabajará
 *
 * \param pArrayListPassenger LinkedList* Recibe la direccion de memoria del primer elemento del array de punteros a memoria dinamica
 * \return int -1 si hubo un error
 * 			   0 si pudo operar exitosamente
 *
 */
int controller_optionsToOpenCsv(LinkedList* listaComputadoras)
{
	int cambiarPath;
	char path[SIZE_STR]="././datos_SP.csv";
	int retorno;

	retorno = -1;
	if(listaComputadoras != NULL)
	{
		cambiarPath= tp_continuar("Ubicacion de archivo '././datos_SP.csv' Desea cambiar el path de apertura? Y/N");
		if(cambiarPath)
		{
			utn_getAlfaNumerica(path, SIZE_STR, "ingrese nuevo path: ", "ingrese un dato valido", REINTENTOS);

		}
		if(!controller_loadFromText(path,listaComputadoras))
		{
			printf("Archivo cargado correctamente");
		}
		else
		{
			printf("Error de carga");
		}
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
int controller_loadFromText(char* path , LinkedList* listaComputadoras)
{
	FILE* pFile;
	int retorno;
	int retornoFuncion;

	retorno = -1;
	if(path != NULL && listaComputadoras != NULL)
	{
		retorno = -2;
		pFile = fopen(path, "r");
		if(pFile != NULL)
		{
			//printf("load ok\n");
			retornoFuncion=parser_ComputerFromText(pFile, listaComputadoras);
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

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param pFile FILE* recibe el puntero al archivo sobre el cual realizara la operacion
 * \param pArrayListPassenger LinkedList* recibe la lista donde alojara los elementos parseados
 * \return int retorna -1 si no pudo operar.
 * 						0 si no leyo
 * 						>0 si leyo (retorna la cantidad de lineas que leyo)
 *
*/
int parser_ComputerFromText(FILE* pFile , LinkedList* listaComputadoras)
{
	int retorno;
	eComputer* pAuxComputer=NULL;
	char auxId[SIZE_INT];
	char auxDescripcion[SIZE_STR];
	char auxPrecio[SIZE_FLOAT];
	char auxIdTipo[SIZE_INT];
	int i;

	retorno = -1;
	i=0;
	if(pFile != NULL && listaComputadoras != NULL)
	{
		retorno = 0;
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]",auxId, auxDescripcion, auxPrecio, auxIdTipo);
		while(!feof(pFile))
		{
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]",auxId,auxDescripcion, auxPrecio, auxIdTipo);
			pAuxComputer = Computer_newParametrosStringAll(auxId,auxDescripcion, auxPrecio, auxIdTipo);//acá ya tendría un pasajero en la lista de punteros

			if(pAuxComputer != NULL && i<20)
			{
				ll_add(listaComputadoras, (eComputer*)pAuxComputer);//guarda en la lista linkedList cada elementoç
				i++;
			}
		}
		retorno = i;
	}
	return retorno;
}

/** \brief Reserva espacio en el heap para una variable del tipo ePassenger
 *
 * \return ePassenger* retorna NULL si no encontro espacio en heap para crear una variable del tipo ePassenger
 * 					   		   *ePassenger (direccion de memoria al tipo ePassenger) si realizo la operacion correctamente
 *
 */
eComputer* Computer_new(void)
{
	return (eComputer*) malloc(sizeof(eComputer));
}

/** \brief Crea un pasajero en memoria dinamica seteando en sus campos los datos recibidos por parametro (modo texto)
 *
 * \param char* id recibe el valor correspondiente para el campo id
 * \param char* nombre recibe la referencia a la cadena correspondiente para el campo nombre
 * \param char* precio recibe el valor correspondiente al campo precio
 * \param char* codigoVuelo recibe la referencia a la cadena correspondiente para el campo FlyCode
 * \param char* tipoPasajero recibe la referencia a la cadena correspondiente para el campo Tipo Pasajero
 * \param char* estadoVuelo recibe la referencia a la cadena correspondiente para el campo tipo pasajero
 * \return ePassenger* retorna NULL si hubo un error al realizar la operacion
 * 					   		   *ePassenger si logro crear y setear a la variable del tipo estructura(retorna la direccion de memoria en donde se creo al pasajero)
 *
 */
eComputer* Computer_newParametrosStringAll(char* idStr,char* descripcionStr,char* precioStr, char* idTipoStr)
{
	eComputer* this = NULL;
	if(idStr != NULL && descripcionStr != NULL && precioStr != NULL && idTipoStr != NULL)
	{
		this = Computer_new();
		if(this != NULL)
		{
			Computer_setIdStr(this, idStr);
			Computer_setDescripcion(this, descripcionStr);
			Computer_setPriceStr(this, precioStr);
			Computer_setIdTipoStr(this, idTipoStr);
		}
		else
		{
			Computer_delete(this);
		}
	}
	return this;
}

/** \brief elimina de memoria dinamica pasajero recibido por parametros
 *
 * \param ePassenger* this recibe el puntero al elemento sobre el cual se va a realizar la operacion
 * \return int  retorna -1 si hubo un error en los parametros recibidos
 * 						-2 si se cancela la operacion
 * 						0 si elimino correctamente
 *
 */
int Computer_delete(eComputer* this)
{
	int retorno;
	int confirmar;

	retorno = -1;//si hay error en los parametros
	confirmar =0;

	if(this != NULL)
	{
		retorno=-2; // si se cancela la eliminacion
		//printf("pasajero id: %d - nombre: %s\n", this->id, this->nombre);
		confirmar=tp_continuar("confirma la baja del pasajero? (Y/N)");
		if(confirmar)
		{
			free(this);
			retorno=0;// si se borra correctamente
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
int Computer_setIdStr(eComputer* this,char* idStr)
{
	int retorno;
	int auxId;

	retorno =-1;
	if(this != NULL && idStr != NULL && !validaciones_esNumeroInt(idStr, strlen(idStr)))
	{
		auxId = atoi(idStr);
		this->id=auxId;
		retorno=0;
	}
	return retorno;
}

/** \brief recibe un nombre y lo carga en el campo correspondiente. Lo valida, y si no es correcto, ofrece la posibilidad de cargarlo manualmente
 *
 * \param ePassenger* this recibe el puntero al elemento sobre el cual se va a realizar la operacion
 * \param char* nombre recibe la referencia de la cadena a la cual se validara como nombre para setearla en el campo correspondiente
 * \return int  retorna -1 si hubo un error en los parametros recibidos
 * 						0 si realizo la operacion correctamente
 *
 */
int Computer_setDescripcion(eComputer* this,char* descripcion)
{
	int retorno;
	int lenString;
	//int cargaManual;

	lenString=strlen(descripcion);
	retorno =-1;
	if(this != NULL && descripcion != NULL)
	{
		strncpy(this->descripcion, descripcion, lenString);
		retorno=0;
	}
	return retorno;
}

/** \brief recibe una cadena, valida que corresponda al formato precio y lo carga en el campo correspondiente.
 * Lo valida, y si no es correcto, ofrece la posibilidad de cargarlo manualmente
 *
 * \param ePassenger* this recibe el puntero al elemento sobre el cual se va a realizar la operacion
 * \param char* priceStr recibe por referencia la cadena que se validara como precio para setearlo en el campo correspondiente
 * \return int  retorna -1 si hubo un error en los parametros recibidos
 * 						-2 si el dato seteado no pertenece al rango correspondiente
 * 						0 si realizo la operacion correctamente
 *
 */
int Computer_setPrice(eComputer* this,float price)
{
	int retorno;
	//float auxPrecio;
	//int cargaManual;

	retorno =-1;
	if(this != NULL )
	{
		this->precio=price;
		retorno=0;
		/*if(auxPrecio < MIN_PRICE)
		{
			retorno = -2;
			printf("\n[DEBUG] ***WARNING*** el precio recibido esta fuera de los parametros esperados para un precio. Valor: %.2f\n", auxPrecio);
			//cargaManual= tp_continuar("Desea cargar manualmente? Y/N");
			if(cargaManual)
			{
				parser_getPriceToBuffer(&auxPrecio);
			}
		}*/
	}
	return retorno;
}

/** \brief recibe una cadena, valida que corresponda al formato precio y lo carga en el campo correspondiente.
 * Lo valida, y si no es correcto, ofrece la posibilidad de cargarlo manualmente
 *
 * \param ePassenger* this recibe el puntero al elemento sobre el cual se va a realizar la operacion
 * \param char* priceStr recibe por referencia la cadena que se validara como precio para setearlo en el campo correspondiente
 * \return int  retorna -1 si hubo un error en los parametros recibidos
 * 						-2 si el dato seteado no pertenece al rango correspondiente
 * 						0 si realizo la operacion correctamente
 *
 */
int Computer_setPriceStr(eComputer* this,char* priceStr)
{
	int retorno;
	float auxPrecio;
	//int cargaManual;

	retorno =-1;
	if(this != NULL && priceStr != NULL && validaciones_esNumeroFlotante(priceStr, strlen(priceStr)))
	{
		auxPrecio = atof(priceStr);
		this->precio=auxPrecio;
		retorno=0;
		/*if(auxPrecio < MIN_PRICE)
		{
			retorno = -2;
			printf("\n[DEBUG] ***WARNING*** el precio recibido esta fuera de los parametros esperados para un precio. Valor: %.2f\n", auxPrecio);
			//cargaManual= tp_continuar("Desea cargar manualmente? Y/N");
			if(cargaManual)
			{
				parser_getPriceToBuffer(&auxPrecio);
			}
		}*/
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
int Computer_setIdTipoStr(eComputer* this,char* idStr)
{
	int retorno;
	int auxIdTipo;

	retorno =-1;
	if(this != NULL && idStr != NULL && !validaciones_esNumeroInt(idStr, strlen(idStr)))
	{
		auxIdTipo = atoi(idStr);
		this->idTipo=auxIdTipo;
		retorno=0;
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
int controller_sortComputer(LinkedList* listaComputadoras)
{
	int retorno;
	//int opcionIngresada;
	int tipoOrden;
	LinkedList* pAuxLista = NULL;

	retorno = -1;
	if(listaComputadoras!= NULL)
	{
		pAuxLista = ll_clone(listaComputadoras);
		//tipoOrden= tp_continuar("Ordenar ID de forma decreciente? Y/N");
		printf("ordenando...\n");
		ll_sort(pAuxLista, Computer_compareByIdTipo, 1);
	}
	tipoOrden= tp_continuar("ORDENADO\nDesea imprimir la lista ordenada? Y/N");
	if(tipoOrden)
	{
		controller_ListComputer(pAuxLista);
	}
	retorno =0;
    return retorno;
}

/** \brief Listar pasajeros
 *
 * \param pArrayListPassenger LinkedList* Recibe la direccion de memoria del primer elemento del array de punteros a memoria dinamica
 * \param int controlOrden bandera para controlar si la lista ha sido desordenada
 * \return int -1 si hubo un error
 * 				0 si opero exitosamente
 *
 */
int controller_ListComputer(LinkedList* listaComputadoras)
{
	int retorno;
	int i;
	eComputer* pAuxComputer = NULL;
	int lenArray;

	retorno =-1;
	if(listaComputadoras!= NULL)
	{
		lenArray = ll_len(listaComputadoras);
		/*if(!controlOrden)
		{
			printf("leyendo Datos... \n");
			ll_sort(pArrayListPassenger, Passenger_compareById, 1);
		}*/
		//Passenger_printEncabezado();
		for(i=0; i<lenArray; i++)
		{
			pAuxComputer = ll_get(listaComputadoras, i);
			Computer_printComputer(pAuxComputer);
		}
		retorno =0;
	}
    return retorno;
}

/** \brief recibe un pasajero e imprime los datos de sus campos
 *
 * \param ePassenger* this recibe el puntero al elemento sobre el cual se va a realizar la operacion
 * \return int  retorna -1 si hubo un error en los parametros recibidos
 * 						0 si opero correctamente
 *
 */
int Computer_printComputer(eComputer* this)
{
	int retorno;
	char auxTipo[SIZE_STR];
	int id;
	char descripcion[SIZE_STR];
	float precio;
	int idTipo;
	retorno=-1;
	if(this != NULL)
	{
		Computer_getDatosDeComputadora(this, &id,descripcion,&precio, &idTipo);

		if(idTipo == 1)
		{
			strncpy(auxTipo, "DESKTOP", SIZE_STR);
		}
		else
		{
			strncpy(auxTipo, "LAPTOP", SIZE_STR);
		}
		printf("%d $%8.2f %10s %15s\n",id,precio,auxTipo,descripcion);
		retorno =0;
	}
	return retorno;
}

/** \brief recibe dos elementos y los compara segun el campo precio
 *
 * \param ePassenger* this recibe el puntero al elemento que se comparara
 * \param ePassenger* that recibe el puntero al elemento contra el cual se comparara
 * \return int retorna -1 si el primer elemento es menor que el segundo
 * 						0 si son iguales
 * 						1 si el primer elemento es mayor que el segundo
 *
 */
int Computer_compareByIdTipo(void* this, void* that)
{
	int comparacion;
	eComputer* pCompu1;
	eComputer* pCompu2;
	int idTipo1;
	int idTipo2;
	comparacion =-1;
	if(this != NULL && that != NULL)
	{
		pCompu1 = (eComputer*) this;
		pCompu2 = (eComputer*) that;

		idTipo1=Computer_getIdTipo(pCompu1);
		idTipo2=Computer_getIdTipo(pCompu2);

		if(idTipo1 < idTipo2)
		{
			comparacion = -1;
		}
		if(idTipo1 > idTipo2)
		{
			comparacion = 1;
		}
	}
	return comparacion;
}

int controller_funcionMap(LinkedList* listaComputadoras)
{
	int retorno;
	LinkedList* pAuxLista = NULL;
	int respuesta;

	retorno = -1;
	if(listaComputadoras != NULL)
	{
		pAuxLista = ll_clone(listaComputadoras);
		printf("Calculando aumentos....  ");
		ll_map(pAuxLista, Computer_incrementarPrecio);
		retorno =0;
	}
	respuesta= tp_continuar("ORDENADO\nDesea imprimir la lista con los nuevos precios? Y/N");
	if(respuesta)
	{
		controller_ListComputer(pAuxLista);
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
int controller_optionsToSaveCsv(LinkedList* listaComputadoras)
{
	int cambiarPath;
	char path[SIZE_STR]="mapeado.csv";
	int retorno;

	retorno = -1;
	if(listaComputadoras != NULL)
	{
		cambiarPath= tp_continuar("Se guardarán los cambios en la ubicacion de archivo './mapeado.csv' Desea guardar en otro path? Y/N");
		if(cambiarPath)
		{
			utn_getAlfaNumerica(path, SIZE_STR, "ingrese nuevo path: ", "ingrese un dato valido", REINTENTOS);
		}
		controller_saveAsText(path,listaComputadoras);
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
int controller_saveAsText(char* path , LinkedList* listaComputadoras)
{
	FILE* pFile;
	int retorno;
	retorno = -1;

	if(path != NULL && listaComputadoras != NULL)
	{
		pFile = fopen(path, "w");
		if(pFile != NULL)
		{
			parser_TextFromComputer(pFile, listaComputadoras);
			fclose(pFile);
			retorno = 0;
			printf("Los cambios se han guardado correctamente\n");
		}
		else
		{
			printf("[ERROR] No se ha crear el archivo");
			retorno = -2;
		}
	}
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
int parser_TextFromComputer(FILE* pFile, LinkedList* listaComputadoras)
{
	int retorno;
	int lenPArray;
	eComputer* this;
	int i;
	int auxId;
	char auxDescripcion[SIZE_STR];
	float auxPrecio;
	int auxIdTipo;

	retorno = -1;

	if(pFile!= NULL && listaComputadoras != NULL)
	{
		retorno = 0;
		lenPArray = ll_len(listaComputadoras);
		if(lenPArray >0)
		{
			for(i=0; i<lenPArray; i++)
			{
				this=ll_get(listaComputadoras, i);
				Computer_getDatosDeComputadora(this, &auxId, auxDescripcion, &auxPrecio, &auxIdTipo);
				fprintf(pFile, "%d,%s,%.2f,%d\n", auxId, auxDescripcion, auxPrecio, auxIdTipo);
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

/** \brief recibe un pasajero y devuelve por referencia los datos obtenidos de sus campos
 *
 * \param int* id recibe un espacio de memoria donde alojar el contenido del campo ID
 * \param char* nombre recibe la referencia donde alojar la cadena correspondiente al campo nombre
 * \param char* apellido recibe la referencia donde alojar la cadena correspondiente al campo apellido
 * \param float* precio  recibe un espacio de memoria donde alojar el contenido del campo precio
 * \param char* codigoVuelo recibe la referencia donde alojar la cadena correspondiente al campo FlyCode
 * \param char* tipoPasajero recibe la referencia donde alojar la cadena correspondiente al campo Tipo Pasajero
 * \param char* estadoVuelo recibe la referencia donde alojar la cadena correspondiente al campo estado de Vuelo
 *
 * \return int  retorna -1 si hubo un error en los parametros recibidos
 * 						0 si realizo la operacion correctamente
 *
 */
int Computer_getDatosDeComputadora(eComputer* this, int* id,char* descripcion,float* precio, int* idTipo)
{
	int retorno;

	retorno = -1;
	if(this!= NULL && id!= NULL && descripcion != NULL && precio!= NULL  && idTipo)
	{
		retorno = 0;
		*id = Computer_getId(this);
		Computer_getDescripcion(this, descripcion);
		*precio= Computer_getPrecio(this);
		*idTipo = Computer_getIdTipo(this);
	}

	return retorno;
}

/** \brief analiza un elemento del tipo ePassenger y devuelve por referencia el dato alojado en el campo id
 *
 * \param ePassenger* this recibe el puntero al elemento sobre el cual se va a realizar la operacion
 * \return int  retorna -1 si hubo un error en los parametros recibidos
 * 						>0 si realizo la operacion correctamente (retorna el id correspondiente)
 *
 */
int Computer_getId(eComputer* this)
{
	int retorno;
	retorno =-1;
	if(this!= NULL)
	{
		retorno =this->id;
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
int Computer_getDescripcion(eComputer* this,char* descripcion)
{
	int retorno;
	retorno =-1;
	if(this!= NULL && descripcion != NULL)
	{
		strcpy(descripcion, this->descripcion);
		retorno =0;
	}
	return retorno;
}

/** \brief analiza un elemento del tipo ePassenger y devuelve por referencia el dato alojado en el campo id
 *
 * \param ePassenger* this recibe el puntero al elemento sobre el cual se va a realizar la operacion
 * \return int  retorna -1 si hubo un error en los parametros recibidos
 * 						>0 si realizo la operacion correctamente (retorna el id correspondiente)
 *
 */
float Computer_getPrecio(eComputer* this)
{
	float retorno;
	retorno =-1;
	if(this!= NULL)
	{
		retorno =this->precio;
	}
	return retorno;
}

/** \brief analiza un elemento del tipo ePassenger y devuelve por referencia el dato alojado en el campo id
 *
 * \param ePassenger* this recibe el puntero al elemento sobre el cual se va a realizar la operacion
 * \return int  retorna -1 si hubo un error en los parametros recibidos
 * 						>0 si realizo la operacion correctamente (retorna el id correspondiente)
 *
 */
int Computer_getIdTipo(eComputer* this)
{
	int retorno;
	retorno =-1;
	if(this!= NULL)
	{
		retorno =this->idTipo;
	}
	return retorno;
}

int Computer_incrementarPrecio(void* this)
{
	int retorno;
	float precio;
	int idTipo;
	float auxPrecio;

	retorno = -1;
	if(this != NULL )
	{
		precio = Computer_getPrecio(this);
		idTipo = Computer_getIdTipo(this);
		auxPrecio = 0;
		switch(idTipo)
		{
			case 1:
				auxPrecio = tp_calcularTotalConInteres(precio, 10);
				break;

			case 2:
				auxPrecio = tp_calcularTotalConInteres(precio, 20);
				break;
		}
		if(auxPrecio>precio)
		{
			Computer_setPrice(this, auxPrecio);
			retorno = 0;
		}
	}
	return retorno;
}

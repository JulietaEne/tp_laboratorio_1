/*
 * Passenger.h
 *
 *  Created on: 2419 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "src/validaciones.h"
#include "src/tp.h"

#include "src/arrays.h"
//#include "parser.h"

#define ID_MAX 2100
#define ID_MIN 1001
#define FILE_ID_MIN 1
#define ID_INIT -1
#define PASS_TYPE_MIN 1
#define PASS_TYPE_MAX 5
#define SIZE_STR 50
#define SIZE_INT 6
#define MAX_PRICE 50000
#define MIN_PRICE 5000
#define INIT_PRICE 0
#define REINTENTOS 10

typedef struct
{
	int id;
	char nombre[SIZE_STR];
	char apellido[SIZE_STR];
	float precio;
	char flyCode[SIZE_STR];
	char tipoPasajero[SIZE_STR];//este estaba en int pero en el archivo es un texto
	char estadoVuelo[SIZE_STR];
	//int isEmpty;

}ePassenger;

ePassenger* Passenger_new();
ePassenger* Passenger_newParametrosStringAll(char* idStr,char* nombreStr,char* apellidoStr, char* precioStr, char* codigoVueloStr, char* tipoPasajeroStr, char* estadoVueloStr);
ePassenger* Passenger_newParametrosAllBinary(int id,char* nombre,char* apellido, float precio, char* codigoVuelo, char* tipoPasajero, char* estadoVuelo);
ePassenger* Passenger_newParametrosAll(int id,char* nombre,char* apellido, float precio, char* codigoVuelo, char* tipoPasajero, char* estadoVuelo, int controlLista);

ePassenger* Passenger_findIndexById(ePassenger* this, int idBusqueda);
int passenger_delete(ePassenger* this);
int Passenger_printPasajero(ePassenger* this);
void Passenger_printEncabezado(void);
void Passenger_printMensajeConId(char* mensaje,  ePassenger* pAuxPasajero);

int Passenger_setId(ePassenger* this,int id, int controlLista);
int Passenger_setIdBinary(ePassenger* this,int idStr);
int Passenger_setIdStr(ePassenger* this,char* idStr);
int Passenger_setNombre(ePassenger* this,char* nombre);
int Passenger_setLastName(ePassenger* this,char* apellidoStr);
int Passenger_setPrecio(ePassenger* this,float precio);
int Passenger_setPriceStr(ePassenger* this,char* priceStr);
int Passenger_setCodigoVuelo(ePassenger* this,char* codigoVuelo);
int Passenger_setStatusFlight(ePassenger* this,char*estadoVueloStr);
int Passenger_setTipoPasajero(ePassenger* this,char* tipoPasajero);

int Passenger_getDatosDePasajero(ePassenger* this, int* id,char* nombre,char* apellido,float* precio, char* codigoVuelo, char* tipoPasajero,char* estadoVuelo);
int Passenger_getId(ePassenger* this);
int Passenger_getNombre(ePassenger* this,char* nombre);
int Passenger_getApellido(ePassenger* this,char* apellido);
int Passenger_getCodigoVuelo(ePassenger* this,char* codigoVuelo);
float Passenger_getPrice(ePassenger* this);
int Passenger_getTipoPasajero(ePassenger* this,char* tipoPasajero);
int Passenger_getEstadoVuelo(ePassenger* this,char* estadoVuelo);

int Passenger_compareById(void* this, void* that);
int Passenger_comparePrice(void* this, void* that);
int Passenger_compareByName(void* this, void* that);



#endif /* PASSENGER_H_ */

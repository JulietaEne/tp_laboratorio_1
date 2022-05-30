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
#include "Passenger.h"

#define ID_MAX 1100
#define ID_MIN 1
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
ePassenger* Passenger_newParametrosString(char* idStr,char* nombreStr,char* tipoPasajeroStr);
ePassenger* Passenger_newParametrosStringAll(char* idStr,char* nombreStr,char* apellidoStr, char* precioStr, char* codigoVueloStr, char* tipoPasajeroStr, char* estadoVueloStr);
ePassenger* Passenger_newParametros(int id,char* nombre,char* tipoPasajero);
int Passenger_getDatosDePasajero(ePassenger* this, int* id, char* nombre, char* typePasajero);
int passenger_delete(ePassenger* this);
int Passenger_initPasajero(ePassenger* this);
int Passenger_printPasajero(ePassenger* this);
void Passenger_printEncabezado();


int Passenger_setId(ePassenger* this,int id);
int Passenger_setIdStr(ePassenger* this,char* idStr);
int Passenger_getId(ePassenger* this/*,int* id*/);



int Passenger_setNombre(ePassenger* this,char* nombre);
int Passenger_getNombre(ePassenger* this,char* nombre);

int Passenger_setApellido(ePassenger* this,char* apellido);
int Passenger_setPrecio(ePassenger* this,float precio);
int Passenger_setCodigoVuelo(ePassenger* this,char* codigoVuelo);
int Passenger_setEstadoVuelo(ePassenger* this,char* estadoVuelo);

int Passenger_setApellido(ePassenger* this,char* apellido);
int Passenger_getApellido(ePassenger* this,char* apellido);

int Passenger_setCodigoVuelo(ePassenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(ePassenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(ePassenger* this,char* tipoPasajero);
//int Passenger_setTipoPasajeroStr(ePassenger* this,char* tipoPasajero);
int Passenger_getTipoPasajero(ePassenger* this,char* tipoPasajero);

int Passenger_setPrecio(ePassenger* this,float precio);
int Passenger_getPrecio(ePassenger* this,float* precio);

int Passenger_setPrice(ePassenger* this,char* priceStr);
int Passenger_setStatusFlight(ePassenger* this,char*estadoVueloStr);
int Passenger_setLastName(ePassenger* this,char* apellidoStr);

ePassenger* Passenger_findIndexById(ePassenger* this, int idBusqueda);









#endif /* PASSENGER_H_ */

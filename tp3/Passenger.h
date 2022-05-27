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

#define ID_MAX 1
#define ID_MIN 1100
#define PASS_TYPE_MIN 1
#define PASS_TYPE_MAX 5

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char tipoPasajero[50];//este estaba en int pero en el archivo es un texto
	char codigoVuelo[4];
	int isEmpty;

}ePassenger;

ePassenger* Passenger_new();
ePassenger* Passenger_newParametrosString(char* idStr,char* nombreStr,char* tipoPasajeroStr);
ePassenger* Passenger_newParametros(int* id,char* nombre,char* tipoPasajero);
int Passenger_getDatosDePasajero(ePassenger* this, int* id, char* nombre, char* typePasajero);
void Passenger_delete();

int Passenger_setId(ePassenger* this,int id);
int Passenger_setIdStr(ePassenger* this,char* idStr);
int Passenger_getId(ePassenger* this/*,int* id*/);


int Passenger_setNombre(ePassenger* this,char* nombre);
int Passenger_getNombre(ePassenger* this,char* nombre);

int Passenger_setApellido(ePassenger* this,char* apellido);
int Passenger_getApellido(ePassenger* this,char* apellido);

int Passenger_setCodigoVuelo(ePassenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(ePassenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(ePassenger* this,char* tipoPasajero);
//int Passenger_setTipoPasajeroStr(ePassenger* this,char* tipoPasajero);
int Passenger_getTipoPasajero(ePassenger* this,char* tipoPasajero);

int Passenger_setPrecio(ePassenger* this,float precio);
int Passenger_getPrecio(ePassenger* this,float* precio);










#endif /* PASSENGER_H_ */

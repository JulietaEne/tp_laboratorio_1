/*
 * passenger.h
 *
 *  Created on: 23 abr. 2022
 *      Author: juliet
 */

#ifndef PASSENGER_H_

struct
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int isEmpty;
}typedef Passenger;

#define REINTENTOS 2
#define MAX_PRECIO 200000
#define MIN_PRECIO 10000
#define MIN_ESTADO_VUELO 0
#define MAX_ESTADO_VUELO 3
#define IS_EMPTY 0


int pass_initArray(Passenger* listPass, int sizeListPass);
int passenger_initAPossition(Passenger* listPass, int indice, int valorInicial);
int pass_printArray(Passenger* listPass, int sizeListPass);
int passenger_printOneIndice(Passenger* listPass, int indice);
int pass_pedirNombre(char* nombre, int sizeNombre);
int pass_pedirApellido(char* apellido, int sizeApellido);
float pass_pedirPrecio(float* precio);
int pass_pedirCodigoVuelo(char* codigoVuelo, int sizeCodigoVuelo);
int pass_pedirEstadoVuelo(int* estadoVuelo);
int pass_pedirTipoPasajero(int* tipoPasajero);



#define PASSENGER_H_

#endif /* PASSENGER_H_ */

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
	int statusFlight;
	int isEmpty;
}typedef Passenger;

#define REINTENTOS 2
#define MAX_PRECIO 200000
#define MIN_PRECIO 10000
#define MIN_ESTADO_VUELO 0
#define MAX_ESTADO_VUELO 3
#define IS_EMPTY 0


int pass_initArray(Passenger* listPass, int sizeListPass);
int pass_initAPossition(Passenger* listPass, int indice, int valorInicial);
int pass_printArray(Passenger* listPass, int sizeListPass);
int pass_printOneIndice(Passenger* listPass, int indice);
void pass_printRotulo(void);

int pass_pedirNuevoPasajero(Passenger* listPass, int sizePass, int ultimoId);
int pass_encontrarPrimerIndiceIsEmpty(Passenger* listPass, int sizePass);
int pass_agregarPasajeroAlArray(Passenger* listPass, int sizePass, int ultimoId, char* nombre, char* apellido, float precio, char* codigoVuelo, int tipoPasajero, int estadoVuelo);

int pass_cambiarNombre(Passenger* listPass, int idCambio);
int pass_cambiarApellido(Passenger* listPass, int idCambio);
int pass_cambiarPrecio(Passenger* listPass, int idCambio);
int pass_cambiarTipoPasajero(Passenger* listPass, int idCambio);
int pass_cambiarCodigoVuelo(Passenger* listPass, int idCambio);

int pass_pedirNombre(char* nombre, int sizeNombre);
int pass_pedirApellido(char* apellido, int sizeApellido);
float pass_pedirPrecio(float* precio);
int pass_pedirCodigoVuelo(char* codigoVuelo, int sizeCodigoVuelo);
int pass_pedirEstadoVuelo(int* estadoVuelo);
int pass_pedirTipoPasajero(int* tipoPasajero);

int pass_pedirIdConsulta(int idUltimo);
int pass_encontrarPasajeroPorId(Passenger* listPass, int sizePass, int idConsulta);

int pass_removerSegunId(Passenger* arrayPasajeros, int indexIdConsulta);



#define PASSENGER_H_

#endif /* PASSENGER_H_ */

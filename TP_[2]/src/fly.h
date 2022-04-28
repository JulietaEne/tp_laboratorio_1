/*
 * fly.h
 *
 *  Created on: 27 abr. 2022
 *      Author: julieta_enee
 */

#ifndef FLY_H_
struct
{
	int idFly;
	char flycode[10];
	float price;
	int statusFlight;
	int isEmpty;
}typedef Fly;

int pass_mostrarListadoCodigosVuelo(Passenger* listPass, int sizeArray);

int pass_ordenarArrayPorCodigo(Passenger* listPass, int sizeArray, int criterio);//sortPassengersByCode

#define FLY_H_



#endif /* FLY_H_ */

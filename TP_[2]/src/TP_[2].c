/*
 ============================================================================
 Name        : TP_[2].c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Nakasone Julieta
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "passenger.h"
#include "utn.h"
#include "arrays.h"

#define ID_INICIAL 100
#define QTY_PASS 10

int main(void) {

	//int idUltimo;
	Passenger arrayPasajeros[QTY_PASS];

	//pass_printArray(arrayPasajeros, QTY_PASS);
	if(!pass_initArray(arrayPasajeros, QTY_PASS))
	{
		pass_printArray(arrayPasajeros, QTY_PASS);
		printf("inicializamos!");
	}


	//idUltimo = ID_INICIAL;


}

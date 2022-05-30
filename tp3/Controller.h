/*
 * Controller.h
 *
 *  Created on: 24 may. 2022
 *
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"

#include "src/tp.h"



int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);
int controller_addPassenger(LinkedList* pArrayListPassenger);
int controller_findLastIdValue(LinkedList* pArrayListPassenger);

int controller_editPassenger(LinkedList* pArrayListPassenger);
int controller_removePassenger(LinkedList* pArrayListPassenger);
int controller_ListPassenger(LinkedList* pArrayListPassenger);
int controller_sortPassenger(LinkedList* pArrayListPassenger);
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);
/*
int controller_getIdToBuffer(int* id, LinkedList* pArrayListPassenger);
int controller_getNameToBuffer(char* name, int lenName);
int controller_getLastNameToBuffer(char* lastName, int lenLastame);
int controller_getPriceToBuffer(float* price);
int controller_getFlyCodeToBuffer(char* flyCode, int lenFlyCode);
int controller_getStatusFlightToBuffer(char* statusFlight, int lenStatusFlight);
int controller_getTypePassToBuffer(char* typePass, int lenName);*/

ePassenger* controller_findIndexById(LinkedList* pArrayListPassenger, int* idIngresado, int* indexHallado);
int controller_chooseCampToEdit(ePassenger* pPasajero, int idPasajero);

//int controller_findIndexById(LinkedList* pArrayListPassenger, ePassenger** pPassengerHallado, int idIngresado);

#endif /* PARSER_H_ */

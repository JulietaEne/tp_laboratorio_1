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


int controller_optionsToOpenCsv(LinkedList* pArrayListPassenger);
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);
int controller_optionsToOpenBin(LinkedList* pArrayListPassenger);
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);

int controller_addPassenger(LinkedList* pArrayListPassenger, int controlPasajeros);

int controller_editPassenger(LinkedList* pArrayListPassenger);
int controller_chooseCampToEdit(ePassenger* pPasajero, int idPasajero);

int controller_removePassenger(LinkedList* pArrayListPassenger);

int controller_ListPassenger(LinkedList* pArrayListPassenger, int controlOrden);
int controller_sortPassenger(LinkedList* pArrayListPassenger);

int controller_optionsToSaveCsv(LinkedList* pArrayListPassenger);
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);
int controller_optionsToSaveBin(LinkedList* pArrayListPassenger);
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);

void controller_askToViewList(LinkedList* pArrayListPassenger);

#endif /* PARSER_H_ */

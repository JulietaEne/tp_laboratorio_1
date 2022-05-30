/*
 * parser.h
 *
 *  Created on: 24 may. 2022
 *      Author: julieta_enee
 */

#ifndef PARSER_H_
#define PARSER_H_



#include "LinkedList.h"
#include "src/utn.h"
#include "Controller.h"

int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger);
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger);
int parser_BinaryFromPassenger(FILE* pFile , LinkedList* pArrayListPassenger);
int parser_TextFromPassenger(FILE* pFile, LinkedList* pArrayListPassenger);
int parser_passengerFromBuffer(LinkedList* pArrayListPassenger);

int parser_getNameToBuffer(char* name, int lenName);
int parser_getLastNameToBuffer(char* lastName, int lenLastame);
int parser_getPriceToBuffer(float* price);
int parser_getFlyCodeToBuffer(char* flyCode, int lenFlyCode);
int parser_getStatusFlightToBuffer(char* statusFlight, int lenStatusFlight);
int parser_getTypePassToBuffer(char* typePass, int lenName);

int parser_passengerToEdit(LinkedList* pArrayListPassenger);
int parser_passengerToDelete(LinkedList* pArrayListPassenger);




#endif /* PARSER_H_ */

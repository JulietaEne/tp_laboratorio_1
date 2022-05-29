/*
 * parser.h
 *
 *  Created on: 24 may. 2022
 *      Author: julieta_enee
 */

#ifndef PARSER_H_
#define PARSER_H_



#include "LinkedList.h"

int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger);
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger);
int parser_BinaryFromPassenger(FILE* pFile , LinkedList* pArrayListPassenger);
int parser_TextFromPassenger(FILE* pFile, LinkedList* pArrayListPassenger);


#endif /* PARSER_H_ */

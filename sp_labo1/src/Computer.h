/*
 * Controller.h
 *
 *  Created on: 28 jun. 2022
 *      Author: julieta_enee
 */

#ifndef SRC_COMPUTER_H_
#define SRC_COMPUTER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "tp.h"
#include "arrays.h"
#include "../inc/LinkedList.h"

#define SIZE_STR 150
#define SIZE_INT 5
#define SIZE_FLOAT 8
#define REINTENTOS 1
#define MIN_PRICE 1000
#define MAX_PRICE 10000000

typedef struct
{
	int id;
	char descripcion[SIZE_STR];
	float precio;
	int idTipo;

}eComputer;


int controller_optionsToOpenCsv(LinkedList* listaComputadoras);
int controller_loadFromText(char* path , LinkedList* listaComputadoras);
int parser_ComputerFromText(FILE* pFile , LinkedList* listaComputadoras);
eComputer* Computer_new(void);
eComputer* Computer_newParametrosStringAll(char* idStr,char* descripcionStr,char* precioStr, char* idTipoStr);
int Computer_delete(eComputer* this);
int Computer_setIdStr(eComputer* this,char* idStr);
int Computer_setDescripcion(eComputer* this,char* descripcion);
int Computer_setPrice(eComputer* this,float price);
int Computer_setPriceStr(eComputer* this,char* priceStr);
int Computer_setIdTipoStr(eComputer* this,char* idStr);
int controller_sortComputer(LinkedList* listaComputadoras);
int controller_ListComputer(LinkedList* listaComputadoras);
int Computer_printComputer(eComputer* this);
int Computer_compareByIdTipo(void* elemento1, void* elemento2);
int Computer_getIdTipo(eComputer* this);
//int controller_ListComputer(void);
int controller_funcionMap(LinkedList* listaComputadoras);
int controller_optionsToSaveCsv(LinkedList* listaComputadoras);
int controller_saveAsText(char* path , LinkedList* listaComputadoras);
int parser_TextFromComputer(FILE* pFile, LinkedList* listaComputadoras);
int Computer_getDatosDeComputadora(eComputer* this, int* id,char* descripcion,float* precio, int* idTipo);
int Computer_getId(eComputer* this);
int Computer_getDescripcion(eComputer* this,char* descripcion);
float Computer_getPrecio(eComputer* this);
int Computer_getIdTipo(eComputer* this);
int Computer_incrementarPrecio(void* this);

#endif /* SRC_COMPUTER_H_ */

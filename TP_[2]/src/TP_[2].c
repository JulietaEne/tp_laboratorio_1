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
#include "tp.h"

#define ID_INICIAL 100
#define QTY_PASS 10

int main(void) {

	int idUltimo;
	Passenger arrayPasajeros[QTY_PASS];
	int menuPrincipal;
	int clientesCargados;

	idUltimo = ID_INICIAL;
	clientesCargados = -1;
	//pass_printArray(arrayPasajeros, QTY_PASS);
	do{
		menuPrincipal = tp_ImprimirMenuSeisOpciones("MENU", "1- ALTA DE CLIENTE", "2- MODIFICAR CLIENTE", "3- BAJA DE CLIENTE", "4- INFORMES", "5- SALIR", "");
		switch (menuPrincipal)
		{
			case 1:
				printf("ALTA DE CLIENTES");
				if(clientesCargados == -1)
				{
					pass_initArray(arrayPasajeros, QTY_PASS);
					clientesCargados = 0;
					printf("[DEBUG****]inicializamos OK!");
				}
				if(!pass_pedirNuevoPasajero(arrayPasajeros, QTY_PASS, idUltimo))
				{
					idUltimo++;
					clientesCargados++;
					if(continuar("Desea visualizar los clientes cargados? (Y/N)"))
					{
						pass_printArray(arrayPasajeros, QTY_PASS);
					}
				}
				else
				{
					tp_MensajeError("ERROR**** ha habido un error en la carga del cliente");
				}

				break;
			default:
				break;
		}
	}while(menuPrincipal<5);








}
/*
if(!pass_initArray(arrayPasajeros, QTY_PASS))
{
	pass_printArray(arrayPasajeros, QTY_PASS);
	printf("inicializamos!");
}
if(!pass_pedirNuevoPasajero(arrayPasajeros, QTY_PASS, idUltimo))
{
	idUltimo ++;
	pass_printArray(arrayPasajeros, QTY_PASS);
}*/

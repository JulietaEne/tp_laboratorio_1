/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    Instancia Segundo Parcial Laboratorio 1

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "validaciones.h"
#include "tp.h"
#include "arrays.h"
#include "Computer.h"

int main(void)
{
	LinkedList* listaComputadoras = ll_newLinkedList();
	int option;
	int control;

	control = 0;
	do{
		option = tp_ImprimirMenuDiezOpciones("\n[MENU]\n", "1- Abrir archivo csv"
														, "2- Ordenar por idTipo"
														, "3- Imprimir lista original"
														, "4- Funcion ll_map"
														, "5- Guardar archivo 'mapeado.csv'"
														, "6- Salir"
														, " "
														, " "
														, " "
														, " ");
		switch(option)
		{
			case 1:
				if(!controller_optionsToOpenCsv(listaComputadoras))
				{
					printf("\n\nCargado\n");
					control = 1;
				}
				else
				{
					printf("\n\nATENCION Imposible abrir archivo. Hay un archivo de datos en ejecucion");
				}
				break;

			case 2:
				// ordenar empleados
				if(control)
				{
					controller_sortComputer(listaComputadoras);
				}
				else
				{
					printf("[AVISO]Es necesario cargar datos antes de ingresar a ordenar \n");
				}
				break;

			case 3:
				printf("LISTA DE COMPUTADORAS\n");
				if(control)
				{
					controller_ListComputer(listaComputadoras);
				}
				else
				{
					printf("[AVISO]Es necesario cargar datos antes de ingresar a la lista \n");
				}
				break;
			case 4:
				printf("FUNCION MAPEAR\n");
				if(control)
				{
					controller_funcionMap(listaComputadoras);
				}
				else
				{
					printf("[AVISO]Es necesario cargar pasajeros antes de ingresar a la listar pasajeros\n");
				}
				break;
			case 5:
				printf("GUARDAR ARCHIVO\n");
				if(control)
				{
					controller_optionsToSaveCsv(listaComputadoras);
				}
				else
				{
					printf("[AVISO]Es necesario cargar datos antes de guardar\n");
				}
				break;
			case 6:
				printf("Gracias, Julieta\n");
				break;
		}
	}while(option != 6);

    return 0;
}


































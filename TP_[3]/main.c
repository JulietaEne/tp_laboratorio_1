#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "src/tp.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/




int main()
{
		int option = 0;


		LinkedList* listaPasajeros = ll_newLinkedList();
		int controlGuardado;
		int controlPasajeros;
		int controlListaOrdenada;
		int controlPasajeroCargado;
		controlGuardado = 0;
		controlPasajeros=0;
		controlListaOrdenada = 1;
		controlPasajeroCargado =0;

		do{
				option = tp_ImprimirMenuDiezOpciones("\n[MENU]\n", "1- Abrir archivo de texto"
																, "2- Abrir archivo binario"
																, "3- Dar de alta pasajero"
																, "4- Modificar pasajero"
																, "5- Dar de baja pasajero"
																, "6- Listar pasajeros"
																, "7- Ordenar pasajeros"
																, "8- Guardar en archivo .csv"
																, "9- Guardar en archivo binario"
																, "10- Salir del programa");
			switch(option)
			{
				case 1:

					if(!controlPasajeros && !controller_optionsToOpenCsv(listaPasajeros))
					{
						controlPasajeros=1;
					}
					else
					{
						printf("\n\nATENCION Imposible abrir archivo. Hay un archivo de datos en ejecucion");
					}
					break;
			    case 2:
					//cargar desde archivo binario
					if(!controlPasajeros && !controller_optionsToOpenBin(listaPasajeros))
					{
						controlPasajeros=1;
					}
					else
					{
						printf("\n\nATENCION Imposible abrir archivo. Hay un archivo de datos en ejecucion");
					}
					break;
				case 3:
					// alta de pasajero
					if(!controller_addPassenger(listaPasajeros, controlPasajeroCargado))
					{
						controlPasajeroCargado++;
					}
					break;
				case 4:
					printf("MODIFICAR PASAJERO\n");
					if(controlPasajeros)
					{
						controller_editPassenger(listaPasajeros);
					}
					else
					{
						printf("[AVISO]Es necesario cargar pasajeros antes de ingresar a la operacion modificar\n");
					}
					break;
				case 5:
					printf("DAR DE BAJA PASAJERO\n");
					if(controlPasajeros)
					{
						controller_removePassenger(listaPasajeros);
					}
					else
					{
						printf("[AVISO]Es necesario cargar pasajeros antes de ingresar a la operacion dar de baja\n");
					}
					break;
				case 6:
					printf("LISTA DE PASAJEROS\n");
					if(controlPasajeros)
					{
						controller_ListPassenger(listaPasajeros, controlListaOrdenada);
					}
					else
					{
						printf("[AVISO]Es necesario cargar pasajeros antes de ingresar a la listar pasajeros\n");
					}
					break;
				case 7:
					// ordenar empleados
					if(controlPasajeros)
					{
						controller_sortPassenger(listaPasajeros);
						controlListaOrdenada=0;
					}
					else
					{
						printf("[AVISO]Es necesario cargar pasajeros antes de ingresar a la listar pasajeros\n");
					}
					break;
				case 8:
					//guardar en modo texto
					if(controlPasajeros)
					{
						printf("guardando archivo data-procesado.scv.....");
						controller_optionsToSaveCsv(listaPasajeros);
						controlGuardado = 1;
					}
					else
					{
						printf("[ERROR]No hay pasajeros para guardar\n");
					}
					break;
				case 9:
					//guardar en modo binario
					if(controlPasajeros)
					{
						printf("guardando archivo extension data-procesado.bin.....");
						controller_optionsToSaveBin(listaPasajeros);
						controlGuardado = 1;
					}
					else
					{
						printf("[ERROR]No hay pasajeros para guardar\n");
					}
					break;
				case 10:
					if(controlGuardado!= 0)
					{
						printf("cerrando el programa.......");
					}
					else
					{
						printf("[ERROR] debe guardar los cambios para poder salir");
						option=0;
					}
			}
		}while(option != 10  || controlGuardado==0);//cuando control guardado es falso, no deberia salir :(
		printf("\nHa salido correctamente");
	return EXIT_SUCCESS;
}


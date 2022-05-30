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
		//int retornoFuncion;

		LinkedList* listaPasajeros = ll_newLinkedList();
		int controlGuardado;
		controlGuardado = 0;



		do{
				option = tp_ImprimirMenuDiezOpciones("\n[MENU]\n", "1- Abrir archivo de texto"
															, "2- Abrir archivo binario"
															, "3- Dar de alta pasajero"
															, "4- Modificar pasajero"
															, "5- Dar de baja pasajero"
															, "6- Listar pasajeros"
															, "7- Ordenar pasajeros (por nombre)"
															, "8- Guardar en archivo .csv"
															, "9- Guardar en archivo binario"
															, "10- Salir del programa");
			switch(option)
			{
				case 1:
					printf("abriendo archivo data.csv....");
					controller_loadFromText("data.csv",listaPasajeros);
					break;
			    case 2:
					//cargar desde archivo binario
			    	printf("abriendo archivo data-procesado.bin....\n");
					controller_loadFromBinary("data-procesado.bin", listaPasajeros);
					break;
				case 3:
					// alta de pasajero
					controller_addPassenger(listaPasajeros);//falta arreglar el tema del id
					break;
				case 4:
					printf("MODIFICAR PASAJERO\n");
					controller_editPassenger(listaPasajeros);
					break;
				case 5:
					printf("DAR DE BAJA PASAJERO\n");
					controller_removePassenger(listaPasajeros);
					break;
				case 6:
					printf("LISTA DE PASAJEROS\n");
					controller_ListPassenger(listaPasajeros);
					break;
				/*case 7:
					// ordenar empleados
					controller_sortPassenger(listaPasajeros);
					break;*/
				case 8:
					//guardar en modo texto
					printf("guardando archivo data-procesado.scv.....");
					controller_saveAsText("data-procesado.scv", listaPasajeros);
					controlGuardado = 1;
					break;
				case 9:
					//guardar en modo binario
					printf("guardando archivo extension data-procesado.bin.....");
					controller_saveAsBinary("data-procesado.bin", listaPasajeros);
					controlGuardado = 1;
					break;
				case 10:
					if(controlGuardado!= 0)
					{
						printf("cerrando el programa.......");
					}
					else
					{
						printf("ERROR. debe guardar los cambios para poder salir");
					}
			}
		}while(option != 10);
		printf("\nHa salido correctamente");
	return EXIT_SUCCESS;
}


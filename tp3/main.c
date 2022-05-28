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



		do{
				option = tp_ImprimirMenuDiezOpciones("[MENU]\n", "1- Abrir archivo de texto"
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
					//cargar de modo binario
			    	printf("abriendo archivo data-procesado.bin....\n");
					controller_loadFromBinary("data-procesado.bin", listaPasajeros);
					break;/*
				case 3:
					// alta de empleado
					controller_addEmployee(listaPasajeros);
					break;
				case 4:
					//modificar empleado
					controller_editEmployee(listaPasajeros);
					break;
				case 5:
					// baja de empleado
					controller_removeEmployee(listaPasajeros);
					break;
				case 6:
					// listar empleado
					controller_ListEmployee(listaPasajeros);
					break;
				case 7:
					// ordenar empleados
					controller_sortEmployee(listaPasajeros);
					break;*/
				case 8:
					//guardar en modo texto
					printf("guardando archivo data-procesado.scv.....");
					controller_saveAsText("data-procesado.scv", listaPasajeros);
					break;
				case 9:
					//guardar en modo binario
					printf("guardando archivo extension data-procesado.bin.....");
					controller_saveAsBinary("data-procesado.bin", listaPasajeros);
					break;
				case 10:
					printf("cerrando el programa.......");
			}
		}while(option != 10);
		printf("\nHa salido correctamente");
	return EXIT_SUCCESS;
}

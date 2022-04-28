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

#define QTY_PASS 2000

int main(void) {

	int idUltimo;
	Passenger arrayPasajeros[QTY_PASS];
	int menuPrincipal;
	int contadorClientesCargados;
	int idConsulta;
	int indexIdConsulta;
	int menuSecundario;
	//int auxCriterio;

	idUltimo = ID_INICIAL;
	contadorClientesCargados = -1;
//DEBUG HARDCODEO******************************************************************
	if(!pass_initArray(arrayPasajeros, QTY_PASS))
	{
		printf("inicializado ok\n");
	}
	if(!pass_cargaForzadaDeDatos(arrayPasajeros, QTY_PASS))
	{
		pass_printArray(arrayPasajeros, QTY_PASS);
		contadorClientesCargados=1;
	}
//******************************************************************DEBUG HARDCODEO

	//pass_printArray(arrayPasajeros, QTY_PASS);
	do{
		menuPrincipal = tp_ImprimirMenuSeisOpciones("\nMENU", "1- ALTA DE CLIENTE", "2- MODIFICAR CLIENTE", "3- BAJA DE CLIENTE", "4- INFORMES", "5- SALIR", "");
		switch (menuPrincipal)
		{
			case 1:
				printf("\nALTA DE CLIENTES\n");
				if(contadorClientesCargados == -1)
				{
					pass_initArray(arrayPasajeros, QTY_PASS);
					contadorClientesCargados = 0;
					//printf("[DEBUG****]inicializamos OK!");
				}
				if(pass_pedirNuevoPasajero(arrayPasajeros, QTY_PASS, idUltimo)>=0)
				{
					idUltimo++;
					contadorClientesCargados++;
					printf("clientes cargados: %d\n", contadorClientesCargados);
					if(continuar("\nDesea visualizar los clientes cargados? (Y/N)"))
					{
						pass_printArray(arrayPasajeros, QTY_PASS);
					}
				}
				else
				{
					tp_MensajeError("[ERROR**ALTA DE CLIENTES] Ha habido un error en la carga del cliente\n");
				}

				break;
			case 2:
				printf("\nMODIFICAR CLIENTE\n");
				//printf("DEBUG*** contadoclientes: %d", contadorClientesCargados);
				if(contadorClientesCargados > 0)
				{
					idConsulta = pass_pedirIdConsulta(idUltimo);
					indexIdConsulta= pass_encontrarPasajeroPorId(arrayPasajeros, QTY_PASS, idConsulta);

					switch (indexIdConsulta)
					{
						case -1:
							printf("DEBUG****** ERROR--- en los parametros");
							break;
						case -2:
							printf("ERROR**** no encontro coincidencia. Intente nuevamente\n");
							break;
						default:
							printf("\n\nCliente: %s - ID: %d\n", arrayPasajeros[indexIdConsulta].name, idConsulta);
							pass_printRotulo();
							//printf("cliente %d\n", idConsulta);
							pass_printOneIndice(arrayPasajeros, indexIdConsulta);
							do
							{
								menuSecundario=pass_interaccionMenuSecundario(arrayPasajeros, QTY_PASS, indexIdConsulta);
								//printf("DEBUG**** menu segundario : %d", menuSecundario);
							}while(menuSecundario!= 6);

							break;
					}

				}
				else
				{
					tp_MensajeError("[**ERROR**]No hay clientes cargados para modificar.");
				}
				break;
			case 3:
				printf("\nELIMINAR CLIENTE\n");
				if(contadorClientesCargados > 0)
				{
					idConsulta = pass_pedirIdConsulta(idUltimo);
					indexIdConsulta= pass_encontrarPasajeroPorId(arrayPasajeros, QTY_PASS, idConsulta);
					switch (indexIdConsulta)
					{
						case -1:
							printf("DEBUG****** ERROR--- en los parametros");
							break;
						case -2:
							printf("ERROR**** no encontro coincidencia. Intente nuevamente\n");
							break;
						default:
							printf("\n\nCliente: %s - ID: %d\n", arrayPasajeros[indexIdConsulta].name, idConsulta);
							pass_printRotulo();
							pass_printOneIndice(arrayPasajeros, indexIdConsulta);
							if( continuar("\n¿Confirma que desea eliminar del sistema al cliente? (Y/N)")
								&& !pass_removerSegunId(arrayPasajeros, indexIdConsulta))
							{
								contadorClientesCargados--;
								printf("El cliente %d se ha eliminado del sistema exitosamente\n", idConsulta);
							}
					}
				}
				else
				{
					tp_MensajeError("[**ERROR**]No hay clientes cargados.");
				}
				break;
			case 4:
				printf("\nINFORMES\n");
				//4if(contadorClientesCargados > 0)
				{
					do
					{
						menuSecundario=tp_ImprimirMenuSeisOpciones("Listados de pasajeros según:", "1- Orden alfabetico o por tipo", "2- Informe de total y promedio de precios", "3- Orden por codigo de vuelo y vuelos activos", "4- Volver al menu anterior", "", "");
						printf("DEBUG**** menu segundario : %d", menuSecundario);
						switch(menuSecundario)
						{
						case 1:
							pass_consignaCuatroUno(arrayPasajeros, QTY_PASS);
							break;
						case 2:
							printf("DEBUG*** entramos al 4-2");
							pass_consignaCuatroDos(arrayPasajeros, QTY_PASS);
							break;
						case 3:
							break;
						case 4:
							break;
						}
					}while(menuSecundario<5);
				}

				//Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.


				//Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio	promedio.
				//Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’
				break;
			case 5:
				printf("Saliendo del programa. \nMuchas gracias. \nNakasone Julieta");
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

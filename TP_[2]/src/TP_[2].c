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
	int idConsulta;
	int indexIdConsulta;
	int menuSecundario;

	idUltimo = ID_INICIAL;
	clientesCargados = -1;
	//pass_printArray(arrayPasajeros, QTY_PASS);
	do{
		menuPrincipal = tp_ImprimirMenuSeisOpciones("\nMENU", "1- ALTA DE CLIENTE", "2- MODIFICAR CLIENTE", "3- BAJA DE CLIENTE", "4- INFORMES", "5- SALIR", "");
		switch (menuPrincipal)
		{
			case 1:
				printf("ALTA DE CLIENTES\n");
				if(clientesCargados == -1)
				{
					pass_initArray(arrayPasajeros, QTY_PASS);
					clientesCargados = 0;
					//printf("[DEBUG****]inicializamos OK!");
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
					tp_MensajeError("ERROR**** ha habido un error en la carga del cliente\n");
				}

				break;
			case 2:
				printf("MODIFICAR CLIENTE\n");
				if(clientesCargados > 0)
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
								menuSecundario = tp_ImprimirMenuSeisOpciones("\nMODIFICAR - Indique el dato que desea modificar", "1- Nombre", "2- Apellido", "3- Precio", "4- Tipo Pasajero", "5- Codigo Vuelo", "6- Regresar atras");
								switch(menuSecundario)
								{
									case 1:
										if(!pass_cambiarNombre(arrayPasajeros, indexIdConsulta))
										{
											pass_printOneIndice(arrayPasajeros, indexIdConsulta);
										}
										else
										{
											tp_MensajeError("ERROR** Ha habido un error al modificar el dato. Vuelva a intentar\n");
										}
										break;
									case 2:
										if(!pass_cambiarApellido(arrayPasajeros, indexIdConsulta))
										{
											pass_printOneIndice(arrayPasajeros, indexIdConsulta);
										}
										else
										{
											tp_MensajeError("ha habido un error al modificar el dato");
										}
										break;
									case 3:
										if(!pass_cambiarPrecio(arrayPasajeros, indexIdConsulta))
										{
											pass_printOneIndice(arrayPasajeros, indexIdConsulta);
										}
										else
										{
											tp_MensajeError("ha habido un error al modificar el dato");
										}
										break;
									case 4:
										if(!pass_cambiarTipoPasajero(arrayPasajeros, indexIdConsulta))
										{
											pass_printOneIndice(arrayPasajeros, indexIdConsulta);
										}
										else
										{
											tp_MensajeError("ha habido un error al modificar el dato");
										}
										break;
									case 5:
										if(!pass_cambiarCodigoVuelo(arrayPasajeros, indexIdConsulta))
										{
											pass_printOneIndice(arrayPasajeros, indexIdConsulta);
										}
										else
										{
											tp_MensajeError("ha habido un error al modificar el dato");
										}
										break;
								}
							}while(menuSecundario!= 6);
							break;
					}

				}
				else
				{
					tp_MensajeError("[**ERROR**]Primero debe ingresar al menos 1 cliente para poder modificar");
				}
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
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

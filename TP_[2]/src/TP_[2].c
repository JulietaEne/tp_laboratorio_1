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

#define QTY_PASS 2

int main(void) {

	int idUltimo;
	Passenger arrayPasajeros[QTY_PASS];
	int menuPrincipal;
	int contadorClientesCargados;
	int idConsulta;
	int indexIdConsulta;
	int menuSecundario;

	idUltimo = ID_INICIAL;
	contadorClientesCargados = -1;
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
							//printf("cliente %d\n", idConsulta);
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

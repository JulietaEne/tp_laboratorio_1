/*
 ============================================================================
 Name        : tp1_nakasone-julieta.c
 Author      : Julieta Nakasone
 Version     : 2
 Copyright   : Your copyright notice
 Description : TP1 - Agencia de Viajes - para linux. En utn.c se guarda **fflush(stdin)**, descomentar para windows
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "utn.h"
#include "tp.h"

int main(void) {

	int menuPrincipal;
	int flagVuelosCargados;
	int retornoFuncion;
	float distanciaTotal;
	float vueloAerolineas;
	float vueloLatam;

	float descuentoAerolineas;
	float interesAerolineas;
	float bitcoinAerolineas;
	float unitarioAerolineas;
	float descuentoLatam;
	float interesLatam;
	float bitcoinLatam;
	float unitarioLatam;
	float diferenciaAerolineasLatam;

	flagVuelosCargados = -1;

	//retornoFuncion = tp_calcularBitcoin(20000);
//	printf("PRUEBA valor en BTC para20000$ ARG = %.6f", retornoFuncion);

	do{
		menuPrincipal= tp_ImprimirMenuSeisOpciones("MENU", "1. Ingresar distancia total", "2. Ingresar precio total", "3. Calcular costos", "4. Informar resultados", "5. Carga forzada de datos", "6. Salir");

		switch (menuPrincipal)
		{
			case 1:
				retornoFuncion = utn_GetNumeroFloat(&distanciaTotal, "1. Ingresar Kilometros: ", "Ingrese un dato valido\n", 2, 20000, 2);
				if(!retornoFuncion)
				{
					printf("km=%.2f\n\n",distanciaTotal);
					flagVuelosCargados = 1;
				}
				else
				{
					tp_MensajeErrorGenerico(retornoFuncion);
				}
				break;

			case 2:
				if(flagVuelosCargados == 1)
				{
					printf("2. Ingresar Precio de vuelos\n");
					retornoFuncion = utn_GetNumeroFloat(&vueloAerolineas, "Precio vuelo Aerolineas: $", "Ingrese un dato valido[ENTRE $25000 y $200000]", 25000, 200000, 2);
					if(!retornoFuncion && !utn_GetNumeroFloat(&vueloLatam, "Precio vuelo Latam: $", "Ingrese un dato valido[ENTRE $25000 y $200000]", 25000, 200000, 2))
					{
						printf("Aerolineas=$%.2f - Latam=$%.2f\n\n",vueloAerolineas, vueloLatam);
						flagVuelosCargados = 2;
					}
					else
					{
						tp_MensajeErrorGenerico(retornoFuncion);
					}
				}
				else
				{
					tp_MensajeError("ERROR\nPrimero debe cargar la distancia total. Ingrese al MENU op1. para continuar\n\n");
				}
				break;

			case 3:
				if(flagVuelosCargados == 2 || flagVuelosCargados == 5)
				{
					printf("3. Calcular todos los costos:\n");
					flagVuelosCargados = 3;
					descuentoAerolineas= tp_calcularTotalConDescuento(vueloAerolineas, 10);
					interesAerolineas= tp_calcularTotalConInteres(vueloAerolineas, 25);
					bitcoinAerolineas= tp_calcularTotalEnBitcoin(vueloAerolineas);
					unitarioAerolineas= tp_calcularPrecioUnitario(vueloAerolineas, distanciaTotal);

					descuentoLatam= tp_calcularTotalConDescuento(vueloLatam, 10);
					interesLatam= tp_calcularTotalConInteres(vueloLatam, 25);
					bitcoinLatam= tp_calcularTotalEnBitcoin(vueloLatam);
					unitarioLatam= tp_calcularPrecioUnitario(vueloLatam, distanciaTotal);

					diferenciaAerolineasLatam= tp_calcularDiferencia(vueloLatam, vueloAerolineas);

					printf("a- Tarjeta de debito (descuento 10)...\nb- Tarjeta de credito (interes 251)");
					sleep(0.5);
					printf("...");
					sleep(0.5);
					printf("\nc- Bitcoin (1BTC=4606954.55 Pesos Argentinos)... \nd- Mostrar precio por km (precio unitario)");
					sleep(0.5);
					printf("...");
					sleep(0.5);
					printf("\ne- Mostrar diferencia de precio ingresada (Latam - Aerolineas)...\n");
					sleep(0.5);
					printf("CALCULADO CON EXITO\n\n");
				}
				else
				{
					switch (flagVuelosCargados)
					{
						case 0:
							tp_MensajeError("ERROR\nPrimero debe cargar la distancia total. Ingrese al MENU op1. para continuar\n\n");
							break;
						case 1:
							tp_MensajeError("ERROR\nPrimero debe cargar el precio total. Ingrese al MENU op2. para continuar\n\n");
							break;
						case 3:
							tp_MensajeError("ADVERTENCIA ya se han calculado los costos. Ingrese al MENU op4. para visualizarlos\n\n");
							break;
					}
					if(flagVuelosCargados == 0)
					{
						tp_MensajeError("ERROR\nPrimero debe cargar la distancia total. Ingrese al MENU op1. para continuar\n\n");
					}
					else
					{
						tp_MensajeError("ERROR\nPrimero debe cargar el precio total. Ingrese al MENU op2. para continuar\n\n");
					}
				}

				break;
			case 4:
				if(flagVuelosCargados == 3)
				{
					printf("4. Informar resultados\n\n");
					printf("LATAM\na- Precio con tarjeta de debito: $%.2f\n", descuentoLatam);
					printf("b- Precio con tarjeta de credito: $%.2f\n", interesLatam);
					printf("c- Precio pagando con bitcoin: %f BTC\n", bitcoinLatam);
					printf("d- Precio unitario: $%.2f por cada KM\n", unitarioLatam);

					printf("\nAEROLINEAS\na- Precio con tarjeta de debito: $%.2f\n", descuentoAerolineas);
					printf("b- Precio con tarjeta de credito: $%.2f\n", interesAerolineas);
					printf("c- Precio pagando con bitcoin: %f BTC\n", bitcoinAerolineas);
					printf("d- Precio unitario: $%.2f por cada KM\n", unitarioAerolineas);

					printf("\nLa diferencia de precio es : $%.2f(Latam - Aerolineas)\n\n", diferenciaAerolineasLatam);
				}
				else
				{
					switch (flagVuelosCargados)
					{
						case 0:
							tp_MensajeError("ERROR\nPrimero debe cargar la distancia total. Ingrese al MENU op1. para continuar\n\n");
							break;
						case 1:
							tp_MensajeError("ERROR\nPrimero debe cargar el precio total. Ingrese al MENU op2. para continuar\n\n");
							break;
						case 2:
							tp_MensajeError("ERROR\nPara poder visualizar los informes, primero tiene que calcular todos los costos. Ingrese al MENU op3. para continuar\n\n");
							break;
						case 5:
							tp_MensajeError("ERROR\nPara poder visualizar los informes, primero tiene que calcular todos los costos. Ingrese al MENU op3. para continuar\n\n");
							break;
					}
				}
				break;
			case 5:
				printf("5. Carga forzada de datos\n");
				flagVuelosCargados = 5;
				distanciaTotal = 7090;
				vueloAerolineas = 162965;
				vueloLatam = 159339;
				sleep(0.5);
				printf("DISTANCIA TOTAL %d\nVUELO AEROLINEAS %d\nVUELO LATAM %d\n\n", distanciaTotal, vueloAerolineas, vueloLatam);
				//acá KM = 7090
				//AA=$162965
				//LATAM=$159339
				break;
			case 6:
				printf("\nSaliendo del programa ...");
				printf("\nMuchas gracias ...");
				printf("\nFINALIZADO");
				break;
		}

	}while(menuPrincipal != 6);
}

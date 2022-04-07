/*
 ============================================================================
 Name        : tp1_nakasone-julieta.c
 Author      : Julieta Nakasone
 Version     : 1
 Copyright   : Your copyright notice
 Description : TP1 - Agencia de Viajes
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
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
				retornoFuncion = utn_GetNumeroFloat(&distanciaTotal, "1. Ingresar Kilómetros: ", "Ingrese un dato valido\n", 2, 20000, 2);
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
					retornoFuncion = utn_GetNumeroFloat(&vueloAerolineas, "Precio vuelo Aerolíneas: $", "Ingrese un dato válido[ENTRE $25000 y $200000]", 25000, 200000, 2);
					if(!retornoFuncion && !utn_GetNumeroFloat(&vueloLatam, "Precio vuelo Latam: $", "Ingrese un dato válido[ENTRE $25000 y $200000]", 25000, 200000, 2))
					{
						printf("Aerolíneas=$%.2f - Latam=$%.2f\n\n",vueloAerolineas, vueloLatam);
						flagVuelosCargados = 2;
					}
					else
					{
						tp_MensajeErrorGenerico(retornoFuncion);
					}
				}
				else
				{
					tp_MensajeError("Primero debe cargar la distancia total. Ingrese al MENU op1. para continuar\n");
				}
				break;

			case 3:
				if(flagVuelosCargados == 2 || flagVuelosCargados == 5)
				{
					printf("3. Calcular todos los costos:\n");
					descuentoAerolineas= tp_calcularTotalConDescuento(vueloAerolineas, 10);
					interesAerolineas= tp_calcularTotalConInteres(vueloAerolineas, 25);
					bitcoinAerolineas= tp_calcularTotalEnBitcoin(vueloAerolineas);
					unitarioAerolineas= tp_calcularPrecioUnitario(vueloAerolineas, distanciaTotal);

					descuentoLatam= tp_calcularTotalConDescuento(vueloLatam, 10);
					interesLatam= tp_calcularTotalConInteres(vueloLatam, 25);
					bitcoinLatam= tp_calcularTotalEnBitcoin(vueloLatam);
					unitarioLatam= tp_calcularPrecioUnitario(vueloLatam, distanciaTotal);

					diferenciaAerolineasLatam= tp_calcularDiferencia(vueloLatam, vueloAerolineas);

					printf("a- Tarjeta de débito (descuento 10)...\nb- Tarjeta de crédito (interés 251)...");
					printf("\nc- Bitcoin (1BTC=4606954.55 Pesos Argentinos)... \nd- Mostrar precio por km (precio unitario)...\n");
					printf("e- Mostrar diferencia de precio ingresada (Latam - Aerolíneas)...\n   CALCULADO CON ÉXITO\n\n");

				}
				else
				{
					if(flagVuelosCargados == 0)
					{
						tp_MensajeError("Primero debe cargar la distancia total. Ingrese al MENU op1. para continuar\n");
					}
					else
					{
						tp_MensajeError("Primero debe cargar el precio total. Ingrese al MENU op2. para continuar\n");
					}
				}

				break;
			case 4:
				printf("4. Informar resultados\n\n");
				printf("LATAM\na- Precio con tarjeta de débito: $%.2f\n", descuentoLatam);
				printf("b- Precio con tarjeta de crédito: $%.2f\n", interesLatam);
				printf("c- Precio pagando con bitcoin: %f BTC\n", bitcoinLatam);
				printf("d- Precio unitario: $%.2f por cada KM\n", unitarioLatam);

				printf("\nAEROLÍNEAS\na- Precio con tarjeta de débito: $%.2f\n", descuentoAerolineas);
				printf("b- Precio con tarjeta de crédito: $%.2f\n", interesAerolineas);
				printf("c- Precio pagando con bitcoin: %f BTC\n", bitcoinAerolineas);
				printf("d- Precio unitario: $%.2f por cada KM\n", unitarioAerolineas);

				printf("\nLa diferencia de precio es : $%.2(Latam - Aerolíneas)f\n\n", diferenciaAerolineasLatam);
				break;
			case 5:
				printf("5. Carga forzada de datos\n");
				printf("DISTANCIA TOTAL 7090\nVUELO AEROLINEAS $162965\nVUELO LATAM $159339\n\n");
				flagVuelosCargados = 5;
				distanciaTotal = 7090;
				vueloAerolineas = 162965;
				vueloLatam = 159339;
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

/*
 * tp1.c
 *
 *  Created on: 4 abr. 2022
 *      Author: juliet
 */
#include <stdio.h>
#include <stdlib.h>
#include "tp.h"
#include "utn.h"
//____________________________:::::FUNCIONES tp 1:::::___________________________
float tp_calcularTotalConDescuento(float numero, float descuento)
{
	float retorno;
	retorno = -1;

	if(descuento < 100 && descuento >0)
	{
		descuento = 1-descuento*0.01;
		//printf("DECUENTO descuento = %.2f", descuento);
		retorno = numero*descuento;
	}
	return retorno;
}

float tp_calcularTotalConInteres(float numero, float interes)
{
	float retorno;
	retorno = -1;

	if(interes < 100 && interes >0)
	{
		interes = 1+interes*0.01;
		retorno = numero*interes;
	}
	return retorno;
}

float tp_calcularTotalEnBitcoin(float pesosArgIngresados)
{
	//valor actual 1 bitcoin = 4606954.55 Pesos Argentinos
	return pesosArgIngresados/4606954.55;
}
float tp_calcularPrecioUnitario(float dividendo, float divisor)
{
	float retorno;
	retorno = -1;
	if(divisor != 0)
	{
		retorno = dividendo/divisor;
	}

	return retorno;
}
float tp_calcularDiferencia(float minuendo, float sustraendo)
{
	return minuendo-sustraendo;
}



//__________________:::::FUNCIONES ASISTENTES DEL PROGRAMA:::::___________________
/**
* \brief Interactua con el usuario para recibir una opción del menú mostrado
* \param descripcion y opciones Todos corresponden a la descripción del menu
* \return Retorna la opción ingresada por el Usuario
*
*/
int tp_ImprimirMenuSeisOpciones(char* descripcion,char* opcionUno, char* opcionDos, char* opcionTres, char* opcionCuatro, char* opcionCinco, char* opcionSeis)
{
    int opcionElegida;
    printf("%s\n%s\n%s\n%s\n%s\n%s\n%s", descripcion, opcionUno, opcionDos, opcionTres, opcionCuatro, opcionCinco, opcionSeis);
    utn_GetNumeroInt(&opcionElegida, "\n\nIngresar opción: ", "por favor, ingrese una opción válida", 1, 6, 1);

    return opcionElegida;
}

/**
* \brief Muestra a usuario un mensaje con el código del error
* \param int error: recibe el código del error presentado
* \return void
*
*/
void tp_MensajeErrorGenerico(int error)
{
    printf("[ERROR %d]. Ha habido un error, imposible continuar\n ", error);
}

/**
* \brief Muestra a usuario un mensaje de error
* \param int error: recibe el código del error presentado
* \return void
*
*/
void tp_MensajeError(char* mensaje)
{
	printf("%s", mensaje);
}

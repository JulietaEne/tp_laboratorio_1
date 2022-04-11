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
//____________________________:::::FUNCIONES tp 1:::::____________________________
/**
 * \brief calcula un descuento según los valores recibidos y retorna el resultado
 * \param numero Recibe por valor el dato sobre el cual se calculará
 * \param descuento Recibe por valor el dato que indique el descuento a realizar
 * \return Retorna > 0 si la operación se realizó con éxito (retorna el resultado de la operación).
 * 				   = -1 si no se pudo realizar la operación (el dato ingresado como descuento no está entre el rango 0-100)
 *
 */
float tp_calcularTotalConDescuento(float numero, float descuento)
{
	float resultado;
	resultado = -1;

	if(descuento <= 100 && descuento >0)
	{
		descuento = 1-descuento*0.01;
		//printf("DECUENTO descuento = %.2f", descuento);
		resultado = numero*descuento;
	}
	return resultado;
}

/**
 * \brief calcula un porcentaje de aumento según los valores recibidos y retorna el resultado
 * \param numero Recibe por valor el dato sobre el cual se calculará
 * \param interes Recibe por valor el dato que indica porcentaje de aumento
 * \return Retorna > 0 si la operación se realizó con éxito (retorna el resultado de la operación).
 * 				   = -1 si no se pudo realizar la operación (el dato ingresado como descuento no está entre el rango 0-100)
 *
 */
float tp_calcularTotalConInteres(float numero, float interes)
{
	float resultado;
	resultado = -1;

	if(interes <= 100 && interes >0)
	{
		interes = 1+interes*0.01;
		resultado = numero*interes;
	}
	return resultado;
}

/**
 * \brief calcula el cambio pesos argentinos en bitcoin y retorna el resultado
 * \param pesosArgIngresados Recibe por valor el importe en pesos
 * \param interes Recibe por valor el dato que indica porcentaje de aumento
 * \return Retorna > 0 (retorna el resultado de la operación).
 *
 */
float tp_calcularTotalEnBitcoin(float pesosArgIngresados)
{
	//valor actual 1 bitcoin = 4606954.55 Pesos Argentinos
	return pesosArgIngresados/4606954.55;
}

/**
 * \brief realiza una división y retorna el resultado
 * \param dividendo Recibe por valor el dato sobre el cual opera
 * \param divisor Recibe por valor el dato por el cual se divide
 * \return Retorna > 0 si la operación se realizó con éxito(retorna el resultado de la operación).
 * 				   = -1 si hubo un error en el parámetro divisor
 *
 */
float tp_calcularPrecioUnitario(float dividendo, float divisor)
{
	float resultado;
	resultado = -1;
	if(divisor != 0)
	{
		resultado = dividendo/divisor;
	}

	return resultado;
}

/**
 * \brief calcula una diferencia y retorna el resultado
 * \param minuendo Recibe por valor el dato sobre el cual opera
 * \param sustraendo Recibe por valor el dato que resta
 * \return Retorna el resultado de la resta
 *
 */
float tp_calcularDiferencia(float minuendo, float sustraendo)
{
	return minuendo-sustraendo;
}



//____________________________:::::FUNCIONES ASISTENTES DEL PROGRAMA:::::____________________________
/**
* \brief Interactua con el usuario para recibir una opción del menú mostrado, retorna la opción ingresada
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
* \param error Recibe por valor el código del error presentado
* \return void
*
*/
void tp_MensajeErrorGenerico(int error)
{
    printf("[ERROR %d]. Ha habido un error, imposible continuar\n ", error);
}

/**
* \brief Muestra a usuario un mensaje de error
* \param error Recibe el mensaje a imprimir
* \return void
*
*/
void tp_MensajeError(char* mensaje)
{
	printf("%s", mensaje);
}

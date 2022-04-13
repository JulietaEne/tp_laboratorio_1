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
 * \brief calcula un descuento segun los valores recibidos y retorna el resultado
 * \param numero Recibe por valor el dato sobre el cual se calculara
 * \param descuento Recibe por valor el dato que indique el descuento a realizar
 * \return Retorna > 0 si la operacion se realizo con exito (retorna el resultado de la operacion).
 * 				   = -1 si no se pudo realizar la operacion (el dato ingresado como descuento no esta entre el rango 0-100)
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
 * \brief calcula un porcentaje de aumento segun los valores recibidos y retorna el resultado
 * \param numero Recibe por valor el dato sobre el cual se calculara
 * \param interes Recibe por valor el dato que indica porcentaje de aumento
 * \return Retorna > 0 si la operacion se realizo con exito (retorna el resultado de la operacion).
 * 				   = -1 si no se pudo realizar la operacion (el dato ingresado como descuento no esta entre el rango 0-100)
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
 * \return Retorna > 0 (retorna el resultado de la operacion).
 *
 */
float tp_calcularTotalEnBitcoin(float pesosArgIngresados)
{
	//valor actual 1 bitcoin = 4606954.55 Pesos Argentinos
	return pesosArgIngresados/4606954.55;
}

/**
 * \brief realiza una division y retorna el resultado
 * \param dividendo Recibe por valor el dato sobre el cual opera
 * \param divisor Recibe por valor el dato por el cual se divide
 * \return Retorna > 0 si la operacion se realizo con exito(retorna el resultado de la operacion).
 * 				   = -1 si hubo un error en el parametro divisor
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
* \brief Interactua con el usuario para recibir una opcion del menu mostrado, retorna la opcion ingresada
* \param descripcion y opciones Todos corresponden a la descripcion del menu
* \return Retorna la opcion ingresada por el Usuario
*
*/
int tp_ImprimirMenuSeisOpciones(char* descripcion,char* opcionUno, char* opcionDos, char* opcionTres, char* opcionCuatro, char* opcionCinco, char* opcionSeis)
{
    int opcionElegida;
    printf("%s\n%s\n%s\n%s\n%s\n%s\n%s", descripcion, opcionUno, opcionDos, opcionTres, opcionCuatro, opcionCinco, opcionSeis);
    utn_GetNumeroInt(&opcionElegida, "\n\nIngresar opcion: ", "por favor, ingrese una opcion valida", 1, 6, 1);

    return opcionElegida;
}

/**
* \brief Muestra a usuario un mensaje con el codigo del error
* \param error Recibe por valor el codigo del error presentado
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

/**
* \brief Interactua con el usuario para recibir una opcion del menu mostrado, retorna la opcion ingresada
* \param descripcion y opciones Todos corresponden a la descripcion del menu
* \return Retorna la opcion ingresada por el Usuario
*
*/
int tp_ImprimirMenuTresOpciones(char* descripcion,char* opcionUno, char* opcionDos, char* opcionTres)
{
    int opcionElegida;
    printf("%s\n%s\n%s\n%s", descripcion, opcionUno, opcionDos, opcionTres);
    utn_GetNumeroInt(&opcionElegida, "\n\nIngresar opcion: ", "por favor, ingrese una opcion valida", 1, 3, 1);

    return opcionElegida;
}

/*
 * tp1.c
 *
 *  Created on: 4 abr. 2022
 *      Author: juliet
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "tp.h"
#include "utn.h"

//____________________________:::::FUNCIONES tp 1:::::____________________________
/**
 * \brief Calcula un descuento segun los valores recibidos y retorna el resultado
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
* \return Retorna int la opcion ingresada por el Usuario (entre 1 y 6)
*
*/
int tp_ImprimirMenuSeisOpciones(char* descripcion,char* opcionUno, char* opcionDos, char* opcionTres, char* opcionCuatro, char* opcionCinco, char* opcionSeis)
{
    int opcionElegida;
    printf("%s\n%s\n%s\n%s\n%s\n%s\n%s", descripcion, opcionUno, opcionDos, opcionTres, opcionCuatro, opcionCinco, opcionSeis);
    utn_GetNumeroInt(&opcionElegida, "\nIngresar opcion: ", "por favor, ingrese una opcion valida", 1, 6, 1);
    //printf("DEBUG*** opc elegida: %d\n\n",opcionElegida);
    return opcionElegida;
}

/**
* \brief Muestra a usuario un mensaje con el codigo del error
* \param error int Recibe por valor el codigo del error presentado
* \return void
*
*/
void tp_MensajeErrorGenerico(int error)
{
    printf("[ERROR %d]. Ha habido un error, imposible continuar\n ", error);
}

/**
* \brief Muestra a usuario un mensaje de error
* \param error char* Recibe el mensaje a imprimir
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
* \return Retorna int la opcion ingresada por el Usuario
*
*/
int tp_ImprimirMenuTresOpciones(char* descripcion,char* opcionUno, char* opcionDos, char* opcionTres)
{
    int opcionElegida;
    printf("%s\n%s\n%s\n%s", descripcion, opcionUno, opcionDos, opcionTres);
    utn_GetNumeroInt(&opcionElegida, "\n\nIngresar opcion: ", "por favor, ingrese una opcion valida", 1, 3, 1);

    return opcionElegida;
}

/**
 * \breif muestra mensaje y recibe un caracter para corroborar que sea 'y'
 * \param *mensaje Recibe por referencia el literal a mostrar
 * \return retorna 1 si continua
 * 		   0 si no continua
 *
 */
int continuar(char* mensaje)
{
	int retorno;
	char respuesta;
	retorno = 0;

	printf("\n%s\nOpcion (Y/N): ", mensaje);
	__fpurge(stdin);
	scanf("%c", &respuesta);
	if(respuesta == 'Y' || respuesta == 'y')
	{
		retorno = 1;
	}
	if(respuesta == 'N' || respuesta == 'n')
	{
		retorno = 0;
	}
	return retorno;
}


/**
 * \brief valida si el numero a analizar es distinto del numero con el que se compara
 * \param numeroAnalizar int Recibe por valor el dato al cual analizara
 * \param inicialCompare int Recibe por valor el dato contra el cual se compara
 * \return Retorna 0 si es falso
 * 		   1 si es verdadero
 *
 */
int esDistintoDeInicial(int numeroAnalizar, int inicialCompare)
{
	int retorno;
	retorno = 0;
	if(numeroAnalizar != inicialCompare)
	{
		retorno = 1;
	}
	return retorno;
}

/**
 * \brief realiza un intercambio entre los valores de las variables recibidas por parametro
 * \param numero1 int* Recibe por referencia un valor int
 * \param numero2 int* Recibe por referencia otro valor int
 * \return Retorna -1 si hubo un error en las direcciones de memoria recibidas
 * 		   0 si realizo la operacion exitosamente
 *
 */
int swap(int* numero1, int* numero2)
{
    int retorno;
    int aux;

    retorno = -1;
    if(numero1!= NULL && numero2!= NULL)
    {
        aux = *numero1;
        *numero1 = *numero2;
        *numero2 = aux;
    	retorno=0;
    }
    return retorno;
}

/**
 * \brief Recibe una cadena de caracteres y si sus componentes representan letras minusculas las sobreescribe por el mismo caracter en mayuscula
 * \param caracter char* Recibe la direccion de memoria del array que analizara
 * \return Retorna -1 si hubo un error en las direcciones de memoria recibidas
 * 		   0 si realizo la operacion exitosamente
 *
 */
int convertirAMayuscula(char* caracter)
{
	int retorno;
	retorno = -1;
	if( caracter != NULL)
	{
		retorno = 0;
		if(*caracter>96 && *caracter<123)
		{
			*caracter=*caracter-32;
			//printf("DEBUG**** caracter %c en mayus", *caracter);
		}
	}
	return retorno;
}

/**
 * \brief Recibe una cadena de caracteres y si sus componentes representan letras mayusculas las sobreescribe por el mismo caracter en minuscula
 * \param caracter char* Recibe la direccion de memoria del array que analizara
 * \return Retorna -1 si hubo un error en las direcciones de memoria recibidas
 * 		   0 si realizo la operacion exitosamente
 *
 */
int convertirAMinuscula(char* caracter)
{
	int retorno;
	retorno = -1;
	if( caracter != NULL)
	{
		retorno = 0;
		if(*caracter>64 && *caracter<91)
		{
			*caracter=*caracter+32;
		}
	}
	return retorno;
}

//____________________________________:::::FUNCIONES DE LOGICA:::::__________________________________
/**
 * \brief valida si el numero recibido es mayor que cero
 * \param numeroint Recibe por valor el dato al cual analizara
 * \return Retorna 0 si es falso
 * 		   1 si es verdadero
 *
 */
int esPositivo(int numero)
{
	int retorno;
	retorno = 0;
	if(numero>0)
	{
		retorno = 1;
	}
	return retorno;
}

/**
 * \brief valida si el numero recibido es par
 * \param numero Recibe por valor el dato al cual analizara
 * \return Retorna 0 si es falso
 * 		   1 si es verdadero
 *
 */
int esPar(int numero)
 {
    int retorno;
    retorno = 0;
    if(numero%2==0)
	{
		retorno = 1;
	}

    return retorno;
 }

/**
 * \brief Compara los valores recibidos y si el primero es mayor, intercambia los valores para ordenar de menor a mayor
 * \param numeroA int* Recibe por referencia el valor a analizar
 * \param numeroB int* Recibe por referencia el valor contra el cual compara
 * \return Retorna -1 si hubo un error en los parámetros
 * 		   -2 si no hubo intercambio
 * 		    0 si se realizo un intercambio en los valores
 *
int ordenarFormaCreciente(int* numeroA, int* numeroB)
{
	int retorno;
	retorno = -1;
	if(numeroA!= NULL && numeroB != NULL)
	{
		retorno = -2;
		if(*numeroA > *numeroB)
		{
			swap(&numeroA, &numeroB);
			retorno = 0;
		}
	}
	return retorno;
} */

/**
 * \brief Compara los valores recibidos y si el primero es menor, intercambia los valores para ordenar de mayor a menor
 * \param numeroA Recibe por referencia el valor a analizar
 * \param numeroB Recibe por referencia el valor contra el cual compara
 * \return Retorna -1 si hubo un error en los parámetros
 * 		   -2 si no hubo intercambio
 * 		    0 si se realizo un intercambio en los valores
 *
int ordenarFormaDecreciente(int* numeroA, int* numeroB)
{
	int retorno;
	retorno = -1;
	if(numeroA!= NULL && numeroB != NULL)
	{
		retorno = 0;
		if(*numeroA < *numeroB)
		{
			swap(&numeroA, &numeroB);
			retorno = 1;
		}
	}
	return retorno;
}*/


float tp_calcularPromedio(float acumulador, int total)
{
	float promedio;
	promedio = -1;
	if(total!= 0)
	{
		promedio = acumulador/total;
	}
	return promedio;
}



/*
 * fecha.c
 *
 *  Created on: 29 abr. 2022
 *      Author: julieta_enee
 */

#include "fecha.h"
#define  REINTENTOS 1
#define MAX_DAY 31
#define MAX_FEB 28
#define MAX_DAY_TWO 30
#define MAX_MONTH 12
#define MAX_YEAR 2022
#define MIN_YEAR 1920

eFecha fecha_newFecha(void)
{
	eFecha unaFecha;
	/*int newday;
	int newmonth;
	int newyear;*/
	utn_GetNumeroInt(&unaFecha.day, "ingrese dia: ", "ingrese un dato valido", 1, MAX_DAY, REINTENTOS);
	utn_GetNumeroInt(&unaFecha.month, "ingrese mes: ", "ingrese un dato valido", 1, MAX_MONTH, REINTENTOS);
	utn_GetNumeroInt(&unaFecha.year, "ingrese anio: ", "ingrese un dato valido", MIN_YEAR, MAX_YEAR, REINTENTOS);

	/*printf("ingrese dia: ");
	scanf("%d", &unaFecha.day);
	printf("dia: %d\n",unaFecha.day);
	printf("ingrese mes: ");
	scanf("%d", &unaFecha.month);
	printf("month: %d\n",unaFecha.month);
	printf("ingrese anio: ");
	scanf("%d", &unaFecha.year);*/
	//printf("una fecha: %d-%d-%d\n",unaFecha.year, unaFecha.day, unaFecha.month);


	return unaFecha;
}

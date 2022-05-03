/*
 * fecha.h
 *
 *  Created on: 29 abr. 2022
 *      Author: julieta_enee
 */

#ifndef FECHA_H_
#define FECHA_H_
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

#define REINTENTOS 1

typedef struct
{
    int day;
    int month;
    int year;
}eFecha;

eFecha fecha_newFecha(void);

#endif /* FECHA_H_ */

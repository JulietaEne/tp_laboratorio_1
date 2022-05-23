/*
 * typePass.h
 *
 *  Created on: 13 may. 2022
 *      Author: julieta_enee
 */

#ifndef TYPEPASS_H_
#define TYPEPASS_H_

#define REINTENTOS 2
#define MAX_PRECIO 200000
#define MIN_PRECIO 10000
#define MIN_ESTADO_VUELO 0
#define MAX_ESTADO_VUELO 3
#define IS_EMPTY 0
#define NOT_EMPTY 1
#define DELETED -1
#define SIZE_STR 51
#define SIZE_CODE 10
#define ID_INICIAL 100
#define ID_MAXIMO 2200

struct
{
	int idTypePass;
	char description[21];
	int isEmpty;
}typedef typePass;

int typePass_cargaForzadaDatos(typePass* listaTipoPasajeros, int sizeTipoPasajeros);
int typePass_printListaTiposPasajeros(typePass* listaTipoPasajeros, int sizeTipoPasajeros);
int typePass_printPosicion(typePass* listaTipoPasajeros, int indice);
int typePass_printTipoPasajeroSegunId(typePass* listaTipoPasajeros, int sizeTipoPasajeros, int idTipoPasajero);
int typePass_getTipoPasajero(typePass* listaTipoPasajeros, int sizeTipoPasajeros);




#endif /* TYPEPASS_H_ */

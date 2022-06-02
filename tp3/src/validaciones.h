/*
 * validaciones.h
 *
 *  Created on: 17 abr. 2022
 *      Author: julieta_enee
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

int validaciones_esNombre(char unString[], int sizeString);
int validacionesInt_sonIdenticos(int variable, int valor);
int validaciones_EsCodigoTresLetrasYNumero(char unString[], int sizeString);
int validaciones_esNumeroInt(char* pCadena, int limite);
int validaciones_esNumeroFlotante(char* pCadena, int limite);
int validaciones_eliminarUltimoEnter(char*pCadena, int lenCadena);


#endif /* VALIDACIONES_H_ */

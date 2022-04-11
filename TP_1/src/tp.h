/*
 * tp.h
 *
 *  Created on: 4 abr. 2022
 *      Author: juliet
 *      Description : Contendrá todas las funciones que dan sercicio a los tp
 */

#ifndef TP_H_
#define TP_H_

//_____________________________________:::::FUNCIONES tp 1:::::_____________________________________
float tp_calcularTotalConDescuento(float numero, float descuento);
float tp_calcularTotalConInteres(float numero, float interes);
float tp_calcularTotalEnBitcoin(float pesosArgIngresados);
float tp_calcularPrecioUnitario(float dividendo, float divisor);
float tp_calcularDiferencia(float minuendo, float sustraendo);

//____________________________:::::FUNCIONES ASISTENTES DEL PROGRAMA:::::____________________________
int tp_ImprimirMenuSeisOpciones(char* descripcion,char* opcionUno, char* opcionDos, char* opcionTres, char* opcionCuatro, char* opcionCinco, char* opcionSeis);
void tp_MensajeErrorGenerico(int error);
void tp_MensajeError(char* mensaje);

#endif /* TP_H_ */

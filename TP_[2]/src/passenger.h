/*
 * passenger.h
 *
 *  Created on: 23 abr. 2022
 *      Author: juliet
 */

#ifndef PASSENGER_H_
#include "typePass.h"


struct
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int idTypePass;
	int statusFlight;
	int isEmpty;
}typedef Passenger;



int pass_initArray(Passenger* listPass, int sizeListPass);//init passengers
int pass_initAPossition(Passenger* listPass, int indice, int valorInicial);
int pass_indicarUltimoId(Passenger* listPass, int sizeListPass);//, int* ultimoId)
int pass_contadorPasajerosCargados(Passenger* listPass, int sizeListPass, int* cantidadCargados);//, int* cantidadCargados)
int pass_printArray(Passenger* listPass, int sizeListPass) ;//printPassenger
int pass_printArrayConTipoPasajero(Passenger* listPass, int sizeListPass, typePass* listaTipoPasajeros, int sizeTipoPasajeros); //printPassenger
void pass_printRotulo(void);
int pass_printOneIndice(Passenger* listPass, int indice);
int pass_getNombre(char* nombre, int sizeNombre);
int pass_getApellido(char* apellido, int sizeApellido);
float pass_getPrecio(float* precio);
int pass_getCodigoVuelo(char* codigoVuelo, int sizeCodigoVuelo);
int pass_getEstadoVuelo(int* estadoVuelo);
int pass_getTipoPasajero(int* tipoPasajero, typePass* listaTipoPasajeros, int sizeTipoPasajeros);
int pass_encontrarPrimerIndiceIsEmpty(Passenger* listPass, int sizePass);
int pass_getNuevoPasajero(Passenger* listPass, int sizePass, int ultimoId, typePass* listaTipoPasajeros, int sizeListaTipoPasajeros);
int pass_agregarPasajeroAlArray(Passenger* listPass, int sizePass, char* nombre, char* apellido, float precio, char* codigoVuelo, int tipoPasajero, int estadoVuelo);
int pass_pedirIdConsulta(int* idConsulta, Passenger* listPass, int sizeListPass, typePass* listaTipoPasajeros, int sizeListaTipoPasajeros);

int pass_setNombre(Passenger* listPass, int indexCambio);
int pass_setApellido(Passenger* listPass, int indexCambio);
int pass_setPrecio(Passenger* listPass, int indexCambio);
int pass_setTipoPasajero(Passenger* listPass, int indexCambio, typePass* listaTipoPasajeros, int sizeListaTipoPasajeros);
int pass_setCodigoVuelo(Passenger* listPass, int indexCambio);
int pass_findIndexSegunId(Passenger* listPass, int sizePass, int idConsulta);
int pass_pedirIdYDevolverIndex(Passenger* listPass, int sizePass, typePass* listaTipoPasajeros, int sizeListaTipoPasajeros);
int pass_removerSegunId(Passenger* arrayPasajeros, int indexIdConsulta);
int pass_prepararArray(Passenger* pArray, int sizeArray, int clientesCargados);
void pass_cambiarNombreEImprimir(Passenger* pArray, int index);
void pass_cambiarApellidoEImprimir(Passenger* pArray, int index);
void pass_cambiarPrecioEImprimir(Passenger* pArray, int index);
void pass_cambiarTipoPasajeroEImprimir(Passenger* pArray, int index, typePass* listaTipoPasajeros, int sizeListaTipoPasajeros);
void pass_cambiarCodigoVueloEImprimir(Passenger* pArray, int index);
int pass_interaccionMenuSecundario(Passenger* pArray, int sizeArray, int indexConsulta, typePass* listaTipoPasajeros, int sizeListaTipoPasajeros);
int pass_swap(Passenger* listPass, int index1, int index2);
int pass_ordenarVuelosActivos(Passenger* listPass, int sizeArray, typePass* listaTipoPasajeros, int sizeListaTipoPasajeros);
int pass_ordenarArrayPorCodigoVuelo(Passenger* listPass, int sizeArray);
int pass_ordenarArrayPorNombreOTipo(Passenger* listPass, int sizeArray, int criterio);//sortPassengers;
int pass_cargaForzadaDeDatos(Passenger* listPass, int sizeArray);
int pass_consignaCuatroUno(Passenger* listPass, int sizeArray, typePass* listaTipoPasajeros, int sizeListaTipoPasajeros);
int pass_consignaCuatroDos(Passenger* listPass, int sizeArray);
int pass_acumuladorTotalPreciosCargados(Passenger* listPass, int sizeArray, float* acumuladorPrecios);
int pass_contadorPreciosSuperanPromedio(Passenger* listPass, int sizeArray, float promedio);
int pass_encontrarMayorId(Passenger* listPass, int sizeArray, int* ultimoId);
int pass_contadorClientesCargados(Passenger* listPass, int sizeArray, int* contador);
/*int pass_initArray(Passenger* listPass, int sizeListPass); //initPassengers
int pass_initAPossition(Passenger* listPass, int indice, int valorInicial);
int pass_printArray(Passenger* listPass, int sizeListPass); //printPassenger
int pass_printOneIndice(Passenger* listPass, int indice);
void pass_printRotulo(void);

int pass_pedirNuevoPasajero(Passenger* listPass, int sizePass, int ultimoId);
int pass_encontrarPrimerIndiceIsEmpty(Passenger* listPass, int sizePass);
int pass_agregarPasajeroAlArray(Passenger* listPass, int sizePass, int ultimoId, char* nombre, char* apellido, float precio, char* codigoVuelo, int tipoPasajero, int estadoVuelo); //addPassenger (le agregue parametro para el estado del vuelo)

int pass_cambiarNombre(Passenger* listPass, int idCambio);
int pass_cambiarApellido(Passenger* listPass, int idCambio);
int pass_cambiarPrecio(Passenger* listPass, int idCambio);
int pass_cambiarTipoPasajero(Passenger* listPass, int idCambio);
int pass_cambiarCodigoVuelo(Passenger* listPass, int idCambio);

int pass_pedirNombre(char* nombre, int sizeNombre);
int pass_pedirApellido(char* apellido, int sizeApellido);
float pass_pedirPrecio(float* precio);
int pass_pedirCodigoVuelo(char* codigoVuelo, int sizeCodigoVuelo);
int pass_pedirEstadoVuelo(int* estadoVuelo);
int pass_pedirTipoPasajero(int* tipoPasajero);

int pass_pedirIdConsulta(int idUltimo);
int pass_encontrarPasajeroPorId(Passenger* listPass, int sizePass, int idConsulta); //findPassengerById

int pass_removerSegunId(Passenger* arrayPasajeros, int indexIdConsulta); //removePassenger !!!!!!!!!! refactorizar para que quede lis, len, id

int pass_prepararArray(Passenger* pArray, int sizeArray, int clientesCargados);
int pass_interaccionMenuSecundario(Passenger* pArray, int sizeArray, int indexConsulta);
void pass_cambiarNombreEImprimir(Passenger* pArray, int index);
void pass_cambiarApellidoEImprimir(Passenger* pArray, int index);
void pass_cambiarPrecioEImprimir(Passenger* pArray, int index);
void pass_cambiarTipoPasajeroEImprimir(Passenger* pArray, int index);
void pass_cambiarCodigoVueloEImprimir(Passenger* pArray, int index);

int pass_swap(Passenger* listPass, int index1, int index2);
int pass_ordenarArrayPorNombreOTipo(Passenger* listPass, int sizeArray, int criterio);//sortPassengers
int pass_acumuladorTotalPreciosCargados(Passenger* listPass, int sizeArray, float* acumuladorPrecios);
int pass_contadorPreciosSuperanPromedio(Passenger* listPass, int sizeArray, float promedio);
int pass_ordenarArrayPorCodigo(Passenger* listPass, int sizeArray, int criterio);//sortPassengersByCode

int pass_cargaForzadaDeDatos(Passenger* listPass, int sizeArray);

int pass_consignaCuatroUno(Passenger* listPass, int sizeArray);
int pass_consignaCuatroDos(Passenger* listPass, int sizeArray);

int pass_encontrarMayorId(Passenger* listPass, int sizeArray, int* ultimoId);
int pass_contadorClientesCargados(Passenger* listPass, int sizeArray, int* contador);*/
#define PASSENGER_H_

#endif /* PASSENGER_H_ */

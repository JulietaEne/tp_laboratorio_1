/*
 * arrays.h
 *
 *  Created on: 12 abr. 2022
 *      Author: julieta_enee
 */

#ifndef ARRAYS_H_
#define ARRAYS_H_

int array_inicializar(int unArray[], int sizeArray, int inicializar);
int array_asignarValorAUnaPosicion(int unArray[], int unaPosicion, int valor);
int arrayInt_imprimirArrayCompleto(int unArray[], int sizeArray);
int array_imprimirArraySinInicializados(int unArray[], int sizeArray);
int arrayInt_imprimirPosicionArray(int unArray[], int unaPosicion);
int array_cargarSecuencial(int unArray[], int sizeArray, int minimoPosible, int maximoPosible, int reintentos);
int array_cargarAleatorio(int unArray[], int sizeArray, int* indice, int valor);
int array_acumuladorPositivos(int unArray[], int sizeArray, int* acumuladorPositivos);
int array_acumuladorNegativos(int unArray[], int sizeArray, int* acumuladorNegativos);
int array_identificarMenorNumero(int unArray[], int sizeArray, int* menorNumero);
int array_identificarMayorNumero(int unArray[], int sizeArray, int* mayorNumero);
int arrayInt_sortNumeros(int unArray[], int sizeArray, int criterio);
int arrayInt_sortNumerosSinCriterio(int unArray[], int sizeArray);


////// ############################### { ARRAY FLOAT } ############################### //////
int array_floatInicializar(float unArray[], int sizeArray, float inicializar);
int array_floatAsignarValorAUnaPosicion(float unArray[], int unaPosicion, float valor);
int array_floatImprimirArrayCompleto(float unArray[], int sizeArray);
int array_floatImprimirArraySinInicializados(float unArray[], int sizeArray);
int array_floatImprimirPosicionArray(float unArray[], int unaPosicion);
int array_floatCargarSecuencial(float unArray[], int sizeArray, float minimoPosible, float maximoPosible, int reintentos);
int array_floatCargarAleatorio(float unArray[], int sizeArray, int* indice, float valor);
int array_floatAcumuladorPositivos(float unArray[], int sizeArray, float* acumuladorPositivos);
int array_floatAcumuladorNegativos(float unArray[], int sizeArray, float* acumuladorNegativos);
int array_floatIdentificarMenorNumero(float unArray[], int sizeArray, float* menorNumero);
//int array_floatsortNumeros(int unArray[], int sizeArray, int criterio);

////// ############################### { ARRAY CHAR } ############################### //////
int arrayChar_convertirStringMayuscula(char unString[], int sizeArray);
int arrayChar_convertirStringMinuscula(char unString[], int sizeArray);
int arrayChar_visualizarApellidoNombre(char nombre[], char apellido[], char apellidoNombre[], int lenApellidoNombre);
int arrayChar_plusInt(char unString[], int sizeString);
int arrayChar_convertirASustantivoPropio(char unString[], int sizeString);
int arrayChar_eliminarTodosLosEspacios(char unString[], int sizeString);
int arrayChar_reemplazarCaracter(char* cadena, int sizeCadena, char charAReemplazar, char charReemplazo);



#endif /* ARRAYS_H_ */

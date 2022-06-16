/*
 * album.h
 *
 *  Created on: 29 abr. 2022
 *      Author: julieta_enee
 */

#ifndef ALBUM_H_
#define ALBUM_H_
#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
#include "utn.h"
#include "tp.h"
#include "arrays.h"
#include <string.h>



#define QTY_ALBUM 10

#define IS_DELETED -1
#define ID_INICIAL 100
#define ID_MAXIMO 1000
#define STR_SIZE 50
#define MAX_PRECIO 5000
#define MIN_PRECIO 700

#define REINTENTOS 1
#define MAX_ARTISTA 10
#define MIN_ARTISTA 1
#define IS_EMPTY 0
#define NOT_EMPTY 1
#define ID_ART_INICIAL 1
#define QTY_ARTIST 10
#define QTY_GENERO 4
#define QTY_TYPE 2

#define MAX_DAY 31
#define MAX_FEB 28
#define MAX_DAY_TWO 30
#define MAX_MONTH 12
#define MAX_YEAR 2022
#define MIN_YEAR 1920

#define QTY_TIPO_ALBUM 3
#define VINILO 1


struct
{
	int idArtista;
	char nombre [51];
	int isEmpty;
	//int tipoArtistaFk; no se pide explicitamente

}typedef eArtista;

struct
{
    int day;
    int month;
    int year;
}typedef eFecha;

struct
{
	int idGenero;
	char descripcion[51];
	int isEmpty;

}typedef eGenero;

struct{

	int idTipoArtista;
	char descripcion[51];
	int isEmpty;

}typedef eTipoArtista;

struct{

	int idTipoAlbum;
	char descripcion[51];
	int isEmpty;

}typedef eTipoAlbum;

struct{
	int idAlbum;
	char titulo[51];
	eFecha fecha;
	float importe;
	int artistaFk; //solicitado en el 5-H
	int generoFk; //no se solicita explicitamente ***falta cargar e imprimir
	int tipoArtistaFk; //cargado ***falta imprimir
	int tipoAlbumFk; //consigna parte 2
	int isEmpty;
}typedef eAlbum;


int alb_initLista(eAlbum* listaAlbum, int sizeListaAlbum);
int alb_initPosicion(eAlbum* listaAlbum, int indice, int valorInicial);
int alb_indicarUltimoId(eAlbum* listaAlbum, int sizeListaAlbum, int* ultimoId);
int alb_contadorAlbumesCargados(eAlbum* listaAlbum, int sizeListaAlbum, int* cantidadCargados);
int alb_printLista(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtita, int sizeListaArtista, eTipoAlbum* listaTipoAlbum, int sizeListaTipoAlbum);
int alb_printPosicion(eAlbum* listaAlbum, int indiceAlbum);
int alb_printPosicionConArtista(eAlbum* listaAlbum, int indiceAlbum, eArtista* listaArtita, int indiceArtista);
void alb_printEncabezado(void);
int alb_findPorCodigo(eAlbum* listaAlbum, int sizeListaAlbum, int idConsulta);

int alb_getTitulo(char* titulo, int sizeTitulo);
int alb_getImporte(float* importe);
int alb_getFecha(eFecha* fechaAlbum);
int alb_getArtista(eArtista* listaArtistas, int sizeListaArtista, int* idArtista);
int alb_findPrimerEspacioLibreEnLista(eAlbum* listaAlbum, int sizeListaAlbum);
int alb_getNuevoAlbum(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtista, int sizeListaArtista, eTipoAlbum* listaTipoAlbum, int sizeListTipoAlbum);
int alb_cargarUnNuevoAlbumAlArray(char* tituloAlbum, int sizeTituloAlbum, eFecha* fechaAlbum, float importeAlbum, int idArtistaAlbum, eAlbum* listaAlbum, int sizeListaAlbum, int tipoArtista, int tipoAlbum);
int alb_solicitarCodigo(int* idSolicitado, eAlbum* listaAlbum, int sizeListaAlbum);
int alb_cargaForzadaDeDatos(eAlbum* listaAlbum, int sizeListaAlbum);

int alb_setTitulo(eAlbum* listaAlbum, int indexCambio);
int alb_setFecha(eAlbum* listaAlbum, int indexCambio);
int alb_setImporte(eAlbum* listaAlbum, int indexCambio);
int alb_removerAlbum(eAlbum* listaAlbum, int indexCambio);


int informes_totalImportes(eAlbum* listaAlbum, int sizeListAlbum, float* totalImporte);
int informes_informarTotalyPromedioDeImportes(eAlbum* listaAlbum, int sizeListAlbum);
int informes_cacularCantidadQueSuperaPromedio(eAlbum* listaAlbum, int sizeListAlbum, float promedio);
int informes_informarCantAlbumPrevioAlDosMil(eAlbum* listaAlbum, int sizeListAlbum);

int alb_printListaAlbumes(eAlbum* listaAlbum, int sizeListAlbum);
int alb_printCodigoYTItulo(eAlbum* listaAlbum, int indice);
void alb_printEncabezadoCodYTit(void);

int listar_printAlbumPrevioAlDosMil(eAlbum* listaAlbum, int sizeListAlbum);
int listar_calcularTotalyPromedioDeImportes(eAlbum* listaAlbum, int sizeListAlbum);
int listar_printAlbumQueSuperaPromedio(eAlbum* listaAlbum, int sizeListAlbum, float promedio);
float listar_findPrecioMasCaro(eAlbum* listaAlbum, int sizeListaAlbum);
int listar_printAlbumesMasCaros(eAlbum* listaAlbum, int sizeListaAlbum);
int listar_printAlbumPorArtista(eArtista* listaArtistas, int sizeListaArtista, eAlbum* listaAlbum, int sizeListaAlbum);
int listar_printYear(eAlbum* listaAlbum, int sizeListaAlbum);
int listar_printAlbumeSegunAnio(eAlbum* listaAlbum, int sizeListaAlbum);

//******************************************************************************

eFecha fecha_newFecha(void);
int art_idUltimoArtista(eArtista* listaArtistas, int sizeListaArtista);
int art_pedirArtista(eArtista* listaArtistas, int sizeListaArtista);
int art_printListaArtista(eArtista* listaArtistas, int sizeListaArtista);
int art_printNombreArtista(eArtista* listaArtistas, int sizeListaArtista, int idArtista);
int art_printPosicion(eArtista* listaArtistas, int indice);
int art_findArtistaPorId(eArtista* listaArtistas, int sizeListaArtista, int idConsulta);
void art_printEncabezado(void);
int art_cargaForzadaDeDatos(eArtista* listaArtistas, int sizeListaArtista);
//_________________________________________________________________________--
int genero_cargaForzadaDeDatos(eGenero* listaGeneros, int sizeGeneros);
int genero_printListaGenero(eGenero* listaGeneros, int sizeGenero);
int genero_printPosicion(eGenero* listaGeneros, int indice);
void genero_printEncabezado(void);
//__________________________________________________________________________--
int type_cargaForzadaDeDatos(eTipoArtista* listaTypes, int sizeTypes);
int type_printListaType(eTipoArtista* listaTypes, int sizeTypes);
int type_printPosicion(eTipoArtista* listaTypes, int indice);
void type_printEncabezado(void);

int alb_swap(eAlbum* listaAlbum, int index1, int index2);
int listar_sortAlbumSegunCriterio(eAlbum* listaAlbum, int sizeListAlbu, int criterio);
int listar_sortAlbum(eAlbum* listaAlbum, int sizeListAlbu, eArtista* listaArtista, int sizeListArtista, eTipoAlbum* listaTipoAlbum, int sizeListaTipoAlbum);
//*******************************************************************************
//CONSIGNAS PP LABO PARTE 2
int tipoAlbum_cargaForzadaDeDatos(eTipoAlbum* listaTipoALbum, int sizelistaTipoALbum);
int tipoAlbum_printListaTipoAlbum(eTipoAlbum* listaTipoALbum, int sizelistaTipoALbum);
int tipoAlbum_printPosicion(eTipoAlbum* listaTipoALbum, int indice);
void tipoAlbum_printEncabezado(void);
int tipoAlbum_pedirTipoAlbum(eTipoAlbum* listaTipoALbum, int sizelistaTipoALbum);
int alb_getTipoAlbum(eTipoAlbum* listaTipoAlbum, int sizelistaTipoALbum, int* idTipoAlbum);
int alb_setTipoAlbum(eAlbum* listaAlbum, int indexCambio, eTipoAlbum* listaTipoAlbum, int sizelistaTipoALbum);
int alb_printPosicionConArtistaYTipoAlbum(eAlbum* listaAlbum, int indiceAlbum, eArtista* listaArtita, int indiceArtista, eTipoAlbum* listaTipoAlbum, int indiceTipoAlbum);
int tipoAlbum_printTipoAlbumSegunId(eTipoAlbum* listaTipoAlbum, int sizelistaTipoAlbum, int idTipoAlbum);
int tipoAlbum_listarAlbumDistintoVinilo(eTipoAlbum* listaTipoAlbum, int sizeTipoAlbum, eAlbum* listaAlbum, int sizeListaAlbum);
int tipoAlbum_printViniloSegunArtista(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtistas, int sizeListaArtistas);
//int alb_initLista(eAlbum* listaAlbum, int sizeListaAlbum);
//int alb_initPosicion(eAlbum* listaAlbum, int sizeListaAlbum, int indice);
//int alb_printLista(eAlbum* listaAlbum, int sizeListaAlbum);
//int alb_printPosicion(eAlbum* listaAlbum, int sizeListaAlbum, int indice);

//void alb_printEncabezado(void);

//______________________________________________________________-
/*1) alta de algunos albumes*/
//int alb_findPrimerEspacioLibreEnLista(eAlbum* listaAlbum, int sizeListaAlbum);
//int alb_ingresarNuevoAlbum(eAlbum* listaAlbum, int sizeListaAlbum, int ultimoId);
//int alb_cargarUnNuevoAlbumAlArray(/*aca van todos los datos que necesito para cargarlo*/); //va dentro de ingresar nuevo album
//int alb_indicarUltimoId(eAlbum* listaAlbum, int sizeListaAlbum, int* ultimoId);
//int alb_contadorAlbumesCargados(eAlbum* listaAlbum, int sizeListaAlbum, int* cantidadCargados);

/* aca van todas las funciones que necesito para interactuar con el usuario al cargar un albom*/
//int alb_pedirTitulo(char* titulo, int sizeTitulo);
//int fecha??
//float alb_pedirImporte(float* importe);
//int alb_pedirArtista(int* artista);//este va a invocar a la estructura eArtista porque precisa mostrar su contenido para dar opciones al usuario (que ingresa una opcion por numero)

/*2) Modificar titulo fecha importe*/
//int alb_cambiarTitulo(char* titulo, int sizeTitulo);
// cambiar fecha??
//float alb_cambiarImporte(float* importe);

//__________________________________________________________________-

//int alb_pedirCodigo(int ultimoId); //2 y 3
//int alb_findPorCodigo(eAlbum* listaAlbum, int sizeListaAlbum, int idConsulta); //2 y 3

/*3) baja segun codigo*/
//int alb_removeSegunId(eAlbum* listaAlbum, int idConsulta); //3 realizar baja logica

//__________________________________________________________________-
//funciones de auxilio

//int alb_swap(eAlbum* listaAlbum, int indice1, int indece2);// 5- E
//int alb_sortByImporte(eAlbum* listaAlbum, int sizeListaAlbum);
//int alb_sortByTitulo(eAlbum* listaAlbum, int sizeListaAlbum);


/**
 * 4) INFORMAR
 * 		a- TOTAL y PROMEDIO de los importes. ¿Cuantos albumes superan el promedio?
 * 		b- CANTIDAD de albumes cuya fecha de publicacion sea anterior a 1/1/2000
 *
 * 5) LISTAR
 * 		a- todos los generos (estructura genero) -> recorro array principal en el campo .genero y comparo los elementos(por ejemplo, busco el mas chico y lo guardo en una variable y al terminar de recorrer el for (con un flag) muestro el char que representa esa variable en su estructura originaria. Luego hago màs comparaciones hasta llegar al ultimo numero
 * 		b- todos los tipos de artistas musicales (estructura tipoArtista que son 2)
 * 		c- todos los artistas (estructura artista)
 * 		d- todos los albumes (recorro el array principal)
 * 		e- un listado de los albumbes ordenados x swap
 * 		f- todos los albumes cuya fecha de publicacion es anterior al 1/1/2000
 * 		g- todos los albumes qu esuperan el promedio de importes
 * 		h- todos los albumes de cada artista (recorro por artista, y voy mostrando)
 * 		i- todos los albumes de un año determinado (tengo que solicitar el ingreso de un año)
 * 		j- el o los albumes más caros (tengo que recorrer todos los precios, guardarme el valor más alto y luego volver a recorrer para printear todos los que tengan ese valor en el campo .price)
 *
 *
 *
 *
 *
 *
 *//*
int alb_pedirArtista(int* idArtista, eArtista* listaArtista, int sizeListaArtista)
{
	int retorno;
	int auxIdArtista;

	retorno = -1;
	auxIdArtista= art_pedirArtista(listaArtista, sizeListaArtista);


	//int auxIndex;
	//auxIndex = art_findArtistaPorId(listaArtista, sizeListaArtista, auxIdArtista);
	//printf("DEBUG******** un artista: %s\n", listaArtista[auxIndex].nombre);

	if(auxIdArtista>0)
	{
		*idArtista=auxIdArtista;
		retorno =0;
	}
	return retorno;
}*/




#endif /* ALBUM_H_ */

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
#define QTY_ARTISTAS 4
#define QTY_GENERO_ALBUM 3
#define QTY_TIPO_DE_ARTISTA 2

#define MAX_DAY 31
#define MAX_FEB 28
#define MAX_DAY_TWO 30
#define MAX_MONTH 12
#define MAX_YEAR 2022
#define MIN_YEAR 1920

#define QTY_FORMATOS_ALBUM 3
#define VINILO 1


struct
{
    int day;
    int month;
    int year;
}typedef eFecha;

struct{
	int idTipoArtista;
	char descripcion[51];
	int isEmpty;
}typedef eTipoArtista;

struct
{
	int idArtistaDelAlbum;
	char nombre [51];
	int isEmpty;
	//int tipoArtistaFk; no se pide explicitamente
}typedef eArtista;

struct
{
	int idGeneroDelAlbum;
	char descripcion[51];
	int isEmpty;
}typedef eGenero;

struct{

	int idFormatoDelAlbum;
	char descripcion[51];
	int isEmpty;

}typedef eTipoAlbum;

struct{
	int codigoIdAlbum;
	char titulo[51];
	eFecha fechaPublicacionAlbum;
	float importeAlbum;
	int artistaDelAlbumFk; //solicitado en el 5-H
	int generoDelAlbumFk; //no se solicita explicitamente ***falta cargar e imprimir
	int tipoArtistaFk; //cargado ***falta imprimir
	int formatoDelAlbumFk; //consigna parte 2
	int isEmpty;
}typedef eAlbum;


int alb_initPosicionListaAlbum(eAlbum* listaAlbum, int indiceRecibido, int valorInicial);
int alb_initListaAlbum(eAlbum* listaAlbum, int sizeListaAlbum);
int alb_findPrimerEspacioLibreEnLista(eAlbum* listaAlbum, int sizeListaAlbum);
int alb_cargaForzadaDatosDeAlbum(eAlbum* listaAlbum, int sizeListaAlbum);
int generoAlbum_cargaForzadaDeGeneroDeAlbum(eGenero* listaGenerosDeAlbum, int sizeListaGenerosDeAlbum);
int art_cargaForzadaDeArtistas(eArtista* listaArtistas, int sizeListaArtistas);
int tipoArtista_cargaForzadaTipoDeArtista(eTipoArtista* listaTiposDeArtista, int sizeListaTiposDeArtista);
int alb_indicarUltimoId(eAlbum* listaAlbum, int sizeListaAlbum, int* ultimoId);
int inicioPrograma(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtistas, int sizeListaArtistas, eGenero* listaGenerosDeAlbum, int sizeListaGenerosDeAlbum, eTipoArtista* listaTiposDeArtista, int sizeListaTiposDeArtista, eTipoAlbum* listaFormatosALbum, int sizelistaFormatosAlbum, int* ultimoId);
int alb_contadorAlbumesCargados(eAlbum* listaAlbum, int sizeListaAlbum);
int alb_printUnAlbum(int indexRecibidoAlbum, eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtistas, int sizeListaArtistas, eGenero* listaGenerosDeAlbum, int sizeListaGenerosDeAlbum, eTipoArtista* listaTiposDeArtista, int sizeListaTiposDeArtista, eTipoAlbum* listaFormatosALbum, int sizeListaFormatosAlbum);
int getNombreArtistaDelAlbum(int unAlbum, eAlbum* listaAlbum, eArtista* listaArtistas, int sizeListaArtistas, char* auxNombreArtista);
int getDescripcionFormatoAlbum(int unAlbum, eAlbum* listaAlbum, eTipoAlbum* listaFormatosAlbum, int sizeListaFormatosAlbum, char* auxFormatoVentaDeAlbum);
int getDescripcionGeneroDelAlbum(int unAlbum, eAlbum* listaAlbum, eGenero* listaGenerosDeAlbum, int sizeListaGenerosDeAlbum, char* auxGeneroAlbum);
int getDescripcionTipoArtista(int unAlbum, eAlbum* listaAlbum, eTipoArtista* listaTiposDeArtista, int sizeListaTiposDeArtista, char* auxTipoArtista);
void alb_printEncabezado(void);
int alb_printListaCompleta(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtistas, int sizeListaArtistas, eGenero* listaGenerosDeAlbum, int sizeListaGenerosDeAlbum, eTipoArtista* listaTiposDeArtista, int sizeListaTiposDeArtista, eTipoAlbum* listaFormatosALbum, int sizeListaFormatosAlbum);
int alb_cargarUnNuevoAlbumAlArray(eAlbum* listaAlbum, int sizeListaAlbum, int indexCarga, char* tituloAlbum, int sizeTituloAlbum, eFecha* fechaDePublicacion, float importeAlbum, int idNombreArtistaFk, int idTipoArtistaFk, int idFormatoVentadeAlbumFk, int idGeneroAlbumFk, int codigoIdAlbum);
int alb_getNuevoAlbum(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtistas, int sizeListaArtistas, eGenero* listaGenerosDeAlbum, int sizeListaGenerosDeAlbum, eTipoArtista* listaTiposDeArtista, int sizeListaTiposDeArtista, eTipoAlbum* listaFormatosALbum, int sizeListaFormatosAlbum, int ultimoCodigoIdAlbum);
int alb_getTituloAlbum(char* tituloAlbum, int sizeTituloAlbum);
int alb_getFechaDePublicacion(eFecha* fechaDePublicacion);
eFecha fecha_newFecha(void);
int alb_getImporte(float* importeAlbum);
int alb_getArtistaPorId(eArtista* listaArtistas, int sizeListaArtista, int* idNombreArtistaFk);
int art_pedirArtista(eArtista* listaArtistas, int sizeListaArtista);
int art_printListaArtista(eArtista* listaArtistas, int sizeListaArtista);
void art_printEncabezado(void);
int art_printArtistaPorIndex(eArtista* listaArtistas, int indiceRecibidoArtistas);
int alb_getTipoArtista(int* idTipoArtistaFk);
int alb_getFormatoVentaAlbumPorId(eTipoAlbum* listaFormatosALbum, int sizeListaFormatosAlbum, int* idFormatoVentadeAlbumFk);
int formatoAlbum_pedirFormatoAlbum(eTipoAlbum* listaFormatosALbum, int sizeListaFormatosAlbum);
int formatoAlbum_printListaFormatoVentaDeAlbum(eTipoAlbum* listaFormatosALbum, int sizeListaFormatosALbum);
void formatoAlbum_printEncabezado(void);
int formatoAlbum_printPosicionFormatosAlbumPorIndex(eTipoAlbum* listaFormatosAlbum, int indiceRecibidoFormatosAlbum);
int alb_getGeneroAlbumPorId(eGenero* listaGenerosDeAlbum, int sizeListaGenerosDeAlbum,int* idGeneroAlbumFk);
int generoAlbum_pedirGeneroDeAlbum(eGenero* listaGenerosDeAlbum, int sizeListaGenerosDeAlbum);
int generoAlbum_printListaGenerosDeAlbum(eGenero* listaGenerosDeAlbum, int sizeListaGenerosDeAlbum);
void generoAlbum_printEncabezado(void);
int generoAlbum_printPosicionGenerosPorIndex(eGenero* listaGenerosDeAlbum, int indiceRecibidoGenerosAlbum);

//**********************************************************
//PP LABO - PARTE 2
int formatoAlbum_cargaForzadaFormatosAlbum(eTipoAlbum* listaFormatosALbum, int sizelistaFormatosAlbum);

#endif /* ALBUM_H_ */

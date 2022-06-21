/*
 * correcciones.h
 *
 *  Created on: 15 jun. 2022
 *      Author: julieta_enee
 */

#ifndef CORRECCIONES_H_
#define CORRECCIONES_H_

#include "album.h"
//#include "artista.h"
//#include "genero.h"
//#include "tipo-artista.h"


int inicioPrograma(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtistas, int sizeListaArtista, eGenero* listaGeneros, int sizeGeneros, eTipoArtista* listaTypes, int sizeTypes, eTipoAlbum* listaTipoALbum, int sizelistaTipoALbum, int* ultimoId);
int modificarAlbum(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtista, int sizeListaArtista, eTipoAlbum* listaTipoAlbum, int sizeListTipoAlbum,eGenero* listaGeneros, int sizeGeneros);
int modificarAlbumOpciones(int auxIndex, eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtista, int sizeListaArtista, eTipoAlbum* listaTipoAlbum, int sizeListTipoAlbum,eGenero* listaGeneros, int sizeGeneros);
int getForeingeKeys(int indexAlbum, eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtista, int sizeListaArtista, eTipoAlbum* listaTipoAlbum, int sizeListTipoAlbum, eGenero* listaGeneros, int sizeGeneros, char* auxArtista, char* auxTipoAlbum, char* auxGenero);
int getNombreArtista(int indexAlbum, eAlbum* listaAlbum, int sizeListaAlbum,  eArtista* listaArtista, int sizeListaArtista, char* auxArtista);
int getTipoAlbum(int indexAlbum, eAlbum* listaAlbum, int sizeListaAlbum, eTipoAlbum* listaTipoAlbum, int sizeListTipoAlbum, char* auxTipoAlbum);
int getGenero(int indexAlbum, eAlbum* listaAlbum, int sizeListaAlbum, eGenero* listaGeneros, int sizeGeneros, char* auxGenero);
int getTipoArt(int indexAlbum, eAlbum* listaAlbum, int sizeListaAlbum, eTipoArtista* listaTypes, int sizeTypes, char* auxTipoArtista);
int printPosicion(int indexAlbum, eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtista, int sizeListaArtista, eTipoAlbum* listaTipoAlbum, int sizeListTipoAlbum, eGenero* listaGeneros, int sizeGeneros);
int printListaAlbum(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtita, int sizeListaArtista, eTipoAlbum* listaTipoAlbum, int sizeListaTipoAlbum,eGenero* listaGenero, int sizeListaGenero);void consultaMostrarLista(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtista, int sizeListaArtista, eTipoAlbum* listaTipoAlbum, int sizeListTipoAlbum,eGenero* listaGeneros, int sizeGeneros);
int deleteAlbum(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtita, int sizeListaArtista, eTipoAlbum* listaTipoAlbum, int sizeListaTipoAlbum,eGenero* listaGenero, int sizeListaGenero);
int puntoCinco(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtista, int sizeListaArtista, eTipoAlbum* listaTipoAlbum, int sizeListaTipoAlbum,eGenero* listaGenero, int sizeListaGenero, eTipoArtista* listaType, int sizeListType);
int mostrarAlbumPrecioMayorAlPromedio(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtista, int sizeListaArtista, eTipoAlbum* listaTipoAlbum, int sizeListaTipoAlbum,eGenero* listaGenero, int sizeListaGenero);
int mostrarAlbumesPorArtista(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtista, int sizeListaArtista, eTipoAlbum* listaTipoAlbum, int sizeListaTipoAlbum,eGenero* listaGenero, int sizeListaGenero);
int imprimirSegunAnio(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtista, int sizeListaArtista, eTipoAlbum* listaTipoAlbum, int sizeListaTipoAlbum,eGenero* listaGenero, int sizeListaGenero);
int printAlbumesMasCaros(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtista, int sizeListaArtista, eTipoAlbum* listaTipoAlbum, int sizeListaTipoAlbum,eGenero* listaGenero, int sizeListaGenero);
int printAlbumNoVinilo(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtista, int sizeListaArtista, eTipoAlbum* listaTipoAlbum, int sizeListaTipoAlbum,eGenero* listaGenero, int sizeListaGenero);
int printViniloSegunArtista(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtista, int sizeListaArtista, eTipoAlbum* listaTipoAlbum, int sizeListaTipoAlbum,eGenero* listaGenero, int sizeListaGenero);

#endif /* CORRECCIONES_H_ */

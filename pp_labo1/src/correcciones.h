/*
 * correcciones.h
 *
 *  Created on: 15 jun. 2022
 *      Author: julieta_enee
 */

#ifndef CORRECCIONES_H_
#define CORRECCIONES_H_

#include "album.h"
#include "artista.h"
#include "genero.h"
#include "tipo-artista.h"


int inicioPrograma(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtistas, int sizeListaArtista, eGenero* listaGeneros, int sizeGeneros, eTipoArtista* listaTypes, int sizeTypes, eTipoAlbum* listaTipoALbum, int sizelistaTipoALbum);
int modificarAlbum(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtista, int sizeListaArtista, eTipoAlbum* listaTipoAlbum, int sizeListTipoAlbum,eGenero* listaGeneros, int sizeGeneros);
int getForeingeKeys(int indexAlbum, eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtista, int sizeListaArtista, eTipoAlbum* listaTipoAlbum, int sizeListTipoAlbum, eGenero* listaGeneros, int sizeGeneros, char* auxArtista, char* auxTipoAlbum, char* auxGenero);
int getNombreArtista(int indexAlbum, eAlbum* listaAlbum, int sizeListaAlbum,  eArtista* listaArtista, int sizeListaArtista, char* auxArtista);
int getTipoAlbum(int indexAlbum, eAlbum* listaAlbum, int sizeListaAlbum, eTipoAlbum* listaTipoAlbum, int sizeListTipoAlbum, char* auxTipoAlbum);
int getGenero(int indexAlbum, eAlbum* listaAlbum, int sizeListaAlbum, eGenero* listaGeneros, int sizeGeneros, char* auxGenero);
int printPosicion(int indexAlbum, eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtista, int sizeListaArtista, eTipoAlbum* listaTipoAlbum, int sizeListTipoAlbum, eGenero* listaGeneros, int sizeGeneros);




#endif /* CORRECCIONES_H_ */

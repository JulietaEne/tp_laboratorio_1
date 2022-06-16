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
int modificarAlbum(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtista, int sizeListaArtista, eTipoAlbum* listaTipoAlbum, int sizeListTipoAlbum);
int modificarAlbum(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtista, int sizeListaArtista, eTipoAlbum* listaTipoAlbum, int sizeListTipoAlbum);

#endif /* CORRECCIONES_H_ */

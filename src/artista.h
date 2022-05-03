/*
 * artista.h
 *
 *  Created on: 29 abr. 2022
 *      Author: julieta_enee
 */

#ifndef ARTISTA_H_
#define ARTISTA_H_
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "validaciones.h"


#define REINTENTOS 1
#define MAX_ARTISTA 10
#define MIN_ARTISTA 1
#define IS_EMPTY 0
#define NOT_EMPTY 1
#define ID_ART_INICIAL 1
#define QTY_ARTIST 10

struct
{
	int idArtista;
	char nombre [51];
	int isEmpty;
	//int tipoArtistaFk; no se pide explicitamente

}typedef eArtista;


int art_idUltimoArtista(eArtista* listaArtistas, int sizeListaArtista);
int art_pedirArtista(eArtista* listaArtistas, int sizeListaArtista);
int art_printListaArtista(eArtista* listaArtistas, int sizeListaArtista);
int art_printNombreArtista(eArtista* listaArtistas, int sizeListaArtista, int idArtista);
int art_printPosicion(eArtista* listaArtistas, int indice);
int art_findArtistaPorId(eArtista* listaArtistas, int sizeListaArtista, int idConsulta);
void art_printEncabezado(void);
int art_cargaForzadaDeDatos(eArtista* listaArtistas, int sizeListaArtista);


#endif /* ARTISTA_H_ */

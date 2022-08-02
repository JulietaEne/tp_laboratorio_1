/*
 * funciones_genericas.c
 *
 *  Created on: 1 ago. 2022
 *      Author: julieta_enee
 */



/*
 * \brief la lista de artistas y su tamaño e imprime su contenido.
 * \param listaArtistas eArtista* Recibe la direccion de memoria del array
 * \param sizeListaArtista int Recibe por valor el tamaño del array

 * \return retorna int -1 si hubo un error en los parametros recibidos
 * 						0 si la operacion se realizo correctamente

int print_unaLista(int codigoLista, eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtistas, int sizeListaArtistas, eGenero* listaGenerosDeAlbum, int sizeListaGenerosDeAlbum, eTipoArtista* listaTiposDeArtista, int sizeListaTiposDeArtista, eTipoAlbum* listaFormatosALbum, int sizeListaFormatosAlbum)
{
	int retorno;
	int i;

	retorno = -1;
	if(listaAlbum != NULL && sizeListaAlbum>0 && listaArtistas != NULL && sizeListaArtistas>0 && listaGenerosDeAlbum != NULL && sizeListaGenerosDeAlbum >0 && listaTiposDeArtista != NULL && sizeListaTiposDeArtista >0 && listaFormatosALbum != NULL && sizeListaFormatosAlbum>0)
	{
		retorno = 0;
		print_unEncabezado(4);
		for(i=0; i<sizeLista; i++)
		{
			if( !validacionesInt_sonIdenticos(pLista[i].isEmpty,IS_EMPTY))
			{
				art_printArtistaPorIndex(pLista, i);
			}
		}
	}
	return retorno;
}


int init_unaLista(int codigoLista, eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtistas, int sizeListaArtistas, eGenero* listaGenerosDeAlbum, int sizeListaGenerosDeAlbum, eTipoArtista* listaTiposDeArtista, int sizeListaTiposDeArtista, eTipoAlbum* listaFormatosALbum, int sizeListaFormatosAlbum)
{
	int retorno;
	int i;

	retorno = -1;
	if(listaAlbum != NULL && sizeListaAlbum>0 && listaArtistas != NULL && sizeListaArtistas>0 && listaGenerosDeAlbum != NULL && sizeListaGenerosDeAlbum >0 && listaTiposDeArtista != NULL && sizeListaTiposDeArtista >0 && listaFormatosALbum != NULL && sizeListaFormatosAlbum>0)
	{

	}
}
 */

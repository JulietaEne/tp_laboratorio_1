/*
 * correcciones.c
 *
 *  Created on: 15 jun. 2022
 *      Author: julieta_enee
 */

#include "correcciones.h"

int inicioPrograma(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtistas, int sizeListaArtista, eGenero* listaGeneros, int sizeGeneros, eTipoArtista* listaTypes, int sizeTypes, eTipoAlbum* listaTipoALbum, int sizelistaTipoALbum)
{
	int retorno;
	retorno = -1;

	if(listaAlbum != NULL && listaArtistas != NULL && listaGeneros && listaTypes != NULL)
	{
		alb_initLista(listaAlbum, QTY_ALBUM);
		alb_cargaForzadaDeDatos(listaAlbum, QTY_ALBUM);
		art_cargaForzadaDeDatos(listaArtistas, QTY_ARTIST);
		genero_cargaForzadaDeDatos(listaGeneros, QTY_GENERO);
		type_cargaForzadaDeDatos(listaTypes, QTY_TYPE);
		tipoAlbum_cargaForzadaDeDatos(listaTipoALbum, sizelistaTipoALbum);
		retorno =0;
	}
	return retorno;
}

int modificarAlbum(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtista, int sizeListaArtista, eTipoAlbum* listaTipoAlbum, int sizeListTipoAlbum)
{
	int retorno;
	int aceptarConsulta;
	int idSolicitado;
	int auxIndex;
	int flag;
	int menuSecundario;

	retorno = -1;
	flag = 0;


		aceptarConsulta = continuar("desea imprimir la lista de albumes? Y/N");
		if(aceptarConsulta)
		{
			alb_printLista(listaAlbum, sizeListaAlbum, listaArtista, sizeListaArtista, listaTipoAlbum, sizeListTipoAlbum);
		}

		do
		{
			alb_solicitarCodigo(&idSolicitado, listaAlbum, sizeListaAlbum);
			auxIndex = alb_findPorCodigo(listaAlbum, sizeListaAlbum, idSolicitado);
			if(auxIndex>=0)
			{
				alb_printEncabezado();
				alb_printPosicion(listaAlbum, auxIndex);
				do
				{
					menuSecundario= tp_ImprimirMenuSeisOpciones("\n\nIndique el campo que desea modificar: ", "1- Titulo", "2- Fecha de Publicacion", "3- Importe", "4- Imprimir cambios", "5- Tipo Album", "6- Volver atras");
					switch (menuSecundario) {
						case 1:
							//modificar titulo
							alb_setTitulo(listaAlbum, auxIndex);
							break;
						case 2:
							//modificar fecha
							alb_setFecha(listaAlbum, auxIndex);
							break;
						case 3:
							//modificar importe
							alb_setImporte(listaAlbum, auxIndex);
							break;
						case 4:
							//imprimo los cambios
							alb_printPosicion(listaAlbum, auxIndex);
							break;
						case 5:
							//camiar tipo album
							alb_setTipoAlbum(listaAlbum, auxIndex, listaTipoAlbum, QTY_TIPO_ALBUM);
							break;
					}
				}while(menuSecundario<6 );
				flag = 1;
			}
			else
			{
				aceptarConsulta = continuar("Desea cancelar? Y/N");
			}
		}while(!flag ||!aceptarConsulta);


	return retorno;
}

/*int modificarAlbum(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtista, int sizeListaArtista, eTipoAlbum* listaTipoAlbum, int sizeListTipoAlbum)
{
	int retorno;
	retorno = -1;
	alb_solicitarCodigo(&auxCodigo, listAlbum, QTY_ALBUM);
	auxIndex = alb_findPorCodigo(listAlbum, QTY_ALBUM, auxCodigo);
	if(auxIndex>=0)
	{
		alb_printEncabezado();
		alb_printPosicion(listAlbum, auxIndex);
		respContinuar=continuar("\nConfirma eliminar el album?");
		if(respContinuar && !alb_removerAlbum(listAlbum, auxIndex))
		{
			printf("se ha eliminado exitosamente");
			alb_printLista(listAlbum, QTY_ALBUM, listArtista, QTY_ALBUM, listaTipoAlbum, QTY_TIPO_ALBUM);
		}
		else
		{
			printf("ha habido un error en el codigo ingresado\n");
		}
	}
	return retorno;
}*/




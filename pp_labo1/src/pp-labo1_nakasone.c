/*
 ============================================================================
 Name        : TP_[2].c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Nakasone Julieta
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "album.h"
#include "utn.h"
#include "arrays.h"
#include "tp.h"
#include "correcciones.h"

int main(void) {

	int menuPrincipal;
	int contadorCargados;
	eAlbum listAlbum[QTY_ALBUM];
	int ultimoId;
	eArtista listArtista[QTY_ARTIST];
	eGenero listaGenero[QTY_GENERO];
	eTipoArtista listaType[QTY_TYPE];
	eTipoAlbum listaTipoAlbum[QTY_TIPO_ALBUM];
	int retornoFuncion;
	//int menuSecundario;

	printf("Alumna: NAKASONE JULIETA\nPrograma para Administrar albumes de artistas musicales\n");
	ultimoId=ID_INICIAL;
	do
	{
		if(ultimoId==ID_INICIAL)
		{
			inicioPrograma(listAlbum, QTY_ALBUM, listArtista, QTY_ARTIST, listaGenero, QTY_GENERO, listaType, QTY_TYPE, listaTipoAlbum, QTY_TIPO_ALBUM, &ultimoId);
			contadorCargados=alb_contadorAlbumesCargados(listAlbum, QTY_ALBUM);
		}
		menuPrincipal = tp_ImprimirMenuSeisOpciones("\n\nMENU", "1- Alta de album", "2- Modificacion de album", "3- Baja de album", "4- Informes", "5- Listas solicitadas", "6- PARTE 2 EXAMEN");
		switch (menuPrincipal)
		{
			case 1:
				printf("\n\nALTA DE ALBUM\n");
				if(!alb_getNuevoAlbum(listAlbum, QTY_ALBUM, listArtista, QTY_ARTIST, listaTipoAlbum, QTY_TIPO_ALBUM, listaGenero, QTY_GENERO, ultimoId))
				{
					ultimoId++;
					contadorCargados ++;
				}
				else
				{
					tp_MensajeError("\nNo se ha podido ingresar correctamente el album");
				}
				break;

			case 2:
				printf("\nMODIFICAR ALBUM\n");
				if(contadorCargados>0)
				{
					modificarAlbum(listAlbum, QTY_ALBUM, listArtista, QTY_ARTIST, listaTipoAlbum, QTY_TIPO_ALBUM, listaGenero, QTY_GENERO);
				}
				else
				{
					printf("Aun no se han cargado datos en el programa\n");
				}
				break;
			case 3:
				printf("\nBORRAR ALBUM\n");
				if(contadorCargados>0)
				{
				   retornoFuncion = deleteAlbum(listAlbum, QTY_ALBUM, listArtista, QTY_ARTIST, listaTipoAlbum, QTY_TIPO_ALBUM, listaGenero, QTY_GENERO);
				   switch(retornoFuncion)
				   {
				       case -1:
				            printf("Error - no se ha ingresado un codigo cargado en la lista \n");
				            break;
				       case -2:
				            printf("Se ha cancelado el Borrado de Album\n");
				            break;
				       case 0:
    				       printf("se ha eliminado correctamente");
    				       contadorCargados--;
				           break;
				   }
				}
				else
				{
					printf("Aun no se han cargado datos en el programa\n");
				}
				break;
			case 4:
				printf("\nINFORMES\n");
				if(contadorCargados>0)
				{
					informes_informarTotalyPromedioDeImportes(listAlbum, QTY_ALBUM);
					informes_informarCantAlbumPrevioAlDosMil(listAlbum, QTY_ALBUM);
				}
				break;
			case 5:
				printf("\nListas");
				if(contadorCargados>0)
				{
					puntoCinco(listAlbum, QTY_ALBUM, listArtista, QTY_ARTIST, listaTipoAlbum, QTY_TIPO_ALBUM,listaGenero, QTY_GENERO, listaType, QTY_TYPE);
				}
				break;
			case 6:
				printf("\nCONSIGNAS PARTE 2 EXAMEN\n");
				 // OK La entidad Tipo de Album, la misma contendrá:
				//	OK Campos: id y descripción.
				//	OK Datos: 1, vinilo; 2, cinta; 3, CD.
				//tipoAlbum_cargaForzadaDeDatos(listaTipoAlbum, QTY_TIPO_ALBUM);
				//	 Listar todos los tipos de álbumes.
				printf("\n\nListar todos los tipos de álbumes.\n");
				tipoAlbum_printListaTipoAlbum(listaTipoAlbum, QTY_TIPO_ALBUM);
				//OK Agregar el Tipo de álbum al Alta y Modificación de álbumes.
				//get y set
				//OK Listar todos los albumes que no sean de vinilo.
				printf("\n\nListar todos los albumes que no sean de vinilo\n");
				tipoAlbum_listarAlbumDistintoVinilo(listaTipoAlbum, QTY_TIPO_ALBUM, listAlbum, QTY_ALBUM);
				//	 Listar todos los albumes de vinilo que correspondan a un artista determinado.
				printf("\n\nListar todos los albumes de vinilo que correspondan a un artista determinado.\n");
				tipoAlbum_printViniloSegunArtista(listAlbum, QTY_ALBUM, listArtista, QTY_ARTIST);

				break;
		}



	}while(menuPrincipal != 6);
return EXIT_SUCCESS;
}

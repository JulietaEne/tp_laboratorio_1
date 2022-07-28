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
//#include "correcciones.h"

int main(void) {

	int menuPrincipal;
	int contadorCargados;
	eAlbum listAlbum[QTY_ALBUM];
	int ultimoCodigoIdAlbum;
	eArtista listArtista[QTY_ARTISTAS];
	eGenero listaGenero[QTY_GENERO_ALBUM];
	eTipoArtista listaType[QTY_TIPO_DE_ARTISTA];
	eTipoAlbum listaTipoAlbum[QTY_FORMATOS_ALBUM];
	int retornoFuncion;
	//int menuSecundario;

	printf("Alumna: NAKASONE JULIETA\nPrograma para Administrar albumes de artistas musicales  Primer Parcial Labo1 + Recuperatorio 1 + Recuperatorio 2\n\n");
	ultimoCodigoIdAlbum=ID_INICIAL;

	do
	{
		if(ultimoCodigoIdAlbum==ID_INICIAL)
		{
			inicioPrograma(listAlbum, QTY_ALBUM, listArtista, QTY_ARTISTAS, listaGenero, QTY_GENERO_ALBUM, listaType, QTY_TIPO_DE_ARTISTA, listaTipoAlbum, QTY_FORMATOS_ALBUM, &ultimoCodigoIdAlbum);
			contadorCargados=alb_contadorAlbumesCargados(listAlbum, QTY_ALBUM);
		}
		menuPrincipal = tp_ImprimirMenuSeisOpciones("\n\nMENU", "1- Alta de album", "2- Modificacion de album", "3- Baja de album", "4- Informes", "5- Listas solicitadas", "6- PARTE 2 EXAMEN -- RECUPERATORIO\n7- SALIR");
		switch (menuPrincipal)
		{
			case 1:
				printf("\n\nALTA DE ALBUM\n");
				retornoFuncion = alb_getNuevoAlbum(listAlbum, QTY_ALBUM, listArtista, QTY_ARTISTAS, listaGenero, QTY_GENERO_ALBUM, listaType, QTY_TIPO_DE_ARTISTA, listaTipoAlbum, QTY_FORMATOS_ALBUM, ultimoCodigoIdAlbum);
				switch(retornoFuncion){
					case 0:
						ultimoCodigoIdAlbum++;
						contadorCargados ++;
						break;
					case -1:
						tp_MensajeError("\nNo se ha podido ingresar correctamente el album");
						break;
					case -2:
						tp_MensajeError("\nNo se ha podido ingresar correctamente el album. La lista no tiene más espacios libres");
						break;
				}
				break;

			/*case 2:
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
				printf("\nCONSIGNAS PARTE 2 EXAMEN -- RECUPERATORIO\n");

				printf("\n\nListar todos los tipos de álbumes.\n");
				tipoAlbum_printListaTipoAlbum(listaTipoAlbum, QTY_TIPO_ALBUM);

				printf("\n\nListar todos los albumes que no sean de vinilo\n");
				printAlbumNoVinilo(listAlbum, QTY_ALBUM, listArtista, QTY_ARTIST, listaTipoAlbum, QTY_TIPO_ALBUM, listaGenero, QTY_GENERO);
*/
				/*printf("\n\nListar todos los albumes de vinilo que correspondan a un artista determinado.\n");
				do{
					printViniloSegunArtista(listAlbum, QTY_ALBUM, listArtista, QTY_ARTIST, listaTipoAlbum, QTY_TIPO_ALBUM, listaGenero, QTY_GENERO);
					retornoFuncion = continuar("desea consultar otro artista?");
				}while(retornoFuncion);*/

				/*
				 * Informar la cantidad de álbumes de un tipo de álbum determinado y de un género determinado.*/
				/*do{
					recu_puntoUno(listAlbum, QTY_ALBUM, listArtista, QTY_ARTIST, listaGenero, QTY_GENERO, listaType, QTY_TYPE, listaTipoAlbum, QTY_TIPO_ALBUM);
					retornoFuncion = continuar("desea consultar otro artista?");
				}while(retornoFuncion);*/
				/*
					 Realizar un solo listado de todos los álbumes de solistas de un año determinado. El listado debe tener los
					siguientes datos: Id, Título, Fecha de publicación, Importe, Descripción del género, Descripción del tipo
					de artista, Descripción del artista y Descripción del tipo de álbum.
				 *
				 * */


				//break;
		}
	}while(menuPrincipal != 7);
	printf("Saliendo...\n Muchas gracias!");
return EXIT_SUCCESS;
}

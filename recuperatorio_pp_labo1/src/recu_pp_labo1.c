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
	eArtista listaArtistas[QTY_ARTISTAS];
	eGenero listaGenerosDeAlbum[QTY_GENERO_ALBUM];
	eTipoArtista listaTiposDeArtista[QTY_TIPO_DE_ARTISTA];
	eTipoAlbum listaFormatosAlbum[QTY_FORMATOS_ALBUM];
	int retornoFuncion;
	//int menuSecundario;

	printf("Alumna: NAKASONE JULIETA\nPrograma para Administrar albumes de artistas musicales  Primer Parcial Labo1 + Recuperatorio 1 + Recuperatorio 2\n\n");
	ultimoCodigoIdAlbum=ID_INICIAL;

	do
	{
		if(ultimoCodigoIdAlbum==ID_INICIAL)
		{
			inicioPrograma(listAlbum, QTY_ALBUM, listaArtistas, QTY_ARTISTAS, listaGenerosDeAlbum, QTY_GENERO_ALBUM, listaTiposDeArtista, QTY_TIPO_DE_ARTISTA, listaFormatosAlbum, QTY_FORMATOS_ALBUM, &ultimoCodigoIdAlbum);
			contadorCargados=alb_contadorAlbumesCargados(listAlbum, QTY_ALBUM);
		}
		menuPrincipal = tp_ImprimirMenuSeisOpciones("\n\nMENU", "1- Alta de album", "2- Modificacion de album", "3- Baja de album", "4- Informes", "5- Listas solicitadas", "6- 2da Parte del Examen \n7- Recuperatorio \n8- RECUPERATORIO INSTANCIA FINAL\n9- Salir");
		switch (menuPrincipal)
		{
			case 1:
				printf("\n\nALTA DE ALBUM\n");
				retornoFuncion = programa_getNuevoAlbum(listAlbum, QTY_ALBUM, listaArtistas, QTY_ARTISTAS, listaGenerosDeAlbum, QTY_GENERO_ALBUM, listaTiposDeArtista, QTY_TIPO_DE_ARTISTA, listaFormatosAlbum, QTY_FORMATOS_ALBUM, ultimoCodigoIdAlbum);
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

			case 2:
				printf("\nMODIFICAR ALBUM\n");
				if(contadorCargados>0)
				{
					programa_modificarAlbum(listAlbum, QTY_ALBUM, listaArtistas, QTY_ARTISTAS, listaGenerosDeAlbum, QTY_GENERO_ALBUM, listaTiposDeArtista, QTY_TIPO_DE_ARTISTA, listaFormatosAlbum, QTY_FORMATOS_ALBUM);
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
				   retornoFuncion = programa_deleteAlbum(listAlbum, QTY_ALBUM, listaArtistas, QTY_ARTISTAS, listaGenerosDeAlbum, QTY_GENERO_ALBUM, listaTiposDeArtista, QTY_TIPO_DE_ARTISTA, listaFormatosAlbum, QTY_FORMATOS_ALBUM);
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
					informes_informarCantAlbumsPreviosAlDosMil(listAlbum, QTY_ALBUM);
				}
				else
				{
					printf("Aun no se han cargado datos en el programa\n");
				}
				break;
			case 5:
				printf("\nListas");
				if(contadorCargados>0)
				{
					puntoCinco(listAlbum, QTY_ALBUM, listaArtistas, QTY_ARTISTAS, listaGenerosDeAlbum, QTY_GENERO_ALBUM, listaTiposDeArtista, QTY_TIPO_DE_ARTISTA, listaFormatosAlbum, QTY_FORMATOS_ALBUM);
				}
				else
				{
					printf("Aun no se han cargado datos en el programa\n");
				}
				break;
			case 6:
				printf("\nCONSIGNAS EXAMEN PARTE 2\n");
				if(contadorCargados>0)
				{
					consignasParteDosExamen(listAlbum, QTY_ALBUM, listaArtistas, QTY_ARTISTAS, listaGenerosDeAlbum, QTY_GENERO_ALBUM, listaTiposDeArtista, QTY_TIPO_DE_ARTISTA, listaFormatosAlbum, QTY_FORMATOS_ALBUM);
				}
				else
				{
					printf("Aun no se han cargado datos en el programa\n");
				}
				break;
			case 7:
				printf("\nCONSIGNAS RECUPERATORIO\n");
				if(contadorCargados>0)
				{
					consignasRecuperatorio(listAlbum, QTY_ALBUM, listaArtistas, QTY_ARTISTAS, listaGenerosDeAlbum, QTY_GENERO_ALBUM, listaTiposDeArtista, QTY_TIPO_DE_ARTISTA, listaFormatosAlbum, QTY_FORMATOS_ALBUM);
				}
				break;
			case 8:
				printf("\nCONSIGNAS RECUPERATORIO INSTANCIA FINAL 4/8/2022\n");
				if(contadorCargados>0)
				{
					consignasRecuperatorioInstanciaFinal(listAlbum, QTY_ALBUM, listaArtistas, QTY_ARTISTAS, listaGenerosDeAlbum, QTY_GENERO_ALBUM, listaTiposDeArtista, QTY_TIPO_DE_ARTISTA, listaFormatosAlbum, QTY_FORMATOS_ALBUM);
				}
				break;
		}
	}while(menuPrincipal != 9);
	printf("Saliendo...\n Muchas gracias!");
return EXIT_SUCCESS;
}

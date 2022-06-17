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
	//int ultimoId;
	eArtista listArtista[QTY_ARTIST];
	eGenero listaGenero[QTY_GENERO];
	eTipoArtista listaType[QTY_TYPE];
	eTipoAlbum listaTipoAlbum[QTY_TIPO_ALBUM];
	int auxCodigo;
	int auxIndex;
	int menuSecundario;
	int respContinuar;

	contadorCargados= -1;
	printf("Alumna: NAKASONE JULIETA\nPrograma para Administrar albumes de artistas musicales\n");
	//alb_initLista(listAlbum, QTY_ALBUM);
	contadorCargados = -1;
	/***carga forzada**
	alb_initLista(listAlbum, QTY_ALBUM);
	alb_cargaForzadaDeDatos(listAlbum, QTY_ALBUM);
	art_cargaForzadaDeDatos(listArtista, QTY_ARTIST);
	genero_cargaForzadaDeDatos(listaGenero, QTY_GENERO);
	type_cargaForzadaDeDatos(listaType, QTY_TYPE);

	**carga forzada**
	********PARTE 2***********
	tipoAlbum_cargaForzadaDeDatos(listaTipoAlbum, QTY_TIPO_ALBUM);
	alb_printLista(listAlbum, QTY_ALBUM, listArtista, QTY_ALBUM, listaTipoAlbum, QTY_TIPO_ALBUM);*/
	do
	{
		if(contadorCargados == -1)
		{
			inicioPrograma(listAlbum, QTY_ALBUM, listArtista, QTY_ARTIST, listaGenero, QTY_GENERO, listaType, QTY_TYPE, listaTipoAlbum, QTY_TIPO_ALBUM);
			contadorCargados = 1;//0
			//printf("init ok");
		}
		//alb_contadorAlbumesCargados(listAlbum, QTY_ALBUM, &contadorCargados);
		printf("\n***contador %d", contadorCargados);
		menuPrincipal = tp_ImprimirMenuSeisOpciones("\n\nMENU", "1- Alta de album", "2- Modificacion de album", "3- Baja de album", "4- Informes", "5- Listas solicitadas", "6- PARTE 2 EXAMEN");
		switch (menuPrincipal)
		{
			case 1:
				printf("\n\nALTA DE ALBUM\n");
				if(!alb_getNuevoAlbum(listAlbum, QTY_ALBUM, listArtista, QTY_ARTIST, listaTipoAlbum, QTY_TIPO_ALBUM))
				{
					contadorCargados ++;
					//alb_printLista(listAlbum, QTY_ALBUM, listArtista, QTY_ALBUM, listaTipoAlbum, QTY_TIPO_ALBUM);
				}
				else
				{
					tp_MensajeError("\nNo se ha podido ingresar correctamente el album");
				}
				break;

			case 2:
				printf("\nMODIFICAR ALBUM\n");
				if(contadorCargados > 0)
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
				if(contadorCargados > 0)
				{
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
				}
				break;
			case 4:
				printf("\nINFORMES\n");
				alb_contadorAlbumesCargados(listAlbum, QTY_ALBUM, &contadorCargados);
				if(contadorCargados > 0)
				{
					informes_informarTotalyPromedioDeImportes(listAlbum, QTY_ALBUM);
					informes_informarCantAlbumPrevioAlDosMil(listAlbum, QTY_ALBUM);
				}
				break;
			case 5:
				printf("\nListas");
				alb_contadorAlbumesCargados(listAlbum, QTY_ALBUM, &contadorCargados);
				if(contadorCargados > 0)
				{
					do
					{
						menuSecundario= tp_ImprimirMenuOnceOpciones("\n\nIndique el tipo de lista que desea visualizar: ", "1- Generos", "2- Tipos Artistas", "3- Artistas", "4- Albumes", "5- Ordenar Albumes", "6- Mostrar Album previos al 2000","7- Albumes que superan promedio de importes","8- Albumes por artista","9- Albumes segun anio","10- ALbum mas caro", "11- Volver Atras");
						switch (menuSecundario) {
							case 1:
								//listar Generos
								genero_printListaGenero(listaGenero, QTY_GENERO);
								break;
							case 2:
								//listar Tipo Artistas
								type_printListaType(listaType, QTY_TYPE);

								break;
							case 3:
								//listar artistas
								art_printListaArtista(listArtista, QTY_ARTIST);
								break;

							case 4:
								//listar albumes
								alb_printListaAlbumes(listAlbum, QTY_ALBUM);
								break;
							case 5:
								//ordenar albumes por criterio -importe (descendente) -Titulo(ascendente)
								//ARREGLAR EN UNA SOLA LISTA !
								listar_sortAlbum(listAlbum, QTY_ALBUM, listArtista, QTY_ARTIST, listaTipoAlbum, QTY_TIPO_ALBUM);
								break;
							case 6:
								//mostrar previos al 2000
								listar_printAlbumPrevioAlDosMil(listAlbum, QTY_ALBUM);
								break;
							case 7:
								//albumes que superan el promedio
								listar_calcularTotalyPromedioDeImportes(listAlbum, QTY_ALBUM);
								break;
							case 8:
								//albumes por artista
								listar_printAlbumPorArtista(listArtista, QTY_ARTIST, listAlbum, QTY_ALBUM);
								break;
							case 9:
								//Albumes segun añio: indicar año
								listar_printAlbumeSegunAnio(listAlbum, QTY_ALBUM);
								break;
							case 10:
								//album mas caro
								listar_printAlbumesMasCaros(listAlbum, QTY_ALBUM);
								break;
						}
					}while(menuSecundario<11 );
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
	//contadorCargados = -1;
/*
	do
	{
		menuPrincipal = tp_ImprimirMenuSeisOpciones("MENU", "1- Alta de album", "2- Modificacion de album", "3- Baja de album", "4- Informes", "5- Listas solicitadas", "salir");
		switch (menuPrincipal)
		{
			case 1:
				printf("ALTA DE ALBUM\n");
				if(contadorCargados == -1)
				{
					//quiere decir que es el primer uso del programa: hay que inicializar la lista
					alb_initLista(listAlbum, QTY_ALBUM);
					alb_indicarUltimoId(listAlbum, QTY_ALBUM, &ultimoId);
					alb_contadorAlbumesCargados(listAlbum, QTY_ALBUM, &contadorCargados);
				}
				if(alb_ingresarNuevoAlbum(listAlbum, QTY_ALBUM, ultimoId)>=0)
				{
					alb_printLista(listAlbum, QTY_ALBUM);
				}
				else
				{
					tp_MensajeError("\nNo se ha podido ingresar correctamente el album");
				}
				break;

			case 2:
				printf("MODIFICAR ALBUM");
				if(contadorCargados > 0)
				{
					auxCodigoConsulta = alb_indicarUltimoId(listAlbum, QTY_ALBUM, &ultimoId);
					auxIndex = alb_findPorCodigo(listAlbum, QTY_ALBUM, auxCodigoConsulta);

				}
				break;
			case 3:
				printf("BORRAR ALBUM");
				if(contadorCargados > 0)
				{
					auxCodigoConsulta = alb_indicarUltimoId(listAlbum, QTY_ALBUM, &ultimoId);
					auxIndex = alb_findPorCodigo(listAlbum, QTY_ALBUM, auxCodigoConsulta);

				}
				break;
		}




	}while(menuPrincipal != 6);



*/
return EXIT_SUCCESS;
}

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
#include "artista.h"



int main(void) {

	int menuPrincipal;
	int contadorCargados;
	eAlbum listAlbum[QTY_ALBUM];
	int ultimoId;
	eArtista listArtista[QTY_ARTIST];
	int auxCodigo;
	int auxIndex;
	int menuSecundario;
	int respContinuar;

	contadorCargados= -1;
	printf("Alumna: NAKASONE JULIETA\n\nPrograma para Administrar albumes de artistas musicales ");
	alb_initLista(listAlbum, QTY_ALBUM);
	alb_cargaForzadaDeDatos(listAlbum, QTY_ALBUM);

	do
	{
		menuPrincipal = tp_ImprimirMenuSeisOpciones("\n\nMENU", "1- Alta de album", "2- Modificacion de album", "3- Baja de album", "4- Informes", "5- Listas solicitadas", "6- Salir");
		switch (menuPrincipal)
		{
			case 1:
				printf("\n\nALTA DE ALBUM\n");
				if(contadorCargados == -1)
				{
					//quiere decir que es el primer uso del programa: hay que inicializar la lista
					//alb_initLista(listAlbum, QTY_ALBUM);
					alb_indicarUltimoId(listAlbum, QTY_ALBUM, &ultimoId);
					alb_contadorAlbumesCargados(listAlbum, QTY_ALBUM, &contadorCargados);
					art_cargaForzadaDeDatos(listArtista, QTY_ARTIST);

				}
				if(!alb_getNuevoAlbum(listAlbum, QTY_ALBUM, listArtista, QTY_ARTIST))
				{
					alb_printLista(listAlbum, QTY_ALBUM, listArtista, QTY_ALBUM);
				}
				else
				{
					tp_MensajeError("\nNo se ha podido ingresar correctamente el album");
				}
				break;

			case 2:
				printf("\nMODIFICAR ALBUM\n");
				alb_contadorAlbumesCargados(listAlbum, QTY_ALBUM, &contadorCargados);
				//printf("**contador: %d", contadorCargados);
				if(contadorCargados > 0)
				{
					alb_solicitarCodigo(&auxCodigo, listAlbum, QTY_ALBUM);
					auxIndex = alb_findPorCodigo(listAlbum, QTY_ALBUM, auxCodigo);
					if(auxIndex>=0)
					{
						alb_printEncabezado();
						alb_printPosicion(listAlbum, auxIndex);
						do
						{
							menuSecundario= tp_ImprimirMenuSeisOpciones("\n\nIndique el campo que desea modificar: ", "1- Titulo", "2- Fecha de Publicacion", "3- Importe", "4- Imprimir cambios", "5- Volver atras", "\n");
							switch (menuSecundario) {
								case 1:
									//modificar titulo
									alb_setTitulo(listAlbum, auxIndex);
									break;
								case 2:
									//modificar fecha
									alb_setFecha(listAlbum, auxIndex);
									break;
								case 3:
									//modificar importe
									alb_setImporte(listAlbum, auxIndex);
									break;
								case 4:
									//imprimo los cambios
									alb_printPosicion(listAlbum, auxIndex);
									break;
							}
						}while(menuSecundario<5 );
					}
					else
					{
						printf("ha habido un error en el codigo ingresado\n");
					}
				}
				break;
			case 3:
				printf("\nBORRAR ALBUM\n");
				alb_contadorAlbumesCargados(listAlbum, QTY_ALBUM, &contadorCargados);
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
							alb_printLista(listAlbum, QTY_ALBUM, listArtista, QTY_ALBUM);
						}
						else
						{
							printf("ha habido un error en el codigo ingresado\n");
						}
					}
				}
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

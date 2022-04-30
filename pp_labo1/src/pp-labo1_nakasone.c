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

#define QTY_ALBUM 15

int main(void) {

	eAlbum unAlbum;
	eAlbum listAlbum[];
	int menuPrincipal;
	int auxCodigoConsulta;
	int auxIndex;
	int menuSecundario;
	int cotadorCargados;
	int ultimoId;

	cotadorCargados = -1;

	printf("NAKASONE JULIETA\n\nPrograma para Administrar albumes de artistas musicales\n ");
	do
	{
		menuPrincipal = tp_ImprimirMenuSeisOpciones("MENU", "1- Alta de album", "2- Modificacion de album", "3- Baja de album", "4- Informes", "5- Listas solicitadas", "salir");
		switch (menuPrincipal)
		{
			case 1:
				printf("ALTA DE ALBUM\n");
				if(cotadorCargados == -1)
				{
					//quiere decir que es el primer uso del programa: hay que inicializar la lista
					alb_initLista(listAlbum, QTY_ALBUM);
					alb_indicarUltimoId(listAlbum, QTY_ALBUM, &ultimoId);
					alb_contadorAlbumesCargados(listAlbum, QTY_ALBUM, &cotadorCargados);
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
				if(cotadorCargados > 0)
				{
					auxCodigoConsulta = alb_indicarUltimoId(listAlbum, QTY_ALBUM, &ultimoId);
					auxIndex = alb_findPorCodigo(listAlbum, QTY_ALBUM, auxCodigoConsulta);

				}
				break;
		}




	}while(menuPrincipal != 6);




return EXIT_SUCCESS;
}

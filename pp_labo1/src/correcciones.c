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

int modificarAlbum(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtista, int sizeListaArtista, eTipoAlbum* listaTipoAlbum, int sizeListTipoAlbum,eGenero* listaGeneros, int sizeGeneros)
{
	int retorno;
	int aceptarConsulta;
	int idSolicitado;
	int auxIndex;
	//int flagSalir;
	int menuSecundario;

	retorno = -1;
	//flagSalir = 0;
		aceptarConsulta = continuar("desea imprimir la lista de albumes? Y/N");
		if(aceptarConsulta)
		{
			alb_printLista(listaAlbum, sizeListaAlbum, listaArtista, sizeListaArtista, listaTipoAlbum, sizeListTipoAlbum, listaGeneros, sizeGeneros);
		}
		alb_solicitarCodigo(&idSolicitado, listaAlbum, sizeListaAlbum);
		auxIndex = alb_findPorCodigo(listaAlbum, sizeListaAlbum, idSolicitado);
		if(auxIndex>=0)
		{
			//alb_printEncabezado();
			//alb_printPosicion(listaAlbum, auxIndex);arreglar
			printPosicion(auxIndex,listaAlbum,sizeListaAlbum, listaArtista, sizeListaArtista, listaTipoAlbum, sizeListTipoAlbum, listaGeneros, sizeGeneros);

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
						alb_printEncabezado();
						printPosicion(auxIndex,listaAlbum,sizeListaAlbum, listaArtista, sizeListaArtista, listaTipoAlbum, sizeListTipoAlbum, listaGeneros, sizeGeneros);
						//alb_printPosicion(listaAlbum, auxIndex);
						break;
					case 5:
						//camiar tipo album
						alb_setTipoAlbum(listaAlbum, auxIndex, listaTipoAlbum, QTY_TIPO_ALBUM);
						break;
					case 6:
						//camiar tipo album
						//flagSalir = 1;
						break;
				}
			}while(menuSecundario<6 );
		}
		else
		{
			aceptarConsulta = continuar("Desea cancelar la operacion? Y/N");
		}

	return retorno;
}

/* Se encarga de matchear el codigo ID de la entidad eAlbum con la descripción de las entidades eArtista, eTipoAlbum, eGenero y devuelve la información hayada por parámetro
 *
 *
**/
int getForeingeKeys(int indexAlbum, eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtista, int sizeListaArtista, eTipoAlbum* listaTipoAlbum, int sizeListTipoAlbum, eGenero* listaGeneros, int sizeGeneros, char* auxArtista, char* auxTipoAlbum, char* auxGenero)
{
    int retorno;
    //int i;

    retorno = -1;
    if( indexAlbum >0 && listaAlbum!= NULL && sizeListaAlbum>0 && listaArtista!= NULL && sizeListaArtista  >0 && listaTipoAlbum!= NULL && sizeListTipoAlbum >0 && listaGeneros!= NULL && sizeGeneros>0 && auxArtista != NULL && auxGenero != NULL && auxTipoAlbum != NULL)
	{
	    getNombreArtista(indexAlbum, listaAlbum, sizeListaAlbum, listaArtista, sizeListaArtista, auxArtista);
	    /*for(i=0;i<sizeListaArtista; i++)
	    {
	        if(listaAlbum[indexAlbum].artistaFk == listaArtista[i].idArtista)
	        {
	            strncpy(auxArtista, listaArtista[i].nombre, STR_SIZE);
	            break;
	        }
	    }*/
	    getTipoAlbum(indexAlbum,listaAlbum, sizeListaAlbum,listaTipoAlbum, sizeListTipoAlbum,auxTipoAlbum);
	    /*for(i=0;i<sizeListTipoAlbum; i++)
	    {
	        if(listaAlbum[indexAlbum].tipoAlbumFk== listaTipoAlbum[i].idTipoAlbum)
	        {
	            strncpy(auxTipoAlbum, listaTipoAlbum[i].descripcion, STR_SIZE);
	            break;
	        }
	    }*/
	    getGenero(indexAlbum,listaAlbum,sizeListaAlbum,listaGeneros, sizeGeneros,auxGenero);
	    /*for(i=0;i<sizeGeneros; i++)
	    {
	        if(listaAlbum[indexAlbum].tipoAlbumFk== listaGeneros[i].idGenero)
	        {
	            strncpy(auxGenero, listaGeneros[i].descripcion, STR_SIZE);
	            break;
	        }
	    }*/
	}
    return retorno;
}

int getNombreArtista(int indexAlbum, eAlbum* listaAlbum, int sizeListaAlbum,  eArtista* listaArtista, int sizeListaArtista, char* auxArtista)
{
    int retorno;
    int i;
    retorno =-1;
    if(indexAlbum >= 0 && listaAlbum != NULL && sizeListaAlbum>0 && listaArtista != NULL && sizeListaArtista >0 && auxArtista)
    {
        for(i=0;i<sizeListaArtista; i++)
	    {
	        if(listaAlbum[indexAlbum].artistaFk == listaArtista[i].idArtista)
	        {
	            strncpy(auxArtista, listaArtista[i].nombre, STR_SIZE);
	            break;
	        }
	    }
    }
    return retorno;
}

int getTipoAlbum(int indexAlbum, eAlbum* listaAlbum, int sizeListaAlbum, eTipoAlbum* listaTipoAlbum, int sizeListTipoAlbum, char* auxTipoAlbum)
{
    int retorno;
    int i;
    retorno =-1;
    if(indexAlbum >= 0 && listaAlbum != NULL && sizeListaAlbum>0 && listaTipoAlbum != NULL && sizeListTipoAlbum >0 && auxTipoAlbum)
    {
        for(i=0;i<sizeListTipoAlbum; i++)
	    {
	        if(listaAlbum[indexAlbum].tipoAlbumFk== listaTipoAlbum[i].idTipoAlbum)
	        {
	            strncpy(auxTipoAlbum, listaTipoAlbum[i].descripcion, STR_SIZE);
	            break;
	        }
	    }
    }
    return retorno;
}

int getGenero(int indexAlbum, eAlbum* listaAlbum, int sizeListaAlbum, eGenero* listaGeneros, int sizeGeneros, char* auxGenero)
{
    int retorno;
    int i;
    retorno =-1;
    if(indexAlbum >= 0 && listaAlbum != NULL && sizeListaAlbum>0 && listaGeneros != NULL && sizeGeneros >0 && auxGenero)
    {
        for(i=0;i<sizeGeneros; i++)
	    {
	        if(listaAlbum[indexAlbum].tipoAlbumFk== listaGeneros[i].idGenero)
	        {
	            strncpy(auxGenero, listaGeneros[i].descripcion, STR_SIZE);
	            break;
	        }
	    }
    }
    return retorno;
}

int printPosicion(int indexAlbum, eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtista, int sizeListaArtista, eTipoAlbum* listaTipoAlbum, int sizeListTipoAlbum, eGenero* listaGeneros, int sizeGeneros)
{
	int retorno;
	char auxArtista[STR_SIZE];
	char auxTipoAlbum[STR_SIZE];
	char auxGenero[STR_SIZE];
	retorno =-1;
	if(indexAlbum >=0 && listaAlbum != NULL && sizeListaAlbum >0 && listaArtista != NULL && sizeListaArtista >0 && listaTipoAlbum != NULL && sizeListTipoAlbum >0 && listaGeneros != NULL && sizeGeneros >0)
	{

		getNombreArtista(indexAlbum, listaAlbum, sizeListaAlbum, listaArtista, sizeListaArtista, auxArtista);
		getTipoAlbum(indexAlbum, listaAlbum, sizeListaAlbum, listaTipoAlbum, sizeListTipoAlbum, auxTipoAlbum);
		getGenero(indexAlbum, listaAlbum, sizeListaAlbum, listaGeneros, sizeGeneros, auxGenero);
		//alb_printEncabezado();
		printf("%s %9d %15s %d/%d/%d %15.2f %18s %s\n",  auxTipoAlbum,
													listaAlbum[indexAlbum].idAlbum,
													listaAlbum[indexAlbum].titulo,
													listaAlbum[indexAlbum].fecha.day,
													listaAlbum[indexAlbum].fecha.month,
													listaAlbum[indexAlbum].fecha.month,
													listaAlbum[indexAlbum].importe,
													auxArtista,
													auxGenero);
	}
	return retorno;
}

/*
 * \brief Recorre el array recibido para imprimir los indices que estan cargados
 * \param listaAlbum eAlbum* Recibe la direccion de memoria del array sobre el cual va a trabajar
 * \param sizeListaAlbum int Recibe por valor el tamaño del array
 * \return retorna int -1 si hubo un error en los parametros recibidos
 * 						0 si la operacion se realizo correctamente
 */

int printListaAlbum(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtita, int sizeListaArtista, eTipoAlbum* listaTipoAlbum, int sizeListaTipoAlbum,eGenero* listaGenero, int sizeListaGenero)
{
	int retorno;
	int i;
	//int j;
	retorno = -1;
	if(listaAlbum != NULL && sizeListaAlbum>0 && listaArtita != NULL && sizeListaArtista>0 && listaTipoAlbum != NULL && sizeListaTipoAlbum >0 && listaGenero != NULL && sizeListaGenero >0)
	{
		retorno = 0;
		alb_printEncabezado();
		for(i=0; i<sizeListaAlbum; i++)
		{
			if(listaAlbum[i].isEmpty==NOT_EMPTY)
			{
				printPosicion(i, listaAlbum, sizeListaAlbum, listaArtita, sizeListaArtista, listaTipoAlbum, sizeListaTipoAlbum, listaGenero, sizeListaGenero);
			}
		}
	}
	return retorno;
}

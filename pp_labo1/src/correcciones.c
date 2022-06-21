/*
 * correcciones.c
 *
 *  Created on: 15 jun. 2022
 *      Author: julieta_enee
 */

#include "correcciones.h"

int inicioPrograma(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtistas, int sizeListaArtista, eGenero* listaGeneros, int sizeGeneros, eTipoArtista* listaTypes, int sizeTypes, eTipoAlbum* listaTipoALbum, int sizelistaTipoALbum, int* ultimoId)
{
	int retorno;
	int auxId;
	retorno = -1;
	auxId = *ultimoId;
	if(listaAlbum != NULL && listaArtistas != NULL && listaGeneros && listaTypes != NULL)
	{
		alb_initLista(listaAlbum, QTY_ALBUM);
		alb_cargaForzadaDeDatos(listaAlbum, QTY_ALBUM);
		art_cargaForzadaDeDatos(listaArtistas, QTY_ARTIST);
		genero_cargaForzadaDeDatos(listaGeneros, QTY_GENERO);
		type_cargaForzadaDeDatos(listaTypes, QTY_TYPE);
		tipoAlbum_cargaForzadaDeDatos(listaTipoALbum, sizelistaTipoALbum);
		alb_indicarUltimoId(listaAlbum, sizeListaAlbum, &auxId);
		*ultimoId=auxId;
		printListaAlbum(listaAlbum, sizeListaAlbum, listaArtistas, sizeListaArtista, listaTipoALbum, sizelistaTipoALbum, listaGeneros, sizeGeneros);

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

	retorno = -1;
	aceptarConsulta = continuar("desea imprimir la lista de albumes? Y/N");
	if(aceptarConsulta)
	{
		printListaAlbum(listaAlbum, sizeListaAlbum, listaArtista, sizeListaArtista, listaTipoAlbum, sizeListTipoAlbum, listaGeneros, sizeGeneros);
	}
	do
	{
		if(!alb_solicitarCodigo(&idSolicitado, listaAlbum, sizeListaAlbum))
		{
			//printf("codigo solicitado :%d", idSolicitado);
			auxIndex = alb_findPorCodigo(listaAlbum, sizeListaAlbum, idSolicitado);
			if(auxIndex>=0)
			{
				printPosicion(auxIndex,listaAlbum,sizeListaAlbum, listaArtista, sizeListaArtista, listaTipoAlbum, sizeListTipoAlbum, listaGeneros, sizeGeneros);
				modificarAlbumOpciones(auxIndex, listaAlbum, sizeListaAlbum, listaArtista,  sizeListaArtista,  listaTipoAlbum,sizeListTipoAlbum,listaGeneros, sizeGeneros);
				aceptarConsulta = (!continuar("Desea modificar otro?"));
			}
		}
		else
		{
			aceptarConsulta = continuar("Desea cancelar la operacion? Y/N");
		}
	}while(!aceptarConsulta);

	return retorno;
}

int modificarAlbumOpciones(int auxIndex, eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtista, int sizeListaArtista, eTipoAlbum* listaTipoAlbum, int sizeListTipoAlbum,eGenero* listaGeneros, int sizeGeneros)
{
	int retorno;
	int menuSecundario;
	retorno=-1;
	if(listaAlbum != NULL && sizeListaAlbum>0 && listaArtista != NULL && sizeListaArtista> 0 && listaTipoAlbum != NULL && sizeListTipoAlbum >0 && listaGeneros != NULL && sizeGeneros>0)
	{
		retorno=0;
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

	    getTipoAlbum(indexAlbum,listaAlbum, sizeListaAlbum,listaTipoAlbum, sizeListTipoAlbum,auxTipoAlbum);

	    getGenero(indexAlbum,listaAlbum,sizeListaAlbum,listaGeneros, sizeGeneros,auxGenero);

	   // getTipoArt(indexAlbum, eAlbum* listaAlbum, int sizeListaAlbum, eTipoArtista* listaTypes, int sizeTypes, char* auxTipoArtista)


	}
    return retorno;
}

int getNombreArtista(int indexAlbum, eAlbum* listaAlbum, int sizeListaAlbum,  eArtista* listaArtista, int sizeListaArtista, char* auxArtista)
{
    int retorno;
    int i;
    retorno =-1;
  // printf("%s - auxArt ***********\n", auxArtista);
    if(indexAlbum >= 0 && listaAlbum != NULL && sizeListaAlbum>0 && listaArtista != NULL && sizeListaArtista >0 && auxArtista)
    {
        for(i=0;i<sizeListaArtista; i++)
	    {
        	//printf("%d) index: {%d} %d ?- listArt %d",i, indexAlbum, listaAlbum[indexAlbum].artistaFk, listaArtista[i].idArtista);
	        if(listaAlbum[indexAlbum].artistaFk == listaArtista[i].idArtista)
	        {
	        	//printf("nombre %d**",listaArtista[i].idArtista);
	        	//printf("%d) nombre: %s - id %d - fk %d - %s\n",i, listaArtista[i].nombre,listaArtista[i].idArtista,listaAlbum[indexAlbum].artistaFk, auxArtista);
	            strncpy(auxArtista, listaArtista[i].nombre, STR_SIZE);
	            break;
	        }
	    }
        //printf("%s - auxArt ***********\n\n", auxArtista);
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
	        	//printf("tipoalb %d**",listaTipoAlbum[i].idTipoAlbum);
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
	        if(listaAlbum[indexAlbum].generoFk== listaGeneros[i].idGenero)
	        {
	        	//printf("genero %d **", listaGeneros[i].idGenero);
	            strncpy(auxGenero, listaGeneros[i].descripcion, STR_SIZE);
	            break;
	        }
	    }
    }
    return retorno;
}

int getTipoArt(int indexAlbum, eAlbum* listaAlbum, int sizeListaAlbum, eTipoArtista* listaTypes, int sizeTypes, char* auxTipoArtista)
{
    int retorno;
    int i;
    retorno =-1;
    if(indexAlbum >= 0 && listaAlbum != NULL && sizeListaAlbum>0 && listaTypes != NULL && sizeTypes >0 && auxTipoArtista)
    {
        for(i=0;i<sizeTypes; i++)
	    {
	        if(listaAlbum[indexAlbum].generoFk== listaTypes[i].idTipoArtista)
	        {
	        	//printf("genero %d **", listaGeneros[i].idGenero);
	            strncpy(auxTipoArtista, listaTypes[i].descripcion, STR_SIZE);
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
		//printf("auxArt: %s\n\n\n", auxArtista);
		printf("%7s %11d %24s %4d/%d/%d %14.2f %25s %20s\n",  auxTipoAlbum,
													listaAlbum[indexAlbum].idAlbum,
													listaAlbum[indexAlbum].titulo,
													listaAlbum[indexAlbum].fecha.day,
													listaAlbum[indexAlbum].fecha.month,
													listaAlbum[indexAlbum].fecha.year,
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

void consultaMostrarLista(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtista, int sizeListaArtista, eTipoAlbum* listaTipoAlbum, int sizeListTipoAlbum,eGenero* listaGeneros, int sizeGeneros)
{
	int aceptarConsulta;
	aceptarConsulta = continuar("desea imprimir la lista de albumes? Y/N");
	if(aceptarConsulta)
	{
		printListaAlbum(listaAlbum, sizeListaAlbum, listaArtista, sizeListaArtista, listaTipoAlbum, sizeListTipoAlbum, listaGeneros, sizeGeneros);
	}
}

int deleteAlbum(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtita, int sizeListaArtista, eTipoAlbum* listaTipoAlbum, int sizeListaTipoAlbum,eGenero* listaGenero, int sizeListaGenero)
{
    int retorno;
    int auxCodigo;
    int indexHallado;
    int respContinuar;

    retorno = -1;
    if(listaAlbum != NULL && sizeListaAlbum>0 && listaArtita != NULL && sizeListaArtista>0 && listaTipoAlbum != NULL && sizeListaTipoAlbum >0 && listaGenero != NULL && sizeListaGenero >0)    {

    	consultaMostrarLista(listaAlbum, sizeListaAlbum, listaArtita, sizeListaArtista, listaTipoAlbum, sizeListaTipoAlbum, listaGenero, sizeListaGenero);
    	alb_solicitarCodigo(&auxCodigo, listaAlbum, sizeListaAlbum);
        indexHallado = alb_findPorCodigo(listaAlbum, sizeListaAlbum, auxCodigo);

        if(indexHallado>=0)
		{
		    retorno = -2;
			alb_printEncabezado();
			printPosicion(indexHallado, listaAlbum, sizeListaAlbum, listaArtita, sizeListaArtista, listaTipoAlbum, sizeListaTipoAlbum, listaGenero, sizeListaGenero);
			respContinuar=continuar("\nConfirma eliminar el album?");
			if(respContinuar==1)
			{
			    alb_removerAlbum(listaAlbum, indexHallado);
			    retorno =0;
				printf("se ha eliminado exitosamente");
			}
		}
    }
    return retorno;
}

int puntoCinco(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtista, int sizeListaArtista, eTipoAlbum* listaTipoAlbum, int sizeListaTipoAlbum,eGenero* listaGenero, int sizeListaGenero, eTipoArtista* listaType, int sizeListType)
{
	int retorno;
	int menuSecundario;
	retorno=-1;
	if(listaAlbum != NULL && sizeListaAlbum>0 && listaArtista != NULL && sizeListaArtista>0 && listaTipoAlbum != NULL && sizeListaTipoAlbum >0 && listaGenero != NULL && sizeListaGenero >0)
	{
		retorno=0;
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
					type_printListaType(listaType, sizeListType);

					break;
				case 3:
					//listar artistas
					art_printListaArtista(listaArtista, sizeListaArtista);
					break;

				case 4:
					//listar albumes
					alb_printListaAlbumes(listaAlbum, sizeListaAlbum);
					break;
				case 5:
					//ordenar albumes por criterio -importe (descendente) -Titulo(ascendente)
					//ARREGLAR EN UNA SOLA LISTA !
					listar_sortAlbum(listaAlbum, sizeListaAlbum, listaArtista, sizeListaArtista, listaTipoAlbum, sizeListaTipoAlbum, listaGenero, sizeListaGenero);
					break;
				case 6:
					//mostrar previos al 2000
					listar_printAlbumPrevioAlDosMil(listaAlbum, sizeListaAlbum);
					break;
				case 7:
					//albumes que superan el promedio
					mostrarAlbumPrecioMayorAlPromedio(listaAlbum, sizeListaAlbum,listaArtista, sizeListaArtista, listaTipoAlbum, sizeListaTipoAlbum,listaGenero, sizeListaGenero);
					//listar_calcularTotalyPromedioDeImportes(listaAlbum, sizeListaAlbum);
					break;
				case 8:
					//albumes por artista
					mostrarAlbumesPorArtista(listaAlbum, sizeListaAlbum,listaArtista, sizeListaArtista, listaTipoAlbum, sizeListaTipoAlbum,listaGenero, sizeListaGenero);
					//listar_printAlbumPorArtista(listaArtista, sizeListaArtista, listaAlbum, sizeListaAlbum);
					break;
				case 9:
					//Albumes segun añio: indicar año
					imprimirSegunAnio(listaAlbum,sizeListaAlbum,listaArtista, sizeListaArtista,listaTipoAlbum, sizeListaTipoAlbum,listaGenero, sizeListaGenero);
					break;
				case 10:
					//album mas caro
					printAlbumesMasCaros(listaAlbum, sizeListaAlbum, listaArtista, sizeListaArtista, listaTipoAlbum, sizeListaTipoAlbum, listaGenero, sizeListaGenero);
					break;
			}
		}while(menuSecundario<11 );
	}
	return retorno;
}

int mostrarAlbumPrecioMayorAlPromedio(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtista, int sizeListaArtista, eTipoAlbum* listaTipoAlbum, int sizeListaTipoAlbum,eGenero* listaGenero, int sizeListaGenero)
{
	int retorno;
	float totalImporte;
	int cantidadImportes;
	float promedio;
	//int cantidadQueSuperaPromedio;
	int i;

	retorno =-1;
	if(listaAlbum != NULL && sizeListaAlbum>0 && listaArtista != NULL && sizeListaArtista>0 && listaTipoAlbum != NULL && sizeListaTipoAlbum >0 && listaGenero != NULL && sizeListaGenero >0)
	{
		retorno=-2;
		cantidadImportes = informes_totalImportes(listaAlbum, sizeListaAlbum, &totalImporte);
		if(cantidadImportes>0)
		{
			promedio= tp_calcularPromedio(totalImporte, cantidadImportes);
			printf("Albumes que superan el precio promedio de %.2f son :\n", promedio);
			for(i=0; i<sizeListaAlbum; i++)
			{
				if(listaAlbum[i].isEmpty == NOT_EMPTY && listaAlbum[i].importe>promedio)
				{
					printPosicion(i, listaAlbum, sizeListaAlbum, listaArtista, sizeListaArtista, listaTipoAlbum, sizeListaTipoAlbum, listaGenero, sizeListaGenero);
				}
			}
			retorno=0;
		}
	}
	return retorno;
}

int mostrarAlbumesPorArtista(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtista, int sizeListaArtista, eTipoAlbum* listaTipoAlbum, int sizeListaTipoAlbum,eGenero* listaGenero, int sizeListaGenero)
{
	int retorno;
	int i;
	int j;
	int bandera;

	retorno=-1;
	if( listaArtista!= NULL && sizeListaArtista>0 && listaAlbum != NULL && sizeListaAlbum>0)
	{
		retorno=0;
		alb_printEncabezado();
		for(i=0; i<sizeListaArtista; i++)
		{
			arrayChar_convertirStringMayuscula(listaArtista[i].nombre, strlen(listaArtista[i].nombre));
			printf("\n\n%s\n", listaArtista[i].nombre);
			bandera=0;
			for(j=0; j<sizeListaAlbum; j++)
			{
				if(listaAlbum[j].isEmpty == NOT_EMPTY && listaAlbum[j].artistaFk == listaArtista[i].idArtista)
				{
					printPosicion(j, listaAlbum, sizeListaAlbum, listaArtista, sizeListaArtista, listaTipoAlbum, sizeListaTipoAlbum, listaGenero, sizeListaGenero);
					printf("\n");
					bandera=1;
				}
				if(j==(sizeListaAlbum-1)&& !bandera)
				{
					printf("Aun no ha cargado albumes para este artista\n");
				}
			}
		}
	}
	return retorno;
}

int imprimirSegunAnio(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtista, int sizeListaArtista, eTipoAlbum* listaTipoAlbum, int sizeListaTipoAlbum,eGenero* listaGenero, int sizeListaGenero)
{
	int contador;
	int i;
	int yearSelected;

	contador = -1;
	if(listaAlbum!= NULL && sizeListaAlbum)
	{
		listar_printYear(listaAlbum, sizeListaAlbum);
		utn_GetNumeroInt(&yearSelected, "Ingrese un año: ", "ingrese un valor valido", 1851, MAX_YEAR, REINTENTOS);
		alb_printEncabezado();

		contador=0;
		for (i=0; i<sizeListaAlbum; i++)
		{
			if(listaAlbum[i].fecha.year== yearSelected)
			{
				contador++;
				printPosicion(i, listaAlbum, sizeListaAlbum, listaArtista, sizeListaArtista, listaTipoAlbum, sizeListaTipoAlbum, listaGenero, sizeListaGenero);
			}
		}
	}
	return contador;
}

int printAlbumesMasCaros(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtista, int sizeListaArtista, eTipoAlbum* listaTipoAlbum, int sizeListaTipoAlbum,eGenero* listaGenero, int sizeListaGenero)
{
	int retorno;
	float mayorPrecio;
	int i;

	retorno =-1;
	if(listaAlbum!= NULL && sizeListaAlbum>0)
	{
		retorno=0;
		mayorPrecio = listar_findPrecioMasCaro(listaAlbum, sizeListaAlbum);
		printf("Albumes con mayor precio de %.2f\n", mayorPrecio);
		for(i=0; i<sizeListaAlbum; i++)
		{
			if(listaAlbum[i].isEmpty== NOT_EMPTY && listaAlbum[i].importe==mayorPrecio)
			{
				printPosicion(i, listaAlbum, sizeListaAlbum, listaArtista, sizeListaArtista, listaTipoAlbum, sizeListaTipoAlbum, listaGenero, sizeListaGenero);
			}
		}
	}
	return retorno;
}

int printAlbumNoVinilo(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtista, int sizeListaArtista, eTipoAlbum* listaTipoAlbum, int sizeListaTipoAlbum,eGenero* listaGenero, int sizeListaGenero)
{
	int retorno;
	int i;

	retorno =-1;
	if(listaTipoAlbum != NULL && sizeListaTipoAlbum>0)
	{
		retorno =0;
		printf("Todos los discos que son Cinta o Cd\n");
		for(i=0; i<sizeListaAlbum; i++)
		{
			if(listaAlbum[i].isEmpty == NOT_EMPTY && listaAlbum[i].tipoAlbumFk != VINILO)
			{
				printPosicion(i, listaAlbum, sizeListaAlbum, listaArtista, sizeListaArtista, listaTipoAlbum, sizeListaTipoAlbum, listaGenero, sizeListaGenero);
				//printf("\n");
			}
		}
	}
	return retorno;
}

int printViniloSegunArtista(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtista, int sizeListaArtista, eTipoAlbum* listaTipoAlbum, int sizeListaTipoAlbum,eGenero* listaGenero, int sizeListaGenero)

{
	int retorno;
	int i;
	int artistaSelected;
	int bandera;

	retorno = -1;
	if(listaAlbum!= NULL && sizeListaAlbum)
	{
		bandera = 0;
		art_printListaArtista(listaArtista, sizeListaArtista);
		utn_GetNumeroInt(&artistaSelected, "indique el codigo de artista que desea buscar: ", "ingrese un valor valido", 1, QTY_ARTIST, REINTENTOS);


		alb_printEncabezado();
		for (i=0; i<sizeListaAlbum; i++)
		{
			if( listaAlbum[i].isEmpty== NOT_EMPTY
				&& listaAlbum[i].artistaFk== artistaSelected && listaAlbum[i].tipoAlbumFk==VINILO)
			{
				printPosicion(i, listaAlbum, sizeListaAlbum, listaArtista, sizeListaArtista, listaTipoAlbum, sizeListaTipoAlbum, listaGenero, sizeListaGenero);
				bandera = 1;
			}
		}
		if(!bandera)
		{
			printf("no tiene album vinilo");
		}
		retorno=0;
	}
	return retorno;
}


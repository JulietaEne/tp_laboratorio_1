/*
 * album.c
 *
 *  Created on: 29 abr. 2022
 *      Author: julieta_enee
 */

#include "album.h"


/**
 * \breif To assign a init value to array's a particular possition
 * \param listaAlbum eAlbum* receives the array which will be operated
 * \param indice int receives the value who indicates where the data will be assigned
 * \param valorInicial int Receives by value the data that is assigned
 * \return retorna int -1 if  Error [Invalid length or NULL pointer or withoufree space]
 * 						0 if Ok - el valor del indice que se encontro
 *
*/
int alb_initPosicionListaAlbum(eAlbum* listaAlbum, int indiceRecibido, int valorInicial)
{
	int retorno;

	retorno = -1;
	if(listaAlbum != NULL && indiceRecibido>=0)
	{
		retorno = 0;
		listaAlbum[indiceRecibido].isEmpty= valorInicial;
	}
	return retorno;
}

/**
 * \brief Recorre el array recibido para asignar valor inicial al campo isEmpty de todos sus elementos
 * \param listaAlbum eAlbum* Recibe la direccion de memoria del array sobre el cual va a operar
 * \param sizeListaAlbum int Recibe por valor el tamaño del array
 * \return retorna int -1 si hubo un error en los parametros recibidos
 * 						0 si la operacion se realizo correctamente
 *
 */
int alb_initListaAlbum(eAlbum* listaAlbum, int sizeListaAlbum)
{
	int retorno;
	int i;
	retorno = -1;
	if(listaAlbum != NULL && sizeListaAlbum>0)
	{
		for(i=0; i<sizeListaAlbum; i++)
		{
			alb_initPosicionListaAlbum(listaAlbum, i, IS_EMPTY);
		}
	}
	return retorno;
}



/**
* \brief Recibe un array de estructuras para recorrerlo en el campo isEmpty hasta encontrar el valor 0,
* 		 retornando el valor del indice hayado
* \param listaAlbum eAlbum* recibe la direccion de memoria del array a analizar
* \param sizeListaAlbum int recibe por valor el tamaño del array
* \return int Return (-1) si hubo un error en los parametros recibidos
* 					 (-2) si no encontro ningun index libre
* 		     		 (>=0) si opero correctamente - el valor del indice que se encontro
*
*/
int alb_findPrimerEspacioLibreEnLista(eAlbum* listaAlbum, int sizeListaAlbum)
{
	int retorno;
	int i;
	retorno =-1;
	if(listaAlbum!= NULL && sizeListaAlbum >0)
	{
		for(i=0; i<sizeListaAlbum; i++)
		{
			if(validacionesInt_sonIdenticos(listaAlbum[i].isEmpty, IS_EMPTY))
			{
				retorno=i;
				break;
			}
			else
			{
				if(validacionesInt_sonIdenticos(listaAlbum[i].isEmpty,IS_DELETED))
				{
					retorno=i;
					break;
				}
				else
				{
					retorno = -2;
				}
			}
		}
	}
	return retorno;
}

/**
* \brief realiza un hardcodeo de 5 elementos a cargar en el array de tipo eAlbum
* \param listaAlbum eAlbum* Recibe la direccion de memoria del primer elemento del array sobre el cual se operara
* \param sizeListaAlbum int Recibe por valor tamaño de la lista
* \return Return 0 si opero correctamente
* 			   (-1) si hubo un error en los parametros recibidos
*
*/
int alb_cargaForzadaDatosDeAlbum(eAlbum* listaAlbum, int sizeListaAlbum)
{
	int retorno;
	int i;

	eAlbum cargaAlbum[] = {
			{101, "El disco de tu corazon",{1,1,2017}, 2050,2,2,2,1,NOT_EMPTY},
			{102, "Sin restricciones",{1,5,2004},2000,2,2,2,3, NOT_EMPTY},
			{103, "El templo del pop",{1,8,2014},2500,2,2,2,3, NOT_EMPTY},
			{104, "Master of puppets",{1,10,1986}, 1800,3,3,2,3,NOT_EMPTY},
			{105, "Dapódromo",{1,10,1996},1900,1,1,1,2,NOT_EMPTY},
			{000, "",{},0,0,0,0,0,IS_EMPTY},
			{000, "",{},0,0,0,0,0,IS_EMPTY},
			{000, "",{},0,0,0,0,0,IS_EMPTY},
			{000, "",{},0,0,0,0,0,IS_EMPTY},
			{000, "",{},0,0,0,0,0,IS_EMPTY},
			};

	retorno = -1;
	if(listaAlbum!= NULL && sizeListaAlbum>0)
	{
		for(i=0; i<7; i++)
		{
			listaAlbum[i]= cargaAlbum[i];
		}
		//printf("id: %d - nombre %s, importe %.2f, ")
		retorno = 0;
	}

	return retorno;
}

/**
* \brief realiza un hardcodeo de 3 elementos a cargar en el array de tipo eGenero
* \param listaGeneros eGenero* Recibe la direccion de memoria del primer elemento del array sobre el cual se operara
* \param sizeGenerosDeAlbum int Recibe por valor tamaño de la lista
* \return Return 0 si opero correctamente
* 			   (-1) si hubo un error en los parametros recibidos
*
*/
int generoAlbum_cargaForzadaDeGeneroDeAlbum(eGenero* listaGenerosDeAlbum, int sizeListaGenerosDeAlbum)
{
	int retorno;
	int i;
	eGenero cargaGeneros[] = {
								{1, "Country", NOT_EMPTY},
								{2, "Dance", NOT_EMPTY},
								{3, "Metal Rock", NOT_EMPTY},
							};
	retorno = -1;
	if(listaGenerosDeAlbum!= NULL && sizeListaGenerosDeAlbum>0)
	{
		for(i=0; i<sizeListaGenerosDeAlbum; i++)
		{
			listaGenerosDeAlbum[i]= cargaGeneros[i];
		}
		retorno = 0;
	}

	return retorno;
}

/**
* \brief realiza un hardcodeo de 4 elementos a cargar en el array de tipo eArtista
* \param listaArtistas eArtista* Recibe la direccion de memoria del primer elemento del array sobre el cual se operara
* \param sizeListaArtista int Recibe por valor tamaño de la lista
* \return Return 0 si opero correctamente
* 			   (-1) si hubo un error en los parametros recibidos
*
*/
int art_cargaForzadaDeArtistas(eArtista* listaArtistas, int sizeListaArtistas)
{
	int retorno;
	int i;
	eArtista cargaArtistas[] = {
								{1, "Babasonicos", NOT_EMPTY},
								{2, "Miranda", NOT_EMPTY},
								{3, "Metallica", NOT_EMPTY},
								{4, "Kiss", NOT_EMPTY},
							};
	retorno = -1;
	if(listaArtistas!= NULL && sizeListaArtistas>0)
	{
		for(i=0; i<sizeListaArtistas; i++)
		{
			listaArtistas[i]= cargaArtistas[i];
		}
		retorno = 0;
	}

	return retorno;
}

/**
* \brief realiza un hardcodeo de 2 elementos a cargar en el array de tipo eTipoArtista
* \param listaTiposDeArtista eTipoArtista* Recibe la direccion de memoria del primer elemento del array sobre el cual se operara
* \param sizeTiposDeArtista int Recibe por valor tamaño de la lista
* \return Return 0 si opero correctamente
* 			   (-1) si hubo un error en los parametros recibidos
*
*/
int tipoArtista_cargaForzadaTipoDeArtista(eTipoArtista* listaTiposDeArtista, int sizeListaTiposDeArtista)
{
	int retorno;
	int i;
	eTipoArtista cargaTipos[] = {
								{1, "Solista", NOT_EMPTY},
								{2, "Banda", NOT_EMPTY},
							};
	retorno = -1;
	if(listaTiposDeArtista!= NULL && sizeListaTiposDeArtista>0)
	{
		for(i=0; i<sizeListaTiposDeArtista; i++)
		{
			listaTiposDeArtista[i]= cargaTipos[i];
		}
		retorno = 0;
	}
	return retorno;
}

int alb_indicarUltimoId(eAlbum* listaAlbum, int sizeListaAlbum, int* ultimoId)
{
	int auxMayorId;
	int i;
	auxMayorId = -1;
	if(listaAlbum!= NULL && sizeListaAlbum >0 && ultimoId != NULL)
	{
		auxMayorId=ID_INICIAL;
		for (i=0; i<sizeListaAlbum; i++)
		{
			if(listaAlbum[i].isEmpty== NOT_EMPTY && listaAlbum[i].codigoIdAlbum>auxMayorId)
			{
				auxMayorId=listaAlbum[i].codigoIdAlbum;
			}
		}
		*ultimoId = auxMayorId;
	}
	return *ultimoId;
}

/**
 * \brief Recorre el array recibido para asignar valor inicial al campo isEmpty de todos sus elementos
 * \param listaAlbum eAlbum* Recibe la direccion de memoria del array sobre el cual va a operar
 * \param sizeListaAlbum int Recibe por valor el tamaño del array
 * \return retorna int -1 si hubo un error en los parametros recibidos
 * 						0 si la operacion se realizo correctamente
 *
 */
int inicioPrograma(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtistas, int sizeListaArtistas, eGenero* listaGenerosDeAlbum, int sizeListaGenerosDeAlbum, eTipoArtista* listaTiposDeArtista, int sizeListaTiposDeArtista, eTipoAlbum* listaFormatosAlbum, int sizeListaFormatosAlbum, int* ultimoId)
{
	int retorno;
	int auxId;
	int confirmar=1;

	retorno = -1;
	auxId = *ultimoId;
	if(listaAlbum != NULL && listaArtistas != NULL && listaGenerosDeAlbum && listaTiposDeArtista != NULL)
	{
		//confirmar = continuar("desea hardcodear 5 datos?");
		if(confirmar){
			alb_initListaAlbum(listaAlbum, sizeListaAlbum);
			alb_cargaForzadaDatosDeAlbum(listaAlbum, sizeListaAlbum);
			art_cargaForzadaDeArtistas(listaArtistas, sizeListaArtistas);
			generoAlbum_cargaForzadaDeGeneroDeAlbum(listaGenerosDeAlbum, sizeListaGenerosDeAlbum);
			tipoArtista_cargaForzadaTipoDeArtista(listaTiposDeArtista, sizeListaTiposDeArtista);
			formatoAlbum_cargaForzadaFormatosAlbum(listaFormatosAlbum, sizeListaFormatosAlbum);
			alb_indicarUltimoId(listaAlbum, sizeListaAlbum, &auxId);
			*ultimoId=auxId;
			alb_printListaCompleta(listaAlbum, sizeListaAlbum, listaArtistas, sizeListaArtistas, listaGenerosDeAlbum, sizeListaGenerosDeAlbum, listaTiposDeArtista, sizeListaTiposDeArtista, listaFormatosAlbum, sizeListaFormatosAlbum);
			retorno =0;
		}
		else{
			alb_initListaAlbum(listaAlbum, sizeListaAlbum);
			retorno = 1;
		}

	}
	return retorno;
}

/*
 * \brief Recorre el array recibido para analizar si el campo isEmpty está usado, y si lo está los contabiliza
 * \param listaAlbum eAlbum* Recibe la direccion de memoria del array sobre el cual va a trabajar
 * \param sizeListaAlbum int Recibe por valor el tamaño del array
 * \param cantidadCargados *int recibe la direccion de memoria donde guardara la cantidad contabilizada
 * \return retorna int -1 si hubo un error en los parametros recibidos
 * 					   -2 si no pudo recorrer el array
 * 					   >=0 si la operacion se realizo correctamente(retorna la cantidad contabilizada)
 *
 */
int alb_contadorAlbumesCargados(eAlbum* listaAlbum, int sizeListaAlbum)
{
	int retorno;
	int i;
	int contador;
	retorno= -1;
	contador=0;

	if(listaAlbum!= NULL && sizeListaAlbum>0)
	{
		retorno=-2;
		for(i=0; i<sizeListaAlbum; i++)
		{
			if(validacionesInt_sonIdenticos(listaAlbum[i].isEmpty, NOT_EMPTY))
			{
				contador++;
			}
		}
		retorno=contador;
	}
	return retorno;
}

/*
 * \brief Recibe un index de la lista e imprime su contenido. Se sirve de otras funciones para buscar el valor de los FK
 * \param listaAlbum eAlbum* Recibe la direccion de memoria del array sobre el cual va a trabajar
 * \param sizeListaAlbum int Recibe por valor el tamaño del array
 * \param listaArtistas eArtista* Recibe la lista de los artistas
 * \param sizeListaArtistas int Recibe el tamaño de la lista de los artistas
 * \param listaGenerosDeAlbum eGenero* Recibe la lista de los generos
 * \param sizeListaGenerosDeAlbum int Recibe el tamaño de la lista de los artistas
 * \param listaTiposDeArtista eTipoArtista* Recibe la lista los tipos de artistas
 * \param sizeListaTiposDeArtista int Recibe el tamaño de la lista

 * \return retorna int -1 si hubo un error en los parametros recibidos
 * 						0 si la operacion se realizo correctamente
 */
int alb_printUnAlbum(int unAlbum, eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtistas, int sizeListaArtistas, eGenero* listaGenerosDeAlbum, int sizeListaGenerosDeAlbum, eTipoArtista* listaTiposDeArtista, int sizeListaTiposDeArtista, eTipoAlbum* listaFormatosALbum, int sizeListaFormatosAlbum)
{
	int retorno;
	char auxNombreArtista[STR_SIZE];
	char auxFormatoVentaDeAlbum[STR_SIZE];
	char auxGeneroAlbum[STR_SIZE];
	char auxTipoArtista[STR_SIZE];
	retorno =-1;
	if(unAlbum >=0 && listaAlbum != NULL && sizeListaAlbum >0 && listaArtistas != NULL && sizeListaArtistas >0 && listaGenerosDeAlbum != NULL && sizeListaGenerosDeAlbum >0 && listaTiposDeArtista != NULL && sizeListaTiposDeArtista >0 && listaFormatosALbum!= NULL && sizeListaFormatosAlbum>0)
	{
		getNombreArtistaDelAlbum(unAlbum,listaAlbum,listaArtistas,sizeListaArtistas,auxNombreArtista);
		getDescripcionFormatoAlbum(unAlbum, listaAlbum, listaFormatosALbum, sizeListaFormatosAlbum, auxFormatoVentaDeAlbum);
		getDescripcionGeneroDelAlbum(unAlbum, listaAlbum, listaGenerosDeAlbum, sizeListaGenerosDeAlbum, auxGeneroAlbum);
		getDescripcionTipoArtista(unAlbum, listaAlbum, listaTiposDeArtista, sizeListaTiposDeArtista, auxTipoArtista);
		//alb_printEncabezado();
		//printf("auxArt: %s\n\n\n", auxArtista);
		printf("%5d %35s %20s %15d/%d/%d %18s %15.2f %15s  %15s\n",listaAlbum[unAlbum].codigoIdAlbum,
													listaAlbum[unAlbum].titulo,
													auxGeneroAlbum,
													listaAlbum[unAlbum].fechaPublicacionAlbum.day,
													listaAlbum[unAlbum].fechaPublicacionAlbum.month,
													listaAlbum[unAlbum].fechaPublicacionAlbum.year,
													auxFormatoVentaDeAlbum,
													listaAlbum[unAlbum].importeAlbum,
													auxNombreArtista,
													auxTipoArtista);
	}
	return retorno;
}

/**
 * \brief Recibe un elemento de la lista album y compara el valor de su campo artistaDelAlbumFk con los ID de la lista eArtista.
 * 		  Si encuentra coincidencia, guarda el contenido en el puntero recibido por parámetro
 * \param unAlbum int recibe por valor el index del album que se está analizando
 * \param listaAlbum eAlbum* recibe un puntero al primer elemento de la lista de albumes
 * \param listaArtistas eArtista* recibe la lista que analizará
 * \param sizeListaArtistas int recibe el tamaño de la lista
 * \param auxNombreArtista char* recibe la dirección de memoria donde guardará la variable hayada
 *
 * \return retorno int -1 si encontró un error en los parámetros
 * 						0 si operó exitosamente
 *
 */
int getNombreArtistaDelAlbum(int unAlbum, eAlbum* listaAlbum, eArtista* listaArtistas, int sizeListaArtistas, char* auxNombreArtista)
{
    int retorno;
    int i;
    retorno =-1;
    if(unAlbum >= 0 && listaAlbum != NULL && listaArtistas != NULL && sizeListaArtistas >0 && auxNombreArtista != NULL)
    {
        for(i=0;i<sizeListaArtistas; i++)
	    {
	        if(listaAlbum[unAlbum].artistaDelAlbumFk == listaArtistas[i].idArtistaDelAlbum)
	        {
	        	strncpy(auxNombreArtista, listaArtistas[i].nombre, STR_SIZE);
	            retorno = 0;
	            break;
	        }
	    }
        if(retorno)
		{
			printf("No se encuentra el nombre de artista para el album indicado (Codigo del album: %d)", listaAlbum[unAlbum].codigoIdAlbum);;
		}
        //printf("%s - auxArt ***********\n\n", auxArtista);
    }
    return retorno;
}

/**
 * \brief Recibe un elemento de la lista album y compara el valor de su campo formatoDelAlbumFk con los ID de la lista eTipoAlbum.
 * 		  Si encuentra coincidencia, guarda el contenido en el puntero recibido por parámetro
 * \param unAlbum int recibe por valor el index del album que se está analizando
 * \param listaAlbum eAlbum* recibe un puntero al primer elemento de la lista de albumes
 * \param listaFormatosAlbum eTipoAlbum* recibe la lista que analizará
 * \param sizeListaFormatosAlbum int recibe el tamaño de la lista
 * \param auxFormatoVentaDeAlbum char* recibe la dirección de memoria donde guardará la variable hayada
 *
 * \return retorno int -1 si encontró un error en los parámetros
 * 						0 si operó exitosamente
 *
 */
int getDescripcionFormatoAlbum(int unAlbum, eAlbum* listaAlbum, eTipoAlbum* listaFormatosAlbum, int sizeListaFormatosAlbum, char* auxFormatoVentaDeAlbum)
{
    int retorno;
    int i;
    retorno =-1;
    if(unAlbum >= 0 && listaAlbum != NULL && listaFormatosAlbum != NULL && sizeListaFormatosAlbum >0 && auxFormatoVentaDeAlbum != NULL)
    {
        for(i=0;i<sizeListaFormatosAlbum; i++)
	    {
	        if(listaAlbum[unAlbum].formatoDelAlbumFk== listaFormatosAlbum[i].idFormatoDelAlbum)
	        {
	        	//printf("tipoalb %d**",listaTipoAlbum[i].idTipoAlbum);
	            strncpy(auxFormatoVentaDeAlbum, listaFormatosAlbum[i].descripcion, STR_SIZE);
	            retorno =0 ;
	            break;
	        }
	    }
       if(retorno)
		{
			printf("No se encuentra descripción del formato de album para el album indicado (Codigo del album: %d)", listaAlbum[unAlbum].codigoIdAlbum);;
		}
    }
    return retorno;
}

/**
 * \brief Recibe un elemento de la lista album y compara el valor de su campo generoDelAlbumFk con los ID de la lista eGenero.
 * 		  Si encuentra coincidencia, guarda el contenido en el puntero recibido por parámetro
 * \param unAlbum int recibe por valor el index del album que se está analizando
 * \param listaAlbum eAlbum* recibe un puntero al primer elemento de la lista de albumes
 * \param listaGenerosDeAlbum eGenero* recibe la lista que analizará
 * \param sizeListaGenerosDeAlbum int recibe el tamaño de la lista
 * \param auxGeneroAlbum char* recibe la dirección de memoria donde guardará la variable hayada
 *
 * \return retorno int -1 si encontró un error en los parámetros
 * 						0 si operó exitosamente
 *
 */
int getDescripcionGeneroDelAlbum(int unAlbum, eAlbum* listaAlbum, eGenero* listaGenerosDeAlbum, int sizeListaGenerosDeAlbum, char* auxGeneroAlbum)
{
    int retorno;
    int i;
    retorno =-1;
    if(unAlbum >= 0 && listaAlbum != NULL && listaGenerosDeAlbum != NULL && sizeListaGenerosDeAlbum >0 && auxGeneroAlbum != NULL)
    {
        for(i=0;i<sizeListaGenerosDeAlbum; i++)
	    {
	        if(listaAlbum[unAlbum].generoDelAlbumFk== listaGenerosDeAlbum[i].idGeneroDelAlbum)
	        {
	        	//printf("genero %d **", listaGeneros[i].idGenero);
	            strncpy(auxGeneroAlbum, listaGenerosDeAlbum[i].descripcion, STR_SIZE);
	            retorno = 0;
	            break;
	        }
	    }
        if(retorno)
		{
			printf("\nNo se encuentra descripción del género de album para el album indicado (Codigo del album: %d)\rrn", listaAlbum[unAlbum].codigoIdAlbum);;
		}
    }
    return retorno;
}

/**
 * \brief Recibe un elemento de la lista album y compara el valor de su campo tipoArtistaFk con los ID de la lista eTipoArtista.
 * 		  Si encuentra coincidencia, guarda el contenido en el puntero recibido por parámetro
 * \param unAlbum int recibe por valor el index del album que se está analizando
 * \param listaAlbum eAlbum* recibe un puntero al primer elemento de la lista de albumes
 * \param listaTiposDeArtista eTipoArtista* recibe la lista que analizará
 * \param sizeListaTiposDeArtista int recibe el tamaño de la lista
 * \param auxTipoArtista char* recibe la dirección de memoria donde guardará la variable hayada
 *
 * \return retorno int -1 si encontró un error en los parámetros
 * 						0 si operó exitosamente
 *
 */
int getDescripcionTipoArtista(int unAlbum, eAlbum* listaAlbum, eTipoArtista* listaTiposDeArtista, int sizeListaTiposDeArtista, char* auxTipoArtista)
{
    int retorno;
    int i;
    retorno =-1;
    if(unAlbum >= 0 && listaAlbum != NULL && listaTiposDeArtista != NULL && sizeListaTiposDeArtista >0 && auxTipoArtista)
    {
        for(i=0;i<sizeListaTiposDeArtista; i++)
	    {
	        if(listaAlbum[unAlbum].tipoArtistaFk== listaTiposDeArtista[i].idTipoArtista)
	        {
	        	//printf("genero %d **", listaGeneros[i].idGenero);
	            strncpy(auxTipoArtista, listaTiposDeArtista[i].descripcion, STR_SIZE);
	            retorno = 0;
	            break;
	        }
	    }
        if(retorno)
        {
        	printf("\nNo se encuentra descripción del tipo de artista para el album indicado (Codigo del album: %d)\n", listaAlbum[unAlbum].codigoIdAlbum);;
        }
    }
    return retorno;
}

/**
 * \brief Imprime el encabezado de la lista de albumes con todas sus caracteristicas
 * \param void
 * \return void
 *
 */
void alb_printEncabezado(void)
{
	printf("\nCODIGO ID\t\tTITULO DEL ALBUM\t\tGENERO\t\tFECHA DE PUBLICACION\tTIPO ALBUM\tIMPORTE\t\tARTISTA\t\tTIPO ARTISTA\n");
}

/**
 * \brief Recibe el array de entidad eAlbum, el array de eArtista y el array eTipoAlbum e imprime el contenido indicado segun la posicion recibida por parametros
 * \param listaAlbum eAlbum* Recibe la direccion de memoria del array sobre el cual va a trabajar
 * \param sizeListaAlbum int Recibe por valor el tamaño del array
 * \param listaArtistas eArtista* Recibe la lista de los artistas
 * \param sizeListaArtistas int Recibe el tamaño de la lista de los artistas
 * \param listaGenerosDeAlbum eGenero* Recibe la lista de los generos
 * \param sizeListaGenerosDeAlbum int Recibe el tamaño de la lista de los artistas
 * \param listaTiposDeArtista eTipoArtista* Recibe la lista los tipos de artistas
 * \param sizeListaTiposDeArtista int Recibe el tamaño de la lista
 *
 * \return retorna int -1 si hubo un error en los parametros recibidos
 * 			0 si la operacion se realizo correctamente
 *
 */
int alb_printListaCompleta(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtistas, int sizeListaArtistas, eGenero* listaGenerosDeAlbum, int sizeListaGenerosDeAlbum, eTipoArtista* listaTiposDeArtista, int sizeListaTiposDeArtista, eTipoAlbum* listaFormatosALbum, int sizeListaFormatosAlbum)
{
	int retorno;
	int i;
	retorno = -1;
	if(listaAlbum != NULL && sizeListaAlbum>0 && listaArtistas != NULL && sizeListaArtistas>0 && listaGenerosDeAlbum != NULL && sizeListaGenerosDeAlbum >0 && listaTiposDeArtista != NULL && sizeListaTiposDeArtista >0 && listaFormatosALbum != NULL && sizeListaFormatosAlbum>0)
	{
		retorno = 0;
		alb_printEncabezado();
		for(i=0; i<sizeListaAlbum; i++)
		{
			if(listaAlbum[i].isEmpty==NOT_EMPTY)
			{
				alb_printUnAlbum(i, listaAlbum, sizeListaAlbum, listaArtistas, sizeListaArtistas, listaGenerosDeAlbum, sizeListaGenerosDeAlbum, listaTiposDeArtista, sizeListaTiposDeArtista, listaFormatosALbum, sizeListaFormatosAlbum);
			}
		}
	}
	return retorno;
}

/**
 * \brief Recibe el array de entidad eAlbum y carga en el ultimo espacio libre un
 * \param listaAlbum eAlbum* Recibe la direccion de memoria del array sobre el cual va a trabajar
 * \param sizeListaAlbum int Recibe por valor el tamaño del array
 * \param indexCarga int recibe el valor del index en el cual se alojarán los datos
 * \param tituloAlbum char* recibe la cadena correspondiente al nombre del album
 * \param sizeTituloAlbum int recibe el tamaño de la cadena
 * \param fechaDePublicacion eFecha* recibe el sector de memoria en donde se alojan los datos correspondientes a la fecha de publicacion del album
 * \param importeAlbum float recibe el valor correspondiente al precio del album
 * \param idNombreArtistaFk int recibe el foreign key de la estructura eArtista
 * \param idTipoArtistaFk int recibe el foreign key de la estructura eTipoArtista
 * \param idFormatoVentadeAlbumFk int recibe el foreign key de la estructura eTipoAlbum
 * \param idGeneroAlbumFk int recibe el foreign key de la estructura eGenero
 * \param ultimoCodigoIdAlbum int recibe el valor correspondiente al ID a cargar
 *
 * \return retorna int -1 si hubo un error en los parametros recibidos
 * 						0 si la operacion se realizo correctamente
*/
int alb_cargarUnNuevoAlbumAlArray(eAlbum* listaAlbum, int sizeListaAlbum, int indexCarga, char* tituloAlbum, int sizeTituloAlbum, eFecha* fechaDePublicacion, float importeAlbum, int idNombreArtistaFk, int idTipoArtistaFk, int idFormatoVentadeAlbumFk, int idGeneroAlbumFk, int codigoIdAlbum)
{
	int retorno;
	//int indexCarga;

	retorno = -1;
	if(tituloAlbum != NULL && sizeTituloAlbum>0 && fechaDePublicacion != NULL && listaAlbum != NULL && sizeListaAlbum >0)
	{
		//retorno = -2;
		//alb_indicarUltimoId(listaAlbum, sizeListaAlbum, &ultimoId);
		listaAlbum[indexCarga].codigoIdAlbum=codigoIdAlbum;
		listaAlbum[indexCarga].importeAlbum=importeAlbum;
		listaAlbum[indexCarga].fechaPublicacionAlbum=*fechaDePublicacion;
		listaAlbum[indexCarga].isEmpty=NOT_EMPTY;
		listaAlbum[indexCarga].artistaDelAlbumFk=idNombreArtistaFk;
		strncpy(listaAlbum[indexCarga].titulo,tituloAlbum, STR_SIZE);
		listaAlbum[indexCarga].tipoArtistaFk = idTipoArtistaFk;
		listaAlbum[indexCarga].formatoDelAlbumFk=idFormatoVentadeAlbumFk;
		listaAlbum[indexCarga].generoDelAlbumFk=idGeneroAlbumFk;
		retorno=0;
	}
	return retorno;
}

/**
* \brief add in a existing list of Album the values received as parameters
* 	     in the first empty position(with alb_cargarUnNuevoAlbumAlArray)
* 	     with the last id wich it has finded
* \param listaAlbum eAlbum* Recibe la direccion de memoria del array sobre el cual va a trabajar
* \param sizeListaAlbum int Recibe por valor el tamaño del array
* \param listaArtistas eArtista* Recibe la lista de los artistas
* \param sizeListaArtistas int Recibe el tamaño de la lista de los artistas
* \param listaGenerosDeAlbum eGenero* Recibe la lista de los generos
* \param sizeListaGenerosDeAlbum int Recibe el tamaño de la lista de los artistas
* \param listaTiposDeArtista eTipoArtista* Recibe la lista los tipos de artistas
* \param sizeListaTiposDeArtista int Recibe el tamaño de la lista
* \param ultimoCodigoIdAlbum int Recibe el ultimo ID utilizado en la lista
*
* \return int Return (-1) if Error [Invalid length or NULL pointer or withoufree space]
* 					(-2) si no hay más lugar para cargar albumes en la lista
*					  (0) if Ok
*
*/
int programa_getNuevoAlbum(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtistas, int sizeListaArtistas, eGenero* listaGenerosDeAlbum, int sizeListaGenerosDeAlbum, eTipoArtista* listaTiposDeArtista, int sizeListaTiposDeArtista, eTipoAlbum* listaFormatosALbum, int sizeListaFormatosAlbum, int ultimoCodigoIdAlbum)
{
	int retorno;
	int indexCarga;
	char tituloAlbum[STR_SIZE];
	float importeAlbum;
	eFecha fechaDePublicacion;
	int idNombreArtistaFk;
	int idTipoArtistaFk;
	int idGeneroAlbumFk;
	int idFormatoVentadeAlbumFk;
	int confirmar;//0 o 1
	int codigoIdAlbum;

	retorno = -1;
	indexCarga= alb_findPrimerEspacioLibreEnLista(listaAlbum, sizeListaAlbum);
	if(indexCarga>= 0)
	{
		alb_getTituloAlbum(tituloAlbum, STR_SIZE);
		alb_getFechaDePublicacion(&fechaDePublicacion);
		alb_getImporte(&importeAlbum);
		alb_getArtistaPorId(listaArtistas, sizeListaArtistas, &idNombreArtistaFk);
		alb_getTipoArtista(&idTipoArtistaFk);
		alb_getFormatoVentaAlbumPorId(listaFormatosALbum, sizeListaFormatosAlbum, &idFormatoVentadeAlbumFk);
		alb_getGeneroAlbumPorId(listaGenerosDeAlbum, sizeListaGenerosDeAlbum, &idGeneroAlbumFk);

		codigoIdAlbum=ultimoCodigoIdAlbum+1;

		if(!alb_cargarUnNuevoAlbumAlArray(listaAlbum, sizeListaAlbum, indexCarga, tituloAlbum,STR_SIZE, &fechaDePublicacion, importeAlbum, idNombreArtistaFk, idTipoArtistaFk, idFormatoVentadeAlbumFk, idGeneroAlbumFk, codigoIdAlbum))
		{
			retorno=0;
			printf("\nSe ha cargado con éxito");
			confirmar = continuar("\n\nDesea imprimir la lista?");
			if(confirmar)
			{
				alb_printListaCompleta(listaAlbum, sizeListaAlbum, listaArtistas, sizeListaArtistas, listaGenerosDeAlbum, sizeListaGenerosDeAlbum, listaTiposDeArtista, sizeListaTiposDeArtista, listaFormatosALbum, sizeListaFormatosAlbum);
			}
		}
	}
	else
	{
		retorno= -2;
	}
	return retorno;
}

/**
 * \brief interactua con el usuario para solicitar el titulo del album
 * \param titulo char* Recibe la direccion de memoria del array donde se guardara el dato ingresado
 * \param sizeTitulo int Recibe por valor el tamaño del array
 * \return retorna -1 si hubo un error en los parametros recibidos
 * 		   		   -2 si hubo un error en la interaccion con el usuario
 * 		  			0 si la operacion se realizo correctamente
 *
 */
int alb_getTituloAlbum(char* tituloAlbum, int sizeTituloAlbum)
{
	int retorno;
	char auxNombre[sizeTituloAlbum];

	retorno =-1;
	if(tituloAlbum!= NULL && sizeTituloAlbum >0)
	{
		do{
			utn_ingresarAlfabetica(auxNombre, sizeTituloAlbum, "Titulo del Album: ", "Ingrese un dato valido", REINTENTOS);
			strncpy(tituloAlbum, auxNombre, sizeTituloAlbum);
			retorno =0;
			if(validaciones_esNombre(tituloAlbum, sizeTituloAlbum))
			{
				retorno = -2;
				printf("[ERROR]Ingrese un título válido\n");
			}
		}while(retorno);

	}
	return retorno;
}

/**
 * \brief interactua con el usuario para solicitar la fecha del album
 * \param fechaAlbum eFecha* Recibe la direccion de memoria del array donde se guardara el dato ingresado
 * \return retorna -1 si hubo un error en los parametros recibidos
 * 		  			0 si la operacion se realizo correctamente
 *
 */
int alb_getFechaDePublicacion(eFecha* fechaDePublicacion)
{
	int retorno;
	retorno = -1;
	if(fechaDePublicacion != NULL )
	{
		printf("\nFecha de emision \n");
		*fechaDePublicacion= fecha_newFecha();
		retorno =0;
	}

	return retorno;
}

/**
 * \brief interactua con el usuario para solicitar una fecha (dia,mes,año)
 * \param void
 * \return retorna eFecha: NULL si hubo un problema
 * 						   un valor del tipo eFecha si operó con éxito
 *
 */
eFecha fecha_newFecha(void)
{
	eFecha unaFecha;
	int formatoFecha;

	do{
		formatoFecha = 1;
		utn_GetNumeroInt(&unaFecha.day, "ingrese dia: ", "Ingrese una fecha día entre 1 y 31\n", 1, MAX_DAY, REINTENTOS);
		utn_GetNumeroInt(&unaFecha.month, "ingrese mes: ", "Ingrese un mes entre 1 y 12\n", 1, MAX_MONTH, REINTENTOS);
		utn_GetNumeroInt(&unaFecha.year, "ingrese año: ", "Ingrese un año entre 1930 y 2022\n", MIN_YEAR, MAX_YEAR, REINTENTOS);
		if(!(unaFecha.day <= 31 && unaFecha.day >0 && unaFecha.month <=12 && unaFecha.month > 0 && unaFecha.year<= MAX_YEAR && unaFecha.year >= MIN_PRECIO))
		{
			formatoFecha = 0;
			printf("\n[ERROR]La carga de fecha no es correcta. Por favor ingrese un dato válido.\n");
			//aceptarConsulta = continuar("Desea cancelar la operacion? Y/N");
		}
	}while(!formatoFecha);

	return unaFecha;
}

/**
 * \brief interactua con el usuario para solicitar el precio del album
 * \param importa float* Recibe la direccion de memoria del array donde se guardara el dato ingresado
 * \return retorna -1 si hubo un error en los parametros recibidos
 * 		  			0 si la operacion se realizo correctamente
 *
 */
int alb_getImporte(float* importeAlbum)
{
	int retorno;
	float auxImporte;

	retorno = -1;
	if(importeAlbum != NULL)
	{
		do{
			utn_GetNumeroFloat(&auxImporte, "\nIngrese el importe del album: $", "ingrese un dato valido ($700 a $5000)", MIN_PRECIO, MAX_PRECIO, REINTENTOS);
			if(auxImporte >= MIN_PRECIO && auxImporte <= MAX_PRECIO)
			{
				*importeAlbum = auxImporte;
				retorno=0;
			}
		}while(retorno);
	}

	return retorno;
}

/**
 * \brief interactua con el usuario para solicitar el precio del album
 * \param importa float* Recibe la direccion de memoria del array donde se guardara el dato ingresado
 * \return retorna -1 si hubo un error en los parametros recibidos
 * 		  			0 si la operacion se realizo correctamente
 *
 */
int alb_getArtistaPorId(eArtista* listaArtistas, int sizeListaArtista, int* idNombreArtistaFk)
{
	int retorno;
	int auxArtista;
	retorno=-1;
	if(listaArtistas!= NULL && sizeListaArtista>0 && idNombreArtistaFk!= NULL)
	{
		auxArtista = art_pedirArtista(listaArtistas, sizeListaArtista);
		*idNombreArtistaFk = auxArtista;
		retorno =0;
	}
	return retorno;
}

/**
* \brief solicita por buffer el codigo id de un artista de la lista
* \param listaArtistas eArtista* recibe la direccion de memoria del array a analizar
* \param sizeListaArtista int recibe por valor el tamaño del array
* \return int Return (-1) si hubo un error en los parametros recibidos
* 		     		 (>=0) si opero correctamente (retorna el valor del indice que se encontro)
*
*/
int art_pedirArtista(eArtista* listaArtistas, int sizeListaArtista)
{
	int unId;
	int idArtista;

	idArtista =-1;
	if(listaArtistas != NULL && sizeListaArtista>0)
	{
		do{
			idArtista =0;
			art_printListaArtista(listaArtistas, sizeListaArtista);
			utn_GetNumeroInt(&unId, "Ingrese el codigo de Artista del album: ", "ingrese un codigo valido\n", MIN_ARTISTA, MAX_ARTISTA, REINTENTOS);
			if(unId<= QTY_ARTISTAS && unId >0)
			{
				idArtista= unId;
			}
		}while(!idArtista);
	}
	return idArtista;
}

/*
 * \brief la lista de artistas y su tamaño e imprime su contenido.
 * \param listaArtistas eArtista* Recibe la direccion de memoria del array
 * \param sizeListaArtista int Recibe por valor el tamaño del array

 * \return retorna int -1 si hubo un error en los parametros recibidos
 * 						0 si la operacion se realizo correctamente
 */
int art_printListaArtista(eArtista* listaArtistas, int sizeListaArtista)
{
	int retorno;
	int i;

	retorno = -1;
	if(listaArtistas!= NULL && sizeListaArtista>0)
	{
		retorno = 0;
		art_printEncabezado();
		for(i=0; i<sizeListaArtista; i++)
		{
			if( !validacionesInt_sonIdenticos(listaArtistas[i].isEmpty,IS_EMPTY))
			{
				art_printArtistaPorIndex(listaArtistas, i);
			}
		}
	}
	return retorno;
}

/**
 * \brief Imprime el encabezado de la lista eArtista
 * \param void
 * \return void
 *
 */
void art_printEncabezado(void)
{
	printf("\nCODIGO\tNOMBRE ARTISTA\n");
}

/*
 * \brief Recibe un index de la lista e imprime su contenido.
 * \param listaArtistas eArtista* Recibe la direccion de memoria del array sobre el cual va a trabajar
 * \param sizeListaArtistas int Recibe por valor el tamaño del array
 *
 * \return retorna int -1 si hubo un error en los parametros recibidos
 * 						0 si la operacion se realizo correctamente
 */
int art_printArtistaPorIndex(eArtista* listaArtistas, int indiceRecibidoArtistas)
{
	int retorno;
	retorno = -1;

	if(listaArtistas!= NULL && indiceRecibidoArtistas >=0)
	{
		retorno = 0;

		printf(" %-7d %s\n",
				listaArtistas[indiceRecibidoArtistas].idArtistaDelAlbum,
				listaArtistas[indiceRecibidoArtistas].nombre);
	}

	return retorno;
}

/**
* \brief solicita por buffer el codigo id de un artista de la lista
* \param idTipoArtistaFk int* recibe el espacio de memoria donde alojará el dato recibido por buffer
* \return int Return (-1) si hubo un error en los parametros recibidos
* 		     		 (0) si opero correctamente
*
*/
int alb_getTipoArtista(int* idTipoArtistaFk)
{
	int retorno;
	int auxTipoArtista;
	retorno=-1;
	if(idTipoArtistaFk!= NULL)
	{
		do{
			printf("\nCODIGO\tTIPO ARTISTA\n 1\tSolista\n 2\tBanda\n");
			if(!utn_GetNumeroInt(&auxTipoArtista, "Indique el código de tipo de artista: ", "indique un dato valido", 1, QTY_TIPO_DE_ARTISTA, REINTENTOS))
			{
				*idTipoArtistaFk = auxTipoArtista;
				retorno =0;
			}
		}while(retorno);
	}
	return retorno;
}

/**
* \brief solicita por buffer el codigo id de un formato de album de la lista
* \param listaFormatosALbum eTipoAlbum* recibe la direccion de memoria del array a analizar
* \param sizeListaFormatosAlbum int recibe por valor el tamaño del array
* \param idFormatoVentadeAlbumFk int* recibe el espacio de memoria donde alojar el dato ingresar por buffer
* \return int Return (-1) si hubo un error en los parametros recibidos
* 		     		 (0)
*
*/
int alb_getFormatoVentaAlbumPorId(eTipoAlbum* listaFormatosALbum, int sizeListaFormatosAlbum, int* idFormatoVentadeAlbumFk)
{
	int retorno;
	retorno=-1;
	if(listaFormatosALbum!= NULL && sizeListaFormatosAlbum>0 && idFormatoVentadeAlbumFk!= NULL)
	{
		*idFormatoVentadeAlbumFk = formatoAlbum_pedirFormatoAlbum(listaFormatosALbum, sizeListaFormatosAlbum);
		retorno=0;
	}
	return retorno;
}

/**
* \brief Recibe un array de entidad tipoAlbun para imprimirlo y luego solicita un id entre los mostrados
* \param listaTipoALbum eTipoAlbum* recibe la direccion de memoria del array a analizar
* \param sizeListaArtista int recibe por valor el tamaño del array
* \return int Return (-1) si hubo un error en los parametros recibidos
* 					 (-2) si no encontro ningun index libre
* 		     		 (>=0) si opero correctamente (retorna el valor del indice que se encontro)
*
*/
int formatoAlbum_pedirFormatoAlbum(eTipoAlbum* listaFormatosALbum, int sizeListaFormatosAlbum)
{
	int unId;
	int idTipoAlbum;

	unId =-1;
	if(listaFormatosALbum != NULL && sizeListaFormatosAlbum>0)
	{
		do{
			unId =0;
			if(!formatoAlbum_printListaFormatoVentaDeAlbum(listaFormatosALbum, sizeListaFormatosAlbum))
			{
				utn_GetNumeroInt(&unId, "Ingrese el codigo de formato de venta del Album: ", "ingrese un codigo valido", 1, QTY_FORMATOS_ALBUM, REINTENTOS);
				if(unId>0 && unId<=3)
				{
					idTipoAlbum= unId;
				}
			}
		}while(!unId);
	}
	return idTipoAlbum;
}

/*
 * \brief Recibe un index de la lista e imprime su contenido.
 * \param listaFormatosALbum eTipoAlbum* Recibe la direccion de memoria del array sobre el cual va a trabajar
 * \param sizeListaFormatosALbum int Recibe por valor el tamaño del array
 *
 * \return retorna int -1 si hubo un error en los parametros recibidos
 * 						0 si la operacion se realizo correctamente
 */
int formatoAlbum_printListaFormatoVentaDeAlbum(eTipoAlbum* listaFormatosALbum, int sizeListaFormatosAlbum)
{
	int retorno;
	int i;

	retorno = -1;
	if(listaFormatosALbum!= NULL && sizeListaFormatosAlbum>0)
	{
		retorno = 0;
		formatoAlbum_printEncabezado();
		for(i=0; i<sizeListaFormatosAlbum; i++)
		{
			if( !validacionesInt_sonIdenticos(listaFormatosALbum[i].isEmpty,IS_EMPTY))
			{
				formatoAlbum_printPosicionFormatosAlbumPorIndex(listaFormatosALbum, i);
			}
		}
	}
	return retorno;
}

/**
 * \brief Imprime el encabezado de la lista eTipoAlbum
 * \param void
 * \return void
 *
 */
void formatoAlbum_printEncabezado(void)
{
	printf("\nCODIGO\tFORMATO DE VENTA\n");
}

/*
 * \brief Recibe un index de la lista e imprime su contenido.
 * \param listaFormatosALbum eTipoAlbum* Recibe la direccion de memoria del array sobre el cual va a trabajar
 * \param indiceRecibidoFormatosAlbum int Recibe por valor el tamaño del array
 *
 * \return retorna int -1 si hubo un error en los parametros recibidos
 * 						0 si la operacion se realizo correctamente
 */
int formatoAlbum_printPosicionFormatosAlbumPorIndex(eTipoAlbum* listaFormatosAlbum, int indiceRecibidoFormatosAlbum)
{
	int retorno;
	retorno = -1;

	if(listaFormatosAlbum!= NULL && indiceRecibidoFormatosAlbum >=0)
	{
		retorno = 0;

		//printf("DEBUG*** print un pasajero\n");
		printf(" %-8d %s\n",
				listaFormatosAlbum[indiceRecibidoFormatosAlbum].idFormatoDelAlbum,
				listaFormatosAlbum[indiceRecibidoFormatosAlbum].descripcion);
	}

	return retorno;
}

/**
* \brief solicita por buffer el codigo id de un formato de album de la lista
* \param listaGenerosDeAlbum eGenero* recibe la direccion de memoria del array a analizar
* \param sizeListaGenerosDeAlbum int recibe por valor el tamaño del array
* \param idGeneroAlbumFk int* recibe el espacio de memoria donde alojar el dato ingresar por buffer
* \return int Return (-1) si hubo un error en los parametros recibidos
* 		     		 (0)
*
*/
int alb_getGeneroAlbumPorId(eGenero* listaGenerosDeAlbum, int sizeListaGenerosDeAlbum,int* idGeneroAlbumFk)
{
	int retorno;
	//int auxGenero;
	retorno=-1;
	if(listaGenerosDeAlbum != NULL && sizeListaGenerosDeAlbum > 0 && idGeneroAlbumFk!= NULL)
	{
		*idGeneroAlbumFk = generoAlbum_pedirGeneroDeAlbum(listaGenerosDeAlbum, sizeListaGenerosDeAlbum);
		retorno=0;
	}
	return retorno;
}

/**
* \brief solicita por buffer el codigo de un genero de la lista
* \param listaGenerosDeAlbum eGenero* recibe la direccion de memoria del array a trabajar
* \param sizeListaGenerosDeAlbum int recibe por valor el tamaño del array
* \return int Return (-1) si hubo un error en los parametros recibidos
* 		     		 (>=0) si opero correctamente (retorna el valor del indice que se encontro)
*
*/
int generoAlbum_pedirGeneroDeAlbum(eGenero* listaGenerosDeAlbum, int sizeListaGenerosDeAlbum)
{
	int unId;
	int idGenero;

	unId =-1;
	if(listaGenerosDeAlbum != NULL && sizeListaGenerosDeAlbum>0)
	{
		do{
			unId =0;
			generoAlbum_printListaGenerosDeAlbum(listaGenerosDeAlbum, sizeListaGenerosDeAlbum);
			utn_GetNumeroInt(&unId, "Ingrese el codigo de Genero del Album: ", "ingrese un codigo valido\n", 1, QTY_GENERO_ALBUM, REINTENTOS);
			if(unId<QTY_GENERO_ALBUM && unId>0)
			{
				idGenero= unId;
			}
		}while(!unId);
	}
	return idGenero;
}

/*
 * \brief Recibe un index de la lista e imprime su contenido.
 * \param listaGenerosDeAlbum eGenero* Recibe la direccion de memoria del array sobre el cual va a trabajar
 * \param sizeListaGenerosDeAlbum int Recibe por valor el tamaño del array
 *
 * \return retorna int -1 si hubo un error en los parametros recibidos
 * 						0 si la operacion se realizo correctamente
 */
int generoAlbum_printListaGenerosDeAlbum(eGenero* listaGenerosDeAlbum, int sizeListaGenerosDeAlbum)
{
	int retorno;
	int i;

	retorno = -1;
	if(listaGenerosDeAlbum!= NULL && sizeListaGenerosDeAlbum>0)
	{
		retorno = 0;
		generoAlbum_printEncabezado();
		for(i=0; i<sizeListaGenerosDeAlbum; i++)
		{
			if( !validacionesInt_sonIdenticos(listaGenerosDeAlbum[i].isEmpty,IS_EMPTY))
			{
				generoAlbum_printPosicionGenerosPorIndex(listaGenerosDeAlbum, i);
			}
		}
	}
	return retorno;
}

/**
 * \brief Imprime el encabezado de la lista eGenero
 * \param void
 * \return void
 *
 */
void generoAlbum_printEncabezado(void)
{
	printf("\nCODIGO\tGENERO ALBUM\n");
}

/*
 * \brief Recibe un index de la lista e imprime su contenido.
 * \param listaGenerosDeAlbum eGenero* Recibe la direccion de memoria del array sobre el cual va a trabajar
 * \param indiceRecibidoGenerosAlbum int Recibe por valor el tamaño del array
 *
 * \return retorna int -1 si hubo un error en los parametros recibidos
 * 						0 si la operacion se realizo correctamente
 */
int generoAlbum_printPosicionGenerosPorIndex(eGenero* listaGenerosDeAlbum, int indiceRecibidoGenerosAlbum)
{
	int retorno;
	retorno = -1;

	if(listaGenerosDeAlbum!= NULL && indiceRecibidoGenerosAlbum >=0)
	{
		retorno = 0;
		printf(" %-8d %s\n",
				listaGenerosDeAlbum[indiceRecibidoGenerosAlbum].idGeneroDelAlbum,
				listaGenerosDeAlbum[indiceRecibidoGenerosAlbum].descripcion);
	}

	return retorno;
}

/**
* \brief modify in a existing list of Album the values received as parameters
* 	     in the position recived by parameters
* \param listaAlbum eAlbum* Recibe la direccion de memoria del array sobre el cual va a trabajar
* \param sizeListaAlbum int Recibe por valor el tamaño del array
* \param listaArtistas eArtista* Recibe la lista de los artistas
* \param sizeListaArtistas int Recibe el tamaño de la lista de los artistas
* \param listaGenerosDeAlbum eGenero* Recibe la lista de los generos
* \param sizeListaGenerosDeAlbum int Recibe el tamaño de la lista de los artistas
* \param listaTiposDeArtista eTipoArtista* Recibe la lista los tipos de artistas
* \param sizeListaTiposDeArtista int Recibe el tamaño de la lista
*
* \return int Return (-1) if Error [Invalid length or NULL pointer or withoufree space]
*					  (0) if Ok
*
*/
int programa_modificarAlbum(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtistas, int sizeListaArtistas, eGenero* listaGenerosDeAlbum, int sizeListaGenerosDeAlbum, eTipoArtista* listaTiposDeArtista, int sizeListaTiposDeArtista, eTipoAlbum* listaFormatosAlbum, int sizeListaFormatosAlbum)
{
	int retorno;
	int aceptarConsulta;
	int solicitudIdUnAlbum;
	int indexUnAlbum;

	retorno = -1;
	aceptarConsulta = continuar("desea imprimir la lista de albumes?");
	if(aceptarConsulta)
	{
		alb_printListaCompleta(listaAlbum, sizeListaAlbum, listaArtistas, sizeListaArtistas, listaGenerosDeAlbum, sizeListaGenerosDeAlbum, listaTiposDeArtista, sizeListaTiposDeArtista, listaFormatosAlbum, sizeListaFormatosAlbum);
	}
	do
	{
		if(!alb_solicitarCodigo(&solicitudIdUnAlbum, listaAlbum, sizeListaAlbum))
		{
			indexUnAlbum = alb_findAlbumPorCodigoID(solicitudIdUnAlbum,listaAlbum,sizeListaAlbum);
			if(solicitudIdUnAlbum>=0)
			{
				alb_printUnAlbum(indexUnAlbum, listaAlbum, sizeListaAlbum, listaArtistas, sizeListaArtistas, listaGenerosDeAlbum, sizeListaGenerosDeAlbum, listaTiposDeArtista, sizeListaTiposDeArtista, listaFormatosAlbum, sizeListaFormatosAlbum);
				alb_opcionesModificarAlbum(indexUnAlbum, listaAlbum, sizeListaAlbum, listaArtistas, sizeListaArtistas, listaGenerosDeAlbum, sizeListaGenerosDeAlbum, listaTiposDeArtista, sizeListaTiposDeArtista, listaFormatosAlbum, sizeListaFormatosAlbum);
				aceptarConsulta = (!continuar("Desea modificar otro?"));
				retorno=0;
			}
		}
		else
		{
			aceptarConsulta = continuar("Desea cancelar la operacion? Y/N");
		}
	}while(!aceptarConsulta);

	return retorno;
}

/**
 * \brief interactua con el usuario para solicitar el código ID de un album y verifica que sea valido
 * \param idUnAlbum int* Recibe la direccion de memoria donde se guardara el dato ingresado
 * \param listaAlbum eAlbum* recibe la lista que utiiza para validar
 * \param sizeListaAlbum int recibe el tamaño de la lista
 * \return retorna -1 si hubo un error en los parametros recibidos
 * 		  			0 si la operacion se realizo correctamente
 *
 */
int alb_solicitarCodigo(int* solicitudIdUnAlbum, eAlbum* listaAlbum, int sizeListaAlbum)
{
	int retorno;
	int auxId;
	int ultimoId;

	retorno = -1;
	if(solicitudIdUnAlbum != NULL)
	{
		utn_GetNumeroInt(&auxId, "Ingrese el Codigo del Album: ", "El dato ingresado no corresponde a un album cargado.\n", ID_INICIAL, ID_MAXIMO, REINTENTOS);
		alb_indicarUltimoId(listaAlbum, sizeListaAlbum, &ultimoId);
		if(auxId <= ultimoId)
		{
			*solicitudIdUnAlbum= auxId;
			retorno =0;
		}
		else
		{
			printf("ingrese el codigo de un album existente");
		}
	}
	return retorno;
}

/**
 * \brief Recibe el array de entidad Album y analiza el campo .id de cada elemento hasta encontrar coincidencia con el valor recibido por parametro
 * \param solicitudIdUnAlbum int recibe por valor el dato contra el cual compara
 * \param listaAlbum *eAlbum recibe la direccion de memoria del array sobre el cual va a trabajar
 * \param sizeListaAlbum int Recibe tamaño del array
 *
 * \return retorna int -1 si hubo un error en los parametros recibidos
 * 					   -2 si no pudo recorrer el array
 * 					   >=0 si la operacion se realizo correctamente (retorna el indice donde encontro la coincidencia)
 *
 */
int alb_findAlbumPorCodigoID(int solicitudIdUnAlbum, eAlbum* listaAlbum, int sizeListaAlbum)
{
	int indexUnAlbum;
	int i;
	indexUnAlbum = -1;
	if(listaAlbum!= NULL && sizeListaAlbum >0 && solicitudIdUnAlbum> ID_INICIAL)
	{
		indexUnAlbum = -2;
		for (i=0; i<sizeListaAlbum; i++)
		{
			if(listaAlbum[i].codigoIdAlbum == solicitudIdUnAlbum)
			{
				indexUnAlbum=i;
				break;
			}
		}
	}
	return indexUnAlbum;
}

/**
 * \brief interactua con el usuario para solicitar el dato que desea modificar y lo modifica
 * \param listaAlbum eAlbum* Recibe la direccion de memoria del array sobre el cual va a trabajar
 * \param sizeListaAlbum int Recibe por valor el tamaño del array
 * \param listaArtistas eArtista* Recibe la lista de los artistas
 * \param sizeListaArtistas int Recibe el tamaño de la lista de los artistas
 * \param listaGenerosDeAlbum eGenero* Recibe la lista de los generos
 * \param sizeListaGenerosDeAlbum int Recibe el tamaño de la lista de los artistas
 * \param listaTiposDeArtista eTipoArtista* Recibe la lista los tipos de artistas
 * \param sizeListaTiposDeArtista int Recibe el tamaño de la lista
 * \return retorna -1 si hubo un error en los parametros recibidos
 * 		  			0 si la operacion se realizo correctamente
 *
 */
int alb_opcionesModificarAlbum(int indexUnAlbum, eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtistas, int sizeListaArtistas, eGenero* listaGenerosDeAlbum, int sizeListaGenerosDeAlbum, eTipoArtista* listaTiposDeArtista, int sizeListaTiposDeArtista, eTipoAlbum* listaFormatosAlbum, int sizeListaFormatosAlbum)
{
	int retorno;
	int menuSecundario;
	retorno=-1;
	if(listaAlbum != NULL && sizeListaAlbum>0 && listaArtistas != NULL && sizeListaArtistas> 0 && listaGenerosDeAlbum != NULL && sizeListaGenerosDeAlbum >0 && listaTiposDeArtista != NULL && sizeListaTiposDeArtista>0 && listaFormatosAlbum != NULL && sizeListaFormatosAlbum)
	{
		retorno=0;
		do
		{
			menuSecundario= tp_ImprimirMenuSeisOpciones("\n\nIndique el campo que desea modificar: ", "1- Titulo", "2- Fecha de Publicacion", "3- Importe", "4- Tipo Album", "5- Imprimir cambios", "6- Volver atras");
			switch (menuSecundario) {
				case 1:
					//modificar titulo
					alb_setTituloAlbum(listaAlbum, indexUnAlbum);
					break;
				case 2:
					//modificar fecha
					alb_setFechaDePublicacion(listaAlbum, indexUnAlbum);
					break;
				case 3:
					//modificar importe
					alb_setImporte(listaAlbum, indexUnAlbum);
					break;
				case 4:
					//camiar tipo album
					alb_setFormatoVentaAlbumPorId(listaAlbum, indexUnAlbum, listaFormatosAlbum, QTY_FORMATOS_ALBUM);
					break;
				case 5:
					//imprimo los cambios
					alb_printEncabezado();
					alb_printUnAlbum(indexUnAlbum, listaAlbum, sizeListaAlbum, listaArtistas, sizeListaArtistas, listaGenerosDeAlbum, sizeListaGenerosDeAlbum, listaTiposDeArtista, sizeListaTiposDeArtista, listaFormatosAlbum, sizeListaFormatosAlbum);
					break;
				case 6:
					//salir
					break;
			}
		}while(menuSecundario<6 );
	}
	return retorno;
}

/**
 * \brief interactua con el usuario para solicitar el nuevo titulo y si es valido lo aplica en el campo titulo del album indicado
 * \param listaAlbum eAlbum* Recibe la direccion de memoria del array sobre el cual va a trabajar
 * \param indexUnAlbum int Recibe por valor el index del album que se modificará
 * \return retorna -1 si hubo un error en los parametros recibidos
 * 		  			0 si la operacion se realizo correctamente
 *
 */
int alb_setTituloAlbum(eAlbum* listaAlbum, int indexUnAlbum)
{
	int retorno;
	char nuevoTitulo[STR_SIZE];

	retorno = -1;
	if(listaAlbum != NULL && indexUnAlbum>=0)
	{
		if(!alb_getTituloAlbum(nuevoTitulo, STR_SIZE))
		{
			strncpy(listaAlbum[indexUnAlbum].titulo, nuevoTitulo, STR_SIZE);
			retorno = 0;
		}
	}
	return retorno;
}

/**
 * \brief interactua con el usuario para solicitar la nueva fecha y si el dato es valido lo aplica en el campo fechaPublicacionAlbum del album indicado
 * \param listaAlbum eAlbum* Recibe la direccion de memoria del array sobre el cual va a trabajar
 * \param indexUnAlbum int Recibe por valor el index del album que se modificará
 * \return retorna -1 si hubo un error en los parametros recibidos
 * 		  			0 si la operacion se realizo correctamente
 *
 */
int alb_setFechaDePublicacion(eAlbum* listaAlbum, int indexUnAlbum)
{
	int retorno;
	eFecha nuevaFecha;

	retorno = -1;
	if(listaAlbum != NULL && indexUnAlbum>=0)
	{
		if(!alb_getFechaDePublicacion(&nuevaFecha))
		{
			listaAlbum[indexUnAlbum].fechaPublicacionAlbum = nuevaFecha;
			retorno=0;
		}
	}
	return retorno;
}

/**
 * \brief interactua con el usuario para solicitar el nuevo importe y si el dato es valido lo aplica en el campo importeAlbum del album indicado
 * \param listaAlbum eAlbum* Recibe la direccion de memoria del array sobre el cual va a trabajar
 * \param indexUnAlbum int Recibe por valor el index del album que se modificará
 * \return retorna -1 si hubo un error en los parametros recibidos
 * 		  			0 si la operacion se realizo correctamente
 *
 */
int alb_setImporte(eAlbum* listaAlbum, int indexUnAlbum)
{
	int retorno;
	float nuevoImporte;

	retorno = -1;
	if(listaAlbum != NULL && indexUnAlbum>=0)
	{
		if(!alb_getImporte(&nuevoImporte))
		{
			listaAlbum[indexUnAlbum].importeAlbum = nuevoImporte;
			retorno=0;
		}
	}
	return retorno;
}

int programa_deleteAlbum(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtistas, int sizeListaArtistas, eGenero* listaGenerosDeAlbum, int sizeListaGenerosDeAlbum, eTipoArtista* listaTiposDeArtista, int sizeListaTiposDeArtista, eTipoAlbum* listaFormatosAlbum, int sizeListaFormatosAlbum)
{
    int retorno;
    int solicitudIdUnAlbum;
    int indexUnAlbum;
    int aceptarConsulta;

    retorno = -1;
	if(listaAlbum != NULL && sizeListaAlbum>0 && listaArtistas != NULL && sizeListaArtistas> 0 && listaGenerosDeAlbum != NULL && sizeListaGenerosDeAlbum >0 && listaTiposDeArtista != NULL && sizeListaTiposDeArtista>0 && listaFormatosAlbum != NULL && sizeListaFormatosAlbum)
	{
		aceptarConsulta = continuar("desea imprimir la lista de albumes?");
		if(aceptarConsulta)
		{
			alb_printListaCompleta(listaAlbum, sizeListaAlbum, listaArtistas, sizeListaArtistas, listaGenerosDeAlbum, sizeListaGenerosDeAlbum, listaTiposDeArtista, sizeListaTiposDeArtista, listaFormatosAlbum, sizeListaFormatosAlbum);
		}

		if(!alb_solicitarCodigo(&solicitudIdUnAlbum, listaAlbum, sizeListaAlbum))
		{
			indexUnAlbum = alb_findAlbumPorCodigoID(solicitudIdUnAlbum,listaAlbum,sizeListaAlbum);
			if(solicitudIdUnAlbum>=0)
			{
				retorno=-2;
				alb_printUnAlbum(indexUnAlbum, listaAlbum, sizeListaAlbum, listaArtistas, sizeListaArtistas, listaGenerosDeAlbum, sizeListaGenerosDeAlbum, listaTiposDeArtista, sizeListaTiposDeArtista, listaFormatosAlbum, sizeListaFormatosAlbum);
				aceptarConsulta=continuar("\nConfirma eliminar el album?");
				if(aceptarConsulta==1)
				{
					alb_removerAlbumSegunIndex(listaAlbum, indexUnAlbum);
					retorno =0;
					printf("se ha eliminado exitosamente");
				}
			}
		}
		else
		{
			aceptarConsulta = continuar("Desea cancelar la operacion?");
		}
    }
    return retorno;
}

int alb_removerAlbumSegunIndex(eAlbum* listaAlbum, int indexUnAlbum)
{
	int retorno;
	retorno = -1;
	if(listaAlbum!= NULL && indexUnAlbum>=0)
	{
		listaAlbum[indexUnAlbum].isEmpty = IS_DELETED;
		retorno=0;
	}
	return retorno;
}

//**********************************************************
//PP LABO - PARTE 2

/**
* \brief realiza un hardcodeo de 3 elementos a cargar en el array de tipo eTipoAlbum
* \param listaFormatosALbum eTipoAlbum* Recibe la direccion de memoria del primer elemento del array sobre el cual se operara
* \param sizelistaFormatosAlbum int Recibe por valor tamaño de la lista
* \return Return 0 si opero correctamente
* 			   (-1) si hubo un error en los parametros recibidos
*
*/
int formatoAlbum_cargaForzadaFormatosAlbum(eTipoAlbum* listaFormatosALbum, int sizelistaFormatosAlbum)
{
	//Datos: 1, vinilo; 2, cinta; 3, CD.
	int retorno;
	int i;
	eTipoAlbum cargaTipoAlbum[] = {
								{1, "Vinilo", NOT_EMPTY},
								{2, "Cinta", NOT_EMPTY},
								{3, "CD", NOT_EMPTY}
							};
	retorno = -1;
	if(listaFormatosALbum!= NULL && sizelistaFormatosAlbum>0)
	{
		retorno = -2;
		for(i=0; i<sizelistaFormatosAlbum; i++)
		{
			listaFormatosALbum[i]= cargaTipoAlbum[i];
		}
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief interactua con el usuario para solicitar el nuevo formato de venta del album y si el dato es valido lo aplica en el campo formatoDelAlbumFk del album indicado
 * \param listaAlbum eAlbum* Recibe la direccion de memoria del array sobre el cual va a trabajar
 * \param indexUnAlbum int Recibe por valor el index del album que se modificará
 * \param listaFormatosALbum eTipoAlbum* Recibe la lista de formatos para mostrarla
 * \param indexUnAlbum int Recibe el tamaño de la lista
 * \return retorna -1 si hubo un error en los parametros recibidos
 * 		  			0 si la operacion se realizo correctamente
 *
 */
int alb_setFormatoVentaAlbumPorId(eAlbum* listaAlbum, int indexUnAlbum, eTipoAlbum* listaFormatosALbum, int sizelistaFormatosAlbum)
{
	int retorno;
	int nuevoFormatoDeVentaAlbum;

	retorno = -1;
	if(listaAlbum != NULL && indexUnAlbum>=0)
	{
		retorno =-2;
		if(!alb_getFormatoVentaAlbumPorId(listaFormatosALbum, sizelistaFormatosAlbum, &nuevoFormatoDeVentaAlbum))
		{
			listaAlbum[indexUnAlbum].formatoDelAlbumFk = nuevoFormatoDeVentaAlbum;
		}
	}
	return retorno;
}

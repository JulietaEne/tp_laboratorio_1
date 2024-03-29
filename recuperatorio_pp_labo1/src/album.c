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
			{102, "Sin restricciones",{1,5,2004},2500,2,2,2,3, NOT_EMPTY},
			{103, "El templo del pop",{1,8,2014},2500,2,2,2,3, NOT_EMPTY},
			{104, "Master of puppets",{1,10,1986}, 1800,3,3,1,3,NOT_EMPTY},
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
	int confirmar;

	retorno = -1;
	auxId = *ultimoId;
	if(listaAlbum != NULL && listaArtistas != NULL && listaGenerosDeAlbum && listaTiposDeArtista != NULL)
	{
		confirmar = continuar("desea hardcodear 5 datos?");
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
		print_unEncabezado(1);
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
 * \brief interactua con el usuario para solicitar el nombre de un artista
 * \param listaArtistas eArtista* Recibe la direccion de memoria del array donde se guardara el dato ingresado
 * \param sizeListaArtista int Recibe el tamaño de la lista
 * \param idNombreArtistaFk int* Recibe la dirección de memoria donde se va a alojar el dato hayado
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
		print_unEncabezado(4);
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


/*
 * \brief la lista de artistas y su tamaño e imprime su contenido.
 * \param listaArtistas eArtista* Recibe la direccion de memoria del array
 * \param sizeListaArtista int Recibe por valor el tamaño del array

 * \return retorna int -1 si hubo un error en los parametros recibidos
 * 						0 si la operacion se realizo correctamente
 */
int tipoArtista_printListaTiposArtista(eTipoArtista* listaTiposDeArtista, int sizeListaTiposDeArtista)
{
	int retorno;
	int i;

	retorno = -1;
	if(listaTiposDeArtista!= NULL && sizeListaTiposDeArtista>0)
	{
		retorno = 0;
		print_unEncabezado(5);
		for(i=0; i<sizeListaTiposDeArtista; i++)
		{
			if( !validacionesInt_sonIdenticos(listaTiposDeArtista[i].isEmpty,IS_EMPTY))
			{
				tipoArtista_printTiposArtistaPorIndex(listaTiposDeArtista, i);
			}
		}
	}
	return retorno;
}

/*
 * \brief Recibe un index de la lista e imprime su contenido.
 * \param listaArtistas eArtista* Recibe la direccion de memoria del array sobre el cual va a trabajar
 * \param sizeListaArtistas int Recibe por valor el tamaño del array
 *
 * \return retorna int -1 si hubo un error en los parametros recibidos
 * 						0 si la operacion se realizo correctamente
 */
int tipoArtista_printTiposArtistaPorIndex(eTipoArtista* listaTiposDeArtista, int indiceTiposArtista)
{
	int retorno;
	retorno = -1;

	if(listaTiposDeArtista!= NULL && indiceTiposArtista >=0)
	{
		retorno = 0;

		printf(" %-7d %s\n",
				listaTiposDeArtista[indiceTiposArtista].idTipoArtista,
				listaTiposDeArtista[indiceTiposArtista].descripcion);
	}

	return retorno;
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
/********************************************************/

/**
 * \brief Imprime el encabezado de la lista indicada
 * \param codigoLista int Recibe el código del encabezado que se desea imprimir
 * 						(1) Encabezado lista album (general)
 * 						(2) Encabezado lista formatos de album
 * 						(3) Encabezado lista géneros de album
 * 						(4) Encabezado lista de artistas
 * \return void
 *
 */
void print_unEncabezado(int codigoLista)
{
	if(codigoLista >= 0 && codigoLista <= 5){
		switch (codigoLista) {
		case 1:
			//1- encabezado general
			printf("\nCODIGO ID\t\tTITULO DEL ALBUM\t\tGENERO\t\tFECHA DE PUBLICACION\tTIPO ALBUM\tIMPORTE\t\tARTISTA\t\tTIPO ARTISTA\n");
			break;
		case 2:
			//2- lista de formatos de album
			printf("\nCODIGO\tFORMATO DE VENTA\n");
			break;
		case 3:
			//3- lista de generos de un album
			printf("\nCODIGO\tGENERO ALBUM\n");
			break;
		case 4:
			//4- lista artista
			printf("\nCODIGO\tNOMBRE ARTISTA\n");
			break;
		case 5:
			//5- lista tipos artista
			printf("\nCODIGO\tTIPO ARTISTA\n");
			break;
		case 0:
			break;
		}
	}
}

/********************************************************/

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
			if(unId<=QTY_GENERO_ALBUM && unId>0)
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
		print_unEncabezado(3);
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

//*******informes********//

int informes_informarCantAlbumsPreviosAlDosMil(eAlbum* listaAlbum, int sizeListaAlbum)
{
	int retorno;
	retorno = -1;
	if(listaAlbum != NULL && sizeListaAlbum >0)
	{
		printf("Cantidad de albumes previos al 2000: %d", informes_analizarAlbumsPreviosAlDosmil(listaAlbum,sizeListaAlbum));
	}
	return retorno;
}

int informes_informarTotalyPromedioDeImportes(eAlbum* listaAlbum, int sizeListaAlbum)
{
	int retorno;
	float sumatoriaImportes;
	float promedio;

	retorno = -1;
	if(listaAlbum != NULL && sizeListaAlbum >0)
	{
		sumatoriaImportes = informes_calcularPromedioImportes(listaAlbum, sizeListaAlbum, &promedio);
		if(sumatoriaImportes > 0)
		{
			printf("Total y promedio de importes cargados\nTOTAL $%.2f\nPROMEDIO $%.2f\n\n", sumatoriaImportes, promedio);
			retorno=0;//retorna -1 si hubo un error. >0 si opero correctamente (retorna el promedio)
		}
		else
		{
			printf("No se encontraron albumes cargados");
		}
	}
	return retorno;
}

float informes_calcularPromedioImportes(eAlbum* listaAlbum, int sizeListaAlbum, float* promedio)
{
	int retorno;
	int cantAlbumsCargados;
	float sumatoriaImportes;

	retorno = -1;
	if(listaAlbum!= NULL && sizeListaAlbum>0 && promedio != NULL)
	{
		cantAlbumsCargados = alb_contadorAlbumesCargados(listaAlbum, sizeListaAlbum);
		sumatoriaImportes = informes_sumatoriaImportes(listaAlbum, sizeListaAlbum);
		*promedio = sumatoriaImportes/(float)cantAlbumsCargados;
		retorno = sumatoriaImportes;
	}
	return retorno;
}

/*
 * \brief Recorre el array recibido para sumar los campos importe de cada album recorrido
 * \param listaAlbum eAlbum* Recibe la direccion de memoria del array sobre el cual va a trabajar
 * \param sizeListaAlbum int Recibe por valor el tamaño del array
 * \return retorna int -1 si hubo un error en los parametros recibidos
 * 					   >=0 si la operacion se realizo correctamente(retorna la sumatoria total)
 *
 */
float informes_sumatoriaImportes(eAlbum* listaAlbum, int sizeListaAlbum)
{
	float retorno;
	int i;
	float sumatoria;
	retorno= -1;
	sumatoria=0;

	if(listaAlbum!= NULL && sizeListaAlbum>0)
	{
		retorno = 0;
		for(i=0; i<sizeListaAlbum; i++)
		{
			if(validacionesInt_sonIdenticos(listaAlbum[i].isEmpty, NOT_EMPTY))
			{
				sumatoria=sumatoria+listaAlbum[i].importeAlbum;
			}
		}
		retorno=sumatoria;
	}
	return retorno;
}

int informes_analizarAlbumsPreviosAlDosmil(eAlbum* listaAlbum, int sizeListaAlbum)
{
	int retorno;
	int i;
	int cantPreviosAlDosmil;
	retorno= -1;
	cantPreviosAlDosmil=0;

	if(listaAlbum!= NULL && sizeListaAlbum>0)
	{
		for(i=0; i<sizeListaAlbum; i++)
		{
			if(validacionesInt_sonIdenticos(listaAlbum[i].isEmpty, NOT_EMPTY)
					&& listaAlbum[i].fechaPublicacionAlbum.year < 2000)
			{
				cantPreviosAlDosmil++;
			}
		}
		retorno=cantPreviosAlDosmil;
	}
	return retorno;
}

//listas
int puntoCinco(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtistas, int sizeListaArtistas, eGenero* listaGenerosDeAlbum, int sizeListaGenerosDeAlbum, eTipoArtista* listaTiposDeArtista, int sizeListaTiposDeArtista, eTipoAlbum* listaFormatosAlbum, int sizeListaFormatosAlbum)
{
	int retorno;
	retorno = -1;
	if(listaAlbum != NULL && sizeListaAlbum>0 && listaArtistas != NULL && sizeListaArtistas> 0 && listaGenerosDeAlbum != NULL && sizeListaGenerosDeAlbum >0 && listaTiposDeArtista != NULL && sizeListaTiposDeArtista>0 && listaFormatosAlbum != NULL && sizeListaFormatosAlbum)
	{
		printf("\nA. Lista de Generos de Albumes");
		generoAlbum_printListaGenerosDeAlbum(listaGenerosDeAlbum, sizeListaGenerosDeAlbum);

		printf("\n\nB. Lista de Tipos de Artistas Musicales");
		tipoArtista_printListaTiposArtista(listaTiposDeArtista, sizeListaTiposDeArtista);

		printf("\n\nC. Lista de Artistas Cargados");
		art_printListaArtista(listaArtistas, sizeListaArtistas);

		printf("\n\nD. Lista de Todos los Albumes Cargados");
		alb_printListaCompleta(listaAlbum, sizeListaAlbum, listaArtistas, sizeListaArtistas, listaGenerosDeAlbum, sizeListaGenerosDeAlbum, listaTiposDeArtista, sizeListaTiposDeArtista, listaFormatosAlbum, sizeListaFormatosAlbum);

		printf("\n\nE. Lista de Albumes Ordenados: segun importe(descendente) y segun titulo(ascendente)");
		alb_printListaCompletaOrdenada(listaAlbum, sizeListaAlbum, listaArtistas, sizeListaArtistas, listaGenerosDeAlbum, sizeListaGenerosDeAlbum, listaTiposDeArtista, sizeListaTiposDeArtista, listaFormatosAlbum, sizeListaFormatosAlbum);

		printf("\n\nF. Lista de Albumes publicados antes del 1/1/2000\n");
		informes_printAlbumsPreviosAlDosmil(listaAlbum, sizeListaAlbum, listaArtistas, sizeListaArtistas, listaGenerosDeAlbum, sizeListaGenerosDeAlbum, listaTiposDeArtista, sizeListaTiposDeArtista, listaFormatosAlbum, sizeListaFormatosAlbum);

		printf("\n\nG. Lista de Albumes de Importe Mayor al promedio de los cargados\n");
		informes_printAlbumsImporteMayorAlPromedio(listaAlbum, sizeListaAlbum, listaArtistas, sizeListaArtistas, listaGenerosDeAlbum, sizeListaGenerosDeAlbum, listaTiposDeArtista, sizeListaTiposDeArtista, listaFormatosAlbum, sizeListaFormatosAlbum);

		printf("\n\nH. Lista de Albumes según Artista\n");
		informes_printAlbumsSegunArtista(listaAlbum, sizeListaAlbum, listaArtistas, sizeListaArtistas, listaGenerosDeAlbum, sizeListaGenerosDeAlbum, listaTiposDeArtista, sizeListaTiposDeArtista, listaFormatosAlbum, sizeListaFormatosAlbum);

		printf("\n\nI. Lista todos los albumes de un año determinado\n");
		informes_printAlbumSegunAnno(listaAlbum, sizeListaAlbum, listaArtistas, sizeListaArtistas, listaGenerosDeAlbum, sizeListaGenerosDeAlbum, listaTiposDeArtista, sizeListaTiposDeArtista, listaFormatosAlbum, sizeListaFormatosAlbum);

		printf("\n\nJ. Lista de Albumes más caros\n");
		print_albumsMayorImporte(listaAlbum, sizeListaAlbum, listaArtistas, sizeListaArtistas, listaGenerosDeAlbum, sizeListaGenerosDeAlbum, listaTiposDeArtista, sizeListaTiposDeArtista, listaFormatosAlbum, sizeListaFormatosAlbum);

	}
	return retorno;
}

int informes_printAlbumsPreviosAlDosmil(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtistas, int sizeListaArtistas, eGenero* listaGenerosDeAlbum, int sizeListaGenerosDeAlbum, eTipoArtista* listaTiposDeArtista, int sizeListaTiposDeArtista, eTipoAlbum* listaFormatosAlbum, int sizeListaFormatosAlbum)
{
	int retorno;
	int i;
	int cantPreviosAlDosmil;
	retorno= -1;
	cantPreviosAlDosmil=0;

	if(listaAlbum!= NULL && sizeListaAlbum>0)
	{
		for(i=0; i<sizeListaAlbum; i++)
		{
			if(validacionesInt_sonIdenticos(listaAlbum[i].isEmpty, NOT_EMPTY)
					&& listaAlbum[i].fechaPublicacionAlbum.year < 2000)
			{
				alb_printUnAlbum(i, listaAlbum, sizeListaAlbum, listaArtistas, sizeListaArtistas, listaGenerosDeAlbum, sizeListaGenerosDeAlbum, listaTiposDeArtista, sizeListaTiposDeArtista, listaFormatosAlbum, sizeListaFormatosAlbum);
			}
		}
		retorno=cantPreviosAlDosmil;
	}
	return retorno;
}

int informes_printAlbumsImporteMayorAlPromedio(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtistas, int sizeListaArtistas, eGenero* listaGenerosDeAlbum, int sizeListaGenerosDeAlbum, eTipoArtista* listaTiposDeArtista, int sizeListaTiposDeArtista, eTipoAlbum* listaFormatosAlbum, int sizeListaFormatosAlbum)
{
	int retorno;
	int i;
	float promedio;

	retorno= -1;
	informes_calcularPromedioImportes(listaAlbum, sizeListaAlbum, &promedio);
	printf("\nPromedio de importes: $%.2f\n", promedio);
	if(listaAlbum!= NULL && sizeListaAlbum>0)
	{
		print_unEncabezado(1);
		for(i=0; i<sizeListaAlbum; i++)
		{
			if(validacionesInt_sonIdenticos(listaAlbum[i].isEmpty, NOT_EMPTY)
					&& listaAlbum[i].importeAlbum > promedio)
			{
				alb_printUnAlbum(i, listaAlbum, sizeListaAlbum, listaArtistas, sizeListaArtistas, listaGenerosDeAlbum, sizeListaGenerosDeAlbum, listaTiposDeArtista, sizeListaTiposDeArtista, listaFormatosAlbum, sizeListaFormatosAlbum);
			}
		}
		retorno=0;
	}
	return retorno;
}

int alb_swap(eAlbum* listaAlbum, int index1, int index2)
{
	int retorno;
	eAlbum auxPass;
	retorno = -1;
	if(listaAlbum!= NULL)
	{
		auxPass= listaAlbum[index1];
		listaAlbum[index1]= listaAlbum[index2];
		listaAlbum[index2]= auxPass;
		retorno=0;
	}
	return retorno;
}

int alb_printListaCompletaOrdenada(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtistas, int sizeListaArtistas, eGenero* listaGenerosDeAlbum, int sizeListaGenerosDeAlbum, eTipoArtista* listaTiposDeArtista, int sizeListaTiposDeArtista, eTipoAlbum* listaFormatosAlbum, int sizeListaFormatosAlbum)
{
	int retorno;
	retorno = -1;
	if(listaAlbum != NULL && sizeListaAlbum>0 && listaArtistas != NULL && sizeListaArtistas>0 && listaGenerosDeAlbum != NULL && sizeListaGenerosDeAlbum >0 && listaTiposDeArtista != NULL && sizeListaTiposDeArtista >0 && listaFormatosAlbum != NULL && sizeListaFormatosAlbum>0)
	{
		if(!alb_ordenarLista(listaAlbum, sizeListaAlbum))
		{
			alb_printListaCompleta(listaAlbum, sizeListaAlbum, listaArtistas, sizeListaArtistas, listaGenerosDeAlbum, sizeListaGenerosDeAlbum, listaTiposDeArtista, sizeListaTiposDeArtista, listaFormatosAlbum, sizeListaFormatosAlbum);
		}
		retorno=0;
	}
	return retorno;
}

int alb_ordenarLista(eAlbum* listaAlbum, int sizeListaAlbum)
{
	int retorno;
	int i;
	int retornoCompare;
	int flagSwap;
	int nuevoLimite;

	retorno = -1;

	if(listaAlbum != NULL && sizeListaAlbum>0)
	{
		retorno = 0;
		nuevoLimite = sizeListaAlbum -1;
		do{
			flagSwap = 0;
			for(i=0; i<nuevoLimite; i++)
			{
				if(		listaAlbum[i].isEmpty== NOT_EMPTY
						&& listaAlbum[i+1].isEmpty == NOT_EMPTY
						&& listaAlbum[i].importeAlbum<listaAlbum[i+1].importeAlbum)
				{
					alb_swap(listaAlbum, i, i+1);
					flagSwap = 1;
				}else if(listaAlbum[i].isEmpty== NOT_EMPTY
						&& listaAlbum[i+1].isEmpty == NOT_EMPTY
						&& listaAlbum[i].importeAlbum==listaAlbum[i+1].importeAlbum)
				{
					arrayChar_convertirASustantivoPropio(listaAlbum[i].titulo, strlen(listaAlbum[i].titulo));
					arrayChar_convertirASustantivoPropio(listaAlbum[i+1].titulo, strlen(listaAlbum[i+1].titulo));

					retornoCompare = strncasecmp(listaAlbum[i].titulo, listaAlbum[i+1].titulo,STR_SIZE);
					if(retornoCompare>0)
					{
						alb_swap(listaAlbum, i, i+1);
						flagSwap = 1;
					}
				}
			}
			nuevoLimite --;
		}while(flagSwap);
	}

	return retorno;
}

int informes_printAlbumsSegunArtista(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtistas, int sizeListaArtistas, eGenero* listaGenerosDeAlbum, int sizeListaGenerosDeAlbum, eTipoArtista* listaTiposDeArtista, int sizeListaTiposDeArtista, eTipoAlbum* listaFormatosAlbum, int sizeListaFormatosAlbum)
{
	int retorno;
	int i;
	int j;
	int flagAlbumDeArtista;

	retorno = -1;
	if(listaAlbum != NULL && sizeListaAlbum>0 && listaArtistas != NULL && sizeListaArtistas>0 && listaGenerosDeAlbum != NULL && sizeListaGenerosDeAlbum >0 && listaTiposDeArtista != NULL && sizeListaTiposDeArtista >0 && listaFormatosAlbum != NULL && sizeListaFormatosAlbum>0)
	{
		retorno = 0;
		for(i=0; i<sizeListaArtistas; i++)
		{
			printf("\nAlbumes de %s\n", listaArtistas[i].nombre);
			flagAlbumDeArtista =0;
			for(j=0; j<sizeListaAlbum; j++)
			{
				if(validacionesInt_sonIdenticos(listaAlbum[i].isEmpty, NOT_EMPTY)
						&& listaArtistas[i].idArtistaDelAlbum == listaAlbum[j].artistaDelAlbumFk)
				{
					alb_printUnAlbum(j, listaAlbum, sizeListaAlbum, listaArtistas, sizeListaArtistas, listaGenerosDeAlbum, sizeListaGenerosDeAlbum, listaTiposDeArtista, sizeListaTiposDeArtista, listaFormatosAlbum, sizeListaFormatosAlbum);
					flagAlbumDeArtista=1;
				}
			}
			if(!flagAlbumDeArtista)
			{
				printf("aun no tiene albums cargados");
			}
		}
	}
	return retorno;
}

int informes_printAlbumSegunAnno(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtistas, int sizeListaArtistas, eGenero* listaGenerosDeAlbum, int sizeListaGenerosDeAlbum, eTipoArtista* listaTiposDeArtista, int sizeListaTiposDeArtista, eTipoAlbum* listaFormatosAlbum, int sizeListaFormatosAlbum)
{
	int retorno;
	int anno;
	int i;
	int flagAlgumPorAnno;

	retorno = -1;
	flagAlgumPorAnno = 0;
	if(listaAlbum != NULL && sizeListaAlbum>0 && listaArtistas != NULL && sizeListaArtistas>0 && listaGenerosDeAlbum != NULL && sizeListaGenerosDeAlbum >0 && listaTiposDeArtista != NULL && sizeListaTiposDeArtista >0 && listaFormatosAlbum != NULL && sizeListaFormatosAlbum>0)
	{
		utn_GetNumeroInt(&anno, "Ingrese el año que desea buscar: ", "ingrese un dato valido (1920-2022)", MIN_YEAR, MAX_YEAR, REINTENTOS);
		for(i=0; i<sizeListaAlbum; i++)
		{
			if(validacionesInt_sonIdenticos(listaAlbum[i].isEmpty, NOT_EMPTY)
					&& listaAlbum[i].fechaPublicacionAlbum.year == anno)
			{
				alb_printUnAlbum(i, listaAlbum, sizeListaAlbum, listaArtistas, sizeListaArtistas, listaGenerosDeAlbum, sizeListaGenerosDeAlbum, listaTiposDeArtista, sizeListaTiposDeArtista, listaFormatosAlbum, sizeListaFormatosAlbum);
				flagAlgumPorAnno = 1;
			}
		}
		if(!flagAlgumPorAnno)
		{
			printf("El año %d aun no tiene albums cargados", anno);
		}
	}
	return retorno;
}


int informes_hayarMayorImporte(eAlbum* listaAlbum, int sizeListaAlbum, float* mayorImporte)
{
	int retorno;
	int i;
	float importeMayor;

	retorno = -1;
	if(listaAlbum != NULL && sizeListaAlbum>0 && mayorImporte != NULL)
	{
		retorno=0;
		for(i=0; i<sizeListaAlbum; i++)
		{
			if(i==0 || (listaAlbum[i].isEmpty == NOT_EMPTY && importeMayor < listaAlbum[i].importeAlbum))
			{
				importeMayor = listaAlbum[i].importeAlbum;
			}
		}
		*mayorImporte = importeMayor;
	}
	return retorno;
}

int print_albumsMayorImporte(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtistas, int sizeListaArtistas, eGenero* listaGenerosDeAlbum, int sizeListaGenerosDeAlbum, eTipoArtista* listaTiposDeArtista, int sizeListaTiposDeArtista, eTipoAlbum* listaFormatosAlbum, int sizeListaFormatosAlbum)
{
	int retorno;
	int i;
	float mayorImporte;

	retorno = -1;
	if(listaAlbum != NULL && sizeListaAlbum>0 && listaArtistas != NULL && sizeListaArtistas>0 && listaGenerosDeAlbum != NULL && sizeListaGenerosDeAlbum >0 && listaTiposDeArtista != NULL && sizeListaTiposDeArtista >0 && listaFormatosAlbum != NULL && sizeListaFormatosAlbum>0)
	{
		informes_hayarMayorImporte(listaAlbum, sizeListaAlbum, &mayorImporte);

		retorno = 0;
		for(i=0; i<sizeListaAlbum; i++)
		{
			if(validacionesInt_sonIdenticos(listaAlbum[i].isEmpty, NOT_EMPTY)
					&& listaAlbum[i].importeAlbum == mayorImporte)
			{
				alb_printUnAlbum(i, listaAlbum, sizeListaAlbum, listaArtistas, sizeListaArtistas, listaGenerosDeAlbum, sizeListaGenerosDeAlbum, listaTiposDeArtista, sizeListaTiposDeArtista, listaFormatosAlbum, sizeListaFormatosAlbum);
			}
		}
	}
	return retorno;
}

//consignasParteDosExamen
int consignasParteDosExamen(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtistas, int sizeListaArtistas, eGenero* listaGenerosDeAlbum, int sizeListaGenerosDeAlbum, eTipoArtista* listaTiposDeArtista, int sizeListaTiposDeArtista, eTipoAlbum* listaFormatosAlbum, int sizeListaFormatosAlbum)
{
	int retorno;
	retorno = -1;
	if(listaAlbum != NULL && sizeListaAlbum>0 && listaArtistas != NULL && sizeListaArtistas> 0 && listaGenerosDeAlbum != NULL && sizeListaGenerosDeAlbum >0 && listaTiposDeArtista != NULL && sizeListaTiposDeArtista>0 && listaFormatosAlbum != NULL && sizeListaFormatosAlbum)
	{
		printf("\nA. Listar todos los albumes que no sean de vinilo\n");
		examenParteDos_printNoVinilos(listaAlbum, sizeListaAlbum, listaArtistas, sizeListaArtistas, listaGenerosDeAlbum, sizeListaGenerosDeAlbum, listaTiposDeArtista, sizeListaTiposDeArtista, listaFormatosAlbum, sizeListaFormatosAlbum);

		printf("\n\nB. Listar todos los albumes de vinilo que correspondan a un artista determinado");
		examenParteDos_printViniloSegunArtistaDeterminado(listaAlbum, sizeListaAlbum, listaArtistas, sizeListaArtistas, listaGenerosDeAlbum, sizeListaGenerosDeAlbum, listaTiposDeArtista, sizeListaTiposDeArtista, listaFormatosAlbum, sizeListaFormatosAlbum);
	}
	return retorno;
}

int examenParteDos_printNoVinilos(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtistas, int sizeListaArtistas, eGenero* listaGenerosDeAlbum, int sizeListaGenerosDeAlbum, eTipoArtista* listaTiposDeArtista, int sizeListaTiposDeArtista, eTipoAlbum* listaFormatosAlbum, int sizeListaFormatosAlbum)
{
	int retorno;
	int i;

	retorno = -1;
	if(listaAlbum != NULL && sizeListaAlbum>0 && listaArtistas != NULL && sizeListaArtistas> 0 && listaGenerosDeAlbum != NULL && sizeListaGenerosDeAlbum >0 && listaTiposDeArtista != NULL && sizeListaTiposDeArtista>0 && listaFormatosAlbum != NULL && sizeListaFormatosAlbum)
	{
		retorno = 0;
		for(i=0; i<sizeListaAlbum; i++)
		{
			if(listaAlbum[i].isEmpty == NOT_EMPTY && listaAlbum[i].formatoDelAlbumFk != VINILO)
			{
				alb_printUnAlbum(i, listaAlbum, sizeListaAlbum, listaArtistas, sizeListaArtistas, listaGenerosDeAlbum, sizeListaGenerosDeAlbum, listaTiposDeArtista, sizeListaTiposDeArtista, listaFormatosAlbum, sizeListaFormatosAlbum);
			}
		}
	}
	return retorno;
}

int examenParteDos_printViniloSegunArtistaDeterminado(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtistas, int sizeListaArtistas, eGenero* listaGenerosDeAlbum, int sizeListaGenerosDeAlbum, eTipoArtista* listaTiposDeArtista, int sizeListaTiposDeArtista, eTipoAlbum* listaFormatosAlbum, int sizeListaFormatosAlbum)
{
	int retorno;
	int idArtistaElegido;
	int i;
	int flagTieneAlbums;

	flagTieneAlbums = 0;
	retorno = -1;
	if(listaAlbum != NULL && sizeListaAlbum>0 && listaArtistas != NULL && sizeListaArtistas> 0 && listaGenerosDeAlbum != NULL && sizeListaGenerosDeAlbum >0 && listaTiposDeArtista != NULL && sizeListaTiposDeArtista>0 && listaFormatosAlbum != NULL && sizeListaFormatosAlbum)
	{
		retorno = 0;
		alb_getArtistaPorId(listaArtistas, sizeListaArtistas, &idArtistaElegido);

		printf("\n... buscando en el sistema album tipo vinilo **ARTISTA:%s** ...\n", listaArtistas[idArtistaElegido-1].nombre);

		for(i=0; i<sizeListaAlbum; i++)
		{
			if(listaAlbum[i].isEmpty == NOT_EMPTY
					&& listaAlbum[i].artistaDelAlbumFk == idArtistaElegido
					&& listaAlbum[i].formatoDelAlbumFk == VINILO)
			{
				alb_printUnAlbum(i, listaAlbum, sizeListaAlbum, listaArtistas, sizeListaArtistas, listaGenerosDeAlbum, sizeListaGenerosDeAlbum, listaTiposDeArtista, sizeListaTiposDeArtista, listaFormatosAlbum, sizeListaFormatosAlbum);
				flagTieneAlbums = 1;
			}
		}
		if(!flagTieneAlbums)
		{
			printf("El artista %s aún no tiene albums cargados en el sistema", listaArtistas[idArtistaElegido-1].nombre);
		}
	}
	return retorno;
}

//consignas recuperatorio
int consignasRecuperatorio(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtistas, int sizeListaArtistas, eGenero* listaGenerosDeAlbum, int sizeListaGenerosDeAlbum, eTipoArtista* listaTiposDeArtista, int sizeListaTiposDeArtista, eTipoAlbum* listaFormatosAlbum, int sizeListaFormatosAlbum)
{
	int retorno;
	retorno = -1;
	if(listaAlbum != NULL && sizeListaAlbum>0 && listaArtistas != NULL && sizeListaArtistas> 0 && listaGenerosDeAlbum != NULL && sizeListaGenerosDeAlbum >0 && listaTiposDeArtista != NULL && sizeListaTiposDeArtista>0 && listaFormatosAlbum != NULL && sizeListaFormatosAlbum)
	{
		printf("\nA. Informar la cantidad de solistas de un año determinado\n");
		recuperatorio_contadorSolistasSegunAnnoDeterminado(listaAlbum, sizeListaAlbum, listaArtistas, sizeListaArtistas, listaGenerosDeAlbum, sizeListaGenerosDeAlbum, listaTiposDeArtista, sizeListaTiposDeArtista, listaFormatosAlbum, sizeListaFormatosAlbum);

		printf("\n\nB. Listado de todos los albumes de un tipo de album y de un genero determinado\n\n  Según el tipo de album y el género que desea hallar, indique lo siguiente\n");
		recuperatorio_listarAlbumesSegunTipoYgeneroDeterminado(listaAlbum, sizeListaAlbum, listaArtistas, sizeListaArtistas, listaGenerosDeAlbum, sizeListaGenerosDeAlbum, listaTiposDeArtista, sizeListaTiposDeArtista, listaFormatosAlbum, sizeListaFormatosAlbum);
	}
	return retorno;
}

int recuperatorio_contadorSolistasSegunAnnoDeterminado(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtistas, int sizeListaArtistas, eGenero* listaGenerosDeAlbum, int sizeListaGenerosDeAlbum, eTipoArtista* listaTiposDeArtista, int sizeListaTiposDeArtista, eTipoAlbum* listaFormatosAlbum, int sizeListaFormatosAlbum)
{
	int retorno;
	int anno;
	int i;
	int contador;

	contador = 0;
	retorno = -1;
	if(listaAlbum != NULL && sizeListaAlbum>0 && listaArtistas != NULL && sizeListaArtistas> 0 && listaGenerosDeAlbum != NULL && sizeListaGenerosDeAlbum >0 && listaTiposDeArtista != NULL && sizeListaTiposDeArtista>0 && listaFormatosAlbum != NULL && sizeListaFormatosAlbum)
	{
		utn_GetNumeroInt(&anno, "Ingrese el año que desea buscar: ", "ingrese un dato valido (1920-2022)", MIN_YEAR, MAX_YEAR, REINTENTOS);
		for(i=0; i<sizeListaAlbum; i++)
		{
			if(listaAlbum[i].isEmpty == NOT_EMPTY && listaAlbum[i].fechaPublicacionAlbum.year == anno && listaAlbum[i].tipoArtistaFk == SOLISTA)
			{
				contador++;
			}
		}

		printf("La cantidad de bandas para el año %d es de: %d", anno, contador);

	}
	return retorno;
}

int recuperatorio_listarAlbumesSegunTipoYgeneroDeterminado(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtistas, int sizeListaArtistas, eGenero* listaGenerosDeAlbum, int sizeListaGenerosDeAlbum, eTipoArtista* listaTiposDeArtista, int sizeListaTiposDeArtista, eTipoAlbum* listaFormatosAlbum, int sizeListaFormatosAlbum)
{
	int retorno;
	int formatoAlbumElegido;
	int generoAlbumElegido;
	int i;
	int flagHalloFormatoYGenero;

	flagHalloFormatoYGenero = 0;
	retorno = -1;
	if(listaAlbum != NULL && sizeListaAlbum>0 && listaArtistas != NULL && sizeListaArtistas> 0 && listaGenerosDeAlbum != NULL && sizeListaGenerosDeAlbum >0 && listaTiposDeArtista != NULL && sizeListaTiposDeArtista>0 && listaFormatosAlbum != NULL && sizeListaFormatosAlbum)
	{
		retorno = 0;
		alb_getFormatoVentaAlbumPorId(listaFormatosAlbum, sizeListaFormatosAlbum, &formatoAlbumElegido);
		alb_getGeneroAlbumPorId(listaGenerosDeAlbum, sizeListaGenerosDeAlbum, &generoAlbumElegido);

		printf("\n... buscando en el sistema **TIPO ALBUM:%s - GENERO:%s** ...\n", listaFormatosAlbum[formatoAlbumElegido-1].descripcion, listaGenerosDeAlbum[generoAlbumElegido-1].descripcion);
		for(i=0; i<sizeListaAlbum; i++)
		{
			if(listaAlbum[i].isEmpty == NOT_EMPTY
					&& listaAlbum[i].formatoDelAlbumFk == formatoAlbumElegido
					&& listaAlbum[i].generoDelAlbumFk == generoAlbumElegido)
			{
				alb_printUnAlbum(i, listaAlbum, sizeListaAlbum, listaArtistas, sizeListaArtistas, listaGenerosDeAlbum, sizeListaGenerosDeAlbum, listaTiposDeArtista, sizeListaTiposDeArtista, listaFormatosAlbum, sizeListaFormatosAlbum);
				flagHalloFormatoYGenero =1;
			}
		}
		if(!flagHalloFormatoYGenero)
		{
			printf("Aun no se han cargado albumes del formato y género indicados");
		}
	}
	return retorno;
}

int consignasRecuperatorioInstanciaFinal(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtistas, int sizeListaArtistas, eGenero* listaGenerosDeAlbum, int sizeListaGenerosDeAlbum, eTipoArtista* listaTiposDeArtista, int sizeListaTiposDeArtista, eTipoAlbum* listaFormatosAlbum, int sizeListaFormatosAlbum)
{
	int retorno;
	retorno = -1;
	{
		if(listaAlbum != NULL && sizeListaAlbum>0 && listaArtistas != NULL && sizeListaArtistas> 0 && listaGenerosDeAlbum != NULL && sizeListaGenerosDeAlbum >0 && listaTiposDeArtista != NULL && sizeListaTiposDeArtista>0 && listaFormatosAlbum != NULL && sizeListaFormatosAlbum)
		{
			printf("\nA. Informar la cantidad de bandas de un género determinado.Para continuar, indique el género sobre el cual desea contabilizar:");
			recuperatorioFinal_printContadorBandasPorDeterminadoGenero(listaAlbum, sizeListaAlbum, listaGenerosDeAlbum, sizeListaGenerosDeAlbum);

			printf("\n\nB. listado de todos los álbumes de un artista determinado y de un tipo de álbum\n\n  Según el tipo de album y el género que desea hallar, indique lo siguiente\n");
			recuperatorioFinal_printSegunArtistaYTipoAlbumDeterminado(listaAlbum, sizeListaAlbum, listaArtistas, sizeListaArtistas, listaGenerosDeAlbum, sizeListaGenerosDeAlbum, listaTiposDeArtista, sizeListaTiposDeArtista, listaFormatosAlbum, sizeListaFormatosAlbum);
		}

	}
	return retorno;
}
/*
 * Pido el id del genero que quiero contabilizar
 * Recorro el array para analizar el campo correspondiente al idGenero => si es == al idIngresado
 * Si hay coincidencia y si tambien es BANDA, contabiliza
 *
 *
 * */
void recuperatorioFinal_printContadorBandasPorDeterminadoGenero(eAlbum* listaAlbum, int sizeListaAlbum,eGenero* listaGenerosDeAlbum, int sizeListaGenerosDeAlbum)
{
	int idGeneroIngresado;
	int i;
	int contadorBandas;

	contadorBandas = 0;
	alb_getGeneroAlbumPorId(listaGenerosDeAlbum, sizeListaGenerosDeAlbum, &idGeneroIngresado);

	for(i=0; i<sizeListaAlbum; i++)
	{
		if(		listaAlbum[i].isEmpty == NOT_EMPTY
				&& listaAlbum[i].generoDelAlbumFk == idGeneroIngresado
				&& listaAlbum[i].tipoArtistaFk == BANDA)
		{
			contadorBandas++;
		}
	}
	printf("En el género indicado la cantidad de albumes de BANDAS cargadas es de: %d", contadorBandas);
}

int recuperatorioFinal_printSegunArtistaYTipoAlbumDeterminado(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtistas, int sizeListaArtistas, eGenero* listaGenerosDeAlbum, int sizeListaGenerosDeAlbum, eTipoArtista* listaTiposDeArtista, int sizeListaTiposDeArtista, eTipoAlbum* listaFormatosAlbum, int sizeListaFormatosAlbum)
{
	int retorno;
	int formatoAlbumElegido;
	int artistaElegido;
	int i;
	int flagHalloFormatoYArtista;

	flagHalloFormatoYArtista = 0;
	retorno = -1;
	if(listaAlbum != NULL && sizeListaAlbum>0 && listaArtistas != NULL && sizeListaArtistas> 0 && listaGenerosDeAlbum != NULL && sizeListaGenerosDeAlbum >0 && listaTiposDeArtista != NULL && sizeListaTiposDeArtista>0 && listaFormatosAlbum != NULL && sizeListaFormatosAlbum)
	{
		retorno = 0;
		alb_getFormatoVentaAlbumPorId(listaFormatosAlbum, sizeListaFormatosAlbum, &formatoAlbumElegido);
		alb_getArtistaPorId(listaArtistas, sizeListaArtistas, &artistaElegido);

		printf("\n... buscando en el sistema **TIPO ALBUM:%s - ARTISTA:%s** ...\n", listaFormatosAlbum[formatoAlbumElegido-1].descripcion, listaArtistas[artistaElegido-1].nombre);
		for(i=0; i<sizeListaAlbum; i++)
		{
			if(listaAlbum[i].isEmpty == NOT_EMPTY
					&& listaAlbum[i].formatoDelAlbumFk == formatoAlbumElegido&& listaAlbum[i].artistaDelAlbumFk == artistaElegido)
			{
				alb_printUnAlbum(i, listaAlbum, sizeListaAlbum, listaArtistas, sizeListaArtistas, listaGenerosDeAlbum, sizeListaGenerosDeAlbum, listaTiposDeArtista, sizeListaTiposDeArtista, listaFormatosAlbum, sizeListaFormatosAlbum);
				flagHalloFormatoYArtista =1;
			}
		}
		if(!flagHalloFormatoYArtista)
		{
			printf("Aun no se han cargado albumes del formato y artista indicados");
		}
	}
	return retorno;
}

/*
 * artista.c
 *
 *  Created on: 29 abr. 2022
 *      Author: julieta_enee
 */

#include "artista.h"


int art_idUltimoArtista(eArtista* listaArtistas, int sizeListaArtista)
{
	int auxMayorId;
	int ultimoId;
	int i;
	auxMayorId = -1;
	if(listaArtistas!= NULL && sizeListaArtista >0)
	{
		auxMayorId= -2;
		for (i=0; i<sizeListaArtista; i++)
		{
			if(listaArtistas[i].isEmpty== NOT_EMPTY)
			{
				if(i==0)
				{
					auxMayorId=ID_ART_INICIAL;
				}
				else
				{
					if(listaArtistas[i].idArtista>auxMayorId)
					{
						auxMayorId=listaArtistas[i].idArtista;
					}
				}
			}
		}
		ultimoId = auxMayorId;
	}

	return ultimoId;
}

/**
* \brief Recibe un array de entidad artista para imprimirlo y luego solicita un id entre los mostrados
* \param listaArtistas eArtista* recibe la direccion de memoria del array a analizar
* \param sizeListaArtista int recibe por valor el tamaño del array
* \return int Return (-1) si hubo un error en los parametros recibidos
* 					 (-2) si no encontro ningun index libre
* 		     		 (>=0) si opero correctamente - el valor del indice que se encontro
*
*/
int art_pedirArtista(eArtista* listaArtistas, int sizeListaArtista)
{
	int unId;
	int idArtista;

	unId =-1;
	if(listaArtistas != NULL && sizeListaArtista>0)
	{
		unId =-2;
		if(!art_printListaArtista(listaArtistas, sizeListaArtista))
		{
			utn_GetNumeroInt(&unId, "ingrese el codigo del Artista: ", "ingrese un codigo valido", MIN_ARTISTA, MAX_ARTISTA, REINTENTOS);
			if(unId<= art_idUltimoArtista(listaArtistas, sizeListaArtista))
			{
				idArtista= unId;
				//printf("DEBUG**** artista: %d", unId);
			}
		}
	}
	return idArtista;
}

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

				//printf("DEBUG** print pasajeros\n");
				art_printPosicion(listaArtistas, i);
			}
		}
	}
	return retorno;
}

int art_printNombreArtista(eArtista* listaArtistas, int sizeListaArtista, int idArtista)
{
	int retorno;
	int i;
	retorno = -1;
	if(listaArtistas != NULL && sizeListaArtista>0)
	{
		retorno =0;
		for (i=0; i<sizeListaArtista ; i++)
		{
			if(idArtista == listaArtistas[i].idArtista)
			{
				printf("-%s\n", listaArtistas[i].nombre);
				break;
			}
		}
	}
	return retorno;
}

int art_printPosicion(eArtista* listaArtistas, int indice)
{
	int retorno;
	retorno = -1;

	if(listaArtistas!= NULL && indice >=0)
	{
		retorno = 0;

		//printf("DEBUG*** print un pasajero\n");
		printf("%5d %18s\n",
				listaArtistas[indice].idArtista,
				listaArtistas[indice].nombre);
	}

	return retorno;
}

void art_printEncabezado(void)
{
	printf("\nCODIGO\t\tNOMBRE ARTISTA\n");
}

/**
* \brief find a eArtista by Id and returns the index position in array.
* \param listaArtistas eArtista* receives the array's memory adress that will operate
* \param sizeListaArtista int to indicate array size
* \param idConsulta int receives the value that compare with .id
* \return Return >=0 passenger index position
* 				(-1) if error about the parameters
*				(-2) if passenger not found
*
*/
int art_findArtistaPorId(eArtista* listaArtistas, int sizeListaArtista, int idConsulta)
{
	int retorno;
	int i;

	retorno = -1;
	if(listaArtistas!= NULL && sizeListaArtista>0)
	{
		retorno = -2;
		for(i=0; i<sizeListaArtista; i++)
		{
			if(validacionesInt_sonIdenticos(listaArtistas[i].idArtista, idConsulta))
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

/**
* \brief realiza un hardcodeo de 5 elementos a cargar en el array de tipo eAlbum
* \param arrayPasajeros eAlbum* Recibe la direccion de memoria del primer elemento del array sobre el cual se operara
* \param sizeListaArtista int Recibe por valor tamaño de la lista
* \return Return 0 si opero correctamente
* 			   (-1) si hubo un error en los parametros recibidos
*
*/
int art_cargaForzadaDeDatos(eArtista* listaArtistas, int sizeListaArtista)
{
	int retorno;
	int i;
	eArtista cargaArtistas[] = {
								{1, "Federic Chopin", NOT_EMPTY},
								{2, "Lali Esposito", NOT_EMPTY},
								{3, "Babasonicos", NOT_EMPTY},
								{4, "Miranda", NOT_EMPTY},
								{5, "Bon Jovi", NOT_EMPTY},
								{6, "Metallica", NOT_EMPTY},
								{7, "Kiss", NOT_EMPTY},
								{8, "Queen", NOT_EMPTY},
								{9, "Paramore", NOT_EMPTY},
								{10, "Avril Lavigne", NOT_EMPTY}
							};
	retorno = -1;
	if(listaArtistas!= NULL && sizeListaArtista>0)
	{
		retorno = -2;
		for(i=0; i<sizeListaArtista; i++)
		{
			listaArtistas[i]= cargaArtistas[i];
		}
		retorno = 0;
	}

	return retorno;
}


/**
* \brief Recibe un array de entidad artista para imprimirlo y luego solicita un id entre los mostrados
* \param listaArtistas eArtista* recibe la direccion de memoria del array a analizar
* \param sizeListaArtista int recibe por valor el tamaño del array
* \return int Return (-1) si hubo un error en los parametros recibidos
* 					 (-2) si no encontro ningun index libre
* 		     		 (>=0) si opero correctamente - el valor del indice que se encontro
*
*/
int genero_pedirGenero(eGenero* listaGeneros, int sizeGeneros)
{
	int unId;
	int idGenero;

	unId =-1;
	if(listaGeneros != NULL && sizeGeneros>0)
	{
		unId =-2;
		if(!genero_printListaGeneros(listaGeneros, sizeGeneros))
		{
			utn_GetNumeroInt(&unId, "ingrese el codigo del Genero: ", "ingrese un codigo valido", 1, 4, REINTENTOS);
			if(unId<= genero_idUltimo(listaGeneros, sizeGeneros))
			{
				idGenero= unId;
				//printf("DEBUG**** artista: %d", unId);
			}
		}
	}
	return idGenero;
}

int genero_printListaGeneros(eGenero* listaGeneros, int sizeGeneros)
{
	int retorno;
	int i;

	retorno = -1;
	if(listaGeneros!= NULL && sizeGeneros>0)
	{
		retorno = 0;
		art_printEncabezado();
		for(i=0; i<sizeGeneros; i++)
		{
			if( !validacionesInt_sonIdenticos(listaGeneros[i].isEmpty,IS_EMPTY))
			{
				//printf("DEBUG** print pasajeros\n");
				genero_printPosicion(listaGeneros, i);
			}
		}
	}
	return retorno;
}

int genero_printPosicion(eGenero* listaGeneros, int indice)
{
	int retorno;
	retorno = -1;

	if(listaGeneros!= NULL && indice >=0)
	{
		retorno = 0;

		//printf("DEBUG*** print un pasajero\n");
		printf("%5d %18s\n",
				listaGeneros[indice].idGenero,
				listaGeneros[indice].descripcion);
	}

	return retorno;
}

/**
* \brief realiza un hardcodeo de 5 elementos a cargar en el array de tipo eAlbum
* \param arrayPasajeros eAlbum* Recibe la direccion de memoria del primer elemento del array sobre el cual se operara
* \param sizeListaArtista int Recibe por valor tamaño de la lista
* \return Return 0 si opero correctamente
* 			   (-1) si hubo un error en los parametros recibidos
*
*/
int genero_cargaForzadaDeDatos(eGenero* listaGeneros, int sizeGeneros)
{
	int retorno;
	int i;
	eGenero cargaGeneros[] = {
								{1, "Clasico", NOT_EMPTY},
								{2, "Pop", NOT_EMPTY},
								{3, "Metal Rock", NOT_EMPTY},
								{4, "Pop Rock", NOT_EMPTY}
							};
	retorno = -1;
	if(listaGeneros!= NULL && sizeGeneros>0)
	{
		retorno = -2;
		for(i=0; i<sizeGeneros; i++)
		{
			listaGeneros[i]= cargaGeneros[i];
		}
		retorno = 0;
	}

	return retorno;
}

int genero_idUltimo(eGenero* listaGeneros, int sizeGeneros)
{
	int auxMayorId;
	int ultimoId;
	int i;
	auxMayorId = -1;
	if(listaGeneros!= NULL && sizeGeneros >0)
	{
		auxMayorId= -2;
		for (i=0; i<sizeGeneros; i++)
		{
			if(listaGeneros[i].isEmpty== NOT_EMPTY)
			{
				if(i==0)
				{
					auxMayorId=ID_ART_INICIAL;
				}
				else
				{
					if(listaGeneros[i].idGenero>auxMayorId)
					{
						auxMayorId=listaGeneros[i].idGenero;
					}
				}
			}
		}
		ultimoId = auxMayorId;
	}

	return ultimoId;
}

int genero_printDescripcGenero(eGenero* listaGenero, int sizeGenero, int idGenero)
{
	int retorno;
	int i;
	retorno = -1;
	if(listaGenero != NULL && sizeGenero>0)
	{
		retorno =0;
		for (i=0; i<sizeGenero ; i++)
		{
			if(idGenero == listaGenero[i].idGenero)
			{
				printf("-%s\n", listaGenero[i].descripcion);
				break;
			}
		}
	}
	return retorno;
}

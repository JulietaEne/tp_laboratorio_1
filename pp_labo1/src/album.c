/*
 * album.c
 *
 *  Created on: 29 abr. 2022
 *      Author: julieta_enee
 */

#include "album.h"

/**
 * \brief Recorre el array recibido para asignar valor inicial al campo isEmpty de todos sus elementos
 * \param listaAlbum eAlbum* Recibe la direccion de memoria del array sobre el cual va a operar
 * \param sizeListaAlbum int Recibe por valor el tamaño del array
 * \return retorna int -1 si hubo un error en los parametros recibidos
 * 						0 si la operacion se realizo correctamente
 *
 */
int alb_initLista(eAlbum* listaAlbum, int sizeListaAlbum)
{
	int retorno;
	int i;
	retorno = -1;
	if(listaAlbum != NULL && sizeListaAlbum>0)
	{
		for(i=0; i<sizeListaAlbum; i++)
		{
			alb_initPosicion(listaAlbum, i, 0);
		}
	}
	return retorno;
}

/**
 * \breif To assign a init value to array's a particular possition
 * \param listaAlbum eAlbum* receives the array which will be operated
 * \param indice int receives the value who indicates where the data will be assigned
 * \param valorInicial int Receives by value the data that is assigned
 * \return retorna int -1 if  Error [Invalid length or NULL pointer or withoufree space]
 * 						0 if Ok - el valor del indice que se encontro
 *
*/
int alb_initPosicion(eAlbum* listaAlbum, int indice, int valorInicial)
{
	int retorno;

	retorno = -1;
	if(listaAlbum != NULL && indice>=0)
	{
		retorno = 0;
		listaAlbum[indice].isEmpty= valorInicial;
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
			if(listaAlbum[i].isEmpty== NOT_EMPTY && listaAlbum[i].idAlbum>auxMayorId)
			{
				auxMayorId=listaAlbum[i].idAlbum;
			}
		}
		*ultimoId = auxMayorId;
		//printf("\nULTIMO ID: %d\n", *ultimoId);
	}

	return *ultimoId;
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
int alb_contadorAlbumesCargados(eAlbum* listaAlbum, int sizeListaAlbum, int* cantidadCargados)
{
	int retorno;
	int i;
	int contador;
	retorno= -1;
	contador=0;
	if(listaAlbum!= NULL && sizeListaAlbum>0 && cantidadCargados!= NULL)
	{
		retorno=-2;
		for(i=0; i<sizeListaAlbum; i++)
		{
			if(validacionesInt_sonIdenticos(listaAlbum[i].isEmpty, NOT_EMPTY))
			{
				contador++;
			}
		}
		*cantidadCargados=contador;
		retorno=i;
	}
	return retorno;
}

/*
 * \brief Recorre el array recibido para imprimir los indices que estan cargados
 * \param listaAlbum eAlbum* Recibe la direccion de memoria del array sobre el cual va a trabajar
 * \param sizeListaAlbum int Recibe por valor el tamaño del array
 * \return retorna int -1 si hubo un error en los parametros recibidos
 * 						0 si la operacion se realizo correctamente
 *
 */
int alb_printLista(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtita, int sizeListaArtista, eTipoAlbum* listaTipoAlbum, int sizeListaTipoAlbum)
{
	int retorno;
	int i;
	//int j;

	retorno = -1;
	if(listaAlbum != NULL && sizeListaAlbum>0 && listaArtita != NULL && sizeListaArtista>0 && listaTipoAlbum != NULL && sizeListaTipoAlbum >0)
	{
		retorno = 0;
		alb_printEncabezado();
		for(i=0; i<sizeListaAlbum; i++)
		{
			if(listaAlbum[i].isEmpty==NOT_EMPTY)
			{
				tipoAlbum_printTipoAlbumSegunId(listaTipoAlbum, sizeListaTipoAlbum, listaAlbum[i].tipoAlbumFk);
				alb_printPosicion(listaAlbum, i);
				art_printNombreArtista(listaArtita, sizeListaArtista, listaAlbum[i].artistaFk);


			}
		}
	}
	return retorno;
}

int alb_printPosicion(eAlbum* listaAlbum, int indiceAlbum)
{
	int retorno;

	retorno = -1;
	if(listaAlbum != NULL && indiceAlbum>=0)
	{
		retorno = 0;

		//printf("DEBUG*** print un pasajero\n");
		printf("%d %15d %20s %8d/%d/%d %15.2f %15d",   listaAlbum[indiceAlbum].tipoAlbumFk,
														listaAlbum[indiceAlbum].idAlbum,
														listaAlbum[indiceAlbum].titulo,
														listaAlbum[indiceAlbum].fecha.day,
														listaAlbum[indiceAlbum].fecha.month,
														listaAlbum[indiceAlbum].fecha.year,
														listaAlbum[indiceAlbum].importe,
														listaAlbum[indiceAlbum].artistaFk);
	}
	return retorno;
}

/**
 * \brief Recibe el array de entidad Album, el array de Artista e imprime el contenido indicado segun la posicion recibida por parametros
 * \param listaAlbum *eAlbum recibe la direccion de memoria del array sobre el cual va a trabajar
 * \param indiceAlbum int Recibe por valor la posicion del array del cual imprimira los valores de sus campos
 * \param listaArtita *eArtista recibe la direccion de memoria del array sobre el cual va a trabajar
 * \param indiceArtista int Recibe por valor la posicion del array Artista del cual imprimira el campo indicado
 * \return retorna int -1 si hubo un error en los parametros recibidos
 * 			0 si la operacion se realizo correctamente
 *
 */
int alb_printPosicionConArtista(eAlbum* listaAlbum, int indiceAlbum, eArtista* listaArtita, int indiceArtista)
{
	int retorno;

	retorno = -1;
	if(listaAlbum != NULL && indiceAlbum>=0 && listaArtita != NULL && indiceArtista>=0)
	{
		retorno = 0;

		//printf("DEBUG*** print un pasajero\n");
		printf("%d %9s %15d/%d/%d %15.2f %18s\n",  listaAlbum[indiceAlbum].idAlbum,
												listaAlbum[indiceAlbum].titulo,
												listaAlbum[indiceAlbum].fecha.day,
												listaAlbum[indiceAlbum].fecha.month,
												listaAlbum[indiceAlbum].fecha.year,
												listaAlbum[indiceAlbum].importe,
												listaArtita[indiceArtista].nombre);
	}
	return retorno;
}

/**
 *
 * \brief Imprime el encabezado de la planilla
 * \return void
 *
 */
void alb_printEncabezado(void)
{
	printf("\nTIPO ALBUM\tID\tTITULO\t\t\tFECHA\t\tPRECIO\t\tNOMBRE DE ARTISTA\n");
}

/**
 * \brief Recibe el array de entidad Album y analiza el campo .id de cada elemento hasta encontrar coincidencia con el valor recibido por parametro
 * \param listaAlbum *eAlbum recibe la direccion de memoria del array sobre el cual va a trabajar
 * \param sizeListaAlbum int Recibe tamaño del array
 * \param idConsulta int recibe por valor el dato contra el cual compara
 * \return retorna int -1 si hubo un error en los parametros recibidos
 * 					   -2 si no pudo recorrer el array
 * 					   >=0 si la operacion se realizo correctamente (retorna el indice donde encontro la coincidencia)
 *
 */
int alb_findPorCodigo(eAlbum* listaAlbum, int sizeListaAlbum, int idConsulta)
{
	int retorno;
	int i;
	retorno = -1;
	if(listaAlbum!= NULL && sizeListaAlbum >0 && idConsulta> ID_INICIAL)
	{
		retorno = -2;
		for (i=0; i<sizeListaAlbum; i++)
		{
			if(validacionesInt_sonIdenticos(listaAlbum[i].idAlbum, idConsulta))
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}


//______________________________________________________________-
/*1) alta de algunos albumes*/

/**
 * \brief interactua con el usuario para solicitar el titulo del album
 * \param titulo char* Recibe la direccion de memoria del array donde se guardara el dato ingresado
 * \param sizeTitulo int Recibe por valor el tamaño del array
 * \return retorna -1 si hubo un error en los parametros recibidos
 * 		   		   -2 si hubo un error en la interaccion con el usuario
 * 		  			0 si la operacion se realizo correctamente
 *
 */
int alb_getTitulo(char* titulo, int sizeTitulo)
{
	int retorno;
	char auxNombre[sizeTitulo];

	retorno =-1;
	if(titulo!= NULL && sizeTitulo >0)
	{
		do{
			utn_ingresarAlfabetica(auxNombre, sizeTitulo, "Titulo del Album: ", "Ingrese un dato valido", REINTENTOS);
			strncpy(titulo, auxNombre, sizeTitulo);
			retorno =0;
			if(validaciones_esNombre(titulo, sizeTitulo))
			{
				retorno = -2;
				printf("hola");
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
int alb_getImporte(float* importe)
{
	int retorno;
	float auxImporte;

	retorno = -1;
	do{
		utn_GetNumeroFloat(&auxImporte, "\ningrese el precio: $", "ingrese un dato valido ($700 a $5000)", MIN_PRECIO, MAX_PRECIO, REINTENTOS);
		*importe = auxImporte;
		retorno=0;
	}while(retorno);
	return retorno;
}

/**
 * \brief interactua con el usuario para solicitar la fecha del album
 * \param fechaAlbum eFecha* Recibe la direccion de memoria del array donde se guardara el dato ingresado
 * \return retorna -1 si hubo un error en los parametros recibidos
 * 		  			0 si la operacion se realizo correctamente
 *
 */
int alb_getFecha(eFecha* fechaAlbum)
{
	int retorno;
	//eFecha fecha;
	retorno = -1;
	printf("\nFecha de emision: \n");
	do{
		*fechaAlbum= fecha_newFecha();
		retorno =0;
	}while(retorno);
	return retorno;
}

/**
 * \brief interactua con el usuario para solicitar la fecha del album
 * \param fechaAlbum eFecha* Recibe la direccion de memoria del array donde se guardara el dato ingresado
 * \return retorna -1 si hubo un error en los parametros recibidos
 * 				   -2 si no se pudo solicitar id de artista
 * 		  			0 si la operacion se realizo correctamente
 *
 */
int alb_getArtista(eArtista* listaArtistas, int sizeListaArtista, int* idArtista)
{
	int retorno;
	int auxArtista;
	retorno=-1;
	if(listaArtistas!= NULL && sizeListaArtista>0 && idArtista!= NULL)
	{
		retorno=-2;
		do{
			auxArtista = art_pedirArtista(listaArtistas, sizeListaArtista);
			*idArtista = auxArtista;
			if(auxArtista>0)
			{
				retorno =0;
			}
		}while(retorno);

	}
	return retorno;
}

int alb_getTipoArtista(int* tipoArtista)
{
	int retorno;
	int auxTipoArtista;
	retorno=-1;
	if(tipoArtista!= NULL)
	{
		retorno=-2;
		do{
			printf("ingrese tipo de artista: 1- solista / 2-banda\n");
			utn_GetNumeroInt(&auxTipoArtista, "indique: ", "indique un dato valido", 1, 2, REINTENTOS);
			*tipoArtista = auxTipoArtista;
			retorno =0;
		}while(retorno);
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
* \brief add in a existing list of Album the values received as parameters
* 	     in the first empty position(with alb_cargarUnNuevoAlbumAlArray)
* 	     with the last id wich it has finded
* \param listaAlbum eAlbum* receives the list where will write the struct
* \param sizeListaAlbum int to indicate array size

* \return int Return (-1) if Error [Invalid length or NULL pointer or withoufree space]
*					  (0) if Ok
*
*/
int alb_getNuevoAlbum(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtista, int sizeListaArtista, eTipoAlbum* listaTipoAlbum, int sizeListTipoAlbum/*, int ultimoId*/)
{
	int retorno;
	int idArtistaAlbum;
	eFecha unaFechaAlbum;
	float importeAlbum;
	char tituloAlbum[STR_SIZE];
	int tipoArtista;
	int tipoAlbum;
	int printLista;

	retorno = -1;
	if(listaAlbum!= NULL && sizeListaAlbum >0 && listaArtista != NULL && sizeListaArtista >0)
	{
		retorno = -2;
		alb_getTitulo(tituloAlbum, STR_SIZE);
		alb_getFecha(&unaFechaAlbum);
		alb_getImporte(&importeAlbum);
		alb_getArtista(listaArtista, sizeListaArtista, &idArtistaAlbum);
		alb_getTipoArtista(&tipoArtista);
		alb_getTipoAlbum(listaTipoAlbum, sizeListTipoAlbum, &tipoAlbum);

		if(!alb_cargarUnNuevoAlbumAlArray(tituloAlbum,STR_SIZE, &unaFechaAlbum, importeAlbum, idArtistaAlbum, listaAlbum, sizeListaAlbum, tipoArtista, tipoAlbum))
		{
			retorno=0;
			printf("se ha cargado con éxito");
			printLista = continuar("desea imprimir la lista? Y/N");
			if(printLista)
			{
				alb_printLista(listaAlbum, sizeListaAlbum, listaArtista, sizeListaArtista, listaTipoAlbum, sizeListTipoAlbum);
			}
		}
	}
	return retorno;
}

int alb_cargarUnNuevoAlbumAlArray(char* tituloAlbum, int sizeTituloAlbum, eFecha* fechaAlbum, float importeAlbum, int idArtistaAlbum, eAlbum* listaAlbum, int sizeListaAlbum, int tipoArtista, int tipoAlbum)
{
	int retorno;
	//int qtyAlbumCargados;
	int ultimoId;
	int indexCarga;

	retorno = -1;
	if(tituloAlbum!= NULL && sizeTituloAlbum >0 && listaAlbum!= NULL && sizeListaAlbum >0 )
	{
		retorno = -2;
		alb_indicarUltimoId(listaAlbum, sizeListaAlbum, &ultimoId);
		ultimoId=ultimoId+1;

		indexCarga= alb_findPrimerEspacioLibreEnLista(listaAlbum, sizeTituloAlbum);
		//printf("\nDEBUG*****\nultimo id: %d\n index carga: %d\n", ultimoId, indexCarga);
		//printf("%s - %d/%d/%d - %2.f - idArt:%d\n\n", tituloAlbum, fechaAlbum->day, fechaAlbum->month, fechaAlbum->year,
				//								  importeAlbum, idArtistaAlbum);
		if(indexCarga>= 0)
		{
			listaAlbum[indexCarga].idAlbum=ultimoId;
			listaAlbum[indexCarga].importe=importeAlbum;
			listaAlbum[indexCarga].fecha=*fechaAlbum;
			listaAlbum[indexCarga].isEmpty=NOT_EMPTY;
			listaAlbum[indexCarga].artistaFk=idArtistaAlbum;
			strncpy(listaAlbum[indexCarga].titulo,tituloAlbum, STR_SIZE);
			listaAlbum[indexCarga].tipoArtistaFk = tipoArtista;
			listaAlbum[indexCarga].tipoAlbumFk=tipoAlbum;
			retorno=0;
		}

	}
	return retorno;
}

int alb_solicitarCodigo(int* idSolicitado, eAlbum* listaAlbum, int sizeListaAlbum)
{
	int retorno;
	int auxId;
	int ultimoId;

	retorno = -1;
	if(idSolicitado != NULL)
	{
		retorno =0;
		utn_GetNumeroInt(&auxId, "Ingrese el Codigo del Album: ", "ingrese un dato valido", ID_INICIAL, ID_MAXIMO, REINTENTOS);
		alb_indicarUltimoId(listaAlbum, sizeListaAlbum, &ultimoId);
		if(auxId <= ultimoId)
		{
			*idSolicitado= auxId;
		}
		else
		{
			printf("ingrese el codigo de un album existente");
		}
	}
	return retorno;
}


int alb_cargaForzadaDeDatos(eAlbum* listaAlbum, int sizeListaAlbum)
{
	int retorno;
	int i;

	eAlbum cargaAlbum[] = {
			{101, "Fantaisie-Impromptu",{1,1,1851},2500,1,1,1,1, NOT_EMPTY},
			{102, "El disco de tu corazon", {1,1,2017}, 2050, 4,1,2,2,NOT_EMPTY},
			{103, "Sin restricciones",{1,5,2004},2000,4,1,1,3, NOT_EMPTY},
			{104, "El templo del pop",{1,8,2014},2500,4,1,2,1, NOT_EMPTY},
			{105, "Have a Nice day",{1,10,2014},1900,5,1,1,2,NOT_EMPTY},
			{106, "Master of puppets",{1,10,1986}, 1800,6,1,2,3,NOT_EMPTY},
			{107, "Made in Heaven",{1,11,1991},2100, 8,1,1,1,NOT_EMPTY},
			{108, "a Kind of magic",{12,11,1986}, 2150, 6,1,2,2,NOT_EMPTY}
			};

	retorno = -1;
	if(listaAlbum!= NULL && sizeListaAlbum>0)
	{
		retorno = -2;
		for(i=0; i<sizeListaAlbum; i++)
		{
			listaAlbum[i]= cargaAlbum[i];
		}
		retorno = 0;
	}

	return retorno;
}

int alb_setTitulo(eAlbum* listaAlbum, int indexCambio)
{
	int retorno;
	char nuevoTitulo[STR_SIZE];

	retorno = -1;
	if(listaAlbum != NULL && indexCambio>=0)
	{
		retorno =-2;
		if(!alb_getTitulo(nuevoTitulo, STR_SIZE))
		{
			strncpy(listaAlbum[indexCambio].titulo, nuevoTitulo, STR_SIZE);
		}
	}
	return retorno;
}

int alb_setFecha(eAlbum* listaAlbum, int indexCambio)
{
	int retorno;
	eFecha nuevaFecha;

	retorno = -1;
	if(listaAlbum != NULL && indexCambio>=0)
	{
		retorno =-2;
		if(!alb_getFecha(&nuevaFecha))
		{
			listaAlbum[indexCambio].fecha = nuevaFecha;
		}
	}
	return retorno;
}

int alb_setImporte(eAlbum* listaAlbum, int indexCambio)
{
	int retorno;
	float nuevoImporte;

	retorno = -1;
	if(listaAlbum != NULL && indexCambio>=0)
	{
		retorno =-2;
		if(!alb_getImporte(&nuevoImporte))
		{
			listaAlbum[indexCambio].importe = nuevoImporte;
		}
	}
	return retorno;
}

int alb_removerAlbum(eAlbum* listaAlbum, int indexCambio)
{
	int retorno;
	retorno = -1;
	if(listaAlbum!= NULL && indexCambio>0)
	{
		listaAlbum[indexCambio].isEmpty = IS_DELETED;
		retorno=0;
	}
	return retorno;
}

//________________________________________________________________________


/**
* \brief Recorre la lista recibida para acumular todos los importes guardados
* \param listaAlbum eAlbum* recibe la lista que analiza
* \param sizeListaAlbum int indica el tamaño de la lista
* \param totalImporte float* recibe una direccion de memoria donde guardar el total encontrado
* \return int Return (-1) si hubo un error en los parametros ingresados
*					  (0) si no hay importes
*					  >0 si encontro importes (retorna la cantidad encontrada)
*
*/
int informes_totalImportes(eAlbum* listaAlbum, int sizeListAlbum, float* totalImporte)
{
	int i;
	int contador;

	contador =-1;

	if(listaAlbum!= NULL && sizeListAlbum)
	{
		contador=0;
		for(i=0; i<sizeListAlbum; i++)
		{
			if(listaAlbum[i].isEmpty == NOT_EMPTY)
			{
				*totalImporte= *totalImporte+listaAlbum[i].importe;
				contador++;
			}
		}
	}
	return contador;
}

int informes_informarTotalyPromedioDeImportes(eAlbum* listaAlbum, int sizeListAlbum)
{
	int retorno;
	float totalImporte;
	int cantidadImportes;
	float promedio;
	int cantidadQueSuperaPromedio;

	retorno =-1;
	if(listaAlbum!= NULL && sizeListAlbum)
	{
		retorno=-2;
		cantidadImportes = informes_totalImportes(listaAlbum, sizeListAlbum, &totalImporte);
		if(cantidadImportes>0)
		{
			promedio= tp_calcularPromedio(totalImporte, cantidadImportes);
			cantidadQueSuperaPromedio = informes_cacularCantidadQueSuperaPromedio(listaAlbum, sizeListAlbum, promedio);
			printf("Total de importes: %.2f\nPromedio de importes: %.2f\nCantidad que supera el promedio: %d",totalImporte, promedio, cantidadQueSuperaPromedio);
			retorno=0;
		}
	}
	return retorno;
}

int informes_cacularCantidadQueSuperaPromedio(eAlbum* listaAlbum, int sizeListAlbum, float promedio)
{
	int i;
	int contador;

	contador=-1;
	if(listaAlbum!= NULL && sizeListAlbum)
	{
		contador=0;
		for(i=0; i<sizeListAlbum; i++)
		{
			if(listaAlbum[i].importe>promedio)
			{
				contador++;
			}
		}
	}
	return contador;
}

int informes_informarCantAlbumPrevioAlDosMil(eAlbum* listaAlbum, int sizeListAlbum)
{
	int contador;
	int i;

	contador = -1;
	if(listaAlbum!= NULL && sizeListAlbum)
	{
		contador=0;
		for (i=0; i<sizeListAlbum; i++)
		{
			if(listaAlbum[i].fecha.year<2000)
			{
				contador++;
			}
		}
		printf("Hay %d albumes anteriores al 1/1/2000\n\n", contador);
	}
	return contador;
}

//______________________________________________________________________

int alb_printListaAlbumes(eAlbum* listaAlbum, int sizeListAlbum)
{
	int retorno;
	int i;

	retorno = -1;
	if(listaAlbum!= NULL && sizeListAlbum>0)
	{
		retorno = 0;
		alb_printEncabezadoCodYTit();
		for(i=0; i<sizeListAlbum; i++)
		{
			if(listaAlbum[i].isEmpty==NOT_EMPTY)
			{

				//printf("DEBUG** print pasajeros\n");
				alb_printCodigoYTItulo(listaAlbum, i);
			}
		}
	}
	return retorno;
}

int alb_printCodigoYTItulo(eAlbum* listaAlbum, int indice)
{
	int retorno;
	retorno = -1;

	if(listaAlbum!= NULL && indice >=0)
	{
		retorno = 0;

		//printf("DEBUG*** print un pasajero\n");
		printf("%5d %18s\n",
				listaAlbum[indice].idAlbum,
				listaAlbum[indice].titulo);
	}

	return retorno;
}

void alb_printEncabezadoCodYTit(void)
{
	printf("\nCODIGO\t\tALBUM\n");
}


int listar_printAlbumPrevioAlDosMil(eAlbum* listaAlbum, int sizeListAlbum)
{
	int contador;
	int i;

	contador = -1;
	if(listaAlbum!= NULL && sizeListAlbum)
	{
		contador=0;
		for (i=0; i<sizeListAlbum; i++)
		{
			if(listaAlbum[i].isEmpty==NOT_EMPTY && listaAlbum[i].fecha.year<2000)
			{
				contador++;
				alb_printPosicion(listaAlbum, i);
				printf("\n");
			}
		}
	}
	return contador;
}
int listar_calcularTotalyPromedioDeImportes(eAlbum* listaAlbum, int sizeListAlbum)
{
	int retorno;
	float totalImporte;
	int cantidadImportes;
	float promedio;

	retorno =-1;
	if(listaAlbum!= NULL && sizeListAlbum)
	{
		retorno=-2;
		cantidadImportes = informes_totalImportes(listaAlbum, sizeListAlbum, &totalImporte);
		if(cantidadImportes>0)
		{
			promedio= tp_calcularPromedio(totalImporte, cantidadImportes);
			//printf("DEBUG**** %.2f", promedio);
			listar_printAlbumQueSuperaPromedio(listaAlbum, sizeListAlbum, promedio);
			retorno=0;
		}
	}
	return retorno;
}

int listar_printAlbumQueSuperaPromedio(eAlbum* listaAlbum, int sizeListAlbum, float promedio)
{
	int i;
	int retorno;

	retorno=-1;
	if(listaAlbum!= NULL && sizeListAlbum)
	{
		retorno=0;
		printf("Albumes que superan el precio promedio de %.2f\n", promedio);
		for(i=0; i<sizeListAlbum; i++)
		{
			if(listaAlbum[i].isEmpty==NOT_EMPTY  && listaAlbum[i].importe>promedio)
			{
				alb_printPosicion(listaAlbum, i);
				printf("\n");
			}
		}
	}
	return retorno;
}

float listar_findPrecioMasCaro(eAlbum* listaAlbum, int sizeListaAlbum)
{
	float mayorPrecio;
	int i;
	float retorno;

	retorno=-1;
	if(listaAlbum!= NULL && sizeListaAlbum >0)
	{
		retorno=0;
		for (i=0; i<sizeListaAlbum; i++)
		{
			if(i==0)
			{
				mayorPrecio = listaAlbum[i].importe;
			}
			if(listaAlbum[i].isEmpty== NOT_EMPTY && listaAlbum[i].idAlbum>mayorPrecio)
			{
				mayorPrecio=listaAlbum[i].importe;
			}
		}
		retorno=mayorPrecio;
	}
	return retorno;
}

int listar_printAlbumesMasCaros(eAlbum* listaAlbum, int sizeListaAlbum)
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
				alb_printPosicion(listaAlbum, i);
				printf("\n");
			}
		}
	}
	return retorno;
}

int listar_printAlbumPorArtista(eArtista* listaArtistas, int sizeListaArtista, eAlbum* listaAlbum, int sizeListaAlbum)
{
	int retorno;
	int i;
	int j;
	int bandera;


	retorno=-1;
	if( listaArtistas!= NULL && sizeListaArtista>0 && listaAlbum != NULL && sizeListaAlbum>0)
	{
		retorno=0;
		alb_printEncabezado();
		for(i=0; i<sizeListaArtista; i++)
		{
			arrayChar_convertirStringMayuscula(listaArtistas[i].nombre, strlen(listaArtistas[i].nombre));
			printf("\n\n%s\n", listaArtistas[i].nombre);
			bandera=0;
			for(j=0; j<sizeListaAlbum; j++)
			{
				if(listaAlbum[j].artistaFk == listaArtistas[i].idArtista)
				{
					//printf("\nDEBUG*** %d-%d\n",listaAlbum[j].artistaFk, listaArtistas[i].idArtista);
					/*if(j==0)
					{
						printf("%s\n", listaArtistas[i].nombre);
					}*/
					//printf("\n");
					alb_printPosicion(listaAlbum, j);
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
int listar_printYear(eAlbum* listaAlbum, int sizeListaAlbum)
{
	int i;
	int contador;

	contador = -1;
	if(listaAlbum!= NULL && sizeListaAlbum>0)
	{
		contador=0;
		printf("Lista de años cargados: \n");
		for (i=0; i<sizeListaAlbum; i++)
		{
			if(listaAlbum[i].isEmpty == NOT_EMPTY)
			{
				printf("- %d\n", listaAlbum[i].fecha.year);
				contador++;
			}
		}
	}
	return contador;
}


int listar_printAlbumeSegunAnio(eAlbum* listaAlbum, int sizeListaAlbum)
{
	int contador;
	int i;
	int yearSelected;

	contador = -1;
	if(listaAlbum!= NULL && sizeListaAlbum)
	{
		listar_printYear(listaAlbum, sizeListaAlbum);
		utn_GetNumeroInt(&yearSelected, "indique el anio que desea buscar", "ingrese un valor valido", MIN_YEAR, MAX_YEAR, REINTENTOS);

		contador=0;
		for (i=0; i<sizeListaAlbum; i++)
		{
			if(listaAlbum[i].fecha.year== yearSelected)
			{
				contador++;
				alb_printPosicion(listaAlbum, i);
				printf("\n");
			}
		}
	}
	return contador;
}
//*************************************************************

eFecha fecha_newFecha(void)
{
	eFecha unaFecha;
	/*int newday;
	int newmonth;
	int newyear;*/
	utn_GetNumeroInt(&unaFecha.day, "ingrese dia: ", "ingrese un dato valido", 1, MAX_DAY, REINTENTOS);
	utn_GetNumeroInt(&unaFecha.month, "ingrese mes: ", "ingrese un dato valido", 1, MAX_MONTH, REINTENTOS);
	utn_GetNumeroInt(&unaFecha.year, "ingrese anio: ", "ingrese un dato valido", MIN_YEAR, MAX_YEAR, REINTENTOS);

	/*printf("ingrese dia: ");
	scanf("%d", &unaFecha.day);
	printf("dia: %d\n",unaFecha.day);
	printf("ingrese mes: ");
	scanf("%d", &unaFecha.month);
	printf("month: %d\n",unaFecha.month);
	printf("ingrese anio: ");
	scanf("%d", &unaFecha.year);*/
	//printf("una fecha: %d-%d-%d\n",unaFecha.year, unaFecha.day, unaFecha.month);


	return unaFecha;
}

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
		printf("%5d %22s\n",
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

//____________________________________________--
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

int genero_printListaGenero(eGenero* listaGeneros, int sizeGenero)
{
	int retorno;
	int i;

	retorno = -1;
	if(listaGeneros!= NULL && sizeGenero>0)
	{
		retorno = 0;
		genero_printEncabezado();
		for(i=0; i<sizeGenero; i++)
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

void genero_printEncabezado(void)
{
	printf("\nCODIGO\t\tTIPO\n");
}
//______________________________________________________________
int type_cargaForzadaDeDatos(eTipoArtista* listaTypes, int sizeTypes)
{
	int retorno;
	int i;
	eTipoArtista cargaTipos[] = {
								{1, "Solista", NOT_EMPTY},
								{2, "Banda", NOT_EMPTY},
							};
	retorno = -1;
	if(listaTypes!= NULL && sizeTypes>0)
	{
		retorno = -2;
		for(i=0; i<sizeTypes; i++)
		{
			listaTypes[i]= cargaTipos[i];
		}
		retorno = 0;
	}
	return retorno;
}

int type_printListaType(eTipoArtista* listaTypes, int sizeTypes)
{
	int retorno;
	int i;

	retorno = -1;
	if(listaTypes!= NULL && sizeTypes>0)
	{
		retorno = 0;
		type_printEncabezado();
		for(i=0; i<sizeTypes; i++)
		{
			if( !validacionesInt_sonIdenticos(listaTypes[i].isEmpty,IS_EMPTY))
			{

				//printf("DEBUG** print pasajeros\n");
				type_printPosicion(listaTypes, i);
			}
		}
	}
	return retorno;
}

int type_printPosicion(eTipoArtista* listaTypes, int indice)
{
	int retorno;
	retorno = -1;

	if(listaTypes!= NULL && indice >=0)
	{
		retorno = 0;

		//printf("DEBUG*** print un pasajero\n");
		printf("%5d %18s\n",
				listaTypes[indice].idTipoArtista,
				listaTypes[indice].descripcion);
	}

	return retorno;
}

void type_printEncabezado(void)
{
	printf("\nCODIGO\t\tTIPO ARTISTA\n");
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
int listar_sortAlbum(eAlbum* listaAlbum, int sizeListAlbu, eArtista* listaArtista, int sizeListArtista, eTipoAlbum* listaTipoAlbum, int sizeListaTipoAlbum)
{
	int retorno;
	int criterio;
	retorno = -1;
	if(listaAlbum != NULL && sizeListAlbu >0)
	{
		retorno=0;
		printf("Indique el criterio de orden: \n1-Descendente segun importe\n2-Ascendente segun titulo\n");
		utn_GetNumeroInt(&criterio, "ingrese el criterio: ", "ingrese un dato valido", 1, 2, REINTENTOS);
		listar_sortAlbumSegunCriterio(listaAlbum, sizeListAlbu, criterio);
		alb_printLista(listaAlbum, sizeListAlbu, listaArtista, sizeListArtista, listaTipoAlbum, sizeListaTipoAlbum);
	}
	return retorno;
}

int listar_sortAlbumSegunCriterio(eAlbum* listaAlbum, int sizeListAlbu, int criterio)
{
    printf("criterio: %d", criterio);
	//ordenar albumes por criterio -importe (descendente) -Titulo(ascendente)
	int retorno;
	int i;
	int strCompare;
	int flagSwap;
	int nuevoLimite;
	retorno =-1;
	if(listaAlbum!= NULL && sizeListAlbu > 0)
	{
		retorno=0;
		nuevoLimite= sizeListAlbu-1;
		switch (criterio)
		{
			case 1:
					do
					{
						flagSwap=0;
						for (i=0; i<nuevoLimite; i++)
						{
							if( listaAlbum[i].isEmpty == NOT_EMPTY
								&& listaAlbum[i+1].isEmpty == NOT_EMPTY
								&& listaAlbum[i].importe<listaAlbum[i+1].importe)
							{
								alb_swap(listaAlbum, i, i+1);
								flagSwap = 1;
							}
						}
						nuevoLimite--;
					}while(flagSwap);
				break;
			case 2:
					do
					{
						flagSwap=0;
						for (i=0; i<nuevoLimite; i++)
						{
							if(listaAlbum[i].isEmpty == NOT_EMPTY && listaAlbum[i+1].isEmpty == NOT_EMPTY )
							{
								strCompare=strncmp(listaAlbum[i].titulo, listaAlbum[i+1].titulo, STR_SIZE);
								arrayChar_convertirASustantivoPropio(listaAlbum[i].titulo, strlen(listaAlbum[i].titulo));
								arrayChar_convertirASustantivoPropio(listaAlbum[i+1].titulo, strlen(listaAlbum[i+1].titulo));
							}
							if(strCompare>0)
							{
								alb_swap(listaAlbum, i, i+1);
								flagSwap = 1;
							}
						}
						nuevoLimite--;
					}while(flagSwap);
				break;
		}
	}
	return retorno;
}

//**********************************************************
//PP LABO - PARTE 2
int tipoAlbum_cargaForzadaDeDatos(eTipoAlbum* listaTipoALbum, int sizelistaTipoALbum)
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
	if(listaTipoALbum!= NULL && sizelistaTipoALbum>0)
	{
		retorno = -2;
		for(i=0; i<sizelistaTipoALbum; i++)
		{
			listaTipoALbum[i]= cargaTipoAlbum[i];
		}
		retorno = 0;
	}
	return retorno;
}

int tipoAlbum_printListaTipoAlbum(eTipoAlbum* listaTipoALbum, int sizelistaTipoALbum)
{
	int retorno;
	int i;

	retorno = -1;
	if(listaTipoALbum!= NULL && sizelistaTipoALbum>0)
	{
		retorno = 0;
		tipoAlbum_printEncabezado();
		for(i=0; i<sizelistaTipoALbum; i++)
		{
			if( !validacionesInt_sonIdenticos(listaTipoALbum[i].isEmpty,IS_EMPTY))
			{

				//printf("DEBUG** print pasajeros\n");
				tipoAlbum_printPosicion(listaTipoALbum, i);
			}
		}
	}
	return retorno;
}

int tipoAlbum_printPosicion(eTipoAlbum* listaTipoALbum, int indice)
{
	int retorno;
	retorno = -1;

	if(listaTipoALbum!= NULL && indice >=0)
	{
		retorno = 0;

		//printf("DEBUG*** print un pasajero\n");
		printf("%5d %18s\n",
				listaTipoALbum[indice].idTipoAlbum,
				listaTipoALbum[indice].descripcion);
	}

	return retorno;
}

void tipoAlbum_printEncabezado(void)
{
	printf("\nCODIGO\t\tTIPO ALBUM\n");
}

/**
* \brief Recibe un array de entidad tipoAlbun para imprimirlo y luego solicita un id entre los mostrados
* \param listaTipoALbum eTipoAlbum* recibe la direccion de memoria del array a analizar
* \param sizeListaArtista int recibe por valor el tamaño del array
* \return int Return (-1) si hubo un error en los parametros recibidos
* 					 (-2) si no encontro ningun index libre
* 		     		 (>=0) si opero correctamente - el valor del indice que se encontro
*
*/
int tipoAlbum_pedirTipoAlbum(eTipoAlbum* listaTipoALbum, int sizelistaTipoALbum)
{
	int unId;
	int idTipoAlbum;

	unId =-1;
	if(listaTipoALbum != NULL && sizelistaTipoALbum>0)
	{
		unId =-2;
		if(!tipoAlbum_printListaTipoAlbum(listaTipoALbum, sizelistaTipoALbum))
		{
			utn_GetNumeroInt(&unId, "ingrese el codigo del Tipo de Album: ", "ingrese un codigo valido", 1, QTY_TIPO_ALBUM, REINTENTOS);
			idTipoAlbum= unId;
				//printf("DEBUG**** artista: %d", unId);
		}
	}
	return idTipoAlbum;
}

int alb_getTipoAlbum(eTipoAlbum* listaTipoAlbum, int sizelistaTipoALbum, int* idTipoAlbum)
{
	int retorno;
	int auxIdTipoAlbum;
	retorno=-1;
	if(listaTipoAlbum!= NULL && sizelistaTipoALbum>0 && idTipoAlbum!= NULL)
	{
		retorno=-2;
		auxIdTipoAlbum = tipoAlbum_pedirTipoAlbum(listaTipoAlbum, sizelistaTipoALbum);
		if(auxIdTipoAlbum>0)
		{
			*idTipoAlbum = auxIdTipoAlbum;
			//printf("un tipoAlbum: %d", *idTipoArtista);
			retorno =0;
		}
	}
	return retorno;
}

int alb_setTipoAlbum(eAlbum* listaAlbum, int indexCambio, eTipoAlbum* listaTipoAlbum, int sizelistaTipoALbum)
{
	int retorno;
	int nuevoTipoAlbum;

	retorno = -1;
	if(listaAlbum != NULL && indexCambio>=0)
	{
		retorno =-2;
		if(!alb_getTipoAlbum(listaTipoAlbum, sizelistaTipoALbum, &nuevoTipoAlbum))
		{
			listaAlbum[indexCambio].tipoAlbumFk = nuevoTipoAlbum;
		}
	}
	return retorno;
}


/**
 * \brief Recibe el array de entidad Album, el array de Artista e imprime el contenido indicado segun la posicion recibida por parametros
 * \param listaAlbum *eAlbum recibe la direccion de memoria del array sobre el cual va a trabajar
 * \param indiceAlbum int Recibe por valor la posicion del array del cual imprimira los valores de sus campos
 * \param listaArtita *eArtista recibe la direccion de memoria del array sobre el cual va a trabajar
 * \param indiceArtista int Recibe por valor la posicion del array Artista del cual imprimira el campo indicado
 * \return retorna int -1 si hubo un error en los parametros recibidos
 * 			0 si la operacion se realizo correctamente
 *
 */
int alb_printPosicionConArtistaYTipoAlbum(eAlbum* listaAlbum, int indiceAlbum, eArtista* listaArtita, int indiceArtista, eTipoAlbum* listaTipoAlbum, int indiceTipoAlbum)
{
	int retorno;

	retorno = -1;
	if(listaAlbum != NULL && indiceAlbum>=0 && listaArtita != NULL && indiceArtista>=0)
	{
		retorno = 0;

		//printf("DEBUG*** print un pasajero\n");
		printf("%d %10s %9s %15d/%d/%d %15.2f %18s\n",
												listaAlbum[indiceAlbum].idAlbum,
												listaTipoAlbum[indiceTipoAlbum].descripcion,
												listaAlbum[indiceAlbum].titulo,
												listaAlbum[indiceAlbum].fecha.day,
												listaAlbum[indiceAlbum].fecha.month,
												listaAlbum[indiceAlbum].fecha.year,
												listaAlbum[indiceAlbum].importe,
												listaArtita[indiceArtista].nombre);
	}
	return retorno;
}

int tipoAlbum_printTipoAlbumSegunId(eTipoAlbum* listaTipoAlbum, int sizelistaTipoAlbum, int idTipoAlbum)
{
	int retorno;
	int i;
	retorno = -1;
	if(listaTipoAlbum != NULL && sizelistaTipoAlbum>0)
	{
		retorno =0;
		for (i=0; i<sizelistaTipoAlbum ; i++)
		{
			if(idTipoAlbum == listaTipoAlbum[i].idTipoAlbum)
			{
				printf("%s", listaTipoAlbum[i].descripcion);
				break;
			}
		}
	}
	return retorno;
}

/*int tipoAlbum_listarAlbumDistintoVinilo(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtita, int sizeListaArtita, eTipoAlbum* listaTipoAlbum, int sizeTipoAlbum)
{
	int retorno;
	retorno =-1;
	if(listaAlbum != NULL)
	{
		retorno =0;
	}
	return retorno;
}*/

int tipoAlbum_listarAlbumDistintoVinilo(eTipoAlbum* listaTipoAlbum, int sizeTipoAlbum, eAlbum* listaAlbum, int sizeListaAlbum)
{
	int retorno;
	int i;

	retorno =-1;
	if(listaTipoAlbum != NULL && sizeTipoAlbum>0)
	{
		retorno =0;
		printf("Todos los discos que son Cinta o Cd\n");
		for(i=0; i<sizeTipoAlbum; i++)
		{
			if(listaTipoAlbum[i].idTipoAlbum != VINILO)
			{
				alb_printPosicion(listaAlbum, i);
				printf("\n");
			}
		}
	}
	return retorno;
}


int tipoAlbum_printViniloSegunArtista(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtistas, int sizeListaArtistas)
{
	int retorno;
	int i;
	int artistaSelected;
	int bandera;

	retorno = -1;
	if(listaAlbum!= NULL && sizeListaAlbum)
	{
		bandera = 0;
		art_printListaArtista(listaArtistas, sizeListaArtistas);
		utn_GetNumeroInt(&artistaSelected, "indique el codigo de artista que desea buscar", "ingrese un valor valido", 1, QTY_ARTIST, REINTENTOS);

		retorno=0;
		for (i=0; i<sizeListaAlbum; i++)
		{
			if( listaAlbum[i].isEmpty== NOT_EMPTY
				&& listaAlbum[i].artistaFk== artistaSelected)
			{
				if(listaAlbum[i].tipoAlbumFk==VINILO)
				{
					alb_printPosicion(listaAlbum, i);
					printf("\n");
					bandera = 1;
				}
				else
				{
					if(!bandera)
					{
						printf("no tiene album vinilo");
					}
				}
			}
		}
	}
	return retorno;
}

/*
int alb_indicarUltimoId(eAlbum* listaAlbum, int sizeListaAlbum, int* ultimoId);
int alb_contadorAlbumesCargados(eAlbum* listaAlbum, int sizeListaAlbum, int* cantidadCargados);
*/


/* aca van todas las funciones que necesito para interactuar con el usuario al cargar un albom*/
/*int alb_pedirTitulo(char* titulo, int sizeTitulo);
//int fecha??
float alb_pedirImporte(float* importe);
int alb_pedirArtista(int* artista);*/ //este va a invocar a la estructura eArtista porque precisa mostrar su contenido para dar opciones al usuario (que ingresa una opcion por numero)

/*2) Modificar titulo fecha importe
int alb_cambiarTitulo(char* titulo, int sizeTitulo);
// cambiar fecha??
float alb_cambiarImporte(float* importe);

//__________________________________________________________________-

int alb_pedirCodigo(int ultimoId); //2 y 3
int alb_findPorCodigo(eAlbum* listaAlbum, int sizeListaAlbum, int idConsulta); //2 y 3*/

/*3) baja segun codigo
int alb_removeSegunId(eAlbum* listaAlbum, int idConsulta); //3 realizar baja logica

//__________________________________________________________________-
//funciones de auxilio

int alb_swap(eAlbum* listaAlbum, int indice1, int indece2);// 5- E
int alb_sortByImporte(eAlbum* listaAlbum, int sizeListaAlbum);
int alb_sortByTitulo(eAlbum* listaAlbum, int sizeListaAlbum);*/

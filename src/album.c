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
			alb_initPosicion(listaAlbum, i, IS_EMPTY);
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
int alb_printLista(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtita, int sizeListaArtista)
{
	int retorno;
	int i;
	//int j;

	retorno = -1;
	if(listaAlbum != NULL && sizeListaAlbum>0 && listaArtita != NULL && sizeListaArtista>0)
	{
		retorno = 0;
		alb_printEncabezado();
		for(i=0; i<sizeListaAlbum; i++)
		{
			if(listaAlbum[i].isEmpty==NOT_EMPTY)
			{
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
		printf("%d %20s %8d/%d/%d %15.2f %15d",   listaAlbum[indiceAlbum].idAlbum,
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
	printf("\nID\tTITULO\t\t\tFECHA\t\tPRECIO\t\tNOMBRE DE ARTISTA\n");
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
		retorno = -2;
		if( !utn_ingresarAlfabetica(auxNombre, sizeTitulo, "Titulo del Album: ", "Ingrese un dato valido", REINTENTOS))
		{
			strncpy(titulo, auxNombre, sizeTitulo);
			retorno = 0;
		}
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
	if( !utn_GetNumeroFloat(&auxImporte, "\ningrese el precio: ", "ingrese un dato valido", MIN_PRECIO, MAX_PRECIO, REINTENTOS))
	{
		*importe = auxImporte;
		retorno=0;
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
int alb_getFecha(eFecha* fechaAlbum)
{
	int retorno;
	//eFecha fecha;
	retorno = -1;
	printf("\nFecha de emision: \n");
	*fechaAlbum= fecha_newFecha();
	//printf("DEBUG******** una fecha: %d-%d-%d\n", unaFecha->day,unaFecha->month,unaFecha->year);


	//printf("una fecha: %d-%d-%d\n",unaFecha.year, unaFecha.day, unaFecha.month);

	retorno =0;

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
		auxArtista = art_pedirArtista(listaArtistas, sizeListaArtista);
		if(auxArtista>0)
		{
			*idArtista = auxArtista;
			//printf("un artista: %d", *idArtista);
			retorno =0;
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
* \brief add in a existing list of Album the values received as parameters
* 	     in the first empty position(with alb_cargarUnNuevoAlbumAlArray)
* 	     with the last id wich it has finded
* \param listaAlbum eAlbum* receives the list where will write the struct
* \param sizeListaAlbum int to indicate array size

* \return int Return (-1) if Error [Invalid length or NULL pointer or withoufree space]
*					  (0) if Ok
*
*/
int alb_getNuevoAlbum(eAlbum* listaAlbum, int sizeListaAlbum, eArtista* listaArtista, int sizeListaArtista)
{
	int retorno;
	int idArtistaAlbum;
	eFecha unaFechaAlbum;
	float importeAlbum;
	char tituloAlbum[STR_SIZE];

	retorno = -1;
	if(listaAlbum!= NULL && sizeListaAlbum >0 && listaArtista != NULL && sizeListaArtista >0)
	{
		retorno = -2;
		alb_getTitulo(tituloAlbum, STR_SIZE);
		alb_getFecha(&unaFechaAlbum);
		alb_getImporte(&importeAlbum);
		alb_getArtista(listaArtista, sizeListaArtista, &idArtistaAlbum);

		if(!alb_cargarUnNuevoAlbumAlArray(tituloAlbum,STR_SIZE, &unaFechaAlbum, importeAlbum, idArtistaAlbum, listaAlbum, sizeListaAlbum))
		{
			retorno=0;
		}
	}
	return retorno;
}

int alb_cargarUnNuevoAlbumAlArray(char* tituloAlbum, int sizeTituloAlbum, eFecha* fechaAlbum, float importeAlbum, int idArtistaAlbum, eAlbum* listaAlbum, int sizeListaAlbum)
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
			{101, "Fantaisie-Impromptu",{1,1,1851},2500,1, NOT_EMPTY},
			{102, "El disco de tu corazon", {1,1,2017}, 2050, 4,NOT_EMPTY},
			{103, "Sin restricciones",{1,5,2004},2000,4, NOT_EMPTY},
			{104, "El templo del pop",{1,8,2014},2500,4, NOT_EMPTY},
			{105, "Have a Nice day",{1,10,2015},1900,5, NOT_EMPTY},
			{106, "Master of puppets",{1,10,1986}, 1800,6, NOT_EMPTY},
			{107, "Made in Heaven",{1,11,1991},2100, 8, NOT_EMPTY},
			{108, "a Kind of magic",{12,11,1986}, 2150, 6, NOT_EMPTY}
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

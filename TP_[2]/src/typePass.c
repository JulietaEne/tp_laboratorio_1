/*
 * typePass.c
 *
 *  Created on: 13 may. 2022
 *      Author: julieta_enee
 */

#ifndef TYPEPASS_C_
#define TYPEPASS_C_
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "arrays.h"
#include "tp.h"
#include "typePass.h"

/**
* \brief realiza un hardcodeo de 3 elementos a cargar en el array de tipo typePass
* \param listaTipoPasajeros typePass* Recibe la direccion de memoria del primer elemento del array sobre el cual se operara
* \param sizeTipoPasajeros int Recibe por valor tamaño de la lista
* \return Return 0 si opero correctamente
* 				(-1) si hubo un error en los parametros recibidos
*
*/
int typePass_cargaForzadaDatos(typePass* listaTipoPasajeros, int sizeTipoPasajeros)
{
  int retorno;
  int i;
  typePass cargaTiposPasajeros[]= {
                                   {1, "CLASE TURISTA", NOT_EMPTY},
                                   {2, "CLASE ECONOMICA", NOT_EMPTY},
                                   {3, "PRIMERA CLASE", NOT_EMPTY}
                                 };
  retorno = -1;
  if( listaTipoPasajeros != NULL && sizeTipoPasajeros >0)
  {
      retorno =0;
      for (i=0; i<sizeTipoPasajeros; i++)
      {
          listaTipoPasajeros[i] = cargaTiposPasajeros[i];
      }
  }
  return retorno;
}

/*
 * \brief Recorre el array recibido para imprimir los indices que estan cargados
 * \param listaTipoPasajeros typePass* Recibe la direccion de memoria del array sobre el cual va a trabajar
 * \param sizeTipoPasajeros int Recibe por valor el tamaño del array
 * \return retorna int -1 si hubo un error en los parametros recibidos
 * 			0 si la operacion se realizo correctamente
 *
 */
int typePass_printListaTiposPasajeros(typePass* listaTipoPasajeros, int sizeTipoPasajeros)
{
    int retorno;
    int i;
    retorno = -1;
    if(listaTipoPasajeros != NULL && sizeTipoPasajeros > 0)
    {
        retorno = 0;
        for (i=0; i<sizeTipoPasajeros; i++)
        {
            if(listaTipoPasajeros[i].isEmpty == 1)
            {
                typePass_printPosicion(listaTipoPasajeros, i);
            }
        }
    }
    return retorno;
}

/**
 * \brief Recibe un array de estructuras e imprime una estructura segun el indice recibido
 * \param listaTipoPasajeros *typePass recibe la direccion de memoria del array sobre el cual va a trabajar
 * \param indice int Recibe por valor la posicion del array del cual imprimira los valores de sus campos
 * \return retorna int -1 si hubo un error en los parametros recibidos
 * 			0 si la operacion se realizo correctamente
 *
 */
int typePass_printPosicion(typePass* listaTipoPasajeros, int indice)
{
    int retorno;
    retorno = -1;
    if(listaTipoPasajeros != NULL && indice >=0)
    {
        retorno = 0;
        printf("%d- %s \n", listaTipoPasajeros[indice].idTypePass, listaTipoPasajeros[indice].description);
    }
    return retorno;
}

/**
 * \brief Recibe una lista de tipo typePass y un ID. Recorre la lista en el campo .idTypePass e imprime cuando encuentra coincidencia
 * \param listaTipoPasajeros *typePass recibe la direccion de memoria del array sobre el cual va a trabajar
 * \param sizeTipoPasajeros recibe por valor el tamaño del array
 * \param indice int Recibe por valor la posicion del array del cual imprimira los valores de sus campos
 * \return retorna int -1 si hubo un error en los parametros recibidos
 * 			0 si la operacion se realizo correctamente
 *
 */
int typePass_printTipoPasajeroSegunId(typePass* listaTipoPasajeros, int sizeTipoPasajeros, int idTipoPasajero)
{
	int retorno;
	int i;
	retorno =-1;
	if(listaTipoPasajeros != NULL && sizeTipoPasajeros >0 && idTipoPasajero >= 0)
	{
		retorno = 0;
		for (i=0; i<sizeTipoPasajeros; i++)
		{
			if(listaTipoPasajeros[i].isEmpty == NOT_EMPTY && idTipoPasajero == listaTipoPasajeros[i].idTypePass)
			{
				typePass_printPosicion(listaTipoPasajeros, i);
				break;
			}
		}
	}
	return retorno;
}

/*
 * \brief interactua con el usuario para solicitar el tipo de pasajero del cliente
 * \param listaTipoPasajeros typePass* Recibe la direccion de memoria de la lista con la cual trabajara
 * \param sizeTipoPasajeros int Recibe por valor el tamaño de la lista
 * \return retorna -1 si hubo un error en los parametros recibidos
 * 		   			0 si la operacion se realizo correctamente
 *
 */
int typePass_getTipoPasajero(typePass* listaTipoPasajeros, int sizeTipoPasajeros)
{
	int unTipo;
	unTipo = -1;
	if(listaTipoPasajeros != NULL && sizeTipoPasajeros >0)
	{
		unTipo = 0;
		//if(!typePass_printListaTiposPasajeros(listaTipoPasajeros, sizeTipoPasajeros))
		//{
		printf("Ingrese el codigo del tipo de pasajero: \n");
		typePass_printListaTiposPasajeros(listaTipoPasajeros, sizeTipoPasajeros);
			utn_GetNumeroInt(&unTipo, "Ingrese el codigo: ", "Ingrese un dato valido", 1, 3, REINTENTOS);
		//}
	}
	return unTipo;
}

#endif /* TYPEPASS_C_ */

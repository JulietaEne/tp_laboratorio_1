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

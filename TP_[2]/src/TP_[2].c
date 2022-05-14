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
#include "passenger.h"
#include "utn.h"
#include "arrays.h"
#include "tp.h"

#define ID_INICIAL 100

#define QTY_PASS 2000
#define QTY_TYPEPASS 3

int main(void) {

    int menuPrincipal;
    int contadorPass;
    Passenger listaPasajeros[QTY_PASS];
    typePass listaTipoPasajeros[QTY_TYPEPASS];
    int ultimoIdPass;
    //int auxId;
    int auxIndex;
    int menuSecundario;
   // int respContinuar;

    contadorPass = -1;
    //***CARGA FORZADA DE DATOS***///
    if(contadorPass == -1)
	{
		//inicializo
		pass_initArray(listaPasajeros, QTY_PASS);
		typePass_cargaForzadaDatos(listaTipoPasajeros, QTY_TYPEPASS);
		ultimoIdPass= pass_indicarUltimoId(listaPasajeros, QTY_PASS);
	}
    ////////////////////////////////
    do
    {
        menuPrincipal = tp_ImprimirMenuSeisOpciones("\nMENU", "1- ALTA DE CLIENTE", "2- MODIFICAR CLIENTE", "3- BAJA DE CLIENTE", "4- INFORMES", "5- CARGA FORZADA", "6- SALIR");

        switch(menuPrincipal)
        {
            case 1:
                printf("\nALTA DE CLIENTES\n");
                if(!pass_getNuevoPasajero(listaPasajeros, QTY_PASS, ultimoIdPass, listaTipoPasajeros, QTY_TYPEPASS))
                {
                    pass_printArrayConTipoPasajero(listaPasajeros, QTY_PASS, listaTipoPasajeros, QTY_TYPEPASS);
                }
                else
                {
                    tp_MensajeError("\nNo se ha podido ingresar correctamente el pasajero");
                }
            break;

            case 2:
                printf("\nMODIFICAR CLIENTE\n");
                pass_contadorPasajerosCargados(listaPasajeros, QTY_PASS, &contadorPass);
                if(contadorPass>0)
                {
                    //solicito id de cliente para modificarlo
                    auxIndex = pass_pedirIdYDevolverIndex(listaPasajeros, QTY_PASS, listaTipoPasajeros, QTY_TYPEPASS);
                    pass_interaccionMenuSecundario(listaPasajeros, QTY_PASS, auxIndex, listaTipoPasajeros, QTY_TYPEPASS);
                }
                else
                {
                    tp_MensajeError("ERROR*** No hay pasajeros ingresados. Ingrese un pasajero para continuar. \n\n");
                }
            break;

            case 3:
                printf("\nELIMINAR CLIENTE\n");
                pass_contadorPasajerosCargados(listaPasajeros, QTY_PASS, &contadorPass);
				if(contadorPass>0)
                {
                    //solicito id de cliente para modificarlo
                    auxIndex = pass_pedirIdYDevolverIndex(listaPasajeros, QTY_PASS, listaTipoPasajeros, QTY_TYPEPASS);
                    if(!pass_removerSegunId(listaPasajeros, auxIndex))
                    {
                        printf("el pasajero nº%d se ha eliminado correctamente", listaPasajeros[auxIndex].id);
                    }
                }
                else
                {
                    //primero hay que cargar clientes
                	tp_MensajeError("ERROR*** No hay pasajeros ingresados. Ingrese un pasajero para continuar. \n\n");
                }
            break;

            case 4:
                do
				{
					menuSecundario=tp_ImprimirMenuSeisOpciones("\nINFORMES\nListados de pasajeros según:", "1- Orden alfabetico (apellidos) o por tipo de pasajero", "2- Informe de total y promedio de precios", "3- Orden por codigo de vuelo y vuelos activos", "4- Volver al menu anterior", "", "");
					//printf("DEBUG**** menu segundario : %d\n\n", menuSecundario);
					switch(menuSecundario)
					{
					    case 1:
					        //orden alfabetico o por tipo
							pass_consignaCuatroUno(listaPasajeros, QTY_PASS, listaTipoPasajeros, QTY_TYPEPASS);
							break;
						case 2:
							//Informe de total y promedio de precios
							pass_consignaCuatroDos(listaPasajeros, QTY_PASS);
							break;
						case 3:
						    //Orden por codigo de vuelo y vuelos activos
							pass_ordenarVuelosActivos(listaPasajeros, QTY_PASS, listaTipoPasajeros, QTY_TYPEPASS);
							break;
					}
				}while(menuSecundario<4);
            break;

            case 5:
            	pass_cargaForzadaDeDatos(listaPasajeros, QTY_PASS);
            	pass_printArrayConTipoPasajero(listaPasajeros, QTY_PASS, listaTipoPasajeros, QTY_TYPEPASS);
            break;

            case 6:
				printf("Saliendo del programa. \nMuchas gracias. \nNakasone Julieta");
			break;
        }
    }while(menuPrincipal<6);

    return EXIT_SUCCESS;
}
/*
if(!pass_initArray(arrayPasajeros, QTY_PASS))
{
	pass_printArray(arrayPasajeros, QTY_PASS);
	printf("inicializamos!");
}
if(!pass_pedirNuevoPasajero(arrayPasajeros, QTY_PASS, idUltimo))
{
	idUltimo ++;
	pass_printArray(arrayPasajeros, QTY_PASS);
}*/

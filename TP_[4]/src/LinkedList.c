#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);
//static Node*  findNodeByIndex(LinkedList* this, int nodeIndex, Node* pObtainedNode);

//static void countNode(Node* this, int* counter);


/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
	LinkedList* this= NULL;
	this = (LinkedList*) malloc(sizeof(LinkedList));
	if(this != NULL)
	{
		this->pFirstNode = NULL;
		this->size = 0;
	}
	return this;
	//printf("New linkedList\n First Node: %p - size Of this%d", this->pFirstNode, this->size);
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
	Node* pAuxNode=NULL;
    int lenghtList;

    lenghtList=-1;
    if(this != NULL)
    {
    	lenghtList = this->size;

    	/*contadorLen=0;
    	pAuxNode = this->pFirstNode;

		if(pAuxNode!= NULL)// si la linkedList apunta a 1 elemento
		{
			contadorLen = 1;
			do
			{

				if(pAuxNode->pNextNode!= NULL)//si en el campo pNextNode, hay una direccion de memoria
				{
					contadorLen++;//contabilizo
					pAuxNode=pAuxNode->pNextNode;//actualizo el auxiliar
					//printf("!!!!!!!!!!!!!tenemos elementos? %d!!!!!!!!!!", contadorLen);
				}
				else
				{
					break;
				}
			}while(pAuxNode!=NULL);
		}//*/
    }
  //  printf("retorno: %d\n\n", contadorLen);
    return lenghtList;
}

/*static void countNode(Node* this, int* counter)
{
	do
	{
		counter++;//contabilizo
		if(this->pNextNode!= NULL)//si en el campo pNextNode, hay una direccion de memoria
		{
			this=this->pNextNode;//actualizo el auxiliar
		}
		else
		{
			break;
		}
	}while(this!=NULL);
}*/

/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 *                       (pGetNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pGetNode=NULL;
    int sizeThis;
    int i;

    sizeThis = ll_len(this);
    if(this != NULL && nodeIndex>=0 && nodeIndex<sizeThis && sizeThis >0)
    {
    	//findNodeByIndex(this, nodeIndex,pObtainedNode);
    	pGetNode= this->pFirstNode;
    	for(i=1; i<=nodeIndex; i++)
    	{
    		pGetNode = pGetNode->pNextNode;
    	}
    }
	return pGetNode;
}

/*static Node* findNodeByIndex(LinkedList* this, int nodeIndex, Node* pObtainedNode)
{
	int i;
	Node* pAuxNode=NULL;

	pObtainedNode= this->pFirstNode;
	printf("\nprimer nodo:%p \n", pObtainedNode);
	for(i=1; i<=nodeIndex; i++)
	{
		printf("i/index=%d nodo:%p \n", i, pObtainedNode->pNextNode);
		pObtainedNode = pObtainedNode->pNextNode;
		pAuxNode = pObtainedNode;
	}
	return pAuxNode;
}*/

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
	Node* newNode=NULL;
	Node* nodoAnterior = NULL;
	Node* nodoReacomodado = NULL;
	int sizeThis;
	int retorno;
	//int i;

	retorno = -1;
	sizeThis = ll_len(this);
	if( this != NULL && nodeIndex >= 0 && nodeIndex <= sizeThis)
	{
		newNode = (Node*)malloc(sizeof(Node));
		if(newNode != NULL)
		{
			//acá tengo que poner còmo se completarian los campos de la estructura para cada caso
			switch (nodeIndex)
			{
				case 0://si tengo que cargar el primer nodo
					this->pFirstNode = newNode;
					newNode->pNextNode = NULL;
					break;
				default:
					if(nodeIndex==sizeThis)//quiere decir que va a ser un elemento que se agregue a lo ultimo
					{
						nodoAnterior = getNode(this, nodeIndex);
						nodoAnterior->pNextNode= newNode;
						newNode->pNextNode=NULL;
					}
					else//si pongo un nodo entre dos nodos
					{
						nodoReacomodado = getNode(this, nodeIndex);
						nodoAnterior = getNode(this, nodeIndex-1);
						nodoAnterior->pNextNode=newNode;
						newNode->pNextNode=nodoReacomodado;
					}
					break;
			}
			newNode->pElement= pElement;
			this->size = sizeThis+1;
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int retorno;
    int sizeThis;

    retorno = -1;
    if(this != NULL && pElement != NULL)
    {
    	sizeThis = ll_len(this);
    	if(!addNode(this, sizeThis, pElement))
    	{
        	retorno = 0;
    	}
    }
    return retorno;
}

/** \brief Retorna un puntero al elemento que se encuentra en el índice especificado
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* pElemento = NULL;
    Node* pNodoElemento = NULL;
    int sizeThis;

    sizeThis = ll_len(this);
    if(this!= NULL && index)
    {
    	pNodoElemento = getNode(this, index);
    	if(pNodoElemento != NULL)
    	{
    		pElemento = pNodoElemento->pElement;
    	}
    }
    return pElemento;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int retorno;
    int sizeThis;
    Node* nodoSeteado;

    sizeThis = ll_len(this);
    retorno = -1;
    if(this != NULL && index>= 0 && index<sizeThis && pElement != NULL)
    {
    	nodoSeteado = getNode(this, index);
    	if(nodoSeteado != NULL)
    	{
    		nodoSeteado->pElement = pElement;
    		retorno = 0;
    	}
    }
    return retorno;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;

    return returnAux;

}


/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "../../testing/utest.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//INCLUDE LIBRARY TO TEST

#include "../../inc/LinkedList.h"
#include "../../testing/inc/Employee.h"

void getNodeTestSetup(void)
{
	utest_print("Setup...\r\n");
}

void getNodeTestCase01(void)
{
    LinkedList* list;
    Node* nodo1;
    Node* nodo2;
    Node* nodoAux;

    list = ll_newLinkedList();
    nodo1 = malloc(sizeof(Node));
    nodo2 = malloc(sizeof(Node));
    nodo1->pNextNode = nodo2;
    nodo2->pNextNode = NULL;
    list->pFirstNode = nodo1;
    list->size=2;
    //printf("CASE1 size 2 - index 0\n");
    nodoAux = test_getNode(list,0);
    utest_assertNotNullMsg(nodoAux,"\n01 Error en el valor de retorno de <getNode> si los parametros son correctos\n y la lista tiene elementos la funcion retorna el puntero al nodo\n");

}


void getNodeTestCase02(void)
{
    LinkedList* list;
    Node* nodo1;
    Node* nodo2;
    Node* nodoAux;

    list = ll_newLinkedList();
    nodo1 = malloc(sizeof(Node));
    nodo2 = malloc(sizeof(Node));
    nodo1->pNextNode = nodo2;
    nodo2->pNextNode = NULL;
    list->pFirstNode = nodo1;
    list->size=2;
   // printf("CASE2 (size 2 - index 0)\n");
    nodoAux = test_getNode(list,0);
    utest_assertEqualsPointerMsg(nodoAux,nodo1,"\n02 Error en el valor de retorno de <getNode> al solicitar el primer elemento\n");

}

void getNodeTestCase03(void)
{
    LinkedList* list;
    Node* nodo1;
    Node* nodo2;
    Node* nodoAux;

    list = ll_newLinkedList();
    nodo1 = malloc(sizeof(Node));
    nodo2 = malloc(sizeof(Node));
    nodo1->pNextNode = nodo2;
    nodo2->pNextNode = NULL;
    list->pFirstNode = nodo1;
    list->size=2;
  //  printf("CASE3 (size 2 - index 1)\n");
    nodoAux = test_getNode(list,1);
    utest_assertEqualsPointerMsg(nodoAux,nodo2,"\n03 Error en el valor de retorno de <getNode> al solicitar el ultimo elemento\n");

}

void getNodeTestCase04(void)
{
    LinkedList* list;
    Node* nodo1;
    Node* nodo2;
    Node* nodoAux;

    list = ll_newLinkedList();
    nodo1 = malloc(sizeof(Node));
    nodo2 = malloc(sizeof(Node));
    nodo1->pNextNode = nodo2;
    nodo2->pNextNode = NULL;
    list->pFirstNode = nodo1;
    list->size=1;
  //  printf("CASE4 (size 1(pero tiene 2) - index -1)\n");
    nodoAux = test_getNode(list,-1);
    utest_assertNullMsg(nodoAux, "\n04 Error en el valor de retorno de <getNode> al solicitar un elemento fuera de indice (-1),\n se deberia retornar NULL\n");
   // printf("CASE4 (size 1 (pero tiene 2) - index 1)\n");
    nodoAux = test_getNode(list,1);
    utest_assertNullMsg(nodoAux, "\n04b Error en el valor de retorno de <getNode> al solicitar un elemento fuera de indice (>= a ll_len),\n se deberia retornar NULL\n");


}

void getNodeTestCase05(void)
{
	//sprintf("CASE5 (lista NULL - index 0)\n");
    utest_assertNullMsg(test_getNode(NULL,0),"\n05 Error en el valor de retorno de <get> si la lista pasada es NULL\n el valor a retornar es (-1)\n");
}


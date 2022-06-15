#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/Employee.h"

int compareEmployee(void* pEmployeeA,void* pEmployeeB)
{
	int retorno;


//	printf("estoy en la func compareEmployee");
	retorno = 0;

	printf("(A)%.2f ?= (B)%.2f",((Employee*)pEmployeeA)->salary,((Employee*)pEmployeeB)->salary );

    if(((Employee*)pEmployeeA)->salary > ((Employee*)pEmployeeB)->salary)
    {
    	retorno = 1;

    }
    if(((Employee*)pEmployeeA)->salary < ((Employee*)pEmployeeB)->salary)
    {
    	retorno = -1;
    }
    printf(" | retorno = %d****\n", retorno);
    return retorno;


}

void printEmployee(Employee* p)
{
    printf("Nombre:%s Salario:%.2f\r\n",p->name,p->salary);
}

/** \brief Set this employee the values recived as parameters
 *
 * \param pEmployee employee*
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [NULL pointer] - (0) if Ok
 *
 */
Employee* newEmployee(int id, char name[],char lastName[],float salary,int sector)
{
    Employee* returnAux = NULL;
    Employee* pEmployee = malloc(sizeof(Employee));

    if(pEmployee != NULL)
    {
        pEmployee->id = id;
        strcpy(pEmployee->name,name);
        strcpy(pEmployee->lastName,lastName);
        pEmployee->salary = salary;
        pEmployee->sector = sector;
        pEmployee->isEmpty = 0;
        returnAux = pEmployee;
    }

    return returnAux;

}


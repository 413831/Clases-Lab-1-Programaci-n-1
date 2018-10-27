#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    char bufferId[1000];
    char bufferName[1000];
    char bufferHorasTrabajadas[1000];
    char bufferSueldo[1000];

    int flagOnce = 1;
    Employee* pEmployee;

    if(pFile != NULL)
    {
        while(!feof(pFile))
        {
            if(flagOnce == 1)
            {
                fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferName,bufferHorasTrabajadas,bufferSueldo);
                flagOnce = 0;
            }
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferName,bufferHorasTrabajadas,bufferSueldo);

            pEmployee = employee_newConParametros(bufferId,bufferName,bufferHorasTrabajadas,bufferSueldo);
            if(pEmployee != NULL)
            {
                ll_add(pArrayListEmployee,pEmployee);//Se agrega ELEMENTO a LINKED LIST
                retorno = 0;
            }
        }
    }
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    //Revisar TIPOS
    int retorno = -1;
    char bufferId[1000];
    char bufferName[1000];
    char bufferHorasTrabajadas[1000];
    char bufferSueldo[1000];

    int flagOnce = 1;
    Employee* pEmployee;

    if(pFile != NULL)
    {
        while(!feof(pFile))
        {
            if(flagOnce == 1)
            {
                fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferName,bufferHorasTrabajadas,bufferSueldo);
                flagOnce = 0;
            }
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferName,bufferHorasTrabajadas,bufferSueldo);

            pEmployee = employee_newConParametros(bufferId,bufferName,bufferHorasTrabajadas,bufferSueldo);
            if(pEmployee != NULL)
            {
                ll_add(pArrayListEmployee,pEmployee);//Se agrega ELEMENTO a LINKED LIST
                retorno = 0;
            }
        }
    }
    return retorno;
    return 1;
}

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

/** \brief Parsea los datos del linked list al archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_SaveToText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* auxEmployee;
    int len;
    int index;
    int bufferId;
    char bufferName[1000];
    int bufferHorasTrabajadas;
    float bufferSueldo;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        len = ll_len(pArrayListEmployee);

        for(index=0;index<len;index++)//Recorro todo el array hasta el LEN
        {
            auxEmployee = ll_get(pArrayListEmployee,index);//Obtengo el elemento del array en posicion index
            employee_getAll(auxEmployee,bufferName,&bufferHorasTrabajadas,&bufferSueldo,&bufferId);
            fprintf(pFile,"%d,%s,%d,%f\n",bufferId,bufferName,bufferHorasTrabajadas,bufferSueldo);
            retorno = 0;
        }
    }
    return retorno;
}



/** \brief Parsea los datos del linked list al archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_SaveToBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i = 0;
    int len;
    Employee* auxEmployee;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        len = ll_len(pArrayListEmployee);
        while(i != len)
        {
            auxEmployee = ll_get(pArrayListEmployee,i);
            fwrite(auxEmployee,sizeof(Employee),1,pFile);
            retorno = 0;
            i++;
        }
    }
    return retorno;
}

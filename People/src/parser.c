#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"
#include "../inc/People.h"
#include "../inc/utn.h"
#include "../inc/parser.h"

#define BUFFER 2000

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param pFile Es el puntero a archivo para leer los datos
 * \param pLinkedListPeople Es la LinkedList donde se guardaran los datos
 * \return Retorna 0 si existe el archivo sino retorna -1
 *
 */
int parser_PeopleFromText(FILE* pFile , LinkedList* pLinkedListPeople)
{
    int retorno = -1;
    char* bufferId;
    char* bufferName;
    char* bufferLastName;
    char* bufferSueldo;
    char* bufferIsEmpty;
    char bufferText[BUFFER];
    People* pPeople;

    if(pFile != NULL)
    {
        while(!feof(pFile))
        {
            fgets(bufferText,sizeof(bufferText),pFile);
            if(bufferText != NULL || strlen(bufferText) > 8)
            {
                bufferId = strtok(bufferText,";");
                bufferName = strtok(NULL,";");
                bufferLastName = strtok(NULL,";");
                bufferIsEmpty = strtok(NULL,";");
                bufferSueldo = strtok(NULL,"\n");

                pPeople = people_newConParametros(bufferId,bufferName,bufferLastName,bufferIsEmpty,bufferSueldo);
                if(pPeople != NULL)
                {
                    ll_add(pLinkedListPeople,pPeople);//Se agrega ELEMENTO a LINKED LIST
                    retorno = 0;
                }
            }
        }
    }
    return retorno;
}


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param pFile Es el puntero a archivo para leer los datos
 * \param pLinkedListPeople Es la LinkedList donde se guardaran los datos
 * \return Retorna 0 si existe el archivo sino retorna -1
 *
 */
int parser_PeopleFromBinary(FILE* pFile , LinkedList* pLinkedListPeople)
{
    int retorno = -1;
    int cantidadLeida;
    People* pPeople;
    People* aux = people_new();

    if(pFile != NULL)
    {
        while(!feof(pFile))
        {
            pPeople = people_new();
            cantidadLeida = fread(pPeople,sizeof(People),1,pFile);
            if(pPeople != NULL && cantidadLeida == 1)
            {
                people_setId(aux,0);
                ll_add(pLinkedListPeople,pPeople);
                retorno = 0;
            }
        }
    }
    return retorno;
}

/** \brief Parsea los datos del linked list al archivo data.csv (modo texto).
 *
 * \param pFile Es el puntero a archivo para escribir los datos
 * \param pLinkedListPeople Es la LinkedList de donde se toman los datos
 * \return Retorna 0 si existe el archivo y el LinkedList sino retorna -1
 *
 */
int parser_SaveToText(FILE* pFile , LinkedList* pLinkedListPeople)
{
    int retorno = -1;
    People* auxPeople;
    int len;
    int index;
    int bufferId;
    int bufferIsEmpty;
    int bufferHorasTrabajadas;
    int bufferSueldo;
    char strIsEmpty[BUFFER];
    char bufferName[BUFFER];
    char bufferLastName[BUFFER];

    if(pFile != NULL && pLinkedListPeople != NULL)
    {
        len = ll_len(pLinkedListPeople);

        for(index=0;index<len;index++)//Recorro todo el array hasta el LEN
        {
            auxPeople = ll_get(pLinkedListPeople,index);//Obtengo el elemento del array en posicion index

            people_getAll(auxPeople,&bufferId,bufferName,bufferLastName,&bufferSueldo,&bufferIsEmpty);

            if(bufferIsEmpty == 1)
            {
                strcpy(strIsEmpty,"true");
            }
            else if(bufferIsEmpty == 0)
            {
                strcpy(strIsEmpty,"false");
            }
            fprintf(pFile,"%d,%s,%s,%d,%s\n",bufferId,bufferName,bufferLastName,bufferSueldo,strIsEmpty);
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief Parsea los datos del linked list al archivo data.bin (modo binario).
 *
 * \param pFile Es el puntero a archivo para escribir los datos
 * \param pLinkedListPeople Es la LinkedList de donde se toman los datos
 * \return Retorna 0 si existe el archivo y el LinkedList sino retorna -1
 *
 */
int parser_SaveToBinary(FILE* pFile , LinkedList* pLinkedListPeople)
{
    int retorno = -1;
    int i = 0;
    int len;
    People* auxPeople;

    if(pFile != NULL && pLinkedListPeople != NULL)
    {
        len = ll_len(pLinkedListPeople);
        while(i != len)
        {
            auxPeople = ll_get(pLinkedListPeople,i);
            if(auxPeople != NULL)
            {
                fwrite(auxPeople,sizeof(People),1,pFile);
            }
            retorno = 0;
            i++;
        }
    }
    return retorno;
}

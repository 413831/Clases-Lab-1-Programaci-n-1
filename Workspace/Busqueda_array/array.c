#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

#define false 0
#define true 1
#define DATO_INVALIDO -1



/**
* \brief Modificar el dato de un indice especifico del array
* \param pArray Es el array que recibe para mostrar
* \param pIndice Es puntero del indice del array que recibe para modificar
* \param pSize Es el puntero del tamaño del array
* \param pMensaje Es el puntero del mensaje a mostrar al usuario
* \return Retorna void
*/

void array_modificarDato(int* pArray,int* pIndice,int* pSize,char* pMensaje)
{
    *pIndice = input_getInt("\nIngrese el indice a modificar: ");
    if(pIndice >= 0 && pIndice < pSize)
    {
        pArray[*pIndice] =  input_getInt(pMensaje);
    }
    else
    {
        printf("\nError.Dato fuera de rango.");
    }
}



int array_init(int* pArray, int limite, int valor)
{
    int retorno=-1;
    int i;
    if(pArray != NULL && limite > 0)
    {
        for(i=0;i<limite;i++)
        {
            pArray[i] = valor;
        }
        retorno = 0;
    }
    return retorno;
}




int array_calcularMaximo(int* pArray, int limite, int* pMaximo)
{
    int retorno=-1;
    int i;

    int maximo;
    int flagPrimerMaximo = false;

    if(pArray != NULL && limite > 0)
    {

        for(i=0;i<limite;i++)
        {
            if(pArray[i] != DATO_INVALIDO)
            {
                if(flagPrimerMaximo == false)
                {
                    maximo = pArray[i];
                    flagPrimerMaximo = true;
                }
                else if(pArray[i] > maximo)
                {
                    maximo = pArray[i];
                }
            }
        }

        if(flagPrimerMaximo == 0)
        {
            retorno = -2;
        }
        else
        {
            retorno = 0;
        }
    }
    return retorno;
}

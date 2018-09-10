#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

#define false 0
#define true 1
#define DATO_INVALIDO -1


/**
* \brief Mostrar los datos ingresados en un array de enteros
* \param pArray Es el array que recibe para mostrar
* \param pIndice Es puntero del indice del array que recibe para mostrar
* \param pSize Es el puntero del tamaño del array
* \param pMensaje Es el puntero del mensaje a mostrar al usuario
* \return Retorna void
*/

void list_mostrarArray(int* pArray,int indice,int size,char* pMensaje)
{
    printf(pMensaje);
    for(indice = 0 ; indice < size ; indice++ )
    {
        printf("  %d    -   %d \n",indice,pArray[indice]);//Se muestra el INDICE y luego el VALOR guardado en ese INDICE del ARRAY
    }
}

int list_mostrarMenor(int array[],int size)
{
    int menor;
    int i;

    for(i=0;i<size;i++)
    {
        if(i == 0 || array[i]<menor)//Entra la primera vez por i ser 0 luego va comparando cual es el elemento menor
        {
        menor = array[i];
        }
    }

    return menor;

}


int list_mostrarMayor(int array[],int size)
{
    int mayor;
    int i;

    for(i=0;i<size;i++)
    {
        if(i == 0 || array[i]>mayor)//Entra la primera vez por i ser 0 luego va comparando cual es el elemento mayor
        {
        mayor = array[i];
        }
    }

    return mayor;
}


int list_mostrarPares(int array[],int size)
{
    int contadorPares = 0;
    int i;

    for(i=size;i>=0;i--)
    {
        if(array[i] % 2 == 0)
        {
        contadorPares++;
        }
    }

    return contadorPares;

}

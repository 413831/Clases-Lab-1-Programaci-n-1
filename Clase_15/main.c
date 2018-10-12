#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"

#define LIMITE 5

/**
>>Punteros
>>Memoria dinamica
    -Operadores
    -Malloc
    -Realloc
    -Free
*/


int initArray(int* array,int size,int value);
int showArray(int* array,int size);
int constructor(int** array,int size);
int destructor(int* array);
int resizeArray(int** array,int newsize);

int main()
{
    int* punteroInt = NULL;
    char* punteroChar = NULL;
    float* punteroFloat = NULL;

    int auxInt = 10;
    char auxChar = 'a';
    float auxFloat = 3.14;
    int** pPuntero = NULL;

    punteroInt = &auxInt ;//Se asigna direccion del valor al puntero
    punteroChar = &auxChar;
    punteroFloat = &auxFloat;

    pPuntero = &punteroInt;//Se asigna direccion del puntero a enteros

    *punteroInt = 22;//Se asigna un valor a traves de la direccion que contiene el puntero
    *punteroChar = 'b';
    *punteroFloat = 22.55;

    printf("\nDIRECCION DE MEMORIA %p -- VALOR INT %d",punteroInt,*punteroInt);
    printf("\nDIRECCION DE MEMORIA %p -- VALOR CHAR %c",punteroChar,*punteroChar);
    printf("\nDIRECCION DE MEMORIA %p -- VALOR FLOAT %f",punteroFloat,*punteroFloat);
    //Se muestra valor del entero por medio del puntero a puntero
    printf("\n\nDIRECCION DE MEMORIA %p -- VALOR INT POR PUNTERO %i",pPuntero,**pPuntero);

/////////////////////EJERCICIO MEMORIA DINAMICA//////////////////////////

    limpiarMemoria();
    getchar();

    int* arrayEnteros;

    constructor(&arrayEnteros,LIMITE);//Se pasa la direccion de memoria del array
    initArray(arrayEnteros,LIMITE,1);
    showArray(arrayEnteros,LIMITE);
    destructor(arrayEnteros);

    limpiarMemoria();
    getchar();

    resizeArray(&arrayEnteros,10);
    initArray(arrayEnteros,10,2);
    showArray(arrayEnteros,10);

    return 0;
}

/**
*\brief Crear array dinamico con malloc
*\param array Es el puntero de la direccion de memoria del array
*\param size Es el limite del array
*\return Retorna 0 si el puntero es diferente a NULL sino retorna -1
*/

int constructor(int** array,int size)
{
    int retorno = -1;
    int* auxArray;

    if(size > 0)
    {
        auxArray = (int*)malloc(sizeof(int)*size);//Reserva lugar para n variables tipo int
        if(auxArray != NULL)
        {
            *array = auxArray;
            retorno = 0;
        }
    }
    return retorno;
}

/**Inicializar array
*/
int initArray(int* array,int size,int value)
{
    int retorno = -1;
    int i = 0;

    if(array != NULL && size > 0)
    {
        for(i=0;i<size;i++)
        {
            *(array+i) = value;//Primero el puntero se desplaza i veces, luego accede y guarda
        }
        retorno = 0;
    }
    return retorno;
}

/**Mostrar array
*/

int showArray(int* array,int size)
{
    int i;
    int retorno = -1;

    if(array != NULL && size > 0)
    {
         for(i=0;i<size;i++)
        {
            printf("\n VALOR %d -- INDICE [%d] -- DIR MEMORIA %p",*(array+i),i,array+i);
        }
    }
    return retorno;
}

/**Borrar array
*/

int destructor(int* array)
{
    int retorno = -1;

    if(array != NULL)
    {
        free(array);
        retorno = 0;
    }
    return retorno;
}

int resizeArray(int** array,int newsize)
{
    int retorno = -1;
    int* auxArray;

    if(array != NULL && newsize > 0)
    {
        auxArray = (int*)realloc(*array,sizeof(int)*newsize);//Reserva lugar para n variables tipo int
        if(auxArray != NULL)
        {
            *array = auxArray;
            retorno = 0;
        }
    }
    return retorno;
}

#include <stdio_ext.h>
#include <stdlib.h>


int initArray(int* array,int size,int value);
int showArray(int* array,int size);
int constructor(int** array,int size);
int destructor(int* array);
int resizeArray(int** array,int newsize);


/**
*\brief Crear array dinamico con funcion malloc
*\param array Es el puntero de la direccion de memoria del array
*\param size Es el limite del array
*\return Retorna 0 si el puntero es diferente a NULL y el size valido sino retorna -1
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


/**
*\brief Inicializar array dinamico
*\param array Es el puntero que recibe para inicializar
*\param size Es el limite de datos
*\param value Es el valor para inicializar
*\return Retorna 0 si el puntero es diferente a NULL y el size valido sino retorna -1
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


/**
*\brief Muestra datos del array dinamico
*\param array Es el puntero que recibe para mostrar
*\param size Es el limite de datos
*\return Retorna 0 si el puntero es diferente a NULL y el size valido sino retorna -1
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

/**
*\brief Borrar un array dinamico con funcion free
*\param array Es el puntero que recibe para liberar
*\return Retorna 0 si el puntero es diferente a NULL sino retorna -1
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


/**
*\brief Relocaliza un array dinamico con funcion realloc
*\param array Es el puntero de la direccion de memoria del array
*\param newsize Es el nuevo limite del array
*\return Retorna 0 si el puntero es diferente a NULL y el newsize valido sino retorna -1
*/

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

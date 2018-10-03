#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utn.h"
#include "Contratacion.h"


//Funciones privadas



/**
*\brief Realiza el swap entre dos elementos
*\param valorA es el puntero del primer elemento
*\param valorB es el puntero del segundo elemento
*\return Retorna void
*/


static void swap(Contratacion* valorA,Contratacion* valorB)
{
    Contratacion auxiliar;//TIPO cont
    auxiliar = *valorA;
    *valorA = *valorB;
    *valorB = auxiliar;
}

/**
*\brief Genera automáticamente un ID único
*\param void
*\return Retorna el número de ID
*/

static int generateID()
{
    static int id = 0;
    id++;
    return id;
}



//__________________




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
*\brief Busca el indice libre en un array
*\param array Es el array que reciba para recorrer
*\param size Es el tamaño del array
*\return Retorna el indice del lugar libre si no retorna -1
*/

int cont_buscarIndiceLibre(Contratacion array[],int size)
{
    int retorno = -1;
    int i;

    for(i=0;i < size; i++)
    {
        if(array[i].isEmpty)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

/**
*\brief Inicializa todos los elementos de un array con un valor de vacio
*\param array Es el array que reciba para recorrer
*\param size Es el tamaño del array
*\param valor Es el valor con el cual cargara el campo de estado
*\return Retorna 0 si no retorna -1
*/

int cont_init(Contratacion array[],int size,int valor)
{
    int i;
    int retorno = -1;
    if(array != NULL && size > 0 && valor >= 0)
    {
        retorno = 0;
        for(i=0;i < size; i++)
        {
        array[i].isEmpty = valor;
        }

    }
    return retorno;
}

/**
*\brief Busca un elemento por ID dentro de un array de estructuras
*\param array Es el array que reciba para recorrer
*\param size Es el tamaño del array
*\param id Es el ID que recibe para buscar
*\return Retorna el puntero del elemento si no retorna NULL
*/

Contratacion* cont_getByID(Contratacion* array,int size,int id)
{
    Contratacion* retorno = NULL;
    int i;

    if(array != NULL && size > 0)
    {
        for(i=0;i<size;i++)
        {
           if(!array[i].isEmpty && array[i].id == id)
            {
            retorno = array+i;
            break;
            }
        }
    }
    return retorno;
}

/**
*\brief Realiza el alta de un elemento del array
*\param array Es el array que reciba para recorrer
*\param size Es el tamaño del array
*\return Retorna 0 si no retorna -1
*/

int cont_alta(Contratacion array[],int size,int id)
{
    char cuit[50];
    int idContratacion;
    int dias;
    char archivo[50];
    int retorno = -1;
    int indice;

    indice = cont_buscarIndiceLibre(array,size);

    if( !input_getCuit(cuit,50,"\nIngrese CUIT: ","\nError,dato invalido.",2)&&
        !input_getLetras(archivo,50,"\nIngrese cuit archivo: ","\nError,dato invalido.",2)&&
        !input_getNumeros(&idContratacion,3,"\nIngrese ID pantalla: ","\nError,dato invalido.",1,10,2)&&
        !input_getNumeros(&dias,7,"\nIngrese dias: ","\nError,dato invalido.",1000,100000,2))
    {
        strncpy(array[indice].cuit,cuit,50);
        strncpy(array[indice].archivo,archivo,50);
        array[indice].dias = dias;
        array[indice].isEmpty = 0;
        array[indice].id = generateID();//SE PASA ID ASIGNADO A LA ESTRUCTURA
        array[indice].idPantalla = id;
        retorno = 0;
    }

    return retorno;
}

/**
*\brief Modifica los campos de un elemento del array
*\param array Es el puntero que recibe del elemento del array
*\param size Es el tamaño del array
*\return Retorna 0 si no retorna -1
*/

int cont_modificar(Contratacion* array,int size)
{
    char cuit[50];
    int idContratacion;
    int dias;
    char archivo[50];
    int retorno = -1;

    if(array != NULL && array->isEmpty == 0)
    {
        if( !input_getCuit(cuit,50,"\nIngrese CUIT: ","\nError,dato invalido.",2)&&
        !input_getLetras(archivo,50,"\nIngrese cuit archivo: ","\nError,dato invalido.",2)&&
        !input_getNumeros(&idContratacion,3,"\nIngrese ID pantalla: ","\nError,dato invalido.",1,10,2)&&
        !input_getNumeros(&dias,7,"\nIngrese dias: ","\nError,dato invalido.",1000,100000,2))
        {
            strncpy(array->cuit,cuit,50);
            strncpy(array->archivo,archivo,50);
            array->dias = dias;
            array->isEmpty = 0;
            array->id = generateID();//SE PASA ID ASIGNADO A LA ESTRUCTURA
            retorno = 0;
        }


    }
    else
    {
        printf("\nCasillero vacio");
    }

    return retorno;
}

/**
*\brief Modifica los campos de un elemento del array
*\param array Es el puntero que recibe del elemento del array
*\param size Es el tamaño del array
*\return Retorna 0 si no retorna -1
*/

int cont_eliminar(Contratacion* array,int size)
{
    int retorno = -1;

    if(array != NULL)
    {
            array->isEmpty = 1;
            retorno = 0;
    }
    else
    {
        printf("\nCasillero vacio");
    }
    return retorno;
}

/**
*\brief Ordena todos los elementos de un array
*\param array Es el array que recibe para ordenar
*\param size Es el tamaño del array
*\param orden Es el numero que indica ordenar de forma ascendente o descendente
*\return Retorna 0 si no retorna -1
*/

int cont_sortName(Contratacion array[],int size,int orden)
{
    int retorno = -1;
    int i;
    int j;

    if(array != NULL && size > 0)
    {

        if(orden == 1)
        {
            retorno = 0;

            for(i=0;i<size;i++)
            {
                for(j=i+1;j<size;j++)
                {
                    if(array[i].cuit == array[j].cuit && strcmp(array[i].cuit,array[j].cuit) > 0)
                    {
                        swap(array+i,array+j);
                    }
                }
            }
        }
        else if(orden == 0)
        {
            retorno = 0;

            for(i=0;i<size;i++)
            {
                for(j=i+1;j<size;j++)
                {
                    if(array[i].cuit == array[j].cuit && strcmp(array[i].cuit,array[j].cuit) < 0)
                    {
                        swap(array+i,array+j);
                    }
                }
            }
        }


    }
    return retorno;
}



int cont_ordenar(Contratacion* array,int limite, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Contratacion auxiliarEstructura;

    if(limite > 0 && array != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                if(!array[i].isEmpty && !array[i+1].isEmpty)
                {
                    if((strcmp(array[i].cuit,array[i+1].cuit) > 0 && orden) || (strcmp(array[i].cuit,array[i+1].cuit) < 0 && !orden)) //******
                    {
                        auxiliarEstructura = array[i];
                        array[i] = array[i+1];
                        array[i+1] = auxiliarEstructura;
                        flagSwap = 1;
                    }
                }
            }
        }while(flagSwap);
    }
    return retorno;
}


/**
*\brief Muestra los datos de un elemento del array
*\param array Es el puntero que recibe del elemento del array
*\param size Es el tamaño del array
*\return Retorna 0 si no retorna -1
*/

int cont_mostrar(Contratacion* array,int size)
{
    int retorno = -1;

    if(array != NULL && size > 0 )
    {
        printf("\n\nCUIT -- %s ",array->cuit);
        printf("\nARCHIVO -- %s",array->cuit);
        printf("\nDIAS -- %d",array->dias);

        retorno = 0;
    }
    return retorno;
}

/**
*\brief Lista los datos de todos los elementos del array
*\param array Es el array que recibe para recorrer
*\param size Es el tamaño del array
*\return Retorna 0 si no retorna -1
*/

int cont_listar(Contratacion array[],int size)
{
    int retorno = -1;
    int i;

    if(array != NULL && size > 0)
    {
        for(i=0;i<size;i++)
        {
            if(!array[i].isEmpty)
            {
                printf("\n\nNOMBRE -- %s",array[i].cuit);
                printf("\nSECTOR -- %s",array[i].cuit);
                printf("\nSALARIO -- %d",array[i].dias);
                printf("\nID -- %d",array[i].id);

                retorno = 0;
            }
        }
    }
    return retorno;
}

/**
*\brief Carga todos los campos de un elemento de un array
*\param array Es el array que recibe para cargar
*\param size Es el tamaño del array
*\param cuit Es el valor del campo cuit
*\param cuit Es el valor del campo cuit
*\param cuit Es el valor del campo cuit
*\param dias Es el valor del campo dias
*\return Retorna 0 si no retorna -1
*/


int cont_altaForzada(Contratacion* array,int size,char* cuit,int idContratacion,int dias, char archivo[])
{
    int retorno = -1;
    int indice;

    if(array != NULL && size > 0)
    {
        retorno = 0;
        indice = cont_buscarIndiceLibre(array,size);
        strncpy(array[indice].cuit,cuit,100);
        strncpy(array[indice].archivo,archivo,100);
        array[indice].dias=dias;
        array[indice].id=generateID();
        array[indice].isEmpty=0;
    }

    return retorno;
}





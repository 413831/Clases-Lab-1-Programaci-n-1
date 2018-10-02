#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utn.h"
#include "pantalla.h"

#define DEFINE_DEL_ARCHIVO  "hola"

//Funciones privadas



/**
*\brief Realiza el swap entre dos elementos
*\param valorA es el puntero del primer elemento
*\param valorB es el puntero del segundo elemento
*\return Retorna void
*/


static void swap(Pantalla* valorA,Pantalla* valorB)
{
    Pantalla auxiliar;//TIPO pantalla
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


int pantalla_mostrarDebug(Pantalla* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            printf("[DEBUG] - %d - %s - %s - %f - %d - %d\n",array[i].id, array[i].nombre,array[i].direccion,array[i].precio,array[i].tipo, array[i].isEmpty);
        }
    }
    return retorno;
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
*\brief Busca el indice libre en un array
*\param array Es el array que reciba para recorrer
*\param size Es el tamaño del array
*\return Retorna el indice del lugar libre si no retorna -1
*/

int pantalla_buscarIndiceLibre(Pantalla array[],int size)
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

int pantalla_init(Pantalla array[],int size,int valor)
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

Pantalla* pantalla_getByID(Pantalla* array,int size,int id)
{
    Pantalla* retorno = NULL;
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

int pantalla_alta(Pantalla* array,int size)
{
    char nombre[50];
    char direccion[50];
    float precio;
    //-----------
    int retorno = -1;
    int indice;

    indice = pantalla_buscarIndiceLibre(array,size);

    if( !input_getLetras(nombre,50,"\nIngrese nombre: ","\nError,dato invalido.",2)&&
        !input_getLetras(direccion,50,"\nIngrese direccion: ","\nError,dato invalido.",2)&&
        !input_getFloat(&precio,7,"\nIngrese el precio: ","\nError,dato invalido.",1000,100000,2))
    {
        strncpy(array[indice].nombre,nombre,50);
        strncpy(array[indice].direccion,direccion,50);
        array[indice].precio = precio;
        array[indice].isEmpty = 0;
        array[indice].id = generateID();//SE PASA ID ASIGNADO A LA ESTRUCTURA
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

int pantalla_modificar(Pantalla* array,int size)
{
   char nombre[50];
    char direccion[50];
    float precio;

    int retorno = -1;

    if(array != NULL && array->isEmpty == 0)
    {

       if( !input_getLetras(nombre,50,"\nIngrese nombre: ","\nError,dato invalido.",2)&&
        !input_getLetras(direccion,50,"\nIngrese direccion: ","\nError,dato invalido.",2)&&
        !input_getFloat(&precio,7,"\nIngrese el precio: ","\nError,dato invalido.",1000,100000,2))
        {
            strncpy(array->nombre,nombre,50);
            strncpy(array->direccion,direccion,50);
            array->precio = precio;
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

int pantalla_eliminar(Pantalla* array,int size)
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

int pantalla_sortName(Pantalla array[],int size)
{
    int retorno = -1;
    int i;
    int j;
    int flag = 1;

    if(array != NULL && size > 0)
    {

        while(flag)
        {
            flag = 0;

            for(i=0;i<size;i++)
            {
                j=i+1;

                 if(array[i].precio < array[i+1].precio)
                {
                     swap(array+i,array+j);
                     flag = 1;
                }
                else if(array[i].precio == array[i+1].precio &&
                strcmp(array[i].nombre,array[i+1].nombre) > 0)
                {
                    swap(array+i,array+j);
                    flag = 1;
                }

            }
        }
        retorno = 0;

    }
    return retorno;
}



int pantalla_ordenar(Pantalla* array,int limite,int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Pantalla auxiliarEstructura;

    if(limite > 0 && array != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                if(!array[i].isEmpty && !array[i+1].isEmpty)
                {
                    if((strcmp(array[i].nombre,array[i+1].nombre) > 0 && orden) ||
                    (strcmp(array[i].nombre,array[i+1].nombre) < 0 && !orden)) //******
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

int pantalla_mostrar(Pantalla* array,int size)
{
    int retorno = -1;

    if(array != NULL && size > 0 )
    {
        printf("\n\nNOMBRE -- %s ",array->nombre);
        printf("\nDIRECCION-- %s",array->direccion);
        printf("\nPRECIO -- $%.2f",array->precio);

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

int pantalla_listar(Pantalla array[],int size)
{
    int retorno = -1;
    int i;

    if(array != NULL && size > 0)
    {
        for(i=0;i<size;i++)
        {
            if(!array[i].isEmpty)
            {
                printf("\n\nNOMBRE -- %s ",array[i].nombre);
                printf("\nDIRECCION -- %s",array[i].direccion);
                printf("\nPRECIO -- %f",array[i].precio);
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
*\param nombre Es el valor del campo nombre
*\param lastName Es el valor del campo lastName
*\param sector Es el valor del campo sector
*\param salary Es el valor del campo salary
*\return Retorna 0 si no retorna -1
*/



int pantalla_ingresoForzado(Pantalla array[],int size,char nombre[],char direccion[],int precio,int tipo)
{
    int retorno = -1;
    int indice;

    if(array != NULL && size > 0)
    {
        retorno = 0;
        indice = pantalla_buscarIndiceLibre(array,size);
        strncpy(array[indice].nombre,nombre,50);
        strncpy(array[indice].direccion,direccion,50);
        array[indice].precio = precio;
        array[indice].isEmpty = 0;
        array[indice].id = generateID();//SE PA
    }

    return retorno;
}


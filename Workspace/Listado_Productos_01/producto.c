#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "producto.h"



static void swap(Producto* elementoA,Producto* elementoB);
static int generateId();
static int producto_buscarLugarVacio(Producto array[],int size);
/////////////////////////////////////////////////////////////////

/**
*\brief Se realiza un swap entre dos valores
*\param elementoA Es el primer elemento para ordenar
*\param elementoA Es el segundo elemento para ordenar
*\return Retorna void
*/

static void swap(Producto* elementoA,Producto* elementoB)
{
    Producto auxiliar;//TIPO ELEMENTO
    auxiliar = *elementoA;
    *elementoA = *elementoB;
    *elementoB = auxiliar;
}

/**
*\brief Se genera un ID unico para una estructura de dato
*\param void
*\return Retorna el ID
*/

static int generateId()
{
    static int id = 0;
    id++;
    return id;
}

/**
*\brief Buscar un lugar vacio en un array
*\param array Es el array que recibe para recorrer
*\param array Es el tamaño del array
*\return Retorna el indice del lugar libre
*/

static int producto_buscarLugarVacio(Producto array[],int size)
{
    int retorno = 1;
    int i;

    for(i=0;i < size; i++)
    {
        if(array[i].isEmpty == 1)
        {
            retorno = i;
            break;
        }

    }
    return retorno;
}

/**
*\brief Inicializa todos los datos de un array en un valor específico
*\param array Es el array que recibe para recorrer
*\param array Es el tamaño del array
*\param value Es el valor que cargamos en el campo 'isEmpty' de la estructura de datos
*\return Retorna 0 si se ejecuta correctamente si no retorna error
*/

int producto_init(Producto array[],int size,int value)
{
    int retorno = -1;
    int i;
    if(array != NULL && size > 0)
    {
        for(i=0;i < size; i++)
        {
            array[i].isEmpty = value;
        }
    retorno = 0;
    }
    return retorno;
}

/**
*\brief Se realiza el alta de todos los campos de un elemento del array
*\param array Es el array que recibe para recorrer
*\param array Es el tamaño del array
*\return Retorna 0 si se realiza el alta si no retorna error
*/

int producto_alta(Producto array[],int size)
{
    char auxNombre[50];
    char auxDescripcion[100];
    char auxPrecio[50];
    int retorno = -1;
    int indice;

    indice = producto_buscarLugarVacio(array,size);

    if(array[indice].isEmpty == 1)
    {
        if( !string_getStringLetras(auxNombre,50,"\n Ingrese el nombre del producto: ","\n Error,nombre invalido.")&&
            !string_getStringLetras(auxDescripcion,100,"\n Ingrese la descripcion: ","\n Error,descripcion invalida.")&&
            !string_getStringFloat(auxPrecio,50,"\n Ingrese el precio: ","\n Error,precio invalido.",0,10000))
        {
            strncpy(array[indice].nombre,auxNombre,50);
            strncpy(array[indice].descripcion,auxDescripcion,100);
            array[indice].precio = atof(auxPrecio);
            array[indice].isEmpty = 0;
            array[indice].ID = generateId();//SE PASA ID ASIGNADO A LA ESTRUCTURA
            retorno = 0;
        }

    }

    return retorno;
}

/**
*\brief Se realiza la modificación de un elemento del array
*\param array Es el array que recibe para recorrer
*\param array Es el tamaño del array
*\return Retorna 0 si se realiza la modificación si no retorna error
*/

int producto_modificar(Producto array[],int size)
{
    char auxNombre[50];
    char auxDescripcion[100];
    char auxPrecio[50];
    int retorno = -1;
    int indice;

    indice = producto_getById(array,size);

    if(array[indice].isEmpty == 0)
    {
        if( !string_getStringLetras(auxNombre,50,"\n Ingrese el nombre del producto: ","\n Error,nombre invalido.")&&
            !string_getStringLetras(auxDescripcion,100,"\n Ingrese la descripcion: ","\n Error,descripcion invalida.")&&
            !string_getStringFloat(auxPrecio,50,"\n Ingrese el precio: ","\n Error,precio invalido.",0,10000) &&
            indice >= 0)
        {
            strncpy(array[indice].nombre,auxNombre,50);
            array[indice].precio = atof(auxPrecio);
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
*\brief Se muestran todos los datos cargados en el array
*\param array Es el array que recibe para recorrer
*\param array Es el tamaño del array
*\return Retorna 0 si se puede listar si no retorna error
*/

int producto_listar(Producto array[],int size)
{
    int retorno = -1;
    int i;

    if(array != NULL && size > 0)
    {
        for(i=0;i < size;i++)
        {
            if(!array[i].isEmpty)
            {
                printf("\n\nPRODUCTO -- %s",array[i].nombre);
                printf("\nDESCRIPCION -- %s",array[i].descripcion);
                printf("\nPRECIO -- $%.2f",array[i].precio);

                retorno = 0;
            }
        }
    }
    return retorno;
}

/**
*\brief Se muestran todos los datos cargados en el array
*\param array Es el array que recibe para recorrer
*\param array Es el tamaño del array
*\return Retorna 0 si se puede listar si no retorna error
*/

int producto_mostrar(Producto array[],int size)
{
    int retorno = -1;
    int indice;

    indice = producto_getById(array,size);

    if(array != NULL && size > 0)
    {
        printf("\n\nPRODUCTO -- %s",array[indice].nombre);
        printf("\nDESCRIPCION -- %s",array[indice].descripcion);
        printf("\nPRECIO -- $%.2f",array[indice].precio);
        retorno = 0;
    }

    return retorno;
}


/**
*\brief Se busca el indice del ID ingresado
*\param array Es el array que recibe para recorrer
*\param array Es el tamaño del array
*\return Retorna el indice del ID ingresado si no retorna error
*/

int producto_getById(Producto array[],int size)
{
    int retorno = -1;
    int i;
    int auxID;

    auxID = input_getInt("\nINGRESE ID: ");//SE PIDE ID A BUSCAR
    if(array != NULL && size > 0 )
    {
        for(i=0;i < size; i++)
        {
            if(!array[i].isEmpty && array[i].ID == auxID)//SE COMPARA ID A BUSCAR CONTRA TODO EL ARRAY
            {
                retorno = i;//SE PASA EL INDICE DEL ID BUSCADO
                break;
            }

        }
    }

    return retorno;
}


/**
*\brief Se realiza la baja de un elemento del array
*\param array Es el array que recibe para recorrer
*\param array Es el tamaño del array
*\return Retorna 0 si se realizo la baja si no retorna error
*/

int producto_baja(Producto array[],int size)
{
    int retorno = -1;
    int indice;

    indice = producto_getById(array,size);

    if(!array[indice].isEmpty)
    {
        if(indice >= 0)
        {
            array[indice].isEmpty = 1;
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
*\brief Se ordena todos los elementos de un array alfabeticamente
*\param array Es el array que recibe para recorrer
*\param array Es el tamaño del array
*\return Retorna 0 si se realizo la baja si no retorna error
*/

int sort_BubbleNombre(Producto* array,int size)
{
    int retorno = -1;
    int i;
    int j;
    if(array != NULL && size > 0)
    {
        for(i=0;i<size;i++)//Ordenamiento por metodo burbuja
        {
            for(j=i+1;j<size;j++)
            {
                if(strcmp(array[i].nombre,array[j].nombre) && array[i].isEmpty != 1)
                {
                   swap(&array[i],&array[j]);
                }
            }
        }
        retorno = 0;
    }
    return retorno;
}

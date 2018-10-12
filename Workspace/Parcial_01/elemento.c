#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "elemento.h"


static void swap(Elemento* valorA,Elemento* valorB);
static int generateId();
static int buscarLugarVacio(Elemento array[],int size);

/**
*\brief Se realiza un swap entre dos valores
*\param elementoA Es el primer elemento para ordenar
*\param elementoA Es el segundo elemento para ordenar
*\return Retorna void
*/

static void swap(Elemento* valorA,Elemento* valorB)
{
    Elemento auxiliar;//TIPO ELEMENTO
    auxiliar = *valorA;
    *valorA = *valorB;
    *valorB = auxiliar;
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

static int buscarLugarVacio(Elemento array[],int size)
{
    int retorno = -1;
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

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/**
*\brief Inicializa todos los datos de un array en un valor específico
*\param array Es el array que recibe para recorrer
*\param array Es el tamaño del array
*\param value Es el valor que cargamos en el campo 'isEmpty' de la estructura de datos
*\return Retorna 0 si se ejecuta correctamente si no retorna error
*/

int elemento_init(Elemento array[],int size,int value)
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
*\brief Se busca un elemento segun el ID recibido por parámetro
*\param array Es el array que recibe para recorrer
*\param array Es el tamaño del array
*\param id Es el numero de id para realizar la busqueda
*\return Retorna la dirección de memoria del elemento buscado sino retorna NULL
*/

Elemento* elemento_getById(Elemento* array, int size,int id)
{
    Elemento* retorno = NULL;
    int i;
    if(array != NULL && size > 0)
    {
        for(i=0;i<size;i++)
        {
            if(!array[i].isEmpty && array[i].id == id)
            {
                retorno = &array[i];
                break;
            }
        }
    }
    return retorno;
}

/**
*\brief Se busca el indice del ID ingresado
*\param array Es el array que recibe para recorrer
*\param array Es el tamaño del array
*\return Retorna el indice del ID ingresado si no retorna error
*/

int elemento_buscarById(Elemento array[],int size)
{
    int retorno = -1;
    int i;
    int auxID;

    auxID = fgetc(stdin); //SE PIDE ID A BUSCAR

    if(array != NULL && size > 0 )
    {
        for(i=0;i < size; i++)
        {
            if(!array[i].isEmpty && array[i].id == auxID)//SE COMPARA ID A BUSCAR CONTRA TODO EL ARRAY
            {
                retorno = i;//SE PASA EL INDICE DEL ID BUSCADO
                break;
            }
        }
    }

    return retorno;
}

/**
*\brief Se realiza el alta de todos los campos de un elemento del array
*\param array Es el array que recibe para recorrer
*\param array Es el tamaño del array
*\return Retorna 0 si se realiza el alta si no retorna error
*/

int elemento_alta(Elemento array[],int size)
{
    char auxNombre[50];
    char auxDescripcion[100];
    char auxPrecio[50];
    int retorno = -1;
    int indice;

    indice = buscarLugarVacio(array,size);

    if(array[indice].isEmpty == 1)
    {
        if( !input_getLetras(auxNombre,50,"\n Ingrese el nombre del elemento: ","\n Error,nombre invalido.",2)&&
            !input_getLetras(auxDescripcion,100,"\n Ingrese la descripcion: ","\n Error,descripcion invalida.",2)&&
            !input_getFloat(auxPrecio,50,"\n Ingrese el precio: ","\n Error,precio invalido.",0,10000,2))
        {
            strncpy(array[indice].nombre,auxNombre,50);//CAMBIAR SEGUN ESTRUCTURA
            strncpy(array[indice].descripcion,auxDescripcion,100);//CAMBIAR SEGUN ESTRUCTURA
            array[indice].precio = atof(auxPrecio);//CAMBIAR SEGUN ESTRUCTURA
            array[indice].isEmpty = 0;
            array[indice].id = generateId();//SE PASA ID ASIGNADO A LA ESTRUCTURA
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

int elemento_modificar(Elemento array[],int size)
{
    char auxNombre[50];
    char auxDescripcion[100];
    char auxPrecio[50];
    int retorno = -1;
    int indice;

    indice = elemento_buscarById(array,size);

    if(array[indice].isEmpty == 0)
    {
        if( !input_getLetras(auxNombre,50,"\n Ingrese el nombre del elemento: ","\n Error,nombre invalido.",2)&&
            !input_getLetras(auxDescripcion,100,"\n Ingrese la descripcion: ","\n Error,descripcion invalida.",2)&&
            !input_getFloat(auxPrecio,50,"\n Ingrese el precio: ","\n Error,precio invalido.",0,10000,2) &&
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
*\brief Se realiza la baja de un elemento del array
*\param array Es el array que recibe para recorrer
*\param array Es el tamaño del array
*\return Retorna 0 si se realizo la baja si no retorna error
*/

int elemento_baja(Elemento array[],int size)
{
    int retorno = -1;
    int indice;

    indice = elemento_buscarById(array,size);

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
*\brief Se muestran todos los datos cargados en el array
*\param array Es el array que recibe para recorrer
*\param array Es el tamaño del array
*\return Retorna 0 si se puede listar si no retorna error
*/

int elemento_listar(Elemento array[],int size)
{
    int retorno = -1;
    int i;

    if(array != NULL && size > 0)
    {
        for(i=0;i < size;i++)
        {
            if(!array[i].isEmpty)
            {
                printf("\n\nelemento -- %s",array[i].nombre);//CAMBIAR SEGUN ESTRUCTURA
                printf("\nDESCRIPCION -- %s",array[i].descripcion);//CAMBIAR SEGUN ESTRUCTURA
                printf("\nPRECIO -- $%.2f",array[i].precio);//CAMBIAR SEGUN ESTRUCTURA

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

int elemento_mostrar(Elemento array[],int size)
{
    int retorno = -1;
    int indice;

    indice = elemento_buscarById(array,size);

    if(array != NULL && size > 0)
    {
        printf("\n\nelemento -- %s",array[indice].nombre);//CAMBIAR SEGUN ESTRUCTURA
        printf("\nDESCRIPCION -- %s",array[indice].descripcion);//CAMBIAR SEGUN ESTRUCTURA
        printf("\nPRECIO -- $%.2f",array[indice].precio);//CAMBIAR SEGUN ESTRUCTURA
        retorno = 0;
    }

    return retorno;
}


/**
*\brief Se ordena todos los elementos de un array alfabeticamente
*\param array Es el array que recibe para recorrer
*\param array Es el tamaño del array
*\return Retorna 0 si se realizo la baja si no retorna error
*/

int sort_BubbleNombre(Elemento* array,int size)
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

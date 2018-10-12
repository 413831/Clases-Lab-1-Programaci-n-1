#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "pantalla.h"


static void swap(Pantalla* valorA,Pantalla* valorB);
static int generateId();
static int buscarLugarVacio(Pantalla array[],int size);

/**
*\brief Se realiza un swap entre dos valores
*\param pantallaA Es el primer pantalla para ordenar
*\param pantallaA Es el segundo pantalla para ordenar
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

static int buscarLugarVacio(Pantalla array[],int size)
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

int pantalla_init(Pantalla array[],int size,int value)
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
*\brief Se busca un pantalla segun el ID recibido por parámetro
*\param array Es el array que recibe para recorrer
*\param array Es el tamaño del array
*\param id Es el numero de id para realizar la busqueda
*\return Retorna la dirección de memoria del pantalla buscado sino retorna NULL
*/

Pantalla* pantalla_getById(Pantalla* array, int size,int id)
{
    Pantalla* retorno = NULL;
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

int pantalla_buscarById(Pantalla array[],int size)
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
*\brief Se realiza el alta de todos los campos de un pantalla del array
*\param array Es el array que recibe para recorrer
*\param array Es el tamaño del array
*\return Retorna 0 si se realiza el alta si no retorna error
*/

int pantalla_alta(Pantalla array[],int size)
{
    char auxNombre[100];
    char auxDireccion[100];
    float auxPrecio;//Precio por dia
    int auxTipo;
    int retorno = -1;
    int indice;

    indice = buscarLugarVacio(array,size);

    if( !input_getAlfanumerico(auxNombre,50,"\nIngrese el nombre de la pantalla: ","\nError,nombre invalido.",2)&&
        !input_getAlfanumerico(auxDireccion,100,"\nIngrese la ubicacion: ","\nError,direccion invalida.",2)&&
        !input_getFloat(&auxPrecio,"\nIngrese el precio: ","\nError,precio invalido.",0,10000,2) &&
        !input_getEnteros(&auxTipo,"\nIngrese tipo de Pantalla : LED '0' o LCD '1': ","\nError. Dato invalido.",0,1,2))
    {
        strncpy(array[indice].nombre,auxNombre,50);//CAMBIAR SEGUN ESTRUCTURA
        strncpy(array[indice].direccion,auxDireccion,100);//CAMBIAR SEGUN ESTRUCTURA
        array[indice].precio = auxPrecio;//CAMBIAR SEGUN ESTRUCTURA
        array[indice].tipo = auxTipo;//CAMBIAR SEGUN ESTRUCTURA
        array[indice].isEmpty = 0;
        array[indice].id = generateId();//SE PASA ID ASIGNADO A LA ESTRUCTURA
        retorno = 0;
    }


    return retorno;
}

/**
*\brief Se realiza la modificación de un pantalla del array
*\param array Es el array que recibe para recorrer
*\param array Es el tamaño del array
*\return Retorna 0 si se realiza la modificación si no retorna error
*/

int pantalla_modificar(Pantalla array[],int size)
{
    char auxNombre[50];
    char auxDireccion[100];
    float auxPrecio;
    int auxTipo;
    int retorno = -1;

    if(array!=NULL)
    {
        if( !input_getAlfanumerico(auxNombre,50,"\nIngrese el nombre de la pantalla: ","\nError,nombre invalido.",2)&&
            !input_getAlfanumerico(auxDireccion,100,"\nIngrese la ubicacion: ","\nError,direccion invalida.",2)&&
            !input_getFloat(&auxPrecio,"\nIngrese el precio: ","\nError,precio invalido.",0,10000,2) &&
            !input_getEnteros(&auxTipo,"\nIngrese tipo de Pantalla : LED '0' o LCD '1': ","\nError. Dato invalido.",0,1,2))
        {
            strncpy(array->nombre,auxNombre,50);//CAMBIAR SEGUN ESTRUCTURA
            strncpy(array->direccion,auxDireccion,100);//CAMBIAR SEGUN ESTRUCTURA
            array->precio = auxPrecio;//CAMBIAR SEGUN ESTRUCTURA
            array->tipo = auxTipo;//CAMBIAR SEGUN ESTRUCTURA
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
*\brief Se realiza la baja de un pantalla del array
*\param array Es el array que recibe para recorrer
*\param array Es el tamaño del array
*\return Retorna 0 si se realizo la baja si no retorna error
*/

int pantalla_baja(Pantalla array[],int size)
{
    int retorno = -1;

        if(array!=NULL)
        {
            array->isEmpty = 1;
            retorno = 0;
        }
        else
        {
           printf("\n\nVACIO");
        }

    return retorno;
}

/**
*\brief Se muestran todos los datos cargados en el array
*\param array Es el array que recibe para recorrer
*\param array Es el tamaño del array
*\return Retorna 0 si se puede listar si no retorna error
*/

int pantalla_listar(Pantalla array[],int size)
{
    int retorno = -1;
    int i;

    if(array != NULL && size > 0)
    {
        for(i=0;i < size;i++)
        {
            if(!array[i].isEmpty)
            {
                printf("\n\nPANTALLA -- %s",array[i].nombre);//CAMBIAR SEGUN ESTRUCTURA
                printf("\nUBICACION -- %s",array[i].direccion);//CAMBIAR SEGUN ESTRUCTURA
                printf("\nVALOR -- $%.2f",array[i].precio);//CAMBIAR SEGUN ESTRUCTURA
                printf("\nID -- %d",array[i].id);//CAMBIAR SEGUN ESTRUCTURA

                if(array[i].tipo == 0)
                        {
                            printf("\nTIPO --  LED");//CAMBIAR SEGUN ESTRUCTURA

                        }
                        else
                        {
                             printf("\nTIPO -- LCD");//CAMBIAR SEGUN ESTRUCTURA
                        }

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

int pantalla_mostrar(Pantalla array[],int size)
{
    int retorno = -1;

    if(array != NULL && size > 0)
    {
        printf("\n\nPANTALLA -- %s",array->nombre);//CAMBIAR SEGUN ESTRUCTURA
        printf("\nUBICACION -- %s",array->direccion);//CAMBIAR SEGUN ESTRUCTURA
        printf("\nPRECIO -- $%.2f",array->precio);//CAMBIAR SEGUN ESTRUCTURA
        if(array->tipo == 0)
        {
            printf("\nTIPO --  LED");//CAMBIAR SEGUN ESTRUCTURA

        }
        else
        {
             printf("\nTIPO -- LCD");//CAMBIAR SEGUN ESTRUCTURA
        }

        retorno = 0;
    }

    return retorno;
}


/**
*\brief Se ordena todos los pantallas de un array alfabeticamente
*\param array Es el array que recibe para recorrer
*\param array Es el tamaño del array
*\return Retorna 0 si se realizo la baja si no retorna error
*/

int pantalla_ordenarNombre(Pantalla* array,int size)
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


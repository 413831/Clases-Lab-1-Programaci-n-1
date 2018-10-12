#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "contrataciones.h"


static void swap(Contratacion* valorA,Contratacion* valorB);
static int generateId();
static int buscarLugarVacio(Contratacion array[],int size);

/**
*\brief Se realiza un swap entre dos valores
*\param contratacionA Es el primer contratacion para ordenar
*\param contratacionA Es el segundo contratacion para ordenar
*\return Retorna void
*/

static void swap(Contratacion* valorA,Contratacion* valorB)
{
    Contratacion auxiliar;//TIPO contratacion
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

static int buscarLugarVacio(Contratacion array[],int size)
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

int contratacion_init(Contratacion array[],int size,int value)
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
*\brief Se busca un contratacion segun el ID recibido por parámetro
*\param array Es el array que recibe para recorrer
*\param array Es el tamaño del array
*\param id Es el numero de id para realizar la busqueda
*\return Retorna la dirección de memoria del contratacion buscado sino retorna NULL
*/

Contratacion* contratacion_getById(Contratacion* array, int size,int id)
{
    Contratacion* retorno = NULL;
    int i;
    if(array != NULL && size > 0)
    {
        for(i=0;i<size;i++)
        {
            if(!array[i].isEmpty && array[i].idContratacion == id)//Busca ID de Pantalla contratada
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

int contratacion_buscarById(Contratacion array[],int size)
{
    int retorno = -1;
    int i;
    char auxCuit[15];

    input_getCuit(auxCuit,15,"\nIngrese CUIT: ","\nError.Dato invalido",2);

    if(array != NULL && size > 0 )
    {
        for(i=0;i < size; i++)
        {
            if(!array[i].isEmpty && array[i].cuitCliente == auxCuit)//SE COMPARA ID A BUSCAR CONTRA TODO EL ARRAY
            {
                retorno = i;//SE PASA EL INDICE DEL ID BUSCADO
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
*\return Devuelve el ID de Pantalla
*/

int contratacion_buscarByCuit(Contratacion array[],int size,char* cuit)
{
    int retorno = -1;
    int i;

    if(array != NULL && size > 0 )
    {
        for(i=0;i < size; i++)
        {
            if(!array[i].isEmpty && array[i].cuitCliente == cuit)//SE COMPARA ID A BUSCAR CONTRA TODO EL ARRAY
            {
                retorno = array[i].idContratacion;//SE PASA EL INDICE DEL ID BUSCADO
                break;
            }
        }
    }

    return retorno;
}


/**
*\brief Se realiza el alta de todos los campos de un contratacion del array
*\param array Es el array que recibe para recorrer
*\param array Es el tamaño del array
*\return Retorna 0 si se realiza el alta si no retorna error
*/

int contratacion_alta(Contratacion array[],int size)
{
    char auxCuitCliente[50];
    int auxDiasContratados;
    char auxNombreArchivo[30];
    int retorno = -1;
    int auxID;
    int indice;

    auxID = fgetc(stdin);//SE PIDE ID DE LA PANTALLA PARA ALQUILAR
    indice = buscarLugarVacio(array,size);//SE BUSCA INDICE PARA DAR ALTA CONTRATACION

    if(array[indice].isEmpty == 1)
    {
        if( !input_getCuit(auxCuitCliente,50,"\n Ingrese el CUIT: ","\n Error,dato invalido.",2)&&
            !input_getEnteros(&auxDiasContratados,"\n Ingrese dias contratados: ","\n Error,precio invalido.",0,10000,2) &&
            !input_getAlfanumerico(auxNombreArchivo,30,"\n Ingrese el nombre del archivo de video: ","\n Error,dato invalido.",2))
        {
            strncpy(array[indice].cuitCliente,auxCuitCliente,50);//CAMBIAR SEGUN ESTRUCTURA
            strncpy(array[indice].nombreArchivo,auxNombreArchivo,30);//CAMBIAR SEGUN ESTRUCTURA
            array[indice].diasContratacion = auxDiasContratados;//CAMBIAR SEGUN ESTRUCTURA
            array[indice].isEmpty = 0;
            array[indice].id = generateId();//SE PASA ID ASIGNADO A LA ESTRUCTURA
            array[indice].idContratacion = auxID;//SE PASA ID DE PANTALLA ALQUILADA
            retorno = 0;
        }

    }

    return retorno;
}

/**
*\brief Se realiza la modificación de un contratacion del array
*\param array Es el array que recibe para recorrer
*\param array Es el tamaño del array
*\return Retorna 0 si se realiza la modificación si no retorna error
*/

int contratacion_modificar(Contratacion array[],int size)
{
    int auxDiasContratados;
    int retorno = -1;
    int auxID;
    Contratacion* auxContratacion;

    auxID = fgetc(stdin);
    auxContratacion = contratacion_getById(array,size,auxID);

    if(auxContratacion!= NULL &&
       !input_getEnteros(&auxDiasContratados,"\n Ingrese dias de contratacion: ","\n Error. Dato invalido.",0,10000,2))
    {
            auxContratacion->diasContratacion = auxDiasContratados;//CAMBIAR SEGUN ESTRUCTURA
            retorno = 0;
    }
    else
    {
            printf("\nCasillero vacio");
    }
    return retorno;
}

/**
*\brief Se realiza la baja de un contratacion del array
*\param array Es el array que recibe para recorrer
*\param array Es el tamaño del array
*\return Retorna 0 si se realizo la baja si no retorna error
*/

int contratacion_baja(Contratacion array[],int size)
{
    int retorno = -1;

    auxID = fgetc(stdin);
    auxContratacion = contratacion_getById(array,size,auxID);

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

int contratacion_listar(Contratacion array[],int size)
{
    int retorno = -1;
    int i;

    if(array != NULL && size > 0)
    {
        for(i=0;i < size;i++)
        {
            if(!array[i].isEmpty)
            {
                printf("\n\nCLIENTE -- %s",array[i].cuitCliente);//CAMBIAR SEGUN ESTRUCTURA
                printf("\n\nDURACION -- %d",array[i].diasContratacion);
                printf("\nPANTALLA -- %d",array[i].id);//CAMBIAR SEGUN ESTRUCTURA

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

int contratacion_mostrar(Contratacion array[],int size)
{
    int retorno = -1;
    int i;
    char auxCuit[15];

    input_getCuit(auxCuit,15,"\nIngrese CUIT: ","\nError.Dato invalido",2);

    if(array != NULL && size > 0)
    {
        for(i=0;i<size;i++)
        {
             if(array->cuitCliente == auxCuit);
            {

                printf("\n\nCLIENTE -- %s",array->cuitCliente);//CAMBIAR SEGUN ESTRUCTURA
                printf("\nPANTALLA -- %d",array->idContratacion);//CAMBIAR SEGUN ESTRUCTURA

                retorno = 0;
            }

        }
    }

    return retorno;
}


/**
*\brief Se ordena todos los contratacions de un array alfabeticamente
*\param array Es el array que recibe para recorrer
*\param array Es el tamaño del array
*\return Retorna 0 si se realizo la baja si no retorna error
*/

int contratacion_ordenarNombre(Contratacion* array,int size)
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
                if(strcmp(array[i].cuitCliente,array[j].cuitCliente) && array[i].isEmpty != 1)//CAMBIAR SEGUN ESTRUCTURA
                {
                   swap(&array[i],&array[j]);
                }
            }
        }
        retorno = 0;
    }
    return retorno;
}


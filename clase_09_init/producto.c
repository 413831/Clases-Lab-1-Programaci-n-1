#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "producto.h"


static void array_swap(Producto* elementoA,Producto* elementoB);
static int getNextId();

static void array_swap(Producto* elementoA,Producto* elementoB)
{
    Producto auxiliar;
    auxiliar = *elementoA;
    *elementoA = *elementoB;
    *elementoB = auxiliar;
}


void producto_initArrayProducto(Producto arrayProducto[],int size,int valor)
{
    int i;
    for(i=0;i < size; i++)
    {
        arrayProducto[i].isEmpty = valor;
    }

}

int producto_altaArray(Producto arrayProducto[],int size)
{
    char auxNombre[50];
    char auxDescripcion[100];
    float auxPrecio;
    int indiceLibre;
    int retorno = -1;

    producto_buscarIndiceArray(arrayProducto,size,&indiceLibre);
    if(arrayProducto[indiceLibre].isEmpty == 1)
    {
        if( !utn_getNombre(auxNombre,50,"\n Ingrese el nombre del producto: ","\n Error,nombre invalido.",2)&&
            !utn_getDescription(auxDescripcion,100,"\n Ingrese la descripcion: ","\n Error,descripcion invalida.",2)&&
            !utn_getNumeroConComa(&auxPrecio,"\n Ingrese el precio: ","\n Error,precio invalido.",0,10000,2))
        {
            strncpy(arrayProducto[indiceLibre].nombre,auxNombre,50);
            strncpy(arrayProducto[indiceLibre].descripcion,auxDescripcion,100);
            arrayProducto[indiceLibre].precio = auxPrecio;
            arrayProducto[indiceLibre].isEmpty = 0;
            arrayProducto[indiceLibre].ID = getNextId();//ALTERNATIVA- SE UTILIZA UN DATO ESTATICO PRECARGADO EN LA FUNCION
            retorno = 0;
        }

    }
    return retorno;
}

int producto_mostrarArray(Producto arrayProducto[],int indice,int size)
{
    int retorno = -1;

    if(arrayProducto != NULL && size > 0 && indice >= 0 && indice < size)
    {
        printf("\n\nPRODUCTO -- %s",arrayProducto[indice].nombre);
        printf("\nDESCRIPCION -- %s",arrayProducto[indice].descripcion);
        printf("\nPRECIO -- $%.2f",arrayProducto[indice].precio);

        retorno = 0;

    }
    return retorno;
}

int producto_buscarIndiceArray(Producto arrayProducto[],int size,int* indiceVacio)
{
    int retorno = 1;
    int i;

    for(i=0;i < size; i++)
    {
        if(arrayProducto[i].isEmpty == 1)
        {
            *indiceVacio = i;
            retorno = 0;
            break;
        }

    }
    return retorno;
}

int producto_IDproducto(Producto arrayProducto[],int size)
{
    int retorno = -1;
    int i;
    int auxID;

    auxID = getInt("\nINGRESE ID: ");//SE PIDE ID A BUSCAR
    printf("\nID ingresado %d", auxID);

    for(i=0;i < size; i++)
    {
        if(arrayProducto[i].ID == auxID)//SE COMPARA ID A BUSCAR CONTRA TODO EL ARRAY
        {
            retorno = i;//SE PASA EL INDICE DEL ID BUSCADO
            break;
        }

    }
    return retorno;
}

int producto_modificarProducto(Producto arrayProducto[],int size)
{
    char auxNombre[50];
    char auxDescripcion[100];
    float auxPrecio;
    int retorno = -1;
    int indiceModificar;

    indiceModificar = producto_IDproducto(arrayProducto,size);


    if(arrayProducto[indiceModificar].isEmpty == 0)
    {
        if( !utn_getNombre(auxNombre,50,"\n Ingrese el nombre del producto: ","\n Error,nombre invalido.",2)&&
            !utn_getDescription(auxDescripcion,100,"\n Ingrese la descripcion: ","\n Error,descripcion invalida.",2)&&
            !utn_getNumeroConComa(&auxPrecio,"\n Ingrese el precio: ","\n Error,precio invalido.",0,10000,2) &&
            indiceModificar >= 0)
        {
            strncpy(arrayProducto[indiceModificar].nombre,auxNombre,50);
            arrayProducto[indiceModificar].precio = auxPrecio;
            retorno = 0;
        }

    }
    else
    {
        printf("\nCasillero vacio");
    }
    return retorno;
}

int producto_eliminarProducto(Producto arrayProducto[],int size)
{
    int retorno = -1;
    int indiceModificar;

    indiceModificar = producto_IDproducto(arrayProducto,size);

    if(arrayProducto[indiceModificar].isEmpty == 0)
    {
        if(indiceModificar >= 0)
        {
            arrayProducto[indiceModificar].isEmpty = 1;
            retorno = 0;
        }
    }
    else
    {
        printf("\nCasillero vacio");
    }
    return retorno;
}


void sort_BubbleNombre(Producto* pArray,int size)
{
    int i;
    int j;
    if(pArray != NULL && size > 0)
    {

        for(i=0;i<size;i++)//Ordenamiento por metodo burbuja
        {
            for(j=i+1;j<size;j++)
            {
                if(strcmp(pArray[i].nombre,pArray[j].nombre) && pArray[i].isEmpty != 1)
                {
                    array_swap(&pArray[i],&pArray[j]);
                }
            }
        }
    }
}



static int getNextId()
{
    static int ultimoId = -1;
    ultimoId++;
    return ultimoId;

}

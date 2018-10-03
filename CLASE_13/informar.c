#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Contratacion.h"
#include "utn.h"
#include "pantalla.h"
#include "informar.h"


int informar_ConsultaFacturacion(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas, char* cuit)
{
    int retorno = -1;

    return retorno;
}




int informar_ListarContrataciones(Pantalla pantallas[],int sizeUno,
              Contratacion contrataciones[], int sizeDos,int lenght)
{
    int retorno = -1;
    int i;
    char listadoCuit[lenght];

    informar_listadoCuit(contrataciones,sizeDos,lenght,listadoCuit);

    if(pantallas != NULL &&
       contrataciones != NULL &&
       sizeUno > 0 &&
       sizeDos > 0)
    {
        for(i=0;i<sizeDos;i++)
        {
            printf("\nCLIENTE %s",listadoCuit+i);
            informar_importePorCuit(pantallas,sizeUno,contrataciones,sizeDos,listadoCuit+i);
        }
        retorno = 0;
    }

    return retorno;
}



int informar_valorPantallas(Pantalla array[],
                                int size,
                                int calculo)
{
    int retorno = -1;
    int i;

    if(array != NULL && size > 0)
    {

        switch(calculo)
        {
            case 1 :
             for(i=0;i<size;i++)
            {
                if(!array[i].isEmpty && array[i].precio <= 10)
                {
                     printf("\n%s",array[i].nombre);
                     printf("\n%s",array[i].direccion);
                     printf("\n$%.2f",array[i].precio);
                     printf("\n%i",array[i].tipo);
                }
            }


            break;

            case 0 :
            for(i=0;i<size;i++)
            {

                if(!array[i].isEmpty && array[i].precio > 10)
                {
                     printf("\n%s",array[i].nombre);
                     printf("\n%s",array[i].direccion);
                     printf("\n$%.2f",array[i].precio);
                     printf("\n%i",array[i].tipo);

                }
            }

            break;

        }
        retorno = 0;
    }


    return retorno;
}

int informar_promedioPantallas(Pantalla array[],
                                int size,
                                int calculo)
{
    int retorno = -1;
    int i;
    float promedio;

    informar_calculoPromedio(array,size,&promedio);

    if(array != NULL && size > 0)
    {

        switch(calculo)
        {
            case 1 :
             for(i=0;i<size;i++)
            {
                if(!array[i].isEmpty && array[i].precio > promedio)
                {
                     printf("\n%s",array[i].nombre);
                     printf("\n%s",array[i].direccion);
                     printf("\n$%.2f",array[i].precio);
                     printf("\n%i",array[i].tipo);
                }
            }
            break;

            case 0 :
            for(i=0;i<size;i++)
            {

                if(!array[i].isEmpty && array[i].precio < promedio)
                {
                     printf("\n%s",array[i].nombre);
                     printf("\n%s",array[i].direccion);
                     printf("\n$%.2f",array[i].precio);
                     printf("\n%i",array[i].tipo);

                }
            }

            break;

        }
        retorno = 0;
    }
    return retorno;
}




int informar_calculoPromedio(Pantalla array[],
                                int size,
                                float* promedio)
{
    int retorno = -1;
    float totalPrecio = 0;
    int contador = 0;
    int i;

    if(array != NULL && size > 0)
    {
        for(i=0;i<size;i++)
        {
            if(!array[i].isEmpty)
            {
                totalPrecio = totalPrecio + array[i].precio;
                contador++;
            }
        }

        *promedio = totalPrecio / contador;
        retorno = 0;
    }

    return retorno;
}

int informar_mostrarPantallas(Pantalla array[],
                                int size,
                                int valor)
{



    float promedio;
    int retorno = -1;
    int i;

    informar_calculoPromedio(array,size,&promedio);

    if(valor == 1)//menor a 10
    {

        for(i=0;i<size;i++)
        {
            if(!array[i].isEmpty && array[i].precio > promedio)
            {
                 printf("\n%s",array[i].nombre);
                 printf("\n%s",array[i].direccion);
                 printf("\n$%.2f",array[i].precio);
                 printf("\n%i",array[i].tipo);
            }
        }
            retorno = 0;
    }
    if(valor == 0)//mayor a 10
    {

        for(i=0;i<size;i++)
        {

            if(!array[i].isEmpty && array[i].precio < promedio)
            {
                 printf("\n%s",array[i].nombre);
                 printf("\n%s",array[i].direccion);
                 printf("\n$%.2f",array[i].precio);
                 printf("\n%i",array[i].tipo);

            }
        }



        retorno = 0;

    }

    return retorno;
}





int informar_diasContratacion(Contratacion arrayUno[],Pantalla arrayDos[],
                                int sizeUno,int sizeDos)
{
    int retorno = -1;
    int i;
    float importeTotal;
    int idPantalla;
    Pantalla* pantallaSeleccionada;

    if(arrayUno != NULL && arrayDos != NULL && sizeUno > 0 && sizeDos > 0)//menor a 10
    {

        for(i=0;i<sizeDos ;i++)
        {
            if(arrayUno[i].dias <= 10)
            {
                importeTotal = 0;

                idPantalla = arrayUno[i].idPantalla;
                pantallaSeleccionada = pantalla_getByID(arrayDos,sizeDos,idPantalla);

                importeTotal = arrayUno[i].dias * arrayDos[i].precio;
                printf("\n\n PANTALLA -- %s",pantallaSeleccionada->nombre);
                printf("\n PRECIO -- $%.2f",pantallaSeleccionada->precio);
                printf("\n DIAS -- %d",arrayUno[i].dias);
                printf("\n IMPORTE TOTAL -- $%.2f",importeTotal);
            }
        }
            retorno = 0;
    }

    return retorno;
}


int informar_importePorCuit(Pantalla arrayUno[],
                            int sizeUno,
                            Contratacion arrayDos[],
                            int sizeDos,
                            char cuit[])
{
    int retorno = -1;
    int i;
    int contador = 0;
    int idPantalla;
    float importe;
    float importeTotal = 0;
    Pantalla* pantallaSeleccionada;

    if(arrayUno != NULL && arrayDos != NULL && cuit != NULL && sizeDos > 0 && sizeUno > 0)
    {
        for(i=0;i<sizeDos;i++)
        {
            if(arrayDos[i].cuit == cuit)
            {
                idPantalla = arrayDos[i].idPantalla;
                pantallaSeleccionada = pantalla_getByID(arrayUno,sizeUno,idPantalla);
                informar_valorContratacion(pantallaSeleccionada,arrayDos+i,&importe);
                importeTotal = importeTotal + importe;
                contador++;+
                printf("\nContratacion %d",arrayDos[i].id);
                printf("\nPantalla %d",arrayDos[i].idPantalla);
                printf("\nImporte $%.2f",importeTotal);
            }
        }
            printf("\nCantidad de contrataciones %d",contador);
            printf("\nImporte total $%.2f",importeTotal);

        retorno = 0;
    }
    return retorno;
}


int informar_listadoCuit(Contratacion array[],int size,int length,char listado[])
{
    int retorno = -1;
    int i;

        for(i=0;i<size;i++)
        {
            if(!array[i].isEmpty && !strcmp(&listado[i],array[i].cuit)!=0)
            {
                listado[i] = array[i].cuit;
            }
        }

    retorno = 0;

    return retorno;
}


int informar_valorContratacion(Pantalla* pantalla,Contratacion* contratacion,float* valor)
{
    int retorno = -1;
    int i;
    float importeTotal;

    if(pantalla != NULL && contratacion != NULL )
    {
        importeTotal = pantalla->precio * contratacion->dias;
        *valor = importeTotal;
        retorno = 0;
    }

    return retorno;
}



int informar_ordenar(Contratacion array[],int size)
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

                 if(array[i].cuit < array[i+1].cuit)
                {
                     swap(array+i,array+j);
                     flag = 1;
                }
                else if(array[i].cuit == array[i+1].cuit &&
                strcmp(array[i].cuit,array[i+1].cuit) > 0)
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


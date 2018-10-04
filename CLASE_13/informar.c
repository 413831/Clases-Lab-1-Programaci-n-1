#include <stdio_ext.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Contratacion.h"
#include "utn.h"
#include "pantalla.h"
#include "informar.h"


static void swap(Contratacion* valorA,Contratacion* valorB)
{
    Contratacion auxiliar;//TIPO pantalla
    auxiliar = *valorA;
    *valorA = *valorB;
    *valorB = auxiliar;
}


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
                                int calculo)//OK
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
                                int calculo)//OK
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
             for(i=0;i<size-1;i++)
            {
                if(!array[i].isEmpty && array[i].precio > promedio)
                {
                     printf("\n%s",array[i].nombre);
                     printf("\n%s",array[i].direccion);
                     printf("\n$%.2f",array[i].precio);
                     printf("\n%d",array[i].tipo);
                }
            }
            break;

            case 0 :
            for(i=0;i<size-1;i++)
            {

                if(!array[i].isEmpty && array[i].precio < promedio)
                {
                     printf("\n%s",array[i].nombre);
                     printf("\n%s",array[i].direccion);
                     printf("\n$%.2f",array[i].precio);
                     printf("\n%d",array[i].tipo);

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
                                float* promedio)//OK
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





int informar_diasContratacion(Contratacion arrayUno[],Pantalla arrayDos[],
                                int sizeUno,int sizeDos)//OK
{
    int retorno = -1;
    int i;
    float importeTotal;
    float importe;
    int contadorCont = 0;
    int idPantalla;
    Pantalla* pantallaSeleccionada;

    if(arrayUno != NULL && arrayDos != NULL && sizeUno > 0 && sizeDos > 0)//menor a 10
    {

        for(i=0;i<sizeUno;i++)
        {
            if(!arrayUno[i].isEmpty && arrayUno[i].dias <= 10)
            {
                printf("\nENTRO IF");
                importe = 0;

                idPantalla = arrayUno[i].idPantalla;
                pantallaSeleccionada = pantalla_getByID(arrayDos,sizeDos,idPantalla);
                contadorCont++;

                importe = arrayUno[i].dias * pantallaSeleccionada->precio;
                importeTotal = importeTotal + importe;

                printf("\n\n PANTALLA -- %s",pantallaSeleccionada->nombre);
                printf("\n PRECIO -- $%.2f",pantallaSeleccionada->precio);
                printf("\n DIAS -- %d",arrayUno[i].dias);
                printf("\n IMPORTE -- $%.2f",importe);
            }
        }
            printf("\nCantidad de contrataciones %d",contadorCont);
            printf("\nImporte total $%.2f",importeTotal);

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
    int contadorCont = 0;
    int idPantalla;
    float importe = 0;
    float importeTotal = 0;
    Pantalla* pantallaSeleccionada;

    if(arrayUno != NULL && arrayDos != NULL && cuit != NULL && sizeDos > 0 && sizeUno > 0)
    {
        for(i=0;i<sizeDos;i++)
        {
            if(!arrayDos[i].isEmpty && arrayDos[i].cuit == cuit)
            {
                idPantalla = arrayDos[i].idPantalla;
                pantallaSeleccionada = pantalla_getByID(arrayUno,sizeUno,idPantalla);
                informar_valorContratacion(pantallaSeleccionada,arrayDos+i,&importe);
                importeTotal = importeTotal + importe;
                contadorCont++;
                printf("\nContratacion %d",arrayDos[i].id);
                printf("\nPantalla %d",arrayDos[i].idPantalla);
                printf("\nImporte $%.2f",importeTotal);
            }


        }



        retorno = 0;
    }
    return retorno;
}


int informar_listadoCuit(Contratacion array[],int size,int length,char listado[])
{
    int retorno = -1;
    int i;
    int j;
    int flag=1;

    while(flag == 1)
    {

        for(i=0;i<size;i++)
        {
            j=i+1;
            flag = 0;

            if(!array[i].isEmpty && strcmp(array[i].cuit,array[j].cuit) != 0 )
            {
                strncpy(listado,array[i].cuit,length);
                flag = 1;
            }
        }

    }

    retorno = 0;

    return retorno;
}


int informar_valorContratacion(Pantalla* pantalla,Contratacion* contratacion,float* valor)
{
    int retorno = -1;
    float importe;

    if(pantalla != NULL && contratacion != NULL )
    {
        importe = pantalla->precio * contratacion->dias;
        *valor = importe;
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


int informar_mostrarPantallas(Pantalla array[],
                                int size,
                                int valor)//REVISAR
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

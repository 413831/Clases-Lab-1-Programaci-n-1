#include <stdio_ext.h>
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



int informar_ListarContrataciones(Contratacion* arrayC,int sizeUno, char CUIT[],int sizeDos,
              Pantalla* pantallas, int lenPantallas)
{
    int retorno = -1;
    int i;
    int idSeleccionado;
    Pantalla* pantallaSelect;
    float importe;


    informar_listadoCuit(arrayC,sizeUno,CUIT,int lenCuit,char arrayCuit[])


    if(arrayC != NULL && CUIT != NULL)
    {
        for(i=0;i<sizeUno;i++)
        {
            if(!strcmp(arrayC[i].cuit,CUIT))
            {
                idSeleccionado = arrayC[i].idPantalla;
                pantallaSelect = pantalla_getByID(pantallas,sizeDos,idSeleccionado);

                precio = pantallaSelect->precio * arrayC[i].dias;
                printf("\nIMPORTE $%.2",importe);
            }

        }


    }



    return retorno;
}


int informar_ListarCantidadContratacionesImporte(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas)
{
    int retorno = -1;

    return retorno;
}



int informar_calculosPantallas(Pantalla array[],
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
            printf("\nENTRO");
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

    informar_promedioPantallas(array,size,&promedio);

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





int informar_calculosContratacion(Contratacion arrayUno[],Pantalla arrayDos[],
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


int informar_listadoCuit(Contratacion array,int size,char clientes[],int lenCuit,char arrayCuit[])
{
    int retorno = -1;
    int i;
    float importeTotal;
    int idPantalla;
    char clientes[sizeDos];


        for(i=0;i<size;i++)
        {
            if(!array[i].isEmpty && !stricmp(array[i].cuit,CUIT,lenCuit))
            {
                clientes[i] = array[i].cuit;
            }

        }

    retorno = 0;


    return retorno;
}




int informar_ordenar(...,array[],int size)
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


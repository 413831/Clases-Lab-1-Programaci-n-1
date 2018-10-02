#include <stdio_ext.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Contratacion.h"
#include "utn.h"
#include "pantalla.h"


int informar_ConsultaFacturacion(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas, char* cuit)
{
    int retorno = -1;

    return retorno;
}



int informar_ListarContrataciones(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas)
{
    int retorno = -1;

    return retorno;
}


int informar_ListarCantidadContratacionesImporte(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas)
{
    int retorno = -1;

    return retorno;
}



Pantalla* informar_calculosPantallas(Pantalla array[],int size,int calculo)
{
    float promedio;
    float totalPrecio;
    int i;


    if(calculo == 1)//menor a 10
    {

            for(i=0;i<size;i++)
            {
                if(array[i].precio <= 10)
                {
                     printf("\n%s",array[i].nombre);
                     printf("\n%s",array[i].direccion);
                     printf("\n$%.2f",array[i].precio);
                     printf("\n%i",tipo;
                }

            }

    }
    if(calculo == 0)//mayor a 10
    {

            for(i=0;i<size;i++)
            {
                if(array[i].precio > 10 )
                {
                     printf("\n%s",array[i].nombre);
                     printf("\n%s",array[i].direccion);
                     printf("\n$%.2f",array[i].precio);
                     printf("\n%i",tipo;

                }

            }

    }






}


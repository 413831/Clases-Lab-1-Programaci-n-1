#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Arrays.h"
#define CANTIDAD_EMPLEADOS 6


int main()
{
    int edades[CANTIDAD_EMPLEADOS] ={50,10,30,50,1,22};
    int i;

    /*for(i=0;i < CANTIDAD_EMPLEADOS;i++)
    {
        if(utn_getEntero(&edades[i],2,"\nEdad?","\nEdad fuera de rango",0,200)==-1)
        {
            edades[i] = DATO_INVALIDO;
        }
    }*/

    array_mostrarArray(edades,CANTIDAD_EMPLEADOS);
    array_minimoDesde(edades,CANTIDAD_EMPLEADOS,2,&i);
    array_ordenar(edades, CANTIDAD_EMPLEADOS,0);
    printf("--%d",i);


    return 0;
}






#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

#define CANTIDAD 5

int main()
{
    printf("Hello world!\n");

    int listadoDeNotas[CANTIDAD];
    int numeroIngresado;//Pedimos un dato y lo ingresamos en el array
    int i = 0;


    for(i=0;i<CANTIDAD;i++)
    {
        printf("\nIngrese nota :");//Se cargan las notas en el array y luego se carga el resultado en la variable para mostrar
        scanf("%d",&numeroIngresado);
        listadoDeNotas[i]=numeroIngresado;
    }

    mostrarInfoArray(listadoDeNotas,CANTIDAD);

    return 0;
}

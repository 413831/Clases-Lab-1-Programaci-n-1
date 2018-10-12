#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

#define CANTIDAD 5

int main()
{
    int listadoDeNotas[CANTIDAD];
    int numeroIngresado;//Pedimos un dato y lo ingresamos en el array
    int i;
    char opcion;

    do
    {
        printf("Hello world!\n");

        for(i=0;i<CANTIDAD;i++)
            {
                printf("\nIngrese nota: ");//Se cargan las notas en el array y luego se carga el resultado en la variable para mostrar
                scanf("%d",&numeroIngresado);
                listadoDeNotas[i]=numeroIngresado;
            }

        mostrarInfoArray(listadoDeNotas,CANTIDAD);
        getchar();
        getCaracter(&opcion,"\n\nContinuar? S/N ");
            while(!(opcion == 'S' || opcion == 's' || opcion == 'N' || opcion == 'n'))
            {
            printf("Ingrese una opcion valida");
            limpiarMemoria();
            getCaracter(&opcion,"\n\nContinuar? S/N ");
            limpiarPantalla();
            }
        limpiarPantalla();

    }while(opcion == 'S' || opcion == 's');


    return 0;
}

#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"
#define LIMITE 5

int main()
{
    int numeros[LIMITE];
    int i;
    int indice;
    int nuevoValor;
    int numeroMayor;



    //pepe[3] - 17;
    for(i=0;i<LIMITE;i++)//Carga secuencial
    {
        __fpurge(stdin);
        //getInt(numeros,i,LIMITE);
        scanf("%d",&numeros[i]);
        printf("Se ingreso el numero en posición %d : %d \n",i,numeros[i]);
    }

    for(i=0;i<LIMITE;i++)//Se muestran los resultados
    {
        printf("Numero en posición %d : %d \n",i,numeros[i]);
    }

    printf("\nIngrese la posicion del array a modificar: ");
    scanf("%d",&indice);



    if(indice <= LIMITE && indice >= 1)
    {
        printf("\nNumer %d", numeros[indice-1]);

        __fpurge(stdin);
        printf("Ingrese el nuevo numero: ");
        scanf("%d",&nuevoValor);

        numeros[indice-1] = nuevoValor;
    }

    numeroMayor = numeros[0];

      for(i=0;i<LIMITE;i++)
      {

        if(numeros[i] > numeroMayor);//Forma 1 de encontrar el numero mayor
        {
            numeroMayor = numeros[i];
        }


        if(i==0);//Forma 2 de encontrar el numero mayor
        {
            numeroMayor = numeros[i];
        }

        /*if(i==LIMITE-1);
        {
            printf("\n ULTIMA VUELTA!");
        }*/

      }

    for(i=0;i<LIMITE;i++)
    {
      array_ordenar(numeros,LIMITE,0);
      printf(&numeros);
    }

    printf("Hello world!\n");
    return 0;
}

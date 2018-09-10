/******************************************************************
*Ejercicio N 5 (Arrays)
*
*Programa con menu:
*1) Cargar datos al array
*2) Mostrar datos del array relacionados a su indice, suma total, promedio, mayor y menor
*3) Opcion de modificar un dato del array
*4) Ordenamiento de todo el array por metodo burbuja
*5) Opcion de salir
*
*Funciones relacionadas a listar,calcular y ordenar datos de un array
*
* *******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

#define CANTIDAD 5 // constante con tamaño del array

int main()
{
    int arrayDeNumeros[CANTIDAD];
    int indiceArray;
    int valorIngresado;
    int opcionMenu = 0;
    int numeroMayor;
    int numeroMenor;
    float totalNumeros = 0;
    float promedio;
    int numeroEncontrado;



    for(indiceArray = 0 ; indiceArray < CANTIDAD ; indiceArray++ )//Se cargan los datos del ARRAY
    {
            arrayDeNumeros[indiceArray] = input_getInt("Ingrese el valor: \n");

            totalNumeros = totalNumeros + arrayDeNumeros[indiceArray];//Se suman los valores del array

            if(indiceArray == 0 || arrayDeNumeros[indiceArray] > numeroMayor )
            {
             numeroMayor = arrayDeNumeros[indiceArray];
            }

            if(indiceArray == 0 || arrayDeNumeros[indiceArray] < numeroMenor)
            {
            numeroMenor = arrayDeNumeros[indiceArray];
            }
    }
    promedio = totalNumeros / CANTIDAD;//Se calcula el promedio de los datos ingresados

    while(opcionMenu != 5)
    {
         opcionMenu = input_getInt("\n1 - Mostrar \n2 - Modificar \n3 - Buscar \n4 - Ordenar \n5 - Salir\n");
         switch(opcionMenu)
         {
            case 1://MOSTRAR LISTADO
                printf("\n\nINDICE - VALOR\n");
                for(indiceArray = 0 ; indiceArray < CANTIDAD ; indiceArray++ )
                {
                    printf("  %d    -   %d \n",indiceArray,arrayDeNumeros[indiceArray]);//Se muestra el INDICE y luego el VALOR guardado en ese INDICE del ARRAY

                }
                printf("\nEl promedio de los numeros ingresados es: %f",promedio);
                printf("\nEl mayor numero ingresado es: %d",numeroMayor);
                printf("\nEl menor numero ingresado es: %d",numeroMenor);
                break;

            case 2://OPCION MODIFICAR
                indiceArray = input_getInt("\nIngrese el indice a modificar: ");//Se ingresa el indice donde se va a modificar el valor
                if(indiceArray >= 0 && indiceArray < CANTIDAD)
                {
                    arrayDeNumeros[indiceArray] = input_getInt("Ingrese el valor: \n");//Se ingresa el valor para modificar el indice
                }
                else
                {
                    printf("\nEl indice ingresado esta fuera de rango!!!!");
                }

                 if(arrayDeNumeros[indiceArray] > numeroMayor )
                {
                 numeroMayor = arrayDeNumeros[indiceArray];
                }

                if(arrayDeNumeros[indiceArray] < numeroMenor)
                {
                numeroMenor = arrayDeNumeros[indiceArray];
                }
                break;
            case 3://OPCION BUSQUEDA
                valorIngresado = input_getInt("Ingrese el numero que desea buscar: \n");
                for(indiceArray=0;indiceArray<CANTIDAD;indiceArray++)
                {
                    if(arrayDeNumeros[indiceArray] == valorIngresado)
                    {
                        numeroEncontrado = valorIngresado;
                        printf("\nNumero encontrado\n INDICE   -   VALOR \n    %d    -    %d",indiceArray,arrayDeNumeros[indiceArray]);
                    }

                }
                if(numeroEncontrado != valorIngresado)
                {
                    printf("\nNumero no encontrado\n");
                }

                break;
            case 4://OPCION ORDENAR
                sort_Bubble(arrayDeNumeros,CANTIDAD);
                printf("\nListado Ordenado\n");
                break;
            default :
                {
                    printf("\nSayonara...");
                }
         } // fin switch
    } // fin while

    return 0;
}


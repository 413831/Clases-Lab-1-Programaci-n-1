#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

#define CANTIDAD_EMPLEADOS 6

//void ordenarArray(char* pNombre,char* pApellido,char* pDni,int limite);
void ordenarArray(char pArray[][50],int limite);

int main()
{
   char nombres[15][50] = {"AAA","EEE","DDD","FFF"};//Cantidad de elementos , cantidad de caracteres
 //   char apellidos[15][50] = {"AAA","BBB","DDD","FFF"};
 //   char dni[15][50] = {"AAA","BBB","DDD","FFF"};
 //   char nombreApellido[100];
   int i;

 /*   for(i=0;i < CANTIDAD_EMPLEADOS;i++)
    {
        utn_getNombre(nombres[i],50,"\nIngrese un nombre: ","\nError.Dato invalido: ",1);
        utn_getNombre(apellidos[i],50,"\nIngrese un apellido: ","\nError.Dato invalido: ",1);
    }
*/
    //nombreApellido = strcat(nombres,apellidos);
    ordenarArray(nombres,CANTIDAD_EMPLEADOS);

    for(i=0;i < CANTIDAD_EMPLEADOS;i++)
    {
        printf("%s \n",nombres[i]);

    }
    return 0;
}

void ordenarArray(char pArray[][50],int limite)
{
    int i;
    int j;
    int aux;
    char bufferStr[256];
    int swap;

    do
    {
        swap = 0;
        for(i=0;i<limite-1;i++)
        {
            j=i+1;
            if(strcmp(pArray[i],pArray[j]) > 0)
            {
                aux = bufferStr[j];
                bufferStr[j] = bufferStr[i];
                bufferStr[i] = aux;
                swap = 1;
            }
        }
    }while(swap);
}





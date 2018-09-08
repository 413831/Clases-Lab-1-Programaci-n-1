#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define SIZE 50


int main()
{
    char myString[SIZE];
    int comparacion;
    int i;
    int enteroValidado = 1;
    int edad;

    strncpy(myString,"pepe", SIZE);
    printf("%s",myString);
    comparacion = strncmp("pepe",myString,SIZE);
    printf("\n %d",comparacion);


    if(!strncmp("pepo",myString,SIZE))
    {}

    printf("\nIngrese su mensaje: ");
    fgets(myString,SIZE, stdin);//array, tamaño, archivo o consola
    printf("%s",myString);


    do
    {
        __fpurge(stdin);
        printf("\nIngrese su edad: ");
        fgets(myString,SIZE, stdin);//array, tamaño, archivo o consola

        for(i=0; i<strlen(myString)-1;i++)//Validacion de strings de números
        {
            if(myString[i] < '0' || myString[i] > '9')
            {
                enteroValidado = -1;
                break;//Porque ya es un ingreso incorrecto
            }
            printf("%c\n",myString[i]);
        }

        if(enteroValidado)// Significa si enteroValidado == 1
        {
            edad = atoi(myString);//Se pasa el string a numero entero
            printf("Mi edad es: %d",edad);
        }

    } while(!enteroValidado);

    return 0;
}

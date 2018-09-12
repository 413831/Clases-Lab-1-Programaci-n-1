#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"


#define LIMITE 200


//ARRAYS
//Ejercicios con arrays


int main()
{
   // char palabra[LIMITE];
    char nombre[10];//El ultimo digito es el \0
    char apellido[10];
    char localidad[10];
    //int tamanio;
   // int usado;
    fgets(nombre,10,stdin);
    __fpurge(stdin);
    fgets(apellido,10,stdin);
    __fpurge(stdin);
    fgets(localidad,10,stdin);
    __fpurge(stdin);

    printf("\n%s%sy vive en la localidad %s ",nombre,apellido,localidad);







/*
    printf("Ingrese un nombre: ");
    scanf("%s",nombre);
    usado = strlen(nombre);
    printf("el nombre ingresado es %s y esta en el espacio de memoria %p",nombre,nombre);

    tamanio = sizeof(nombre); // Se muestra el tamaño en BYTES del array
    printf("\nEl tamanio en bytes es %d",tamanio);//El tamaño coincide con el limite del array
    printf("\nLa cantidad de caracteres usados es %d",usado);
*/


    /*printf("\nIngrese una palabra: ");
    fgets(palabra,LIMITE,stdin);
    printf("Usted ingreso: %s",palabra);
    */

    return 0;
}

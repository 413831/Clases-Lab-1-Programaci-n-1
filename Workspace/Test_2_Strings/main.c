#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

#define LIMITE 30
#define MIN 0
#define MAX 100

int main()
{
    char nombre[LIMITE];
    char edad[LIMITE];

    string_getStringLetras("Ingrese su nombre: ",LIMITE,nombre);
    printf("Su nombre es %s",nombre);
    string_getStringNumeros("\nIngrese su edad: ",LIMITE,edad,MIN,MAX);
    printf("Su nombre es %s",edad);


    return 0;
}

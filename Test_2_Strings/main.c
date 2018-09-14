#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

#define LIMITE 30
#define MIN 1
#define MAX 100

int main()
{
    char nombre[LIMITE];
    char edad[LIMITE];

    string_getStringLetras("\nIngrese su nombre: ","\nError.Intente nuevamente",LIMITE,nombre);
    printf("\nSu nombre es %s",nombre);
    string_getStringNumeros("\nIngrese su edad: ","\nError.Intente nuevamente",LIMITE,edad,MIN,MAX);
    printf("\nSu edad es %s",edad);


    return 0;
}

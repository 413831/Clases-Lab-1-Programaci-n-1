#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"

#define LIMITE 30
#define SUELDO 8








int main()
{
    char edadAux[LIMITE];
    int edad;
    int acumEdad = 0;
    int contador;
    float promedio;
    int i;

    for(i=1;i<4;i++)
    {
    contador = i;
    string_inicializar(edadAux,LIMITE,0);
    string_getStringNumeros("\nIngrese su edad: ","\nError.Dato incorrecto",LIMITE,edadAux,0,100);
    edad = atoi(edadAux);
    acumEdad+=edad;

    printf("\nLA EDAD Nº%d ES: %d",i,edad);
    }

    promedio = acumEdad / contador;

    printf("\nEl total es: %d",acumEdad);
    printf("\nEl promedio es: %f",promedio);

    getchar();

        return 0;
}

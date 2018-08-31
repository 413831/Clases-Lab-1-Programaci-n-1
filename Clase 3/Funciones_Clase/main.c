#include <stdio.h>
#include <stdlib.h>

int pedirEdad(int edad);
int validacionEdad(int edad,int minimo,int maximo);

int main()
{
    int edad;
    edad = pedirEdad(int edad);
    printf("%d",edad);
}

int pedirEdad(int edad)
{
    printf("Ingrese su edad");
    scanf("%d",&edad);
    return edad;
}



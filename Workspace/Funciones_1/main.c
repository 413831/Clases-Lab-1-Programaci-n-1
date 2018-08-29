#include <stdio.h>
#include <stdlib.h>
/*
>Pedir edad por medio de una función
>Validar edad por medio de una función
>Mostrar resultados en función main
*/

int pedirEdad();
int validarEdad();

int main()
{
    int edad;
    int i;

    for(i=0;i<5;i++)
    {

    do{
    edad = validarEdad(pedirEdad());
    }while(edad == -1);

    printf("La edad ingresada es %d \n",edad);
    }
}
int pedirEdad()
{
    int edadIngresada;
    printf("Ingrese su edad: ");
    scanf("%d",&edadIngresada);
    return edadIngresada;
}
int validarEdad(int edad)
{
    int validacion;
    validacion = edad;
    if(validacion >= 1 && validacion <= 100)
    {
        return edad;
    }
    else
    {
        return -1;
    }
}

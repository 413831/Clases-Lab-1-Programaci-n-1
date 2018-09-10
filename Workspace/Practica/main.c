#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"

int main()
{
    int numeros;


    getInt(&numeros);

    if(numeros == 0)
    {
    printf("Error.Dato invalido");
    }
    else
    {
    printf("El numero ingresado es: %d",numeros);
    }


    return 0;
}

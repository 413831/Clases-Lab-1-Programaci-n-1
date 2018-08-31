#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"


int main()
{
    int numero;

        if(utn_getNumero(&numero,"¿Numero?","Error.Ingrese nuevo numero",10,100,2) == 0)//Return == 0
        {
        printf("El numero es: %d",numero);
        }
    return 0;
}





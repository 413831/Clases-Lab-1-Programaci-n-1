#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"
#include "pantalla.h"

#define QTY_PANTALLAS 5
#define QTY_CONTRATACIONES 5

#define NUMERO 100
#define FLOTANTE 100

int main()
{
//Pantalla arrayPantallas[QTY_PANTALLAS];

int numero;
float flotante;

    input_getNumeros(&numero,NUMERO,"\nNUMERO","\nERROR",0,100);
    input_getFloat(&flotante,FLOTANTE,"\nNUMERO","\nERROR",0,100);

    printf("\nNumero UNO %d ",numero);
    printf("\nNumero DOS %f ",flotante);

    printf("Hello world!\n");
    return 0;
}

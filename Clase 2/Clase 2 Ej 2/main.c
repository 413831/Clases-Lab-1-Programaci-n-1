#include <stdio_ext.h>
#include <stdlib.h>

#define LIMITE 5

int main()
{float numero[LIMITE];
int i;
float acumulador = 0;
float promedio;


for(i=0;i<LIMITE;i++)
{
    printf("Ingrese un número \n");

    while(scanf("%f",&numero[i]) != 1)//
    {
       printf("\nError - Numero %d:",i+1);
       __fpurge(stdin);//función para borrar el dato en el buffer, "stdin" ubicación del buffer del teclado
                //fflush(stdin); En Windows
    }
acumulador+=numero[i];

}

promedio = acumulador / LIMITE;
printf("\nEl promedio total es: %f",promedio);

    printf("\nHello world!\n");
    return 0;
}

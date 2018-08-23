#include <stdio.h>
#include <stdlib.h>

#define LIMITE 5

int main()
{int numero[LIMITE];
int i;
int acumulador = 0;
int promedio;


for(i=0;i<LIMITE;i++)
{
    printf("Ingrese un número \n");

    while(scanf("%d",&numero[i]) != 1)//
    {
       printf("\nError - Numero %d:",i+1);
       __fpurge(stdin);//función para borrar el dato en el buffer, "stdin" ubicación del buffer del teclado
                //fflush(stdin); En Windows
    }
acumulador+=numero[i];

}

promedio = acumulador / LIMITE;
printf("\nEl promedio total es: %d",promedio);

    printf("\nHello world!\n");
    return 0;
}

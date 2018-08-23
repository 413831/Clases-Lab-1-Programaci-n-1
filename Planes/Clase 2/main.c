#include <stdio_ext.h>
#include <stdlib.h>

int main()
{//int numeroUno;
//int numeroDos;
//int numeroTres;
int numeroMin;
int numeroMax;
int numero[3];
int i;

for(i = 0;i<3;i++)
{
    printf("\nNumero %d:",i+1);//i = 1 entonces es el primer número
    while(scanf("%d",&numero[i]) != 1)//
    {
        printf("\nError - Numero %d:",i+1);
        __fpurge(stdin);//función para borrar el dato en el buffer, "stdin" ubicación del buffer del teclado
                        //fflush(stdin); En Windows
    }

    if(i==0)
    {
        numeroMax = numero[i];
        numeroMin = numero[i];
    }
    else if(numero[i]>numeroMax)
    {
        numeroMax = numero[i];
    }
    else if(numero[i]<numeroMin)
    {
        numeroMin = numero[i];
    }
}

for(i = 0;i<3;i++)
{

    if(numero[i] > numeroMin && numero[i] < numeroMax)
    {
        printf("Es el numero del medio %d",numero[i]);
        break;
    }
}


return 0;


}











/*printf("Ingrese el primer número :\n");
if(scan("%d",&numeroUno) == 1);
{
printf("%d",numeroUno);
}


while(scanf("%d",&numeroUno) != 1)*
{
printf("\nError - Numero 1:");
__fpurge(stdin);//función para borrar el dato en el buffer, "stdin" ubicación del buffer del teclado
                //fflush(stdin); En Windows
}

numeroMax = numeroUno;
numeroMin = numeroUno;

printf("Ingrese el segundo número : \n");
while(scanf("%d",&numeroDos) != 1)
{
printf("\nError - Numero 2:");
__fpurge(stdin);
}

    if(numeroDos > numeroMax)
    {
    numeroMax = numeroDos;
    }
    else
    {
    numeroMin = numeroDos;
    }


printf("Ingrese el segundo número : \n");
while(scanf("%d",&numeroTres) != 1)
{
printf("\nError - Numero 3:");
__fpurge(stdin);
}

    if(numeroTres > numeroMax)
    {
    numeroMax = numeroTres;
    }
    else if(numeroTres < numeroMin)
    {
    numeroMin = numeroTres;
    }

printf("Número máximo: %d - Número mínimo: %d",numeroMax,numeroMin);



}*/

#include <stdio.h>
#include <stdlib.h>

int main()
{int numeroUno;
int numeroDos;
int numeroTres;
int numeroMax;
int numeroMin;


printf("Ingrese el primer n�mero ");
scanf("%d",&numeroUno);
numeroMax = numeroUno;
numeroMin = numeroUno;

printf("Ingrese el segundo n�mero ");
scanf("%d",&numeroDos);

    if(numeroDos > numeroUno)
    {
    numeroMax = numeroDos;
    }
    else
    {
    numeroMin = numeroDos;
    }

printf("Ingrese el tercer n�mero ");
scanf("%d",&numeroTres);

    if(numeroTres > numeroMax)
    {
    numeroMax = numeroTres;
    }
    else if(numeroTres < numeroMin)
    {
    numeroMin = numeroTres;
    }
    //3      >    2              3    <       5
    // 3     <   5            3        >     2

    if(numeroUno > numeroDos && numeroUno < numeroTres || numeroUno < numeroDos && numeroUno > numeroTres)
    {
        printf("El n�mero del medio es el numero uno: %d \n",numeroUno);

    }
    else if(numeroDos > numeroTres && numeroDos < numeroUno || numeroDos < numeroTres && numeroDos > numeroUno)
    {
             printf("El n�mero del medio es el numero dos: %d \n",numeroDos);
    }
    else
    {
             printf("El n�mero del medio es el numero tres: %d \n",numeroTres);
    }

printf("El numero mayor es: %d \n",numeroMax );
printf("El numero minimo es: %d \n",numeroMin );

}

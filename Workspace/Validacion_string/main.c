#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

#define BUFFER 100


int testValidacion(char* str,int (*validacion)(char* str,int buf));


int main()
{
    int value;
    char testString[10][100] = {"12345","----","aBcDf","....","123abc","abc123","-123","%·%·","4342&%&$","   "};
    int i;
  //  int input(char* mensaje,char* campo,int size, int (*validacion)(char*));
    printf("TEST VALIDACIONES\n\nVALORES DE RETORNO\n (1) Funciona validacion\n (0) No funciona validacion\n");
    printf("\n-Validacion enteros-\n");

    for(i=0;i<10;i++)
    {
        value = testValidacion(testString[i],validacion_Int);
        switch(value)
        {
            case 1 :
                printf("\nACEPTO EL DATO.\n");
                break;
            case 2 :
                printf("\nNO ACEPTO EL DATO.\n");
                break;
        }
    }
    pause();

    return 0;
}


int testValidacion(char* str,int (*validacion)(char* str,int buf))
{
    int retorno = -1;
    int result;

    result = validacion(str,BUFFER);
    printf("\nRETURN >> %d",result);
    if(result == 1)
    {
        retorno = 1;
    }
    else if(result == 0)
    {
        retorno = 2;
    }
    printf("\nEl dato ingresado es >> %s",str);
    return retorno;
}

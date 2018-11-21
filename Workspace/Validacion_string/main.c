#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

#define BUFFER 100
#define RED_BOLD "\033[1;31m"
#define RED      "\033[0;31m"
#define GREEN     "\033[0;32m"
#define GREEN_BLD "\033[1;32m"
#define CYAN_BLD     "\033[1;36m"
#define NORMAL   "\033[0;00m"


int testValidacion(char* str,int (*validacion)(char* str,int buf));


int main()
{
    int value;
    char testString[15][100] = {"47778169","bananas","4numerotelefonico","66563654635","00000202000","    ","\n\n","&%&$·","51231212 ","54 54334543","3.14","03.15",".....","423...","523.43"};
    int i;
  //  int input(char* mensaje,char* campo,int size, int (*validacion)(char*));
    printf("TEST VALIDACIONES\n\nVALORES DE RETORNO\n (1) Funciona validacion\n (0) No funciona validacion\n");
    printf("\n-Validacion DNI-\n");

    for(i=0;i<15;i++)
    {
        value = testValidacion(testString[i],validacion_Telefono);
        switch(value)
        {
            case 1 :
                printf("\n---------------%sACEPTO EL DATO.\n%s",GREEN_BLD,NORMAL);
                break;
            case 2 :
                printf("\n---------------%sNO ACEPTO EL DATO.\n%s",RED_BOLD,NORMAL);
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
    printf("\nEl dato ingresado es >> %s%s%s",CYAN_BLD,str,NORMAL);
    return retorno;
}

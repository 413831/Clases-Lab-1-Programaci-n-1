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
    char testString[15][100] = {"22-12123123-9","22-1212-123-9","abcdefghijk","_1231231231","123123123_","    ","\n\n","&%&$·","11-11234234-8 ","cuitcuitcuit","3.14","03.15","----","abc---","123---"};
    int i;
  //  int input(char* mensaje,char* campo,int size, int (*validacion)(char*));
    printf("TEST VALIDACIONES\n\nVALORES DE RETORNO\n (1) Funciona validacion\n (0) No funciona validacion\n");
    printf("\n-Validacion solo letras-\n");

    for(i=0;i<15;i++)
    {
        value = testValidacion(testString[i],validacion_Cuit);
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

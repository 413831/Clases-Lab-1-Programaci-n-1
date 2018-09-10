#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"


static int validacionInt(char* array);

int utn_getEntero(int* pEdad,int reintentos,char* msg,
                          char*msgErr,int min, int max)
{
    int retorno = -1;
    int auxiliarEdad;

    for(;reintentos > 0;reintentos--)
    {
        printf(msg);
        if(getInt(&auxiliarEdad) == 0)
        {
            if(auxiliarEdad >= min && auxiliarEdad < max)
            {
                *pEdad = auxiliarEdad;
                retorno = 0;
                break;
            }
            else
            {
                printf(msgErr);
            }
        }
        else
        {
            printf(msgErr);
            __fpurge(stdin);
        }
    }
    return retorno;
}


int getInt(int* pResultado)
{
    char buffer[64];
    int retorno = 0;

    printf("Ingrese un enorme numero: ");
    scanf("%s",buffer);
    if(validacionInt(buffer))
    {
    *pResultado = atoi(buffer);
    retorno = 1;
    }


    return retorno;
}

static int validacionInt(char* array)
{
    int retorno = -1;
    int i = 0;

    if(array != NULL)
    {
        while(array[i] != '\0')
        {
            if(array[i]<'0' || array[i]>'0')
            {
                break;
            }
            if(array[i]=='\0')
            {
                retorno = 1;
            }

        }

    }
    return retorno;

}



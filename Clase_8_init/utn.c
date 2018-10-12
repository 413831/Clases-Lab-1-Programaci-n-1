#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "utn.h"
#define BUFFER_GRANDE 4000


static void limpiarMemoria();

static int isValidNombre(char* pBuffer,int limite);

static int getString(char* pBuffer, int limite);



static void limpiarMemoria()
{
    __fpurge(stdin);

}



/**
    utn_getNombre :
    @param
    @param
    @return
*/
static int isValidNombre(char* pBuffer,int limite)
{
    int retorno = 0;
    int i;

    if(pBuffer != NULL && limite > 0)
    {
        retorno = 1;

         for(i=0;i < limite && pBuffer[i] != '\0';i++)//Primero se evalua el limite y luego evalua el \0
         {
            if(tolower(pBuffer[i]) < 'a' || tolower(pBuffer[i])  > 'z')
            {
                retorno = 0;
                break;
            }
         }

    }




    return retorno;
}

/**
    utn_getNombre :
    @param
    @param
    @return
*/
static int getString(char* pBuffer, int limite)
{
    int retorno = -1;
    char bufferStr[BUFFER_GRANDE];
    int lenght;

    if(pBuffer != NULL && limite > 0)
    {
        limpiarMemoria();
        fgets(bufferStr,limite,stdin);//fgets lee archivos, stdin es el archivo textual del flujo de caracteres del teclado
        lenght = strlen(bufferStr);

        if(lenght != limite-1 || bufferStr[limite-2] == '\n')
        {
        bufferStr[lenght-1] = '\0';
        }
        strncpy(pBuffer,bufferStr,limite);
        retorno = 0;
    }
    return retorno;
}


/**
    utn_getNombre :
    @param
    @param
    @return
*/
int utn_getNombre(  char* pNombre,int limite , char* msg,
                    char msgErr[], int reintentos)
{
    int retorno=-1;
    char bufferNombre[BUFFER_GRANDE];

    if(pNombre != NULL && limite > 0 && msg != NULL &&
                    msgErr != NULL && reintentos >= 0)//Si es limite es == a 0 no tiene espacio
    {
        do
        {
            reintentos--;

            printf("%s",msg);
            if(getString(bufferNombre,limite) == 0 &&
               isValidNombre(bufferNombre,limite))//No anidar IF, sumar condiciones.
            {
                strncpy(pNombre,bufferNombre,limite);//Version segura de strcpy
               retorno = 0;
               break;//Busca una estructura repetitiva o un switch
            }
            else
            {
                printf("%s",msgErr);
            }

        }while(reintentos >= 0);// El 0 es por si la cantidad de reintentos es 1 para que itere una vez mas

    }
    return retorno;
}





















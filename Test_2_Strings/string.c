#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
int string_getString(char input[],int size)
{
    int retorno = -1;
    char auxBuffer[size];
    int lenght;

    if(input != NULL && size > 0)
    {
        limpiarMemoria();
        fgets(auxBuffer,size,stdin);
        lenght = strlen(auxBuffer);

        if(lenght != size-1 ||
            auxBuffer[size-2] == '\n')
        {
        auxBuffer[lenght-1] = '\0';
        }

        strncpy(input,auxBuffer,size);
        retorno = 0;
    }



    return retorno;
}


/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int string_getStringLetras(char mensaje[],char mensajeErr[],int size,char input[])
{
    char buffer[size];
    int retorno = -1;

    printf(mensaje);
    string_getString(buffer,size);

    if(validacion_Letras(buffer))
    {
        strncpy(input,buffer,size);//Se copia string cargado a variable local
        retorno = 0;
    }
    else
    {
        printf(mensajeErr);
    }
    return retorno;
}

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param size Es el tamaño del string recibido
 * \param minimo Es el minimo valor permitido para ingresar
 * \param maximo Es el maximo valor permitido para ingresar
 * \param input Array donde se cargará el texto ingresado
 * \return 0 si el string contiene solo números sino retorna error
 */
int string_getStringNumeros(char mensaje[],
                            char mensajeErr[],
                            int size,
                            char input[],
                            int minimo,
                            int maximo)
{
    char buffer[size];
    int retorno = -1;

    printf(mensaje);
    string_getString(buffer,size);

    if(validacion_Int(buffer))
    {
        strncpy(input,buffer,size);//Se copia string cargado a variable del main
        retorno = 0;
    }
    else
    {
        printf(mensajeErr);
    }
    return retorno;
}

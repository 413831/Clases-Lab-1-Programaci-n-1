#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"


/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param size Es el limite del string
 * \param input Array donde se cargará el texto ingresado
 * \return Retorna 1 si es string valido si no retorna 0
 */
int getString(char* mensaje,int size,char* input)
{   int retorno = 0;

    printf("%s",mensaje);
    fgets(input,size,stdin);

    if(strlen(input) != 0)
    {
    retorno = 1;
    }


    return retorno;
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param size Es el limite del string
 * \param input Array donde se cargará el texto ingresado
 * \return Retorna 1 si el texto contiene solo letras
 */
int getStringLetras(char* mensaje,int size,char* input)
{
    char buffer[256];
    int retorno = 0;
    getString(mensaje,size,buffer);
    if(validacion_Nombre(buffer))
    {
        strcpy(input,buffer);
        retorno = 1;
    }
    return retorno;
}

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param size Es el limite del string
 * \param input Array donde se cargará el texto ingresado
 * \return Retorna 1 si el texto contiene solo números
 */
int getStringNumeros(char* mensaje,int size,char* input)
{
    char buffer[256];
    int retorno = 0

    getString(mensaje,size,buffer);
    if(validacion_Int(buffer))
    {
    input = buffer;
    retorno = 1;
    }
    else if(validacion_Float(buffer))
    {
    input = buffer;
    retorno = 1;
    }

    return retorno;
}

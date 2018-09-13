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
void string_getString(char mensaje[],int size,char input[])
{
    printf("%s",mensaje);
    fgets(input,size,stdin);
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int string_getStringLetras(char mensaje[],int size,char input[])
{
    char buffer[size];
    int retorno = 0;
    string_getString(mensaje,size,input);//Se recibe variable a cargar por string

    strcpy(buffer,input);//Se copia string cargado a variable local

    if(validacion_Letras(buffer) == 1)
    {
        retorno = 1;
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
 * \return 1 si el texto contiene solo números
 */
int string_getStringNumeros(char mensaje[],int size,char input[],int minimo,int maximo)
{
    char buffer[size];
    int retorno = 0;

    string_getString(mensaje,size,input);
    strcpy(buffer,input);

    if(validacion_Int(buffer,minimo,maximo) == 1)
    {
        retorno = 1;
    }
    return retorno;
}

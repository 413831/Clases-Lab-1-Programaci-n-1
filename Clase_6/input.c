#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"

/**
 * \brief Solicita un número entero y lo retorna
 * \param *mensaje Es el mensaje para mostrar al usuario
 * \return Entero ingresado por el usuario
 */
int input_getInt(char* mensaje)
{
    int auxiliarInt;
    printf("%s",mensaje);
    scanf("%d",&auxiliarInt);
    return auxiliarInt;
}

/**
 * \brief Solicita un número flotante y lo retorna
 * \param *mensaje Es el mensaje para mostrar al usuario
 * \return Flotante ingresado por el usuario
 */

float input_getFloat(char* mensaje)
{
    float auxiliarFloat;
    printf("%s",mensaje);
    scanf("%f",&auxiliarFloat);
    return auxiliarFloat;
}


/**
 * \brief Solicita un caracter y lo retorna
 * \param *mensaje Es el mensaje para mostrar al usuario
 * \return Caracter ingresado por el usuario
 *
 */
char input_getChar(char* mensaje)
{
    float auxiliarChar;
    printf("%s",mensaje);
    scanf("%f",&auxiliarChar);
    return auxiliarChar;
}

/**
* \brief Modificar el dato de un indice especifico del array
* \param pArray Es el array que recibe para mostrar
* \param pIndice Es puntero del indice del array que recibe para modificar
* \param pSize Es el puntero del tamaño del array
* \param pMensaje Es el puntero del mensaje a mostrar al usuario
* \return Retorna void
*/

void input_modificarArray(int* pArray,int* pIndice,int* pSize,char* pMensaje)
{
    *pIndice = input_getInt("\nIngrese el indice a modificar: ");
    if(pIndice >= 0 && pIndice < pSize)
    {
        pArray[*pIndice] =  input_getInt(pMensaje);
    }
    else
    {
        printf("\nError.Dato fuera de rango.");
    }
}


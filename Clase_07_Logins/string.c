#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void string_getString(char mensaje[],int size, char input[])
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
int string_getStringLetras(char mensaje[],int size,char* input)//FINALIZAR DE CODEAR FINAL MODIFICABLE DE ARRAY
{
    char auxArray[size];
    int retorno = 0;
    int i;
    int sizeArray;

    string_getString(mensaje,size,auxArray);//Pido un string comun
    sizeArray = strlen(auxArray);//Calculo la cantidad de espacios utilizados

    printf("El tamanio del array es: %d",sizeArray);

    while(!(validacion_Nombre(auxArray)))//Valido si es nombre
    {
        printf("\nDato incorrecto\n");
        string_getString(mensaje,size,auxArray);
    }

    for(i=0;i<sizeArray;i++)
    {
    input[i] = auxArray[i];
    printf("\nIteracion numero: %d\n",i);
    }
   // strcpy(input,auxArray);
    printf("FUNCIONA %s",auxArray);
    retorno = 1;
    return retorno;
}

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int string_getStringNumeros(char mensaje[],int size)
{
    char aux[size];
    int retorno = 0;

    string_getString(mensaje,size,aux);
    if(validacion_Int(aux))
    {
        retorno = 1;
    }
    return retorno;
}

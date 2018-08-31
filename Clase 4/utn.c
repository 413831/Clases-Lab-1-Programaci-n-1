#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"

static void myFpurge()
{
    __fpurge(stdin);
    //fflush(stdin);
}

static int getInt(int *numeroIngresado)//se prohibe para uso exlusivo interno
{
    myFpurge();
    return scanf("%d",numeroIngresado);
}

static int getFloat(float *numeroIngresado)
{
    myFpurge();
    return scanf("%f",numeroIngresado);
}

static int getChar(char *caracterIngresado)
{
    myFpurge();
    return scanf("%c",caracterIngresado);
}

static int getString(char textoIngresado[])
{
    myFpurge();
    return scanf("%s",textoIngresado);
}




/**
*\brief Solicita un número al usuario y devuelve el resultado
*\param pResultado Puntero a la variable resultado
*\param mensaje Es el mensaje a ser mostrado
*\param mensajeError Es el mensaje a ser mostrado en caso de error
*\param minimo Es el limite minimo incluido
*\param maximo Es el limite maximo incluido
*\param reintentos ES la cantidad de reingresos de numeros
*\return En caso de exito retorna 0 y en caso de error -1
*/


int utn_getNumero(  int * pResultado,  //dejar el resultado
                char* mensaje,     //mensaje para ingresar
                char* mensajeError,//mensaje de error
                int minimo,        //limite minimo
                int maximo,        //limite maximo
                int reintentos)    //cantidad de intentos
{
    int numeroUsuario;
    int i;

    for(i=reintentos;i>0;reintentos--)
    {
        printf(mensaje);
        getInt(&numeroUsuario);

            if(numeroUsuario >= minimo && numeroUsuario <= maximo)
            {
            *pResultado = numeroUsuario;
            break;
            }
        printf(mensajeError);
    }

    return 0;
}

/**
*\brief Solicito un caracter al usuario
*\param pCaracter Puntero del caracter ingresado
*\param mensaje Es el mensaje para ingresar el caracter
*\param mensajeError Es el mensaje que se muestra al ingresar dato incorrecto
*\param minimo Es el primer caracter disponible para ingresar
*\param maximo Es el último caracter disponible para ingresar
*\param reintentos Es la cantidad de reintentos disponibles
*\return En caso de ser correcto retorna 0 y en caso de error -1
*/

int utn_getCaracter(char *pCaracter,
                    char *mensaje,
                    char *mensajeError,
                    char *minimo,
                    char *maximo,
                    int reintentos)
{
    char auxiliarCaracter;
    int i;


    for(i=reintentos;i>0;reintentos--)
    {
        printf(mensaje);
        getChar(auxiliarCaracter);

            if(auxiliarCaracter > minimo && auxiliarCaracter < maximo)
            {
            *pCaracter = auxiliarCaracter;
            break;
            }
        printf(mensajeError);

    }

    return 0;
}




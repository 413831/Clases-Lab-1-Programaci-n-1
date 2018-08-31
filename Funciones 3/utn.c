#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

/**
*\brief Solicita un número al usuario y dvuelve el resultado
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
        scanf("%d",&numeroUsuario);

            if(numeroUsuario >= minimo && numeroUsuario <= maximo)
            {
            *pResultado = numeroUsuario;
            break;
            }
        printf(mensajeError);
    }

    return *pResultado;
}

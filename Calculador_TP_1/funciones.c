#include <stdio_ext.h>
#include <stdlib.h>
#include "funciones.h"

/**
*\brief Ingresar un caracter por el usuario
*\param caracterAuxiliar Puntero del caracter ingresado
*\return Retorna 0 si es correcto si es incorrecto retorna -1
*/
char getCaracter(char * caracterAuxiliar)
{
    __fpurge(stdin);
    scanf("%c",caracterAuxiliar);
    return 0;

}


int getNumero(int * numeroAuxiliar)
{
    __fpurge(stdin);
    scanf("%d",numeroAuxiliar);
    return 0;
}


int funcionSuma(int auxiliarUno,int auxiliarDos)
{
    int resultado;

    resultado = auxiliarUno + auxiliarDos;
    printf("%d",resultado);
    return resultado;

}

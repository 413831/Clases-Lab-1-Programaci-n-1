#include <stdio_ext.h>
#include <stdlib.h>
#include "funciones.h"

/**
*\brief Ingresar un caracter por el usuario
*\param caracterAuxiliar Puntero del caracter ingresado
*\param mensaje Mensaje que se muestra al usuario para ingresar caracter
*\return Retorna 0 si es correcto si es incorrecto retorna -1
*/
char getCaracter(char * caracterAuxiliar,char * mensaje)
{
    __fpurge(stdin);
    printf(mensaje);
    scanf("%c",caracterAuxiliar);
    return 0;

}

/**
*\brief Ingresar un número por el usuario
*\param numeroAuxiliar Puntero del número ingresado
*\return Retorna 0 si es correcto si es incorrecto retorna -1
*/

int getNumero(int * numeroAuxiliar)
{
    __fpurge(stdin);
    printf("Ingrese un número: ");
    scanf("%d",numeroAuxiliar);
    return 0;
}


/**
*\brief Sumar dos numeros ingresados por el usuario
*\param auxiliarUno Valor del primer numero a sumar
*\param auxiliarDos Valor del segundo numero a sumar
*\return Retorna el resultado de la suma
*/

int funcionSuma(int auxiliarUno,int auxiliarDos)
{
    int resultado;
    __fpurge(stdin);
    resultado = auxiliarUno + auxiliarDos;
    return resultado;

}


/**
*\brief Restar dos numeros ingresados por el usuario
*\param auxiliarUno Valor del primer numero a restar
*\param auxiliarDos Valor del segundo numero a restar
*\return Retorna el resultado de la resta
*/

int funcionResta(int auxiliarUno,int auxiliarDos)
{
    int resultado;
    __fpurge(stdin);
    resultado = auxiliarUno - auxiliarDos;
    return resultado;

}


/**
*\brief Multiplicar dos numeros ingresados por el usuario
*\param auxiliarUno Valor del primer numero a multiplicar
*\param auxiliarDos Valor del segundo numero a multiplicar
*\return Retorna el resultado de la multiplición
*/

int funcionMultiplicar(int auxiliarUno,int auxiliarDos)
{
    int resultado;
    __fpurge(stdin);
    resultado = auxiliarUno * auxiliarDos;
    return resultado;

}


/**
*\brief Dividir dos numeros ingresados por el usuario
*\param auxiliarUno Valor del primer numero a dividir
*\param auxiliarDos Valor del segundo numero a dividir
*\return Retorna el resultado de la división
*/

int funcionDividir(int auxiliarUno,int auxiliarDos)
{
    int resultado;
    __fpurge(stdin);
    resultado = auxiliarUno / auxiliarDos;
    return resultado;

}


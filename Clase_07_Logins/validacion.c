#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utn.h"



/**
 * \brief Genera un número aleatorio
 * \param desde Número aleatorio mínimo
 * \param hasta Número aleatorio máximo
 * \param iniciar Indica si se trata del primer número solicitado 1 indica que si
 * \return retorna el número aleatorio generado
 */

char test_RandomInt(int desde , int hasta, int iniciar)
{
    if(iniciar)
        srand (time(NULL));
    return desde + (rand() % (hasta + 1 - desde)) ;
}

/**
 * \brief Verifica si el string recibido es numérico
 * \param array Es el array para validar su tipo
 * \return 1 si es númerico y 0 si no lo es
 */

int validacion_Int(char* array)
{
   int i=0;
   int retorno = 0;
   while(array != NULL)
   {
       if(array[i] < '0' || array[i] > '9')//Se utiliza el caracter según tabla ASCII
       {
       retorno = 0;
       break;
       }
       else
       {
       retorno = 1;
       array[i] = atoi(array);
       }
       i++;
   }
   return retorno;
}

/**
 * \brief Verifica si el string recibido es de tipo float
 * \param array Es el array para validar su tipo
 * \return 1 si contiene solo un '.' y numeros y 0 si no cumple
 */
int validacion_Float(char* array)
{
   int i=0;
   int retorno = 0;
   int contadorSimbolo = 0;
   while(array != NULL)
   {
       if((array[i] != '.') && (array[i] < 'a' || array[i] > 'z') && (array[i] < 'A' || array[i] > 'Z'))
       {
        retorno = 0;
        break;
       }
       else if(array[i] == '.')
       {
        contadorSimbolo++;
       }
       else
       {
        array[i] = atof(array) ;
       }
       i++;
   }

    if(contadorSimbolo == 1)
    {
     retorno = 1;
    }

   return retorno;
}


/**
 * \brief Verifica si el string recibido tiene solo letras
 * \param array Es el array para validar su tipo
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int validacion_Nombre(char* array)
{
   int i=0;
   int retorno = 0;
   while(array != NULL)
   {
       if((array[i] != ' ') && (array[i] < 'a' || array[i] > 'z') && (array[i] < 'A' || array[i] > 'Z'))
       {
        break;
       }
       else
       {
        retorno = 1;
       }
       i++;
   }
   return retorno;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param array Es el string para validar el tipo
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 *
 */
int validacion_AlfaNumerico(char* array)
{
   int i=0;
   int retorno = 0;
   while(array != NULL)
   {
       if((array[i] != ' ') && (array[i] < 'a' || array[i] > 'z') && (array[i] < 'A' || array[i] > 'Z') && (array[i] < '0' || array[i] > '9'))
       {
        retorno = 0;
        break;
       }
       else
       {
        retorno = 1;
       }
       i++;
   }
   return retorno;
}

/**
 * \brief Verifica si el string recibido es un numero de telefono valido
 * \param array Es el string recibido para ser validado
 * \return 1 si contiene solo numeros, espacios y un guion.
 *
 */
int validacion_Telefono(char* array)
{
   int i=0;
   int contadorSimbolo = 0;
   int retorno = 0;
   while(array != NULL)
   {
       if((array[i] != ' ') && (array[i] != '-') && (array[i] != '+') && (array[i] < '0' || array[i] > '9'))
       {
        retorno = 0;
        break;
       }
       else if(array[i] == '-' || array[i] == '+')
       {
        contadorSimbolo++;
       }

       i++;
   }
   if(contadorSimbolo <= 2) // Se acepta hasta dos simbolos
   {
    retorno = 1;
   }

    return retorno;
}

/**
 * \brief Verifica si el string recibido es un numero de dni valido
 * \param array Es el string recibido para ser validado
 * \return 1 si contiene solo numeros, espacios y un guion.
 *
 */
int validacion_DNI(char* array)
{
   int i=0;
   int contadorSimbolo = 0;
   int retorno = 0;
   while(array != NULL)
   {
       if((array[i] != '.') && (array[i] < '0' || array[i] > '9'))
       {
        retorno = 0;
        break;
       }
       else if(array[i] == '.')
       {
        contadorSimbolo++;
       }

       i++;
   }
   if(contadorSimbolo == 2 || contadorSimbolo == 0) // Se acepta dos simbolos o ningun simbolo
   {
    retorno = 1;
   }

    return retorno;
}

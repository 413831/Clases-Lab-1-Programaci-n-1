#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

#define LIMITE 30

int main()
{
    char nombre[LIMITE];

//  string_getString("Ingrese su nombre ",LIMITE,nombre);
//  validacion = validacion_Nombre(nombre);

    string_getStringLetras("Ingrese su nombre: ",LIMITE,nombre);

//  printf("\nLa validacion dio: %d",validacion);
    printf("\nEl nombre ingresado es: %s",nombre);

  /*char usuario[6];
    char clave[9];
    char auxUsuario[]="admin\n";
    char auxClave[]="1234\n";
    int tamanio;
    int retorno;

    printf("Ingrese usuario:\n");
    fgets(usuario,16,stdin);
    __fpurge(stdin);
    printf("Ingrese clave:\n");
    fgets(clave,9,stdin);
    __fpurge(stdin);

    retorno = strlen(usuario);
    printf("Tamanio de usuario %d",retorno);
    printf("\nUsuario: %s Clave: %s",usuario,clave);

    tamanio = strcmp(usuario,clave);
    printf("\n%d\n",tamanio);


    if(strcmp(usuario,auxUsuario)==0 && strcmp(clave,auxClave)==0)//El strcmp compara bytes
    {
        printf("Usuario correcto");
    }
    else
    {
    printf("Error");
    }


    */

    return 0;
}

#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"
#include "person.h"

int funcion(void)//"funcion" representa a una direccion de memoria, funcion() llama a lo que contiene la direccion
{
    return 7;
}

void funcionClientes(Cliente array[],int size)
{

}

void funcionRecibeF(int (*pepe)(void))//Se arma la funcion dentro del argumento y se pasa su direccion
{
    pepe();
    printf("puntero desde funcion: %p\n",pepe);
    printf("puntero desde funcion: %d\n",pepe());
}

int main()
{
    printf("%p\n",funcion);
    funcionRecibeF(funcion);

    return 0;
}

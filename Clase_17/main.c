#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"
#include "person.h"

#define QTY_PERSON 5

int funcion(void)//"funcion" representa a una direccion de memoria, funcion() llama a lo que contiene la direccion
{
    return 7;
}

void funcionPerson(Person array[],int size)
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
    Person* arrayPerson[QTY_PERSON];//Array de punteros de la estructura

    Person* personita;
  //  printf("%p\n",funcion);
  //  funcionRecibeF(funcion);

    person_constructor(&personita);//Para reservar memoria de una estructura
    person_initArray(personita,1);//Para inicializar un elemento de la estructura
    person_constructor(arrayPerson);


    return 0;
}

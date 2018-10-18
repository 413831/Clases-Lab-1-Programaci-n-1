#include <stdio_ext.h>
#include <stdlib.h>
#include "person.h"



/**
*\brief Crear array dinamico con funcion malloc
*\param array Es el puntero de la direccion de memoria del array
*\param size Es el limite del array
*\return Retorna 0 si el puntero es diferente a NULL y el size valido sino retorna -1
*/

int person_constructor(Person** person)
{
    int retorno = -1;
    Person* auxPerson = NULL;

        auxPerson = (Person*)malloc(sizeof(Person)*1);//Reserva lugar para n variables tipo person
        if(auxPerson != NULL)
        {
            *person = auxPerson;
            printf("\nCONSTRUYO");
            retorno = 0;
        }

    return retorno;
}


/**
*\brief Inicializar array dinamico
*\param array Es el puntero que recibe para inicializar
*\param size Es el limite de datos
*\param value Es el valor para inicializar
*\return Retorna 0 si el puntero es diferente a NULL y el size valido sino retorna -1
*/

int person_initArray(Person* person,int value)
{
    int retorno = -1;
    Person auxPerson;

    if(person != NULL)
    {
        auxPerson.isEmpty = value;//Primero el puntero se desplaza i veces, luego accede y guarda
        auxPerson.id = generateID();
        printf("\nINICIALIZO");
        *person = auxPerson;
        retorno = 0;
    }
    return retorno;
}


/**
*\brief Muestra datos del array dinamico
*\param array Es el puntero que recibe para mostrar
*\param size Es el limite de datos
*\return Retorna 0 si el puntero es diferente a NULL y el size valido sino retorna -1
*/


int person_showArray(Person* person)
{
    int retorno = -1;

    if(person != NULL)
    {
        printf("\nESTADO %d -- DIR MEMORIA %p",person->isEmpty,person);
        printf("\nID %d",person->id);
    }
    return retorno;
}

/**
*\brief Borrar un array dinamico con funcion free
*\param array Es el puntero que recibe para liberar
*\return Retorna 0 si el puntero es diferente a NULL sino retorna -1
*/

int person_destructor(Person* array)
{
    int retorno = -1;

    if(array != NULL)
    {
        free(array);
        retorno = 0;
    }
    return retorno;
}


/**
*\brief Relocaliza un array dinamico con funcion realloc
*\param array Es el puntero de la direccion de memoria del array
*\param newsize Es el nuevo limite del array
*\return Retorna 0 si el puntero es diferente a NULL y el newsize valido sino retorna -1
*/

int person_resizeArray(Person** array,int newsize)
{
    int retorno = -1;
    Person* auxArray;

    if(array != NULL && newsize > 0)
    {
        auxArray = (Person*)realloc(*array,sizeof(Person)*newsize);//Reserva lugar para n variables tipo int
        if(auxArray != NULL)
        {
            *array = auxArray;
            retorno = 0;
        }
    }
    return retorno;
}

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "person.h"
#include "utn.h"


int person_getName(Person* person)
{
    char* auxName;

    if(person != NULL)
    {
   //     input_getLetras(auxName,sizeof(person->name),"\nIngrese nombre","Error.Dato invalido",2);
        auxName = fgets("\nIngrese nombre",20,stdin);

        strncpy(person->name,auxName,sizeof(person->name));
        return 0;
    }
    return 1;
}



int person_setName(Person* person)
{
    int retorno = -1;
    Person* auxPerson;

    if(person != NULL)
    {
        person_getName(auxPerson);

        printf("\nSETEO NAME");
        strncpy(person->name,auxPerson->name,sizeof(person->name));
        retorno = 0;
    }
    return retorno;

}



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
*\param value Es el valor para inicializar
*\return Retorna 0 si el puntero es diferente a NULL y el size valido sino retorna -1
*/

int person_initArray(Person* person,int value)
{
    int retorno = -1;
    Person* auxPerson;

    if(person != NULL)
    {
        auxPerson->isEmpty = value;//Primero el puntero se desplaza i veces, luego accede y guarda
        auxPerson->id = generateID();
        auxPerson->age = 16;

      //  person_setName(auxPerson);

        printf("\nINICIALIZO");
        person = auxPerson;
        retorno = 0;
    }
    return retorno;
}



int person_setAge(Person* person)
{


    return 0;
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
        printf("\nNAME %s",person->name);
        printf("\nAGE %d",person->age);
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


/**
*\brief Cargar array dinamico
*\param array Es el puntero que recibe para inicializar
*\return Retorna 0 si el puntero es diferente a NULL y el size valido sino retorna -1
*/

int person_cargar(Person* person)
{
    int retorno = -1;
    Person* auxPerson;

    person_constructor(&auxPerson);

    if(person != NULL)
    {
        input_getLetras(auxPerson->name,20,"\nIngrese nombre: ","\nError dato invalido",2);
        input_getLetras(auxPerson->lastName,20,"\nIngrese apellido: ","\nError dato invalido",2);
        input_getNumeros(&auxPerson->age,3,"\nIngrese edad: ","\nError dato invalido",0,100,2);
        input_getAlfanumerico(auxPerson->adress,20,"\nIngrese direccion: ","\nError dato invalido",2);
        auxPerson->id = generateID();
        printf("\nINICIALIZO");

        person = auxPerson;
        person_destructor(auxPerson);

        retorno = 0;
    }
    return retorno;
}

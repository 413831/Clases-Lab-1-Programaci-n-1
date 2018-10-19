#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "person.h"
#include "utn.h"




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

#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"
#include "person.h"


int generateID()
{
    static int id = 0;
    id++;
    return id;
}


int person_create(Person** person)//Recibe puntero a puntero persona o direccion de memoria de puntero
{
    int retorno = -1;
    Person* auxPerson = NULL;

    printf("\n\nDIR PERSONA %p",*person);
    auxPerson = *person;//copio direccion de memoria de puntero a puntero auxiliar

    printf("\n\nDIR PERSONA COPIA %p",auxPerson);
    person_constructor(&auxPerson);//paso direccion de memoria de puntero auxiliar recibo direccion de memoria disponible

    printf("\n\nDIR PERSONA COPIA %p",auxPerson);
    person_initArray(auxPerson,200);

    retorno = 0;

    *person = auxPerson;//retorno nueva memoria asignada a lo apuntado por puntero a puntero persona
    printf("\n\nDIR PERSONA %p",*person);
    return retorno;
}


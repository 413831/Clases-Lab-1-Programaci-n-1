#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"
#include "person.h"

static int isValidName(char* name)
{

    return 1;
}


int generateID()
{
    static int id = 0;
    id++;
    return id;
}


int person_create(Person** person)//Recibe puntero a puntero persona o direccion de memoria de puntero
{
    int retorno = -1;
    int age;
    char* name;
    Person* auxPerson;

    auxPerson = (Person*) malloc(sizeof(Person));
    if(auxPerson != NULL)
    {
        input_getLetras(name,30,"\nIngrese nombre","Error.Dato invalido",2);
        input_getNumeros(&age,3,"\nIngrese edad","Error.Dato invalido",0,100,2);
        person_init(auxPerson,name,age);
        retorno = 0;
    }



    return retorno;
}



int person_init(Person* person,char* name,int age)
{
    int retorno = -1;

    if(person != NULL)
    {
        strcpy(person->name,name);
        person->age = age;
        retorno = 0;
    }

    return retorno;
}

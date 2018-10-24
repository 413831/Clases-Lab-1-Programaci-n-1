#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "person.h"

static int isValidName(char* name)
{
    int retorno = 0;

    if(name != NULL && strlen(name) < 30  && strlen(name) > 1)
    {
        retorno = 1;
    }
    return retorno;
}

static int isValidLastName(char* lastName)
{
    int retorno = 0;

    if(lastName != NULL && strlen(lastName) < 30 && strlen(lastName) > 1)
    {
        retorno = 1;
    }
    return retorno;
}

static int isValidAge(int age)
{
    int retorno = 0;

    if(age > 0 && age < 100)
    {
        retorno = 1;
    }
    return retorno;
}

static int isValidAdress(char* adress)
{
    int retorno = 0;

    if(adress != NULL && strlen(adress) > 2)
    {
        retorno = 1;
    }
    return retorno;
}

int generateID()
{
    static int id = 0;
    id++;
    return id;
}

////////////////////////////////////////////////////////////////////////////////////

/**
* Inicializa un array de punteros Cliente en NULL
*/

int person_init(Person* person[],int size)
{
    int retorno = -1;
    int i;

    if(person != NULL && size > 0)
    {
        for(i=0;i<size;i++)
        {
            person[i] = NULL;//Seteo a todo el array en NULL
            retorno = 0;
        }
    }
    return retorno;
}

/**
* Busco lugar libre en el array
*/

int person_searchEmpty(Person* array[], int size)
{
    int i;
    int retorno =-1;
    if(array!=NULL && size > 0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i]==NULL)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

/**
*\brief Reserva un espacio en memoria para un elemento
*\param array Es el puntero que recibe para reservar espacio
*\return Retorna 0 si el puntero es diferente a NULL sino retorna -1
*/

int person_constructor(Person** this)
{
    int retorno = -1;
    Person* aux = NULL;

    aux=(Person*)malloc(sizeof(Person));//Reserva lugar para 1 elemento tipo person
    if(aux!=NULL)
    {
        aux->id = generateID();
        aux->status = 1;
        *this=aux;
        printf("\nCONSTRUYO");
        printf("\nPUNTERO AUX %p",aux);
        printf("\nPUNTERO THIS %p",this);
        retorno = 0;
    }
    return retorno;
}

/**
* Seteo campo name
*/

int person_setName(Person* this,char* name)
{
    int retorno = -1;

    if(this!=NULL && isValidName(name))
    {
        strncpy(this->name,name,30);
        retorno = 0; // todo bien
    }
    return retorno;
}

/**
* Get campo name
*/

int person_getName(Person* this,char* name)
{
    int retorno = -1;

    if(this!=NULL && name != NULL)
    {
        strncpy(name,this->name,20);
        retorno = 0; // todo bien
    }
    return retorno;
}

/**
* Seteo campo lastName
*/

int person_setLastName(Person* this,char* lastName)
{
    int retorno = -1;

    if(this!=NULL && isValidLastName(lastName))
    {
        strncpy(this->lastName,lastName,30);
        retorno = 0; // todo bien
    }
    return retorno;
}

/**
* Get campo lastName
*/

int person_getlastName(Person* this,char* lastName)
{
    int retorno = -1;

    if(this!=NULL && lastName!= NULL)
    {
        strncpy(lastName,this->lastName,30);
        retorno = 0; // todo bien
    }
    return retorno;
}


/**
*\brief Libera la direccion de memoria del puntero recibido
*\param array Es el puntero que recibe para liberar
*\return Retorna 0 si el puntero es diferente a NULL sino retorna -1
*/

int person_destructor(Person* this)
{
    int retorno = -1;

    if(this!=NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

/**
*\brief Busca un elemento por ID
*\param array Es el puntero que recibe para realizar la busqueda
*\param size Es el límite del array
*\param id Es el ID del elemento a buscar
*\return Retorna el puntero del elemento sino retorna NULL
*/

Person* person_getById(Person* array[],int size,int id)
{
    int i;
    Person* retorno=NULL;

    if(array!=NULL && size > 0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i]->id==id)
            {
                retorno = *(array+i);
                break;
            }
        }
    }
    return retorno;
}


/**
*\brief Muestra datos del array dinamico
*\param array Es el puntero que recibe para mostrar
*\param size Es el limite de datos
*\return Retorna 0 si el puntero es diferente a NULL y el size valido sino retorna -1
*/

int person_showArray(Person* this)
{
    int retorno = -1;

    if(this != NULL)
    {
        printf("\nNAME %s",this->name);
        printf("\nAGE %d",this->age);
        printf("\nESTADO %d -- DIR MEMORIA %p",this->status,this);
        printf("\nID %d",this->id);
    }
    return retorno;
}

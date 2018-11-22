

********************* Person.c ************************

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "utn.h"
#include "Person.h"
#include "parser.h"
#include "controller.h"

Person* person_constructor(char* name,char* lastName,int age,char* address,int id)
{
	Person* this = malloc(sizeof(Person));

	if(this != NULL)
	{
		if(	!person_setName(this,name) &&
			!person_setLastName(this,lastName) &&
			!person_setAge(this,age) &&
			!person_setAddress(this,address) &&
			!person_setId(this,id) &&
			)
		{
			return this;
		}
		else
		{
			person_destructor(this);
			return NULL;
		}
	}
}

int person_destructor(Person* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		free(this);
		retorno = 0;
	}
	return retorno;
}

int person_setName(Person* this,char* name)
{
	int retorno = -1;
	if(this != NULL && name != NULL)
	{
		strcpy(this->name,name);
		retorno = 0;
	}
	return = retorno;
}

int person_setLastName(Person* this,char* lastName)
{
	int retorno = -1;
	if(this != NULL && lastName != NULL)
	{
		strcpy(this->lastName,lastName);
		retorno = 0;
	}
	return = retorno;
}

int person_setAge(Person* this,int age)
{
	int retorno = -1;
	if(this != NULL)
	{
		this->age = age;
		retorno = 0;
	}
	return = retorno;
}

int person_setAddress(Person* this,char* address)
{
	int retorno = -1;
	if(this != NULL && address != NULL)
	{
		strcpy(this->address,address);
		retorno = 0;
	}
	return = retorno;
}

int person_setId(Person* this,int id)
{
	int retorno = -1;
	if(this != NULL)
	{
		this->id = id;
		retorno = 0;
	}
	return = retorno;
}

char* person_getName(Person* this)
{
	char* retorno = NULL;
	if(this != NULL)
	{
		strcpy(retorno,this->name);
	}
	return = retorno;
}

char* person_getLastName(Person* this)
{
	char* retorno = NULL;
	if(this != NULL)
	{
		strcpy(retorno,this->lastName);
	}
	return = retorno;
}

int person_getAge(Person* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		retorno = this->age;
	}
	return = retorno;
}

char* person_getAddress(Person* this)
{
	char* retorno = NULL;
	if(this != NULL)
	{
		strcpy(retorno,this->address);
	}
	return = retorno;
}

int person_getId(Person* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		retorno = this->id;
	}
	return = retorno;
}

Person* person_getByName(LinkedList* pArray,char* name)
{
	int i;
	Person* aux;
	Person* retorno=NULL;
	for(i=0;i<ll_len(pArray);i++)
	{
		aux = ll_get(pArray,i);
		if(strcmp(name,person_getName(aux))==0)
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}

Person* person_getByLastName(LinkedList* pArray,char* lastName)
{
	int i;
	Person* aux;
	Person* retorno=NULL;
	for(i=0;i<ll_len(pArray);i++)
	{
		aux = ll_get(pArray,i);
		if(strcmp(lastName,person_getLastName(aux))==0)
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}

Person* person_getByAge(LinkedList* pArray,int age)
{
	int i;
	Person* aux;
	Person* retorno=NULL;
	for(i=0;i<ll_len(pArray);i++)
	{
		aux = ll_get(pArray,i);
		if(age == person_getAge(aux))
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}

Person* person_getByAddress(LinkedList* pArray,char* address)
{
	int i;
	Person* aux;
	Person* retorno=NULL;
	for(i=0;i<ll_len(pArray);i++)
	{
		aux = ll_get(pArray,i);
		if(strcmp(address,person_getAddress(aux))==0)
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}

Person* person_getById(LinkedList* pArray,int id)
{
	int i;
	Person* aux;
	Person* retorno=NULL;
	for(i=0;i<ll_len(pArray);i++)
	{
		aux = ll_get(pArray,i);
		if(id == person_getId(aux))
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}

int person_compareByName(void* thisA ,void* thisB)
{
	int retorno = 0;

	if(thisA != NULL && thisB != NULL)
	{
		retorno = strcmp(person_getName(thisA),person_getName(thisB));
	}
	return retorno;
}

int person_compareByLastName(void* thisA ,void* thisB)
{
	int retorno = 0;

	if(thisA != NULL && thisB != NULL)
	{
		retorno = strcmp(person_getLastName(thisA),person_getLastName(thisB));
	}
	return retorno;
}

int person_compareByAge(void* thisA ,void* thisB)
{
	int retorno = 0;

	if(thisA != NULL && thisB != NULL)
	{
		if(person_getAge(thisA) > person_getAge(thisB))
		{
				retorno = 1;
		}
		else if(person_getAge(thisA) < person_getAge(thisB))
		{
			retorno = -1;
		}
	}
	return retorno;
}

int person_compareByAddress(void* thisA ,void* thisB)
{
	int retorno = 0;

	if(thisA != NULL && thisB != NULL)
	{
		retorno = strcmp(person_getAddress(thisA),person_getAddress(thisB));
	}
	return retorno;
}

int person_compareById(void* thisA ,void* thisB)
{
	int retorno = 0;

	if(thisA != NULL && thisB != NULL)
	{
		if(person_getId(thisA) > person_getId(thisB))
		{
				retorno = 1;
		}
		else if(person_getId(thisA) < person_getId(thisB))
		{
			retorno = -1;
		}
	}
	return retorno;
}



********************* Person.c ************************




********************* Employee.c ************************

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "utn.h"
#include "Employee.h"
#include "parser.h"
#include "controller.h"

Employee* employee_new(int id,char* name,char* lastName,int age,int type)
{
	Employee* this = malloc(sizeof(Employee));

	if(this != NULL)
	{
		if(	!employee_setId(this,id) &&
			!employee_setName(this,name) &&
			!employee_setLastName(this,lastName) &&
			!employee_setAge(this,age) &&
			!employee_setType(this,type) &&
			)
		{
			return this;
		}
		else
		{
			employee_delete(this);
	\ttreturn NULL;
		}
	}
}

int employee_delete(Employee* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		free(this);
		retorno = 0;
	}
	return retorno;
}

int employee_setId(Employee* this,int id)
{
	int retorno = -1;
	if(this != NULL)
	{
		this->id = id;
		retorno = 0;
	}
	return = retorno;
}

int employee_setName(Employee* this,char* name)
{
	int retorno = -1;
	if(this != NULL && name != NULL)
	{
		strcpy(this->name,name);
		retorno = 0;
	}
	return = retorno;
}

int employee_setLastName(Employee* this,char* lastName)
{
	int retorno = -1;
	if(this != NULL && lastName != NULL)
	{
		strcpy(this->lastName,lastName);
		retorno = 0;
	}
	return = retorno;
}

int employee_setAge(Employee* this,int age)
{
	int retorno = -1;
	if(this != NULL)
	{
		this->age = age;
		retorno = 0;
	}
	return = retorno;
}

int employee_setType(Employee* this,int type)
{
	int retorno = -1;
	if(this != NULL)
	{
		this->type = type;
		retorno = 0;
	}
	return = retorno;
}

int employee_getId(Employee* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		this->id;
		retorno = 0;
	}
	return = retorno;
}

char* employee_getName(Employee* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		this->name;
		retorno = 0;
	}
	return = retorno;
}

char* employee_getLastName(Employee* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		this->lastName;
		retorno = 0;
	}
	return = retorno;
}

int employee_getAge(Employee* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		this->age;
		retorno = 0;
	}
	return = retorno;
}

int employee_getType(Employee* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		this->type;
		retorno = 0;
	}
	return = retorno;
}

Employee* employee_getById(LinkedList* pArray,int id)
{
	int i;
	Employee* aux;
	Employee* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(id == employee_getId(aux))
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}

Employee* employee_getByName(LinkedList* pArray,char* name)
{
	int i;
	Employee* aux;
	Employee* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(strcmp(name,employee_getName(aux))==0)
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}

Employee* employee_getByLastName(LinkedList* pArray,char* lastName)
{
	int i;
	Employee* aux;
	Employee* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(strcmp(lastName,employee_getLastName(aux))==0)
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}

Employee* employee_getByAge(LinkedList* pArray,int age)
{
	int i;
	Employee* aux;
	Employee* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(age == employee_getAge(aux))
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}

Employee* employee_getByType(LinkedList* pArray,int type)
{
	int i;
	Employee* aux;
	Employee* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(type == employee_getType(aux))
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}

int employee_compareById(void* pA ,void* pB)
{

	int retorno = 0;

	if(employee_getId(pA) > employee_getId(pB))
		retorno = 1;
	else if(employee_getId(pA) < employee_getId(pB))
		retorno = -1;

	return retorno;
}

int employee_compareByName(void* pA ,void* pB)
{
	int retorno;

	retorno = strcmp(employee_getName(pA),employee_getName(pB));

	return retorno;
}

int employee_compareByLastName(void* pA ,void* pB)
{
	int retorno;

	retorno = strcmp(employee_getLastName(pA),employee_getLastName(pB));

	return retorno;
}

int employee_compareByAge(void* pA ,void* pB)
{

	int retorno = 0;

	if(employee_getAge(pA) > employee_getAge(pB))
		retorno = 1;
	else if(employee_getAge(pA) < employee_getAge(pB))
		retorno = -1;

	return retorno;
}

int employee_compareByType(void* pA ,void* pB)
{

	int retorno = 0;

	if(employee_getType(pA) > employee_getType(pB))
		retorno = 1;
	else if(employee_getType(pA) < employee_getType(pB))
		retorno = -1;

	return retorno;
}



********************* Employee.c ************************


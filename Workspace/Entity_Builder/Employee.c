

********************* Employee.c ************************

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "utn.h"
#include "Employee.h"
#include "parser.h"
#include "controller.h"

Employee* employee_constructor(int id,char* name,char* lastName,int age,int type)
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
			employee_destructor(this);
			return NULL;
		}
	}
}

int employee_destructor(Employee* this)
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
		retorno = this->id;
	}
	return = retorno;
}

char* employee_getName(Employee* this)
{
	char* retorno = NULL;
	if(this != NULL)
	{
		strcpy(retorno,this->name);
	}
	return = retorno;
}

char* employee_getLastName(Employee* this)
{
	char* retorno = NULL;
	if(this != NULL)
	{
		strcpy(retorno,this->lastName);
	}
	return = retorno;
}

int employee_getAge(Employee* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		retorno = this->age;
	}
	return = retorno;
}

int employee_getType(Employee* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		retorno = this->type;
	}
	return = retorno;
}

Employee* employee_getById(LinkedList* pArray,int id)
{
	int i;
	Employee* aux;
	Employee* retorno=NULL;
	for(i=0;i<ll_len(pArray);i++)
	{
		aux = ll_get(pArray,i);
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
	for(i=0;i<ll_len(pArray);i++)
	{
		aux = ll_get(pArray,i);
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
	for(i=0;i<ll_len(pArray);i++)
	{
		aux = ll_get(pArray,i);
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
	for(i=0;i<ll_len(pArray);i++)
	{
		aux = ll_get(pArray,i);
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
	for(i=0;i<ll_len(pArray);i++)
	{
		aux = ll_get(pArray,i);
		if(type == employee_getType(aux))
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}

int employee_compareById(void* thisA ,void* thisB)
{
	int retorno = 0;

	if(thisA != NULL && thisB != NULL)
	{
		if(employee_getId(thisA) > employee_getId(thisB))
		{
				retorno = 1;
		}
		else if(employee_getId(thisA) < employee_getId(thisB))
		{
			retorno = -1;
		}
	}
	return retorno;
}

int employee_compareByName(void* thisA ,void* thisB)
{
	int retorno = 0;

	if(thisA != NULL && thisB != NULL)
	{
		retorno = strcmp(employee_getName(thisA),employee_getName(thisB));
	}
	return retorno;
}

int employee_compareByLastName(void* thisA ,void* thisB)
{
	int retorno = 0;

	if(thisA != NULL && thisB != NULL)
	{
		retorno = strcmp(employee_getLastName(thisA),employee_getLastName(thisB));
	}
	return retorno;
}

int employee_compareByAge(void* thisA ,void* thisB)
{
	int retorno = 0;

	if(thisA != NULL && thisB != NULL)
	{
		if(employee_getAge(thisA) > employee_getAge(thisB))
		{
				retorno = 1;
		}
		else if(employee_getAge(thisA) < employee_getAge(thisB))
		{
			retorno = -1;
		}
	}
	return retorno;
}

int employee_compareByType(void* thisA ,void* thisB)
{
	int retorno = 0;

	if(thisA != NULL && thisB != NULL)
	{
		if(employee_getType(thisA) > employee_getType(thisB))
		{
				retorno = 1;
		}
		else if(employee_getType(thisA) < employee_getType(thisB))
		{
			retorno = -1;
		}
	}
	return retorno;
}



********************* Employee.c ************************


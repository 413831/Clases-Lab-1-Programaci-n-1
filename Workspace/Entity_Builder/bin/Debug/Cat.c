

********************* Cat.c ************************

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "utn.h"
#include "Cat.h"
#include "parser.h"
#include "controller.h"

Cat* cat_new(char* nombre,char* color,char* sexo,int edad,int id)
{
	Cat* this = malloc(sizeof(Cat));

	if(this != NULL)
	{
		if(	!cat_setNombre(this,nombre) &&
			!cat_setColor(this,color) &&
			!cat_setSexo(this,sexo) &&
			!cat_setEdad(this,edad) &&
			!cat_setId(this,id) &&
			)
		{
			return this;
		}
		else
		{
			cat_delete(this);
	\ttreturn NULL;
		}
	}
}

int cat_delete(Cat* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		free(this);
		retorno = 0;
	}
	return retorno;
}

int cat_setNombre(Cat* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre,nombre);
		retorno = 0;
	}
	return = retorno;
}

int cat_setColor(Cat* this,char* color)
{
	int retorno = -1;
	if(this != NULL && color != NULL)
	{
		strcpy(this->color,color);
		retorno = 0;
	}
	return = retorno;
}

int cat_setSexo(Cat* this,char* sexo)
{
	int retorno = -1;
	if(this != NULL && sexo != NULL)
	{
		strcpy(this->sexo,sexo);
		retorno = 0;
	}
	return = retorno;
}

int cat_setEdad(Cat* this,int edad)
{
	int retorno = -1;
	if(this != NULL)
	{
		this->edad = edad;
		retorno = 0;
	}
	return = retorno;
}

int cat_setId(Cat* this,int id)
{
	int retorno = -1;
	if(this != NULL)
	{
		this->id = id;
		retorno = 0;
	}
	return = retorno;
}

char* cat_getNombre(Cat* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		this->nombre;
		retorno = 0;
	}
	return = retorno;
}

char* cat_getColor(Cat* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		this->color;
		retorno = 0;
	}
	return = retorno;
}

char* cat_getSexo(Cat* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		this->sexo;
		retorno = 0;
	}
	return = retorno;
}

int cat_getEdad(Cat* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		this->edad;
		retorno = 0;
	}
	return = retorno;
}

int cat_getId(Cat* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		this->id;
		retorno = 0;
	}
	return = retorno;
}

Cat* cat_getByNombre(LinkedList* pArray,char* nombre)
{
	int i;
	Cat* aux;
	Cat* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(strcmp(nombre,cat_getNombre(aux))==0)
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}

Cat* cat_getByColor(LinkedList* pArray,char* color)
{
	int i;
	Cat* aux;
	Cat* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(strcmp(color,cat_getColor(aux))==0)
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}

Cat* cat_getBySexo(LinkedList* pArray,char* sexo)
{
	int i;
	Cat* aux;
	Cat* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(strcmp(sexo,cat_getSexo(aux))==0)
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}

Cat* cat_getByEdad(LinkedList* pArray,int edad)
{
	int i;
	Cat* aux;
	Cat* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(edad == cat_getEdad(aux))
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}

Cat* cat_getById(LinkedList* pArray,int id)
{
	int i;
	Cat* aux;
	Cat* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(id == cat_getId(aux))
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}

int cat_compareByNombre(void* pA ,void* pB)
{
	int retorno;

	retorno = strcmp(cat_getNombre(pA),cat_getNombre(pB));

	return retorno;
}

int cat_compareByColor(void* pA ,void* pB)
{
	int retorno;

	retorno = strcmp(cat_getColor(pA),cat_getColor(pB));

	return retorno;
}

int cat_compareBySexo(void* pA ,void* pB)
{
	int retorno;

	retorno = strcmp(cat_getSexo(pA),cat_getSexo(pB));

	return retorno;
}

int cat_compareByEdad(void* pA ,void* pB)
{

	int retorno = 0;

	if(cat_getEdad(pA) > cat_getEdad(pB))
		retorno = 1;
	else if(cat_getEdad(pA) < cat_getEdad(pB))
		retorno = -1;

	return retorno;
}

int cat_compareById(void* pA ,void* pB)
{

	int retorno = 0;

	if(cat_getId(pA) > cat_getId(pB))
		retorno = 1;
	else if(cat_getId(pA) < cat_getId(pB))
		retorno = -1;

	return retorno;
}



********************* Cat.c ************************




********************* Person.c ************************

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "utn.h"
#include "Person.h"
#include "parser.h"
#include "controller.h"

static int isValidName(char* name);
static int isValidLastName(char* lastName);
static int isValidAge(int age);
static int isValidAddress(char* address);
static int isValidId(int id);
 
/**
*\brief Valida un dato del campo name
*\param name Es el dato recibido para validar
*\return Retorna 1 si el dato es valido sino retorna 0
*/
static int isValidName(char* name)
{
	int retorno = 0;
	if(name != NULL && strlen(name) > 1)
	{
		retorno = 1;
	}
	return = retorno;
}

/**
*\brief Valida un dato del campo lastName
*\param lastName Es el dato recibido para validar
*\return Retorna 1 si el dato es valido sino retorna 0
*/
static int isValidLastName(char* lastName)
{
	int retorno = 0;
	if(lastName != NULL && strlen(lastName) > 1)
	{
		retorno = 1;
	}
	return = retorno;
}

/**
*\brief Valida un dato del campo age
*\param age Es el dato recibido para validar
*\return Retorna 1 si el dato es valido sino retorna 0
*/
static int isValidAge(int age)
{
	int retorno = 0;
	if(age >= 0)
	{
		retorno = 1;
	}
	return = retorno;
}

/**
*\brief Valida un dato del campo address
*\param address Es el dato recibido para validar
*\return Retorna 1 si el dato es valido sino retorna 0
*/
static int isValidAddress(char* address)
{
	int retorno = 0;
	if(address != NULL && strlen(address) > 1)
	{
		retorno = 1;
	}
	return = retorno;
}

/**
*\brief Valida un dato del campo id
*\param id Es el dato recibido para validar
*\return Retorna 1 si el dato es valido sino retorna 0
*/
static int isValidId(int id)
{
	int retorno = 0;
	if(id >= 0)
	{
		retorno = 1;
	}
	return = retorno;
}

 
//////////////////PUBLIC//////////////////

/**
*\brief Es el constructor del elemento donde se reserva memoria y se setean los campos
*\param COMPLETAR
*\return Retorna 0 si logra agregar elemento sino retorna -1
*/
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

/**
*\brief Es el destructor del elemento que funciona para liberar memoria reservada
*\param this Es el elemento para eliminar
*\return Retorna 0 si logra eliminar elemento sino retorna -1
*/
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

/**
*\brief Es el setter del campo name del elemento
*\param this Es el elemento que se recibe para setear un campo
*\param name Es el dato recibido para setear el campo
*\return Retorna 0 si el elemento existe y si el dato es valido sino retorna COMPLETAR
*/
int person_setName(Person* this,char* name)
{
	int retorno = -1;
	if(this != NULL && name != NULL && isValidName(name))
	{
		strcpy(this->name,name);
		retorno = 0;
	}
	return = retorno;
}

/**
*\brief Es el setter del campo lastName del elemento
*\param this Es el elemento que se recibe para setear un campo
*\param lastName Es el dato recibido para setear el campo
*\return Retorna 0 si el elemento existe y si el dato es valido sino retorna COMPLETAR
*/
int person_setLastName(Person* this,char* lastName)
{
	int retorno = -1;
	if(this != NULL && lastName != NULL && isValidLastName(lastName))
	{
		strcpy(this->lastName,lastName);
		retorno = 0;
	}
	return = retorno;
}

/**
*\brief Es el setter del campo age del elemento
*\param this Es el elemento que se recibe para setear un campo
*\param age Es el dato recibido para setear el campo
*\return Retorna 0 si el elemento existe y si el dato es valido sino retorna COMPLETAR
*/
int person_setAge(Person* this,int age)
{
	int retorno = -1;
	if(this != NULL && isValidAge(age))
	{
		this->age = age;
		retorno = 0;
	}
	return = retorno;
}

/**
*\brief Es el setter del campo address del elemento
*\param this Es el elemento que se recibe para setear un campo
*\param address Es el dato recibido para setear el campo
*\return Retorna 0 si el elemento existe y si el dato es valido sino retorna COMPLETAR
*/
int person_setAddress(Person* this,char* address)
{
	int retorno = -1;
	if(this != NULL && address != NULL && isValidAddress(address))
	{
		strcpy(this->address,address);
		retorno = 0;
	}
	return = retorno;
}

/**
*\brief Es el setter del campo id del elemento
*\param this Es el elemento que se recibe para setear un campo
*\param id Es el dato recibido para setear el campo
*\return Retorna 0 si el elemento existe y si el dato es valido sino retorna COMPLETAR
*/
int person_setId(Person* this,int id)
{
	int retorno = -1;
	if(this != NULL && isValidId(id))
	{
		this->id = id;
		retorno = 0;
	}
	return = retorno;
}

/**
*\brief Es el getter del campo name del elemento
*\param this Es el elemento del cual se obtiene el dato name
*\return Retorna 0 si el elemento existe y si el dato es valido sino retorna COMPLETAR
*/
char* person_getName(Person* this)
{
	char* retorno = NULL;
	if(this != NULL)
	{
		strcpy(retorno,this->name);
	}
	return = retorno;
}

/**
*\brief Es el getter del campo lastName del elemento
*\param this Es el elemento del cual se obtiene el dato lastName
*\return Retorna 0 si el elemento existe y si el dato es valido sino retorna COMPLETAR
*/
char* person_getLastName(Person* this)
{
	char* retorno = NULL;
	if(this != NULL)
	{
		strcpy(retorno,this->lastName);
	}
	return = retorno;
}

/**
*\brief Es el getter del campo age del elemento
*\param this Es el elemento del cual se obtiene el dato age
*\return Retorna 0 si el elemento existe y si el dato es valido sino retorna COMPLETAR
*/
int person_getAge(Person* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		retorno = this->age;
	}
	return = retorno;
}

/**
*\brief Es el getter del campo address del elemento
*\param this Es el elemento del cual se obtiene el dato address
*\return Retorna 0 si el elemento existe y si el dato es valido sino retorna COMPLETAR
*/
char* person_getAddress(Person* this)
{
	char* retorno = NULL;
	if(this != NULL)
	{
		strcpy(retorno,this->address);
	}
	return = retorno;
}

/**
*\brief Es el getter del campo id del elemento
*\param this Es el elemento del cual se obtiene el dato id
*\return Retorna 0 si el elemento existe y si el dato es valido sino retorna COMPLETAR
*/
int person_getId(Person* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		retorno = this->id;
	}
	return = retorno;
}

/**
*\brief Retorna un elemento segun el dato name ingresado
*\param pArray Es el puntero a LinkedList recibido para buscar elemento
*\param name Es el dato que se recibe para encontrar el elemento
*\return Retorna el elemento si lo encuentra sino retorna NULL
*/
Person* person_getByName(LinkedList* pArray,char* name)
{
	int i;
	Person* aux;
	Person* retorno=NULL;

	if(pArray != NULL && isValidName(name))
	{
		for(i=0;i<ll_len(pArray);i++)
		{
			aux = ll_get(pArray,i);
			if(strcmp(name,person_getName(aux))==0)
			{
				retorno = aux;
				break;
			}
		}
	}
	return retorno;
}

/**
*\brief Retorna un elemento segun el dato lastName ingresado
*\param pArray Es el puntero a LinkedList recibido para buscar elemento
*\param lastName Es el dato que se recibe para encontrar el elemento
*\return Retorna el elemento si lo encuentra sino retorna NULL
*/
Person* person_getByLastName(LinkedList* pArray,char* lastName)
{
	int i;
	Person* aux;
	Person* retorno=NULL;

	if(pArray != NULL && isValidLastName(lastName))
	{
		for(i=0;i<ll_len(pArray);i++)
		{
			aux = ll_get(pArray,i);
			if(strcmp(lastName,person_getLastName(aux))==0)
			{
				retorno = aux;
				break;
			}
		}
	}
	return retorno;
}

/**
*\brief Retorna un elemento segun el dato age ingresado
*\param pArray Es el puntero a LinkedList recibido para buscar elemento
*\param age Es el dato que se recibe para encontrar el elemento
*\return Retorna el elemento si lo encuentra sino retorna NULL
*/
Person* person_getByAge(LinkedList* pArray,int age)
{
	int i;
	Person* aux;
	Person* retorno=NULL;

	if(pArray != NULL && isValidAge(age))
	{
		for(i=0;i<ll_len(pArray);i++)
		{
			aux = ll_get(pArray,i);
			if(age == person_getAge(aux))
			{
				retorno = aux;
				break;
			}
		}
	}
	return retorno;
}

/**
*\brief Retorna un elemento segun el dato address ingresado
*\param pArray Es el puntero a LinkedList recibido para buscar elemento
*\param address Es el dato que se recibe para encontrar el elemento
*\return Retorna el elemento si lo encuentra sino retorna NULL
*/
Person* person_getByAddress(LinkedList* pArray,char* address)
{
	int i;
	Person* aux;
	Person* retorno=NULL;

	if(pArray != NULL && isValidAddress(address))
	{
		for(i=0;i<ll_len(pArray);i++)
		{
			aux = ll_get(pArray,i);
			if(strcmp(address,person_getAddress(aux))==0)
			{
				retorno = aux;
				break;
			}
		}
	}
	return retorno;
}

/**
*\brief Retorna un elemento segun el dato id ingresado
*\param pArray Es el puntero a LinkedList recibido para buscar elemento
*\param id Es el dato que se recibe para encontrar el elemento
*\return Retorna el elemento si lo encuentra sino retorna NULL
*/
Person* person_getById(LinkedList* pArray,int id)
{
	int i;
	Person* aux;
	Person* retorno=NULL;

	if(pArray != NULL && isValidId(id))
	{
		for(i=0;i<ll_len(pArray);i++)
		{
			aux = ll_get(pArray,i);
			if(id == person_getId(aux))
			{
				retorno = aux;
				break;
			}
		}
	}
	return retorno;
}

/**
*\brief Compara dos elementos por su campo name
*\param thisA Es el puntero al primer elemento a comparar
*\param thisB Es el puntero al segundo elemento a comparar
*\return Retorna 0 si ambos campos son iguales
		Retorna 1 si el campo del primer elemento es mayor al segundo
		Retorna -1 si el campo del segundo elemento es mayor al primero
*/
int person_compareByName(void* thisA ,void* thisB)
{
	int retorno = 0;

	if(thisA != NULL && thisB != NULL)
	{
		retorno = strcmp(person_getName(thisA),person_getName(thisB));
	}
	return retorno;
}

/**
*\brief Compara dos elementos por su campo lastName
*\param thisA Es el puntero al primer elemento a comparar
*\param thisB Es el puntero al segundo elemento a comparar
*\return Retorna 0 si ambos campos son iguales
		Retorna 1 si el campo del primer elemento es mayor al segundo
		Retorna -1 si el campo del segundo elemento es mayor al primero
*/
int person_compareByLastName(void* thisA ,void* thisB)
{
	int retorno = 0;

	if(thisA != NULL && thisB != NULL)
	{
		retorno = strcmp(person_getLastName(thisA),person_getLastName(thisB));
	}
	return retorno;
}

/**
*\brief Compara dos elementos por su campo age
*\param thisA Es el puntero al primer elemento a comparar
*\param thisB Es el puntero al segundo elemento a comparar
*\return Retorna 0 si ambos campos son iguales
		Retorna 1 si el campo del primer elemento es mayor al segundo
		Retorna -1 si el campo del segundo elemento es mayor al primero
*/
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

/**
*\brief Compara dos elementos por su campo address
*\param thisA Es el puntero al primer elemento a comparar
*\param thisB Es el puntero al segundo elemento a comparar
*\return Retorna 0 si ambos campos son iguales
		Retorna 1 si el campo del primer elemento es mayor al segundo
		Retorna -1 si el campo del segundo elemento es mayor al primero
*/
int person_compareByAddress(void* thisA ,void* thisB)
{
	int retorno = 0;

	if(thisA != NULL && thisB != NULL)
	{
		retorno = strcmp(person_getAddress(thisA),person_getAddress(thisB));
	}
	return retorno;
}

/**
*\brief Compara dos elementos por su campo id
*\param thisA Es el puntero al primer elemento a comparar
*\param thisB Es el puntero al segundo elemento a comparar
*\return Retorna 0 si ambos campos son iguales
		Retorna 1 si el campo del primer elemento es mayor al segundo
		Retorna -1 si el campo del segundo elemento es mayor al primero
*/
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

/**
*\brief Muestra los datos de un elemento
*\param this Es el elemento que recibe para mostrar
*\return Retorna 0 si el elemento existe sino retorna -1
*/
int person_show(Person* this)
{
	if(this != NULL)
	{
		printf("\nName -- %s",person_getName(this));/////CAMBIAR /n;
		printf("\nLastName -- %s",person_getLastName(this));/////CAMBIAR /n;
		printf("\nAge -- %d",person_getAge(this));/////CAMBIAR /n;
		printf("\nAddress -- %s",person_getAddress(this));/////CAMBIAR /n;
		printf("\nId -- %d",person_getId(this));/////CAMBIAR /n;
		retorno = 0;
	}
	return retorno;
}



********************* Person.c ************************


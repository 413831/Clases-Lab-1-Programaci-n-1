

********************* Employee.c ************************

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "utn.h"
#include "Employee.h"
#include "parser.h"
#include "controller.h"

static int isValidId(int id);
static int isValidName(char* name);
static int isValidLastName(char* lastName);
static int isValidAge(int age);
static int isValidType(int type);
 
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
*\brief Valida un dato del campo type
*\param type Es el dato recibido para validar
*\return Retorna 1 si el dato es valido sino retorna 0
*/
static int isValidType(int type)
{
	int retorno = 0;
	if(type >= 0)
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

/**
*\brief Es el destructor del elemento que funciona para liberar memoria reservada
*\param this Es el elemento para eliminar
*\return Retorna 0 si logra eliminar elemento sino retorna -1
*/
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

/**
*\brief Es el setter del campo id del elemento
*\param this Es el elemento que se recibe para setear un campo
*\param id Es el dato recibido para setear el campo
*\return Retorna 0 si el elemento existe y si el dato es valido sino retorna COMPLETAR
*/
int employee_setId(Employee* this,int id)
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
*\brief Es el setter del campo name del elemento
*\param this Es el elemento que se recibe para setear un campo
*\param name Es el dato recibido para setear el campo
*\return Retorna 0 si el elemento existe y si el dato es valido sino retorna COMPLETAR
*/
int employee_setName(Employee* this,char* name)
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
int employee_setLastName(Employee* this,char* lastName)
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
int employee_setAge(Employee* this,int age)
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
*\brief Es el setter del campo type del elemento
*\param this Es el elemento que se recibe para setear un campo
*\param type Es el dato recibido para setear el campo
*\return Retorna 0 si el elemento existe y si el dato es valido sino retorna COMPLETAR
*/
int employee_setType(Employee* this,int type)
{
	int retorno = -1;
	if(this != NULL && isValidType(type))
	{
		this->type = type;
		retorno = 0;
	}
	return = retorno;
}

/**
*\brief Es el getter del campo id del elemento
*\param this Es el elemento del cual se obtiene el dato id
*\return Retorna 0 si el elemento existe y si el dato es valido sino retorna COMPLETAR
*/
int employee_getId(Employee* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		retorno = this->id;
	}
	return = retorno;
}

/**
*\brief Es el getter del campo name del elemento
*\param this Es el elemento del cual se obtiene el dato name
*\return Retorna 0 si el elemento existe y si el dato es valido sino retorna COMPLETAR
*/
char* employee_getName(Employee* this)
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
char* employee_getLastName(Employee* this)
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
int employee_getAge(Employee* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		retorno = this->age;
	}
	return = retorno;
}

/**
*\brief Es el getter del campo type del elemento
*\param this Es el elemento del cual se obtiene el dato type
*\return Retorna 0 si el elemento existe y si el dato es valido sino retorna COMPLETAR
*/
int employee_getType(Employee* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		retorno = this->type;
	}
	return = retorno;
}

/**
*\brief Retorna un elemento segun el dato id ingresado
*\param pArray Es el puntero a LinkedList recibido para buscar elemento
*\param id Es el dato que se recibe para encontrar el elemento
*\return Retorna el elemento si lo encuentra sino retorna NULL
*/
Employee* employee_getById(LinkedList* pArray,int id)
{
	int i;
	Employee* aux;
	Employee* retorno=NULL;

	if(pArray != NULL && isValidId(id))
	{
		for(i=0;i<ll_len(pArray);i++)
		{
			aux = ll_get(pArray,i);
			if(id == employee_getId(aux))
			{
				retorno = aux;
				break;
			}
		}
	}
	return retorno;
}

/**
*\brief Retorna un elemento segun el dato name ingresado
*\param pArray Es el puntero a LinkedList recibido para buscar elemento
*\param name Es el dato que se recibe para encontrar el elemento
*\return Retorna el elemento si lo encuentra sino retorna NULL
*/
Employee* employee_getByName(LinkedList* pArray,char* name)
{
	int i;
	Employee* aux;
	Employee* retorno=NULL;

	if(pArray != NULL && isValidName(name))
	{
		for(i=0;i<ll_len(pArray);i++)
		{
			aux = ll_get(pArray,i);
			if(strcmp(name,employee_getName(aux))==0)
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
Employee* employee_getByLastName(LinkedList* pArray,char* lastName)
{
	int i;
	Employee* aux;
	Employee* retorno=NULL;

	if(pArray != NULL && isValidLastName(lastName))
	{
		for(i=0;i<ll_len(pArray);i++)
		{
			aux = ll_get(pArray,i);
			if(strcmp(lastName,employee_getLastName(aux))==0)
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
Employee* employee_getByAge(LinkedList* pArray,int age)
{
	int i;
	Employee* aux;
	Employee* retorno=NULL;

	if(pArray != NULL && isValidAge(age))
	{
		for(i=0;i<ll_len(pArray);i++)
		{
			aux = ll_get(pArray,i);
			if(age == employee_getAge(aux))
			{
				retorno = aux;
				break;
			}
		}
	}
	return retorno;
}

/**
*\brief Retorna un elemento segun el dato type ingresado
*\param pArray Es el puntero a LinkedList recibido para buscar elemento
*\param type Es el dato que se recibe para encontrar el elemento
*\return Retorna el elemento si lo encuentra sino retorna NULL
*/
Employee* employee_getByType(LinkedList* pArray,int type)
{
	int i;
	Employee* aux;
	Employee* retorno=NULL;

	if(pArray != NULL && isValidType(type))
	{
		for(i=0;i<ll_len(pArray);i++)
		{
			aux = ll_get(pArray,i);
			if(type == employee_getType(aux))
			{
				retorno = aux;
				break;
			}
		}
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

/**
*\brief Compara dos elementos por su campo name
*\param thisA Es el puntero al primer elemento a comparar
*\param thisB Es el puntero al segundo elemento a comparar
*\return Retorna 0 si ambos campos son iguales
		Retorna 1 si el campo del primer elemento es mayor al segundo
		Retorna -1 si el campo del segundo elemento es mayor al primero
*/
int employee_compareByName(void* thisA ,void* thisB)
{
	int retorno = 0;

	if(thisA != NULL && thisB != NULL)
	{
		retorno = strcmp(employee_getName(thisA),employee_getName(thisB));
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
int employee_compareByLastName(void* thisA ,void* thisB)
{
	int retorno = 0;

	if(thisA != NULL && thisB != NULL)
	{
		retorno = strcmp(employee_getLastName(thisA),employee_getLastName(thisB));
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

/**
*\brief Compara dos elementos por su campo type
*\param thisA Es el puntero al primer elemento a comparar
*\param thisB Es el puntero al segundo elemento a comparar
*\return Retorna 0 si ambos campos son iguales
		Retorna 1 si el campo del primer elemento es mayor al segundo
		Retorna -1 si el campo del segundo elemento es mayor al primero
*/
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

/**
*\brief Muestra los datos de un elemento
*\param this Es el elemento que recibe para mostrar
*\return Retorna 0 si el elemento existe sino retorna -1
*/
int employee_show(Employee* this)
{
	if(this != NULL)
	{
		printf("\nId -- %d",employee_getId(this));/////CAMBIAR /n;
		printf("\nName -- %s",employee_getName(this));/////CAMBIAR /n;
		printf("\nLastName -- %s",employee_getLastName(this));/////CAMBIAR /n;
		printf("\nAge -- %d",employee_getAge(this));/////CAMBIAR /n;
		printf("\nType -- %d",employee_getType(this));/////CAMBIAR /n;
		retorno = 0;
	}
	return retorno;
}



********************* Employee.c ************************


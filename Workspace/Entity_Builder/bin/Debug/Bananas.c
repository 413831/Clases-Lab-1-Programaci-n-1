

********************* Bananas.c ************************

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "utn.h"
#include "Bananas.h"

static int isValidCantidad(int cantidad);
static int isValidPrecio(int precio);
static int isValidOrigen(char* origen);
static int isValidId(int id);
static int isValidIsEmpty(int isEmpty);
 
/**
*\brief Valida un dato del campo cantidad
*\param cantidad Es el dato recibido para validar
*\return Retorna 1 si el dato es valido sino retorna 0
*/
static int isValidCantidad(int cantidad)
{
	int retorno = 0;
	if(cantidad >= 0)
	{
		retorno = 1;
	}
	return = retorno;
}

/**
*\brief Valida un dato del campo precio
*\param precio Es el dato recibido para validar
*\return Retorna 1 si el dato es valido sino retorna 0
*/
static int isValidPrecio(int precio)
{
	int retorno = 0;
	if(precio >= 0)
	{
		retorno = 1;
	}
	return = retorno;
}

/**
*\brief Valida un dato del campo origen
*\param origen Es el dato recibido para validar
*\return Retorna 1 si el dato es valido sino retorna 0
*/
static int isValidOrigen(char* origen)
{
	int retorno = 0;
	if(origen != NULL && strlen(origen) > 1)
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

/**
*\brief Valida un dato del campo isEmpty
*\param isEmpty Es el dato recibido para validar
*\return Retorna 1 si el dato es valido sino retorna 0
*/
static int isValidIsEmpty(int isEmpty)
{
	int retorno = 0;
	if(isEmpty >= 0)
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
Bananas* bananas_constructor(int cantidad,int precio,char* origen,int id,int isEmpty)
{
	Bananas* this = malloc(sizeof(Bananas));

	if(this != NULL)
	{
		if(	!bananas_setCantidad(this,cantidad) &&
			!bananas_setPrecio(this,precio) &&
			!bananas_setOrigen(this,origen) &&
			!bananas_setId(this,id) &&
			!bananas_setIsEmpty(this,isEmpty) &&
			)
		{
			return this;
		}
		else
		{
			bananas_destructor(this);
			return NULL;
		}
	}
}

/**
*\brief Es el destructor del elemento que funciona para liberar memoria reservada
*\param this Es el elemento para eliminar
*\return Retorna 0 si logra eliminar elemento sino retorna -1
*/
int bananas_destructor(Bananas* this)
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
*\brief Es el setter del campo cantidad del elemento
*\param this Es el elemento que se recibe para setear un campo
*\param cantidad Es el dato recibido para setear el campo
*\return Retorna 0 si el elemento existe y si el dato es valido sino retorna COMPLETAR
*/
int bananas_setCantidad(Bananas* this,int cantidad)
{
	int retorno = -1;
	if(this != NULL && isValidCantidad(cantidad))
	{
		this->cantidad = cantidad;
		retorno = 0;
	}
	return = retorno;
}

/**
*\brief Es el setter del campo precio del elemento
*\param this Es el elemento que se recibe para setear un campo
*\param precio Es el dato recibido para setear el campo
*\return Retorna 0 si el elemento existe y si el dato es valido sino retorna COMPLETAR
*/
int bananas_setPrecio(Bananas* this,int precio)
{
	int retorno = -1;
	if(this != NULL && isValidPrecio(precio))
	{
		this->precio = precio;
		retorno = 0;
	}
	return = retorno;
}

/**
*\brief Es el setter del campo origen del elemento
*\param this Es el elemento que se recibe para setear un campo
*\param origen Es el dato recibido para setear el campo
*\return Retorna 0 si el elemento existe y si el dato es valido sino retorna COMPLETAR
*/
int bananas_setOrigen(Bananas* this,char* origen)
{
	int retorno = -1;
	if(this != NULL && origen != NULL && isValidOrigen(origen))
	{
		strcpy(this->origen,origen);
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
int bananas_setId(Bananas* this,int id)
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
*\brief Es el setter del campo isEmpty del elemento
*\param this Es el elemento que se recibe para setear un campo
*\param isEmpty Es el dato recibido para setear el campo
*\return Retorna 0 si el elemento existe y si el dato es valido sino retorna COMPLETAR
*/
int bananas_setIsEmpty(Bananas* this,int isEmpty)
{
	int retorno = -1;
	if(this != NULL && isValidIsEmpty(isEmpty))
	{
		this->isEmpty = isEmpty;
		retorno = 0;
	}
	return = retorno;
}

/**
*\brief Es el getter del campo cantidad del elemento
*\param this Es el elemento del cual se obtiene el dato cantidad
*\return Retorna 0 si el elemento existe y si el dato es valido sino retorna COMPLETAR
*/
int bananas_getCantidad(Bananas* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		retorno = this->cantidad;
	}
	return = retorno;
}

/**
*\brief Es el getter del campo precio del elemento
*\param this Es el elemento del cual se obtiene el dato precio
*\return Retorna 0 si el elemento existe y si el dato es valido sino retorna COMPLETAR
*/
int bananas_getPrecio(Bananas* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		retorno = this->precio;
	}
	return = retorno;
}

/**
*\brief Es el getter del campo origen del elemento
*\param this Es el elemento del cual se obtiene el dato origen
*\return Retorna 0 si el elemento existe y si el dato es valido sino retorna COMPLETAR
*/
char* bananas_getOrigen(Bananas* this)
{
	char* retorno = NULL;
	if(this != NULL)
	{
		strcpy(retorno,this->origen);
	}
	return = retorno;
}

/**
*\brief Es el getter del campo id del elemento
*\param this Es el elemento del cual se obtiene el dato id
*\return Retorna 0 si el elemento existe y si el dato es valido sino retorna COMPLETAR
*/
int bananas_getId(Bananas* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		retorno = this->id;
	}
	return = retorno;
}

/**
*\brief Es el getter del campo isEmpty del elemento
*\param this Es el elemento del cual se obtiene el dato isEmpty
*\return Retorna 0 si el elemento existe y si el dato es valido sino retorna COMPLETAR
*/
int bananas_getIsEmpty(Bananas* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		retorno = this->isEmpty;
	}
	return = retorno;
}

/**
*\brief Retorna un elemento segun el dato cantidad ingresado
*\param pArray Es el puntero a LinkedList recibido para buscar elemento
*\param cantidad Es el dato que se recibe para encontrar el elemento
*\return Retorna el elemento si lo encuentra sino retorna NULL
*/
Bananas* bananas_getByCantidad(LinkedList* pArray,int cantidad)
{
	int i;
	Bananas* aux;
	Bananas* retorno=NULL;

	if(pArray != NULL && isValidCantidad(cantidad))
	{
		for(i=0;i<ll_len(pArray);i++)
		{
			aux = ll_get(pArray,i);
			if(cantidad == bananas_getCantidad(aux))
			{
				retorno = aux;
				break;
			}
		}
	}
	return retorno;
}

/**
*\brief Retorna un elemento segun el dato precio ingresado
*\param pArray Es el puntero a LinkedList recibido para buscar elemento
*\param precio Es el dato que se recibe para encontrar el elemento
*\return Retorna el elemento si lo encuentra sino retorna NULL
*/
Bananas* bananas_getByPrecio(LinkedList* pArray,int precio)
{
	int i;
	Bananas* aux;
	Bananas* retorno=NULL;

	if(pArray != NULL && isValidPrecio(precio))
	{
		for(i=0;i<ll_len(pArray);i++)
		{
			aux = ll_get(pArray,i);
			if(precio == bananas_getPrecio(aux))
			{
				retorno = aux;
				break;
			}
		}
	}
	return retorno;
}

/**
*\brief Retorna un elemento segun el dato origen ingresado
*\param pArray Es el puntero a LinkedList recibido para buscar elemento
*\param origen Es el dato que se recibe para encontrar el elemento
*\return Retorna el elemento si lo encuentra sino retorna NULL
*/
Bananas* bananas_getByOrigen(LinkedList* pArray,char* origen)
{
	int i;
	Bananas* aux;
	Bananas* retorno=NULL;

	if(pArray != NULL && isValidOrigen(origen))
	{
		for(i=0;i<ll_len(pArray);i++)
		{
			aux = ll_get(pArray,i);
			if(strcmp(origen,bananas_getOrigen(aux))==0)
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
Bananas* bananas_getById(LinkedList* pArray,int id)
{
	int i;
	Bananas* aux;
	Bananas* retorno=NULL;

	if(pArray != NULL && isValidId(id))
	{
		for(i=0;i<ll_len(pArray);i++)
		{
			aux = ll_get(pArray,i);
			if(id == bananas_getId(aux))
			{
				retorno = aux;
				break;
			}
		}
	}
	return retorno;
}

/**
*\brief Retorna un elemento segun el dato isEmpty ingresado
*\param pArray Es el puntero a LinkedList recibido para buscar elemento
*\param isEmpty Es el dato que se recibe para encontrar el elemento
*\return Retorna el elemento si lo encuentra sino retorna NULL
*/
Bananas* bananas_getByIsEmpty(LinkedList* pArray,int isEmpty)
{
	int i;
	Bananas* aux;
	Bananas* retorno=NULL;

	if(pArray != NULL && isValidIsEmpty(isEmpty))
	{
		for(i=0;i<ll_len(pArray);i++)
		{
			aux = ll_get(pArray,i);
			if(isEmpty == bananas_getIsEmpty(aux))
			{
				retorno = aux;
				break;
			}
		}
	}
	return retorno;
}

/**
*\brief Compara dos elementos por su campo cantidad
*\param thisA Es el puntero al primer elemento a comparar
*\param thisB Es el puntero al segundo elemento a comparar
*\return Retorna 0 si ambos campos son iguales
		Retorna 1 si el campo del primer elemento es mayor al segundo
		Retorna -1 si el campo del segundo elemento es mayor al primero
*/
int bananas_compareByCantidad(void* thisA ,void* thisB)
{
	int retorno = 0;

	if(thisA != NULL && thisB != NULL)
	{
		if(bananas_getCantidad(thisA) > bananas_getCantidad(thisB))
		{
				retorno = 1;
		}
		else if(bananas_getCantidad(thisA) < bananas_getCantidad(thisB))
		{
			retorno = -1;
		}
	}
	return retorno;
}

/**
*\brief Compara dos elementos por su campo precio
*\param thisA Es el puntero al primer elemento a comparar
*\param thisB Es el puntero al segundo elemento a comparar
*\return Retorna 0 si ambos campos son iguales
		Retorna 1 si el campo del primer elemento es mayor al segundo
		Retorna -1 si el campo del segundo elemento es mayor al primero
*/
int bananas_compareByPrecio(void* thisA ,void* thisB)
{
	int retorno = 0;

	if(thisA != NULL && thisB != NULL)
	{
		if(bananas_getPrecio(thisA) > bananas_getPrecio(thisB))
		{
				retorno = 1;
		}
		else if(bananas_getPrecio(thisA) < bananas_getPrecio(thisB))
		{
			retorno = -1;
		}
	}
	return retorno;
}

/**
*\brief Compara dos elementos por su campo origen
*\param thisA Es el puntero al primer elemento a comparar
*\param thisB Es el puntero al segundo elemento a comparar
*\return Retorna 0 si ambos campos son iguales
		Retorna 1 si el campo del primer elemento es mayor al segundo
		Retorna -1 si el campo del segundo elemento es mayor al primero
*/
int bananas_compareByOrigen(void* thisA ,void* thisB)
{
	int retorno = 0;

	if(thisA != NULL && thisB != NULL)
	{
		retorno = strcmp(bananas_getOrigen(thisA),bananas_getOrigen(thisB));
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
int bananas_compareById(void* thisA ,void* thisB)
{
	int retorno = 0;

	if(thisA != NULL && thisB != NULL)
	{
		if(bananas_getId(thisA) > bananas_getId(thisB))
		{
				retorno = 1;
		}
		else if(bananas_getId(thisA) < bananas_getId(thisB))
		{
			retorno = -1;
		}
	}
	return retorno;
}

/**
*\brief Compara dos elementos por su campo isEmpty
*\param thisA Es el puntero al primer elemento a comparar
*\param thisB Es el puntero al segundo elemento a comparar
*\return Retorna 0 si ambos campos son iguales
		Retorna 1 si el campo del primer elemento es mayor al segundo
		Retorna -1 si el campo del segundo elemento es mayor al primero
*/
int bananas_compareByIsEmpty(void* thisA ,void* thisB)
{
	int retorno = 0;

	if(thisA != NULL && thisB != NULL)
	{
		if(bananas_getIsEmpty(thisA) > bananas_getIsEmpty(thisB))
		{
				retorno = 1;
		}
		else if(bananas_getIsEmpty(thisA) < bananas_getIsEmpty(thisB))
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
int bananas_show(Bananas* this)
{
	if(this != NULL)
	{
		printf("\nCantidad -- %d",bananas_getCantidad(this));
		printf("\nPrecio -- %d",bananas_getPrecio(this));
		printf("\nOrigen -- %s",bananas_getOrigen(this));
		printf("\nId -- %d",bananas_getId(this));
		printf("\nIsEmpty -- %d",bananas_getIsEmpty(this));
		retorno = 0;
	}
	return retorno;
}



********************* Bananas.c ************************


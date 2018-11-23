

********************* Compra.c ************************

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "utn.h"
#include "Compra.h"

static int isValidNombreCliente(char* nombreCliente);
static int isValidIdProducto(int idProducto);
static int isValidPrecioUnitario(float precioUnitario);
static int isValidUnidades(int unidades);
static int isValidIva(float iva);
static int isValidMontoTotal(float montoTotal);
 
/**
*\brief Valida un dato del campo nombreCliente
*\param nombreCliente Es el dato recibido para validar
*\return Retorna 1 si el dato es valido sino retorna 0
*/
static int isValidNombreCliente(char* nombreCliente)
{
	int retorno = 0;
	if(nombreCliente != NULL && strlen(nombreCliente) > 1)
	{
		retorno = 1;
	}
	return = retorno;
}

/**
*\brief Valida un dato del campo idProducto
*\param idProducto Es el dato recibido para validar
*\return Retorna 1 si el dato es valido sino retorna 0
*/
static int isValidIdProducto(int idProducto)
{
	int retorno = 0;
	if(idProducto >= 0)
	{
		retorno = 1;
	}
	return = retorno;
}

/**
*\brief Valida un dato del campo precioUnitario
*\param precioUnitario Es el dato recibido para validar
*\return Retorna 1 si el dato es valido sino retorna 0
*/
static int isValidPrecioUnitario(float precioUnitario)
{
	int retorno = 0;
	if(precioUnitario >= 0)
	{
		retorno = 1;
	}
	return = retorno;
}

/**
*\brief Valida un dato del campo unidades
*\param unidades Es el dato recibido para validar
*\return Retorna 1 si el dato es valido sino retorna 0
*/
static int isValidUnidades(int unidades)
{
	int retorno = 0;
	if(unidades >= 0)
	{
		retorno = 1;
	}
	return = retorno;
}

/**
*\brief Valida un dato del campo iva
*\param iva Es el dato recibido para validar
*\return Retorna 1 si el dato es valido sino retorna 0
*/
static int isValidIva(float iva)
{
	int retorno = 0;
	if(iva >= 0)
	{
		retorno = 1;
	}
	return = retorno;
}

/**
*\brief Valida un dato del campo montoTotal
*\param montoTotal Es el dato recibido para validar
*\return Retorna 1 si el dato es valido sino retorna 0
*/
static int isValidMontoTotal(float montoTotal)
{
	int retorno = 0;
	if(montoTotal >= 0)
	{
		retorno = 1;
	}
	return = retorno;
}

 
//////////////////PUBLIC//////////////////

/**
*\brief Se realiza el alta de un elemento desde consola
*\param pLinkedList Es el array para ingresar elemento
*\return Retorna 0 si logra agregar elemento sino retorna -1
*/
int elemento_add(void* pLinkedList)
{
    int retorno = -1;
    char campoUno[BUFFER];
    char campoDos[BUFFER];
    char campoTres[BUFFER];
    char campoCuatro[BUFFER];
    char campoCinco[BUFFER];
    Elemento* this = NULL;

    if( !input("campoUno",bufferCampoUno,BUFFER,punteroValidacionUno) &&
        !input("campoDos",bufferCampoDos,BUFFER,punteroValidacionDos) &&
        !input("campoTres",bufferCampoTres,BUFFER,punteroValidacionTres) &&
        !input("campoCuatro",bufferCampoCuatro,BUFFER,punteroValidacionCuatro) &&
        !input("campoCinco",bufferCampoCinco,BUFFER,punteroValidacionCinco))
    {
        this = elemento_constructor(bufferCampoUno,bufferCampoDos,bufferCampoTres,bufferCampoCuatro,bufferCampoCinco);
        if(this != NULL)
        {
            elemento_show(this);
            ll_add(pLinkedList,this);
            retorno = 0;;
        }
    }
    return retorno;
}


/**
*\brief Se da de baja un elemento seteando el ID en valor especifico
*\param pArray Es el array para recorrer
*\return Retorna 0 si existe el ID sino retorna -1
*/
int elemento_remove(void* pLinkedList,void* pListInactives)
{
    int retorno = -1;
    int index;
    char bufferId[BUFFER];
    char option[2];
    Elemento* this = NULL;

    if(!input("ID",bufferId,BUFFER,validacionId))
    {
        this = elemento_getById(pLinkedList,atoi(bufferId));//Busco el elemento del Id ingresado
        if(this != NULL)
        {
            elemento_show(this);//Muestro datos del elemento
            input_getLetras(option,2,"\nATENCION!\nDesea dar de baja a empleado? S/N\n","\nError.Dato invalido",2);
            if(!strcasecmp("s",option))
            {
                index = ll_indexOf(pLinkedList,this);
                this = ll_pop(pLinkedList,index);//Se saca el elemento del LinkedList

                ll_add(pListInactives,this);//Se agrega el elemento a la otra LinkedList
                retorno = 0;
            }
        }
        else
        {
            printf("\nEl ID ingresado no existe");
        }
    }
    return retorno;
}

/**
*\brief Se modifica un campo del elemento
*\param this Es el elemento a modificar
*\param validacion Es el puntero a la funcion de validacion
*\param set Es el puntero a la funcion set del campo
*\return Retorna 0 si logra modificar campo sino retorna -1
*/
int elemento_modify(Elemento* this,
                        char* mensaje,
                        int (*validacion)(char*,int),
                        int (*set)(Elemento*,char*))
 {
    int retorno = -1;
    char buffer[BUFFER];

    if(this != NULL && mensaje != NULL && validacion != NULL && set != NULL)
    {
        input(mensaje,buffer,BUFFER,validacion);
        if(buffer != NULL)
        {
            (*set)(this,buffer);
            elemento_show(this);
            retorno = 0;
        }
    }
    else
    {
        printf("\nError");
    }
    return retorno;
}


/**
*\brief Es el constructor del elemento donde se reserva memoria y se setean los campos
*\param COMPLETAR
*\return Retorna 0 si logra agregar elemento sino retorna -1
*/
Compra* compra_constructor(char* nombreCliente,int idProducto,float precioUnitario,int unidades,float iva,float montoTotal)
{
	Compra* this = malloc(sizeof(Compra));

	if(this != NULL)
	{
		if(	!compra_setNombreCliente(this,nombreCliente) &&
			!compra_setIdProducto(this,idProducto) &&
			!compra_setPrecioUnitario(this,precioUnitario) &&
			!compra_setUnidades(this,unidades) &&
			!compra_setIva(this,iva) &&
			!compra_setMontoTotal(this,montoTotal) &&
			)
		{
			return this;
		}
		else
		{
			compra_destructor(this);
			return NULL;
		}
	}
}

/**
*\brief Es el destructor del elemento que funciona para liberar memoria reservada
*\param this Es el elemento para eliminar
*\return Retorna 0 si logra eliminar elemento sino retorna -1
*/
int compra_destructor(Compra* this)
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
*\brief Es el setter del campo nombreCliente del elemento
*\param this Es el elemento que se recibe para setear un campo
*\param nombreCliente Es el dato recibido para setear el campo
*\return Retorna 0 si el elemento existe y si el dato es valido sino retorna COMPLETAR
*/
int compra_setNombreCliente(Compra* this,char* nombreCliente)
{
	int retorno = -1;
	if(this != NULL && nombreCliente != NULL && isValidNombreCliente(nombreCliente))
	{
		strcpy(this->nombreCliente,nombreCliente);
		retorno = 0;
	}
	return = retorno;
}

/**
*\brief Es el setter del campo idProducto del elemento
*\param this Es el elemento que se recibe para setear un campo
*\param idProducto Es el dato recibido para setear el campo
*\return Retorna 0 si el elemento existe y si el dato es valido sino retorna COMPLETAR
*/
int compra_setIdProducto(Compra* this,int idProducto)
{
	int retorno = -1;
	if(this != NULL && isValidIdProducto(idProducto))
	{
		this->idProducto = idProducto;
		retorno = 0;
	}
	return = retorno;
}

/**
*\brief Es el setter del campo precioUnitario del elemento
*\param this Es el elemento que se recibe para setear un campo
*\param precioUnitario Es el dato recibido para setear el campo
*\return Retorna 0 si el elemento existe y si el dato es valido sino retorna COMPLETAR
*/
int compra_setPrecioUnitario(Compra* this,float precioUnitario)
{
	int retorno = -1;
	if(this != NULL && isValidPrecioUnitario(precioUnitario))
	{
		this->precioUnitario = precioUnitario;
		retorno = 0;
	}
	return = retorno;
}

/**
*\brief Es el setter del campo unidades del elemento
*\param this Es el elemento que se recibe para setear un campo
*\param unidades Es el dato recibido para setear el campo
*\return Retorna 0 si el elemento existe y si el dato es valido sino retorna COMPLETAR
*/
int compra_setUnidades(Compra* this,int unidades)
{
	int retorno = -1;
	if(this != NULL && isValidUnidades(unidades))
	{
		this->unidades = unidades;
		retorno = 0;
	}
	return = retorno;
}

/**
*\brief Es el setter del campo iva del elemento
*\param this Es el elemento que se recibe para setear un campo
*\param iva Es el dato recibido para setear el campo
*\return Retorna 0 si el elemento existe y si el dato es valido sino retorna COMPLETAR
*/
int compra_setIva(Compra* this,float iva)
{
	int retorno = -1;
	if(this != NULL && isValidIva(iva))
	{
		this->iva = iva;
		retorno = 0;
	}
	return = retorno;
}

/**
*\brief Es el setter del campo montoTotal del elemento
*\param this Es el elemento que se recibe para setear un campo
*\param montoTotal Es el dato recibido para setear el campo
*\return Retorna 0 si el elemento existe y si el dato es valido sino retorna COMPLETAR
*/
int compra_setMontoTotal(Compra* this,float montoTotal)
{
	int retorno = -1;
	if(this != NULL && isValidMontoTotal(montoTotal))
	{
		this->montoTotal = montoTotal;
		retorno = 0;
	}
	return = retorno;
}

/**
*\brief Es el getter del campo nombreCliente del elemento
*\param this Es el elemento del cual se obtiene el dato nombreCliente
*\return Retorna 0 si el elemento existe y si el dato es valido sino retorna COMPLETAR
*/
char* compra_getNombreCliente(Compra* this)
{
	char* retorno = NULL;
	if(this != NULL)
	{
		strcpy(retorno,this->nombreCliente);
	}
	return = retorno;
}

/**
*\brief Es el getter del campo idProducto del elemento
*\param this Es el elemento del cual se obtiene el dato idProducto
*\return Retorna 0 si el elemento existe y si el dato es valido sino retorna COMPLETAR
*/
int compra_getIdProducto(Compra* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		retorno = this->idProducto;
	}
	return = retorno;
}

/**
*\brief Es el getter del campo precioUnitario del elemento
*\param this Es el elemento del cual se obtiene el dato precioUnitario
*\return Retorna 0 si el elemento existe y si el dato es valido sino retorna COMPLETAR
*/
float compra_getPrecioUnitario(Compra* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		retorno = this->precioUnitario;
	}
	return = retorno;
}

/**
*\brief Es el getter del campo unidades del elemento
*\param this Es el elemento del cual se obtiene el dato unidades
*\return Retorna 0 si el elemento existe y si el dato es valido sino retorna COMPLETAR
*/
int compra_getUnidades(Compra* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		retorno = this->unidades;
	}
	return = retorno;
}

/**
*\brief Es el getter del campo iva del elemento
*\param this Es el elemento del cual se obtiene el dato iva
*\return Retorna 0 si el elemento existe y si el dato es valido sino retorna COMPLETAR
*/
float compra_getIva(Compra* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		retorno = this->iva;
	}
	return = retorno;
}

/**
*\brief Es el getter del campo montoTotal del elemento
*\param this Es el elemento del cual se obtiene el dato montoTotal
*\return Retorna 0 si el elemento existe y si el dato es valido sino retorna COMPLETAR
*/
float compra_getMontoTotal(Compra* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		retorno = this->montoTotal;
	}
	return = retorno;
}

/**
*\brief Retorna un elemento segun el dato nombreCliente ingresado
*\param pArray Es el puntero a LinkedList recibido para buscar elemento
*\param nombreCliente Es el dato que se recibe para encontrar el elemento
*\return Retorna el elemento si lo encuentra sino retorna NULL
*/
Compra* compra_getByNombreCliente(LinkedList* pArray,char* nombreCliente)
{
	int i;
	Compra* aux;
	Compra* retorno=NULL;

	if(pArray != NULL && isValidNombreCliente(nombreCliente))
	{
		for(i=0;i<ll_len(pArray);i++)
		{
			aux = ll_get(pArray,i);
			if(strcmp(nombreCliente,compra_getNombreCliente(aux))==0)
			{
				retorno = aux;
				break;
			}
		}
	}
	return retorno;
}

/**
*\brief Retorna un elemento segun el dato idProducto ingresado
*\param pArray Es el puntero a LinkedList recibido para buscar elemento
*\param idProducto Es el dato que se recibe para encontrar el elemento
*\return Retorna el elemento si lo encuentra sino retorna NULL
*/
Compra* compra_getByIdProducto(LinkedList* pArray,int idProducto)
{
	int i;
	Compra* aux;
	Compra* retorno=NULL;

	if(pArray != NULL && isValidIdProducto(idProducto))
	{
		for(i=0;i<ll_len(pArray);i++)
		{
			aux = ll_get(pArray,i);
			if(idProducto == compra_getIdProducto(aux))
			{
				retorno = aux;
				break;
			}
		}
	}
	return retorno;
}

/**
*\brief Retorna un elemento segun el dato precioUnitario ingresado
*\param pArray Es el puntero a LinkedList recibido para buscar elemento
*\param precioUnitario Es el dato que se recibe para encontrar el elemento
*\return Retorna el elemento si lo encuentra sino retorna NULL
*/
Compra* compra_getByPrecioUnitario(LinkedList* pArray,float precioUnitario)
{
	int i;
	Compra* aux;
	Compra* retorno=NULL;

	if(pArray != NULL && isValidPrecioUnitario(precioUnitario))
	{
		for(i=0;i<ll_len(pArray);i++)
		{
			aux = ll_get(pArray,i);
			if(precioUnitario == compra_getPrecioUnitario(aux))
			{
				retorno = aux;
				break;
			}
		}
	}
	return retorno;
}

/**
*\brief Retorna un elemento segun el dato unidades ingresado
*\param pArray Es el puntero a LinkedList recibido para buscar elemento
*\param unidades Es el dato que se recibe para encontrar el elemento
*\return Retorna el elemento si lo encuentra sino retorna NULL
*/
Compra* compra_getByUnidades(LinkedList* pArray,int unidades)
{
	int i;
	Compra* aux;
	Compra* retorno=NULL;

	if(pArray != NULL && isValidUnidades(unidades))
	{
		for(i=0;i<ll_len(pArray);i++)
		{
			aux = ll_get(pArray,i);
			if(unidades == compra_getUnidades(aux))
			{
				retorno = aux;
				break;
			}
		}
	}
	return retorno;
}

/**
*\brief Retorna un elemento segun el dato iva ingresado
*\param pArray Es el puntero a LinkedList recibido para buscar elemento
*\param iva Es el dato que se recibe para encontrar el elemento
*\return Retorna el elemento si lo encuentra sino retorna NULL
*/
Compra* compra_getByIva(LinkedList* pArray,float iva)
{
	int i;
	Compra* aux;
	Compra* retorno=NULL;

	if(pArray != NULL && isValidIva(iva))
	{
		for(i=0;i<ll_len(pArray);i++)
		{
			aux = ll_get(pArray,i);
			if(iva == compra_getIva(aux))
			{
				retorno = aux;
				break;
			}
		}
	}
	return retorno;
}

/**
*\brief Retorna un elemento segun el dato montoTotal ingresado
*\param pArray Es el puntero a LinkedList recibido para buscar elemento
*\param montoTotal Es el dato que se recibe para encontrar el elemento
*\return Retorna el elemento si lo encuentra sino retorna NULL
*/
Compra* compra_getByMontoTotal(LinkedList* pArray,float montoTotal)
{
	int i;
	Compra* aux;
	Compra* retorno=NULL;

	if(pArray != NULL && isValidMontoTotal(montoTotal))
	{
		for(i=0;i<ll_len(pArray);i++)
		{
			aux = ll_get(pArray,i);
			if(montoTotal == compra_getMontoTotal(aux))
			{
				retorno = aux;
				break;
			}
		}
	}
	return retorno;
}

/**
*\brief Compara dos elementos por su campo nombreCliente
*\param thisA Es el puntero al primer elemento a comparar
*\param thisB Es el puntero al segundo elemento a comparar
*\return Retorna 0 si ambos campos son iguales
		Retorna 1 si el campo del primer elemento es mayor al segundo
		Retorna -1 si el campo del segundo elemento es mayor al primero
*/
int compra_compareByNombreCliente(void* thisA ,void* thisB)
{
	int retorno = 0;

	if(thisA != NULL && thisB != NULL)
	{
		retorno = strcmp(compra_getNombreCliente(thisA),compra_getNombreCliente(thisB));
	}
	return retorno;
}

/**
*\brief Compara dos elementos por su campo idProducto
*\param thisA Es el puntero al primer elemento a comparar
*\param thisB Es el puntero al segundo elemento a comparar
*\return Retorna 0 si ambos campos son iguales
		Retorna 1 si el campo del primer elemento es mayor al segundo
		Retorna -1 si el campo del segundo elemento es mayor al primero
*/
int compra_compareByIdProducto(void* thisA ,void* thisB)
{
	int retorno = 0;

	if(thisA != NULL && thisB != NULL)
	{
		if(compra_getIdProducto(thisA) > compra_getIdProducto(thisB))
		{
				retorno = 1;
		}
		else if(compra_getIdProducto(thisA) < compra_getIdProducto(thisB))
		{
			retorno = -1;
		}
	}
	return retorno;
}

/**
*\brief Compara dos elementos por su campo precioUnitario
*\param thisA Es el puntero al primer elemento a comparar
*\param thisB Es el puntero al segundo elemento a comparar
*\return Retorna 0 si ambos campos son iguales
		Retorna 1 si el campo del primer elemento es mayor al segundo
		Retorna -1 si el campo del segundo elemento es mayor al primero
*/
int compra_compareByPrecioUnitario(void* thisA ,void* thisB)
{
	int retorno = 0;

	if(thisA != NULL && thisB != NULL)
	{
		if(compra_getPrecioUnitario(thisA) > compra_getPrecioUnitario(thisB))
		{
				retorno = 1;
		}
		else if(compra_getPrecioUnitario(thisA) < compra_getPrecioUnitario(thisB))
		{
			retorno = -1;
		}
	}
	return retorno;
}

/**
*\brief Compara dos elementos por su campo unidades
*\param thisA Es el puntero al primer elemento a comparar
*\param thisB Es el puntero al segundo elemento a comparar
*\return Retorna 0 si ambos campos son iguales
		Retorna 1 si el campo del primer elemento es mayor al segundo
		Retorna -1 si el campo del segundo elemento es mayor al primero
*/
int compra_compareByUnidades(void* thisA ,void* thisB)
{
	int retorno = 0;

	if(thisA != NULL && thisB != NULL)
	{
		if(compra_getUnidades(thisA) > compra_getUnidades(thisB))
		{
				retorno = 1;
		}
		else if(compra_getUnidades(thisA) < compra_getUnidades(thisB))
		{
			retorno = -1;
		}
	}
	return retorno;
}

/**
*\brief Compara dos elementos por su campo iva
*\param thisA Es el puntero al primer elemento a comparar
*\param thisB Es el puntero al segundo elemento a comparar
*\return Retorna 0 si ambos campos son iguales
		Retorna 1 si el campo del primer elemento es mayor al segundo
		Retorna -1 si el campo del segundo elemento es mayor al primero
*/
int compra_compareByIva(void* thisA ,void* thisB)
{
	int retorno = 0;

	if(thisA != NULL && thisB != NULL)
	{
		if(compra_getIva(thisA) > compra_getIva(thisB))
		{
				retorno = 1;
		}
		else if(compra_getIva(thisA) < compra_getIva(thisB))
		{
			retorno = -1;
		}
	}
	return retorno;
}

/**
*\brief Compara dos elementos por su campo montoTotal
*\param thisA Es el puntero al primer elemento a comparar
*\param thisB Es el puntero al segundo elemento a comparar
*\return Retorna 0 si ambos campos son iguales
		Retorna 1 si el campo del primer elemento es mayor al segundo
		Retorna -1 si el campo del segundo elemento es mayor al primero
*/
int compra_compareByMontoTotal(void* thisA ,void* thisB)
{
	int retorno = 0;

	if(thisA != NULL && thisB != NULL)
	{
		if(compra_getMontoTotal(thisA) > compra_getMontoTotal(thisB))
		{
				retorno = 1;
		}
		else if(compra_getMontoTotal(thisA) < compra_getMontoTotal(thisB))
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
int compra_show(Compra* this)
{
	if(this != NULL)
	{
		printf("\nNombreCliente -- %s",compra_getNombreCliente(this));
		printf("\nIdProducto -- %d",compra_getIdProducto(this));
		printf("\nPrecioUnitario -- %d",compra_getPrecioUnitario(this));
		printf("\nUnidades -- %d",compra_getUnidades(this));
		printf("\nIva -- %d",compra_getIva(this));
		printf("\nMontoTotal -- %d",compra_getMontoTotal(this));
		retorno = 0;
	}
	return retorno;
}



********************* Compra.c ************************


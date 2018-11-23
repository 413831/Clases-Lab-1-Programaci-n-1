

********************* Compra.h ************************

#include "LinkedList.h"

#ifndef _COMPRA_H
#define _COMPRA_H
typedef struct
{
	char nombreCliente[128];
	int idProducto;
	float precioUnitario;
	int unidades;
	float iva;
	float montoTotal;
}Compra;
#endif// _COMPRA_H


#define BUFFER 4000
#define LEN_LL 6
Compra* compra_constructor(char* nombreCliente,int idProducto,float precioUnitario,int unidades,float iva,float montoTotal);
int compra_destructor(Compra* this);
int compra_setNombreCliente(Compra* this,char* nombreCliente);
int compra_setIdProducto(Compra* this,int idProducto);
int compra_setPrecioUnitario(Compra* this,float precioUnitario);
int compra_setUnidades(Compra* this,int unidades);
int compra_setIva(Compra* this,float iva);
int compra_setMontoTotal(Compra* this,float montoTotal);
char* compra_getNombreCliente(Compra* this);
int compra_getIdProducto(Compra* this);
float compra_getPrecioUnitario(Compra* this);
int compra_getUnidades(Compra* this);
float compra_getIva(Compra* this);
float compra_getMontoTotal(Compra* this);
Compra* compra_getByNombreCliente(LinkedList* pArray,char* nombreCliente);
Compra* compra_getByIdProducto(LinkedList* pArray,int idProducto);
Compra* compra_getByPrecioUnitario(LinkedList* pArray,float precioUnitario);
Compra* compra_getByUnidades(LinkedList* pArray,int unidades);
Compra* compra_getByIva(LinkedList* pArray,float iva);
Compra* compra_getByMontoTotal(LinkedList* pArray,float montoTotal);
int compra_compareByNombreCliente(void* thisA ,void* thisB);
int compra_compareByIdProducto(void* thisA ,void* thisB);
int compra_compareByPrecioUnitario(void* thisA ,void* thisB);
int compra_compareByUnidades(void* thisA ,void* thisB);
int compra_compareByIva(void* thisA ,void* thisB);
int compra_compareByMontoTotal(void* thisA ,void* thisB);
int compra_show(Compra* this);


********************* Compra.h ************************


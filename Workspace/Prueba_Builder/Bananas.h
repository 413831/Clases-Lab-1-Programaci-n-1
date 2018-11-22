
#include "LinkedList.h"

#ifndef _BANANAS_H
#define _BANANAS_H
typedef struct
{
	int cantidad;
	int precio;
	char origen[30];
	int id;
	int isEmpty;
}Bananas;
#endif// _BANANAS_H


#define BUFFER 4000
#define LEN_LL 6

Bananas* bananas_constructor(int cantidad,int precio,char* origen,int id,int isEmpty);
int bananas_destructor(Bananas* this);
int bananas_setCantidad(Bananas* this,int cantidad);
int bananas_setPrecio(Bananas* this,int precio);
int bananas_setOrigen(Bananas* this,char* origen);
int bananas_setId(Bananas* this,int id);
int bananas_setIsEmpty(Bananas* this,int isEmpty);
int bananas_getCantidad(Bananas* this);
int bananas_getPrecio(Bananas* this);
char* bananas_getOrigen(Bananas* this);
int bananas_getId(Bananas* this);
int bananas_getIsEmpty(Bananas* this);
Bananas* bananas_getByCantidad(LinkedList* pArray,int cantidad);
Bananas* bananas_getByPrecio(LinkedList* pArray,int precio);
Bananas* bananas_getByOrigen(LinkedList* pArray,char* origen);
Bananas* bananas_getById(LinkedList* pArray,int id);
Bananas* bananas_getByIsEmpty(LinkedList* pArray,int isEmpty);
int bananas_compareByCantidad(void* thisA ,void* thisB);
int bananas_compareByPrecio(void* thisA ,void* thisB);
int bananas_compareByOrigen(void* thisA ,void* thisB);
int bananas_compareById(void* thisA ,void* thisB);
int bananas_compareByIsEmpty(void* thisA ,void* thisB);
int bananas_show(Bananas* this);


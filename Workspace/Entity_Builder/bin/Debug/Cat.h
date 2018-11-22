

********************* Cat.h ************************

#include "LinkedList.h"

#ifndef _CAT_H
#define _CAT_H
typedef struct
{
	char nombre[50];
	char color[30];
	char sexo[20];
	int edad;
	int id;
}Cat;
#endif// _CAT_H


#define BUFFER 4000
#define LEN_LL 6Cat* cat_newConParametros(char* nombre,char* color,char* sexo,int edad,int id);
int cat_delete(Cat* this);
int cat_setNombre(Cat* this,char* nombre);
int cat_setColor(Cat* this,char* color);
int cat_setSexo(Cat* this,char* sexo);
int cat_setEdad(Cat* this,int edad);
int cat_setId(Cat* this,int id);
char* cat_getNombre(Cat* this);
char* cat_getColor(Cat* this);
char* cat_getSexo(Cat* this);
int cat_getEdad(Cat* this);
int cat_getId(Cat* this);
Cat* cat_getByNombre(LinkedList* pArray,char* nombre);
Cat* cat_getByColor(LinkedList* pArray,char* color);
Cat* cat_getBySexo(LinkedList* pArray,char* sexo);
Cat* cat_getByEdad(LinkedList* pArray,int edad);
Cat* cat_getById(LinkedList* pArray,int id);
int cat_compareByNombre(void* pA ,void* pB);
int cat_compareByColor(void* pA ,void* pB);
int cat_compareBySexo(void* pA ,void* pB);
int cat_compareByEdad(void* pA ,void* pB);
int cat_compareById(void* pA ,void* pB);


********************* Cat.h ************************


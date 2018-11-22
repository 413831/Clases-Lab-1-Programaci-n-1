

********************* Person.h ************************

#include "LinkedList.h"

#ifndef _PERSON_H
#define _PERSON_H
typedef struct
{
	char name[50];
	char lastName[50];
	int age;
	char address[50];
	int id;
}Person;
#endif// _PERSON_H


#define BUFFER 4000
#define LEN_LL 6Person* person_constructor(char* name,char* lastName,int age,char* address,int id);
int person_destructor(Person* this);
int person_setName(Person* this,char* name);
int person_setLastName(Person* this,char* lastName);
int person_setAge(Person* this,int age);
int person_setAddress(Person* this,char* address);
int person_setId(Person* this,int id);
char* person_getName(Person* this);
char* person_getLastName(Person* this);
int person_getAge(Person* this);
char* person_getAddress(Person* this);
int person_getId(Person* this);
Person* person_getByName(LinkedList* pArray,char* name);
Person* person_getByLastName(LinkedList* pArray,char* lastName);
Person* person_getByAge(LinkedList* pArray,int age);
Person* person_getByAddress(LinkedList* pArray,char* address);
Person* person_getById(LinkedList* pArray,int id);
int person_compareByName(void* thisA ,void* thisB);
int person_compareByLastName(void* thisA ,void* thisB);
int person_compareByAge(void* thisA ,void* thisB);
int person_compareByAddress(void* thisA ,void* thisB);
int person_compareById(void* thisA ,void* thisB);
int person_show(Person* this);


********************* Person.h ************************


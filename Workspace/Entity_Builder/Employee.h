

********************* Employee.h ************************

#include "LinkedList.h"

#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H
typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	int age;
	int type;
}Employee;
#endif// _EMPLOYEE_H


#define BUFFER 4000
#define LEN_LL 6
Employee* employee_constructor(int id,char* name,char* lastName,int age,int type);
int employee_destructor(Employee* this);
int employee_setId(Employee* this,int id);
int employee_setName(Employee* this,char* name);
int employee_setLastName(Employee* this,char* lastName);
int employee_setAge(Employee* this,int age);
int employee_setType(Employee* this,int type);
int employee_getId(Employee* this);
char* employee_getName(Employee* this);
char* employee_getLastName(Employee* this);
int employee_getAge(Employee* this);
int employee_getType(Employee* this);
Employee* employee_getById(LinkedList* pArray,int id);
Employee* employee_getByName(LinkedList* pArray,char* name);
Employee* employee_getByLastName(LinkedList* pArray,char* lastName);
Employee* employee_getByAge(LinkedList* pArray,int age);
Employee* employee_getByType(LinkedList* pArray,int type);
int employee_compareById(void* thisA ,void* thisB);
int employee_compareByName(void* thisA ,void* thisB);
int employee_compareByLastName(void* thisA ,void* thisB);
int employee_compareByAge(void* thisA ,void* thisB);
int employee_compareByType(void* thisA ,void* thisB);
int employee_show(Employee* this);


********************* Employee.h ************************


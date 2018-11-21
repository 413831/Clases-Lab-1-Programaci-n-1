#include "../inc/LinkedList.h"
#ifndef people_H_INCLUDED
#define people_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    char apellido[128];
    int sueldo;
    //
    int isEmpty;
}People;

typedef int (*function_type)(void* thisA,void* thisB);
typedef int (*criterio_type)(void* this);

People* people_new();
People* people_newConParametros(char* id,char* nombre,char* apellido,char* isEmpty,char* sueldo);
People* people_getById(void* pArrayListPeople,int idIngresado);
int people_add(void* pArrayListPeople);
int people_remove(void* pLinkedList,void* pListInactives);
int people_delete(People* this);
int people_copy(People* thisA,People* thisB);
int people_replace(LinkedList* pLinkedList,void* auxElement,int index);
int people_insert(LinkedList* pListActives,LinkedList* pListInactives);
int people_edit(void* pArrayListPeople);

int people_show(void* this);
int people_sort(void* pArrayListPeople);
int people_aumentarSueldo(void* this,int porcentaje);
void* people_ordenCriterio();
int people_generarLista(LinkedList* pLinkedList,LinkedList* listaPrincipal[],int* index);
void* people_selectorCriterio();
int people_borrarLista(LinkedList* pLinkedList[]);
int people_hardcode(void* pLinkedList,char *bufferName,char* bufferLastName,char* bufferIsEmpty,char* bufferSueldo);

int people_setId(People* this,int id);
int people_getId(People* this,int* id);

int people_setNombre(People* this,char* nombre);
int people_getNombre(People* this,char* nombre);

int people_setApellido(People* this,char* apellido);
int people_getApellido(People* this,char* apellido);

int people_setIsEmpty(People* this,int isEmpty);
int people_getIsEmpty(People* this,int* isEmpty);

int people_setSueldo(People* this,int sueldo);
int people_getSueldo(People* this,int* sueldo);

int people_setAll(People* this,int id,char* name,char* lastName,int salary,int isEmpty);
int people_getAll(People* this,int* id,char* name,char* lastName,int* salary,int* isEmpty);


#endif // people_H_INCLUDED

#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

typedef struct
{
    char* name;
    char* lastName;
    ////////////
    char* id;
    char* status;

}Person;

int generateID();

int person_init(Person* person[],int size);
Person* person_newParametros(char* name, char* lastName,char* id,char* status);
int person_constructor(Person** person);
int person_destructor(Person* this);
int person_searchEmpty(Person* array[], int size);
int person_setId(Person* this,char* id);
int person_setStatus(Person* this,char* status);
int person_setName(Person* this,char* name);
int person_setLastName(Person* this,char* lastName);
int person_getId(Person* this,char* id);
int person_getStatus(Person* this,char* status);
int person_getName(Person* this,char* name);
int person_getlastName(Person* this,char* lastName);
Person* person_getById(Person* array[],int size,int id);

int person_showArray(Person* person);
int person_resizeArray(Person** array,int newsize);
#endif // PERSON_H_INCLUDED

#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

typedef struct
{
    char* name;
    char* lastName;
    ////////////
    int id;
    int status;

}Person;

int generateID();

int person_init(Person* person[],int size);
int person_constructor(Person** person);
int person_destructor(Person* this);
int person_searchEmpty(Person* array[], int size);
int person_setName(Person* this,char* name);
int person_setLastName(Person* this,char* lastName);
int person_getName(Person* this,char* name);
int person_getlastName(Person* this,char* lastName);
Person* person_getById(Person* array[],int size,int id);

int person_showArray(Person* person);
int person_resizeArray(Person** array,int newsize);
#endif // PERSON_H_INCLUDED



typedef struct
{
    char* name;
    char* lastName;
    int* age;
    char* adress;
    ////////////
    int id;
    int isEmpty;

}Person;

int generateID();
int person_initArray(Person* person,int value);
int person_showArray(Person* person);
int person_constructor(Person** person);
int person_destructor(Person* array);
int person_resizeArray(Person** array,int newsize);
int person_create(Person** person);

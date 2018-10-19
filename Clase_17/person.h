

typedef struct
{
    char name[30];
    char lastName[30];
    int age;
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
int person_cargar(Person* person);
int person_setAge(Person* person);
int person_getName(Person* person);
int person_setName(Person* person);

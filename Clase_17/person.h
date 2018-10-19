

typedef struct
{
    char* name;
    char* lastName;
    int age;
    char* adress;
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
int person_setAge(Person* this,int age);
int person_setAdress(Person* this,char* adress);
int person_getName(Person* this,char* name);
int person_getlastName(Person* this,char* lastName);
int person_getAge(Person* this,int* age);
int person_getAdress(Person* this,char* adress);
Person* person_getById(Person* array[],int size,int id);

int person_showArray(Person* person);
int person_resizeArray(Person** array,int newsize);





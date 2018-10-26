#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newConParametros(char* id,char* nombre,char* horasTrabajadas,char* sueldo);
int employee_input(char* campo,int size);
int employee_EmployeeFromUser(void* pArrayListEmployee);
int employee_sort(void* thisA,void* thisB);
void employee_delete();

int employee_setId(Employee* this,char* id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,char* horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,char* sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_searchEmpty(Employee* array[], int size);

#endif // employee_H_INCLUDED

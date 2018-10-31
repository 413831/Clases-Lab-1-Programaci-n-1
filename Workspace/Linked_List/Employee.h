#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    float sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newConParametros(char* id,char* nombre,char* horasTrabajadas,char* sueldo);
int employee_EmployeeFromUser(void* pArrayListEmployee);
int employee_edit(void* pArrayListEmployee);
int employee_modify(void* pArrayListEmployee,
                        char* mensaje,
                        int (*validacion)(char*),
                        int (*set)(Employee*,char*));
int employee_remove(void* pArrayListEmployee);

int employee_input(char* mensaje,char* campo,int size, int (*pFunc)(char*));
int employee_sort(void* thisA,void* thisB);
int employee_delete();

int employee_setId(Employee* this,char* id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,char* horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,char* sueldo);
int employee_getSueldo(Employee* this,float* sueldo);

int employee_setAll(Employee* this,char* name,char* hours,char* salary);
int employee_getAll(Employee* this,char* name,int* hours,float* salary,int* id);

int employee_searchEmpty(Employee* array[], int size);
int employee_show(Employee* this);

#endif // employee_H_INCLUDED

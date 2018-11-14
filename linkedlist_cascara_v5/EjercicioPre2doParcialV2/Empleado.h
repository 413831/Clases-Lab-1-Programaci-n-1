#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

typedef struct S_Empleado
{
  int id;
  char nombre[128];
  int horasTrabajadas;
  float sueldo;
}Empleado;

void employee_calcularSueldo(void* pEmpleado);
Empleado* employee_newConParametros(char* id,char* nombre,char* horasTrabajadas,char* sueldo);
int employee_delete(Empleado* this);

int employee_setId(Empleado* this,char* id);
int employee_getId(Empleado* this,int* id);

int employee_setNombre(Empleado* this,char* nombre);
int employee_getNombre(Empleado* this,char* nombre);

int employee_setHorasTrabajadas(Empleado* this,char* horasTrabajadas);
int employee_getHorasTrabajadas(Empleado* this,int* horasTrabajadas);

int employee_setSueldo(Empleado* this,char* sueldo);
int employee_getSueldo(Empleado* this,float* sueldo);

int employee_setAll(Empleado* this,char* id,char* name,char* hours,char* salary);
int employee_getAll(Empleado* this,char* name,int* hours,float* salary,int* id);



#endif // EMPLEADO_H_INCLUDED

#include "Employee.h"
#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"


static int isValidName(char* name)
{
    int retorno = 0;

    if(name != NULL && strlen(name) < 30  && strlen(name) > 1)
    {
        retorno = 1;
    }
    return retorno;
}


static int isValidHoras(char* horas)//CORREGIR
{
    int retorno = 0;

    if(horas != NULL && strlen(horas) < 30  && strlen(horas) > 1)
    {
        retorno = 1;
    }
    return retorno;
}


static int isValidSueldo(char* sueldo)//CORREGIR
{
    int retorno = 0;

    if(sueldo != NULL && strlen(sueldo) < 30  && strlen(sueldo) > 1)
    {
        retorno = 1;
    }
    return retorno;
}


//////////////////////////////////////////////////////////////////////////////////////////

Employee* employee_new()
{
    Employee* this;
    this=malloc(sizeof(Employee));
    return this;
}

void employee_delete(Employee* this)
{
    free(this);
}

int employee_input(char* campo,int size)
{
    int retorno = -1;
    if(campo != NULL)
    {
        input_getString(campo,size);
        retorno = 0;
    }
    return retorno;
}

int employee_EmployeeFromUser(void* pArrayListEmployee)
{
    Employee* pEmployee;
    int retorno = -1;
    char bufferId[1000];
    char bufferName[1000];
    char bufferHorasTrabajadas[1000];
    char bufferSueldo[1000];

    printf("\n ID");
    employee_input(bufferId,1000);
    printf("\n NOMBRE");
    employee_input(bufferName,1000);
    printf("\n HORAS");
    employee_input(bufferHorasTrabajadas,1000);
    printf("\n SUELDO");
    employee_input(bufferSueldo,1000);

    if(bufferId != NULL && bufferName!= NULL && bufferHorasTrabajadas != NULL && bufferSueldo != NULL)
    {
        pEmployee = employee_newConParametros(bufferId,bufferName,bufferHorasTrabajadas,bufferSueldo);
        if(pEmployee != NULL)
        {
            ll_add(pArrayListEmployee,pEmployee);//Se agrega ELEMENTO a LINKED LIST
            retorno = 0;
        }
    }
    return retorno;
}

Employee* employee_newConParametros(char* id,char* nombre,char* horasTrabajadas,char* sueldo)
{
    Employee* this;
    this=employee_new();

    /////VALIDAR////////////////////////!!!!!

    if( !employee_setId(this,id)&&
        !employee_setNombre(this,nombre)&&
        !employee_setHorasTrabajadas(this,horasTrabajadas)&&
        !employee_setSueldo(this,sueldo))
    {
        return this;
    }
    else
    {
        employee_delete(this);
        return NULL;
    }
}

int employee_setId(Employee* this,char* id)////////VALIDAR ID INICIAL CONTRA ARCHIVO
{
    int retorno=-1;
    static int proximoId=-1;
    int auxId = atoi(id);

    if(this!=NULL && auxId==-1)
    {
        proximoId++;
        this->id=proximoId;
        retorno=0;
    }
    else if(auxId>proximoId)
    {
        proximoId=auxId;
        this->id=proximoId;
        retorno=0;
    }
    return retorno;
}

int employee_getId(Employee* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL && isValidName(nombre))
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,char* horasTrabajadas)
{
    int retorno=-1;
    int auxHorasTrabajadas;

    if(this!=NULL && isValidHoras(horasTrabajadas))
    {
        auxHorasTrabajadas = atoi(horasTrabajadas);
        this->horasTrabajadas = auxHorasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int employee_setSueldo(Employee* this,char* sueldo)
{
    int retorno=-1;
    int auxSueldo;

    if(this!=NULL && isValidSueldo(sueldo))
    {
        auxSueldo = atoi(sueldo);
        this->sueldo=auxSueldo;
        retorno=0;
    }
    return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *sueldo=this->sueldo;
        retorno=0;
    }
    return retorno;
}


int employee_searchEmpty(Employee* array[], int size)
{
    int i;
    int retorno =-1;
    if(array!=NULL && size > 0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i]==NULL)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

int employee_sort(void* thisA,void* thisB)
{
    int retorno = 0;
    char nombreEmployeeA[50];
    char nombreEmployeeB[50];
    employee_getNombre(thisA,nombreEmployeeA);
    employee_getNombre(thisB,nombreEmployeeB);

    if(strcmp(nombreEmployeeA,nombreEmployeeB) > 0 )
    {
        retorno = 1;
    }
    else if(strcmp(nombreEmployeeA,nombreEmployeeB) < 0)
    {
        retorno = -1;
    }
    return retorno;
}


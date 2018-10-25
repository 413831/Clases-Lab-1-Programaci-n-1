#include "Employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int isValidStatus(char* status)
{
    int retorno = 0;

    if(strcmp("true",status) == 0 ||
        strcmp("false",status))
    {
        retorno = 1;
    }
    return retorno;
}

static int isValidName(char* name)
{
    int retorno = 0;

    if(name != NULL && strlen(name) < 30  && strlen(name) > 1)
    {
        retorno = 1;
    }
    return retorno;
}

static int isValidLastName(char* lastName)
{
    int retorno = 0;

    if(lastName != NULL && strlen(lastName) < 30 && strlen(lastName) > 1)
    {
        retorno = 1;
    }
    return retorno;
}

//////////////////////////////////////////////////////////////

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

Employee* employee_newConParametros(char* id,char* nombre,char* horasTrabajadas,char* sueldo)
{
    Employee* this;
    this=employee_new();
    int auxHorasTrabajadas;
    int auxSueldo;
    int auxId;
    /////VALIDAR////////////////////////!!!!!
    auxHorasTrabajadas = atoi(horasTrabajadas);
    auxSueldo = atoi(sueldo);
    auxId = atoi(id);

    if(
    !employee_setId(this,auxId)&&
    !employee_setNombre(this,nombre)&&
    !employee_setHorasTrabajadas(this,auxHorasTrabajadas)&&
    !employee_setSueldo(this,auxSueldo))
        return this;

    employee_delete(this);
    return NULL;
}

int employee_setId(Employee* this,int id)////////VALIDAR ID INICIAL CONTRA ARCHIVO
{
    int retorno=-1;
    static int proximoId=-1;

    if(this!=NULL && id==-1)
    {
        proximoId++;
        this->id=proximoId;
        retorno=0;
    }
    else if(id>proximoId)
    {
        proximoId=id;
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
    if(this!=NULL && nombre!=NULL)
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

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->horasTrabajadas=horasTrabajadas;
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

int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->sueldo=sueldo;
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


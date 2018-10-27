#include "Employee.h"
#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

static int isValidName(char* name)
{
    int retorno = 0;

    if(name != NULL && validacion_Letras(name,strlen(name)))
    {
        retorno = 1;
    }
    return retorno;
}

static int isValidHoras(char* horas)//CORREGIR
{
    int retorno = 0;
    int digitosIngresados = strlen(horas);

    if(horas != NULL && validacion_Int(horas,digitosIngresados))
    {
        retorno = 1;
    }
    return retorno;
}

static int isValidSueldo(char* sueldo)//CORREGIR
{
    int retorno = 0;
    int digitosIngresados = strlen(sueldo);

    if(sueldo != NULL && strlen(sueldo) > 4  && validacion_Float(sueldo,digitosIngresados))
    {
        retorno = 1;
    }
    return retorno;
}

static int isValidId(char* id)//CORREGIR
{
    int retorno = 0;
    int digitosIngresados = strlen(id);

    if(id != NULL && validacion_Int(id,digitosIngresados))
    {
        retorno = 1;
    }
    return retorno;
}

static int getNextId(LinkedList* pArrayListEmployee)////////VALIDAR ID INICIAL CONTRA ARCHIVO
{
    int retorno=-1;
    int index;

    if(pArrayListEmployee != NULL)
    {
        index = ll_len(pArrayListEmployee);
        retorno = index;
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

int employee_delete(Employee* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

int employee_input(char* campo,int size, int (*pFunc)(char*))
{
    int retorno = -1;
    if(campo != NULL)
    {
        printf("\nIngrese campo: ");
        input_getString(campo,size);
        if(!pFunc(campo))
        {
            retorno = 0;
        }
    }
    return retorno;
}

int employee_EmployeeFromUser(void* pArrayListEmployee)
{
    Employee* this = NULL;
    int retorno = -1;

    char bufferId[1000];
    char bufferName[1000];
    char bufferHorasTrabajadas[1000];
    char bufferSueldo[1000];
    int auxID = getNextId(pArrayListEmployee)+1;

    printf("\n PROXIMO ID %d",auxID);

    employee_input(bufferName,1000,isValidName);
    employee_input(bufferHorasTrabajadas,1000,isValidHoras);
    employee_input(bufferSueldo,1000,isValidSueldo);
    printf("\nNOMBRE: %s",bufferName);
    printf("\nHORAS: %s",bufferHorasTrabajadas);
    printf("\nSUELDO: %s",bufferSueldo);

    if(bufferId != NULL && bufferName!= NULL && bufferHorasTrabajadas != NULL && bufferSueldo != NULL)
    {
        this = employee_newConParametros(bufferId,bufferName,bufferHorasTrabajadas,bufferSueldo);
        printf("\nID: %s",bufferId);
        if(this != NULL)
        {
            ll_add(pArrayListEmployee,this);
            employee_show(this);
            retorno = 0;;
        }
    }
    return retorno;
}

Employee* employee_newConParametros(char* id,char* nombre,char* horasTrabajadas,char* sueldo)
{
    Employee* this;
    this=employee_new();
    /////VALIDAR////////////////////////!!!!!
    if(isValidName(nombre) == 0)
    {
        printf("\nSE ROMPE TODO");
        printf("\nNOMBRE %s",nombre);
        printf("\nID %s",id);
    }

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
    static int proximoId=0;
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
    float auxSueldo;

    if(this!=NULL && isValidSueldo(sueldo))
    {
        auxSueldo = atof(sueldo);
        this->sueldo=auxSueldo;
        retorno=0;
    }
    return retorno;
}

int employee_getSueldo(Employee* this,float* sueldo)
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

int employee_show(Employee* this)
{
    int retorno = -1;
    int auxId;
    char auxNombre[128];
    int auxHorasTrabajadas;
    float auxSueldo;

    if(this != NULL)
    {
        employee_getNombre(this,auxNombre);
        employee_getSueldo(this,&auxSueldo);
        employee_getHorasTrabajadas(this,&auxHorasTrabajadas);
        employee_getId(this,&auxId);

        printf("\nNOMBRE -- %s",auxNombre);
        printf("\nSUELDO -- %f",auxSueldo);
        printf("\nHORAS -- %d",auxHorasTrabajadas);
        printf("\nID -- %d",auxId);

        retorno = 0;
    }
    return retorno;
}

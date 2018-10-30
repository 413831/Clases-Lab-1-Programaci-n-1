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

    if(sueldo != NULL && digitosIngresados > 4 && validacion_Int(sueldo,digitosIngresados))
    {
        retorno = 1;
    }
    return retorno;
}

static int isValidId(char* id)//CORREGIR
{
    int retorno = 0;
    int digitosIngresados = strlen(id);

    if(id != NULL && validacion_Int(id,digitosIngresados) && *id > '0')
    {
        retorno = 1;
    }
    return retorno;
}

static int getNextId(LinkedList* pArrayListEmployee)////////VALIDAR ID INICIAL CONTRA ARCHIVO
{
    int retorno=-1;
    int index;
    Employee* auxEmployee;
    int auxID;

    if(pArrayListEmployee != NULL)
    {
        for(index=0;index<ll_len(pArrayListEmployee);index++)//Recorro todo el array hasta el LEN
        {
            auxEmployee = ll_get(pArrayListEmployee,index);//Obtengo el elemento del array en posicion index
            employee_getId(auxEmployee,&auxID);//Obtengo el ID del elemento
        }
        retorno = auxID+1;//Retorno el ID del ultimo elemento más uno
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


Employee* employee_getById(LinkedList* pArrayListEmployee,int idIngresado)
{
    Employee* retorno = NULL;
    int index;
    Employee* auxEmployee;
    int auxID;

    if(pArrayListEmployee != NULL)
    {
        for(index=0;index<ll_len(pArrayListEmployee);index++)//Recorro todo el array hasta el LEN
        {
            auxEmployee = ll_get(pArrayListEmployee,index);//Obtengo el elemento del array en posicion index
            employee_getId(auxEmployee,&auxID);//Obtengo el ID del elemento
            if(auxID == idIngresado)
            {
                retorno = auxEmployee;
                break;
            }
        }
    }
    return retorno;
}

int employee_input(char* mensaje,char* campo,int size, int (*pFunc)(char*))
{
    int retorno = -1;
    int reintentos = 2;
    if(campo != NULL)
    {
        do
        {
            printf("\nIngrese %s: ",mensaje);
            input_getString(campo,size);
            if((*pFunc)(campo))//Validar segun tipo
            {
                retorno = 0;
                break;
            }
            else
            {
                printf("\nIntente nuevamente");
            }
            reintentos--;
        }while(reintentos > 0);
    }
    return retorno;
}

int employee_setAll(Employee* this,char* name,char* hours,char* salary)
{
    int retorno = -1;

    if(this != NULL)
    {
        employee_setNombre(this,name);
        employee_setHorasTrabajadas(this,hours);
        employee_setSueldo(this,salary);
        retorno = 0;
    }
    return retorno;
}

int employee_getAll(Employee* this,char* name,int* hours,float* salary,int* id)
{
    int retorno = -1;

    if(this != NULL)
    {
        employee_getNombre(this,name);
        employee_getHorasTrabajadas(this,hours);
        employee_getSueldo(this,salary);
        employee_getId(this,id);
        retorno = 0;
    }
    return retorno;
}

int employee_remove(void* pArrayListEmployee)
{
    Employee* this = NULL;
    int retorno = -1;
    char bufferId[1000];
    int idIngresado;
    char option[2];
    int index;

   if(!employee_input("ID",bufferId,1000,isValidId))
    {
        idIngresado = atoi(bufferId);
        this = employee_getById(pArrayListEmployee,idIngresado);
        if(this != NULL)
        {
            employee_show(this);
            index = ll_indexOf(pArrayListEmployee,this);
            input_getLetras(option,2,"\nDesea eliminar? S/N","\nError.Dato invalido",2);
            if(!strcasecmp("s",option))
            {
                employee_delete(this);
                ll_remove(pArrayListEmployee,index);

                retorno = 0;
            }
        }
        else
        {
            printf("\nEl ID ingresado no existe");
        }
    }
    return retorno;
    return retorno;
}

int employee_modify(void* pArrayListEmployee)
{
    Employee* this = NULL;
    int retorno = -1;
    int idIngresado;
    char option[2];

    char bufferId[1000];
    char bufferName[1000];
    char bufferHorasTrabajadas[1000];
    char bufferSueldo[1000];

    if(!employee_input("ID",bufferId,1000,isValidId))
    {
        idIngresado = atoi(bufferId);
        this = employee_getById(pArrayListEmployee,idIngresado);
        if(this != NULL)
        {
            employee_show(this);
            input_getLetras(option,2,"\nDesea modificar datos? S/N","\nError.Dato invalido",2);
            if( !strcasecmp("s",option)&&
                !employee_input("nombre",bufferName,1000,isValidName) &&
                !employee_input("horas trabajadas",bufferHorasTrabajadas,1000,isValidHoras) &&
                !employee_input("sueldo",bufferSueldo,1000,isValidSueldo))
            {
                employee_setAll(this,bufferName,bufferHorasTrabajadas,bufferSueldo);
                employee_show(this);
                retorno = 0;
            }
        }
        else
        {
            printf("\nEl ID ingresado no existe");
        }
    }
    return retorno;
}

int employee_EmployeeFromUser(void* pArrayListEmployee)
{
    Employee* this = NULL;
    int retorno = -1;

    char bufferId[1000] = {"-1"};
    char bufferName[1000];
    char bufferHorasTrabajadas[1000];
    char bufferSueldo[1000];

   // sprintf(bufferId,"%d",auxID);//Int Parse to Str

    if( !employee_input("nombre",bufferName,1000,isValidName) &&
        !employee_input("horas trabajadas",bufferHorasTrabajadas,1000,isValidHoras) &&
        !employee_input("sueldo",bufferSueldo,1000,isValidSueldo))
    {
        this = employee_newConParametros(bufferId,bufferName,bufferHorasTrabajadas,bufferSueldo);

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

    if( !employee_setNombre(this,nombre)&&
        !employee_setHorasTrabajadas(this,horasTrabajadas)&&
        !employee_setSueldo(this,sueldo) &&
       !employee_setId(this,id))
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

        printf("\nID -- %d",auxId);
        printf(" / Nombre -- %s",auxNombre);
        printf(" / Sueldo -- $%.2f",auxSueldo);
        printf(" / Horas trabajadas -- %dhs",auxHorasTrabajadas);
        retorno = 0;
    }
    return retorno;
}


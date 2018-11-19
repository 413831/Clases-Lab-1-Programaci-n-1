
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Empleado.h"
#include "utn.h"


#define BUFFER 4000

/////////////////////////////////////////////////STATIC/////////////////////////////////////////////////////////////////////

/**
*\brief Valida un nombre del elemento
*\param name Es el string a validar
*\return Retorna 1 si es correcto sino retorna 0
*/
static int isValidName(char* name)
{
    int retorno = 0;

    if(name != NULL && validacion_Letras(name,strlen(name)))
    {
        retorno = 1;
    }
    return retorno;
}

/**
*\brief Valida horas trabajadas del elemento
*\param horas Es el string a validar
*\return Retorna 1 si es correcto sino retorna 0
*/
static int isValidHoras(char* horas)
{
    int retorno = 0;
    int digitosIngresados = strlen(horas);

    if(horas != NULL && validacion_Int(horas,digitosIngresados) && atoi(horas) > 0)
    {
        retorno = 1;
    }
    return retorno;
}

/**
*\brief Valida sueldo del elemento
*\param sueldo Es el string a validar
*\return Retorna 1 si es correcto sino retorna 0
*/
static int isValidSueldo(char* sueldo)
{
    int retorno = 0;
    int digitosIngresados = strlen(sueldo);

    if(sueldo != NULL && validacion_Int(sueldo,digitosIngresados) && atoi(sueldo) > 0)
    {
        retorno = 1;
    }
    return retorno;
}


/**
*\brief Valida ID del elemento
*\param id Es el string a validar
*\return Retorna 1 si es correcto sino retorna 0
*/
static int isValidId(char* id)
{
    int retorno = 0;
    int digitosIngresados = strlen(id);

    if(id != NULL && validacion_Int(id,digitosIngresados))
    {
        retorno = 1;
    }
    return retorno;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////
int employee_calcularSueldo(void* pEmpleado)
{
    int retorno = -1;
    int cantidadHoras;
    float auxSueldo;
    char sueldo[BUFFER];

    if(pEmpleado != NULL)
    {
        employee_getHorasTrabajadas(pEmpleado,&cantidadHoras);

        if(cantidadHoras < 120)
        {
            auxSueldo = cantidadHoras * 180;
            sprintf(sueldo,"%.2f",auxSueldo);
            employee_setSueldo(pEmpleado,sueldo);
        }
        else if(cantidadHoras > 120 && cantidadHoras < 160)
        {
            auxSueldo = cantidadHoras * 240;
            sprintf(sueldo,"%.2f",auxSueldo);
            employee_setSueldo(pEmpleado,sueldo);
        }
        else if(cantidadHoras > 160 && cantidadHoras < 240)
        {
            auxSueldo = cantidadHoras * 350;
            sprintf(sueldo,"%.2f",auxSueldo);
            employee_setSueldo(pEmpleado,sueldo);
        }
        retorno = 0;
    }

    return retorno;
}



/**
*\brief Reserva espacio en memoria para un elemento
*\param void
*\return Retorna el elemento si reserva memoria sino NULL
*/
Empleado* employee_new()
{
    Empleado* this;
    this=malloc(sizeof(Empleado));
    if(this != NULL)
    {
      return this;
    }
    else
    {
        return NULL;
    }
}

/**
*\brief Es el constructor del elemento donde se reserva memoria y se setean los campos
*\param id Es el dato id para setear en el campo del elemento
*\param nombre Es el dato nombre para setear en el campo del elemento
*\param horasTrabajadas Es el dato horasTrabajadas para setear en el campo del elemento
*\param sueldo Es el dato sueldo para setear en el campo del elemento
*\return Retorna 0 si logra agregar elemento sino retorna -1
*/
Empleado* employee_newConParametros(char* id,char* nombre,char* horasTrabajadas,char* sueldo)
{
    Empleado* this;
    this=employee_new();

    if(isValidId(id) &&
       isValidName(nombre) &&
       isValidHoras(horasTrabajadas) &&
       isValidSueldo(sueldo) &&
       !employee_setAll(this,id,nombre,horasTrabajadas,sueldo))
    {
        return this;
    }
    else
    {
        employee_delete(this);
        return NULL;
    }
}


/**
*\brief Libera espacio en memoria ocupado por un elemento
*\param this Es el elemento
*\return Retorna 0 si logra liberar sino retorna -1
*/
int employee_delete(Empleado* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

/**
*\brief Se muestran los datos de todos los campos del elemento
*\param this Es el puntero al elemento
*\return Retorna 0 si el elemento es diferente a NULL sino retorna -1
*/
int employee_show(void* this)
{
    int retorno = -1;
    int auxId;
    char auxNombre[128];
    int auxHorasTrabajadas;
    float auxSueldo;

    if(this != NULL)
    {
        employee_getId(this,&auxId);
        if(auxId != -1)
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
    }
    return retorno;
}

/////////////////////////////////////////////SETTERS & GETTERS///////////////////////////////////////////////////////////
/**
*\brief Se setea el ID del elemento
*\param this Es el elemento
*\param id Es el ID para setear
*\return Retorna 0 si setea sino -1
*/
int employee_setId(Empleado* this,char* id)
{
    int retorno=-1;
    static int proximoId=0;
    int auxId = atoi(id);

    if(this!=NULL && auxId==0)//Se carga primer ID y en el ALTA
    {
        proximoId++;
        this->id=proximoId;
        retorno=0;
    }
    else if(this!=NULL && auxId>proximoId)//Se comparan los ID al cargar del archivo
    {
        proximoId=auxId;
        this->id=proximoId;
        retorno=0;
    }
    return retorno;
}

/**
*\brief Se obtiene el ID del elemento
*\param this Es el elemento
*\param id Es el ID que se obtiene
*\return Retorna 0 si obtiene sino retorna -1
*/
int employee_getId(Empleado* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

/**
*\brief Se setea el nombre del elemento
*\param this Es el elemento
*\param nombre Es el nombre para setear
*\return Retorna 0 si setea elemento sino retorna -1
*/
int employee_setNombre(Empleado* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL && isValidName(nombre))
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

/**
*\brief Se obtiene el nombre del elemento
*\param this Es el elemento
*\param nombre Es el nombre que se obtiene
*\return Retorna 0 si obtiene elemento sino retorna -1
*/
int employee_getNombre(Empleado* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

/**
*\brief Se setea las horas trabajadas del elemento
*\param this Es el elemento
*\param horasTrabajadas Es la cantidad de horas para setear
*\return Retorna 0 si setea elemento sino retorna -1
*/
int employee_setHorasTrabajadas(Empleado* this,char* horasTrabajadas)
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

/**
*\brief Se obtienen las horas trabajadas del elemento
*\param this Es el elemento
*\param horasTrabajadas Es la cantidad de horas que se obtiene
*\return Retorna 0 si setea elemento sino retorna -1
*/
int employee_getHorasTrabajadas(Empleado* this,int* horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

/**
*\brief Se setea el sueldo del elemento
*\param this Es el elemento
*\param sueldo Es el sueldo para setear
*\return Retorna 0 si setea elemento sino retorna -1
*/
int employee_setSueldo(Empleado* this,char* sueldo)
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

/**
*\brief Se obtiene el sueldo del elemento
*\param this Es el elemento
*\param sueldo Es el sueldo que se obtiene
*\return Retorna 0 si setea elemento sino retorna -1
*/
int employee_getSueldo(Empleado* this,float* sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *sueldo=this->sueldo;
        retorno=0;
    }
    return retorno;
}

/**
*\brief Setea todos los campos del elemento
*\param this Es el elemento
*\param name Es el dato para setear el campo nombre
*\param hours Es el dato para setear el campo horas trabajadas
*\param salary Es el dato para setear el campo salario
*\return Retorna 0 si existe el elemento sino retorna -1
*/
int employee_setAll(Empleado* this,char* id,char* name,char* hours,char* salary)
{
    int retorno = -1;

    if(this != NULL)
    {
        if( !employee_setId(this,id) &&
            !employee_setNombre(this,name) &&
            !employee_setHorasTrabajadas(this,hours) &&
            !employee_setSueldo(this,salary))
        {
            retorno = 0;
        }
    }
    return retorno;
}

/**
*\brief Obtiene todos los campos del elemento
*\param this Es el elemento
*\param name Es el dato para obtener el campo nombre
*\param hours Es el dato para obtener el campo horas trabajadas
*\param salary Es el dato para obtener el campo salario
*\return Retorna 0 si existe el elemento sino retorna -1
*/
int employee_getAll(Empleado* this,char* name,int* hours,float* salary,int* id)
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

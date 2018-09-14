#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

#define CANTIDAD_EMPLEADOS 3

/*
struct sEmpleado
{
    char nombre[50];
    char apellido[50];
    float salario;

};

typedef struct sEmpleado Empleado;
*/

typedef struct sEmpleado
{
    char nombre[CANTIDAD_EMPLEADOS][50];
    char apellido[CANTIDAD_EMPLEADOS][50];
    float salario;

}Empleado;




int sortEmpleadosNombre(Empleado* pEmpleado,int limite)
{
    int swap = 0;
    int i;

    Empleado bufferEmpleado;
    do
    {
        for(i=0;i<limite;i++)
        {
            if(strcmp(pEmpleado[i].nombre,pEmpleado[i+1].nombre) > 0)
            {
                swap = 1;
                bufferEmpleado = pEmpleado[i];
                pEmpleado[i] = pEmpleado[i+1];
                pEmpleado[i] = bufferEmpleado;
            }
        }

    }while(swap);
    return swap;
}

int main()
{
    char nombre[CANTIDAD_EMPLEADOS][50] = {"AAA","BBB","FFF","DDD",};
    char apellido[CANTIDAD_EMPLEADOS][50]  = {"AAA","BBB","FFF","DDD",};
    float salario;

    Empleado arrayEmpleados[CANTIDAD_EMPLEADOS];//Valor tipo Empleado
    Empleado* pEmpleado;//Puntero de tipo Empleado
    pEmpleado = arrayEmpleados;

    strcpy(arrayEmpleados[1].apellido,"LOPEZ");//Si no es puntero se accede con el PUNTO
    strcpy((pEmpleados+1).>apellido,"LOPEZ");//Si es puntero es FLECHA


    return 0;
}

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "/home/alexei/Documents/Workspace/Bibliotecas/utn.h"

#define QTY_EMPLEADOS 5
#define QTY_NAME 30
#define QTY_AGE 3
#define QTY_DNI 15
#define LIMITE_TEL 30


typedef struct  sEmpleado
{
    char nombre[QTY_NAME];
    char edad[QTY_AGE];
    char dni[QTY_DNI];
    char sueldo[10];
    char legajo[10];

}Empleado;


void sort_Nombre(Empleado* pArray,int size);


int main()
{
    //struct sEmpleado arrayEmpleado[5];
    char telefono[30];

  /*  for(i=0;i<5;i++)
    {
    string_getStringLetras("\nIngrese su nombre: ","Error.Reingrese su nombre", QTY_NAME,arrayEmpleado[i].nombre);
    string_getStringNumeros("\nIngrese su legajo: ","Error.Legajo incorrecto",QTY_EMPLEADOS,arrayEmpleado[i].legajo,0,5);
    string_getStringNumeros("\nIngrese su edad: ","Error.Edad incorrecta",QTY_AGE,arrayEmpleado[i].edad,0,100);
    string_getStringFloat("\nIngrese su sueldo: ","Error.Dato incorrecto",8,arrayEmpleado[i].sueldo,0,60000);
    }
*/ //CARGAR ARRAY DE ESTRUCTURAS


 /*   for(i=0;i<5;i++)
    {
       printf("\nEl nombre es %s",arrayEmpleado[i].nombre);
       printf("\nEl legajo es %s",arrayEmpleado[i].legajo);
       printf("\nLa edad es %s",arrayEmpleado[i].edad);
       printf("\nEl sueldo es %s\n",arrayEmpleado[i].sueldo);
    }
*/

    printf("\nIngrese tu numero de telefono ");
    string_getString(telefono,LIMITE_TEL);
    printf("\nEl telefono ingresado es %s",telefono);

    if(validacion_Telefono(telefono,LIMITE_TEL))
    {
        printf("\nEl telefono ingresado es %s",telefono);
    }
    else
    {
        printf("\nERROR");
    }


    return 0;
}


void sort_Nombre(Empleado* pArray,int size)
{
    int i;
    int j;
    Empleado aux;

    for(i=0;i<size;i++)//Ordenamiento por metodo burbuja
    {
        j=i + 1;
        if(strcmp(pArray[i].nombre,pArray[j].nombre) > 0)
            {
                aux = pArray[i];
                pArray[i] = pArray[j];
                pArray[j] = aux;
            }

    }
}

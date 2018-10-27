#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
    int option;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do
    {
        option = 1; //BORRAR
        switch(option)
        {
            case 1:
                printf("\nSize Linked List %d",ll_len(listaEmpleados));
                controller_loadFromText("data.csv",listaEmpleados);
                printf("\nSize Linked List %d",ll_len(listaEmpleados));
            case 2:
                printf("\nSize Linked List %d",ll_len(listaEmpleados));
                controller_loadFromBinary("data.csv",listaEmpleados);
                printf("\nSize Linked List %d",ll_len(listaEmpleados));
            case 3:
                controller_addEmployee(listaEmpleados);
                controller_ListEmployee(listaEmpleados);
                printf("\nSize Linked List %d",ll_len(listaEmpleados));
                option = 10; //BORRAR
                break;

        }
    }while(option != 10);
    return 0;
}

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "elemento.h"


int elemento_menu(Employee array[],int size)
{
    int retorno = -1;
    int i;
    int opcion;
    int contador = 0;//CAMBIAR PARA HARDCODE
    int idIngresado;
    Elemento* elementoSeleccionado;

    elemento_init(array,size,1);

   do
   {
       limpiarPantalla();
       printf("\n<<<MENU>>>\n\n1) ALTA\n2) MODIFICAR\n3) BAJA\n4) INFORMES\n5) SALIR\n");
       input_ScanInt("\nIngrese opcion: ",&opcion);

       switch(opcion)
       {
            case 1 :
                printf("\n--ALTA--\n");
                if(elemento_buscarIndiceLibre(array,size) >= 0)
                {
                    elemento_alta(array,size);
                    contador++;
                }
                else
                {
                    printf("\nNo hay espacios libres.");
                    printf("\nIngrese cualquier tecla para continuar...");
                    limpiarMemoria();
                    getchar();
                }
            break;

            case 2 :
                if(contador > 0)
                {
                    printf("\n--MODIFICAR--\n");
                    elementos_listar(array,size);
                    input_ScanInt("\nIngrese ID: ",&idIngresado);
                    elementoSeleccionado = elemento_getByID(array,size,idIngresado);
                    elemento_modificar(elementoSeleccionado);
                }
                else
                {
                    printf("\nNo hay datos cargados.");
                    printf("\nIngrese cualquier tecla para continuar...");
                    limpiarMemoria();
                    getchar();
                }

            break;

            case 3 :
                if(contador > 0)
                {
                    printf("\n--BAJA--\n");
                    elementos_listar(array,size);
                    input_ScanInt("\nIngrese ID: ",&idIngresado);
                    elementoSeleccionado = employee_getByID(array,size,idIngresado);
                    elemento_eliminar(elementoSeleccionado);
                    contador--;
                }
                else
                {
                    printf("\nNo hay datos cargados.");
                    printf("\nIngrese cualquier tecla para continuar...");
                    limpiarMemoria();
                    getchar();
                }

            break;

            case 4 :
                 if(contador > 0)
                {
                    printf("\n--INFORMES--\n");
                   
                }
                else
                {
                    printf("\nNo hay datos cargados.");
                    printf("\nIngrese cualquier tecla para continuar...");
                    limpiarMemoria();
                    getchar();
                }
            case 5 :
                {
                    printf("\nVuelvas prontos...:)");
                    limpiarMemoria();
                    getchar();
                }
                break;

            default :
                printf("\nOpcion invalida.:P");
                printf("\nIngrese cualquier tecla para continuar...");
                limpiarMemoria();
                getchar();


        }
        retorno = 0;
   }while(opcion != 5);

        return retorno;

}

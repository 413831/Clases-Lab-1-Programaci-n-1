#include <stdio_ext.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "pantalla.h"
#include "utn.h"
#include "Contratacion.h"
#include "informar.h"

#define QTY 10
#define LEN_CONT    1000
#define CUIT 5

/*

A. Realizar un solo listado de las pantallas ordenadas por los siguientes criterios:
   o Precio (descendentemente)
   o Nombre (ascendentemente)

B.  Todas las pantallas que su valor es menor o igual a 10.

C.  Todas las pantallas que su valor es mayor a 10.

D.  Todas las pantallas que superan el promedio de los precios.

E.  Todas las pantallas que no superan el promedio de los precios.

F.  Todas las contrataciones cuya cantidad de dias es menor o igual a 10,
    indicando nombre de la pantalla contratada, precio unitario, dias y precio total de la contratacion

G.  Listado de clientes en el cual se indique la cantidad de contrataciones que ha realizado
    y por que importe. Ordenado por los siguientes criterios:
        o Importe (descendentemente)
        o Cuit (ascendentemente)

H. La o las pantallas con mas contrataciones.
8ik
I. La o las pantallas con mas clientes.

J. La o las pantallas que mas ha facturado.

K. La o las pantallas que han facturado mas que el promedio.

*/



int main()
{
    Pantalla pantallas[QTY];
    Contratacion contrataciones[LEN_CONT];
    int menu;
    int i;
    int auxiliarId;
    int contadorPantallas = 1;//CAMBIAR
    int contadorContrataciones = 0;
    float totalPrecios;
    float promedioPrecio;
    float precioContratacion;
    char listadoCuit[CUIT];
    Pantalla* pantSeleccionada;
    Pantalla pantallaMayorCont;
    Pantalla pantallaMayorClientes;
    Pantalla pantallaMayorFact;
    Pantalla pantallaMayorFactPromedio;


    pantalla_init(pantallas,QTY,1);
    cont_init(contrataciones,LEN_CONT,1);

    pantalla_ingresoForzado(pantallas,QTY,"Grundig","Las Flores 50",50,0);
    pantalla_ingresoForzado(pantallas,QTY,"Philips","Belgrano 250",5000,0);
    pantalla_ingresoForzado(pantallas,QTY,"Samsung","Cerrito 300",3000,0);
    pantalla_ingresoForzado(pantallas,QTY,"LG","Lavalle 450",5000,1);
    pantalla_ingresoForzado(pantallas,QTY,"Sony","Mitre 150",5000,1);

    cont_altaForzada(contrataciones,LEN_CONT,"20911911915",1,5,"video.avi");
    cont_altaForzada(contrataciones,LEN_CONT,"20911911915",1,4,"video1.avi");
    cont_altaForzada(contrataciones,LEN_CONT,"30911911915",1,300,"video2.avi");
    cont_altaForzada(contrataciones,LEN_CONT,"30911911915",2,7,"video3.avi");
    cont_altaForzada(contrataciones,LEN_CONT,"40911911915",2,8,"video4.avi");
    cont_altaForzada(contrataciones,LEN_CONT,"40911911915",2,600,"video5.avi");

  /*  informar_ConsultaFacturacion(contrataciones,LEN_CONT,pantallas,QTY,"20911911915");
    informar_ListarContrataciones(contrataciones,LEN_CONT,pantallas,QTY);
    informar_ListarCantidadContratacionesImporte(contrataciones,LEN_CONT,pantallas,QTY);

*/
    do
    {
       // input_getNumeros(&menu,1,"\n\n1.Alta\n2.Baja\n3.Modificar\n4.Mostrar\n5.Ordenar\n6.Mostrar Debug\n7.Contratar\n8.Informes\n9.Salir\n","\nNo valida\n",1,9,2);
        input_ScanInt("\nIngrese opcion\n\n1.Alta\n2.Baja\n3.Modificar\n4.Listar\n5.Ordenar\n6.Mostrar Debug\n7.Contratar\n8.Informes\n9.Salir\n",&menu);

        switch(menu)
        {
            case 1 :
            if(pantalla_buscarIndiceLibre(pantallas,QTY) >= 0)
            {
                printf("\n--ALTA--");
                pantalla_alta(pantallas,QTY);
                contadorPantallas++;
            }
            else
            {
                printf("\nNo hay lugares libres");
                printf("\nIngrese una tecla para continuar...");
                limpiarMemoria();
                getchar();
            }

            break;
            case 2 :
            if(contadorPantallas > 0)
            {
                printf("\n--BAJA PANTALLA--");
                input_ScanInt("\nIngrese ID: ",&auxiliarId);
                pantSeleccionada = pantalla_getByID(pantallas,QTY,auxiliarId);
                pantalla_eliminar(pantSeleccionada,QTY);
                contadorPantallas--;
            }
            else
            {
                printf("\nNo hay datos cargados");
                printf("\nIngrese una tecla para continuar...");
                limpiarMemoria();
                getchar();
            }

            break;
            case 3 :
            if(contadorPantallas > 0)
            {
                printf("\n--MODIFICAR PANTALLA--");
                input_ScanInt("\nIngrese ID: ",&auxiliarId);
                pantSeleccionada = pantalla_getByID(pantallas,QTY,auxiliarId);
                pantalla_modificar(pantSeleccionada,QTY);
            }
            else
            {
                printf("\nNo hay datos cargados");
                printf("\nIngrese una tecla para continuar...");
                limpiarMemoria();
                getchar();
            }


            break;
            case 4 :
            if(contadorPantallas > 0)
            {
                printf("\n--LISTAR PANTALLAS--");
                pantalla_listar(pantallas,QTY);
                informar_listadoCuit(contrataciones,LEN_CONT,14,listadoCuit);
                    for(i=0;i<CUIT;i++)
                    {
                        printf("\nCUIT -- %s",listadoCuit[i]);

                    }
            }
            else
            {
                printf("\nNo hay datos cargados");
                printf("\nIngrese una tecla para continuar...");
                limpiarMemoria();
                getchar();
            }


            break;
            case 5 :
            if(contadorPantallas > 0)
            {
                printf("\n--ORDENAR PANTALLAS--");
                pantalla_sortName(pantallas,QTY);
            }
            else
            {
                printf("\nNo hay datos cargados");
                printf("\nIngrese una tecla para continuar...");
                limpiarMemoria();
                getchar();
            }


            break;
            case 6 :
            if(contadorPantallas > 0)
            {
                printf("\n--BUSCAR PANTALLA--");
                input_ScanInt("\nIngrese ID: ",&auxiliarId);
                pantSeleccionada = pantalla_getByID(pantallas,QTY,auxiliarId);
                pantalla_mostrar(pantSeleccionada,QTY);
            }
            else
            {
                printf("\nNo se encontró pantalla");
                printf("\nIngrese una tecla para continuar...");
                limpiarMemoria();
                getchar();
            }



            break;
            case 7 :
            if(contadorPantallas > 0)
            {
                printf("\n--ALTA CONTRATACION--");
                pantalla_listar(pantallas,QTY);
                input_ScanInt("\nIngrese ID de Pantalla: ",&auxiliarId);
                cont_alta(contrataciones,LEN_CONT,auxiliarId);
                contadorContrataciones++;
            }
            else
            {
                printf("\nNo hay pantallas cargadas");
                printf("\nIngrese una tecla para continuar...");
                limpiarMemoria();
                getchar();
            }

            break;
            case 8 :
                printf("\n--INFORMES--\n");
                printf("\n--Listar--");
                pantalla_sortName(pantallas,QTY);
                pantalla_listar(pantallas,QTY);
                printf("\nIngrese una tecla para continuar...");
                limpiarMemoria();
                getchar();

                printf("\n--Valor de pantallas menores o igual a 10--");
                informar_valorPantallas(pantallas,QTY,1);
                printf("\nIngrese una tecla para continuar...");
                limpiarMemoria();
                getchar();
                printf("\n--Valor de pantallas mayores a 10--");
                informar_valorPantallas(pantallas,QTY,0);
                printf("\nIngrese una tecla para continuar...");
                limpiarMemoria();
                getchar();

                printf("\n--Pantallas que superan promedio--");
                informar_promedioPantallas(pantallas,QTY,1);
                printf("\nIngrese una tecla para continuar...");
                limpiarMemoria();
                getchar();
                printf("\n--Pantallas que no superan promedio--");
                informar_promedioPantallas(pantallas,QTY,0);

                printf("\n--Contrataciones con menos de 10 dias--");
                informar_diasContratacion(contrataciones,pantallas,LEN_CONT,QTY);
                printf("\nIngrese una tecla para continuar...");
                limpiarMemoria();
                getchar();



                informar_listadoCuit(contrataciones,LEN_CONT,CUIT,listadoCuit);
                printf("\nIngrese una tecla para continuar...");
                limpiarMemoria();
                getchar();
         //       informar_importePorCuit(pantallas,QTY,contrataciones,LEN_CONT,"30911911915");




        //    informar_mostrarPantallas(pantallas,QTY,1);
         //   informar_mostrarPantallas(pantallas,QTY,0);
         //   informar_calculosContratacion(pantallas,contrataciones,QTY,LEN_CONT);



            break;



        }

    }while(menu != 9);

    return 0;
}

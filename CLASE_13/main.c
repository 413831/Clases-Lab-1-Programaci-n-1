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

I. La o las pantallas con mas clientes.

J. La o las pantallas que mas ha facturado.

K. La o las pantallas que han facturado mas que el promedio.

*/



int main()
{
    Pantalla array[QTY];
    Contratacion contrataciones[LEN_CONT];
    int menu;
    int auxiliarId;
    int contadorPantallas = 0;
    int contadorContrataciones = 0;
    float totalPrecios;
    float promedioPrecio;
    float precioContratacion;
    Pantalla* pantSeleccionada;
    Pantalla pantallaMayorCont;
    Pantalla pantallaMayorClientes;
    Pantalla pantallaMayorFact;
    Pantalla pantallaMayorFactPromedio;


    pantalla_init(array,QTY,1);
    cont_init(contrataciones,LEN_CONT,1);

    pantalla_ingresoForzado(array,QTY,"Grundig","Las Flores 50",50,0);
    pantalla_ingresoForzado(array,QTY,"Philips","Belgrano 250",5000,0);
    pantalla_ingresoForzado(array,QTY,"Samsung","Cerrito 300",3000,0);
    pantalla_ingresoForzado(array,QTY,"LG","Lavalle 450",5000,1);
    pantalla_ingresoForzado(array,QTY,"Sony","Mitre 150",5000,1);

    cont_altaForzada(contrataciones,LEN_CONT,"20911911915",0,100,"video.avi");
    cont_altaForzada(contrataciones,LEN_CONT,"20911911915",0,400,"video1.avi");
    cont_altaForzada(contrataciones,LEN_CONT,"30911911915",0,300,"video2.avi");
    cont_altaForzada(contrataciones,LEN_CONT,"30911911915",2,400,"video3.avi");
    cont_altaForzada(contrataciones,LEN_CONT,"40911911915",2,500,"video4.avi");
    cont_altaForzada(contrataciones,LEN_CONT,"40911911915",2,600,"video5.avi");

    informar_ConsultaFacturacion(contrataciones,LEN_CONT,array,QTY,"20911911915");
    informar_ListarContrataciones(contrataciones,LEN_CONT,array,QTY);
    informar_ListarCantidadContratacionesImporte(contrataciones,LEN_CONT,array,QTY);


    do
    {
       // input_getNumeros(&menu,1,"\n\n1.Alta\n2.Baja\n3.Modificar\n4.Mostrar\n5.Ordenar\n6.Mostrar Debug\n7.Contratar\n8.Informes\n9.Salir\n","\nNo valida\n",1,9,2);
        input_ScanInt("\nIngrese opcion\n\n1.Alta\n2.Baja\n3.Modificar\n4.Mostrar\n5.Ordenar\n6.Mostrar Debug\n7.Contratar\n8.Informes\n9.Salir\n",&menu);

        switch(menu)
        {
            case 1 :

            pantalla_alta(array,QTY);
            contadorPantallas++;



            break;
            case 2 :
            input_ScanInt("\nIngrese ID: ",&auxiliarId);
            pantSeleccionada = pantalla_getByID(array,QTY,auxiliarId);
            pantalla_eliminar(pantSeleccionada,QTY);
            contadorPantallas--;

            break;
            case 3 :
            input_ScanInt("\nIngrese ID: ",&auxiliarId);
            pantSeleccionada = pantalla_getByID(array,QTY,auxiliarId);
            pantalla_modificar(pantSeleccionada,QTY);


            break;
            case 4 :
            pantalla_listar(array,QTY);


            break;
            case 5 :
            pantalla_ordenar(array,QTY,1);


            break;
            case 6 :
            input_ScanInt("\nIngrese ID: ",&auxiliarId);
            pantSeleccionada = pantalla_getByID(array,QTY,auxiliarId);
            pantalla_mostrar(pantSeleccionada,QTY);



            break;
            case 7 :
            pantalla_listar(array,QTY);
            input_ScanInt("\nIngrese ID: ",&auxiliarId);
            cont_alta(contrataciones,LEN_CONT,auxiliarId);
            contadorContrataciones++;

            break;
            case 8 :

            pantalla_sortName(array,QTY);
            pantalla_listar(array,QTY);



            break;



        }

    }while(menu != 9);

    return 0;
}

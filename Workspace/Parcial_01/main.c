#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "pantalla.h"
#include "contrataciones.h"

#define QTY_PANTALLA 3
#define QTY_CLIENTES 3


/*
Se debe desarrollar un sistema (en ANSI C) el cual permita comercializar espacios
publicitarios,​ ​ los​ ​ cuales​ ​ estarán​ ​ integrados​ ​ por​ ​ dos​ ​ tipos​ ​ de​ ​ dispositivos:
1. Pantallas​ ​ LCD​ ​ - ​ ​ Ubicados​ ​ en​ ​ paseos​ ​ comerciales
2. Pantallas​ Gigantes​ ​ Led​ ​ - ​ ​ Ubicadas​ ​ en​ ​ la​ ​ vía​ ​ pública
En el sistema existirán pantallas del tipo Led o LCD , las cuales se registrarán mediante
nombre,​ ​ dirección​ ​ y ​ ​ precio​ ​ de​ ​ la​ ​ publicidad​ ​ en​ ​ dicha​ ​ pantalla​ ​ por​ ​ cada​ ​ día​ ​ de​ ​ publicación.
La plataforma permitirá vender a un cliente la publicación de un video publicitario en una
pantalla​ ​ determinada.
La porción del sistema que deberá realizarse se centrará en la venta de publicidad y consta de
un​ ​ menú​ ​ con​ ​ las​ ​ siguientes​ ​ opciones:
*/

int main()
{
    Pantalla arrayPantallas[QTY_PANTALLA];
    Contratacion arrayContrataciones[QTY_CLIENTES];
    Pantalla* pantallaSeleccionada;
    Contratacion* contratacionSeleccionada;
    int opcion = 1;
    int idIngresado;

    pantalla_init(arrayPantallas,QTY_PANTALLA,1);
    contratacion_init(arrayContrataciones,QTY_CLIENTES,1);

    do
    {
        opcion = input_ScanInt("\n>>MENU<<\n\n1) ALTA DE PANTALLA \n2) MODIFICAR DATOS DE PANTALLA \n3) BAJA DE PANTALLA\n4) LISTAR PANTALLAS\n5) SALIR\n");

        switch(opcion)
        {
                case 1 :
                    printf("\n- ALTA DE PANTALLA -");
                    pantalla_alta(arrayPantallas,QTY_PANTALLA);
                    break;
                case 2 :
                    printf("\n- MODIFICAR DATOS DE PANTALLA -");
                    __fpurge(stdin);
                    idIngresado = input_ScanInt("\nIngrese ID: ");
                    pantallaSeleccionada = pantalla_getById(arrayPantallas,QTY_PANTALLA,idIngresado);
                    pantalla_modificar(pantallaSeleccionada,QTY_PANTALLA);
                    break;
                case 3 :
                    printf("\n- BAJA DE PANTALLA -");
                    __fpurge(stdin);
                    idIngresado = input_ScanInt("\nIngrese ID");
                    pantallaSeleccionada = pantalla_getById(arrayPantallas,QTY_PANTALLA,idIngresado);
                    pantalla_baja(pantallaSeleccionada,QTY_PANTALLA);
                        for(i=0;i<QTY_CLIENTES;i++)
                        {
                            if(arrayContrataciones[i].idContratacion == idIngresado);
                            {
                                contratacionSeleccionada = contratacion_getById(arrayContrataciones,QTY_CLIENTES,idIngresado);
                                contratacion_baja(contratacionSeleccionada,QTY_CLIENTES);
                            }

                        }
                    break;
                case 4 :
                    printf("\nLISTAR PANTALLAS");
                    pantalla_listar(arrayPantallas,QTY_PANTALLA);
                    __fpurge(stdin);
                    getc(stdin);
                    contratacion_alta(arrayContrataciones,QTY_CLIENTES)


                    break;
                case 5 :
                    printf("\nBUSCAR PANTALLA POR ID");
                    idIngresado = input_ScanInt("\nIngrese ID");
                    pantallaSeleccionada = pantalla_getById(arrayPantallas,QTY_PANTALLA,idIngresado);
                    pantalla_mostrar(pantallaSeleccionada,QTY_PANTALLA);

        }


    }while(opcion != 6);


    return 0;
}

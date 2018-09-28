#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"
#include "pantalla.h"
#include "contrataciones.h"

#define QTY_PANTALLAS 5
#define QTY_CONTRATACIONES 5

#define NUMERO 100
#define FLOTANTE 100

    /**1) Alta de pantalla: Se solicitan al usuario los datos de la pantalla, para que el sistema
    pueda​ ​ funcionar​ ​ se​ ​ deberá​ ​ generar​ ​ un​ ​ ID​ ​ único​ ​ para​ ​ cada​ ​ pantalla.

    2) Modificar datos de pantalla: Se ingresa el ID de la pantalla, permitiendo modificar sus
    datos.

    3) Baja de pantalla: Se ingresa el ID de la pantalla, se eliminará la pantalla junto con todas
    las​ ​ contrataciones​ ​ de​ ​ publicidad​ ​ para​ ​ esta​ ​ pantalla.

    4) Contratar una publicidad: ​ Se listaran todas las pantallas y se le pedirá al usuario que
    elija la pantalla donde se quiere publicar, ingresando su ID. Luego se pedirán los datos
    asociados a la publicidad: cuit del cliente, cantidad de días que dura la publicación y
    nombre​ ​ del​ ​ archivo​ ​ de​ ​ video​ ​ (p.ej.​ ​ Video1.avi).

    5) Modificar condiciones de publicación: ​ Se pedirá que se ingrese el cuit del cliente y se
    listaran todas las pantallas de video que el cliente tiene contratadas mostrando todos sus
    campos. Luego de ingresar el ID de la pantalla, se permitirá modificar la cantidad de días
    contratados​ ​ para​ ​ la​ ​ misma.

    6) Cancelar contratación: ​ Se pedirá que se ingrese el cuit del cliente y se listaran todas las
    pantallas de video que el cliente tiene contratadas mostrando todos sus campos. Luego
    ingresar​ ​ el​ ​ ID​ ​ de​ ​ la​ ​ pantalla​ ​ de​ ​ la​ ​ cual​ ​ se​ ​ quiere​ ​ cancelar​ ​ la​ ​ contratación.

    7) Consulta facturación: Se deberá ingresar el cuit del cliente y se deberá listar el importe
    a​ ​ pagar​ ​ por​ ​ cada​ ​ contratación.

    8) Listar contrataciones: ​ Se deberán listar las contrataciones indicando nombre de la
    pantalla,​ ​ nombre​ ​ de​ ​ video,​ ​ cantidad​ ​ de​ ​ días​ ​ y ​ ​ cuit​ ​ de​ ​ cliente.

    9) Listar​ ​ pantallas:​ ​ Se​ ​ deberán​ ​ listar​ ​ las​ ​ pantallas​ ​ existentes​ ​ indicando​ ​ todos​ ​ sus​ ​ campos.
*/

int main()
{
    Pantalla arrayPantallas[QTY_PANTALLAS];
    Contratacion arrayContratacion[QTY_CONTRATACIONES];
    int opcion;
    int i;
    int idIngresado;
    char cuitIngresado[100];
    Pantalla* pantallaBuscada;
    Contratacion* contratacionBuscada;
    float importeTotal;
    float importePantalla;
    int diasContratados;
    float precioPantalla;

do
{
    opcion = 0;

    switch(opcion)
    {
        case 1 :
        pantalla_alta(arrayPantallas,QTY_PANTALLAS);
        break;
        case 2 :
        idIngresado = input_ScanInt("\nIngresar ID a modificar");
        pantallaBuscada = pantalla_getByID(arrayPantallas,QTY_PANTALLAS,idIngresado);
        pantalla_modificar(pantallaBuscada,QTY_PANTALLAS);
        break;
        case 3 :
        idIngresado = input_ScanInt("\nIngresar ID a modificar");
        pantallaBuscada = pantalla_getByID(arrayPantallas,QTY_PANTALLAS,idIngresado);
        pantalla_modificar(pantallaBuscada,QTY_PANTALLAS);
        break;
        case 4 :
        pantalla_ordenar(arrayPantallas,QTY_PANTALLAS);
        contratacion_alta(arrayContratacion,QTY_CONTRATACIONES);
        break;
        case 5 :
        idIngresado = input_ScanInt("\nIngresar ID a modificar");
        contratacionBuscada = contratacion_getByID(arrayContratacion,QTY_CONTRATACIONES,idIngresado);
        contratacion_modificar(contratacionBuscada,QTY_CONTRATACIONES);
        break;
        case 6 :
        cuitIngresado = input_getCuit(cuitIngresado,100,"\nIngrese CUIT","\nError");

            for(i=0;i<QTY_CONTRATACIONES;i++)
            {
                if(arrayContratacion[i].cuit == cuitIngresado)
                {
                idIngresado = arrayContratacion[i].idPantalla;
                pantallaBuscada = pantalla_getByID(arrayPantallas,QTY_PANTALLAS,idIngresado);
                pantalla_mostrar(pantallaBuscada,QTY_PANTALLAS);
                }
            }
        break;
        case 7 :
        cuitIngresado = input_getCuit(cuitIngresado,100,"\nIngrese CUIT","\nError");

            for(i=0;i<QTY_CONTRATACIONES;i++)
            {
                if(arrayContratacion[i].cuit == cuitIngresado)
                {
                idIngresado = arrayContratacion[i].idPantalla;
                diasContratados = arrayContratacion[i].dias;

                pantallaBuscada = pantalla_getByID(arrayPantallas,QTY_PANTALLAS,idIngresado);
                precioPantalla = pantallaBuscada->precio;

                importeTotal = diasContratados + precioPantalla;

                printf("\nCUIT -- %s\nIMPORTE -- %f",arrayContratacion[i].cuit,importeTotal);
                }
            }
        break;

        break;



    }



}while(opcion != 8);



    return 0;
}

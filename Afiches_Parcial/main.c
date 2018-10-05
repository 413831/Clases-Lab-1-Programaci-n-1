#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "ventas.h"
#include "utn.h"

#define QTY_CLIENTES 10
#define QTY_VENTAS 10


int main()
{
    Cliente arrayClientes[QTY_CLIENTES];
    Venta arrayVentas[QTY_VENTAS];
    int i;
    int opcion;
    int contadorClientes = 5;//CAMBIAR PARA HARDCODE
    int contadorVentas = 5;//CAMBIAR PARA HARDCODE
    char respuesta[5];
    int idIngresado;
    Cliente* clienteSeleccionado;
    Venta* ventaSeleccionada;

    cliente_init(arrayClientes,QTY_CLIENTES,1);
    venta_init(arrayVentas,QTY_VENTAS,"Disponible");


    cliente_ingresoForzado(arrayClientes,QTY_CLIENTES,"Pepito","Gomez","23-33444555-1");
    cliente_ingresoForzado(arrayClientes,QTY_CLIENTES,"Huguito","Perez","23-11444555-3");
    cliente_ingresoForzado(arrayClientes,QTY_CLIENTES,"Laurita","Moreira","25-66777888-9");
    cliente_ingresoForzado(arrayClientes,QTY_CLIENTES,"Pedrito","Gomez","22-11111111-2");
    cliente_ingresoForzado(arrayClientes,QTY_CLIENTES,"Lupita","Gurruchaga","27-22123123-3");


    venta_ingresoForzado(arrayVentas,QTY_VENTAS,"archivo1.mpg","CABA",5,1);
    venta_ingresoForzado(arrayVentas,QTY_VENTAS,"archivo2.mpg","GBA NORTE",10,1);
    venta_ingresoForzado(arrayVentas,QTY_VENTAS,"archivo3.mpg","GBA SUR",15,1);
    venta_ingresoForzado(arrayVentas,QTY_VENTAS,"archivo4.mpg","GBA OESTE",20,2);
    venta_ingresoForzado(arrayVentas,QTY_VENTAS,"archivo5.mpg","CABA",25,2);



   do
   {
      // limpiarPantalla();
       printf("\n<<<MENU>>>\n\n1) ALTA CLIENTE\n2) MODIFICAR DATOS CLIENTES\n3) BAJA CLIENTE");
       printf("\n4) VENTA AFICHE\n5) EDITAR AFICHE\n6) COBRAR VENTA\n7) IMPRIMIR LISTA DE CLIENTES\n8) SALIR\n");
       input_ScanInt("\nIngrese opcion: ",&opcion);

       switch(opcion)
       {
            case 1 :
                printf("\n--ALTA CLIENTE--\n");
                if(cliente_buscarIndiceLibre(arrayClientes,QTY_CLIENTES) >= 0)
                {
                    if(!cliente_alta(arrayClientes,QTY_CLIENTES,clienteSeleccionado))
                    {
                        printf("\nID CLIENTE %d",clienteSeleccionado->id);
                        contadorClientes++;
                    }

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
                if(contadorClientes > 0)
                {
                    printf("\n--MODIFICAR DATOS CLIENTE--\n");
                    cliente_listar(arrayClientes,QTY_CLIENTES);
                    input_ScanInt("\nIngrese ID: ",&idIngresado);
                    clienteSeleccionado = cliente_getByID(arrayClientes,QTY_CLIENTES,idIngresado);
                    cliente_modificar(clienteSeleccionado);
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
                if(contadorClientes > 0)
                {
                    cliente_listar(arrayClientes,QTY_CLIENTES);
                    input_ScanInt("\nIngrese ID: ",&idIngresado);
                    input_getLetras(respuesta,3,"\nEsta seguro de realizar la baja?","Error.Dato invalido",2);

                    if(!strcmp(respuesta,"si"))
                    {
                        printf("\n--BAJA DE CLIENTE--\n");


                        clienteSeleccionado = cliente_getByID(arrayClientes,QTY_CLIENTES,idIngresado);
                        cliente_eliminar(clienteSeleccionado);

                            do
                            {
                                ventaSeleccionada = venta_getByID(arrayVentas,QTY_VENTAS,idIngresado);

                               if(ventaSeleccionada != NULL)
                               {
                                    venta_eliminar(ventaSeleccionada);
                               }

                            } while(ventaSeleccionada != NULL);

                        contadorClientes--;
                        }
                    else if(!strcmp(respuesta,"no"))
                    {
                        break;
                    }
                    else
                    {
                        printf("Error.Opcion incorrecta");
                    }

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
                 printf("\n--ALTA VENTA--\n");
                if(venta_buscarIndiceLibre(arrayVentas,QTY_VENTAS) >= 0)
                {
                    input_ScanInt("\nIngrese ID: ",&idIngresado);
                    if(venta_buscarIndiceLibre(arrayVentas,QTY_CLIENTES) >= 0)
                    {
                        venta_alta(arrayVentas,QTY_VENTAS,idIngresado);

                    }
                        contadorVentas++;
                }
                else
                {
                    printf("\nNo hay espacios libres.");
                    printf("\nIngrese cualquier tecla para continuar...");
                    limpiarMemoria();
                    getchar();
                }
                break;
            case 5 :
                  if(contadorVentas > 0)
                {
                    printf("\n--EDITAR VENTA--\n");
                    venta_listar(arrayVentas,QTY_VENTAS);
                    input_ScanInt("\nIngrese ID: ",&idIngresado);
                    ventaSeleccionada = venta_getByID(arrayVentas,QTY_CLIENTES,idIngresado);
                    venta_modificar(ventaSeleccionada);
                }
                else
                {
                    printf("\nNo hay datos cargados.");
                    printf("\nIngrese cualquier tecla para continuar...");
                    limpiarMemoria();
                    getchar();
                }
                break;
            case 6 :
                if(contadorVentas > 0)
                {
                    printf("\n--COBRAR VENTA--\n");

                    venta_listar(arrayVentas,QTY_VENTAS);
                    input_ScanInt("\nIngrese ID: ",&idIngresado);
                    ventaSeleccionada = venta_getByID(arrayVentas,QTY_VENTAS,idIngresado);
                    venta_eliminar(ventaSeleccionada);
                    contadorVentas--;
                }
                else
                {
                    printf("\nNo hay datos cargados.");
                    printf("\nIngrese cualquier tecla para continuar...");
                    limpiarMemoria();
                    getchar();
                }
                 break;
            case 7 :
                if(contadorClientes > 0 && contadorVentas > 0)
                {
                    printf("\n--IMPRIMIR CLIENTES--\n");

                    for(i=0;i<QTY_CLIENTES;i++)
                    {
                        clienteSeleccionado = cliente_getByID(arrayClientes,QTY_CLIENTES,arrayClientes[i].id);

                        if(venta_getByID(arrayVentas,QTY_VENTAS,arrayClientes[i].id) != NULL)
                        {
                            cliente_mostrar(clienteSeleccionado,&idIngresado);
                            printf("\n\n>>VENTAS A COBRAR<<\nID CLIENTE: %d",idIngresado);
                            venta_mostrar(arrayVentas,QTY_VENTAS,idIngresado);
                        }

                    }
                    printf("\nIngrese cualquier tecla para continuar...");
                    limpiarMemoria();
                    getchar();

                }
                else
                {
                    printf("\nNo hay datos cargados.");
                    printf("\nIngrese cualquier tecla para continuar...");
                    limpiarMemoria();
                    getchar();
                }

                  break;
            case 8 :

                break;
            default :
                printf("\nOpcion invalida.:P");
                printf("\nIngrese cualquier tecla para continuar...");
                limpiarMemoria();
                getchar();


        }

   }while(opcion != 8);

        return 0;

}

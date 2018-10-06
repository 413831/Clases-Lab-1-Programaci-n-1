#include <stdio_ext.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utn.h"
#include "clientes.h"
#include "ventas.h"
#include "informar.h"


static void swapVentas(Venta* valorA,Venta* valorB)
{
    Venta auxiliar;//TIPO pantalla
    auxiliar = *valorA;
    *valorA = *valorB;
    *valorB = auxiliar;
}

static void swapClientes(Venta* valorA,Venta* valorB)
{
    Venta auxiliar;//TIPO pantalla
    auxiliar = *valorA;
    *valorA = *valorB;
    *valorB = auxiliar;
}


int informar_ConsultaFacturacion(Venta* arrayC,int limite,
              Cliente* clientes, int lenClientes, char* cuit)
{
    int retorno = -1;

    return retorno;
}

/*
int informar_ListarVentas(Cliente clientes[],int sizeUno,
              Venta ventas[], int sizeDos,int lenght)
{
    int retorno = -1;
    int i;
    char listadoCuit[lenght];



    if(clientes != NULL &&
       ventas != NULL &&
       sizeUno > 0 &&
       sizeDos > 0)
    {
        for(i=0;i<sizeDos;i++)
        {
            printf("\nCLIENTE %s",listadoCuit+i);
            informar_importePorCuit(clientes,sizeUno,ventas,sizeDos,listadoCuit+i);
        }
        retorno = 0;
    }

    return retorno;
}
*/
///Listar todas las ventas segun STATUS


int informar_statusVentas(Venta array[],
                                int size,
                                int status)
{
    int retorno = -1;
    int i;

    if(array != NULL && size > 0)
    {

        switch(status)
        {
            case 1 :
             for(i=0;i<size;i++)
            {
                if(!strcmp(array[i].status,STATUS_1))
                {
                    printf("\nID CLIENTE -- %d",array[i].idCliente);
                    printf("\nID NOMBRE DE ARCHIVO-- %s",array[i].nombreAfiche);
                    printf("\nID CANTIDAD DE AFICHES-- %d",array[i].cantidad);
                    printf("\nID ZONA-- %s",array[i].zona);
                    printf("\nID STATUS-- %s",array[i].status);
                }
            }


            break;

            case 0 :
            for(i=0;i<size;i++)
            {

                if(!strcmp(array[i].status,STATUS_1))
                {
                    printf("\nID CLIENTE -- %d",array[i].idCliente);
                    printf("\nID NOMBRE DE ARCHIVO-- %s",array[i].nombreAfiche);
                    printf("\nID CANTIDAD DE AFICHES-- %d",array[i].cantidad);
                    printf("\nID ZONA-- %s",array[i].zona);
                    printf("\nID STATUS-- %s",array[i].status);

                }
            }

            break;

        }
        retorno = 0;
    }


    return retorno;
}


///Listar todas las ventas que superan o no el promedio de cantidad de afiches

int informar_promedioCantidad(Venta array[],
                                int size,
                                int calculo)//OK
{
    int retorno = -1;
    int i;
    float promedio;

    informar_calculoPromedioCantidad(array,size,&promedio);

    if(array != NULL && size > 0)
    {

        switch(calculo)
        {
            case 1 :
             for(i=0;i<size-1;i++)
            {
                if(!strcmp(array[i].status,STATUS_1) && array[i].cantidad > promedio)
                {

                     printf("\n%s",array[i].nombreAfiche);
                     printf("\n%s",array[i].zona);
                     printf("\n%d",array[i].cantidad);
                     printf("\n%d",array[i].idCliente);
                }
            }
            break;

            case 0 :
            for(i=0;i<size-1;i++)
            {

                if(!strcmp(array[i].status,STATUS_1) && array[i].cantidad < promedio)
                {
                     printf("\n%s",array[i].nombreAfiche);
                     printf("\n%s",array[i].zona);
                     printf("\n%d",array[i].cantidad);
                     printf("\n%d",array[i].idCliente);

                }
            }

            break;

        }
        retorno = 0;
    }
    return retorno;
}


///Calculo del promedio de cantidad de afiches

int informar_calculoPromedioCantidad(Venta array[],
                                int size,
                                float* promedio)//OK
{
    int retorno = -1;
    float cantidadTotal = 0;
    int contador = 0;
    int i;

    if(array != NULL && size > 0)
    {
        for(i=0;i<size;i++)
        {
            if(!strcmp(array[i].status,STATUS_1))//CON STATUS "A COBRAR"
            {
                cantidadTotal = cantidadTotal + array[i].cantidad;
                contador++;
            }
        }

        *promedio = cantidadTotal / contador;
        retorno = 0;
    }

    return retorno;
}

///Listar todas las ventas cobradas por zona

int informar_calculoVentasZona(Venta array[],
                                int size,
                                int opcion)//OK
{
    int retorno = -1;
    int contadorVentas = 0;
    int i;

    if(array != NULL && size > 0)
    {
        switch(opcion)
        {
            case 1 :

                contadorVentas = 0;

                for(i=0;i<size;i++)
                {
                    if(!strcmp(array[i].status,STATUS_2) && !strcmp(array[i].zona,"CABA"))//CON STATUS "COBRADA"
                    {
                        printf("\nID CLIENTE -- %d",array[i].idCliente);
                        printf("\nID NOMBRE DE ARCHIVO-- %s",array[i].nombreAfiche);
                        printf("\nID CANTIDAD DE AFICHES-- %d",array[i].cantidad);
                        printf("\nID ZONA-- %s",array[i].zona);
                        printf("\nID STATUS-- %s",array[i].status);
                        contadorVentas++;
                    }
                }

                printf("\nTotal de ventas realizadas en CABA: %d",contadorVentas);
                retorno = 0;
                break;
            case 2 :

                contadorVentas = 0;

                for(i=0;i<size;i++)
                {
                    if(!strcmp(array[i].status,STATUS_2) && !strcmp(array[i].zona,"GBA SUR"))//CON STATUS "COBRADA"
                    {
                        printf("\nID CLIENTE -- %d",array[i].idCliente);
                        printf("\nID NOMBRE DE ARCHIVO-- %s",array[i].nombreAfiche);
                        printf("\nID CANTIDAD DE AFICHES-- %d",array[i].cantidad);
                        printf("\nID ZONA-- %s",array[i].zona);
                        printf("\nID STATUS-- %s",array[i].status);
                        contadorVentas++;

                    }

                }

                printf("\nTotal de ventas realizadas en CABA: %d",contadorVentas);
                retorno = 0;
                break;
            case 3 :

                contadorVentas = 0;

                for(i=0;i<size;i++)
                {
                    if(!strcmp(array[i].status,STATUS_2) && !strcmp(array[i].zona,"GBA OESTE"))//CON STATUS "COBRADA"
                    {
                        printf("\nID CLIENTE -- %d",array[i].idCliente);
                        printf("\nID NOMBRE DE ARCHIVO-- %s",array[i].nombreAfiche);
                        printf("\nID CANTIDAD DE AFICHES-- %d",array[i].cantidad);
                        printf("\nID ZONA-- %s",array[i].zona);
                        printf("\nID STATUS-- %s",array[i].status);
                        contadorVentas++;
                    }
                }

                printf("\nTotal de ventas realizadas en CABA: %d",contadorVentas);
                retorno = 0;
                break;
            default :
                {
                    printf("\nZona invalida");
                }

        }


    }

    return retorno;
}


int informar_calculoClientesZona(Cliente arrayUno[],
                                 Venta arrayDos[],
                                int sizeUno,
                                int sizeDos,
                                int opcion)//OK
{
    int retorno = -1;
    int idCliente;
    int contadorClientes = 0;
    int i;
    int j;

    if(arrayUno != NULL &&
       arrayDos != NULL &&
       sizeUno > 0 &&
       sizeDos > 0)
    {
        switch(opcion)
        {
            case 1 :
                contadorClientes = 0;

                for(i=0;i<sizeUno;i++)//Recorro array clientes
                {
                    if(!arrayUno[i].isEmpty)
                    {
                        for(j=0;j<sizeDos;j++)//Recorro array ventas
                        {
                            if(arrayDos[j].idCliente == arrayUno[i].id &&
                               !strcasecmp(arrayDos[j].zona,"CABA"))//Si encuentra ventas del cliente a cobrar o cobradas entra
                            {
                                cliente_mostrar(arrayUno+i,&idCliente);
                                contadorClientes++;
                            }

                        }
                        printf("\nTotal de clientes de CABA: %d",contadorClientes);

                    }

                }

                printf("\nTotal de ventas realizadas en CABA: %d",contadorClientes);
                retorno = 0;
                break;
            case 2 :

                contadorClientes = 0;

                for(i=0;i<sizeUno;i++)//Recorro array clientes
                {
                    if(!arrayUno[i].isEmpty)
                    {
                        for(j=0;j<sizeDos;j++)//Recorro array ventas
                        {
                            if(arrayDos[j].idCliente == arrayUno[i].id &&
                               !strcasecmp(arrayDos[j].zona,"GBA SUR"))//Si encuentra ventas del cliente a cobrar o cobradas entra
                            {
                                cliente_mostrar(arrayUno+i,&idCliente);
                                contadorClientes++;
                            }

                        }
                        printf("\nTotal de clientes de GBA SUR: %d",contadorClientes);

                    }

                }
                break;
            case 3 :

                contadorClientes = 0;

                for(i=0;i<sizeUno;i++)//Recorro array clientes
                {
                    if(!arrayUno[i].isEmpty)
                    {
                        for(j=0;j<sizeDos;j++)//Recorro array ventas
                        {
                            if(arrayDos[j].idCliente == arrayUno[i].id &&
                               !strcasecmp(arrayDos[j].zona,"GBA OESTE"))//Si encuentra ventas del cliente a cobrar o cobradas entra
                            {
                                cliente_mostrar(arrayUno+i,&idCliente);
                                contadorClientes++;
                            }

                        }
                        printf("\nTotal de clientes de GBA OESTE: %d",contadorClientes);

                    }

                }
                break;
            default :
                {
                    printf("\nZona invalida");
                }

        }


    }

    return retorno;
}




int informar_clienteMasVentasPendientes(Cliente arrayUno[],Venta arrayDos[],
                                int sizeUno,int sizeDos)//OK
{
    int retorno = -1;
    int i;
    int j;
    int idCliente;
    int flag = 1;
    int contadorVentas;
    int mayorCantidad;
    int arrayVentas[sizeUno];
    Venta* ventaSeleccionada;

    if(arrayUno != NULL && arrayDos != NULL && sizeUno > 0 && sizeDos > 0)//menor a 10
    {

        for(i=0;i<sizeUno;i++)//Recorro array clientes
        {
            contadorVentas = 0;

            if(!arrayUno[i].isEmpty)
            {
                for(j=0;j<sizeDos;j++)//Recorro array ventas
                {
                    if(arrayUno[i].id == arrayDos[j].idCliente)//Busca las ventas relacionadas al cliente
                    {
                        ventaSeleccionada = venta_getByID(arrayDos,sizeDos,arrayDos[j].id);

                        if(ventaSeleccionada != NULL && !strcmp(ventaSeleccionada->status,STATUS_1))
                        {
                            contadorVentas++;//Sumo la venta a cobrar
                        }

                    }

                }

                arrayVentas[i] = contadorVentas;
            }
        }


            retorno = 0;
    }

    return retorno;
}


int informar_clienteMasVentasCobradas(Cliente arrayUno[],Venta arrayDos[],
                                int sizeUno,int sizeDos)//OK
{
    int retorno = -1;
    int i;
    int j;
    int idCliente;
    int flag = 1;
    int contadorVentas;
    int totalVentas;
    Cliente* clienteMasVentas;
    Venta* ventaSeleccionada;

    if(arrayUno != NULL && arrayDos != NULL && sizeUno > 0 && sizeDos > 0)//menor a 10
    {

        for(i=0;i<sizeUno;i++)//Recorro array clientes
        {
            contadorVentas = 0;

            if(!arrayUno[i].isEmpty)
            {
                for(j=0;j<sizeDos;j++)//Recorro array ventas
                {
                    if(!strcmp(arrayUno[i].id,arrayDos[j].idCliente))//Busca las ventas relacionadas al cliente
                    {
                        ventaSeleccionada = venta_getByID(arrayDos,sizeDos,arrayDos[j].id);

                        if(ventaSeleccionada != NULL && !strcmp(ventaSeleccionada->status,STATUS_2))
                        {
                            contadorVentas++;//Sumo la venta a cobradas
                        }

                    }

                }


                if(flag == 1 || contadorVentas > totalVentas)//Determino el cliente con mas ventas
                {
                    totalVentas = contadorVentas;
                    clienteMasVentas = arrayUno+1;
                    flag = 0;
                }

            }
        }

            retorno = 0;
    }

    return retorno;
}


int informar_clienteMenosVentasPendientes(Cliente arrayUno[],Venta arrayDos[],
                                int sizeUno,int sizeDos)//OK
{
    int retorno = -1;
    int i;
    int j;
    int idCliente;
    int flag = 1;
    int contadorVentas;
    int totalVentas;
    Cliente* clienteMenosVentas;
    Venta* ventaSeleccionada;

    if(arrayUno != NULL && arrayDos != NULL && sizeUno > 0 && sizeDos > 0)//menor a 10
    {

        for(i=0;i<sizeUno;i++)//Recorro array clientes
        {
            contadorVentas = 0;

            if(!arrayUno[i].isEmpty)
            {
                for(j=0;j<sizeDos;j++)//Recorro array ventas
                {
                    if(!strcmp(arrayUno[i].id,arrayDos[j].idCliente))//Busca las ventas relacionadas al cliente
                    {
                        ventaSeleccionada = venta_getByID(arrayDos,sizeDos,arrayDos[j].id);

                        if(ventaSeleccionada != NULL && !strcmp(ventaSeleccionada->status,STATUS_1))
                        {
                            contadorVentas++;//Sumo la venta a cobrar
                        }

                    }

                }


                if(flag == 1 || contadorVentas < totalVentas)//Determino el cliente con mas ventas
                {
                    totalVentas = contadorVentas;
                    clienteMenosVentas = arrayUno+1;
                    flag = 0;
                }

            }
        }

            retorno = 0;
    }

    return retorno;
}


int informar_clienteMenosVentasCobradas(Cliente arrayUno[],Venta arrayDos[],
                                int sizeUno,int sizeDos)//OK
{
    int retorno = -1;
    int i;
    int j;
    int idCliente;
    int flag = 1;
    int contadorVentas;
    int totalVentas;
    Cliente* clienteMenosVentas;
    Venta* ventaSeleccionada;

    if(arrayUno != NULL && arrayDos != NULL && sizeUno > 0 && sizeDos > 0)//menor a 10
    {

        for(i=0;i<sizeUno;i++)//Recorro array clientes
        {
            contadorVentas = 0;

            if(!arrayUno[i].isEmpty)
            {
                for(j=0;j<sizeDos;j++)//Recorro array ventas
                {
                    if(!strcmp(arrayUno[i].id,arrayDos[j].idCliente))//Busca las ventas relacionadas al cliente
                    {
                        ventaSeleccionada = venta_getByID(arrayDos,sizeDos,arrayDos[j].id);

                        if(ventaSeleccionada != NULL && !strcmp(ventaSeleccionada->status,STATUS_2))
                        {
                            contadorVentas++;//Sumo la venta a cobrar
                        }

                    }

                }


                if(flag == 1 || contadorVentas < totalVentas)//Determino el cliente con mas ventas
                {
                    totalVentas = contadorVentas;
                    clienteMenosVentas = arrayUno+1;
                    flag = 0;
                }

            }
        }

            retorno = 0;
    }

    return retorno;
}



int informar_validarCuit(char auxCuit[],Cliente array[],int size,int length)
{
    int retorno = -1;
    int j;

    for(j=0;j<size;j++)
    {

        if(!strcmp(array[j].cuit,auxCuit))
        {
            strncpy(auxCuit,array[j].cuit,14);
        }

        retorno = 0;
    }



    return retorno;
}


int informar_initListadoCuit(Cliente array[],char listadoCuit[],int qty_clientes)
{
    int i;
    int retorno = -1;

    for(i=0;i<qty_clientes;i++)
    {

        strncpy(listadoCuit[i],"0",13);
        retorno = 0;
    }



    return retorno;
}



int informar_listadoCuit(Cliente array[],int size,int length,char listadoCuit[])
{
    int retorno = -1;
    int i;
    int j;
    int flag=1;
    char auxCuit[length];

    //informar_initListadoCuit(listadoCuit,size);

   // while(flag == 1)

            printf("\nENTRO WHILE");
        for(i=0;i<size;j++)
        {
            strncpy(auxCuit,array[i].cuit,length);
            if(!informar_validarCuit(auxCuit,array, size, length))
            {
                strncpy(listadoCuit[i],auxCuit,length);
            }

        }

        for(i=0;i<size;j++)
        {
            printf("\nCLIENTE CUIT Nº -- %s",listadoCuit[i]);
        }

    retorno = 0;

    return retorno;
}

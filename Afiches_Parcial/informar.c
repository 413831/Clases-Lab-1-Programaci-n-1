#include <stdio_ext.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utn.h"
#include "clientes.h"
#include "ventas.h"
#include "informar.h"

#define QTY_CLIENTES 10

/*
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
*/


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

/**
*\brief Lista todas las ventas segun CUIT
*\param arrayUno Es el array de cliente que recibe
*\param arrayDos Es el array de ventas que recibe
*\param sizeUno Es el tamaño del array uno
*\param sizeDos Es el tamaño del array dos
*\return Retorna 0 si se encuentran los clientes sino retorna -1
*/

int informar_ventasPorCuit(Cliente arrayUno[],
                                 Venta arrayDos[],
                                int sizeUno,
                                int sizeDos)
{
    int retorno = -1;
    char cuitIngresado[13];
    Cliente* clienteSeleccionado;

    if(arrayUno != NULL && arrayDos != NULL && sizeUno > 0 && sizeDos > 0)
    {
        if(!input_getCuit(cuitIngresado,13,"\nIngrese numero de CUIT: ","Error.Numero invalido",2))//Se ingresa CUIT
        {
            clienteSeleccionado = informar_buscarClienteCuit(arrayUno,sizeUno,cuitIngresado);
            if( clienteSeleccionado != NULL)//Se busca ID cliente
            {
                cliente_mostrar(clienteSeleccionado);//Se muestran datos del cliente
                venta_mostrar(arrayDos,sizeDos,clienteSeleccionado->id);//Ventas a cobrar
                venta_cobradas(arrayDos,sizeDos,clienteSeleccionado->id);//Ventas cobradas
                retorno = 0;
            }
        }
    }

    return retorno;
}


/**
*\brief Lista todas las ventas segun CUIT y Zona
*\param arrayUno Es el array de cliente que recibe
*\param arrayDos Es el array de ventas que recibe
*\param sizeUno Es el tamaño del array uno
*\param sizeDos Es el tamaño del array dos
*\param opcion Es la opcion de zona a listar
*\return Retorna 0 si se encuentran los clientes sino retorna -1
*/

int informar_ventasPorCuitZona(Cliente arrayUno[],
                                 Venta arrayDos[],
                                int sizeUno,
                                int sizeDos,
                                int opcion)
{
    int retorno = -1;
    int i;
    char cuitIngresado[13];
    int idCliente;
    Cliente* clienteSeleccionado;


    if(arrayUno != NULL && arrayDos != NULL && sizeUno > 0 && sizeDos > 0)
    {
        if(!input_getCuit(cuitIngresado,13,"\nIngrese numero de CUIT: ","Error.Numero invalido",2))//Se ingresa CUIT
        {
            clienteSeleccionado = informar_buscarClienteCuit(arrayUno,sizeUno,cuitIngresado);//Se busca cliente

            if(clienteSeleccionado != NULL)
            {
                idCliente = clienteSeleccionado->id;

                switch(opcion)
                {
                    case 1 :
                        for(i=0;i<sizeDos;i++)
                        {
                            if(arrayDos[i].idCliente == idCliente &&
                               !strcmp(arrayDos[i].zona,"CABA"))//Se buscan ventas del cliente en zona CABA
                            {
                                cliente_mostrar(clienteSeleccionado);
                                venta_mostrar(arrayDos,sizeDos,idCliente);
                                venta_cobradas(arrayDos,sizeDos,idCliente);
                            }
                        }
                    break;
                    case 2 :
                        for(i=0;i<sizeDos;i++)
                        {
                            if(arrayDos[i].idCliente == idCliente &&
                               !strcmp(arrayDos[i].zona,"GBA OESTE"))//Se buscan ventas del cliente en zona GBA OESTE
                            {
                                cliente_mostrar(clienteSeleccionado);
                                venta_mostrar(arrayDos,sizeDos,idCliente);
                                venta_cobradas(arrayDos,sizeDos,idCliente);
                            }
                        }
                    break;
                    case 3 :
                        for(i=0;i<sizeDos;i++)
                        {
                            if(arrayDos[i].idCliente == idCliente &&
                               !strcmp(arrayDos[i].zona,"GBA SUR"))//Se buscan ventas del cliente en zona GBA SUR
                            {
                                cliente_mostrar(clienteSeleccionado);
                                venta_mostrar(arrayDos,sizeDos,idCliente);
                                venta_cobradas(arrayDos,sizeDos,idCliente);
                            }
                        }
                    break;
                    default :
                        printf("\nOpcion invalida");
                }

                retorno = 0;
            }

        }

    }


    return retorno;
}




/**
*\brief Lista todas las ventas según status
*\param array Es el array de ventas que recibe
*\param size Es el tamaño del array
*\return Retorna 0 si el array es valido sino retorna -1
*/

int informar_statusVentas(Venta array[],
                                int size)
{
    int retorno = -1;
    int i;
    int opcion;

    if(array != NULL && size > 0)
    {
        input_getNumeros(&opcion,3,"\n1) PENDIENTE\n2) COBRADA\n","Opcion invalida",1,2,2);

        switch(opcion)
        {
            case 1 :
                 for(i=0;i<size;i++)
                {
                    if(!strcmp(array[i].status,STATUS_1))//Se buscan ventas A COBRAR
                    {
                        printf("\n\nID CLIENTE -- %d\n",array[i].idCliente);
                        printf("\nNOMBRE DE ARCHIVO-- %s",array[i].nombreAfiche);
                        printf("\nCANTIDAD DE AFICHES-- %d",array[i].cantidad);
                        printf("\nZONA-- %s",array[i].zona);
                        printf("\nSTATUS-- %s",array[i].status);
                    }
                }


            break;

            case 2 :

                for(i=0;i<size;i++)
                {

                    if(!strcmp(array[i].status,STATUS_2))//Se buscan ventas COBRADAS
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


/**
*\brief Lista todas las ventas segun CUIT y Zona
*\param array Es el array de ventas que recibe
*\param size Es el tamaño del array
*\param calculo Es la opcion de calculo segun el case
*\return Retorna 0 si el array existe sino retorna -1
*/

int informar_ventasPromedioAfiches(Venta array[],
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
            case 1 : //Se buscan ventas A COBRAR que superen el PROMEDIO de cantidad de afiches
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

            case 2 : //Se buscan ventas A COBRAR que NO superen el PROMEDIO de cantidad de afiches
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


/**
*\brief Calcula la cantidad promedio de afiches de ventas a cobrar
*\param array Es el array de ventas que recibe
*\param size Es el tamaño del array
*\param promedio Es el puntero de la variable promedio para guardar el dato
*\return Retorna 0 si existe el array sino retorna -1
*/

int informar_calculoPromedioCantidad(Venta array[],
                                int size,
                                float* promedio)
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
                cantidadTotal = cantidadTotal + array[i].cantidad;//Se suma la cantidad de afiches
                contador++;
            }
        }

        *promedio = cantidadTotal / contador;//Se calcula el promedio
        retorno = 0;
    }

    return retorno;
}

/**
*\brief Lista todas las ventas cobradas por zona
*\param array Es el array de ventas que recibe
*\param size Es el tamaño del array uno
*\param opcion Es la opcion de zona a listar
*\return Retorna 0 se muestra una de las listas sino retorna -1
*/

int informar_calculoVentasZona(Venta array[],
                                int size,
                                int opcion)
{
    int retorno = -1;
    int contadorVentas = 0;
    int i;

    if(array != NULL && size > 0)
    {
        switch(opcion)
        {
            case 1 ://Se muestran listan ventas COBRADAS en CABA

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
            case 2 ://Se muestran listan ventas COBRADAS en GBA SUR

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

                printf("\nTotal de ventas realizadas en GBA SUR: %d",contadorVentas);
                retorno = 0;
                break;
            case 3 ://Se muestran listan ventas COBRADAS en GBA OESTE

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

                printf("\nTotal de ventas realizadas en GBA OESTE: %d",contadorVentas);
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


/**
*\brief Lista todos los clientes por zona y total de ventas por zona
*\param arrayUno Es el array de cliente que recibe
*\param arrayDos Es el array de ventas que recibe
*\param sizeUno Es el tamaño del array uno
*\param sizeDos Es el tamaño del array dos
*\param opcion Es la opcion de zona a listar
*\return Retorna 0 si se encuentran los clientes sino retorna -1
*/

int informar_calculoClientesZona(Cliente arrayUno[],
                                 Venta arrayDos[],
                                int sizeUno,
                                int sizeDos,
                                int opcion)
{
    int retorno = -1;
    int contadorClientes = 0;
    int contadorVentas = 0;
    int totalVentas = 0;
    int flag = 0;
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
                        contadorVentas = 0;

                        for(j=0;j<sizeDos;j++)//Recorro array ventas
                        {
                            if(arrayDos[j].idCliente == arrayUno[i].id &&
                               !strcasecmp(arrayDos[j].zona,"CABA"))//Si encuentra ventas del cliente a cobrar o cobradas entra
                            {
                                contadorVentas++;
                                totalVentas+=contadorVentas;
                                flag = 1;
                            }

                        }

                        if(flag == 1)
                        {
                            cliente_mostrar(arrayUno+i);//Se muestra cliente de CABA
                            contadorClientes++;
                        }


                        printf("\nCLIENTE-> %s -- ZONA-> CABA -- VENTAS-> %d",arrayUno[i].cuit,contadorVentas);

                    }

                }
                printf("\n\nTotal de clientes de CABA: %d",contadorClientes);//Total de clientes en CABA
                printf("\nTotal de ventas realizadas en CABA: %d",totalVentas);
                retorno = 0;
                break;
            case 2 :
                contadorClientes = 0;

                for(i=0;i<sizeUno;i++)//Recorro array clientes
                {
                    if(!arrayUno[i].isEmpty)
                    {
                        contadorVentas = 0;

                        for(j=0;j<sizeDos;j++)//Recorro array ventas
                        {
                            if(arrayDos[j].idCliente == arrayUno[i].id &&
                               !strcasecmp(arrayDos[j].zona,"GBA SUR"))//Si encuentra ventas del cliente a cobrar o cobradas entra
                            {
                                contadorVentas++;
                                totalVentas+=contadorVentas;
                                flag = 1;
                            }

                        }

                        if(flag == 1)
                        {
                            cliente_mostrar(arrayUno+i);//Se muestra cliente de GBA SUR
                            contadorClientes++;
                        }


                        printf("\nCLIENTE-> %s -- ZONA-> GBA SUR -- VENTAS-> %d",arrayUno[i].cuit,contadorVentas);

                    }

                }
                printf("\n\nTotal de clientes de GBA SUR: %d",contadorClientes);//Total de clientes en GBA SUR
                printf("\nTotal de ventas realizadas en GBA SUR: %d",totalVentas);
                retorno = 0;
                break;
            case 3 :
                contadorClientes = 0;

                for(i=0;i<sizeUno;i++)//Recorro array clientes
                {
                    if(!arrayUno[i].isEmpty)
                    {
                        contadorVentas = 0;

                        for(j=0;j<sizeDos;j++)//Recorro array ventas
                        {
                            if(arrayDos[j].idCliente == arrayUno[i].id &&
                               !strcasecmp(arrayDos[j].zona,"GBA OESTE"))//Si encuentra ventas del cliente a cobrar o cobradas entra
                            {
                                contadorVentas++;
                                totalVentas+=contadorVentas;
                                flag = 1;
                            }

                        }

                        if(flag == 1)
                        {
                            cliente_mostrar(arrayUno+i);//Se muestra cliente de GBA OESTE
                            contadorClientes++;
                        }


                        printf("\nCLIENTE-> %s -- ZONA-> GBA OESTE -- VENTAS-> %d",arrayUno[i].cuit,contadorVentas);

                    }

                }
                printf("\n\nTotal de clientes de GBA OESTE: %d",contadorClientes);//Total de clientes en GBA OESTE
                printf("\nTotal de ventas realizadas en GBA OESTE: %d",totalVentas);
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



/**
*\brief Lista los clientes con mas ventas pendientes
*\param arrayUno Es el array de cliente que recibe
*\param arrayDos Es el array de ventas que recibe
*\param sizeUno Es el tamaño del array uno
*\param sizeDos Es el tamaño del array dos
*\return Retorna 0 si existen los arrays y son validos los limites sino retorna -1
*/

int informar_clienteMasVentasPendientes(Cliente arrayUno[],Venta arrayDos[],
                                int sizeUno,int sizeDos)
{
    int retorno = -1;
    int i;
    int j;
    int flag = 1;
    int contadorVentas = 0;
    int contadorClientes = 0;
    int mayorCantidad;
    Cliente arrayClientesVenta[sizeUno];
    Venta* ventaSeleccionada;

    if(arrayUno != NULL && arrayDos != NULL && sizeUno > 0 && sizeDos > 0)
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
                            contadorVentas++;//Sumo la venta a cobrar del cliente
                        }
                    }
                }
            }

            if(flag == 1 ||
               contadorVentas > mayorCantidad ||
               contadorVentas == mayorCantidad)//Guardo el dato de mayor cantidad de ventas
            {
                mayorCantidad = contadorVentas;
                arrayClientesVenta[i] = arrayUno[i];
                contadorClientes++;
                flag = 0;
            }
        }

        printf("\nCLIENTES CON MAYOR VENTA %d",contadorClientes);
        printf("\nMAYOR CANTIDAD DE VENTAS %d",mayorCantidad);

        for(i=0;i<contadorClientes;i++)//Muestro los datos de los clientes con mayor cantidad de ventas
        {
            if(arrayClientesVenta != NULL)
            {
                cliente_mostrar(arrayClientesVenta+i);
            }
        }
            retorno = 0;
    }

    return retorno;
}


/**
*\brief Lista los clientes con mas ventas cobradas
*\param arrayUno Es el array de cliente que recibe
*\param arrayDos Es el array de ventas que recibe
*\param sizeUno Es el tamaño del array uno
*\param sizeDos Es el tamaño del array dos
*\return Retorna 0 si existen los arrays y son validos los limites sino retorna -1
*/

int informar_clienteMasVentasCobradas(Cliente arrayUno[],Venta arrayDos[],
                                int sizeUno,int sizeDos)//OK
{
    int retorno = -1;
    int i;
    int j;
    int flag = 1;
    int contadorVentas = 0;
    int contadorClientes = 0;
    int mayorCantidad;
    Cliente arrayClientesVenta[sizeUno];
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

                        if(ventaSeleccionada != NULL && !strcmp(ventaSeleccionada->status,STATUS_2))
                        {
                            contadorVentas++;//Sumo la venta cobrada del cliente
                        }
                    }
                }
            }

            if(flag == 1 ||
               contadorVentas > mayorCantidad ||
               contadorVentas == mayorCantidad)//Guardo el dato de mayor cantidad de ventas
            {
                mayorCantidad = contadorVentas;
                arrayClientesVenta[i] = arrayUno[i];
                contadorClientes++;
                flag = 0;
            }
        }

        printf("\nCLIENTES CON MAYOR VENTA %d",contadorClientes);
        printf("\nMAYOR CANTIDAD DE VENTAS %d",mayorCantidad);
        for(i=0;i<contadorClientes;i++)//Muestro los datos de los clientes con mayor cantidad de ventas
        {
            if(arrayClientesVenta != NULL)
            {
                cliente_mostrar(arrayClientesVenta+i);
            }
        }

            retorno = 0;
    }
    return retorno;
}


/**
*\brief Lista los clientes con menos ventas pendientes
*\param arrayUno Es el array de cliente que recibe
*\param arrayDos Es el array de ventas que recibe
*\param sizeUno Es el tamaño del array uno
*\param sizeDos Es el tamaño del array dos
*\return Retorna 0 si existen los arrays y son validos los limites sino retorna -1
*/

int informar_clienteMenosVentasPendientes(Cliente arrayUno[],Venta arrayDos[],
                                int sizeUno,int sizeDos)//OK
{
    int retorno = -1;
    int i;
    int j;
    int flag = 1;
    int contadorVentas = 0;
    int contadorClientes = 0;
    int menorCantidad;
    Cliente arrayClientesVenta[sizeUno];
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
                            contadorVentas++;//Sumo la venta a cobrar del cliente
                        }
                    }
                }
            }

            if(flag == 1 ||
               contadorVentas < menorCantidad ||
               contadorVentas == menorCantidad)//Guardo el dato de la menor cantidad de ventas
            {
                menorCantidad = contadorVentas;
                arrayClientesVenta[i] = arrayUno[i];
                contadorClientes++;
                flag = 0;
            }
        }

        printf("\nCLIENTES CON MENOS VENTA %d",contadorClientes);
        printf("\nMENOR CANTIDAD DE VENTAS %d",menorCantidad);
        for(i=0;i<contadorClientes;i++)//Muestro los datos de los clientes con menor cantidad de ventas
        {
            if(arrayClientesVenta != NULL)
            {
                cliente_mostrar(arrayClientesVenta+i);
            }
        }

            retorno = 0;
    }

    return retorno;
}



/**
*\brief Lista los clientes con menos ventas cobradas
*\param arrayUno Es el array de cliente que recibe
*\param arrayDos Es el array de ventas que recibe
*\param sizeUno Es el tamaño del array uno
*\param sizeDos Es el tamaño del array dos
*\return Retorna 0 si existen los arrays y son validos los limites sino retorna -1
*/

int informar_clienteMenosVentasCobradas(Cliente arrayUno[],Venta arrayDos[],
                                int sizeUno,int sizeDos)//OK
{
    int retorno = -1;
    int i;
    int j;
    int flag = 1;
    int contadorVentas = 0;
    int contadorClientes = 0;
    int menorCantidad;
    Cliente arrayClientesVenta[sizeUno];
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
                            contadorVentas++;//Sumo la venta cobrada del cliente
                        }
                    }
                }
            }

            if(flag == 1 ||
               contadorVentas <  menorCantidad ||
               contadorVentas == menorCantidad)//Guardo el dato de menor cantidad de ventas
            {
                menorCantidad = contadorVentas;
                arrayClientesVenta[i] = arrayUno[i];
                contadorClientes++;
                flag = 0;
            }
        }

        printf("\nCLIENTES CON MENOS VENTA %d",contadorClientes);
        printf("\nMENOR CANTIDAD DE VENTAS %d",menorCantidad);
        for(i=0;i<contadorClientes;i++)//Muestro los datos de los clientes con menor cantidad de ventas
        {
            if(arrayClientesVenta != NULL)
            {
                cliente_mostrar(arrayClientesVenta+i);
            }
        }

            retorno = 0;
    }

    return retorno;
}

/**
*\brief Lista los clientes con mayor cantidad de afiches
*\param arrayUno Es el array de cliente que recibe
*\param arrayDos Es el array de ventas que recibe
*\param sizeUno Es el tamaño del array uno
*\param sizeDos Es el tamaño del array dos
*\return Retorna 0 si existen los arrays y son validos los limites sino retorna -1
*/

int informar_clienteMasAfiches(Cliente arrayUno[],Venta arrayDos[],
                                int sizeUno,int sizeDos)
{

    int retorno = -1;
    int i;
    int j;
    int flag = 1;
    int acumAfiches = 0;
    int contadorClientes = 0;
    int mayorCantidad;
    Cliente arrayClientesVenta[sizeUno];
    Venta* ventaSeleccionada;

    if(arrayUno != NULL && arrayDos != NULL && sizeUno > 0 && sizeDos > 0)//menor a 10
    {

        for(i=0;i<sizeUno;i++)//Recorro array clientes
        {
            acumAfiches = 0;

            if(!arrayUno[i].isEmpty)
            {
                for(j=0;j<sizeDos;j++)//Recorro array ventas
                {
                    if(arrayUno[i].id == arrayDos[j].idCliente)//Busca las ventas relacionadas al cliente
                    {
                        ventaSeleccionada = venta_getByID(arrayDos,sizeDos,arrayDos[j].id);

                        if(ventaSeleccionada != NULL && !strcmp(ventaSeleccionada->status,STATUS_1))
                        {
                            acumAfiches+=ventaSeleccionada->cantidad;//Tomo la cantidad de afiches de la venta
                        }
                    }
                }
            }

            if(flag == 1 ||
               acumAfiches > mayorCantidad ||
               acumAfiches == mayorCantidad)//Guardo el dato de mayor cantidad de afiches
            {
                mayorCantidad = acumAfiches;
                arrayClientesVenta[i] = arrayUno[i];
                contadorClientes++;
                flag = 0;
            }
        }

        printf("\nCLIENTES CON MAYOR CANTIDAD DE AFICHES %d",contadorClientes);
        printf("\nMAYOR CANTIDAD DE AFICHES %d",mayorCantidad);

        for(i=0;i<contadorClientes;i++)//Muestro los datos de los clientes con mayor cantidad de afiches
        {
            if(arrayClientesVenta != NULL)
            {
                cliente_mostrar(arrayClientesVenta+i);
            }
        }
            retorno = 0;
    }

    return retorno;
}

/**
*\brief Lista los clientes con menor cantidad de afiches
*\param arrayUno Es el array de cliente que recibe
*\param arrayDos Es el array de ventas que recibe
*\param sizeUno Es el tamaño del array uno
*\param sizeDos Es el tamaño del array dos
*\return Retorna 0 si existen los arrays y son validos los limites sino retorna -1
*/

int informar_clienteMenosAfiches(Cliente arrayUno[],Venta arrayDos[],
                                int sizeUno,int sizeDos)
{

    int retorno = -1;
    int i;
    int j;
    int flag = 1;
    int acumAfiches = 0;
    int contadorClientes = 0;
    int menorCantidad;
    Cliente arrayClientesVenta[sizeUno];
    Venta* ventaSeleccionada;

    if(arrayUno != NULL && arrayDos != NULL && sizeUno > 0 && sizeDos > 0)//menor a 10
    {

        for(i=0;i<sizeUno;i++)//Recorro array clientes
        {
            acumAfiches = 0;

            if(!arrayUno[i].isEmpty)
            {
                for(j=0;j<sizeDos;j++)//Recorro array ventas
                {
                    if(arrayUno[i].id == arrayDos[j].idCliente)//Busca las ventas relacionadas al cliente
                    {
                        ventaSeleccionada = venta_getByID(arrayDos,sizeDos,arrayDos[j].id);

                        if(ventaSeleccionada != NULL && !strcmp(ventaSeleccionada->status,STATUS_1))
                        {
                            acumAfiches+=ventaSeleccionada->cantidad;//Tomo la cantidad de afiches de la venta
                        }
                    }
                }
            }

            if(flag == 1 ||
               acumAfiches < menorCantidad ||
               acumAfiches == menorCantidad)//Guardo el dato de menor cantidad de ventas
            {
                menorCantidad = acumAfiches;
                arrayClientesVenta[i] = arrayUno[i];
                contadorClientes++;
                flag = 0;
            }
        }

        printf("\nCLIENTES CON MENOR CANTIDAD DE AFICHES %d",contadorClientes);
        printf("\nMENOR CANTIDAD DE AFICHES %d",menorCantidad);

        for(i=0;i<contadorClientes;i++)//Muestro los datos de los clientes con mayor cantidad de ventas
        {
            if(arrayClientesVenta != NULL)
            {
                cliente_mostrar(arrayClientesVenta+i);
            }
        }
            retorno = 0;
    }

    return retorno;
}


/**
*\brief Menu con opciones de informes
*\param arrayUno Es el array de cliente que recibe
*\param sizeUno Es el tamaño del array uno
*\param arrayDos Es el array de ventas que recibe
*\param sizeDos Es el tamaño del array dos
*\return Retorna 0 si existen los arrays y son validos los limites sino retorna -1
*/

int informar_menu(Cliente arrayClientes[],int sizeUno,Venta arrayVentas[],int sizeDos)
{
    int retorno = -1;
    int opcion;

    if(arrayClientes != NULL && sizeUno > 0 && arrayVentas != NULL && sizeDos > 0)
    {

        printf("\n1) ESTADO DE LAS VENTAS");
        printf("\n2) LISTADO DE VENTAS EN CABA\n3) LISTADO DE VENTAS EN GBA SUR\n4) LISTADO DE VENTAS EN GBA OESTE");
        printf("\n5) CLIENTES CON MAYOR VENTAS PENDIENTES\n6) CLIENTES CON MAYOR VENTAS COBRADAS");
        printf("\n7) CLIENTES CON MENOR VENTAS PENDIENTES\n8) CLIENTES CON MENOR VENTAS COBRADAS");
        printf("\n9) VENTAS SUPERIOR A PROMEDIO DE AFICHES\n10) VENTAS INFERIOR A PROMEDIO DE AFICHES");
        printf("\n11) SALIR DE INFORMES;");
        input_ScanInt("\nIngrese opcion: ",&opcion);

        do
        {
            limpiarPantalla();

            switch(opcion)
            {
                case 1:
                    informar_statusVentas(arrayVentas,sizeDos);
                    printf("\nIngrese cualquier tecla para continuar...");
                    limpiarMemoria();
                    getchar();
                break;
                case 2:
                    informar_calculoVentasZona(arrayVentas,sizeDos,1);
                    printf("\nIngrese cualquier tecla para continuar...");
                    limpiarMemoria();
                    getchar();
                break;
                case 3:
                    informar_calculoVentasZona(arrayVentas,sizeDos,2);
                    printf("\nIngrese cualquier tecla para continuar...");
                    limpiarMemoria();
                    getchar();
                break;
                case 4:
                    informar_calculoVentasZona(arrayVentas,sizeDos,3);
                    printf("\nIngrese cualquier tecla para continuar...");
                    limpiarMemoria();
                    getchar();
                break;
                case 5:
                    informar_clienteMasVentasPendientes(arrayClientes,arrayVentas,sizeUno,sizeDos);
                    printf("\nIngrese cualquier tecla para continuar...");
                    limpiarMemoria();
                    getchar();
                break;
                case 6:
                    informar_clienteMasVentasCobradas(arrayClientes,arrayVentas,sizeUno,sizeDos);
                    printf("\nIngrese cualquier tecla para continuar...");
                    limpiarMemoria();
                    getchar();
                break;
                case 7 :
                    informar_clienteMenosVentasPendientes(arrayClientes,arrayVentas,sizeUno,sizeDos);
                    printf("\nIngrese cualquier tecla para continuar...");
                    limpiarMemoria();
                    getchar();
                break;
                case 8:
                    informar_clienteMenosVentasCobradas(arrayClientes,arrayVentas,sizeUno,sizeDos);
                    printf("\nIngrese cualquier tecla para continuar...");
                    limpiarMemoria();
                    getchar();
                break;
                case 9:
                    informar_ventasPromedioAfiches(arrayVentas,sizeDos,1);
                    printf("\nIngrese cualquier tecla para continuar...");
                    limpiarMemoria();
                    getchar();
                break;
                case 10:
                    informar_ventasPromedioAfiches(arrayVentas,sizeDos,1);
                    printf("\nIngrese cualquier tecla para continuar...");
                    limpiarMemoria();
                    getchar();
                break;
                default :
                    printf("\nOpcion incorrecta");
                    printf("\nIngrese cualquier tecla para continuar...");
                    limpiarMemoria();
                    getchar();
            }


            printf("\nIngrese cualquier tecla para continuar...");
            limpiarMemoria();
            getchar();


        }while(opcion != 11);

        retorno = 0;

    }


    return retorno;
}


Cliente* informar_buscarClienteCuit(Cliente array[],int size,char cuit[])
{
    Cliente* retorno = NULL;
    int i;

    for(i=0;i<size;i++)
    {
        if(!strcmp(array[i].cuit,cuit))
        {
            retorno = array+i;
            break;
        }
    }
    return retorno;
}



int informar_initListadoCuit(Cliente array[],int qty_clientes)
{
    int i;
    int j;
    int retorno = -1;
    char auxListadoCuit[QTY_CLIENTES][13];
    char auxCuit[15];
    char listadoCuit[QTY_CLIENTES][15];

    for(i=0;i<qty_clientes;i++)
    {
        if(!array[i].isEmpty)
        {
           strncpy(auxCuit,array[i].cuit,15);//Guardo todos los CUITS en un nuevo listado
           strncpy(auxListadoCuit[i],auxCuit,15);
           printf("\nCUIT ORIGINAL %s",array[i].cuit);
           printf("\nCUIT COPIADO %s",auxCuit);
            printf("\nNUEVO CUIT UNICO: %s",auxListadoCuit[i]);
        }
    }

    for(i=0;i<qty_clientes;i++)
    {
        printf("\nITERACION %d -- CUIT %s",i,auxListadoCuit[i]);
        for(j=0;j<qty_clientes;j++)
        {
            if(!strcmp(array[j].cuit,auxListadoCuit[i]))//Comparo cada CUIT con todo el listado de clientes
            {
                strncpy(listadoCuit[i],auxListadoCuit[i],15);
                printf("\n\n %s",listadoCuit[i]);
            }
        }

    }

    for(i=0;i<qty_clientes;i++)
    {
        printf("\nCUIT -- %s",listadoCuit[i]);
    }

    retorno = 0;

    return retorno;
}


/*
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
*/

#ifndef INFORMAR_H_INCLUDED
#define INFORMAR_H_INCLUDED


#include "ventas.h"
#include "clientes.h"

int informar_statusVentas(Venta array[],
                                int size,
                                int status);

int informar_promedioCantidad(Venta array[],
                                int size,
                                int calculo);

int informar_calculoPromedioCantidad(Venta array[],
                                int size,
                                float* promedio);

int informar_calculoVentasZona(Venta array[],
                                int size,
                                int opcion);


int informar_clienteMasVentasCobradas(Cliente arrayUno[],Venta arrayDos[],
                                int sizeUno,int sizeDos);

int informar_clienteMasVentasPendientes(Cliente arrayUno[],Venta arrayDos[],
                                int sizeUno,int sizeDos);

int informar_clienteMasVentasCobradas(Cliente arrayUno[],Venta arrayDos[],
                                int sizeUno,int sizeDos);

int informar_clienteMenosVentasPendientes(Cliente arrayUno[],Venta arrayDos[],
                                int sizeUno,int sizeDos);

int informar_clienteMenosVentasCobradas(Cliente arrayUno[],Venta arrayDos[],
                                int sizeUno,int sizeDos);
int informar_listarClientes(Cliente array[],int size);

#endif

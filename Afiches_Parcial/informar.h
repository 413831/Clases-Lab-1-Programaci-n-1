#include "clientes.h"
#include "ventas.h"


int informar_ConsultaFacturacion(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas, char* cuit);


int informar_ListarContrataciones(Pantalla pantallas[],int sizeUno,
              Contratacion contrataciones[], int sizeDos,int lenght);

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

int informar_diasVenta(Venta arrayUno[],Cliente arrayDos[],
                                int sizeUno,int sizeDos);

int informar_importePorCuit(Cliente arrayUno[],
                            int sizeUno,
                            Venta arrayDos[],
                            int sizeDos,
                            char cuit[]);

int informar_clienteMasVentasCobradas(Cliente arrayUno[],Venta arrayDos[],
                                int sizeUno,int sizeDos);

int informar_clienteMasVentasPendientes(Cliente arrayUno[],Venta arrayDos[],
                                int sizeUno,int sizeDos);

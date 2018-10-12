#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"
#include "producto.h"

#define CANTIDAD_PRODUCTO 5

int main()

{
    Producto arrayProducto[CANTIDAD_PRODUCTO];
    int indiceVacio;
    int indiceID;
    int opcion = 0;
    int i;

    producto_init(arrayProducto,CANTIDAD_PRODUCTO,1);

    do
    {

        printf("\n\nIngrese opcion del menu:\n1) ALTA - 2) LISTAR - 3) BUSCAR - 4)EDITAR - 5)BORRAR\n");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1 :

                if(!producto_alta(arrayProducto,CANTIDAD_PRODUCTO))//Se realiza el ALTA en el indice vacio
                {
                    printf("\nNO HAY LUGARES VACIOS");
                }

               break;

            case 2 :

                for(i=0;i<CANTIDAD_PRODUCTO;i++)
                {
                    if(!arrayProducto[i].isEmpty)
                    {
                    producto_listar(arrayProducto,CANTIDAD_PRODUCTO);
                    }
                }
                break;
            case 3 :

                indiceID =producto_getById(arrayProducto,CANTIDAD_PRODUCTO);
                producto_mostrar(arrayProducto,CANTIDAD_PRODUCTO);
                break;
            case 4 :

                producto_modificar(arrayProducto,CANTIDAD_PRODUCTO);
                break;

            case 5 :

                producto_baja(arrayProducto,CANTIDAD_PRODUCTO);
                break;


            case 6 :
                sort_BubbleNombre(arrayProducto,CANTIDAD_PRODUCTO);

        }

    }while(opcion != 6);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "producto.h"
#define CANTIDAD_PRODUCTO 3
/*
1)  Definir un tipo de dato que represente un producto.
    El producto tiene un nombre, una descripcion y un precio

2)  Definir un array de 200 productos, indicar de alguna manera
    que la info de cada item no esta cargada.

3)  Realizar una funcion que reciba el array, un indice, y le
    permita al usuario cargar los datos en el item de la posicion especificada por el indice.

4)  Realizar una funcion que reciba el array y un indice e imprima
    los datos del item de la posicion especificada por el indice.

5)  Realizar una funcion que me devuelva el indice de un item vacio (sin cargar).


6) Realizar un programa con un menu de dos opciones:
    a) Cargar un producto
    b) Imprimir lista productos


7)  Agregar al tipo de dato el campo ID que represente un identificador unico.
    Modificar el codigo anterior para que el ID se genere automaticamente. Se debera cargar el ID automaticamente al cargar un producto, y se debera imprimir al imprimir la lista.

8)  Realizar una funcion que reciba el array y un ID, y me devuelva el indice
    del item con dicho ID.

9)  Realizar una funcion que reciba el array, un indice, y le permita al usuario
    modificar los campos nombre y precio del item del array en la posicion especificada por el indice.


10)  Agregar una opcion en el menu. "Editar producto" que pida al usuario el ID del
    mismo y le permita cambiar el nombre y el precio.

11)  Agregar una opcion en el menu "Borrar producto" que pida al usuario el ID del
    mismo.

*/
int main()
{
    Producto arrayProducto[CANTIDAD_PRODUCTO];
    int indiceVacio;
    int indiceID;
    int opcion = 0;
    int i;

    producto_initArrayProducto(arrayProducto,CANTIDAD_PRODUCTO,1);

    do
    {

        printf("\n\nIngrese opcion del menu:\n1) ALTA - 2) LISTAR - 3) BUSCAR - 4)EDITAR - 5)BORRAR\n");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1 :

                if(producto_buscarIndiceArray(arrayProducto,CANTIDAD_PRODUCTO,&indiceVacio))//Busca el indice vacio cada vez que se hace un ALTA
                {
                    printf("\nNO HAY LUGARES VACIOS");
                    break;
                }
                producto_altaArray(arrayProducto,indiceVacio,CANTIDAD_PRODUCTO);//Se realiza el ALTA en el indice vacio
                break;

            case 2 :

                for(i=0;i<CANTIDAD_PRODUCTO;i++)
                {
                    if(!(arrayProducto[i].isEmpty == 1))
                    {
                    producto_mostrarArray(arrayProducto,i,CANTIDAD_PRODUCTO);
                    }

                }
                break;
            case 3 :

                indiceID =producto_IDproducto(arrayProducto,CANTIDAD_PRODUCTO);
                producto_mostrarArray(arrayProducto,indiceID,CANTIDAD_PRODUCTO);
                break;
            case 4 :

                producto_modificarProducto(arrayProducto,CANTIDAD_PRODUCTO);
                break;

            case 5 :

                producto_eliminarProducto(arrayProducto,CANTIDAD_PRODUCTO);
                break;

        }

    }while(opcion != 6);


    return 0;
}







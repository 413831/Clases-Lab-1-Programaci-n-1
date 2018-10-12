typedef struct sProducto
{
    char descripcion[100];
    char nombre[100];
    float precio;
    int isEmpty;
    int ID;

}Producto;

int producto_init(Producto array[],int size,int value);
int producto_alta(Producto array[],int size);
int producto_listar(Producto array[],int size);
int producto_mostrar(Producto array[],int size);
int producto_getById(Producto array[],int size);
int producto_modificar(Producto array[],int size);
int producto_baja(Producto array[],int size);
int sort_BubbleNombre(Producto* array,int size);//MODIFICAR SEGUN TIPO

typedef struct sElemento
{
    char descripcion[100];
    char nombre[100];
    float precio;
    int isEmpty;
    int id;
}Elemento;

int elemento_init(Elemento array[],int size,int value);
Elemento* elemento_getById(Elemento* array, int size,int id);
int elemento_buscarById(Elemento array[],int size);
int elemento_alta(Elemento array[],int size);
int elemento_modificar(Elemento array[],int size);
int elemento_baja(Elemento array[],int size);
int elemento_listar(Elemento array[],int size);
int elemento_mostrar(Elemento array[],int size);
int sort_BubbleNombre(Elemento* array,int size);//MODIFICAR SEGUN TIPO


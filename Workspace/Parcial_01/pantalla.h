#define LED 0
#define LCD 1


typedef struct sPantalla
{
    char nombre[100];
    char direccion[100];
    float precio;//Precio por dia
    int tipo;
    int isEmpty;
    int id;
}Pantalla;


int pantalla_init(Pantalla array[],int size,int value);
Pantalla* pantalla_getById(Pantalla* array, int size,int id);
int pantalla_buscarById(Pantalla array[],int size);
int pantalla_alta(Pantalla array[],int size);
int pantalla_modificar(Pantalla array[],int size);
int pantalla_baja(Pantalla array[],int size);
int pantalla_listar(Pantalla array[],int size);
int pantalla_mostrar(Pantalla array[],int size);
int pantalla_ordenarNombre(Pantalla* array,int size);//MODIFICAR SEGUN TIPO


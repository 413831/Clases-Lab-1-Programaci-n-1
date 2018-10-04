#ifndef PANTALLA_H_INCLUDED
#define PANTALLA_H_INCLUDED
typedef struct
{
    char nombre[50];
    char direccion[50];
    float precio;
    int tipo;
    //------------
    int id;
    int isEmpty;
}Pantalla;


int pantalla_buscarIndiceLibre(Pantalla array[],int size);
Pantalla* pantalla_getByID(Pantalla* array,int size, int id);
int pantalla_init(Pantalla array[],int size,int valor);
int pantalla_mostrar(Pantalla* array,int size);
int pantalla_mostrarDebug(Pantalla* array,int size);
int pantalla_alta(Pantalla* array,int size);
int pantalla_eliminar(Pantalla* array,int size);
int pantalla_modificar(Pantalla* array,int size);
int pantalla_listar(Pantalla* array,int size);
int pantalla_sortName(Pantalla array[],int size);
int pantalla_ordenar(Pantalla* array,int size,int orden);

int pantalla_ingresoForzado(Pantalla array[],int size,char nombre[],char direccion[],int precio,int tipo);

//int proximoId();
//int pantalla_buscarPorId(Pantalla* array,int size, int id);

#endif // PANTALLA_H_INCLUDED

#ifndef ELEMENTO_H_INCLUDED
#define ELEMENTO_H_INCLUDED
typedef struct
{
    char nombre[50];
    char direccion[50];
    float precio;
    int tipo;
    //------------
    int id;
    int isEmpty;
}Elemento;


int elemento_buscarIndiceLibre(Elemento array[],int size);
int elemento_init(Elemento array[],int size,int valor);
Elemento* elemento_getByID(Elemento* array,int size,int id)
int elemento_alta(Elemento* array,int size)
int elemento_modificar(Elemento* array);
int elemento_eliminar(Elemento* array)
int elemento_ordenar(Elemento array[],int size);
int elemento_mostrar(Elemento* array);
int elemento_listar(Elemento array[],int size);
int elemento_ingresoForzado(Elemento array[],
				int size,
				char nombre[],
				char direccion[],
				int precio,
				int tipo)


//int proximoId();
//int pantalla_buscarPorId(Pantalla* array,int size, int id);

#endif // ELEMENTO_H_INCLUDED

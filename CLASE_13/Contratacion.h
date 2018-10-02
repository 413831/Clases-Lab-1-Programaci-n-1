#ifndef CONTRATACION_H_INCLUDED
#define CONTRATACION_H_INCLUDED
typedef struct
{
    char cuit[50];
    int idContratacion;
    int dias;
    int idPantalla;
    char archivo[50];
    //------------
    int id;
    int isEmpty;
}Contratacion;


int cont_buscarIndiceLibre(Contratacion array[],int size);
int cont_init(Contratacion array[],int size,int valor);
int cont_mostrar(Contratacion* array,int size);
int cont_alta(Contratacion array[],int size,int id);
int cont_eliminar(Contratacion* array,int size);
int cont_modificar(Contratacion* array,int size);
int cont_ordenar(Contratacion* array,int size, int orden);
Contratacion* cont_getByID(Contratacion* array,int size, int id);
int cont_altaForzada(Contratacion* array,int size,char* cuit,int idContratacion,int dias, char archivo[]);

#endif // PANTALLA_H_INCLUDED



typedef struct sContratacion
{
    char cuitCliente[15];
    int diasContratacion;
    char nombreArchivo[30];
    int isEmpty;
    int id;//ID de Contratacion
    int idContratacion;//Pantalla alquilada
}Contratacion;


int contratacion_init(Contratacion array[],int size,int value);
Contratacion* contratacion_getById(Contratacion* array, int size,int id);
int contratacion_buscarByCuit(Contratacion array[],int size,char* cuit);
int contratacion_buscarById(Contratacion array[],int size);
int contratacion_alta(Contratacion array[],int size);
int contratacion_modificar(Contratacion array[],int size);
int contratacion_baja(Contratacion array[],int size);
int contratacion_listar(Contratacion array[],int size);
int contratacion_mostrar(Contratacion array[],int size);
int contratacion_ordenarNombre(Contratacion* array,int size);//MODIFICAR SEGUN TIPO


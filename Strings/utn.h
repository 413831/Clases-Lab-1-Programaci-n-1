#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED


/**
    utn_getEntero : pide un entero al usuario
    @param pEdad: puntero a edad
    @param reintentos: cantidad de reintentos
    @return : 0 OK, -1 error.
*/
int utn_getEntero(int* pEdad,int reintentos,char* msg,
                          char*msgErr,int min, int max);
int array_mostrar(int* pArray, int limite);
int array_calcularMaximo(int* pArray, int limite, int* pMaximo);
int array_init(int* pArray, int limite, int valor);
int array_ordenar(int* pArray, int limite, int orden);
int array_minimoDesde(  int* pArray, int limite,
                        int desde, int* pMinimo);
void array_swap(int* elementoA,int* elementoB);
int array_ordenar2(int* pArray, int limite, int orden);
int getInt(int* pResultado,int j,int limite);

void insertionSort(int array[], int size);
void bubbleSort(int array[],int size);



#endif // UTN_H_INCLUDED

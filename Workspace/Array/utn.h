int getCaracter(char * caracterAuxiliar,char mensaje[50]);
int getNumero(float * numeroAuxiliar);
float funcionSuma(float auxiliarUno,float auxiliarDos);
float funcionResta(float auxiliarUno,float auxiliarDos);
float funcionMultiplicar(float auxiliarUno,float auxiliarDos);
float funcionDividir(float auxiliarUno,float auxiliarDos);
double funcionFactorial(float auxiliarUno);
int funcionCalculos(float auxiliarUno,float auxiliarDos);
int menuCalculosDosNumeros();
int utn_getEntero(int* pEdad,int reintentos,char* msg,
                          char*msgErr,int min, int max);
int array_mostrar(int* pArray, int limite);
int array_calcularMaximo(int* pArray, int limite, int* pMaximo);
int array_init(int* pArray, int limite, int valor);
int array_ordenar(int* pArray, int limite, int orden);
int array_minimoDesde(  int* pArray, int limite,
                        int desde, int* pMinimo);
int array_swap(int* elementoA,int* elementoB);
int array_ordenar2(int* pArray, int limite, int orden);
void mostrarInfoArray(int array[],int size);
int retornarNumeroMenor(int array[],int size);
int retornarNumeroMayor(int array[],int size);
int retornarNumerosPares(int array[],int size);
int getInt(int* pResultado);
int empleadosSueldo(int* edad,float* sueldo,float* sumaTotal,float* promedio,int size);
int cargaSecuencial(int* pEdad,float* pSueldo,int size);
int cargaAleatoria(int* pEdad,float* pSueldo,int size);


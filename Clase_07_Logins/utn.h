/**
*Funciones de ENTRADA
*/
int input_getInt(char* mensaje);
float input_getFloat(char* mensaje);
char input_getChar(char* mensaje);
void input_modificarArray(int* pArray,int* pIndice,int* pSize,char* pMensaje);
/**
*Funciones de CÁLCULOS
*/
float calculo_AreaCirculo(float radio);
/**
*Funciones de VALIDACION y TESTING
*/
char test_RandomInt(int desde , int hasta, int iniciar);
int validacion_Int(char* array);
int validacion_Float(char* array);
int validacion_Nombre(char* array);
int validacion_AlfaNumerico(char* array);
int validacion_Telefono(char* array);
int validacion_DNI(char* array);

/**
*Funciones de LISTADOS
*/
void array_mostrarInt(int* pArray,int indice,int size,char* pMensaje);


/**
*Funciones de ORDENAMIENTO de Array
*/
void sort_Bubble(int* pArray,int size);
int sort_Selection(int* pArray, int limite, int orden);
int sort_Insertion(int* pArray, int limite, int orden);

/**
*Funciones de STRING
*/
void string_getString(char mensaje[],int size, char input[]);
int string_getStringLetras(char mensaje[],int size,char* input);
int string_getStringNumeros(char mensaje[],int size);

int informar_ConsultaFacturacion(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas, char* cuit);


int informar_ListarContrataciones(Pantalla pantallas[],int sizeUno,
              Contratacion contrataciones[], int sizeDos,int lenght);


int informar_listadoCuit(Contratacion array[],int size,int length,char listado[]);


int informar_promedioPantallas(Pantalla array[],
                                int size,
                                int calculo);

int informar_valorPantallas(Pantalla array[],
                                int size,
                                int calculo);

int informar_mostrarPantallas(Pantalla array[],
                                int size,
                                int valor);

int informar_calculoPromedio(Pantalla array[],
                                int size,
                                float* promedio);

int informar_diasContratacion(Contratacion arrayUno[],Pantalla arrayDos[],
                                int sizeUno,int sizeDos);
int informar_valorContratacion(Pantalla* pantalla,
                               Contratacion* contratacion,
                               float* valor);

int informar_importePorCuit(Pantalla arrayUno[],
                            int sizeUno,
                            Contratacion arrayDos[],
                            int sizeDos,
                            char cuit[]);


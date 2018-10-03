int informar_ConsultaFacturacion(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas, char* cuit);

int informar_ListarContrataciones(Contratacion* arrayC,int sizeUno, char CUIT,int sizeDos,
              Pantalla* pantallas, int lenPantallas);


int informar_ListarCantidadContratacionesImporte(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas);
int informar_promedioPantallas(Pantalla array[],
                                int size,
                                float* promedio);

int informar_calculosPantallas(Pantalla array[],
                                int size,
                                int calculo);

int informar_mostrarPantallas(Pantalla array[],
                                int size,
                                int valor);



int informar_calculosContratacion(Contratacion arrayUno[],Pantalla arrayDos[],
                                int sizeUno,int sizeDos);
int informar_listadoCuit(Contratacion array,int size,char CUIT,int lenCuit,char arrayCuit[]);

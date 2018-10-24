#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct{
    char nombre[64];
    char apellido[64];
    int id;
}Cliente;

Cliente* cli_newCliente(void);
int cli_buscarLugarVacio(Cliente* array[], int len);
int cli_inicializarArray(Cliente* array[], int len);

int cli_getNombre(Cliente* this,char* nom);
int cli_setNombre(Cliente* this,char* nom);

#endif // CLIENTE_H_INCLUDED

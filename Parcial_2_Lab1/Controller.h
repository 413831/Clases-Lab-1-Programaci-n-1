#include "LinkedList.h"
#include "Venta.h"

int controller_loadFromText(char* path , LinkedList* pLinkedList);
int controller_loadFromBinary(char* path , LinkedList* pLinkedList);
int controller_addVenta(LinkedList* pLinkedList);
int controller_editVenta(LinkedList* pLinkedList);
int controller_removeVenta(LinkedList* listaPrincipal[]);
int controller_ListVenta(LinkedList* pLinkedList);
int controller_insertVenta(LinkedList* listaPrincipal[]);
int controller_generateNewList(LinkedList* listaPrincipal);
int controller_undoList(LinkedList* listaPrincipal[]);
int controller_sortVenta(LinkedList* pLinkedList);
int controller_saveAsText(char* path , LinkedList* pLinkedList);
int controller_saveAsBinary(char* path , LinkedList* pLinkedList);
int controller_init();

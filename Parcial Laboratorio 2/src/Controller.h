int controller_loadFromText(char* path , LinkedList* pArrayListLibro);
int controller_loadFromBinary(char* path , LinkedList* pArrayListLibro);
int controller_addLibro(LinkedList* pArrayListLibro, int id);
int controller_editLibro(LinkedList* pArrayListLibro);
int controller_removeLibro(LinkedList* pArrayListLibro);
int controller_ListLibro(LinkedList* pArrayListLibro);
int controller_sortLibro(LinkedList* pArrayListLibro);
int controller_saveAsText(char* path , LinkedList* pArrayListLibro);
int controller_saveAsBinary(char* path , LinkedList* pArrayListLibro);

int controller_ordenarPorAutor(void* libroUno, void* LibroDos);
int controller_descuento(LinkedList* this);
void controller_calcularDescuento(void* pElement);
int controller_leeUltimoId();
void controller_EscribirUltimoId();

int controller_Filter(LinkedList* this);
int controller_filtraAutor(void* pElement);
void controller_count(LinkedList* this);
int controller_contarPorAutor(void* pElement);

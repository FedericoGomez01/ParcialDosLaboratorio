#ifndef eLibro_H_INCLUDED
#define eLibro_H_INCLUDED

//typedef struct
//{
//    char PLANETA[128];
//    char SIGLOXXIEDITORES[128];
//    char PEARSON[128];
//    char MINOTAURO[128];
//    char SALAMANDRA[128];
//    char PENGUINBOOKS[128];
//}eEditoriales;

typedef struct
{
    int id;
    char nombreLibro[128];
    char autor[128];
    int precio;
    char editorial[128];
}eLibro;

eLibro* eLibro_new();
eLibro* eLibro_newParametros(char* idStr,char* nombreStr,char* autorStr, char* sueldo, char* editorial);
void eLibro_delete();

int eLibro_setId(eLibro* this,int id);
int eLibro_getId(eLibro* this,int* id);

int eLibro_setNombreLibro(eLibro* this,char* nombre);
int eLibro_getNombreLibro(eLibro* this,char* nombre);

int eLibro_setAutor(eLibro* this,char* autorStr);
int eLibro_getAutor(eLibro* this,char* autorStr);

int eLibro_setPrecio(eLibro* this,int precio);
int eLibro_getPrecio(eLibro* this,int* precio);


int eLibro_setEditorialId(eLibro* this, char* editorial);
int eLibro_getEditorialId(eLibro* this, char* editorial);

int eLibro_printOne(eLibro* this);
#endif // eLibro_H_INCLUDED

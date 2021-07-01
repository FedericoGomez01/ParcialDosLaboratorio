#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"
#include "LinkedList.h"
#include "Controller.h"
#include "eLibro.h"

/****************************************************
    Menu:
     1. Cargar los datos de los Libros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los Libros desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar Libros
     7. Ordenar Libros
     8. Guardar los datos de los Libros en el archivo data.csv (modo texto).
     9. Guardar los datos de los Libros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout,NULL);
    int option;
    //int flagGuardado=0;
    char path[128];
    LinkedList* listaLibros = ll_newLinkedList();


    do{
    	//int idAutoincremental = controller_leeUltimoId();
    	Menu("\n=================================================================================\n"
			 "                                     MENU                                        \n"
			 "=================================================================================\n"
			"1. Cargar los datos de los Libros desde el archivo Datos.csv (modo texto).\n"
			"2. Odenar\n"
			"3. Imprimir\n"
			"4. Descuentos\n"
			"5. Generar 'mapeado.csv' con descuentos\n"
			"10. Salir\n");
    	option = Get_IntRange("INICIE EL MENU: ", "ERROR. REINGRESE: ", 1, 10);
		switch(option)
        {
            case 1:
            	Get_String("INGRESE EL NOMBRE DEL ARCHIVO A LEER: (Datos) ", "ERROR. REINGRESE: ", path, 127);
            	strcat(path, ".csv");
            	if(ll_len(listaLibros)>0 && listaLibros!=NULL){
                	if(Validate_Exit_SN("DESEA SOBREESCRIBIR LOS DATOS CARGADOS?: [S]-SI [N]-NO", "ERROR. REINGRESE: ")){
                		ll_clear(listaLibros);
                		controller_loadFromText(path,listaLibros);
                    	break;
                	}else{
                    	controller_loadFromText(path,listaLibros);
                	}
            	}else{
                	controller_loadFromText(path,listaLibros);
            	}
                break;
            case 2:
            	if(ll_len(listaLibros)>0 && listaLibros!=NULL){
					int (*pFunc)(void*, void*);
					pFunc = &controller_ordenarPorAutor;
					ll_sort(listaLibros, pFunc, 0);
				}else{
					puts("DEBE CARGAR UNA LISTA DE Libros");
				}
            	break;
            case 3:
            	if(ll_len(listaLibros)>0 && listaLibros!=NULL){
            		controller_ListLibro(listaLibros);
            	}else{
            		puts("DEBE CARGAR UNA LISTA DE Libros");
            	}
            	break;
            case 4:
            	if(ll_len(listaLibros)>0 && listaLibros!=NULL){
            		controller_descuento(listaLibros);
            	}else{
            		puts("DEBE CARGAR UNA LISTA DE Libros");
            	}
            	break;
            case 5:
            	if(ll_len(listaLibros)>0 && listaLibros!=NULL){
            		controller_saveAsText("mapeado.csv", listaLibros);
            	}else{
            		puts("DEBE CARGAR UNA LISTA DE Libros");
            	}
            	break;
            case 6:
            	if(ll_len(listaLibros)>0 && listaLibros!=NULL){
            		if(controller_Filter(listaLibros))
            			puts("SE FILTRO CON EXITO");
            	}else{
            		puts("DEBE CARGAR UNA LISTA DE Libros");
            	}
            	break;
            case 7:
            	controller_count(listaLibros);
            	break;
            case 10:
            	if(ll_len(listaLibros)>0 && listaLibros!=NULL){
//            		if(flagGuardado!=1){
//            			if(Validate_Exit_SN("DESEA SALIR SIN GUARDAR? [S]-SI  [N]-NO", "ERROR. REINGRESE: ")){
//							ll_deleteLinkedList(listaLibros);
//            				option =10;
//						}else{
//
//					    	Menu("\n=================================================================================\n"
//								 "                                     MENU                                        \n"
//								 "=================================================================================\n"
//								"1. Cargar los datos de los Libros desde el archivo Datos.csv (modo texto).\n"
//								"6. Imprimir\n"
//								"4. Odenar\n"
//								"10. Salir\n");
//							option = Get_IntRange("INICIE EL MENU: ", "ERROR. REINGRESE: ", 1, 10);
//						}
//            		}else{
					option =10;
					ll_deleteLinkedList(listaLibros);
//            		}
            	}
            	break;
        }
    }while(option != 10);
    puts("GRACIAS POR USAR EL PROGRAMA!");
    return 0;
}


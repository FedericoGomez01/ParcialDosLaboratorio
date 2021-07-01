#ifndef PARSER_H_
#define PARSER_H_

int parser_eLibroFromText(FILE* pFile , LinkedList* pArrayListeLibro);

int parser_eLibroFromBinary(FILE* pFile , LinkedList* pArrayListeLibro);

int parser_obterenUltimoId(FILE* pFile);


#endif /* PARSER_H_ */

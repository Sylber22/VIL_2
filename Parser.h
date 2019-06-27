#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include "LinkedList.h"

int parser_parseEmpleados(FILE* pFile, LinkedList* listaEntregas);
int parser_loadFromText(char* path , LinkedList* listaEntregas);

#endif // PARSER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "Empleado.h"
#include "Parser.h"

#include "LinkedList.h"
#include "UTN_Bibloteca.h"
#include "Validaciones.h"
int parser_loadFromText(char* path , LinkedList* listaEntregas)
{
    int ret=-1;
    FILE* fp;
    fp= fopen(path, "r");
    if( fp!=NULL && path!=NULL)
    {
        if(!parser_parseEmpleados(fp, listaEntregas))
        {
            ret=1;
        }
    }
    else
    {
        exit(EXIT_FAILURE);
    }
    fclose(fp);
    return ret;
}

int parser_parseEmpleados(FILE* pFile, LinkedList* listaEntregas)
{
    int ret=-1;
    char bufferId[4096];
    char bufferTipo[4096];
    char bufferCant[4096];
    char bufferPeso[4096];
    int i=0;
    int r=0;
    Entregas *bufferEntregas= emp_new();

    if(pFile != NULL)
    {
        //CABECERA
        r=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferTipo,bufferCant, bufferPeso);
        printf("%s %s %s    %s\n", bufferId, bufferTipo, bufferCant, bufferPeso);
        while(!feof(pFile))
        {
            r= fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId, bufferTipo, bufferCant, bufferPeso);
            if(r==4)
            {
                bufferEntregas = emp_newParameters(bufferId, bufferTipo, bufferCant, bufferPeso);
                if((bufferEntregas != NULL)&&(!ll_add(listaEntregas,bufferEntregas)))
                    {
                        //emp_printEntregas(bufferEntregas);
                        i++;
                        ret=0;
                    }
            }//IF==4
            else
               {
                    break;
                }
        }//WHILE
        printf("SE CARGARON %d ENTREGAS\n", i);
    }//IF NULL
    return ret;
}


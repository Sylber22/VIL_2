#include <stdio.h>
#include <stdlib.h>
#include "Empleado.h"
//#include "ArrayList.h"
#include "Parser.h"

#include "LinkedList.h"
#include "UTN_Bibloteca.h"
#include "Validaciones.h"
/**
    Realizar un programa que lee de un archivo los datos de empleados y los guarda en un arraylist de entidades
    empleado.
    Luego, debera calcular el campo "sueldo" de cada uno de los empleados leidos, segun la horas que trabajaron, con el
    siguiente criterio:
    Los valores de horas varian entre 80 y 240.
    - Las primeras 120 horas la hora vale $180
    - De 120 a 160 horas, la hora vale $240
    - De 160 a 240 horas, la hora vale $350

    Para hacer este calculo, se debera desarrollar la funcion "map" en al biblioteca ArrayList, La cual recibe la lista y una funcion.
    La funcion map ejecutara la funcion recibida como parametro por cada item de la lista, y le pasaran en cada llamada, uno de los items.
    De esta manera la funcion pasada como parametro podra realizar un calculo con el item recibido, en este caso, calcular el sueldo.

    Una vez cargados los campos sueldo en las entidades, se debera generar un archivo de salida "sueldos.csv" el cual sera igual que el
    original pero con una columna mas al final, en donde se indicara el sueldo calculado.
*/

int generarArchivo(char* path,LinkedList* listaEntregas);

int main()
{


    // Definir lista de empleados
    // Crear lista empledos
    LinkedList* listaEntregas=ll_newLinkedList();
    if(parser_loadFromText("data.csv",listaEntregas)==1)
        {
            // emp_printEntregas(listaEntregas);
            // Generar archivo de salida

            if(!generarArchivo("Informes.txt",listaEntregas))
            {
                printf("Archivo generado correctamente\n");
            }
            else
                printf("Error generando archivo\n");
        }
        else
        printf("Error leyendo empleados\n");
    return 0;
}

int generarArchivo(char* path,LinkedList* listaEntregas)
{
    int ret= -1;
    //int lenLista = ll_len(listaEntregas);
    int contadorSTD=0;
    int contadorECO=0;
    int contadorEXP=0;
    FILE* fileName = fopen(path, "w");


    if((fileName!=NULL) && (listaEntregas!=NULL))
    {
        contadorSTD=contadorStd(listaEntregas);
        contadorEXP=contadorExp(listaEntregas);
        contadorECO=contadorEco(listaEntregas);

        printf( "********************\n");
        printf( "Informe de ventas\n");
        printf( "********************\n");
        printf( "Cantidad total de entregas: %d\n",sumadorDeEntregas(listaEntregas));
        printf( "Cantidad de entregas por tipo: %d (STD) - %d (EXP) - %d (ECO)\n", contadorSTD, contadorEXP, contadorECO);
        printf( "Cantidad maxima de bultos entregados: %d\n",maximoBultos(listaEntregas));
        printf( "Promedio de bultos por entrega: %.2f\n",(float)(promedioEntregas(listaEntregas)));
        printf( "Peso promedio por entrega: %.2f\n",(float)promedioPeso(listaEntregas));


        fprintf(fileName,"********************\n");
        fprintf(fileName, "Informe de ventas\n");
        fprintf(fileName,"********************\n");
        fprintf(fileName, "\nCantidad de bultos entregados %d \n", sumadorDeEntregas(listaEntregas));
        fprintf(fileName, "Cantidad de entregas por tipo: %d (STD) - %d (EXP) - %d (ECO)\n", contadorSTD, contadorEXP, contadorECO);
        fprintf(fileName, "Cantidad maxima de bultos entregados: %d\n",maximoBultos(listaEntregas));
        fprintf(fileName, "Promedio de bultos por entrega: %.2f\n",(float) promedioEntregas(listaEntregas));
        fprintf(fileName, "Peso promedio por entrega: %.2f\n",(float)promedioPeso(listaEntregas));



        printf("Se ha realizado el guardado del archivo con exito\n");
        ret=0;

    }//NULL
    fclose(fileName);
    return ret;
}


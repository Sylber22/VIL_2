#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED
#include "LinkedList.h"
typedef struct
{
  int id;
  char tipo[128];
  int cant;
  float peso;
}Entregas;

int em_calcularSueldo(void* p);
int emp_reduceForSalary(void* p);
int contadorStd(LinkedList* this);
int entregaStd(void* p);
int contadorEco(LinkedList* this);
int entregaEco(void* p);
int contadorExp(LinkedList* this);
int entregaExp(void* p);
int entregas(void* p);
int sumadorDeEntregas(LinkedList* this);
int parametroMaximo(void* p);
int maximoBultos(LinkedList* this);
float peso(void* p);
float promedioPeso(LinkedList* this);
float promedioEntregas(LinkedList* this);
//----------------------------------------
Entregas* emp_new();
Entregas* emp_newParameters(char* pId,char* pTipo,char* pCant, char* pPeso);
int emp_Delete(Entregas* this);

int emp_setId(Entregas* this,int id);
int emp_setStrId(Entregas* this, char* strId);
int emp_getId(Entregas* this,int* id);

int emp_setTipo(Entregas* this,char* tipo);
int emp_getTipo(Entregas* this,char* tipo);

int emp_setCant(Entregas* this,int cant);
int emp_setStrCant(Entregas* this, char* strCant);
int emp_getCant(Entregas* this,int* cant);

int emp_setPeso(Entregas* this,float peso);
int emp_setStrPeso(Entregas* this, char* strPeso);
int emp_getPeso(Entregas* this,float* peso);

int emp_sortByTipo(void* empA, void* empB);
//------------------------------------------------
void emp_printEntregas(Entregas* this);

//------------------------------------------------

#endif // EMPLEADO_H_INCLUDED

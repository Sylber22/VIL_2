#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "LinkedList.h"
#include "UTN_Bibloteca.h"
#include "Validaciones.h"

#include "Empleado.h"
/*int reduceList(LinkedList* this)
{
    int ret=-1;
    if(!ll_reduce(this, emp_reduceForSalary))
    {
        ret=0;
    }
    return ret;
}
int emp_reduceForSalary(void* p)
{
    int ret=-1;
    int bufferSalary;
    Entregas* pLista;

     if(p!=NULL)
   {
    pLista=(Entregas*)p;

       if(!emp_getSalary(pLista, &bufferSalary))
       {
           if(bufferSalary<15000)
           {
               emp_Delete(pLista);
               ret=0;
           }
       }
   }

   return ret;
}*/


float promedioEntregas(LinkedList* this)
{
    int lenList=ll_len(this);
    float cantidadTotal=0;
    float cantidadPromedio=0;
    cantidadTotal=ll_sumador(this, entregas);
    cantidadPromedio= (float)cantidadTotal/lenList;
    //printf("TOTAL %d", cantidadPromedio;
    return cantidadPromedio;
}

//------------------------------------------------------
float promedioPeso(LinkedList* this)
{
    int lenList=ll_len(this);
    float cantidadTotal=0;
    float cantidadPromedio=0;
    cantidadTotal=ll_sumadorFloat(this, peso);
    cantidadPromedio= cantidadTotal/lenList;
    //printf("TOTAL %.2f", (float)cantidadPromedio);
    return cantidadPromedio;
}

float peso(void* p)
{
    float bufferPeso;
    Entregas* pLista;
    pLista=(Entregas*)p;

    if(pLista!=NULL)
    {
       emp_getPeso(pLista, &bufferPeso);
        //printf("suma %.2f\n", bufferPeso);
    }
    return bufferPeso;
}

int maximoBultos(LinkedList* this)
{
    int contador=0;
    contador=ll_maximo(this, parametroMaximo);
    return contador;
}

int parametroMaximo(void* p)
{
    int ret=-1;
    int bufferCant;
    Entregas* pLista;
    pLista=(Entregas*)p;

    if(pLista!=NULL)
    {
       emp_getCant(pLista, &bufferCant);
        ret=bufferCant;
    }
    return ret;
}

int sumadorDeEntregas(LinkedList* this)
{
    int contador=0;
    contador=ll_sumador(this, entregas)+contador;
    return contador;
}

int entregas(void* p)
{
    int bufferCant;
    int ret=0;
    Entregas* pLista;
    pLista=(Entregas*)p;

    if(pLista!=NULL)
    {
       emp_getCant(pLista, &bufferCant);
        ret=bufferCant;
    }
    return ret;
}

int contadorStd(LinkedList* this)
{
     int contador=0;
    contador+=ll_counter(this, entregaStd);
    return contador;
}

int entregaStd(void* p)
{
    char buffer[51];
    int ret=0;
    Entregas* pLista;
    pLista=(Entregas*)p;

    if(pLista!=NULL)
    {
        emp_getTipo(pLista, buffer);
        if(strcmp(buffer, "STD")== 0)
        {
             ret = 1;
        }
    }
    return ret;
}
int contadorEco(LinkedList* this)
{
    int contador=0;
    contador+=ll_counter(this, entregaEco);
    return contador;
}

int entregaEco(void* p)
{
    char buffer[51];
    int ret=0;
     Entregas* pLista;
    pLista=(Entregas*)p;

    emp_getTipo(pLista, buffer);
    if(pLista!=NULL)
    {
        if(strcmp(buffer, "ECO")== 0)
        {
             ret = 1;
        }
    }
    return ret;
}
int contadorExp(LinkedList* this)
{
    int contador=0;
    contador+=ll_counter(this, entregaExp);
    return contador;
}

int entregaExp(void* p)
{
    char buffer[51];
    int ret=0;
     Entregas* pLista;
    pLista=(Entregas*)p;

    emp_getTipo(pLista, buffer);
    if(pLista!=NULL)
    {
        if(strcmp(buffer, "EXP")== 0)
        {
             ret = 1;
        }
    }
    return ret;
}
Entregas* emp_new()
{
    return(Entregas*)malloc(sizeof(Entregas));
}
/** \brief le da nuevos para metros a la estructura de empleado y crea la una lista
 *
 * \param cadena de los campos de la estructura
 * \return la lista llena
 *
 */
Entregas* emp_newParameters(char* pId,char* pTipo,char* pCant, char* pPeso)
{
    Entregas* bufferEntregas= emp_new();

    if(bufferEntregas!=NULL)
    {
     if((emp_setStrId(bufferEntregas, pId))||
        (emp_setTipo(bufferEntregas, pTipo))||
        (emp_setStrCant(bufferEntregas, pCant))||
        (emp_setStrPeso(bufferEntregas, pPeso)))
           {
             emp_Delete(bufferEntregas);
           }
    }
    return bufferEntregas;// DEVUELVE LA LIST LLENA
}

/** \brief borra el empleado
 *
 * \param la lista
 * \return -1 si dio erro y 0 si se pudo borra el empleado
 *
 */
int emp_Delete(Entregas* this)
{
    int ret = -1;
    if(this != NULL)
    {
        free(this);
        ret = 0;
    }
    return ret;
}

/** \brief Recibe una cadena y verifica si se pudo convertir a un entero valido
 *
 * \param la lista de empleados
 * \param la cadena que contiene el id
 * \return 0 si se pudo convertir, -1 si hubo error
 *
 */
int emp_setStrId(Entregas* this, char* strId)
{
    int ret=-1;
    int bufferId;
    if(this!=NULL && esNumerico(strId))
    {
        bufferId= atoi(strId);
        if(!emp_setId(this, bufferId))
        {
          ret=0;
        }
    }
    return ret;
}

/** \brief recibe un entero y verifica si es un id valido y lo guarda
 *
 * \param la lista de empleados
 * \param el numero entero: id
 * \return 0 si se pudo convertir, -1 si hubo error
 *
 */
int emp_setId(Entregas* this,int id)
{
    int ret = -1;
    if(this != NULL && id >0)
    {
        this->id = id;
        ret = 0;
    }
    return ret;
}

/** \brief guar el id en el campo id de la estructura
 *
 * \param la lista de empleados
 * \return  0 si se pudo convertir, -1 si hubo error
 *
 */
int emp_getId(Entregas* this,int* id)
{
    int ret = -1;
    if(this!=NULL)
    {
        *id = this->id;
        ret = 0;
    }
    return ret;
}


/** \brief recibe una cadena y lo guarda en el elemento nombre
 *
 * \param la lista de empleados
 * \param la cadena
 * \return 0 si se pudo convertir, -1 si hubo error
 *
 */
int emp_setTipo(Entregas* this, char* tipo)
{
    int ret=-1;
    if (this!=NULL && strlen(tipo)>0)
        {
            strncpy(this->tipo, tipo, sizeof(this->tipo));
            ret=0;
        }
    return ret;
}

/** \brief toma una cadena y la muestra
 *
 * \param lista de empleados
 * \param cadena nombre
 * \return 0 si se pudo convertir, -1 si hubo error
 *
 */
int emp_getTipo(Entregas* this,char* tipo)
{
    int ret= -1;
    if(this!=NULL)//VALIDAR tipo
    {
        strcpy ( tipo, this->tipo);
        ret = 0;
    }
    return ret;
}

/** \brief  recibe la cadena 'horas trabajadas' y la valida
 *
 * \param lista de empleados
 * \param acadena 'horas trabajadas'
 * \return  0 si se pudo convertir, -1 si hubo error
 *
 */
int emp_setStrCant(Entregas* this, char* strCant)
{
     int ret=-1;
     int bufferCant;
    if(this!=NULL && esNumerico(strCant))
    {
        bufferCant = atoi(strCant);
        if(!emp_setCant(this, bufferCant))
        {
          ret=0;
        }
    }
    return ret;
}

/** \brief recibe una cadena y la guarda en un campo de la estructura
 *
 * \param lista de empleados
 * \param numero entero
 * \return 0 si se pudo convertir, -1 si hubo error
 *
 */
int emp_setCant(Entregas* this,int cant)
{
    int ret=-1;
    if(this!=NULL)
       {
           if(cant> 0)
         {
            this-> cant= cant;
            ret=0;
         }
    }
    return ret;
}

/** \brief toma la el entero del campo
 *
 * \param lista de empleados
 * \param numero entero
 * \return  0 si se pudo convertir, -1 si hubo error
 *
 */
int emp_getCant(Entregas* this,int* cant)
{
    int ret = -1;
    if(this!=NULL)
    {
        *cant = this->cant;
        ret= 0;
    }
    return ret;
}

/** \brief valida la cadena y la guardar
 *
 * \param lista de empleados
 * \param cadena
 * \return  0 si se pudo convertir, -1 si hubo error
 *
 */
int emp_setStrPeso(Entregas* this, char* pPeso)
{
    int ret=-1;
    float bufferPeso;
    if(this!=NULL && esNumericoFlotante(pPeso))
    {
        bufferPeso = atof(pPeso);
        if(!emp_setPeso(this, bufferPeso))
        {
            ret= 0;
        }
    }
    return ret;
}

/** \brief guarda la cadena en el campo de la estructura
 *
 * \param lista de empleados
 * \param numero entero
 * \return 0 si se pudo convertir, -1 si hubo error
 *
 */
int emp_setPeso(Entregas* this,float peso)
{
    int ret=-1;
    if(this!=NULL)
    {
        if(peso>.01 || peso<99999)
        {
            this-> peso= peso;
            ret=0;
        }
    }
    return ret;
}

/** \brief toma el valor del campo
 *
 * \param lista de empleados
 * \param puntero al valor
 * \return 0 si se pudo convertir, -1 si hubo error
 *
 */
int emp_getPeso(Entregas* this,float* peso)
{
   int ret = -1;
    if(this!=NULL)
    {
        *peso = this->peso;
        ret = 0;
    }
    return ret;

}

/** \brief imprime un empleado
 *
 * \param lista de empleados
 * \return -
 *
 */
void emp_printEntregas(Entregas* this)
{
    int bufferId;
    char bufferTipo[4096];
    int bufferCant;
    float bufferPeso;

    if(this!=NULL)
    {
        if((!emp_getId(this, &bufferId))&&
            (!emp_getTipo(this, bufferTipo))&&
                (!emp_getCant(this, &bufferCant))&&
                    (!emp_getPeso(this, &bufferPeso)))
        {
             printf("%5d  %10s %10d  %.2f\n",bufferId, bufferTipo,bufferCant, bufferPeso);
        }
    }

}

/** \brief ordena por id
 *
 * \param void a empleado
 * \param void a empleado
 * \return  0 si se pudo convertir, -1 si hubo error
 *
 */
int emp_sortById(void* empA, void* empB)
{
    int ret=0;
    int idUno;
    int idDos;

    emp_getId(empA, &idUno);
    emp_getId(empB, &idDos);

    if(empA!=NULL && empB!=NULL)
    {
        if(idUno > idDos)
        {
             ret = 1;
        }
        else if(idUno < idDos)
        {
            ret = -1;
        }
    }
    return ret;
}

/** \brief ordena por nombre
 *
 * \param void a empleado
 * \param void a empleado
 * \return  0 si se pudo convertir, -1 si hubo error
 *
 */
/*int emp_sortByTipo(void* empA, void* empB)
{
    int ret=0;
    char Uno[51];
    char Dos[51];

    emp_getTipo(empA, Uno);
    emp_getTipo(empB, Dos);

    if(empA!=NULL && empB!=NULL)
    {
        if(strcmp(nameUno, nameDos) > 0)
        {
             ret = 1;
        }
        else if(strcmp(nameUno, nameDos) < 0)
        {
            ret = -1;
        }
    }
    return ret;
}*/

/** \brief ordena por horas trabajadas
 *
 * \param void a empleado
 * \param void a empleado
 * \return  0 si se pudo convertir, -1 si hubo error
 *
 */
/*int emp_sortByWorkHours(void* empA, void* empB)
{
    int ret=0;
    int hoursUno;
    int hoursDos;

    emp_getWorkingHours(empA, &hoursUno);
    emp_getWorkingHours(empB, &hoursDos);

    if(empA!=NULL && empB!=NULL)
    {
        if(hoursUno > hoursDos)
        {
             ret = 1;
        }
        else if(hoursUno < hoursDos)
        {
            ret = -1;
        }
    }
    return ret;
}*/
/** \brief ordena por salario
 *
 * \param void a empleado
 * \param void a empleado
 * \return  0 si se pudo convertir, -1 si hubo error
 *
 */
/*int emp_sortBySalary(void* empA, void* empB)
{
    int ret=0;
    int salaryUno;
    int salaryDos;

    emp_getSalary(empA, &salaryUno);
    emp_getSalary(empB, &salaryDos);

    if(empA!=NULL && empB!=NULL)
    {
        if(salaryUno > salaryDos)
        {
             ret = 1;
        }
        else if(salaryUno < salaryDos)
        {
            ret = -1;
        }
    }
    return ret;
}
*/

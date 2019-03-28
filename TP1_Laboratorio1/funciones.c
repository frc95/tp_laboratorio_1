#include <stdio.h>
#include "funciones.h"



float suma(float numeroUno,float numeroDos)
{
    float resultadoSuma;
    resultadoSuma=numeroUno+numeroDos;
    return resultadoSuma;
}

float resta(float numeroUno,float numeroDos)
{
    float resultadoResta;
    resultadoResta=numeroUno-numeroDos;
    return resultadoResta;
}

float division(float numeroUno,float numeroDos)
{
    float resultadoDivi;
    resultadoDivi=numeroUno/numeroDos;
    return resultadoDivi;
}

float multiplicar(float numeroUno,float numeroDos)
{
    float resultadoMulti;
    resultadoMulti=numeroUno*numeroDos;
    return resultadoMulti;
}

int factorial(int numero)
{
    int resultadoFac=1;
    int i;
    for(i=1;i<=numero;i++)
    {
        resultadoFac=resultadoFac*i;
    }
    return resultadoFac;
}

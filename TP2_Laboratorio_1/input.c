#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "input.h"



/** \brief Pide un numero entero al usuario verificando si es mayor al minimo
 *
 * \param min Limite minimo a validar
 * \param valor Se carga el numero ingresado
 * \param intentos Es la cantidad de intentos que tiene el usuario en caso de equivocarse
 * \param mensaje Es el mensaje a ser mostrado
 * \param msjError Es el mensaje a ser mostrado en caso de error
 * \return todoOk Si es igual a 1 el numero es mayor al minimo
 *
 */

int pedirInt(int min, int* valor, int intentos,  char* mensaje, char* msjError){

char auxEntero[20];
int entero;
int todoOk = 0;
int cont = 0;

printf("%s mayor que %d : ", mensaje,  min);
scanf("%s", auxEntero);

    while( (esNumerico(auxEntero)==0) || (((entero=atoi(auxEntero)) <= min ) && cont < intentos  ))
    {

        cont++;
        printf("%s mayor que %d \n", msjError, min);
        /*if(!esNumerico(auxEntero))
        {
            printf("SOLO NUMEROS\n");

        }*/

        if( cont == intentos)
        {
            break;
        }
        //printf("%s entre %d y %d ", msjError, min, max);
        scanf("%s", auxEntero);

        entero=atoi(auxEntero);


    }

     if(cont < intentos)
    {

        *valor = entero;
        todoOk = 1;

    }

return todoOk;
}

/** \brief Pide un numero flotante al usuario verificando si es mayor al minimo
 *
 * \param min Limite minimo a validar
 * \param valor Se carga el numero ingresado
 * \param intentos Es la cantidad de intentos que tiene el usuario en caso de equivocarse
 * \param mensaje Es el mensaje a ser mostrado
 * \param msjError Es el mensaje a ser mostrado en caso de error
 * \return todoOk Si es igual a 1 el numero es mayor al minimo
 *
 */


int pedirFloat(float min, float* valor, int intentos,  char* mensaje, char* msjError)
{
    float flotante;
    char auxFlotante[20];
    int todoOk = 0;
    int cont = 0;

    printf("%s mayor que %.2f: ", mensaje,  min);
    scanf("%s", auxFlotante);

    while( (esNumericoFlotante(auxFlotante)==0) || (((flotante=atof(auxFlotante)) <= min  && cont < intentos  )  ))
    {

            cont++;
            printf("%s mayor que %.2f \n", msjError, min);
            if( cont == intentos){
                break;
            }
            scanf("%s", auxFlotante);

            flotante=atof(auxFlotante);
    }

    if(cont < intentos)
    {

    *valor = flotante;
     todoOk = 1;

    }

    return todoOk;
}

/** \brief Pide un caracter al usuario verificando si es igual a caracterA o caracterB.
 *
 * \param caracterA Es el caracter a validar
 * \param caracterB Es el caracter a validar
 * \param letra Se carga el caracter ingresado
 * \param intentos Es la cantidad de intentos que tiene el usuario en caso de equivocarse
 * \param mensaje Es el mensaje a ser mostrado
 * \param msjError Es el mensaje a ser mostrado en caso de error
 * \return todoOk Si es igual a 1 el caracter ingresado es igual a caracterA o caracterB.
 *
 */

int pedirChar(char caracterA, char caracterB, char* letra, int intentos,  char* mensaje, char* msjError)
{
    char caracter;
    int todoOk = 0;
    int cont = 0;

    printf("%s solo %c o %c: ", mensaje,  caracterA, caracterB);
    fflush(stdin);
    scanf("%c", &caracter);

    while( ( caracter!=caracterA && caracter!=caracterB ) && cont < intentos  ){

            cont++;

            if( cont == intentos){
                break;
            }
            printf("%s solo %c y %c: ", msjError, caracterA, caracterB);
            fflush(stdin);
            scanf("%c", &caracter);
    }

if(cont < intentos){

    *letra = caracter;
     todoOk = 1;

}

return todoOk;

}

/** \brief Pide una cadena de caracteres al usuario verificando si la cantidad de caracteres es menor al limite
           y si contiene solo letras.
 *
 * \param limite Es el limite a validar
 * \param cadena Se carga el array ingresado
 * \param intentos Es la cantidad de intentos que tiene el usuario en caso de equivocarse
 * \param mensaje Es el mensaje a ser mostrado
 * \param msjError Es el mensaje a ser mostrado en caso de error
 * \return todoOk Si es igual a 1 la cantidad de caracteres es menor al limite y contiene solo letras.
 *
 */

int pedirStringChar(int limite, char cadena[], int intentos,  char* mensaje, char* msjError)
{
    char string[limite];
    int todoOk = 0;
    int cont = 0;

    printf("%s de %d o menos caracteres: ", mensaje, limite);
    fflush(stdin);
    gets(string);
    //scanf("%s", string);


    while( ( soloLetras(string)==0 || strlen(string)>limite ) && cont < intentos  )
    {
            printf("%s de %d caracteres \n", msjError, limite);

            cont++;
            if( cont == intentos)
            {

                break;
            }
            //printf("%s de %d caracteres: ", msjError, limite);
            fflush(stdin);
            gets(string);
            //scanf("%s", string);
    }

if(cont < intentos){

     strcpy(cadena,string);

     todoOk = 1;

}

return todoOk;


}
/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */

int esNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */

int soloLetras(char cadena[])
{
    int i=0;
    while(cadena[i]!='\0')
    {
        if((cadena[i]<'a' || cadena[i]>'z') && (cadena[i]<'A' || cadena[i]>'Z') && (cadena[i]!=' '))
        {
            return 0;
        }
        i++;
    }
    return 1;
}

/**
 * \brief Verifica si el valor recibido es numérico aceptando flotantes
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */

int esNumericoFlotante(char str[])
{
   int i=0;
   int cantidadPuntos=0;
   while(str[i] != '\0')
   {
       if (str[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 *
 */
int esAlfaNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
           return 0;
       i++;
   }
   return 1;
}


/**
 * \brief Verifica si el valor recibido contiene solo números, + y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion.
 *
 */
int esTelefono(char str[])
{
   int i=0;
   int contadorGuiones=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
           return 0;
       if(str[i] == '-')
            contadorGuiones++;
       i++;
   }
   if(contadorGuiones==1) // debe tener un guion
        return 1;

    return 0;
}



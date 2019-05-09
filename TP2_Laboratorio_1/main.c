#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "input.h"
#define EMP 10
int main()
{
    char seguir = 's';
    char confirma;
    int verificar;

    int idEmpleado=0;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;

    int orden;

    int id;


    Employee listaEmployees[EMP];/*={

         {1,"franco","godoy",1000,1,0},
         {2,"juan","acosta",2000,2,0},
         {3,"ramon","caballero",3000,3,0},
         {4,"alejandra","godoy",4000,2,0},
         {5,"luis","ruiz",1500,1,0},
         {6,"marco","benitez",10500,5,0},
         {7,"jose","suarez",9000,6,0},
         {8,"jorge","benitez",11500,6,0},
         {9,"lara","gimenez",9500,3,0},
         {10,"mirian","benitez",15000,4,0},

    };*/

    initEmployees(listaEmployees, EMP);



    do
    {

        switch(menu())
        {

        case 1:
            if(pedirStringChar(51,nombre,1,"Ingrese el nombre","Solo letras"))
            if(pedirStringChar(51,apellido,1,"Ingrese el apellido","Solo letras"))
            if(pedirFloat(0,&salario,1,"Ingrese el salario","Solo numeros"))
            if(pedirInt(0,&sector,1,"Ingrese el id sector","Solo numeros"))
            {
                idEmpleado++;
                verificar=addEmployee(listaEmployees, EMP, idEmpleado, nombre, apellido, salario, sector);
                if(verificar==0)
                {
                    printf("El empleado fue dado de alta\n");
                }
                else
                {
                    idEmpleado--;
                    printf("No hay lugar en el sistema\n");
                }
            }
            system("pause");
            break;

        case 2:
            if(pedirInt(0, &id, 1, "Ingrese la id", "Solo numeros"))
            {
                verificar=modifyEmployee(listaEmployees, EMP, id);
                if(verificar==0)
                {
                    printf("\nEl dato del empleado fue modificado\n");
                }
                else if(verificar==1)
                {
                    printf("\nEl dato no fue modificado\n");
                }
                else
                {
                    printf("El empleado no existe\n");
                }
            }
            system("pause");
            break;

        case 3:
            if(pedirInt(0, &id, 1, "Ingrese la id", "Solo numeros"))
            {
                verificar=removeEmployee(listaEmployees, EMP, id);
                if(verificar==0)
                {

                    printf("\nEl empleado fue dado de baja\n");
                }
                else if(verificar==1)
                {
                    printf("\nEl empleado no fue dado de baja\n");
                }
                else
                {
                    printf("El empleado no existe\n");
                }
            }
            system("pause");
            break;

        case 4:
            printf("Ingrese el orden\n");
            printf("0-Ordena empleados por apellido y sector de manera desendente\n");
            printf("1-Ordena empleados por apellido y sector de manera ascendente\n");
            scanf("%d",&orden);

            if(orden==0 || orden==1)
            {
                verificar=sortEmployees(listaEmployees, EMP, orden);
                if(verificar)
                {
                    printf("Fue ordenado de manera ascendente\n");
                    verificar=printEmployees(listaEmployees, EMP);
                    if(verificar==0)
                    {
                        printf("\n\nNo hay empleados que mostrar\n");
                    }
                }
                else
                {
                    printf("Fue ordenado de manera desendente\n");
                    verificar=printEmployees(listaEmployees, EMP);
                    if(verificar==0)
                    {
                        printf("\n\nNo hay empleados que mostrar\n");
                    }
                }
            }
            else
            {
                printf("Opcion Incorrecta\n");
            }

            system("pause");
            break;

        case 5:
            printf("\nConfirma salida s/n?: ");
            fflush(stdin);
            confirma = getche();

            if( tolower(confirma) == 's')
            {
                seguir = 'n';
            }
            break;

        default:
            printf("\n Opcion invalida\n\n");
            system("pause");
            system("break");
        }
    }
    while(seguir == 's');

    return 0;
}


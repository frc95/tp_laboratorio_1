#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    int tam;
    int i;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
        system("cls");
        printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
        printf("2. Cargar los datos de los empleados desde el archivo datos.bin (modo binario).\n");
        printf("3. Alta de empleado\n");
        printf("4. Modificar datos de empleado\n");
        printf("5. Baja de empleado\n");
        printf("6. Listar empleados\n");
        printf("7. Ordenar empleados\n");
        printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
        printf("9. Guardar los datos de los empleados en el archivo datos.bin (modo binario).\n");
        printf("10. Salir\n");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                if(controller_loadFromText("data.csv",listaEmpleados))
                {
                    printf("Los empleados fueron cargados (texto)\n");
                }
                else
                {
                    printf("Error al cargar los empleados\n");
                }
                system("pause");

                break;
            case 2:

                if(controller_loadFromBinary("datos.bin",listaEmpleados))
                {
                    printf("Los empleados fueron cargados (binario)\n");
                }
                else
                {
                    printf("Error al cargar los empleados\n");
                }
                system("pause");
                break;

            case 3:
                if(controller_addEmployee(listaEmpleados))
                {
                    printf("El empleado fue dado de alta\n");
                }
                else
                {
                    printf("Error al dar de alta\n");
                }

                system("pause");
                break;

            case 4:

                if(controller_editEmployee(listaEmpleados))
                {
                    printf("Los datos del empleado fue modificado\n");
                }
                else
                {
                    printf("El empleado no fue modificado\n");
                }

                system("pause");
                break;

            case 5:

                if(controller_removeEmployee(listaEmpleados))
                {
                    printf("El empleado fue dado de baja\n");
                }
                else
                {
                    printf("El empleado no fue dado de baja\n");
                }

                system("pause");
                break;

            case 6:
                if(controller_ListEmployee(listaEmpleados))
                {
                    printf("\nTodos los empleados de alta\n");
                }
                else
                {
                    printf("No hay empleado\n");
                }
                system("pause");
                break;

            case 7:
                if(controller_sortEmployee(listaEmpleados))
                {
                    printf("\nTodos los empleados fueron ordenados alfabeticamente\n");
                }
                else
                {
                    printf("No hay empleados para ordenar\n");
                }
                system("pause");
                break;

            case 8:
                if(controller_saveAsText("data.csv",listaEmpleados))
                {
                    printf("Los empleados fueron guardados (texto)\n");
                }
                else
                {
                    printf("Error al guardar los empleados\n");
                }
                system("pause");
                break;

            case 9:
                if(controller_saveAsBinary("datos.bin",listaEmpleados))
                {
                    printf("\nLos datos fueron guardados en binario\n");
                }
                else
                {
                    printf("Hubo un error en guardar los datos\n");
                }
                system("pause");
                break;


            case 10:
                printf("\nGracias por utilizar el programa \n");
                system("pause");
                break;

            default:
                printf("Opcion invalida\n");
                system("pause");
                break;

        }
    }while(option != 10);


    tam=ll_len(listaEmpleados);
    for(i=0;i<tam;i++)
    {
        free(ll_get(listaEmpleados,i));
    }
    ll_deleteLinkedList(listaEmpleados);

    return 0;
}

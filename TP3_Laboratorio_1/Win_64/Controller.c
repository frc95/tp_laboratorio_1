#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int todoOK 1.Esta todo bien
                      0.Error
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    FILE* f;

    if((f=fopen(path,"r")) == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        system("pause");
    }
    else
    {
        todoOk=parser_EmployeeFromText(f,pArrayListEmployee);
    }

    fclose(f);
    return todoOk;
}

/** \brief Carga los datos de los empleados desde el archivo datos.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int todoOK 1.Esta todo bien
                      0.Error
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    FILE* f;

    if((f=fopen(path,"rb")) == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        system("pause");

    }
    else
    {
        todoOk=parser_EmployeeFromBinary(f,pArrayListEmployee);
    }
    fclose(f);

    return todoOk;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int todoOK 1.Esta todo bien
                      0.Error
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int id;
    char nombre[20];
    int horas;
    int sueldo;


    int todoOK=0;

    Employee* empleado=NULL;
    empleado=employee_new();
    printf("Ingrese la id: ");
    scanf("%d",&id);
    if(employee_setId(empleado,id))
    {
        printf("Ingrese el nombre: ");
        fflush(stdin);
        scanf("%s",nombre);
        if(employee_setNombre(empleado,nombre))
        {
                printf("Ingrese las horas trabajadas: ");
                scanf("%d",&horas);
                if(employee_setHorasTrabajadas(empleado,horas))
                {
                    printf("Ingrese el sueldo: ");
                    scanf("%d",&sueldo);
                    if(employee_setSueldo(empleado,sueldo))
                    {
                        ll_add(pArrayListEmployee,empleado);
                        todoOK=1;
                    }
                    else
                    {
                        printf("Sueldo invalido\n");
                    }

                }
                else
                {
                    printf("Horas de trabajo invalidas\n");
                }
        }
        else
        {
            printf("nombre invalido\n");
        }
    }
    else
    {

        printf("ID invalido\n");


    }

    return todoOK;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int todoOK 1.Esta todo bien
                      0.Error
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int todoOK=0;
    int idAux;
    int tam;
    int i;
    Employee* empleado=NULL;
    int opcion;
    char confirma;

    char nombre[20];
    int horas;
    int sueldo;

    printf("Ingrese el ID para modificar: \n");
    scanf("%d",&idAux);

    tam=ll_len(pArrayListEmployee);

    for(i=0;i<tam;i++)
    {
            empleado=ll_get(pArrayListEmployee,i);
            if( (empleado->id == idAux)  && (empleado->id > 0) )
            {

                printf("Se encontro un empleado con ID %d\n",idAux);
                printf("ID:%2d  Nombre:%10s  Horas Trabajadas:%3d  Sueldo:%6d\n",empleado->id, empleado->nombre, empleado->horasTrabajadas, empleado->sueldo);
                printf("\nSeguro que quiere modificar s/n?: ");
                fflush(stdin);
                confirma = getche();
                if( tolower(confirma) == 's')
                {
                    system("cls");
                    printf("1-NOMBRE\n");
                    printf("2-HORAS TRABAJADAS\n");
                    printf("3-SUELDO\n");
                    scanf("%d",&opcion);
                    switch(opcion)
                    {
                    case 1:
                        printf("Ingrese el nombre: ");
                        fflush(stdin);
                        scanf("%s",nombre);
                        if(employee_setNombre(empleado,nombre))
                        {
                            todoOK=1;
                        }

                        system("pause");

                        break;
                    case 2:
                        printf("Ingrese las horas trabajadas: ");
                        scanf("%d",&horas);

                        if(employee_setHorasTrabajadas(empleado,horas))
                        {
                            todoOK=1;
                        }

                        system("pause");

                        break;
                    case 3:
                        printf("Ingrese el sueldo: ");
                        scanf("%d",&sueldo);

                        if(employee_setSueldo(empleado,sueldo))
                        {
                            todoOK=1;
                        }

                        system("pause");

                        break;
                    }

                }

            }
    }

    return todoOK;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int todoOK 1.Esta todo bien
                      0.Error
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int todoOK=0;
    int idAux;
    int tam;
    int i;
    char confirma;
    Employee* empleado=NULL;

    printf("Ingrese el ID para dar de baja: \n");
    scanf("%d",&idAux);

    tam=ll_len(pArrayListEmployee);

    for(i=0;i<tam;i++)
    {
            empleado=ll_get(pArrayListEmployee,i);
            if( (empleado->id == idAux)  && (empleado->id > 0) )
            {
                printf("Se encontro un empleado con ID %d\n",idAux);
                printf("ID:%2d  Nombre:%10s  Horas Trabajadas:%3d  Sueldo:%6d\n",empleado->id, empleado->nombre, empleado->horasTrabajadas, empleado->sueldo);
                printf("\nSeguro que quiere modificar s/n?: ");
                fflush(stdin);
                confirma = getche();
                if( tolower(confirma) == 's')
                {
                    ll_remove(pArrayListEmployee,i);
                    todoOK=1;
                    break;
                }
                break;
            }
    }



    return todoOK;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int todoOK 1.Esta todo bien
                      0.Error
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int tam;
    int i;
    int todoOK=0;


    Employee* empleado=NULL;
    tam=ll_len(pArrayListEmployee);


    if(tam>0)
    {
        for(i=0;i<tam;i++)
        {
            empleado=ll_get(pArrayListEmployee,i);
            if( empleado->id > 0 )
            {

                printf("ID:%2d  Nombre:%10s  Horas Trabajadas:%3d  Sueldo:%6d\n",empleado->id, empleado->nombre, empleado->horasTrabajadas, empleado->sueldo);
            }
        }
        todoOK=1;
    }

    return todoOK;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int todoOK 1.Esta todo bien
                      0.Error
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int todoOK=0;
    int i;
    int j;
    int tam;

    Employee* empleado=NULL;
    Employee* empleadoJ=NULL;

    tam=ll_len(pArrayListEmployee);

    if(tam>0)
    {

        for( i=0 ; i<tam-1 ; i++ )
        {
            for( j=i+1 ; j<tam ; j++)
            {
                empleado=ll_get(pArrayListEmployee,i);
                empleadoJ=ll_get(pArrayListEmployee,j);
                if( (strcmp(empleado->nombre,empleadoJ->nombre) > 0))
                {
                    ll_set(pArrayListEmployee,i,empleadoJ);
                    ll_set(pArrayListEmployee,j,empleado);

                }
            }
        }
        todoOK=1;

    }



    return todoOK;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int todoOK 1.Esta todo bien
                      0.Error
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    FILE* f;
    Employee* empleado=NULL;
    int tam;
    int i;

    if((f=fopen(path,"w")) == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        system("pause");
    }
    else
    {
        tam=ll_len(pArrayListEmployee);
        fprintf(f,"id,nombre,horasTrabajadas,sueldo\n");


        for(i=0; i < tam; i++)
        {
            empleado=ll_get(pArrayListEmployee,i);
            if(empleado->id > 0)
            {
                fprintf(f,"%d,%s,%d,%d\n", empleado->id, empleado->nombre, empleado->horasTrabajadas, empleado->sueldo);

            }

        }
        todoOk=1;
    }

    fclose(f);
    return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo datos.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int todoOK 1.Esta todo bien
                      0.Error
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    Employee* empleado=NULL;
    FILE* f;

    int tam;
    int i;


    tam=ll_len(pArrayListEmployee);
    if(tam>0)
    {
        if((f=fopen(path,"wb")) == NULL)
        {
            printf("No se pudo abrir el archivo\n");
            system("pause");

        }
        else
        {

            rewind(f);
            for(i=0; i < tam; i++)
            {
                empleado=ll_get(pArrayListEmployee,i);
                if(empleado->id > 0)
                {
                    fwrite(empleado,sizeof(Employee), 1, f);
                }

            }
            todoOk=1;
        }
    }


    fclose(f);

    return todoOk;
}




#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "input.h"


/**
 * \brief To indicate that all position in the array are empty,
 *         this function put the flag (isEmpty) in TRUE in all
 *         position of the array
 * \param list Pointer to array of employees
 * \param len Array length
 * \return void
 *
 */

void initEmployees(Employee* list, int len)
{
    int i;
    for(i=0; i < len; i++)
    {
        list[i].isEmpty = 1;
    }


}

/**
 * \brief It's a menu for an ABM
 * \return opcion It will be the value to be compared with some constant.
 *
 */

int menu()
{
    int opcion;

    system("cls");
    printf("  *** ABM EMPLEADO ***\n\n");
    printf("1- ALTA EMPLEADO\n");
    printf("2- MODIFICAR EMPLEADO\n");
    printf("3- BAJA EMPLEADO\n");
    printf("4- INFORMAR\n");
    printf("5- SALIR\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}





/**
 * \brief Find the first empty place
 * \param list It is the array of employees in which to search.
 * \param len Indicates the length of the array of employees.
 * \return Return the position of the empty index or (-1) if [Invalid length or NULL pointer received or there is no place in the system]
 *
 */

int findEmpty(Employee* list, int len){

    int index = -1;
    int i;
     for(i=0; i < len; i++)
    {
        if(list[i].isEmpty == 1){
            index = i;
            break;
        }
    }

    return index;
}

/**
 * \brief find an Employee by Id en returns the index position in array.
 * \param list It is the array of employees in which to search.
 * \param len Indicates the length of the array of employees.
 * \param id It is the value that is sought
 * \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 *
 */

int findEmployeeById(Employee* list, int len, int id){

    int index = -1;
    int i;
    for(i=0; i < len; i++)
    {
        if(list[i].isEmpty == 0 && list[i].id == id){
            index = i;
            break;
        }
    }

    return index;
}




/** \brief add in a existing list of employees the values received as parameters in the first empty position
* \param list It is the array of employees in which to search.
* \param len Indicates the length of the array of employees.
* \param id It is the id of the employee to load.
* \param name[] It is the employee's name to load
* \param lastName[] It is the employee's last name to load
* \param salary It is the employee's salary to load
* \param sector It is the employee's sector code to load.
* \return int Return index (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*/

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    int index;


    index = findEmpty(list, len);

    if(index!=-1)
    {

            list[index].id=id;
            strcpy(list[index].name, name);
            strcpy(list[index].lastName, lastName);
            list[index].salary=salary;
            list[index].sector=sector;
            list[index].isEmpty = 0;
            index=0;



    }
    return index;
}




/**
 * \brief Remove a Employee by Id (put isEmpty Flag in 1)
 * \param list It is the array of employees in which to search.
 * \param len Indicates the length of the array of employees.
 * \param id It is the value that is sought
 * \return int Return esta (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
 *         (1) if the user canceled the operation.
 */

int removeEmployee(Employee* list, int len, int id)
{
    char confirma;
    int esta;

    esta=findEmployeeById(list,len,id);

    if(esta!=-1)
    {
        printf("Existe un empleado de id %d en el sistema\n", id);
        printf("    ID     NOMBRE   APELLIDO  SALARIO  SECTOR\n");
        printEmployee(list[esta]);

        printf("\n Seguro que quiere dar de baja s/n?: ");
        fflush(stdin);
        confirma = getche();

        if( tolower(confirma) == 's')
        {
            list[esta].isEmpty=1;
            esta=0;
        }
        else
        {
            esta=1;
        }


    }

    return esta;

}

/**
 * \brief modify a Employee by Id (put isEmpty Flag in 1)
 * \param list It is the array of employees in which to search.
 * \param len Indicates the length of the array of employees.
 * \param id It is the value that is sought
 * \return int Return esta (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
 *         (1) if the user canceled the operation or had an error in data entry.
 */

int modifyEmployee(Employee* list, int len, int id)
{
    char confirma;
    int esta;
    int opcion;

    esta=findEmployeeById(list,len,id);

    if(esta!=-1)
    {
        printf("Existe un empleado de id %d en el sistema\n", id);
        printf("    ID     NOMBRE   APELLIDO  SALARIO  SECTOR\n");
        printEmployee(list[esta]);

        printf("\n Seguro que quiere modificar s/n?: ");
        fflush(stdin);
        confirma = getche();

        if( tolower(confirma) == 's')
        {
            system("cls");
            printf("  *** MODIFICAR EMPLEADO ***\n\n");
            printf("1- MODIFICAR NOMBRE\n");
            printf("2- MODIFICAR APELLIDO\n");
            printf("3- MODIFICAR SALARIO\n");
            printf("4- MODIFICAR SECTOR\n");
            printf("Ingrese opcion: ");
            scanf("%d", &opcion);
            switch(opcion)
            {
            case 1:
                if(pedirStringChar(51,list[esta].name,1,"Ingrese el nombre","Solo letras"))
                {
                    esta=0;
                }
                else
                {
                    esta=1;
                }
                system("pause");
                break;
            case 2:
                if(pedirStringChar(51,list[esta].lastName,1,"Ingrese el apellido","Solo letras"))
                {
                    esta=0;
                }
                else
                {
                    esta=1;
                }
                system("pause");
                break;
            case 3:
                if(pedirFloat(0,&list[esta].salary,1,"Ingrese el salario","Solo numeros"))
                {
                    esta=0;
                }
                else
                {
                    esta=1;
                }
                system("pause");
                break;
            case 4:
                if(pedirInt(0,&list[esta].sector,1,"Ingrese el id sector","Solo numeros"))
                {
                    esta=0;
                }
                else
                {
                    esta=1;
                }
                system("pause");
                break;
            default:
                printf("Opcion invalida\n");
                system("pause");
                break;
            }

        }
        else
        {
            esta=1;
        }

    }

    return esta;

}

/**
 * \brief Shows the data of an employee that is in the system
 * \param emp It is the structure of employees to use
 * \return void
 *
 */

void printEmployee(Employee emp)
{

    printf("  %2d  %10s  %10s  %8.2f  %2d\n", emp.id, emp.name, emp.lastName, emp.salary, emp.sector);

}

/** \brief print the content of employees array and shows the total and average salaries,
*          and how many employees exceed the average salary.
* \param list It is the array of employees in which to search.
* \param length Indicates the length of the array of employees.
* \return contador If (0). Verify that there is no employee in the system.
*
*/


int printEmployees(Employee* list, int length)
{
    int contador = 0;
    int i;
    float total=0;
    float promedio=0;
    int contadorQueSuperaElpromedio=0;
    printf("  ID       NOMBRE   APELLIDO  SALARIO  SECTOR\n");
    for( i=0; i < length; i++){
        if(list[i].isEmpty == 0){
            printEmployee(list[i]);
            contador++;
            total=list[i].salary+total;

        }
    }
    promedio=total/contador;
    if(total==0 && contador==0)
    {
        promedio=0;
    }
    for(i=0; i<length ;i++)
    {
        if(list[i].isEmpty == 0 && list[i].salary>promedio)
        {
            contadorQueSuperaElpromedio++;
        }
    }
    printf("\n\nEl total de los salarios es: %.2f\n",total);
    printf("\n\nEl promedio de los salarios es: %.2f\n",promedio);
    printf("\n\nLa cantidad de empleados que superan el salario promedio es: %d\n",contadorQueSuperaElpromedio);
    return contador;
}

/** \brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order
*
* \param list It is the array of employees in which to search.
* \param len Indicates the length of the array of employees.
* \param order int [1] indicate UP - [0] indicate DOWN
* \return verificarOrden (1) if it was sorted in ascending order. - (0) if it was sorted in descending order.
*
*/


int sortEmployees(Employee* list, int len, int order)
{
    int i;
    int j;
    int verificarOrden;
    Employee aux;

    if(order==1)
    {
        for(i=0;i<len-1;i++)
        {
            for(j=i+1;j<len;j++)
            {
                if(strcmp(list[i].lastName,list[j].lastName)>0)
                {
                    aux=list[i];
                    list[i]=list[j];
                    list[j]=aux;
                }
                else if(strcmp(list[i].lastName,list[j].lastName)==0 && list[i].sector>list[j].sector)
                {
                    aux=list[i];
                    list[i]=list[j];
                    list[j]=aux;
                }
            }
        }
        verificarOrden=1;
    }
    else
    {
        for(i=0;i<len-1;i++)
        {
            for(j=i+1;j<len;j++)
            {
                if(strcmp(list[i].lastName,list[j].lastName)<0)
                {
                    aux=list[i];
                    list[i]=list[j];
                    list[j]=aux;
                }
                else if(strcmp(list[i].lastName,list[j].lastName)==0 && list[i].sector<list[j].sector)
                {
                    aux=list[i];
                    list[i]=list[j];
                    list[j]=aux;
                }
            }
        }
        verificarOrden=0;

    }


    return verificarOrden;
}


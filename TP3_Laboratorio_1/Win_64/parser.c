#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int todoOK 1.Esta todo bien
                      0.Error
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    Employee* nuevoEmpleado=NULL;
    char buffer[4][20];
    int cant;

    fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
    while( !feof(pFile) )
    {
        cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
        if( cant < 4)
        {
            todoOk=0;
            break;
        }
        nuevoEmpleado=employee_newParametros( buffer[0], buffer[1],buffer[2],buffer[3]);
        ll_add(pArrayListEmployee,nuevoEmpleado);
        todoOk=1;
    }


    return todoOk;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo datos.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int todoOK 1.Esta todo bien
                      0.Error
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    Employee* nuevoEmpleado=NULL;
    int cant;
    while( !feof(pFile) )
    {
        nuevoEmpleado=employee_new();
        if(nuevoEmpleado == NULL)
        {
            printf("Error al pedir memoria\n");
            system("pause");
            todoOk=0;
            break;
        }
        cant = fread( nuevoEmpleado , sizeof(Employee), 1, pFile);
        if( cant < 1)
        {

            break;
        }
        ll_add(pArrayListEmployee,nuevoEmpleado);
        todoOk=1;
    }

    return todoOk;
}

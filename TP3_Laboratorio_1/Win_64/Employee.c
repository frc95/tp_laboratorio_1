#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "input.h"

/** \brief Crea y retorna un empleado. Inicializando todos sus campos vacios
 *

 * \return emp
 *
 */


Employee* employee_new()
{
    Employee* emp = (Employee*)malloc( sizeof(Employee));

    if(emp != NULL)
    {
        emp->id = 0;
        strcpy(emp->nombre, "");
        emp->horasTrabajadas = 0;
        emp->sueldo = 0;

    }
    return emp;
}

/** \brief Crea y retorna un empleado.Inicializando todos sus campos de acuerdo a los datos que recibe como parametro
           Puede usarse para parsear un archivo de texto.
 *
 * \param char* idStr
 * \param char* nombreStr
 * \param char* horasTrabajadasStr
 * \param char* sueldo
 * \return emp
 *
 */


Employee* employee_newParametros( char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldo)
{
    Employee* emp = (Employee*)malloc( sizeof(Employee));

    int todoOk=0;


    if(emp != NULL)
    {
        if(employee_setId(emp, atoi(idStr)))
        {
            if(employee_setNombre(emp, nombreStr))
            {
                if(employee_setHorasTrabajadas(emp, atoi(horasTrabajadasStr)))
                {
                    if(employee_setSueldo(emp, atoi(sueldo)))
                    {
                        todoOk=1;
                    }

                }

            }
        }
        if(todoOk==0)
        {
            free(emp);
            emp=NULL;
        }


    }

    return emp;
}

/** \brief Recibe la id, verifica si es mayor que cero y si this no es NULL. Despues se completa el campo id de this
 *
 * \param int id
 * \param Employee* this
 * \return todoOk 1.Esta todo bien
                  0.Error
 *
 */


int employee_setId(Employee* this,int id)
{
    int todoOk=0;



    if( this!=NULL &&  id>0 )
    {

        this -> id= id;
        todoOk=1;
    }

    return todoOk;
}

/** \brief Recibo como punteros id y la estructura Employee verificacndo si son distinto de NULL.
           Si son distinto, el valor de id sera modificado de acuerdo al campo id de this.
 *
 * \param Employee* this
 * \param int* id
 * \return todoOk 1.Esta todo bien
                  0.Error
 *
 */


int employee_getId(Employee* this,int* id)
{
    int todoOk=0;

    if(this != NULL && id != NULL)
    {
        *id= this->id;
        todoOk=1;
    }

    return todoOk;
}

/** \brief Recibe el nombre, verificando si son solo letras y si this no es NULL.
           Despues se completa el campo nombre de this.
 *
 * \param char* nombre
 * \param Employee* this
 * \return todoOk 1.Esta todo bien
                  0.Error
 *
 */

int employee_setNombre(Employee* this,char* nombre)
{
    int todoOk=0;

    if( this!=NULL && soloLetras(nombre))
    {
        strcpy( this->nombre,nombre);
        todoOk=1;
    }

    return todoOk;
}

/** \brief Recibo como punteros el nombre y la estructura Employee verificacndo si son distinto de NULL.
           Si son distinto, el valor de nombre sera modificado de acuerdo al campo nombre de this.
 *
 * \param Employee* this
 * \param char* nombre
 * \return todoOk 1.Esta todo bien
                  0.Error
 *
 */

int employee_getNombre(Employee* this,char* nombre)
{
    int todoOk=0;

    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        todoOk=1;
    }

    return todoOk;
}

/** \brief Recibe las horas trabajadas, verifica si es mayor que cero y si this no es NULL.
           Despues se completa el campo horasTrabajadas de this.
 *
 * \param int horasTrabajadas
 * \param Employee* this
 * \return todoOk 1.Esta todo bien
                  0.Error
 *
 */

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int todoOk=0;

    if( this!=NULL && horasTrabajadas > 0 )
    {
        this -> horasTrabajadas= horasTrabajadas;
        todoOk=1;
    }

    return todoOk;
}

/** \brief Recibo como punteros las horasTrabajadas y la estructura Employee verificacndo si son distinto de NULL.
           Si son distinto, el valor de horasTrabajadas sera modificado de acuerdo al campo horasTrabajadas de this.
 *
 * \param Employee* this
 * \param int* horasTrabajadas
 * \return todoOk 1.Esta todo bien
                  0.Error
 *
 */

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int todoOk=0;

    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas= this->horasTrabajadas;
        todoOk=1;
    }

    return todoOk;
}
/** \brief Recibe el sueldo, verifica si es mayor que cero y si this no es NULL.
           Despues se completa el campo sueldo de this
 *
 * \param int sueldo
 * \param Employee* this
 * \return todoOk 1.Esta todo bien
                  0.Error
 *
 */

int employee_setSueldo(Employee* this,int sueldo) // escribir el sueldo
{
    int todoOk=0;

    if( this!=NULL && sueldo > 0 )
    {
        this -> sueldo= sueldo;
        todoOk=1;
    }

    return todoOk;
}

/** \brief Recibo como punteros el sueldo y la estructura Employee verificacndo si son distinto de NULL.
           Si son distinto, el valor de sueldo sera modificado de acuerdo al campo horasTrabajadas de this.
 *
 * \param Employee* this
 * \param int* sueldo
 * \return todoOk 1.Esta todo bien
                  0.Error
 *
 */

int employee_getSueldo(Employee* this,int* sueldo) //leer el sueldo
{
    int todoOk=0;

    if(this != NULL && sueldo != NULL)
    {
        *sueldo= this->sueldo;
        todoOk=1;
    }

    return todoOk;
}



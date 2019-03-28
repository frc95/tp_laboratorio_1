#include <stdio.h>
#include <stdlib.h>

#include "funciones.h"

#include <conio.h>

int main()
{
    int rta=0;

    float numero1=0;
    float numero2=0;

    float sumar=0;
    float restar=0;
    float dividir=0;
    float multi=0;

    int factorial1;
    int factorial2;

    do{

        system("cls");
        printf("1. Ingresar 1er operando (A=x) %.2f\n"
               "2. Ingresar 2do operando (B=y) %.2f\n"
               "3. Calcular todas las operaciones\n"
               "4. Informar resultados\n"
               "5. Salir\n\n\n",numero1,numero2);
        scanf("%d",&rta);

        switch(rta)
        {
        case 1:

            printf("Ingrese el primer operando: ");
            scanf("%f",&numero1);

            break;
        case 2:

            printf("Ingrese el segundo operando: ");
            scanf("%f",&numero2);

            break;
        case 3:

            sumar=suma(numero1,numero2);
            restar=resta(numero1,numero2);
            dividir=division(numero1,numero2);
            multi=multiplicar(numero1,numero2);

            factorial1=factorial((int)numero1);
            factorial2=factorial((int)numero2);

            break;
        case 4:

            printf("La suma es: %.2f\n",sumar);
            printf("La resta es: %.2f\n",restar);

            if(numero2==0)
            {
                printf("No se puede dividir entre cero\n");
            }
            else
            {
                printf("La division es: %.2f\n",dividir);
            }

            printf("La multiplicacion es: %.2f\n",multi);

            if(numero1<0)
            {
                printf("No se puede sacar el factorial de %d porque es negativo\n",(int)numero1);
            }
            else
            {
                printf("El factorial de %d es: %d\n",(int)numero1,factorial1);
            }

            if(numero2<0)
            {
                printf("No se puede sacar el factorial de %d porque es negativo\n",(int)numero2);
            }
            else
            {
                printf("El factorial de %d es: %d\n",(int)numero2,factorial2);
            }

            getch();
            break;
        case 5:
            printf("Gracias por usar el programa");
            break;
        default:
            printf("No existe esa opcion");
            getch();
            break;

        }



    }while(rta!=5);
    return 0;
}

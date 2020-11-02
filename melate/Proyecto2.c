/********************************************
    Nombre de Alumnos: Mario Ivan Jimenez Alfaro #727740

    Fecha: 7 de Noviembre 2020
    Materia: Estructura de Datos
    Programa: Proyecto 2
    Descripcion: Funciones Auxiliares para Simulador Melate
********************************************/

#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

void verifyOption(int *value, int max, int min)
{
    if(*value > max || *value < min)
    {
        do {
            printf("\tOpci%cn no valida, intente de nuevo: ", 162);
            scanf("%i", &*value);
        } while(*value > max || *value < min);
    }
}

void captureTicket()
{
    printf("\n\tHacer algo");
}

void drawNumbers()
{
    printf("\n\tHacer algo");
}

void ticketReportByCapture()
{
    printf("\n\tHacer algo");
}

void ticketReportByWinner()
{
    printf("\n\tHacer algo");
}

void restartApp()
{
    printf("\n\tHacer algo");
}

void menu()
{
    int opc;

    do {
        printf("\n\t--------------- Bienvenido a Melate! ---------------\n"
               "\n\t1 - Captura de Boleta"
               "\n\t2 - Ejecuci%cn de Sorteo"
               "\n\t3 - Reporte de Boletas Capturadas"
               "\n\t4 - Reporte de Boletas Ganadoras"
               "\n\t5 - Reinicio de Aplicaci%cn"
               "\n\t6 - Salir"
               "\n\n\tIntroduce una opci%cn: ", 162, 162, 162);
        scanf("%i", &opc);

        verifyOption(&opc, 6, 1);

        switch(opc) {
            case 1:
                captureTicket();
                break;
            case 2:
                drawNumbers();
                break;
            case 3:
                ticketReportByCapture();
                break;
            case 4:
                ticketReportByWinner();
                break;
            case 5:
                restartApp();
                break;
        }
        printf("\n\n");
        system("pause");
        system("cls");
    } while(opc != 6);
}

int main()
{
    menu();
    return 0;
}

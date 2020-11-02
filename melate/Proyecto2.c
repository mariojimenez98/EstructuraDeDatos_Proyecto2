/********************************************
    Nombre de Alumnos: Mario Ivan Jimenez Alfaro #727740

    Fecha: 7 de Noviembre 2020
    Materia: Estructura de Datos
    Programa: Proyecto 2
    Descripcion: Simulador Melate
********************************************/

#include <stdio.h>
#include <stdlib.h>

#define K_ARR_SIZE 6
//CAMBIAR TAMAÑO TICKETS ANTES DE SUBIR
#define K_NUM_TICKETS 3
#define true 1
#define false 0

int i, j, acumTicketIndex = 0;

typedef struct
{
    int id;
    int numArray[K_ARR_SIZE];
    int isWinner;
}Ticket;

Ticket tickets[K_NUM_TICKETS];

int verifyRepeatedNumbers(Ticket t)
{
    for (i = 0; i < K_ARR_SIZE; i++)
        for (j = 0; j < K_ARR_SIZE; j++)
            if(t.numArray[i] == t.numArray[j] && i != j)
                return false;
    return true;
}

void shellSort(int t[])
{
    int k, jump, aux, end, acum = 1;

    j = 0;

    jump = K_ARR_SIZE;

    while (jump > 0)
    {
        jump = jump / 2;
        do
        {
            end = true;
            k = K_ARR_SIZE-jump ;
            for (i = 0; i < k; i++)
            {
                j = i + jump;
                if (t[i] > t[j])
                {
                    aux = t[i];
                    t[i] = t[j];
                    t[j] = aux;
                    end = false;
                }
            }
        } while (!end);
    }
}

void verifyRange(int *value, int max, int min)
{
    if(*value > max || *value < min)
    {
        do {
            printf("\tN%cmero no es valido, intente de nuevo: ", 163, 162);
            scanf("%i", &*value);
        } while(*value > max || *value < min);
    }
}

void pauseAndWipe()
{
    printf("\n\n");
    system("pause");
    system("cls");
}

void captureTicket()
{
    if(acumTicketIndex < K_NUM_TICKETS)
    {
        printf("\n\t------------ Capturando boleta %i ------------\n", acumTicketIndex + 1);
        for(i = 0; i < K_ARR_SIZE; i++)
        {
            printf("\n\tIntroduce el valor %i de su boleta: ", i + 1);
            scanf("%i", &tickets[acumTicketIndex].numArray[i]);
            verifyRange(&tickets[acumTicketIndex].numArray[i], 56, 1);
        }
        if(!verifyRepeatedNumbers(tickets[acumTicketIndex]))
        {
            printf("\n\tExiste al menos un valor repetido, captura de nuevo.");
            pauseAndWipe();
            captureTicket();
        }
        else
        {
            shellSort(tickets[acumTicketIndex].numArray);
            tickets[acumTicketIndex].id = acumTicketIndex + 1;
            acumTicketIndex++;
        }
    }
    else
        printf("\n\tSe excedi%c el numero de boletas.", 162);
    return;
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

        verifyRange(&opc, 6, 1);

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
        pauseAndWipe();
    } while(opc != 6);
}

int main()
{
    menu();
    return 0;
}

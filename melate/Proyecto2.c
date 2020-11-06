/********************************************
    Nombre de Alumnos: Mario Ivan Jimenez Alfaro #727740

    Fecha: 7 de Noviembre 2020
    Materia: Estructura de Datos
    Programa: Proyecto 2
    Descripcion: Simulador Melate
********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definicion de variables estaticas
#define K_NUMS_TICKET 6
/*          -------------------------------------
            CAMBIAR TAMAÑO TICKETS ANTES DE SUBIR
            -------------------------------------
*/
#define K_TICKETS 3
#define true 1
#define false 0

// Creacion de la estructura Ticket
typedef struct
{
    int id;
    int numArray[K_NUMS_TICKET];
    int isWinner;
    int place;
}Ticket;

// Creacion de variables globales
int i, j, acumTicketIndex = 0;
Ticket tickets[K_TICKETS];

// Declaracion de funciones auxiliares
int verifyRepeatedNumbers(Ticket t);
void verifyRange(int *value, int max, int min);
void shellSort(int t[]);
void pauseAndWipe();

// Declaracion de funciones principales
void captureTicket();
void drawNumbers();
void ticketReportByCapture();
void ticketReportByWinner();
void restartApp();
void menu();

// ----------------- Funciones Auxiliares -----------------

int verifyRepeatedNumbers(Ticket t)
{
    for (i = 0; i < K_NUMS_TICKET; i++)
        for (j = 0; j < K_NUMS_TICKET; j++)
            if(t.numArray[i] == t.numArray[j] && i != j)
                return false;
    return true;
}

void verifyRange(int *value, int max, int min)
{
    if(*value > max || *value < min)
    {
        do {
            printf("\tN%cmero no es valido, intente de nuevo: ", 163);
            scanf("%i", &*value);
        } while(*value > max || *value < min);
    }
}

void shellSort(int t[])
{
    int k, jump, aux, end, acum = 1;

    j = 0;

    jump = K_NUMS_TICKET;

    while (jump > 0)
    {
        jump = jump / 2;
        do
        {
            end = true;
            k = K_NUMS_TICKET-jump ;
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

void pauseAndWipe()
{
    printf("\n\n");
    system("pause");
    system("cls");
}

// ----------------- Funciones Principales -----------------

void captureTicket()
{
    if(acumTicketIndex < K_TICKETS)
    {
        printf("\n\t------------ Capturando boleta %i ------------\n", acumTicketIndex + 1);
        for(i = 0; i < K_NUMS_TICKET; i++)
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
        printf("\n\tERROR: Se excedi%c el numero de boletas.", 162);
    return;
}

void drawNumbers()
{
    printf("\n\tHacer algo");
}

void ticketReportByCapture()
{
    if(acumTicketIndex > 0)
    {
        char num[31];
        int index = 0;

        printf("\n\t------------ Boletas Capturadas ------------\n");
        for(i = 0; i < acumTicketIndex; i++)
        {
            for(j = 0; j < K_NUMS_TICKET; j++)
                index += sprintf(&num[index], " %i ", tickets[i].numArray[j]);

            printf("\n\tIdentificador de la boleta: %i\tNumeros: %s", tickets[i].id, num);
            index = 0;
        }
    }
    else
        printf("\n\tERROR: No hay boletas.");
}

void ticketReportByWinner()
{
    printf("\n\tHacer algo");
}

void restartApp()
{
    for (i = 0; i < acumTicketIndex; i++){
        tickets[i].id =0;
        for (j = 0; j < K_NUMS_TICKET; j++){
            tickets[i].numArray[j] = 0;
        }
        tickets[i].isWinner =0;
        tickets[i].place =0;
    }
    acumTicketIndex = 0;

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

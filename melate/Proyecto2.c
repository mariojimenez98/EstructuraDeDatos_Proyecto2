/********************************************
    Nombre de Alumnos: Mario Ivan Jimenez Alfaro    #727740
                       Benjamin Gil Flores          #727211
                       Juan Enrique Cibrian Loera   #725290
                       Alejandro Sada Prendes       #725958
                       Carlos Manuel Alanis Peña    #732158
    Fecha: 7 de Noviembre 2020
    Materia: Estructura de Datos
    Programa: Proyecto 2
    Descripcion: Simulador Melate
********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Definicion de variables estaticas
#define K_NUMS_TICKET 6
#define K_MELATE 7
#define K_REVANCHA 6
#define K_TICKETS 100
#define K_PLACES 3

#define true 1
#define false 0

// Creacion de la estructura Ticket
typedef struct
{
    int id;
    int numArray[K_NUMS_TICKET];
    int place[K_PLACES];
    char numbers[31];
}Ticket;

// Creacion de variables globales
int i, j, k, acumTicketIndex = 0;
int arrMelate[K_MELATE], arrRevancha[K_REVANCHA], arrRevanchita[K_REVANCHA];
int topMelate = 0, topRevancha = 0, topRevanchita = 0;
int hasCaptured = false, hasDrawn = false;
Ticket tickets[K_TICKETS];

// Declaracion de funciones auxiliares
int verifyRepeatedNumbers(int arr[], int size);
void verifyRange(int *value, int max, int min);
void convertArrayToString();
void shellSort(int t[]);
void insertStack(int *draw, int *top, int max, int num);
void removeStack(int *top);
int isStackFull(int top, int max);
int isStackEmpty(int top);
void generateWinningNumbers(int draw[], int size, int top);
void printDrawnNumbers(int draw[], int size);
int binarySearch(int t[], int size, int num);
void clearStack(int top);
void pauseAndWipe();

// Declaracion de funciones principales
void captureTicket();
void drawNumbers();
void ticketReportByCapture();
void ticketReportByWinner();
void restartApp();
void menu();

// ----------------- Funciones Auxiliares -----------------

int verifyRepeatedNumbers(int arr[], int size)
{
    for (i = 0; i < size; i++)
        for (j = 0; j < size; j++)
            if(arr[i] == arr[j] && i != j)
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

void convertArrayToString()
{
    char num[31];
    int index = 0;

    for(i = 0; i < acumTicketIndex; i++)
    {
        for(j = 0; j < K_NUMS_TICKET; j++)
            index += sprintf(&num[index], " %i ", tickets[i].numArray[j]);

        strcpy(tickets[i].numbers, num);
        index = 0;
    }
}

void shellSort(int t[])
{
    int jump, aux, end, acum = 1;

    j = 0;
    k = 0;

    jump = K_NUMS_TICKET;

    while (jump > 0)
    {
        jump = jump / 2;
        do
        {
            end = true;
            k = K_NUMS_TICKET - jump ;
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

void insertStack(int *draw, int *top, int max, int num)
{
    int t;
    t =* top;
    if(isStackFull(t, max))
    {
        printf("\n\n ERROR: La pila esta llena.");
        pauseAndWipe();
    }
    else
    {
        draw[t] = num;
        t++;
        *top = t;
    }
}

void removeStack(int *top)
{
    int t;
    t =* top;
    if(isStackEmpty(t))
    {
        printf("\n\n ERROR: La pila esta vacia.");
        pauseAndWipe();
    }
    else
    {
        t--;
        *top = t;
    }
}

int isStackFull(int top, int max)
{
    return (top == max) ? true : false;
}

int isStackEmpty(int top)
{
    return (top == 0) ? true : false;
}

void generateWinningNumbers(int draw[], int size, int top)
{
    int num;

    for(i = 0; i < size; i++)
    {
        num = (rand() % 56) + 1;
        insertStack(draw, &top, size, num);
    }
}

void printDrawnNumbers(int draw[], int size)
{
    for(i = 0; i < size; i++)
        printf("\t%i", draw[i]);
}

int binarySearch(int t[], int size, int num)
{
    int start = 0, end = size - 1, index = 0, isFound = false, middle;

    while(isFound == false && index <= end)
    {
        middle = (index + end) / 2;
        if (num == t[middle])
            isFound = true;
        else
            if (num < t[middle])
                end = middle - 1;
            else
                index = middle + 1;

    }
    return isFound;
}

void clearStack(int top)
{
    for(i = 0; i < top; i++)
        removeStack(&top);
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
    if(!hasDrawn)
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
            if(!verifyRepeatedNumbers(tickets[acumTicketIndex].numArray, K_NUMS_TICKET))
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
                hasCaptured = true;
            }
        }
        else
            printf("\n\tERROR: Se excedi%c el numero de boletas.", 162);
    }
    else
        printf("\n\tERROR: Ya se generaron los ganadores, no es posible capturar mas boletas.");
}

void drawNumbers()
{
    if(hasCaptured)
        if(!hasDrawn)
        {
            do
            {
                srand(time(0));
                generateWinningNumbers(arrMelate, K_MELATE, topMelate);
                generateWinningNumbers(arrRevancha, K_REVANCHA, topRevancha);
                generateWinningNumbers(arrRevanchita, K_REVANCHA, topRevanchita);

            } while(!verifyRepeatedNumbers(arrMelate, K_MELATE) ||
                    !verifyRepeatedNumbers(arrRevancha, K_REVANCHA) ||
                    !verifyRepeatedNumbers(arrRevanchita, K_REVANCHA));

            shellSort(arrMelate);
            shellSort(arrRevancha);
            shellSort(arrRevanchita);

            printf("\n\t------------------- Melate -------------------\n");
            printDrawnNumbers(arrMelate, K_MELATE);

            printf("\n\n\t------------------- Revancha -------------------\n");
            printDrawnNumbers(arrRevancha, K_REVANCHA);

            printf("\n\n\t------------------- Revanchita -------------------\n");
            printDrawnNumbers(arrRevanchita, K_REVANCHA);

            hasDrawn = true;
        }
        else
            printf("\n\tERROR: Ya se generaron los n%cmeros ganadores", 163);
    else
        printf("\n\tERROR: Se deben capturar boletas antes de generar los n%cmeros ganadores", 163);
}

void ticketReportByCapture()
{
    if(hasCaptured)
    {
        printf("\n\t------------ Boletas Capturadas ------------\n");
        for(i = 0; i < acumTicketIndex; i++)
        {
            printf("\n\tIdentificador de la boleta: %i\tN%cmeros: %s", tickets[i].id, 163, tickets[i].numbers);
        }
    }
    else
        printf("\n\tERROR: No hay boletas.");
}

void ticketReportByWinner()
{
    int countMelate = 0, countRevancha = 0, countRevanchita = 0;

    if(hasCaptured)
        if(hasDrawn)
        {
            for(i = 0; i < acumTicketIndex; i++)
            {
                for(j = 0; j < K_MELATE; j++)
                    if(binarySearch(tickets[i].numArray, K_NUMS_TICKET, arrMelate[j]))
                        countMelate++;
                for(k = 0; k < K_REVANCHA; k++)
                    if(binarySearch(tickets[i].numArray, K_NUMS_TICKET, arrRevancha[k]))
                        countRevancha++;
                    if(binarySearch(tickets[i].numArray, K_NUMS_TICKET, arrRevanchita[k]))
                        countRevanchita++;

                // Sorteo Melate
                if(countMelate == 6)
                    tickets[i].place[0] = 1;
                else if(countMelate == 5 && binarySearch(tickets[i].numArray, K_NUMS_TICKET, arrMelate[K_MELATE]))
                    tickets[i].place[0] = 2;
                else if(countMelate == 5)
                    tickets[i].place[0] = 3;

                // Sorteo Revancha
                if(countRevancha == 6)
                    tickets[i].place[1] = 1;
                else if(countRevancha == 5)
                    tickets[i].place[1] = 2;
                else if(countRevancha == 4)
                    tickets[i].place[1] = 3;

                // Sorteo Revanchita
                if(countRevanchita == 6)
                    tickets[i].place[2] = 1;
                else if(countRevanchita == 5)
                    tickets[i].place[2] = 2;
                else if(countRevanchita == 4)
                    tickets[i].place[2] = 3;

                countMelate = 0;
                countRevancha = 0;
                countRevanchita = 0;
            }

            printf("\n\t----------------- Ganadores Melate -----------------\n");
            for(i = 0; i < acumTicketIndex; i++)
            {
                if(tickets[i].place[0] == 1)
                    printf("\n\t1er. lugar --- Boleta: %i\tNumeros: %s", tickets[i].id, tickets[i].numbers);
                else if(tickets[i].place[0] == 2)
                    printf("\n\t2do. lugar --- Boleta: %i\tNumeros: %s", tickets[i].id, tickets[i].numbers);
                else if(tickets[i].place[0] == 3)
                    printf("\n\t3er. lugar --- Boleta: %i\tNumeros: %s", tickets[i].id, tickets[i].numbers);
                else
                    printf("\n\tNo hay ganadores! Sigue participando.");
            }

            printf("\n\n\t----------------- Ganadores Revancha -----------------\n");
            for(j = 0; j < acumTicketIndex; j++)
            {
                if(tickets[j].place[1] == 1)
                    printf("\n\t1er. lugar --- Boleta: %i\tNumeros: %s", tickets[j].id, tickets[j].numbers);
                else if(tickets[j].place[1] == 2)
                    printf("\n\t2do. lugar --- Boleta: %i\tNumeros: %s", tickets[j].id, tickets[j].numbers);
                else if(tickets[j].place[1] == 3)
                    printf("\n\t3er. lugar --- Boleta: %i\tNumeros: %s", tickets[j].id, tickets[j].numbers);
                else
                    printf("\n\tNo hay ganadores! Sigue participando.");
            }

            printf("\n\n\t----------------- Ganadores Revanchita -----------------\n");
            for(k = 0; k < acumTicketIndex; k++)
            {
                if(tickets[k].place[2] == 1)
                    printf("\n\t1er. lugar --- Boleta: %i\tNumeros: %s", tickets[k].id, tickets[k].numbers);
                else if(tickets[k].place[2] == 2)
                    printf("\n\t2do. lugar --- Boleta: %i\tNumeros: %s", tickets[k].id, tickets[k].numbers);
                else if(tickets[k].place[2] == 3)
                    printf("\n\t3er. lugar --- Boleta: %i\tNumeros: %s", tickets[k].id, tickets[k].numbers);
                else
                    printf("\n\tNo hay ganadores! Sigue participando.");
            }
        }
        else
            printf("\n\tERROR: No se han generado los n%cmeros ganadores", 163);
    else
        printf("\n\tERROR: Se deben capturar boletas antes de imprimir a los ganadores");
    //binarySearch(tickets[0].numArray, K_NUMS_TICKET, 3);
}

void restartApp()
{
    for(i = 0; i < acumTicketIndex; i++)
    {
        tickets[i].id = 0;
        for(j = 0; j < K_NUMS_TICKET; j++)
            tickets[i].numArray[j] = 0;

        for(k = 0; k < K_PLACES; k++)
            tickets[i].place[k] = 0;
    }

    clearStack(topMelate);
    clearStack(topRevancha);
    clearStack(topRevanchita);

    acumTicketIndex = 0;
    hasCaptured = false;
    hasDrawn = false;



    printf("\n\tAplicaci%cn se reinici%c con %cxito", 162, 162, 130);
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

            convertArrayToString();
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
            case 6:
                printf("\n\tCerrando aplicaci%cn...", 162);
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

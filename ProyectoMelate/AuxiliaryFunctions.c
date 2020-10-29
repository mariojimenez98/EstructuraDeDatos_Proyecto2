/********************************************
    Nombre de Alumnos: Mario Ivan Jimenez Alfaro #727740

    Fecha: 7 de Noviembre 2020
    Materia: Estructura de Datos
    Programa: Proyecto 2
    Descripcion: Funciones Auxiliares para Simulador Melate
********************************************/

#include <stdio.h>

#include "AuxiliaryFunctions.h"

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

#ifndef _PUNTOS_INICIALES_H
#define _PUNTOS_INICIALES_H 

// Importando Librerias utiles.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h> // para comparar cadenas


// Funciones a utilizar para encontrar puntos validos en los bordes de la matriz.
int num_entradas(int m, int n, int **matriz);
void puntos_inicio(int m, int n,  int **matriz , int *entrada_x, int *entrada_y);



#endif
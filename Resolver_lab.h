#ifndef _RESOVER_LAB_H
#define _RESOLVER_LAB_H 

// Importando Librerias utiles.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h> // para comparar cadenas


// Funciones a utilizar para resolver el laberinto.

void mostrar(int **matriz, int m, int n);
void buscarSolucion (int** matriz, int x, int y, int m, int n, int *aux);
void buscarSolucion_2 (int** matriz, int x, int y, int m, int n, int *aux);
void buscarSolucion_3 (int** matriz, int x, int y, int m, int n, int *aux);
void buscarSolucion_4 (int** matriz, int x, int y, int m, int n, int *aux); 

#endif
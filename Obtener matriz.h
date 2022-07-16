#ifndef _OBTENER_MATRIZ_
#define _OBTENER_MATRIZ_


// Importando Librerias utiles.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h> // para comparar cadenas


// Funciones a utilizar para contruir la matriz a partir del archivo.

void contador(int *m, int *n);
void validar_archivo();
int reservar_memoria (int filas, int colum);
void introduce_valores (int filas, int colum, char **mat);

#endif
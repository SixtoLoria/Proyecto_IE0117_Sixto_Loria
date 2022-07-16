// Programacion bajo plataformas abietas - IE0117
// Estudiante: Sixto Alejandro Loria Villagra.

// Archivos de la modularidad
#include "Obtener matriz.h"
#include "Puntos_iniciales.h"

// Importando Librerias utiles.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h> // para comparar cadenas



int main (){
	
// Lo primero es leer de cuanto por cuanto es la matriz del profesor para hacer yo asi una matriz que lea esa cantidad.

	// contadores
	int m = 1, n = 0; // m sera el contador de filas y n el de columnas.
	
// ------------------------------------------------- Contruccion de la matriz --------------------------------------	
	// Abriendo y validando el archivo.
	validar_archivo();
	
	// Contando el numero de filas y columnas que tiene el laberinto.
	contador ( &m, &n);
	
	// Creacion de la martiz de trabajo
	char **matriz; 
	
	// memoria dinamica para la matriz
	matriz = reservar_memoria(m, n);
	
	// asignacion de valores.
	introduce_valores(m, n, matriz);
	
	
	int i,j;
	printf("\n\n");
    for (i= 0; i<m; ++i){
        for (j=0; j<n; ++j){
            printf("%i", matriz[i][j]);
        }
        printf("\n");
    }
    
    /* Ahora antes de comenzar a buscar una trayectoria valida, es necesario encontrar la posicion inicial del intento.
	El enunciado indica de que se debe comenzar a recorrer desde los bordes. 
	Buscando si hay un uno o un dos en los bordes:  
	*/
    
    // Definiendo vectores para las posiciones iniciales
    int *entrada_x, *entrada_y;
    int entradas;
    
    // Calculando el numero de entradas para la memoria Dinamica de los vectores.
    
    entradas = num_entradas( m,  n, matriz);
    
    printf("El numero de entradas es: %i", entradas);
    
    // Reservando memoria para los vectores que contienen las posiciones iniciales
    entrada_x = (int*)malloc(entradas*sizeof(int));
    entrada_y = (int*)malloc(entradas*sizeof(int));
    
    
    // Ingreso de datos con las posiciones en los bordes.
    puntos_inicio(m,  n, matriz , entrada_x, entrada_y);
    
    // Si en los bordes no se encuentra el punto de ingreso, el laberinto es invalido.
    if (entrada_x  == NULL || entrada_y == NULL){
	 	printf(" Error el laberinto ingresado no cuenta con una entrada en los bordes\n");
	 	exit(1);
	 }
	 
	 for (i = 0; i < entradas ; i++){
    	printf(" \n %i , %i \n", entrada_x[i], entrada_y[i]);
	}
    
    
    
    
	
	system("pause");
	return 0;
}






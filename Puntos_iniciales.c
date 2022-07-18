#include "Puntos_iniciales.h"

/*
En este archivo de codigo se encuentran contenidas las librerias necesarias para buscar puntos de inicio con los cuales comenzar a resolver el laberinto.
Lo primero sera contar la cantidad de puntos, para asi reservar la memoria dinamica necesaria en los vectores que contentran las coordenadas de puntos
validos de entrada, posteriormente se asignaran los valores correspondientes.
*/


// Funcion que cuenta el numero de entradas, retorna dicho numero.
int num_entradas(int m, int n, int **matriz){
	int i;
	int entrada = 0;
	
	for (i = 0; i < n ; i++){
		if ( matriz[0][i] == 1 || matriz[0][i] == 2){
				entrada ++;
		}
	}
	for (i = 0; i< m ; i++){
		if ( matriz[i][0] == 1 || matriz[i][0] == 2){
				entrada ++;
		}
	}
	for (i= 0; i < n ; i++){
		if(matriz[m-1][i] == 1 || matriz[m-1][i] == 2){
				entrada ++;
		}
	}
	for (i = 0 ; i < m; i++){
		if (matriz[i][n-1] == 1 || matriz[i][n-1] == 2){
				entrada ++;
		}
	}
	return entrada;
}


// Funcion que encuentra y guarda en vectores los puntos encontrados en los bordes.
void puntos_inicio(int m, int n,  int **matriz , int *entrada_x, int *entrada_y){
	int cont = 0;
	int i,j;
	
	for (j = 0; j < n ; j++){
		if ( matriz[0][j] == 1 || matriz[0][j] == 2){
				entrada_x[cont] = 0;
            	entrada_y[cont] = j;
            	cont++;
		}
	}
	for (i = 0; i< m ; i++){
		if ( matriz[i][0] == 1 || matriz[i][0] == 2){
				entrada_x[cont] = i;
            	entrada_y[cont] = 0;
            	cont++;
		}
	}
	for (j = 0; j < n ; j++){
		if(matriz[m-1][j] == 1 || matriz[m-1][j] == 2){
				entrada_x[cont] = m-1;
            	entrada_y[cont] = j;
            	cont++;
		}
	}
	for (i = 0 ; i < m; i++){
		if (matriz[i][n-1] == 1 || matriz[i][n-1] == 2){
				entrada_x[cont] = i;
            	entrada_y[cont] = n-1;
            	cont++;
		}
	}	
}






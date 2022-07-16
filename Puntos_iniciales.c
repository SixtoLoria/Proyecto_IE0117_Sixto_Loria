#include "Puntos_iniciales.h"

/*
En este archivo de codigo se encuentran contenidas las librerias necesarias para buscar puntos de inicio con los cuales comenzar a resolver el laberinto.
Lo primero sera contar la cantidad de puntos, para asi reservar la memoria dinamica necesaria en los vectores que contentran las coordenadas de puntos
validos de entrada, posteriormente se asignaran los valores correspondientes.
*/


// Funcion que cuenta el numero de entradas, retorna dicho numero.
int num_entradas(int m, int n, char **matriz){
	
	int i,j;
	int entrada = 0;
	
	for (i= 0; i<m ; ++i){
        for (j=0; j<n; ++j){
            
            if (  (i == 0) && (matriz[0][j] == 1 || matriz[0][j] == 2)){
            	entrada ++;
			}
			else if ( (i == 0) && (matriz[i][0] == 1 || matriz[i][0] == 2)){
				entrada ++ ;
			}
			else if (  (i == 0) && (matriz[m-1][j] == 1 || matriz[m-1][j] == 2) ){
				entrada ++;
			}
			else if ( (i == 0) && (matriz[i][n-1] == 1 || matriz[i][n-1] == 2) ){
				entrada ++;
			}
			else{
				
			}	
        }
    }
	return entrada;
}


// Funcion que encuentra y guarda en vectores los puntos encontrados en los bordes.
void puntos_inicio(int m, int n,  char **matriz , int *entrada_x, int *entrada_y){
	int cont = 0;
	int i,j;
	
	for (i= 0; i<m ; ++i){
        for (j=0; j<n; ++j){
            
            if ( (i == 0) && (matriz[0][j] == 1 || matriz[0][j] == 2)){
            	entrada_x[cont] = 0;
            	entrada_y[cont] = j;
            	cont++;
			}
			else if ( (i == 0) && (matriz[i][0] == 1 || matriz[i][0] == 2) ){
				entrada_x[cont] = i;
            	entrada_y[cont] = 0;
            	cont++;
            	
			}
			else if ( (i == 0) && (matriz[m-1][j] == 1 || matriz[m-1][j] == 2)){
				entrada_x[cont] = m;
            	entrada_y[cont] = j;
            	cont++;
            	
			}
			else if (  (i == 0) && (matriz[i][n-1] == 1 || matriz[i][n-1] == 2)){
				entrada_x[cont] = i;
            	entrada_y[cont] = n;
            	cont++;
            	
			}
			else{
				
			}
        }
    }
}






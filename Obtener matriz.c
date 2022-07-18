

#include "Obtener matriz.h"

/*
En este archivo se encuentran las funciones necesarias para leer el archivo de texto y pasarlo a una matriz de tipo char.
Para ello sera necesario primero abrir y validar el archivo a ver si no hay ningun fallo con el mismo.
Luego se contaran la cantidad de filas y columnas necesarios para la contruccion de la matriz.
*/


// Funcion que lee y valida el archivo.
void validar_archivo(){
	
	
	FILE *laberinto; 
    laberinto = fopen("laberinto.txt", "r"); 
    // Comprobando si hay informacion en el archivo.

    if(laberinto == NULL){
        printf ("El archivo esta vacio");
        exit(1);
    }
    fclose(laberinto);
}


// Funcion que cuenta el numero de filas y columnas del la matriz leida.
void contador(int *a, int *b){
	
	int m,n;
	m = *a;
	n = *b;
	FILE *laberinto;
	laberinto = fopen("laberinto.txt", "r"); 
	char contenido; // variable para leer el contenido 
	
	// ---------------  Leyendo el archivo--------
    while (contenido != EOF){
    	
        contenido = fgetc(laberinto); 
        
     	if (contenido == '\n' || contenido == '\r'){
        	m ++;  // aumentando contador de filas
        	n = 0; // reiniciando contador de columnas
		}
		else if (isdigit(contenido)){  // "isdigit" es funcion que evalua si es un digito.
        	n ++; 
        	
		} 
        
     	printf ("%c", contenido);   
    
    }
    *a = m;
    *b = n;
    fclose(laberinto);
}

// Funcion que reserva la memoria dinamica necesaria para la asignacion de valores, necesarios para contruir la matriz.
int **reservar_memoria (int filas, int colum){

	int i;
	int **matriz;
	
	matriz = (int**)calloc(filas,sizeof(int*));
	if (matriz == NULL){
		printf("No se ha podido revervar memoria \n");
		exit(1);
	}
	for(i = 0; i< filas; i++){
		matriz[i] = (int*)calloc(colum,sizeof(int));
		if (matriz == NULL){
		printf("No se ha podido revervar memoria \n");
		exit(1);
		}
	}
	return matriz;	
}


// Funcion que asigna los valores correspondientes al archivo leido en la matriz dinamica creada.


void introduce_valores(int filas, int colum, int **matriz){
	FILE *laberinto;
	
	laberinto = fopen("laberinto.txt", "r");
	int i = 0,j = 0;
	char recorrido;
	recorrido = ' ';
	while (recorrido != EOF){
        recorrido = fgetc(laberinto); 
        
        if (i >= filas ){
        	break;
		}
        if (j >= colum ){
        	i++;
        	j = 0;
		}
        
     	if (isdigit(recorrido) ){
				matriz[i][j] = atoi(&recorrido);
				j++;
		}
    }
	fclose(laberinto);
}


    













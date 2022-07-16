

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
int reservar_memoria (int filas, int colum){

	int i;
	char **matriz;
	
	matriz = (char**)calloc(filas,sizeof(char*));
	if (matriz == NULL){
		printf("No se ha podido revervar memoria \n");
		exit(1);
	}
	for(i = 0; i< filas; i++){
		matriz[i] = (char*)calloc(colum,sizeof(char));
		if (matriz == NULL){
		printf("No se ha podido revervar memoria \n");
		exit(1);
		}
	}
	return matriz;	
}


// Funcion que asigna los valores correspondientes al archivo leido en la matriz dinamica creada.
void introduce_valores(int filas, int colum, char **matriz){
	FILE *laberinto;
	laberinto = fopen("laberinto.txt", "r");
	int i,j;
	char recorido;
	
	for (i = 0; i < filas; i++){
		for(j = 0 ; j < colum ; j++){
			recorido = fgetc(laberinto);
			if (recorido != EOF){
				fscanf(laberinto, "%d" ,&matriz[i][j+1]);
			}
		}
	}
	fclose(laberinto);
}


// LIBERACION DE LA MEMORIA DINAMICA
  /*  for (i= 0; i<m; ++i)
        free(matriz[i]);
    free(matriz);

*/












#include "Resolver_lab.h"


/*
Funcion recursiva que resuelve el laberinto, ba dejando ratro para no volver a pasar por el mismo camino 2 veces.
La funcion tambien imprime en pantalla la posicion en donde se encuentra la solucion.
El valor de auxiliar lo que hace es que una vez se encuentre una respuesta, nos salimos ya que 
segun el enunciado solo una respuest es valida, de esta forma ahorramos un poco de recursos.
*/


// Funcion que imprime la matriz, utili para ver el funcionamiento del resolverdor paso a paso.
void mostrar(int **matriz, int m, int n){
	int i,j;
	
	printf("\n\n");
    for (i= 0; i<m; ++i){
        for (j=0; j<n; ++j){
            printf("%i", matriz[i][j]);
        }
        printf("\n");
    }	
}


void buscarSolucion (int** matriz, int x, int y, int m, int n, int *aux){
	
	// la resolucion se hace en una copia para poder probar diversos valores.
	int i,j;
	int **copia = reservar_memoria(m,n);
	
	for (i = 0; i< m ; i++){
		for(j =0; j <n ; j++){
			copia [i][j] = matriz[i][j];
		}
	}
	
	
	int salir = *aux;
	// Caso base: llegar a la solucion, en este caso que se encunetre en uno de los bordes.
	if (copia[x][y] == 2 ){    //    ||  copia[x-1][y] == 2 || copia[x+1][y] == 2  || copia[x][y+1] == 2 || copia[x][y-1] == 2
		printf("Se encontro una solucion valida en: \n\n");
		printf(" (Fila # %i, Columna # %i) \n\n ", x, y);
		printf("Recordar que las primeras filas y columnas son las #0 \n\n");
		salir = 1;
		*aux = salir;
	}
	
	
	else{
		if (copia[x+1][y] == 1 && x+1 > 0 && x+1 < m ){
			copia[x+1][y] = 4; // Para ir dejando rastro
			copia[x][y] = 4;
		//	mostrar(copia, m, n);
			buscarSolucion ( copia, x +1,  y,  m,  n, aux);
		}
		else{
			if ( copia[x-1][y] == 1 && x-1 > 0 && x-1 <= m){
				 copia[x-1][y] = 4;
				 copia[x][y] = 4;
			//	 mostrar(copia,  m, n);
				 buscarSolucion ( copia, x-1, y,  m,  n, aux);
			}
			else{
				if(copia[x][y+1] == 1 && y+1 > 0 && y+1 <= n){
					copia[x][y+1] = 4;
					copia[x][y] = 4;
				//	mostrar(copia,  m, n);
					buscarSolucion ( copia, x, y+1,  m, n, aux);
				}
				else{
					if (copia[x][y-1] == 1 && y-1 > 0 && y-1 <= n){
						copia[x][y-1] = 4;
						copia[x][y] = 4;
				//		mostrar(copia,  m, n);
						buscarSolucion ( copia, x, y-1,  m,  n, aux);
					}
					// Si no encuentro un uno pruebo si encontre la respuesta y si no me regreso.
					else if ( copia[x+1][y] == 2){
						printf("Se encontro una solucion valida en: \n\n");
						printf(" (Fila # %i, Columna # %i) \n\n ", x+1, y);
						printf("Recordar que las primeras filas y columnas son las #0 \n\n"); 
						salir = 1;
						*aux = salir;
					}
	
					else if (copia[x-1][y] == 2){
						printf("Se encontro una solucion valida en el punto: \n\n");
						printf(" (Fila # %i, columna # %i) \n\n ", x-1, y);
						printf("Recordar que las primeras filas y columnas son las #0 \n\n");
						salir = 1;
						*aux = salir;
					}
					else if(copia[x][y+1] == 2){
						printf("Se encontro una solucion valida en el punto: \n\n");
						printf(" (Fila # %i, # Columna %i) \n\n", x, y+1);
						printf("Recordar que las primeras filas y columnas son las #0 \n\n");
						salir = 1;
						*aux = salir;
					}
					else if (copia[x][y-1] == 2){
						printf("Se encontro una solucion valida en el punto: \n\n");
						printf(" (Fila # %i, Columna # %i) \n\n ", x, y-1);
						printf("Recordar que las primeras filas y columnas son las #0 \n\n ");
						salir = 1;
						*aux = salir;
					}
					else{
						if (copia[x+1][y] == 4 && x+1 > 0 && x+1 <= m){
							copia[x][y] = 5;     // 5 Representa un camino que ya fue usado y no llevo a la solucion.
						//	mostrar(copia,  m, n);
							buscarSolucion ( copia, x +1, y,  m,  n, aux);
						}
						else{
							if(copia[x-1][y] == 4 && x-1 > 0 && x-1 <= m){
								copia[x][y] = 5;
						//		mostrar(copia,  m, n);
								buscarSolucion ( copia, x-1, y,  m,  n, aux);
							}
							else{
								if (copia[x][y+1] == 4 && y+1 > 0 && y+1 <= n){
									copia[x][y] = 5;
							//		mostrar(copia,  m, n);
									buscarSolucion ( copia, x, y+1,  m,  n, aux);
								}
								else{
									if(copia[x][y-1] == 4 && y-1 > 0 && y-1 <= n){
										copia[x][y] = 5;
								//		mostrar(copia,  m, n);
										buscarSolucion ( copia, x, y-1,  m,  n, aux);
									}
								}
							}
						}
					}
				}
			}  
		}	
	}	
}


// Solucion si x = m es decir borde inferior

void buscarSolucion_2 (int** matriz, int x, int y, int m, int n, int *aux){
	
	// la resolucion se hace en una copia para poder probar diversos valores.
	int i,j;
	int **copia_2 = reservar_memoria(m , n);
	
	for (i = 0; i< m ; i++){
		for(j =0; j <n ; j++){
			copia_2 [i][j] = matriz[i][j];
		}
	}
	
	
	int salir = *aux;
	// Caso base: llegar a la solucion, en este caso que se encunetre en uno de los bordes.
	if (copia_2[x][y] == 2 ){    //    ||  copia[x-1][y] == 2 || copia[x+1][y] == 2  || copia[x][y+1] == 2 || copia[x][y-1] == 2
		printf("Se encontro una solucion valida en: \n\n");
		printf(" (Fila # %i, Columna # %i) \n\n ", x, y);
		printf("Recordar que las primeras filas y columnas son las #0 \n\n");
		salir = 1;
		*aux = salir;
	}
	
	
	else{
		if ( copia_2[x-1][y] == 1 && x-1 > 0 && x-1 <= m){
		 copia_2[x-1][y] = 4;
		 copia_2[x][y] = 4;
	//	 mostrar(copia_2,  m, n);
		 buscarSolucion ( copia_2, x-1, y,  m,  n, aux);
		}
		else{
			if (copia_2[x+1][y] == 1 && x+1 > 0 && x+1 < m ){
				copia_2[x+1][y] = 4; // Para ir dejando rastro
				copia_2[x][y] = 4;
			//	mostrar(copia_2, m, n);
				buscarSolucion ( copia_2, x +1,  y,  m,  n, aux);
			}
			else{
				if(copia_2[x][y+1] == 1 && y+1 > 0 && y+1 <= n){
					copia_2[x][y+1] = 4;
					copia_2[x][y] = 4;
				//	mostrar(copia_2,  m, n);
					buscarSolucion ( copia_2, x, y+1,  m, n, aux);
				}
				else{
					if (copia_2[x][y-1] == 1 && y-1 > 0 && y-1 <= n){
						copia_2[x][y-1] = 4;
						copia_2[x][y] = 4;
					//	mostrar(copia_2,  m, n);
						buscarSolucion ( copia_2, x, y-1,  m,  n, aux);
					}
					// Si no encuentro un uno pruebo si encontre la respuesta y si no me regreso.
					else if ( copia_2[x+1][y] == 2){
						printf("Se encontro una solucion valida en: \n\n");
						printf(" (Fila # %i, Columna # %i) \n\n ", x+1, y);
						printf("Recordar que las primeras filas y columnas son las #0 \n\n"); 
						salir = 1;
						*aux = salir;
					}
	
					else if (copia_2[x-1][y] == 2){
						printf("Se encontro una solucion valida en el punto: \n\n");
						printf(" (Fila # %i, columna # %i) \n\n ", x-1, y);
						printf("Recordar que las primeras filas y columnas son las #0 \n\n");
						salir = 1;
						*aux = salir;
					}
					else if(copia_2[x][y+1] == 2){
						printf("Se encontro una solucion valida en el punto: \n\n");
						printf(" (Fila # %i, # Columna %i) \n\n", x, y+1);
						printf("Recordar que las primeras filas y columnas son las #0 \n\n");
						salir = 1;
						*aux = salir;
					}
					else if (copia_2[x][y-1] == 2){
						printf("Se encontro una solucion valida en el punto: \n\n");
						printf(" (Fila # %i, Columna # %i) \n\n ", x, y-1);
						printf("Recordar que las primeras filas y columnas son las #0 \n\n ");
						salir = 1;
						*aux = salir;
					}
					else{
						if (copia_2[x+1][y] == 4 && x+1 > 0 && x+1 <= m){
							copia_2[x][y] = 5;     // 5 Representa un camino que ya fue usado y no llevo a la solucion.
						//	mostrar(copia_2,  m, n);
							buscarSolucion ( copia_2, x +1, y,  m,  n, aux);
						}
						else{
							if(copia_2[x-1][y] == 4 && x-1 > 0 && x-1 <= m){
								copia_2[x][y] = 5;
							//	mostrar(copia_2,  m, n);
								buscarSolucion ( copia_2, x-1, y,  m,  n, aux);
							}
							else{
								if (copia_2[x][y+1] == 4 && y+1 > 0 && y+1 <= n){
									copia_2[x][y] = 5;
								//	mostrar(copia_2,  m, n);
									buscarSolucion ( copia_2, x, y+1,  m,  n, aux);
								}
								else{
									if(copia_2[x][y-1] == 4 && y-1 > 0 && y-1 <= n){
										copia_2[x][y] = 5;
									//	mostrar(copia_2,  m, n);
										buscarSolucion ( copia_2, x, y-1,  m,  n, aux);
									}
								}
							}
						}
					}
				}
			}  
		}	
	}	
}


//  Si comienza en y = 0 es decir a la izquiera

void buscarSolucion_3 (int** matriz, int x, int y, int m, int n, int *aux){
	
	// la resolucion se hace en una copia_2 para poder probar diversos valores.
	int i,j;
	int **copia_3 = reservar_memoria(m,n);
	
	for (i = 0; i< m ; i++){
		for(j =0; j <n ; j++){
			copia_3 [i][j] = matriz[i][j];
		}
	}
	
	
	int salir = *aux;
	// Caso base: llegar a la solucion, en este caso que se encunetre en uno de los bordes.
	if (copia_3[x][y] == 2 ){    //    ||  copia_3[x-1][y] == 2 || copia_3[x+1][y] == 2  || copia_3[x][y+1] == 2 || copia_3[x][y-1] == 2
		printf("Se encontro una solucion valida en: \n\n");
		printf(" (Fila # %i, Columna # %i) \n\n ", x, y);
		printf("Recordar que las primeras filas y columnas son las #0 \n\n");
		salir = 1;
		*aux = salir;
	}
	
	
	else{
		if ( copia_3[x-1][y] == 1 && x-1 > 0 && x-1 <= m){
		 copia_3[x-1][y] = 4;
		 copia_3[x][y] = 4;
	//	 mostrar(copia_3,  m, n);
		 buscarSolucion ( copia_3, x-1, y,  m,  n, aux);
		}
		else{
			if (copia_3[x+1][y] == 1 && x+1 > 0 && x+1 < m ){
				copia_3[x+1][y] = 4; // Para ir dejando rastro
				copia_3[x][y] = 4;
			//	mostrar(copia_3, m, n);
				buscarSolucion ( copia_3, x +1,  y,  m,  n, aux);
			}
			else{
				if(copia_3[x][y+1] == 1 && y+1 > 0 && y+1 <= n){
					copia_3[x][y+1] = 4;
					copia_3[x][y] = 4;
				//	mostrar(copia_3,  m, n);
					buscarSolucion ( copia_3, x, y+1,  m, n, aux);
				}
				else{
					if (copia_3[x][y-1] == 1 && y-1 > 0 && y-1 <= n){
						copia_3[x][y-1] = 4;
						copia_3[x][y] = 4;
					//	mostrar(copia_3,  m, n);
						buscarSolucion ( copia_3, x, y-1,  m,  n, aux);
					}
					// Si no encuentro un uno pruebo si encontre la respuesta y si no me regreso.
					else if ( copia_3[x+1][y] == 2){
						printf("Se encontro una solucion valida en: \n\n");
						printf(" (Fila # %i, Columna # %i) \n\n ", x+1, y);
						printf("Recordar que las primeras filas y columnas son las #0 \n\n"); 
						salir = 1;
						*aux = salir;
					}
	
					else if (copia_3[x-1][y] == 2){
						printf("Se encontro una solucion valida en el punto: \n\n");
						printf(" (Fila # %i, columna # %i) \n\n ", x-1, y);
						printf("Recordar que las primeras filas y columnas son las #0 \n\n");
						salir = 1;
						*aux = salir;
					}
					else if(copia_3[x][y+1] == 2){
						printf("Se encontro una solucion valida en el punto: \n\n");
						printf(" (Fila # %i, # Columna %i) \n\n", x, y+1);
						printf("Recordar que las primeras filas y columnas son las #0 \n\n");
						salir = 1;
						*aux = salir;
					}
					else if (copia_3[x][y-1] == 2){
						printf("Se encontro una solucion valida en el punto: \n\n");
						printf(" (Fila # %i, Columna # %i) \n\n ", x, y-1);
						printf("Recordar que las primeras filas y columnas son las #0 \n\n ");
						salir = 1;
						*aux = salir;
					}
					else{
						if (copia_3[x+1][y] == 4 && x+1 > 0 && x+1 <= m){
							copia_3[x][y] = 5;     // 5 Representa un camino que ya fue usado y no llevo a la solucion.
						//	mostrar(copia_3,  m, n);
							buscarSolucion ( copia_3, x +1, y,  m,  n, aux);
						}
						else{
							if(copia_3[x-1][y] == 4 && x-1 > 0 && x-1 <= m){
								copia_3[x][y] = 5;
							//	mostrar(copia_3,  m, n);
								buscarSolucion ( copia_3, x-1, y,  m,  n, aux);
							}
							else{
								if (copia_3[x][y+1] == 4 && y+1 > 0 && y+1 <= n){
									copia_3[x][y] = 5;
								//	mostrar(copia_3,  m, n);
									buscarSolucion ( copia_3, x, y+1,  m,  n, aux);
								}
								else{
									if(copia_3[x][y-1] == 4 && y-1 > 0 && y-1 <= n){
										copia_3[x][y] = 5;
										//mostrar(copia_3,  m, n);
										buscarSolucion ( copia_3, x, y-1,  m,  n, aux);
									}
								}
							}
						}
					}
				}
			}  
		}	
	}	
}

// Si comienza con y = n es decir a la derecha

void buscarSolucion_4 (int** matriz, int x, int y, int m, int n, int *aux){
	
	// la resolucion se hace en una copia_3 para poder probar diversos valores.
	int i,j;
	int **copia_4 = reservar_memoria(m,n);
	
	for (i = 0; i< m ; i++){
		for(j =0; j <n ; j++){
			copia_4 [i][j] = matriz[i][j];
		}
	}
	
	
	int salir = *aux;
	// Caso base: llegar a la solucion, en este caso que se encunetre en uno de los bordes.
	if (copia_4[x][y] == 2 ){    //    ||  copia_4[x-1][y] == 2 || copia_4[x+1][y] == 2  || copia_4[x][y+1] == 2 || copia_4[x][y-1] == 2
		printf("Se encontro una solucion valida en: \n\n");
		printf(" (Fila # %i, Columna # %i) \n\n ", x, y);
		printf("Recordar que las primeras filas y columnas son las #0 \n\n");
		salir = 1;
		*aux = salir;
	}
	
	
	else{
		if ( copia_4[x-1][y] == 1 && x-1 > 0 && x-1 <= m){
		 copia_4[x-1][y] = 4;
		 copia_4[x][y] = 4;
		 //mostrar(copia_4,  m, n);
		 buscarSolucion ( copia_4, x-1, y,  m,  n, aux);
		}
		else{
			if (copia_4[x+1][y] == 1 && x+1 > 0 && x+1 < m ){
				copia_4[x+1][y] = 4; // Para ir dejando rastro
				copia_4[x][y] = 4;
			//	mostrar(copia_4, m, n);
				buscarSolucion ( copia_4, x +1,  y,  m,  n, aux);
			}
			else{
				if (copia_4[x][y-1] == 1 && y-1 > 0 && y-1 <= n){
						copia_4[x][y-1] = 4;
						copia_4[x][y] = 4;
						//mostrar(copia_4,  m, n);
						buscarSolucion ( copia_4, x, y-1,  m,  n, aux);
				}
				else{
					if (copia_4[x][y+1] == 1 && y+1 > 0 && y+1 <= n){
					copia_4[x][y+1] = 4;
					copia_4[x][y] = 4;
					//mostrar(copia_4,  m, n);
					buscarSolucion ( copia_4, x, y+1,  m, n, aux);
					}
					// Si no encuentro un uno pruebo si encontre la respuesta y si no me regreso.
					else if ( copia_4[x+1][y] == 2){
						printf("Se encontro una solucion valida en: \n\n");
						printf(" (Fila # %i, Columna # %i) \n\n ", x+1, y);
						printf("Recordar que las primeras filas y columnas son las #0 \n\n"); 
						salir = 1;
						*aux = salir;
					}
	
					else if (copia_4[x-1][y] == 2){
						printf("Se encontro una solucion valida en el punto: \n\n");
						printf(" (Fila # %i, columna # %i) \n\n ", x-1, y);
						printf("Recordar que las primeras filas y columnas son las #0 \n\n");
						salir = 1;
						*aux = salir;
					}
					else if(copia_4[x][y+1] == 2){
						printf("Se encontro una solucion valida en el punto: \n\n");
						printf(" (Fila # %i, # Columna %i) \n\n", x, y+1);
						printf("Recordar que las primeras filas y columnas son las #0 \n\n");
						salir = 1;
						*aux = salir;
					}
					else if (copia_4[x][y-1] == 2){
						printf("Se encontro una solucion valida en el punto: \n\n");
						printf(" (Fila # %i, Columna # %i) \n\n ", x, y-1);
						printf("Recordar que las primeras filas y columnas son las #0 \n\n ");
						salir = 1;
						*aux = salir;
					}
					else{
						if (copia_4[x+1][y] == 4 && x+1 > 0 && x+1 <= m){
							copia_4[x][y] = 5;     // 5 Representa un camino que ya fue usado y no llevo a la solucion.
							//mostrar(copia_4,  m, n);
							buscarSolucion ( copia_4, x +1, y,  m,  n, aux);
						}
						else{
							if(copia_4[x-1][y] == 4 && x-1 > 0 && x-1 <= m){
								copia_4[x][y] = 5;
								//mostrar(copia_4,  m, n);
								buscarSolucion ( copia_4, x-1, y,  m,  n, aux);
							}
							else{
								if (copia_4[x][y+1] == 4 && y+1 > 0 && y+1 <= n){
									copia_4[x][y] = 5;
									//mostrar(copia_4,  m, n);
									buscarSolucion ( copia_4, x, y+1,  m,  n, aux);
								}
								else{
									if(copia_4[x][y-1] == 4 && y-1 > 0 && y-1 <= n){
										copia_4[x][y] = 5;
										//mostrar(copia_4,  m, n);
										buscarSolucion ( copia_4, x, y-1,  m,  n, aux);
									}
								}
							}
						}
					}
				}
			}  
		}	
	}	
}















































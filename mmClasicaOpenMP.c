/***************************************
-Pontificia Universidad Javeriana
-Nombres: Viviana Gómez 
-Clase: Sistemas Operativos
-Fecha: 2025-04-30
-Tema: Evaluación de Rendimiento
**************************************/

#include "mmInterfazOpenMP.h"

/*
 * Descripción:
 * Este programa realiza la multiplicación de matrices utilizando programación
 * paralela con la biblioteca OpenMP. Para ello, distribuye las filas de la matriz
 * entre los hilos disponibles, de modo que cada hilo se encarga de multiplicar una parte.
 */

/*
 * Conclusión:
 * La implementación de OpenMP en este problema es viable, ya que la multiplicación de matrices
 * permite ejecutar instrucciones similares en paralelo, cambiando únicamente los parámetros
 * que recibe cada hilo (específicamente, la fila a procesar).
 * Al utilizar directivas de OpenMP, es importante declarar las variables privadas por hilo,
 * garantizando que cada uno almacene sus propios resultados y evitando condiciones de carrera.
 * Además, se recomienda no asignar más hilos de los que soporta el procesador de la máquina,
 * ya que esto podría afectar negativamente el rendimiento del programa.
 */



/*
 * Función principal que:
 * 1. Valida argumentos de entrada (tamaño de matriz y número de hilos)
 * 2. Reserva memoria e inicializa matrices
 * 3. Realiza la multiplicación de matrices en paralelo con OpenMP 
 * 4. Mide el tiempo de ejecución
 * 5. Imprime las matrices si son pequeñas
 */
int main(int argc, char *argv[]){
	if(argc < 3){
		printf("\n Use: $./clasicaOpenMP SIZE Hilos \n\n");
		exit(0);
	}

	int N = atoi(argv[1]);  // Dimensión de la matriz
	int TH = atoi(argv[2]); // Número de hilos a utilizar

	// Reservar memoria para matrices A, B y C 
	size_t *matrixA  = (size_t *)calloc(N*N, sizeof(size_t));
	size_t *matrixB  = (size_t *)calloc(N*N, sizeof(size_t));
	size_t *matrixC  = (size_t *)calloc(N*N, sizeof(size_t));

	srand(time(NULL));      // Inicializa semilla para números aleatorios 

	omp_set_num_threads(TH); // Establece número de hilos a usar con OpenMP

	iniMatrix(matrixA, matrixB, N); // Inicializa las matrices A y B

	impMatrix(matrixA, N);  // Imprime matriz A si es pequeña
	impMatrix(matrixB, N);  // Imprime matriz B si es pequeña

	InicioMuestra();              // Inicia cronómetro
	multiMatrix(matrixA, matrixB, matrixC, N); // Multiplica matrices
	FinMuestra();                 // Finaliza cronómetro e imprime el tiempo

	impMatrix(matrixC, N);        // Imprime matriz resultado si es pequeña

	free(matrixA);                // Libera memoria asignada a matriz A
	free(matrixB);                // Libera memoria asignada a matriz B
	free(matrixC);                // Libera memoria asignada a matriz C
	
	return 0;
}

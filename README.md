# Multiplicacion-Matrices-Clasica-OpenMP
Taller en clase Sistemas Operativos de Multiplicación Matrices Clásica: OpenMP

## Descripción
El objetivo principal es demostrar cómo la paralelización con OpenMP puede mejorar el rendimiento en operaciones computacionalmente intensivas, como la multiplicación de matrices. El programa divide las filas de la matriz entre los hilos disponibles, permitiendo que cada hilo procese una porción de la tarea de manera concurrente.

## Conclusión
La implementación de OpenMP en este contexto es efectiva, ya que:
- La multiplicación de matrices permite ejecutar instrucciones similares en paralelo, variando únicamente los parámetros que recibe cada hilo (la fila a procesar).
- Al utilizar directivas de OpenMP, se declaran variables privadas para cada hilo, garantizando que cada uno almacene sus propios resultados y evitando condiciones de carrera.
- Se recomienda no asignar más hilos de los que soporta el procesador de la máquina, ya que esto podría afectar negativamente el rendimiento del programa.

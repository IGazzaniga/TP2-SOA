/* 
  Compile with: mpicc ejercicio19.c -o ejercicio19 -lm
  Run with: mpirun -n 3 ./ejercicio19 X(número a calcular potencias)
*/


#include <stdio.h>
#include <mpi.h>
#include <math.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
int cuadrado(int n) {
  int m;
    m = pow(n, 2);
  return m;
}

int cubo(int n) {
  int m;
    m = pow(n, 3);
  return m;
}

int cuarta(int n) {
  int m;
    m = pow(n, 4);
  return m;
}

int main (int argc, char *argv[])
{
  int cuad, cub, cuar, actual, errno, total, num, id;
  
  num = strtoull( argv[1], NULL, 10 );
  /* inicializa MPI, crea MPI_COMM_WORLD */
  MPI_Init (&argc, &argv);

  /* toma el id del proceso actual */
  MPI_Comm_rank (MPI_COMM_WORLD, &actual);

  /* toma la cantidad total de procesos */
  MPI_Comm_size (MPI_COMM_WORLD, &total);
  
  if (actual == 0){
  cuad = cuadrado(num);
  printf("Proceso %d devuelve el cuadrado que es = %i\n", actual, cuad);
  }
  if (actual == 1){
  cub = cubo(num);
  printf("Proceso %d devuelve el cubo que es = %i\n", actual, cub);
  }
  if (actual == 2){
  cuar = cuarta(num);
  printf("Proceso %d devuelve la potencia cuarta que es = %i\n", actual, cuar);
  }
  /* finaliza MPI */
  MPI_Finalize();

  return 0;
}
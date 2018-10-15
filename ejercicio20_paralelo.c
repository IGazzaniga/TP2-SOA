#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>


int rellenar(int precios[], int tamano){
    int i, numero;
    
    i=0;
    for (i=0;i<1000000;i++){
        numero = rand() % 200 +1; 
        precios[i] = numero;
    }
    return i;
}

int aumento(int precios[], int tamano, int desde, int hasta){
    int i, numero;
    i=0;
    for (i=desde;i<hasta;i++){
        precios[i] = precios[i]*1.2;
    }
}

int main(int argc, char *argv[]) {
  int actual, total, precios[1000000], desde, hasta, aumentador, aumentar;
  rellenar(precios, 1000000);
  
  /* inicializa MPI, crea MPI_COMM_WORLD */
  MPI_Init (&argc, &argv);

  /* toma el id del proceso actual */
  MPI_Comm_rank (MPI_COMM_WORLD, &actual);

  /* toma la cantidad total de procesos */
  MPI_Comm_size (MPI_COMM_WORLD, &total);

  
  desde = actual*(1000000 / total);
  hasta   = (actual+1)*((1000000 / total));
  aumentar = aumento(precios, 1000000, desde , hasta);
  printf("Proceso %i llama a aumento con %i, %i = %i\n", actual, desde, hasta, aumentar );
  
  // End MPI.
  MPI_Finalize();
  return 0;
}
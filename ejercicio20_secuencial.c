#include <stdio.h>
#include <stdlib.h>

int rellenar(int precios[], int tamano){
    int i, numero;
    
    i=0;
    for (i=0;i<1000000;i++){
        numero = rand() % 200 +1; 
        precios[i] = numero;
    }
    return i;
}

int aumento(int precios[], int tamano){
    int i, numero;
    i=0;
    for (i=0;i<1000000;i++){
        precios[i] = precios[i]*1.2;
    }
}

int main(){
   int precios[1000000];
   rellenar(precios, 1000000);
   aumento(precios, 1000000);
}

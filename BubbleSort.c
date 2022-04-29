#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int main(){
    srand (time(NULL));

    int n = 5;
    int *lista = malloc(n * sizeof(int));
    
    for(int i=0;i<n;i++){
        lista[i] = rand() % 100;
    }
    bubbleSort(lista,n);
    
    printf("Lista Ordenada: \n");
    for(int i = 0; i < n; i++){
        printf("%d, ", lista[i]);
    }

}

int bubbleSort(int lista[], int n){
    int trocado;
    for(int j = 0; j < n - 1; j++){
        trocado = 0;
        for(int i = 0; i < n - 1; i++){

            if(lista[i] > lista[i+1]){
                int aux = lista[i];
                lista[i] = lista[i+1];
                lista[i+1] = aux;
                trocado = 1;
            }
        }

        if(!trocado){
            break;
        }
    }

}


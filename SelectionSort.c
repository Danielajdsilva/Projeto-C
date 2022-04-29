#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int main(){
    srand (time(NULL));

    int i, n=10;
    int *lista = malloc(n * sizeof(int));

    for(i=0;i<n;i++){
        lista[i] = rand() % 10;
    }



    int menor, aux;
    for(int i = 0; i < n-1; i++){
        menor = i;
        for(int j = i + 1; j < n; j++){
            if(lista[menor] > lista[j])
            menor=j;
        }
        if(menor != i){
            aux = lista[i];
            lista[i]= lista[menor];
            lista[menor] = aux;
        }
    }

    for(int i=0;i<n;i++){
        printf("%d,", lista[i]);
    }

    return 0;
}

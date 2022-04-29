#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void){

    int n=5 ;
    int *lista = (int *) malloc(n*sizeof(int));
  
    srand (time(NULL));
    
    for(int i=0;i<n;i++){
        lista[i] = rand() % 10;
    }

    insertionSort(lista,n);
    
    for(int i=0;i<n;i++){
        printf("%d, ", lista[i]);
    }

    return 0;
}


int insertionSort(int lista[], int n){

    for(int i = 1; i <= n-1; i++){
        int elemento_chave = lista[i];
        int j = i-1;

        while(j >= 0 && lista[j] > elemento_chave){
            lista[j+1] = lista[j];
            j = j-1;
        }
        lista[j+1] = elemento_chave;
    }

}

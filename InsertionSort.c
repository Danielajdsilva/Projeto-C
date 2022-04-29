#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void){

/*
*   Iniciamos o algorítmo recebendo ou criando uma lista, tanto pelo próprio código ou um arquivo a ser ordenado.
*   Nesse caso a lista é criada na função "main" e executada a ordenação dentro da função "bubbleSort".
*/

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

/****
 *  Nessa função o laço for inicia contando em 1, pois precisamos de um elemento inicial 
 *  para a comparação dos demais, então iniciamos o laço com o segundo número da lista
 *  sendo o elemento chave.
 *  Apartir do elemento chave, declaramos a variavel j como a posição anterior ao elemento chave i-1.
 * 
*/

/****
 * O while executará enquanto o j for maior ou igual a posição 0 da lista
 * e enquanto a posição atual da lista for maior que o elemento chave.
 * percorrendo então por todas as posições anteriores. 
 * caso a posição seja {1,2,3,4,0};
 * O while só será executado na ultima posição, então j=3,
 * pois iniciamos do 1. Os números serão atribuidos uma posição a mais, lista[j+1]={1,2,3,4}
 * assim que todos forem organizados e acabarem as posições o j = -1;
 * então ele é atribuido lista[j+1] = elemento_chave
 * fazendo então que a primeira posição receba o 0.
 * 
*/

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
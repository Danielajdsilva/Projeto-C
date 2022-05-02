#include<stdio.h>
#include<stdlib.h>
#include<time.h>


/*
*   O BUBBLE SORT pode ser considerado o mais simples entre os algoritmos de comparação;
*   Complexidade O(n²) ele é executado com a lógica de n-1.
*   Este algoritmo é considerado instavel pois mantem a ordem dos iguais.
*/

/*
*   Iniciamos o algorítmo recebendo ou criando uma lista, tanto pelo próprio código ou um arquivo a ser ordenado.
*   Nesse caso a lista é criada na função "main" e executada a ordenação dentro da função "bubbleSort".
*/

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

    /*   
    *   
    *   O primeiro laço de repetição é um contador que conta de 0 até n-1,
    *   que vai do primeiro até o penultimo número.
    *   No laço for interno realiza um procedimento que faz referência das posições dentro da lista.
    *   Na condição if compara então um elemento com o elemento ao lado. 
    *   Se o primeiro é maior que o segundo realiza a troca. Se não, repete o laço e verifica-se os numeros seguintes.
    *   
    *   No inicio declaramos uma variável para saber se houve ou não uma troca.
    *   Se hover a troca a lista será executada novamente pelo contador.
    *   O segundo if verifica se houve ou não uma troca, se houve troca o laço do contador continua.
    *   Caso de não haver trocas o laço será quebrado, sem precisar de mais repetições.
    * 
    *   Melhor caso é haver 0 trocas, pois o laço de repetição apenas irá verificar a lista uma vez e quebrará o laço do contador.
    *   No pior caso o laço contador repetirá n vezes e o laço interno também verificará n vezes.
    */

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


#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*
*   Iniciamos o algorítmo recebendo ou criando uma lista, tanto pelo próprio código ou um arquivo a ser ordenado.
*   Nesse caso a lista é criada na função "main" e executada a ordenação dentro da função "bubbleSort".
*/

int main(){
    srand (time(NULL));

    int i, n=10;
    int *lista = malloc(n * sizeof(int));

    for(i=0;i<n;i++){
        lista[i] = rand() % 10;
    }

    /****
     * No início, assumimos que o menor elemento está no índice 0.
     * iniciamos a partir do segundo índice comparando os elementos.
     * Na primeira execução ele encontrará o menor valor da lista.
     * após encontrado ele será setado como a posição [0]
     * e após essa execução ele não percorrerá mais o item [0] da lista
     * e ordenará o menor número depois do anterior encontrado e assim por diante.
     * 
     * O if somente será executado caso o lista[menor] não seja maior que qualquer outra posição da lista
     */

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
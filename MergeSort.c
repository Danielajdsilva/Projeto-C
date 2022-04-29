#include<stdlib.h>
#include<stdio.h>
// Merge Function


void merge(int lista[], int inicio, int meio, int fim){
  int i, j, k;

  /***
   * Cria a variável L = lista[p..q] e R ← lista[q+1..r]
   * Criando assim uma matriz de dois números(conjunto) para serem ordenados
   * 
  */ 

  int n1 = meio - inicio + 1;
  int n2 = fim - meio;
  int L[n1], R[n2];
  for (i = 0; i < n1; i++)
    L[i] = lista[inicio + i];
  for (j = 0; j < n2; j++)
    R[j] = lista[meio + 1+ j];


    /*
     * Logo em seguida mantém o índice atual do conjunto formado pela função acima
     * e da matriz principal designada pelo k que será formada após as comparações.
     * 
     * 
    */

    i = 0; //topo de i
    j = 0; // topo de j
    k = inicio;

    /*
     * Até chegar ao final de L ou R,
     * O while escolhe o maior entre os elementos L e R e coloca na posição correta na lista
     * O "i" e "j" significam tambem o topo de suas listas.
    */
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            lista[k] = L[i];
            i++;
        }else{
            lista[k] = R[j];
            j++;
        }
    k++;
    }

    /*
     * Quando ficarmos sem elementos em L ou R, esse while pega os elementos restantes e coloca na lista
    */ 
    while (i < n1){
        lista[k] = L[i];
        i++;
        k++; 
    }
/*
 * Esse while sai do loop anterior porque i < n1 não é válido
*/
    while (j < n2){
        lista[k] = R[j];
        j++;    
        k++;
    }
}

/*
 * Nesse bloco o Merge faz a separação dos blocos inicio, fim e meio
 * dividimos o vetor em duas partes
 * se o inicio for menor que o final
 * o fim sempre inicia com o vetor inteiro, pois o parametro passado no main 
 * para que possamos fazer a divisão
 * então como o fim sempre inicia com o maior valor, fazemos uma divisão do vetor por 2
 * assim passando os paramêtros para a função merge
 * 
 * A função mergeSort divide repetidamente o array em duas metades
 * até chegarmos a um estágio em que tentamos executar MergeSort em um caso de tamanho 1
 * 
*/
void mergeSort(int lista[], int inicio, int fim){
    if (inicio < fim){
        int meio = (fim+inicio)/2;
        mergeSort(lista, inicio, meio);
        mergeSort(lista, meio+1, fim);
        merge(lista, inicio, meio, fim);
    }
}

//Função apenas para imprimir uma lista na tela
void printArray(int A[], int size){
    int i;
    for (i=0; i < size; i++)
        printf("%d, ", A[i]);
        printf("\n");
    }

int main(void){
    srand (time(NULL));

    int n = 5, *arr[n];
    
    for(int i=0;i<n;i++){
        arr[i] = rand() % 20;
    }

    int arr_size = sizeof(arr)/sizeof(arr[0]);

    mergeSort(arr, 0, arr_size - 1);

    printf("\nNUMEROS ORDENADOS:: \n");
    printArray(arr, arr_size);
    return 0;
}

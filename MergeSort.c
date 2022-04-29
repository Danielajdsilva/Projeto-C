#include<stdlib.h>
#include<stdio.h>
// Merge Function


void merge(int lista[], int inicio, int meio, int fim){
  int i, j, k;


  int n1 = meio - inicio + 1;
  int n2 = fim - meio;
  int L[n1], R[n2];
  for (i = 0; i < n1; i++)
    L[i] = lista[inicio + i];
  for (j = 0; j < n2; j++)
    R[j] = lista[meio + 1+ j];


    i = 0; 
    j = 0; 
    k = inicio;

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

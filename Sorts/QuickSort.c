// Quick sort in C

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int array[], int low, int high) {
  
  int pivot = array[high];
  int i = (low - 1);

  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }

  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    int pi = partition(array, low, high);
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}

void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

int main() {
  srand (time(NULL));

  int size = 10;
  int *data = (int *) malloc(size *sizeof(int));
  
  int n = sizeof(data) / sizeof(data[0]);
  
  for (int i = 0; i < size; i++) {
    data[i] = rand() % 100;
  }
  
  // perform quicksort on data
  quickSort(data, 0, size - 1);
  
  printf("NUMEROS ORDENADOS \n");
  printArray(data, size);
}
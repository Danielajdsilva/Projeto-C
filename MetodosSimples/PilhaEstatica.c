#include <stdio.h>
#include <stdlib.h>

#define MAXTAM 5

int count = 0;

typedef struct{
    int item[MAXTAM];
    int topo;
}tPilha;

void tPilha_Inicia(tPilha *p){
    p-> topo = -1; 
}


int tPilha_Vazia(tPilha *p){
    if(p->topo == -1){
        return 1;
    } else {
        return 0;
    }
}


int tPilha_Cheia(tPilha *p){
    if(p->topo == MAXTAM-1){
        return 1;
    } else {
        return 0;
    }
}


void tPilha_Insere(tPilha *p, int novoItem){
    if(tPilha_Cheia(p) == 1){
        printf("\nERRO: A pilha esta cheia.\n");
    }else{
        p->topo++;
        p->item[p->topo] = novoItem;
        count++;
    }
    
}

void tPilha_Remove(tPilha *p){
  
    if(tPilha_Vazia(p) == 1){
        printf("\nERRO: A pilha esta vazia.\n");
    } else {
        printf("\nItem removido = %d", p->item[p->topo]);
        p-> topo--;    
        count--;    
    }
    
    printf("\n");
}

void tPilha_Print(tPilha *p) {
  
  for (int i = 0; i < count; i++) {
    printf("%d ", p->item[i]);
  }
  printf("\n");
}

int main() {

    tPilha *p = (tPilha*)malloc(sizeof(tPilha));
    
    tPilha_Inicia(p);

    int inserir_n = 1;
    int remover_n = 1;

    for (int i = 0; i < inserir_n; i++) {
       int novo_numero = rand() % 100;
        tPilha_Insere(p,novo_numero);    
    }    

    printf("Pilha Anterior: ");
    tPilha_Print(p);

    for (int i = 0; i < remover_n; i++) {
    tPilha_Remove(p);
    }

    printf("\nPilha atual: \n");
    tPilha_Print(p);

}

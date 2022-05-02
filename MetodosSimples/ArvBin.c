#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *direita, *esquerda;
}NoArv;

/*
      função para remover nós da Árvore binária
*/
/*
     função para remover nós folhas ou com um filho da Árvore binária
*/
NoArv* remover(NoArv *raiz, int chave) {
    if(raiz == NULL){
        printf("Valor nao encontrado!\n");
        return NULL;
    } else { // procura o nó a remover
        if(raiz->valor == chave) {
            // remove nós folhas (nós sem filhos)
            if(raiz->esquerda == NULL && raiz->direita == NULL) {
                free(raiz);
                printf("Elemento folha removido: %d !\n", chave);
                return NULL;
            }
            else{
                // remover nós que possuem 2 filhos
                if(raiz->esquerda != NULL && raiz->direita != NULL){
                    /// pode ser direita ou esqueda, se for esquerda aux-> direita se for direita aux->esqueda no WHILE
                    NoArv *aux = raiz->esquerda; // subárvore à esquerda
                    while(aux->direita != NULL){
                        aux = aux->direita;  // obtêm o nó mais a direita
                    }
                    //troca de elementos.
                    raiz->valor = aux->valor;
                    aux->valor = chave;
                    printf("Elemento trocado: %d !\n", chave);
                    raiz->esquerda = remover(raiz->esquerda, chave);
                    return raiz;
                }
                else{
                    // remover nós que possuem apenas 1 filho
                    NoArv *aux;
                    if(raiz->esquerda != NULL)
                        aux = raiz->esquerda;
                    else
                        aux = raiz->direita;
                    free(raiz);
                    printf("Elemento com 1 filho removido: %d !\n", chave);
                    return aux;
                }
            }
        } else {
            if(chave < raiz->valor){
                raiz->esquerda = remover(raiz->esquerda, chave);
            } else{
                raiz->direita = remover(raiz->direita, chave);
            }
            return raiz;
        }
    }
}


void inserir(NoArv **raiz, int num){
  NoArv *aux = *raiz;
  while(aux){
    if(num < aux->valor){
      raiz = &aux->esquerda;
    }else{
      raiz = &aux->direita;
    }
    aux = *raiz;
  }
  aux = malloc(sizeof(NoArv));
  aux->valor = num;
  aux->esquerda = NULL;
  aux->direita = NULL;
  *raiz = aux;
}


NoArv* buscar(NoArv *raiz, int num){
    while(raiz){
        if(num < raiz->valor){
            raiz = raiz->esquerda;
        }else if(num > raiz->valor){
            raiz = raiz->direita;
        }else{
            return raiz;
        }
    }
    return NULL;
}

int altura(NoArv *raiz){
    if(raiz == NULL){
        return -1;
    }
    else{
        int esq = altura(raiz->esquerda);
        int dir = altura(raiz->direita);
        if(esq > dir){
            return esq + 1;
        }else{
            return dir + 1;
        }
    }
}

int quantidade_nos(NoArv *raiz){
    if(raiz == NULL)
        return 0;
    else
        return 1 + quantidade_nos(raiz->esquerda) + quantidade_nos(raiz->direita);

    // operador ternário
    //return (raiz == NULL)? 0: 1 + quantidade_nos(raiz->esquerda) + quantidade_nos(raiz->direita);
}

int quantidade_folhas(NoArv *raiz){
    if(raiz == NULL){
        return 0;
    }else if(raiz->esquerda == NULL && raiz->direita == NULL){
        return 1;
    }else{
        return quantidade_folhas(raiz->esquerda) + quantidade_folhas(raiz->direita);
    }
}

void imprimir(NoArv *raiz){
    if(raiz){
        imprimir(raiz->esquerda);
        printf("%d ", raiz->valor);
        imprimir(raiz->direita);
    }
}

int main(){
    NoArv *busca, *raiz = NULL;
    int opcao, valor;

    do{
        printf("\n\t0 - Sair\t1 - Inserir\t2 - Imprimir\t3 - Buscar\n");
        printf("\t4 - Altura\t5 - Tamanho\t6 - Folhas\t7 - Remover");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            printf("\n\tDigite um valor: ");
            scanf("%d", &valor);
            inserir(&raiz, valor);
            break;
        case 2:
            printf("\n\tSegunda impressao:\n\t");
            imprimir(raiz);
            printf("\n");
            break;
        case 3:
            printf("\n\tDigite o valor a ser procurado: ");
            scanf("\n\t%d", &valor);
            busca = buscar(raiz, valor);
            if(busca)
                printf("\n\tValor encontrado: %d\n", busca->valor);
            else
                printf("\n\tValor nao encontrado!\n");
            break;
        case 4:
            printf("\n\tAltura da arvore: %d\n\n", altura(raiz));
            break;
        case 5:
            printf("\n\tQuantidade de nos: %d\n", quantidade_nos(raiz));
            break;
        case 6:
            printf("\n\tQuantidade folhas: %d\n", quantidade_folhas(raiz));
            break;
        case 7:
            printf("\t");
            imprimir(raiz);
            printf("\n\tDigite o valor a ser removido: ");
            scanf("%d",&valor);
            raiz = remover(raiz, valor);
            break;
        default:
            if(opcao != 0)
                printf("\n\tOpcao invalida!!!\n");
        }
    }while(opcao != 0);

    return 0;
}
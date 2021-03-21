#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct no{
    int info;
    struct no *ant;
    struct no *prox;
};

Lista cria_lista(){
    return NULL;
}

int lista_vazia(Lista lst){
    if(lst == NULL){
        return 1;   //Lista vazia
    }
    return 0;       //lista nao vazia
}

int insere_elemento(Lista *lst, int elemento){      //Insere no inicio da Lista
    Lista N = (Lista) malloc(sizeof(struct no));
    if(N == NULL){
        return 0;       //Nao foi possivel inserir o elemento.
    }
    N->info = elemento;
    N->prox = *lst;
    N->ant = NULL;
    if(lista_vazia(*lst) == 0){         //Caso em que a lista não é vazia
        (*lst)->ant = N;            
    }
    *lst = N;
    return 1;       //Elemento inserido com sucesso
}

int remove_elemento(Lista *lst, int elemento){     //Procura o elemento para remover
    if(lista_vazia(*lst) == 1){
        return 0;                   //Nao é possivel remover o elemento     
    }
    Lista aux = *lst;
    while(aux->info != elemento && aux->prox != NULL){
        aux = aux->prox;
    }
    if(aux->info != elemento){
        return 0;       //Elemento nao esta na lista
    }
    if(aux->ant != NULL){           //Elemento nao é o primeiro da lista
        aux->ant->prox = aux->prox;
    }
    if(aux->prox != NULL){          //Elemento nao é o ultimo da lista
        aux->prox->ant = aux->ant;
    }
    if(aux == *lst){            //Elemento é o primeiro da lista
        *lst = aux->prox;
    }
    free(aux);
    return 1;       //Elemento removido com sucesso
}

void imprime(Lista lst){
    if(lista_vazia(lst) == 1){
        printf("Vazia.\n");
    }else{
        Lista aux = lst;
        while(aux != NULL){
            printf("%d ", aux->info);
            aux = aux->prox;
        }
        printf("\n");
    }
}
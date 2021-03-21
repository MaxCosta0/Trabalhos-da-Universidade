/*Deque Dinamica Encadeada*/
#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

struct no{
    int info;
    struct no  *prox;
    struct no *ant;
};

struct deque{
    struct no *inicio;
    struct no *fim;
};

Deque cria_deque(){
    Deque d = (Deque) malloc(sizeof(struct deque));
    if(d != NULL){
        d->inicio = NULL;
        d->fim = NULL;
    }
    return d;
}

int deque_vazia(Deque d){
    if(d->inicio == NULL){
        return 1;
    }
    return 0;
}

int insere_inicio(Deque d, int elemento){
    struct no* N = (struct no*) malloc(sizeof(struct no));
    if(N == NULL){
        return 0;
    }
    N->info = elemento;
    N->ant = NULL;
    N->prox = d->inicio;
    if(deque_vazia(d) == 1){
        d->fim = N;
    }else{
        d->inicio->ant = N;
    }
    d->inicio = N;
    return 1;
}


int insere_fim(Deque d, int elemento){
    struct no* N = (struct no*) malloc(sizeof(struct no));
    if(N == NULL){
        return 0;
    }
    N->info = elemento;
    N->ant = d->fim;
    N->prox = NULL;
    if(deque_vazia(d) == 1){
        d->inicio = N;
    }else{
        d->fim->prox = N;
    }    
    d->fim = N;
    return 1;
}

int remove_inicio(Deque *d, int* elemento){
    if(deque_vazia(*d) == 1){
        return 0;
    }
    struct no* aux = (*d)->inicio;
    *elemento = aux->info;
    (*d)->inicio = aux->prox;
    (*d)->inicio->ant = aux->ant;
    free(aux);
    return 1;
}

int remove_fim(Deque *d, int* elemento){
    if(deque_vazia(*d) == 1){
        return 0;
    }
    struct no* aux = (*d)->fim;
    *elemento = aux->info;
    (*d)->fim = aux->ant;
    (*d)->fim->prox = aux->prox;
    free(aux);
    return 1;
}

void imprime(Deque d){
    if(deque_vazia(d) == 1){
        printf("Vazia.\n");
    }else{
        struct no* aux = d->inicio;
        while(aux != NULL){
            printf("%d ", aux->info);
            aux = aux->prox;
        }
        printf("\n");
    }
}
/*Pilha Dinamica Encadeada*/
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct no{
    int info;
    struct no *prox;
};

Pilha cria_pilha(){
    return NULL;
}

int pilha_vazia(Pilha p){
    if(p == NULL){
        return 1;       //Pilha vazia.
    }
    return 0;       //Pilha nao vazia.
}

int push(Pilha *p, int elemento){
    Pilha N = (Pilha) malloc(sizeof(struct no));
    if(p == NULL){
        return 0;       //Nao foi possivel empilhar o elemento.
    }
    N->info = elemento;
    N->prox = *p;
    *p = N;
    return 1;       //Elemento empilhado com sucesso.
}

int pop(Pilha *p, int *elemento){
    if(pilha_vazia(*p) == 1){
        return 0;       //Nao é possivel desempilhar uma pilha vazia
    }
    Pilha aux = *p;
    *elemento = aux->info;
    *p = aux->prox;
    free(aux);
    return 1;       //Elemento desempilhado com sucesso
}

int le_topo(Pilha *p, int *elemento){
    if(pilha_vazia(*p) == 1){
        return 0;       //Nao é possivel ler o topo de uma pilha vazia
    }
    *elemento = (*p)->info;
    return 1;       //Sucesso em ler o topo da pilha
}

void imprime(Pilha p){
    if(pilha_vazia(p) == 1){
        printf("Vazia.\n");
    }else{
        Pilha aux = p;
        while(aux != NULL){
            printf("%d ", aux->info);
            aux = aux->prox;
        }
        printf("\n");        
    }
}
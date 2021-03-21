/*Fila de prioridade ascendente*/
#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct no{
    int info;
    struct no *prox;
};

struct fila{
    struct no *inicio;
    struct no *fim;
};

Fila criar_fila(){
    Fila f = (Fila) malloc(sizeof(struct fila));
    if(f != NULL){
        f->inicio = NULL;
        f->fim = NULL;
    }
    return f;
}

int fila_vazia(Fila f){
    if(f->inicio == NULL){
        return 1;       
    }
    return 0;
}

int insere_ordenado(Fila f, int elemento){
    No N = (No) malloc(sizeof(struct no));
    if(N == NULL){
        return 0;
    }
    N->info = elemento;
    if(fila_vazia(f) == 1){
        N->prox = NULL;
        f->inicio = N;
        f->fim = N;
    }else{
        if(elemento < f->inicio->info){     //Elemento menor do que o primeiro da fila
            N->prox = f->inicio;
            f->inicio = N;
        }else if(elemento > f->fim->info){      //Elemento maior do que o ultimo da fila
            N->prox = NULL;
            f->fim->prox = N;
            f->fim = N;
        }else{                                 //Elemento no meio da fila
            No aux = f->inicio;
            while(elemento > aux->prox->info){
                aux = aux->prox;
            }
            N->prox = aux->prox;;
            aux->prox = N;
        }
    }
    return 1;
}

int remove_inicio(Fila f, int *elemento){
    if(fila_vazia(f) == 1){
        return 0;
    }
    No aux = f->inicio;
    *elemento = aux->info;
    if(aux->prox == NULL){
        f->fim = NULL;
    }
    f->inicio = aux->prox;
    free(aux);
    return 1;
}

void imprime(Fila f){
    if(fila_vazia(f) == 1){
        printf("Vazia\n");
    }else{
        No aux = f->inicio;
        while(aux != NULL){
            printf("%d ", aux->info);
            aux = aux->prox;
        }
        printf("\n");
    }
}
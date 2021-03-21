#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

#define max 20

struct pilha{
    int no[max];
    int topo;
};

Pilha cria_pilha(){
    Pilha p = (Pilha) malloc(sizeof(struct pilha));
    if(p != NULL){
        p->topo = -1;
    }
    return p;
}

int pilha_vazia(Pilha p){
    if(p->topo == -1){
        return 1;       //Pilha vazia
    }
    return 0;       //Pilha nao vazia
}

int pilha_cheia(Pilha p){
    if(p->topo == max - 1){
        return 1;       //Pilha cheia
    }
    return 0;       //Pilha nao cheia
}

int push(Pilha p, int elemento){
    if(pilha_cheia(p) == 1){
        return 0;       //Nao é possivel empilhar elemento em uma pilha cheia
    }
    p->topo++;
    p->no[p->topo] = elemento;
    return 1;       //Elemento empilhado com sucesso
}

int pop(Pilha p, int *elemento){
    if(pilha_vazia(p) == 1){
        return 0;       //Nao é possivel desempilhar uma pilha vazia
    }
    *elemento = p->no[p->topo];
    p->topo--;
    return 1;
}

int le_topo(Pilha p, int *elemento){
    if(pilha_vazia(p) == 1){
        return 0;       
    }
    *elemento = p->no[p->topo];
    return 1;
}

void imprime(Pilha p){
    int i;
    if(pilha_vazia(p) == 1){
        printf("Vazia.\n");
    }else{
        for(i = p->topo; i >= 0; i++){
            printf("%d ", p->no[i]);
        }
        printf("\n");
    }
}
/*Deque Estatica Sequencial*/

#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

#define max 20

struct deque{
    int no[max];
    int inicio, contador;
};

Deque cria_deque(){
    Deque d = (Deque) malloc(sizeof(struct deque));
    if(d != NULL){
        d->inicio = 0;
        d->contador = 0;
    } 
    return d;
}

int deque_vazia(Deque d){
    if(d->contador == 0){
        return 1;               //Deque vazia.
    }
    return 0;               //Deque nao vazia.
}

int deque_cheia(Deque d){
    if(d->contador == max){
        return 1;               //Deque cheia;
    }
    return 0;               //Deque nao cheia.
}

int insere_inicio(Deque d, int elemento){
    if(deque_cheia(d) == 1){
        return 0;
    }
    d->inicio = (d->inicio + max - 1) % max;
    d->no[d->inicio] = elemento;
    d->contador++;
    return 1;
}

int insere_fim(Deque d, int elemento){
    if(deque_cheia(d) == 1){
        return 0;
    }
    d->no[(d->inicio + d->contador) % max] = elemento;
    d->contador++;
    return 1;
}

int remove_inicio(Deque d, int* elemento){
    if(deque_vazia(d) == 1){
        return 0;
    }
    *elemento = d->no[d->inicio];
    d->inicio = (d->inicio + 1) % max;
    d->contador--;
    return 1;
}

int remove_fim(Deque d, int* elemento){
    if(deque_vazia(d) == 1){
        return 0;
    }
    *elemento = d->no[(d->inicio + d->contador - 1) % max];
    d->contador--;
    return 1;
}

void imprime(Deque d){
    if(deque_vazia(d) == 1){
        printf("Vazia.\n");
    }else{
        int i, j;
        for(i = d->inicio, j = d->contador; j > 0; i = (i + 1) % max, j--){
            printf("%d ", d->no[i]);
        }
        printf("\n");
    }
}
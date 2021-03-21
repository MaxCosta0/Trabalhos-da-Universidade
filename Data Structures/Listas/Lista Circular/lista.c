/*Lista Dinamica com Encadeamento Circular*/

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct no{
    int info;
    struct no *prox;
};

Lista cria_lista(){
    return NULL;
}

int lista_vazia(Lista lst){
    if(lst == NULL){
        return 1;       //Lista vazia.
    }
    return 0;       //Lista nao vazia.
}

int insere_fim(Lista *lst, int elemento){
    Lista N = (Lista) malloc(sizeof(struct no));
    if(N == NULL){
        return 0;   //Nao é possivel inserir o elemento
    }
    N->info = elemento;
    if(lista_vazia(*lst) == 1){
        N->prox = N;        
    }else{
        N->prox = (*lst)->prox;
        (*lst)->prox = N;
    }
    *lst = N;
    return 1;       //Elemento inserido com sucesso
}

int remove_inicio(Lista *lst, int *elemento){
    if(lista_vazia(*lst) == 1){
        return 0;       //Nao é possivel remover o elemento
    }
    Lista aux = (*lst)->prox;
    *elemento = aux->info;
    if(*lst == (*lst)->prox){
        *lst = NULL;
    }else{
        (*lst)->prox = aux->prox;
    }
    free(aux);
    return 1;       //Elemento removido com sucesso
}

void imprime(Lista lst){
    if(lista_vazia(lst) == 1){
        printf("Vazia.\n");
    }else{
        Lista aux = lst->prox;
        while(aux != lst){
            printf("%d ", aux->info);
            aux = aux->prox;
        }
        printf("%d\n", aux->info);
    }
}

//Lista vazia ++++++++ Lista com 1 elemento ++++++++ Lista com varios elementos
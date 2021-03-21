#include <stdio.h>
#include <stdlib.h>
#include "DinamicaEncadeada.h"

struct no{
    int info;
    struct no *prox;
};

Lista cria_lista(){
    return NULL;  //Vetor nao aponta pra nenhum lugar da memoria
}

int lista_vazia(Lista lst){
    if(lst == NULL){
        return 1; //Vazia
    }
    else{
        return 0; //Nao vazia
    }
}

int insere_elemento(Lista *end_lst, int elemento){
    Lista N = (Lista) malloc(sizeof(struct no));
    if(N == NULL){
        return 0; //Falha na alocação do novo nó
    }
    N->info = elemento;
    N->prox = *end_lst; //Aponta para o primeiro nó da lista (utilizando o endereço da lista).
    *end_lst = N; //Faz a lista apontar para o novo nó.
    return 1; //sucesso ao inserir o elemento.
}

int remove_elemento(Lista *end_lst, int elemento){
    if(lista_vazia(*end_lst) == 1){
        return 0; //Nao foi possivel remover o elemento.
    }
    Lista aux = *end_lst; //ponteiro auxiliar que aponta para o primeiro nó.

    if(elemento == (*end_lst)->info){
        *end_lst = aux->prox;
        free(aux);  //Libera o ponteiro auxiliar apos a remoção.
        return 1;
    }
    while(aux->prox != NULL && aux->prox->info != elemento){
        aux = aux->prox;
    }
    if(aux->prox == NULL){
        return 0; //Falha: Elemento nao esta na lista
    }
    Lista aux2 = aux->prox;
    aux->prox = aux2->prox;
    free(aux2); //Libera aux2 apos remoção.
    return 1;
}

void imprime_lista(Lista *lst){

    Lista aux = *lst;

    if(lista_vazia(lst) == 1){
        printf("A lista esta vazia.");
    }else{
        while(aux != NULL){       //Percorre a lista até o campo prox de uma struct no ser igual a NULL
            printf("%d ", aux->info);
            aux = aux->prox;        //avança para a proxima struct no.
        }
    }
    printf("\n");
}

int remove_todos(Lista *lst, int elemento){
    Lista aux, aux2;

    if(lista_vazia(*lst) == 1){
        return 0;       //Falha.
    }

    aux = *lst;
    if(aux->info == elemento){          //Tratando o caso do elemento estar no inicio da lista.
        *lst = aux->prox;
        free(aux);
        aux = *lst;
    }

    while(aux->prox != NULL){           //Tratando o caso em que o elemento esta em qualquer outra posição da lista.
        if(aux->prox->info == elemento){
            aux2 = aux->prox;
            aux->prox = aux2->prox;
            free(aux2);
        }else{
            aux = aux->prox;
        }
    }
    return 1;
}

int insere_no_final(Lista *end_lst, int elemento){
    Lista N = (Lista) malloc(sizeof(struct no));

    if(N == NULL){
        return 0;       //Falha: Nao foi possivel alocar uma struct no.
    }

    N->info = elemento;
    N->prox = NULL;

    if(lista_vazia(*end_lst) == 1){     //Inserção para lista vazia.
        *end_lst = N;
        return 1;
    }
    Lista aux = *end_lst;
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    aux->prox = N;          //Insere na ultima posição.
    return 1;       //Sucesso.

}

int remove_impares(Lista *end_lst){
    Lista aux;

    if(lista_vazia(*end_lst) == 1){
        return 0;       //Falha: A lista esta vazia.
    }

    aux = *end_lst;
    while(aux->prox != NULL){
        if(aux->prox->info % 2 != 0){
            Lista remover = aux->prox;
            aux->prox = remover->prox;
            free(remover);
        }else{
            aux = aux->prox; //Avança somente se o campo info apontado por aux nao for impar.
        }

    }
    return 1;
}

int menor(Lista lst){       //Usuario deve tratar o  caso em que lst esta vazia.
    Lista menor, aux;

    aux = lst;
    menor = lst;
    while(aux->prox != NULL){
        if(aux->info < menor->info){
            menor = aux;
        }
        aux = aux->prox;
    }
    return menor->info;
}

int tamanho(Lista lst){
    int i;
    Lista aux = lst;

    if(lista_vazia(lst) == 1){
        return 0;
    }
    for(i = 1; aux->prox != NULL; i++){
        aux = aux->prox;
    }
    return i;
}

Lista concatena(Lista *lst1, Lista *lst2){
    Lista lst3, aux;

    lst3 = cria_lista();

    aux = *lst1;
    while(aux != NULL){
        insere_no_final(&lst3, aux->info);
        aux = aux->prox;
    }
    aux = *lst2;
    while(aux != NULL){
        insere_no_final(&lst3, aux->info);
        aux = aux->prox;
    }
    return lst3;
}

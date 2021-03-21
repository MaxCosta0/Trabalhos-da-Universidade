#include <stdio.h>
#include <stdlib.h>
#include "listaOrdenada.h"

#define MAX 20

struct lista{
    int no[MAX];
    int fim;
};


Lista cria_lista(){
    Lista lst;

    lst = (Lista) malloc(sizeof(struct lista));

    if(lst != NULL){
        lst->fim = 0;
    }
    return lst;
}

int lista_vazia(Lista lst){
    if(lst->fim == 0){
        return 1;
    }
    else{
        return 0;
    }
}

int lista_cheia(Lista lst){
    if(lst->fim == MAX){
        return 1;
    }
    else{
        return 0;
    }
}

int insere_ord(Lista lst, int elemento){
    if(lst == NULL || lista_cheia(lst) == 1){
        return 0;
    }
    if(lista_vazia(lst) == 1 || elemento >= lst->no[lst->fim-1]){
        lst->no[lst->fim] = elemento;
    }
    else{
        int i, aux = 0;
        while(elemento >= lst->no[aux]){
            aux++;
        }
        for(i = lst->fim; i > aux; i--){
            lst->no[i] = lst->no[i-1];
        }
        lst->no[aux] = elemento;
    }
    lst->fim++;
    return 1;
}

int remove_ord(Lista lst, int elemento){
    if(lst == NULL || lst->fim == 0 || elemento < lst->no[0] || elemento > lst->no[lst->fim-1]){
        return 0;
    }
    else{
        int i, aux = 0;
        while(aux < lst->fim && elemento > lst->no[aux]){
            aux++;
        }
        if(aux == lst->fim || elemento > lst->no[aux]){
            return 0;
        }
        for(i = aux+1; i < lst->fim; i++){
            lst->no[i-1] = lst->no[i];
        }
        lst->fim--;
        return 1;
    }
}

void imprime_lista(Lista lst){      //O usuario deve tratar o caso em que lst == NULL.
    if(lst->fim == 0){
        printf("Lista vazia.\n");
    }
    else{
        int i;
        for(i = 0; i < lst->fim; i++){
            printf("%d ", lst->no[i]);
        }
    }
}

int remove_pares(Lista lst){
    int i, aux;

    if(lst == NULL){
        return 0;  //Falha.
    }

    for(i = 0; i < lst->fim; i++){
        if(lst->no[i] % 2 == 0){
            for(aux = i + 1;  aux < lst->fim; aux++){
                lst->no[aux - 1] = lst->no[aux];
            }
            i--;
            lst->fim--;
        }
    }
    return 1;  //Sucesso.
}

int maior(Lista lst){           //O usuario deve tratar o caso em que lst == NULL
    int i, maior = lst->no[0];

    for(i = 1; i < lst->fim; i++){
        if(lst->no[i] > maior){
            maior = lst->no[i];
        }
    }
    return maior;
}

int tamanho(Lista lst){     //O usuario deve tratar o caso em que lst == NULL.

    return lst->fim;
}

int iguais(Lista lst1, Lista lst2){     //O usuario deve tratar o caso em que lst == NULL.

    int i;

    if(lst1->fim == lst2->fim){
        for(i = 0; i < lst1->fim; i++){
            if(lst1->no[i] != lst2->no[i]){
                return 0;   //Diferentes: possuem tamanhos iguais mas elementos diferentes.
            }
        }
        return 1;   //Iguais.
    }
    return 0;   //Diferentes: possuem tamanhos diferentes.
}

Lista intercala(Lista lst1, Lista lst2){
    Lista lst3;
    int aux1 = 0, aux2 = 0, aux3 = 0;   //Poderia utilizar aux1 + aux2 ao inves de aux3, mas ficaria menos legivel.

    lst3 = cria_lista();

    if(lst3 == NULL || lst1 == NULL || lst2 == NULL){
        return NULL;
    }

    while((lst3->fim < MAX) && (aux1 < lst1->fim && aux2 < lst2->fim)){ //vai rodar enquanto os dois auxiliares forem menores do que a posição final de suas respectivas listas e
                                                                        //o vetor nó da lista 3 conseguir guardar os elementos (estatica sequencial permite que a lista fique cheia).
        if((aux1 < lst1->fim) && (lst1->no[aux1] <= lst2->no[aux2])){
            lst3->no[aux3] = lst1->no[aux1];
            aux3++;
            aux1++;
            lst3->fim++;

        }else if((aux2 < lst2->fim) && (lst2->no[aux2] < lst1->no[aux1])){
            lst3->no[aux3] = lst2->no[aux2];
            aux3++;
            aux2++;
            lst3->fim++;
        }
    }

    //Tratamento para o ultimo elemento da lista que nao pode ser tratado acima pois
    //estariamos comparando um elemento da lista com o valor do fim da lista.
     if(aux1 < lst1->fim){
        while(aux1 < lst1->fim){
            lst3->no[aux3] = lst1->no[aux1];
            aux3++;
            aux2++;
            lst3->fim++;
        }

    }
    if(aux2 < lst2->fim){
        while(aux2 < lst2->fim){
            lst3->no[aux3] = lst2->no[aux2];
            aux3++;
            aux2++;
            lst3->fim++;
            }
    }

    return lst3;
}

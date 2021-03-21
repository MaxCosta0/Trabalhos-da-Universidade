#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

#define TAM 20

struct lista{
    int no[TAM];
    int fim;
};

Lista cria_lista(){
    Lista lst;

    lst = (Lista) malloc(sizeof(struct lista));
    if(lst != NULL)
        lst->fim = 0;
    return lst;
}

int lista_vazia(Lista lst){
    if(lst->fim == 0){
        return 1;
    }
    return 0;
}

int lista_cheia(Lista lst){
    if(lst->fim == TAM){
        return 1;
    }
    return 0;
}

int insere_elemento(Lista lst, int elemento){
    if(lst == NULL || lst->fim == TAM){
        return 0;
    }
    lst->no[lst->fim] = elemento;
    lst->fim++;
    return 1;
}

int remove_elemento(Lista lst, int elemento){
    int i, aux = 0;

    if(lst == NULL || lst->fim == 0){
        return 0;
    }

    while(aux < TAM && lst->no[aux] != elemento){
        aux++;
    }

    for(i = aux+1; i < lst->fim; i++){
        lst->no[i-1] = lst->no[i];
    }
    lst->fim--;
    return 1;

}

void imprime_lista(Lista lst){
    int i;

    if(lista_vazia(lst) == 1){
            printf("Lista vazia.\n");
            printf("Fim da lista %d\n", lst->fim);

    }else{

        for(i = 0; i < lst->fim; i++){
            printf("%d ", lst->no[i]);
        }
        printf("\nFim da lista %d\n", lst->fim);
        printf("\n");
    printf("\n");

    }
}

int remove_todos(Lista lst, int elemento){
    int i, aux = 0;

    if(lst == NULL || lst->fim == 0){
        return 0;
    }

    while(aux < lst->fim){
        if(lst->no[aux] == elemento){
            for(i = aux + 1; i < lst->fim; i++){
                lst->no[i - 1] = lst->no[i];
            }
            aux--;
            lst->fim--;
        }
        aux++;
   }
    return 1;
}

int insere_no_inicio(Lista lst, int elemento){
    int i;

    if(lst == NULL || lst->fim == TAM){
        return 0;
    }

    for(i = lst->fim; i >= 0; i--){
        lst->no[i] = lst->no[i-1];
    }

    lst->no[0] = elemento;
    lst->fim ++;
    return 1;
}

int remove_impares(Lista lst){
    int i, aux;

    if(lst == NULL || lst->fim == 0){
        return 0; //Falha
    }

    for(i = 0; i < lst->fim; i++){
        aux = lst->no[i];
        if(aux % 2 != 0){
            remove_elemento(lst, lst->no[i]);   //Sempre que remover um elemento, todos os elementos à direita do retirado terão suas suas posições
            i--;                           // atualizadas em 1 casa à esquerda, entao devemos manter o indice parado sempre que removermos um elemento.
        }
    }
    return 1;
}

int menor(Lista lst){
    int i, menor;

    menor = lst->no[0];
    for(i = 0; i < lst->fim; i++){
        if(lst->no[i] < menor){
            menor = lst->no[i];
        }
    }
    return menor;
}

int tamanho(Lista lst){

    if(lst->fim == 0){
        return 0; //Lista possui zero elementos.
    }
    return lst->fim; //retorna o tamanho de uma lista com 1 ou mais elementos.
}

Lista concatena(Lista lst1, Lista lst2){
    int i, aux;
    Lista lst3;

    lst3 = cria_lista();

    for(i = 0; i < lst1->fim; i++){
        lst3->no[lst3->fim] = lst1->no[i];
        lst3->fim++;
    }

    aux = i;
    for(i = 0; aux < TAM && i < lst2->fim; i++, aux++){  //impede o overflow da lista 3, limitando a concatenação à somente 20 elementos.
        lst3->no[lst3->fim] = lst2->no[i];
        lst3->fim++;
    }

    return lst3;
}

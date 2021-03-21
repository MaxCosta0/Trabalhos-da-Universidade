#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

#define TAM 20

int main()
{
    Lista lst1, lst2, lst3;
    int i, aleatorio;

    printf("=================================CRIA LISTA VAZIA===============================\n");

    lst1 = cria_lista();
    lst2 = cria_lista();

    if(lst1 == NULL){
        printf("Nao foi possivel alocar memoria para o ponteiro lst: \n");
        return -1;
    }
    if(lst2 == NULL){
        printf("Nao foi possivel alocar memoria para o ponteiro lst2: \n");
        return -1;
    }

    printf("\nLista 1: ");
    imprime_lista(lst1);
    printf("\nLista 2: ");
    imprime_lista(lst2);

    printf("===============================ATRIBUI VALORES==================================\n");

    for(i = 0 ; i < TAM; i++){
        aleatorio = rand() % 10;
        insere_elemento(lst1, aleatorio);
    }


    for(i = 0 ; i < TAM; i++){
        aleatorio = rand() % 100;
        insere_elemento(lst2, aleatorio);
    }

    printf("\nLista 1: ");
    imprime_lista(lst1);

    printf("\nLista 2: ");
    imprime_lista(lst2);

    printf("================================REMOVE UM ELEMENTO=============================\n");

    remove_elemento(lst1, 8);
    printf("\nLista 1: ");
    imprime_lista(lst1);


    printf("\nLista 2: ");
    imprime_lista(lst2);

    printf("==========================INSERE UM ELEMENTO NO INICIO==========================\n");

    insere_no_inicio(lst1, 5);
    printf("\nLista 1: ");
    imprime_lista(lst1);

    printf("\nLista 2: ");
    imprime_lista(lst2);

    printf("================================REMOVE OS ÍMPARES==============================\n");

    remove_impares(lst1);
    printf("\nLista 1: ");
    imprime_lista(lst1);

    //remove_impares(lst2);
    printf("\nLista 2: ");
    imprime_lista(lst2);

    printf("============================ENCONTRA O MENOR ELEMENTO===========================\n");

    printf("Menor elemento da lista 1: %d\n", menor(lst1));
    printf("Tamanho da lista 1: %d\n", tamanho(lst1));

    printf("\nMenor elemento da lista 2: %d\n", menor(lst2));
    printf("Tamanho da lista 2: %d\n", tamanho(lst2));

    printf("==============================CONCATENA DUAS LISTAS=============================\n");

    printf("Lista 1: ");
    imprime_lista(lst1);

    printf("Lista 2: ");
    imprime_lista(lst2);

    lst3 = concatena(lst1, lst2);
    printf("Lista 3: ");
    imprime_lista(lst3);

    printf("================================REMOVE TODOS====================================\n");

    remove_todos(lst1, 6);
    printf("\nLista 1: ");
    imprime_lista(lst1);


    free(lst1);
    free(lst2);
    free(lst3);
    return 0;
}

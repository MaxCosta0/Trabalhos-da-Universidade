#include <stdio.h>
#include <stdlib.h>
#include "DinamicaEncadeada.h"

int main()
{
    Lista lst1, lst2, lst3;

    printf("===================CRIA LISTA===========================\n");
    lst1 = cria_lista();
    imprime_lista(&lst1);

    printf("Tamanho da lista 1: %d\n", tamanho(lst1));

    lst2 = cria_lista();
    imprime_lista(&lst2);

    printf("\nTamanho da lista 2: %d\n\n", tamanho(lst2));

    printf("===================INSERE ELEMENTO======================\n");

    insere_elemento(&lst1, 4);
    insere_elemento(&lst1, 8);
    insere_elemento(&lst1, 4);
    insere_elemento(&lst1, 19);
    insere_elemento(&lst1, 2);
    insere_elemento(&lst1, 7);
    insere_elemento(&lst1, 4);
    insere_elemento(&lst1, 22);
    insere_elemento(&lst1, 8);

    insere_elemento(&lst2, 5);
    insere_elemento(&lst2, 9);
    insere_elemento(&lst2, 1);
    insere_elemento(&lst2, 5);
    insere_elemento(&lst2, 3);
    insere_elemento(&lst2, 8);
    insere_elemento(&lst2, 5);
    insere_elemento(&lst2, 23);
    insere_elemento(&lst2, 9);

    imprime_lista(&lst1);
    printf("Tamanho da lista 1: %d\n\n", tamanho(lst1));

    imprime_lista(&lst2);
    printf("Tamanho da lista 2: %d\n\n", tamanho(lst2));

    printf("===================REMOVE ELEMENTO======================\n");

    remove_elemento(&lst1, 8);
    imprime_lista(&lst1);
    printf("Tamanho da lista 1 apos remocao do elemento escolhido: %d\n\n", tamanho(lst1));

    remove_elemento(&lst2, 9);
    imprime_lista(&lst2);
    printf("Tamanho da lista 2 apos remocao do elemento escolhido: %d\n\n", tamanho(lst2));

    printf("=====================REMOVE TODOS========================\n");

    remove_todos(&lst1, 4);
    printf("Lista 1: ");
    imprime_lista(&lst1);
    printf("\n");

    remove_todos(&lst2, 5);
    printf("Lista 2: ");
    imprime_lista(&lst2);
    printf("\n");

    printf("===================INSERIR NO FINAL======================\n");

    insere_no_final(&lst1, 15);
    printf("Lista 1: ");
    imprime_lista(&lst1);
    printf("\n");

    insere_no_final(&lst1, 7);
    printf("Lista 1: ");
    imprime_lista(&lst1);
    printf("\n");

    printf("====================REMOVE IMPARES======================\n");

    remove_impares(&lst1);
    printf("Lista 1: ");
    imprime_lista(&lst1);
    printf("\n");


    remove_impares(&lst2);
    printf("Lista 2: ");
    imprime_lista(&lst2);
    printf("\n");


    printf("=========================MENOR==========================\n");

    if(lista_vazia(lst1) != 1){
        printf("O menor elemento da lista 1 e: %d\n", menor(lst1));
    }


    if(lista_vazia(lst2) != 1){
        printf("\nO menor elemento da lista 2 e: %d\n\n", menor(lst2));
    }

    printf("========================CONCATENA========================\n");
    printf("Lista 1: ");
    imprime_lista(&lst1);
    printf("\n");

    printf("Lista 2: ");
    imprime_lista(&lst2);
    printf("\n");

    lst3 = concatena(&lst1, &lst2);
    printf("Lista 3: ");
    imprime_lista(&lst3);
    printf("\n");




    free(lst1);
    free(lst2);
    free(lst3);
    return 0;
}

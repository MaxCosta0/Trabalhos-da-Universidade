#include <stdio.h>
#include <stdlib.h>
#include "listaOrdenada.h"


int main()
{
    Lista lst1, lst2, lst3;

    printf("====================CRIA LISTA====================\n");

    lst1 = cria_lista();
    printf("Lista 1: ");
    imprime_lista(lst1);
    printf("\n");

    lst2 = cria_lista();
    printf("Lista 2: ");
    imprime_lista(lst2);
    printf("\n");

    printf("====================INSERE ORDENADO====================\n");

    insere_ord(lst1, 4);
    insere_ord(lst1, 8);
    insere_ord(lst1, -1);
    insere_ord(lst1, 19);
    insere_ord(lst1, 2);
    insere_ord(lst1, 7);
    insere_ord(lst1, 8);
    insere_ord(lst1, 5);
    insere_ord(lst1, 9);
    insere_ord(lst1, 22);
    insere_ord(lst1, 17);

    insere_ord(lst2, 1);
    insere_ord(lst2, 3);
    insere_ord(lst2, 7);
    insere_ord(lst2, 19);
    insere_ord(lst2, 9);
    insere_ord(lst2, 11);
    insere_ord(lst2, 8);
    insere_ord(lst2, 5);
    insere_ord(lst2, 9);
    insere_ord(lst2, 67);
    insere_ord(lst2, 45);

    printf("Lista 1: ");
    imprime_lista(lst1);
    printf("\n");

    printf("Lista 2: ");
    imprime_lista(lst2);
    printf("\n \n");


    printf("====================REMOVE ORDENADO====================\n");

    remove_ord(lst1, 8);
    printf("Lista 1: ");
    imprime_lista(lst1);
    printf("\n");

    remove_ord(lst2, 9);
    printf("Lista 2: ");
    imprime_lista(lst2);
    printf("\n \n");


    printf("====================REMOVE PARES====================\n");

    remove_pares(lst1);
    printf("Lista 1: ");
    imprime_lista(lst1);
    printf("\n");

    remove_pares(lst2);
    printf("Lista 2: ");
    imprime_lista(lst2);
    printf("\n\n");

    printf("==========================Maior==========================\n");

    if(lst1 != NULL){
        printf("Maior elemento da lista 1: %d\n", maior(lst1));
    }else{
        printf("ERRO: A lista 1 nao esta alocada.");
    }

    if(lst2 != NULL){
        printf("Maior elemento da lista 2: %d\n", maior(lst2));
    }else{
        printf("ERRO: A lista 2 nao esta alocada.");
    }


    printf("==========================TAMANHO==========================\n");

    if(lst1 != NULL){
        printf("Tamanho da lista 1: %d\n", tamanho(lst1));
    }

    if(lst2 != NULL){
        printf("Tamanho da lista 2: %d\n", tamanho(lst2));
    }

    printf("=========================IGUAIS=========================\n");

    if(lst1 != NULL && lst2 != NULL){
        if(iguais(lst1, lst2) == 1){
            printf("Sao Iguais.\n");
        }else{
            printf("Sao Diferentes.\n");
        }
    }else{
        printf("ERRO: Uma lista nao esta alocada.");
    }


    printf("=========================INTERCALA=========================\n");

    printf("Lista 1: ");
    imprime_lista(lst1);

    printf("\nLista 2: ");
    imprime_lista(lst2);

    lst3 = intercala(lst1, lst2);
    printf("\nLista 3: ");
    imprime_lista(lst3);
    printf("\n\n");

    return 0;
}

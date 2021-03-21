#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){

    int elemento;

    printf("====================CRIA LISTA====================\n");
    Lista lst = cria_lista();
    printf("Lista: ");
    imprime(lst);

    printf("====================INSERE NO FIM====================\n");
    insere_fim(&lst, 4);
    insere_fim(&lst, 7);
    insere_fim(&lst, 2);

    printf("Lista: ");
    imprime(lst);

    printf("====================REMOVE NO INICIO====================\n");
    remove_inicio(&lst, &elemento);
    printf("Elemento removido: %d\n", elemento);
    printf("Lista: ");
    imprime(lst);

    remove_inicio(&lst, &elemento);
    printf("Elemento removido: %d\n", elemento);
    printf("Lista: ");
    imprime(lst);
    
    remove_inicio(&lst, &elemento);
    printf("Elemento removido: %d\n", elemento);
    printf("Lista: ");
    imprime(lst);

    return 0;
}
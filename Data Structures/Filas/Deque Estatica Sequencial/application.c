#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

int main(){

    int elemento;

    printf("=========================CRIA DEQUE=========================\n");
    Deque d = cria_deque();
    printf("Deque: ");
    imprime(d);

    printf("=========================INSERE INICIO=========================\n");
    insere_inicio(d, 5);
    insere_inicio(d, 15);    
    insere_inicio(d, 9);
    insere_inicio(d, 3);

    printf("Deque: ");
    imprime(d);

    printf("=========================INSERE FIM=========================\n");
    insere_fim(d, 67);
    insere_fim(d, 7);
    insere_fim(d, 1);
    insere_fim(d, 2);

    printf("Deque: ");
    imprime(d);

    printf("=========================REMOVE INICIO=========================\n");
    remove_inicio(d, &elemento);
    printf("Elemento removido: %d\n", elemento);
    printf("Deque: ");
    imprime(d);

    remove_inicio(d, &elemento);
    printf("Elemento removido: %d\n", elemento);
    printf("Deque: ");
    imprime(d);

    printf("=========================REMOVE FIM=========================\n");
    remove_fim(d, &elemento);
    printf("Elemento removido: %d\n", elemento);
    printf("Deque: ");
    imprime(d);

    remove_fim(d, &elemento);
    printf("Elemento removido: %d\n", elemento);
    printf("Deque: ");
    imprime(d);

    return 0;
}
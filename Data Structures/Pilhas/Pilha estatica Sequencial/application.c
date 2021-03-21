#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(){
    int elemento;

    printf("=========================CRIA PILHA=========================\n");
    Pilha p = cria_pilha();
    printf("Pilha: ");
    imprime(p);

    printf("=========================EMPILHA==========================\n");
    push(p, 4);
    push(p, 7);
    push(p, 12);
    push(p, 45);
    push(p, 2);
    push(p, 1);

    printf("Pilha: ");
    imprime(p);

    printf("=========================LE TOPO==========================\n");
    le_topo(p, &elemento);
    printf("Elemento do topo: %d\n", elemento);

    printf("=========================DESEMPILHA==========================\n");
    pop(p, &elemento);
    printf("Elemento desempilhado: %d\n", elemento);
    printf("Pilha: ");
    imprime(p);

    printf("\n");

    pop(p, &elemento);
    printf("Elemento desempilhado: %d\n", elemento);
    printf("Pilha: ");
    imprime(p);

    printf("\n");

    pop(p, &elemento);
    printf("Elemento desempilhado: %d\n ", elemento);
    printf("Pilha: ");
    imprime(p);

    printf("=========================LE TOPO==========================\n");
    le_topo(p, &elemento);
    printf("Elemento do topo: %d\n", elemento);

    return 0;
}
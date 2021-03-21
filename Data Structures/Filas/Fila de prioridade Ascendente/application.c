#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(){

    int elemento;

    printf("====================CRIA FILA====================\n");
    Fila f = criar_fila();
    printf("Fila: ");
    imprime(f);

    printf("====================INSERE ORDENADO====================\n");
    insere_ordenado(f, 4);
    insere_ordenado(f, 7);
    insere_ordenado(f, 2);
    insere_ordenado(f, 9);
    insere_ordenado(f, 12);
    insere_ordenado(f, 1);

    printf("Fila: ");
    imprime(f);

    printf("====================REMOVE NO INICIO====================\n");
    remove_inicio(f, &elemento);
    printf("Elemento removido: %d\n", elemento);
    printf("Fila: ");
    imprime(f);

    printf("\n");

    remove_inicio(f, &elemento);
    printf("Elemento removido: %d\n", elemento);
    printf("Fila: ");
    imprime(f);

    printf("\n");

    remove_inicio(f, &elemento);
    printf("Elemento removido: %d\n", elemento);
    printf("Fila: ");
    imprime(f);

    printf("\n");

    remove_inicio(f, &elemento);
    printf("Elemento removido: %d\n", elemento);
    printf("Fila: ");
    imprime(f);

    return 0;
}
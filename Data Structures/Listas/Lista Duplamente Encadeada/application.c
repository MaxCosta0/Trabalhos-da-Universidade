#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){
    printf("====================CRIA LISTA====================\n");
    Lista lst = cria_lista();
    printf("Lista: ");
    imprime(lst);

    printf("====================INSERE ELEMENTOS====================\n");
    insere_elemento(&lst, 4);
    insere_elemento(&lst, 7);
    insere_elemento(&lst, 23);
    insere_elemento(&lst, 6);
    insere_elemento(&lst, 5);

    printf("Lista: ");
    imprime(lst);

    printf("====================REMOVE ELEMENTOS====================\n");
    remove_elemento(&lst, 4);
    remove_elemento(&lst, 23);
    remove_elemento(&lst, 10);

    printf("Lista: ");
    imprime(lst);

    return 0;
}
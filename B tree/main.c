/*
    Grupo MJB
    Integrantes:
    Maxley Soares da Costa      11911BCC038
    Joao Vitor Afonso Pereira   11911BCC037
    Bruno Olivera Sinhoroto     11821BCC044
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "GrupoMJB.h"

int main(){
    ArvB* arvB = cria_ArvB();

    //Verifica se é vazia
    if(ehVazia_ArvB(arvB))
        printf("Arvore vazia\n");
    else
        printf("Arvore nao vazia\n");

    //Insere elementos
    insere_ArvB(arvB, 5);
    insere_ArvB(arvB, 15);
    insere_ArvB(arvB, 20);
    insere_ArvB(arvB, 30);
    insere_ArvB(arvB, 35);
    insere_ArvB(arvB, 8);
    insere_ArvB(arvB, 24);
    insere_ArvB(arvB, 13);
    insere_ArvB(arvB, 5);

    //Printa os valores da arvore
    emOrdem(arvB);
    printf("\n");

    //Remove elementos da arvore
    if(remove_ArvB(arvB, 24))
        printf("Elemento removido com sucesso\n");
    else
        printf("Nao foi possivel remover o elemento\n");

    //Verifica se é vazia
    if(ehVazia_ArvB(arvB))
        printf("Arvore vazia\n");
    else
        printf("Arvore nao vazia\n");

    //Printa a arvore
    emOrdem(arvB);
    printf("\n");

    //Verifica se um valor esta na arvore
    if(busca_ArvB(arvB, 20))
        printf("Elemento encontrado.\n");

    else
        printf("O elemento nao esta na arvore.\n");


    //Mostra a quantidade de nohs da arvore
    printf("Total de nohs =  %d \n",totalNO_ArvB(arvB));

    //Libera a arvore
    libera_ArvB(arvB);

    return 0;
} 
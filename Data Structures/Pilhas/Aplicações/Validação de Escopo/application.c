#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int abertura(char caractere){
    if(caractere == '(' || caractere == '[' || caractere == '{'){
        return 1;       //É um delimitador de abertura
    }
    return 0;           //Não é um delimitador de abertura
}

int fechamento(char caractere){
    if(caractere == ')' || caractere == ']' || caractere == '}'){
        return 1;           //É um delimitador de fechamento
    }
    return 0;               //Não é um delimitador de fechamento
}

int respectivo(char abertura, char fechamento){
    if(abertura == '(' && fechamento == ')' || abertura == '[' && fechamento == ']' || abertura == '{' && fechamento == '}'){
        return 1;
    }
    return 0;
}

int valida_escopo(char* expressao){
    Pilha p = cria_pilha();
    int i;
    char delimitador;
    for(i = 0; expressao[i] != '\0'; i++){
        if(abertura(expressao[i]) == 1){                //Se delimitador de abertura, entao empilha
            push(&p, expressao[i]);
        }else if(fechamento(expressao[i]) == 1){                //Se delimitador de fechamento, entao verifica se é igual o topo e desempilha
            pop(&p, &delimitador);
            if(respectivo(delimitador, expressao[i]) == 0){
                return 0;
            }
        }
    }
    if(pilha_vazia(p) == 0){
        return 0;
    }
    return 1;
}

int main(){
    char expressao[20];
    printf("Digite sua expressao: ");
    scanf("%s", &(*expressao));

    if(valida_escopo(expressao) == 1){
        printf("Expressao Valida.\n");
    }else{
        printf("Expressao Invalida.\n");
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

char convHex(int decimal){
    switch(decimal){
        case 10:
            return 'A';
            break;
        
        case 11:
            return 'B';
            break;

        case 12:
            return 'C';
            break;
        
        case 13:
            return 'D';
            break;

        case 14:
            return 'E';
            break;

        case 15:
            return 'F';
            break;

        default:
            return '\0';
            break;        
    }
}

void dec2hex(int decimal){
    int resto, elemento;
    Pilha p = cria_pilha();
    do{
        resto = decimal % 16;
        decimal = decimal / 16;
        push(p, resto);
        if(pilha_cheia(p) == 1){
            printf("Estouro de pilha.\n");
            break;
        }
    }while(decimal != 0);

    printf("Hexadecimal: ");
    while(pilha_vazia(p) == 0){
        pop(p, &elemento);
        if(elemento > 9){
            char hex = convHex(elemento);                 //Converter o elemento em hexadecimal;
            printf("%c ", hex);   
        }else{
            printf("%d ", elemento);
        }
    }
    printf("\n");
}

void dec2oct(int decimal){
    int resto, elemento;
    Pilha p = cria_pilha();
    do{
        resto = decimal % 8;
        decimal = decimal / 8;
        push(p, resto);
        if(pilha_cheia(p) == 1){
            printf("Estouro de Pilha.\n");
            break;
        }
    }while(decimal != 0);

    printf("Octal: ");
    while(pilha_vazia(p) == 0){
        pop(p, &elemento);
        printf("%d ", elemento);
    }
    printf("\n");
}

void dec2bin(int decimal){
    int resto, elemento;
    Pilha p = cria_pilha();
    do{
        resto = decimal % 2;
        decimal = decimal / 2;
        push(p, resto);
        if(pilha_cheia(p) == 1){
            printf("Estouro de pilha.\n");
            break;
        }
    }while(decimal != 0);

    printf("Binario: ");
    while(pilha_vazia(p) == 0){
        pop(p, &elemento);
        printf("%d ", elemento);
    }
    printf("\n");
}

int main(){

    int resp, decimal;

    printf("Digite o numero da conversao desejada\n");
    printf("1.Decimal -> Binario \n2.Decimal -> Octal \n3.Decimal -> Hexadecimal\n");
    scanf("%d", &resp);

    switch(resp){
        case 1:
            printf("Digite um Valor Decimal: ");
            scanf("%d", &decimal);
            dec2bin(decimal);
            break;

        case 2:
            printf("Digite um Valor Decimal: ");
            scanf("%d", &decimal);
            dec2oct(decimal);
            break;

        case 3:
            printf("Digite um Valor Decimal: ");
            scanf("%d", &decimal);
            dec2hex(decimal);
            break;
        
        default:
            break;
    }

    return 0;
}
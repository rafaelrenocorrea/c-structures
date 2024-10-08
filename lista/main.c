#include <stdio.h>

#include "lista.h"

int rotinaTeste(Lista *lista);
// Rotina de testes para as funções da lista
//
// Retornos:
// - 0: tudo certo;
// - 1: algum teste falhou.

int main(void){
    Lista *lista = NULL;

    if(rotinaTeste(lista) == 0){
        printf("Os testes sucederam :)\n");
    }else fprintf(stderr, "Algum teste falhou :(\n");

    return 0;
}

// Rotina de testes para as funções da lista
int rotinaTeste(Lista *lista){
    int i;
    lista = fazLista();
    if(lista == NULL)return 1;

    for(i = 0; i < 5; i++){
        if(insereNo(lista, i + 1, "front") != 0)return 1; // teste de inserção no começo da lista
    }

    for(i = 5; i < 10; i++){
        if(insereNo(lista, i + 1, "back") != 0)return 1; // teste de inserção no final da lista
    }

    if(imprimeLista(lista) != 0)return 1;

    for(i = 1; i <= 10; i++){
        if(removeNo(lista, i) != 0)return 1;

        if(imprimeLista(lista) != 0)return 1;
    }

    if(liberaLista(lista) != 0)return 1;

    return 0;
}

/*
    Implementação das funções de lista

            Estrutura de Dados

       Por Rafael Renó Corrêa, 2024
*/

#include <stdlib.h>
#include <stdio.h>

#include "lista.h"

struct no{
    int valor;
    struct no *prox;
};

struct lista{
    struct no *raiz;
    int qtd;
};

// Função para alocar o ponteiro para a lista
Lista *fazLista(){
    Lista *lista = (Lista*) malloc(sizeof(Lista));
    if(lista == NULL)return NULL;

    lista->raiz = NULL;
    lista->qtd = 0;

    return lista;
}

// Função para alocar o ponteiro para o nó
No *fazNo(int valor){
    No *novoNo = (No*) malloc(sizeof(No));
    if(novoNo == NULL)return NULL;

    novoNo->valor = valor;
    novoNo->prox = NULL; // por padrão o nó é inserido no final da lista

    return novoNo;
}

// Função para inserir um novo nó no começo da lista
int insereNo(Lista *lista, int valor){
    if(lista == NULL)return 1;

    No *novoNo = fazNo(valor);
    if(novoNo == NULL)return 2;

    // Inserção O(1)
    if(lista->qtd > 0){
        novoNo->prox = lista->raiz;

        lista->raiz = novoNo;
    }else{ // se é o primeiro nó
        lista->raiz = novoNo;
    }
    //

    lista->qtd++;

    return 0;
}
//

// Função para inserir um novo nó no final da lista
int insereNoFinal(Lista *lista, int valor){
    if(lista == NULL)return 1;

    No *novoNo = fazNo(valor);
    if(novoNo == NULL)return 2;

    if(lista->qtd > 0){
        No *aux;

        aux = lista->raiz;

        while(aux->prox != NULL)aux = aux->prox; // O(n)

        aux->prox = novoNo;
    }else{ // se é o primeiro nó
        lista->raiz = novoNo;
    }

    lista->qtd++;

    return 0;
}

// Função para remover um nó da lista
int removeNo(Lista *lista, int valor){
    if(lista == NULL)return 1;

    No *ant, *aux;

    if(lista->qtd > 0){
        if(lista->qtd > 1){
            aux = lista->raiz;

            if(aux->valor != valor){
                while((aux != NULL) && (aux->valor != valor)){
                    ant = aux;

                    aux = aux->prox;
                }

                if(aux != NULL){
                    ant->prox = aux->prox;

                    free(aux);
                }else return 3;
            }else{ // se é o primeiro nó
                lista->raiz = aux->prox;

                free(aux);
            }
        }else{ // se é o primeiro e único nó
            aux = lista->raiz;

            free(aux);

            lista->raiz = NULL;
        }
    }else return 2;

    lista->qtd--;

    return 0;
}

// Função para imprimir o conteúdo da lista
int imprimeLista(Lista *lista){
    if(lista == NULL)return 1;
    
    No *aux = lista->raiz;

    if(lista->qtd > 0){
        printf("Lista = {");
        for(int i = 0; i < lista->qtd - 1; i++){
            printf("%d, ", aux->valor);

            aux = aux->prox;
        }
        printf("%d}\n", aux->valor);
    }else printf("Lista = {}\n");

    return 0;
}

// Função para liberar a lista da memória RAM
int liberaLista(Lista *lista){
    if(lista == NULL)return 1;

    No *ant, *prox;

    ant = lista->raiz;

    while(ant != NULL){
        prox = ant->prox;

        free(ant);

        ant = prox;
    }

    free(lista);

    return 0;
}
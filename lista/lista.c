/*
    Implementação das funções de lista

            Estrutura de Dados

       Por Rafael Renó Corrêa, 2024
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h> // strcmp()

#include "lista.h"

struct no{
    int chave;
    struct info *dados;
    struct no *prox;
};

struct lista{
    int qtd;
    struct no *raiz;
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
No *fazNo(int chave, Info *dados){
    No *novoNo = (No*) malloc(sizeof(No));
    if(novoNo == NULL)return NULL;

    Info *novoDado = (Info*) malloc(sizeof(Info));
    if(novoDado == NULL){
        free(novoNo);

        return NULL;
    }
    *novoDado = *dados;

    novoNo->chave = chave;
    novoNo->dados = novoDado;
    novoNo->prox = NULL; // por padrão, o nó é inserido no final da lista

    return novoNo;
}

// Função para inserir um novo nó na lista
int insereNo(Lista *lista, int chave, Info *dados, char *modo){
    if(lista == NULL)return 1;

    No *novoNo = fazNo(chave, dados);
    if(novoNo == NULL)return 2;

    if(strcmp(modo, "front") == 0){ // insere o novo nó no começo da lista
        if(lista->qtd > 0){
            novoNo->prox = lista->raiz;

            lista->raiz = novoNo;
        }else{ // se é o primeiro nó
            lista->raiz = novoNo;
        }
    }else if(strcmp(modo, "back") == 0){ // insere o novo nó no final da lista
        if(lista->qtd > 0){
            No *aux;

            aux = lista->raiz;

            while(aux->prox != NULL)aux = aux->prox; // O(n)

            aux->prox = novoNo;
        }else{ // se é o primeiro nó
            lista->raiz = novoNo;
        }
    }else{ // modo inválido
        return 3;
    }

    lista->qtd++;

    return 0;
}
//

// Função para remover um nó da lista
int removeNo(Lista *lista, int chave){
    if(lista == NULL)return 1;

    No *ant, *aux;

    if(lista->qtd > 0){
        if(lista->qtd > 1){
            aux = lista->raiz;

            if(aux->chave != chave){
                while((aux != NULL) && (aux->chave != chave)){
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

// Função para consultar o conteúdo de um nó da lista a partir da chave
Info *consultaNo(Lista *lista, int chave){
    if(lista == NULL)return NULL;

    if(lista->qtd > 0){
        No *aux = lista->raiz;

        while((aux != NULL) && (aux->chave != chave))aux = aux->prox;

        if((aux != NULL) && (aux->chave == chave)){ // se encontrou
            return aux->dados;
        }else{ // se não encontrou
            return NULL;
        }
    }else return NULL; // a lista está vazia
}

// Função para acessar o tamanho da lista
int tamanhoLista(Lista *lista){
    return lista->qtd;
}

// Função para liberar a lista da memória RAM
int liberaLista(Lista *lista){
    if(lista == NULL)return 1;

    No *ant, *prox;

    ant = lista->raiz;

    while(ant != NULL){
        prox = ant->prox;

        free(ant->dados);
        free(ant);

        ant = prox;
    }

    free(lista);

    return 0;
}
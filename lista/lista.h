/*
    Assinaturas das funções de lista

           Estrutura de Dados

      Por Rafael Renó Corrêa, 2024
*/

#ifndef LISTA_H
#define LISTA_H

typedef struct no No;
typedef struct lista Lista;

Lista *fazLista();
// Função para alocar o ponteiro para a lista
//
// Retorno:
// - Ponteiro do tipo Lista (se nulo, não havia memória RAM).

No *fazNo(int valor);
// Função para alocar o ponteiro para o nó
//
// Retorno:
// - Ponteiro do tipo Nó (se nulo, não havia memória RAM).

int insereNo(Lista *lista, int valor);
// Função para inserir um novo nó no começo da lista
//
// Complexidade: O(1)
//
// Retornos:
// - 0: tudo certo;
// - 1: a lista nunca foi alocada;
// - 2: memória RAM insuficiente.

int insereNoFinal(Lista *lista, int valor);
// Função para inserir um novo nó no final da lista
//
// Complexidade: O(n)
//
// Retornos:
// - 0: tudo certo;
// - 1: a lista nunca foi alocada;
// - 2: memória RAM insuficiente.

int removeNo(Lista *lista, int valor);
// Função para remover um nó da lista
//
// Retornos:
// - 0: tudo certo;
// - 1: a lista nunca foi alocada;
// - 2: a lista está vazia;
// - 3: o nó não está na lista.

int imprimeLista(Lista *lista);
// Função para imprimir o conteúdo da lista
//
// Retornos:
// - 0: tudo certo;
// - 1: a lista nunca foi alocada. 

int liberaLista(Lista *lista);
// Função para liberar a lista da memória RAM
//
// Retornos:
// - 0: tudo certo;
// - 1: a lista nunca foi alocada.

#endif // LISTA_H
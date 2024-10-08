/*
    Assinaturas das funções de lista

           Estrutura de Dados

      Por Rafael Renó Corrêa, 2024
*/

#ifndef LISTA_H
#define LISTA_H

typedef struct info{
    int valor;
    char caracter;

    // Preencha o tipo com as informações desejadas...
}Info;
/*
    Nota: ao preencher o tipo de informações, é necessário alterar
          a função imprimeLista() para imprimir todos os dados.
*/

typedef struct no No;
typedef struct lista Lista;

Lista *fazLista();
// Função para alocar o ponteiro para a lista
//
// Retorno:
// - Ponteiro do tipo Lista (se nulo, não havia memória RAM).

No *fazNo(int chave, Info *dados);
// Função para alocar o ponteiro para o nó
//
// Retorno:
// - Ponteiro do tipo Nó (se nulo, não havia memória RAM).

int insereNo(Lista *lista, int chave, Info *dados, char *modo);
// Função para inserir um novo nó na lista
//
// Modos:
//     - "front": insere o nó no começo da lista (O(1));
//     - "back": insere o nó no final da lista (O(n)).
//
// Retornos:
// - 0: tudo certo;
// - 1: a lista nunca foi alocada;
// - 2: memória RAM insuficiente.

int removeNo(Lista *lista, int chave);
// Função para remover um nó da lista
//
// Retornos:
// - 0: tudo certo;
// - 1: a lista nunca foi alocada;
// - 2: a lista está vazia;
// - 3: o nó não está na lista.

Info *consultaNo(Lista *lista, int chave);
// Função para consultar o conteúdo de um nó da lista a partir da chave
//
// Retornos:
// - Ponteiro para o dado no nó (se nulo, não havia memória RAM).

int tamanhoLista(Lista *lista);
// Função para acessar o tamanho da lista
//
// Portanto, retorna o tamanho da lista.

int liberaLista(Lista *lista);
// Função para liberar a lista da memória RAM
//
// Retornos:
// - 0: tudo certo;
// - 1: a lista nunca foi alocada.

#endif // LISTA_H
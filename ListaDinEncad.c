#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncad.h"
#include "Chamados.h"

Lista* cria_lista() {
    Lista* lista = (Lista*) malloc(sizeof(Lista));
    if (lista != NULL)
        *lista = NULL;
    return lista;
}

void libera_lista(Lista* lista) {
    if (lista != NULL) {
        Elemento* atual;
        while ((*lista) != NULL) {
            atual = *lista;
            *lista = (*lista)->prox;
            free(atual);
        }
        free(lista);
    }
}

int consulta_lista_pos(Lista* lista, int posicao, Chamado* aluno_consultado) {
    if (lista == NULL || posicao <= 0)
        return 0;

    Elemento* atual = *lista;
    int contador = 1;
    while (atual != NULL && contador < posicao) {
        atual = atual->prox;
        contador++;
    }

    if (atual == NULL)
        return 0;

    *aluno_consultado = atual->dados;
    return 1;
}

int consulta_lista_num(Lista* lista, int num, Chamado* ch) {
    if (lista == NULL)
        return 0;

    Elemento* atual = *lista;
    while (atual != NULL && atual->dados.numero != num) {
        atual = atual->prox;
    }

    if (atual == NULL)
        return 0;

    *ch = atual->dados;
    return 1;
}

int insere_lista_inicio(Lista* lista, Chamado novo_aluno) {
    if (lista == NULL)
        return 0;

    Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
    if (novo == NULL)
        return 0;

    novo->dados = novo_aluno;
    novo->prox = *lista;
    *lista = novo;
    return 1;
}

int insere_lista_final(Lista* lista, Chamado novo_aluno) {
    if (lista == NULL)
        return 0;

    Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
    if (novo == NULL)
        return 0;

    novo->dados = novo_aluno;
    novo->prox = NULL;

    if (*lista == NULL) {
        *lista = novo;
    } else {
        Elemento* atual = *lista;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }

    return 1;
}

int insere_lista_ordenada(Lista* lista, Chamado novo_aluno) {
    if (lista == NULL)
        return 0;

    Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
    if (novo == NULL)
        return 0;

    novo->dados = novo_aluno;

    if (*lista == NULL || (*lista)->dados.numero > novo_aluno.numero) {
        novo->prox = *lista;
        *lista = novo;
    } else {
        Elemento* anterior = *lista;
        Elemento* atual = (*lista)->prox;
        while (atual != NULL && atual->dados.numero < novo_aluno.numero) {
            anterior = atual;
            atual = atual->prox;
        }
        novo->prox = atual;
        anterior->prox = novo;
    }

    return 1;
}

int remove_lista(Lista* lista, int numero) {
    if (lista == NULL || *lista == NULL)
        return 0;

    Elemento* anterior = NULL;
    Elemento* atual = *lista;

    while (atual != NULL && atual->dados.numero != numero) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL)
        return 0;

    if (anterior == NULL)
        *lista = atual->prox;
    else
        anterior->prox = atual->prox;

    free(atual);
    return 1;
}

int remove_lista_inicio(Lista* lista) {
    if (lista == NULL || *lista == NULL)
        return 0;

    Elemento* removido = *lista;
    *lista = removido->prox;
    free(removido);
    return 1;
}

int remove_lista_final(Lista* lista) {
    if (lista == NULL || *lista == NULL)
        return 0;

    Elemento* anterior = NULL;
    Elemento* atual = *lista;

    while (atual->prox != NULL) {
        anterior = atual;
        atual = atual->prox;
    }

    if (anterior == NULL)
        *lista = NULL;
    else
        anterior->prox = NULL;

    free(atual);
    return 1;
}

int tamanho_lista(Lista* lista) {
    if (lista == NULL)
        return 0;

    int tamanho = 0;
    Elemento* atual = *lista;
    while (atual != NULL) {
        tamanho++;
        atual = atual->prox;
    }
    return tamanho;
}

int lista_vazia(Lista* lista) {
    return (lista == NULL || *lista == NULL);
}

int lista_cheia(Lista* lista) {
    return 0;
}

void imprime_lista(Lista* lista) {
    if (lista == NULL)
        return;

    Elemento* atual = *lista;
    while (atual != NULL) {
        chamadoInfo(atual->dados);
        printf("-------------------------------\n");
        atual = atual->prox;
    }
}

// ListaDinEncad.h

#ifndef LISTADINENCADEADA_H
#define LISTADINENCADEADA_H

#include "Structs.h"



Lista* cria_lista();
void libera_lista(Lista* li);
int insere_lista_final(Lista* li, Chamado al);
int insere_lista_inicio(Lista* li, Chamado al);
int insere_lista_ordenada(Lista* li, Chamado al);
int remove_lista(Lista* li, int num);
int remove_lista_inicio(Lista* li);
int remove_lista_final(Lista* li);
int tamanho_lista(Lista* li);
int lista_vazia(Lista* li);
int lista_cheia(Lista* li);
void imprime_lista(Lista* li);
int consulta_lista_num(Lista* li, int num, Chamado* ch);
int consulta_lista_pos(Lista* li, int pos, Chamado* al);

#endif

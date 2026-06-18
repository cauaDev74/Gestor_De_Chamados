//
// Created by cauadev74 on 09/06/2026.
//

#ifndef GESTORDECHAMADOS_CHAMADOS_H
#define GESTORDECHAMADOS_CHAMADOS_H

#include "Structs.h"

void clearInputBuffer();
void removeEnter(char* c);
void chamadoInfo(Chamado dados);
void inputDados(Chamado *dados);

void abrirChamado(Lista *l, Chamado dados);

void listarChamados(Lista *l);

void buscarPorNumero(Lista *l, int numero);

void assumirChamado(Lista *l, char *tec);

void resolverChamado(Lista *l, int numero);

void listarPorStatus(Lista *l, char *status);

void removerChamado(Lista *l, int numero);

void salvarEmArquivo(Lista *l);

void carregarArquivo(Lista *l);

#endif //GESTORDECHAMADOS_CHAMADOS_H
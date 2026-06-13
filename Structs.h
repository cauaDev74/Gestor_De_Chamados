//
// Created by cauadev74 on 11/06/2026.
//

#ifndef GESTORDECHAMADOS_STRUCTS_H
#define GESTORDECHAMADOS_STRUCTS_H
#include <time.h>

typedef struct Chamado{
    int numero;
    char solicitante[100];
    char descricao[250];
    char categoria[60];
    char status[30];
    char tecnico[80];
    char dataAbertura[30];
}Chamado;

typedef struct Elemento{
    Chamado dados;
    struct Elemento* prox;
}Elemento;

typedef struct Elemento* Lista;

#endif //GESTORDECHAMADOS_STRUCTS_H
#include "Chamados.h"
#include "ListaDinEncad.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int proximoNumero = 1;

//Miscelaneous
void clearInputBuffer() {
    //Limpa caracteres restantes no buffer de entrada
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void removeEnter(char* c) {
    c[strcspn(c, "\n")] = 0;
}

void chamadoInfo(Chamado dados) {
    printf("Numero: %d\n", dados.numero);
    printf("Solicitante: %s\n", dados.solicitante);
    printf("descricao: %s\n", dados.descricao);
    printf("Categoria: %s\n", dados.categoria);
    printf("Status: %s\n", dados.status);
    printf("Tecnico: %s\n", dados.tecnico);
    printf("Data de abertura: %s\n", dados.dataAbertura);
}
void inputDados(Chamado *dados) {
    printf("Solicitante: ");
    fgets(dados->solicitante, 100, stdin);
    removeEnter(dados->solicitante);

    printf("Descricao do chamado:\n");
    fgets(dados->descricao, 250, stdin);
    removeEnter(dados->descricao);

    printf("Categoria: ()");
    fgets(dados->categoria, 100, stdin);
    removeEnter(dados->categoria);

    printf("Tecnico: ");
    fgets(dados->tecnico, 100, stdin);
    removeEnter(dados->tecnico);
    
    strcpy(dados->status, "aberto");
    time_t t = time(NULL);
    strftime(dados->dataAbertura, 10, "%d/%m/%Y", localtime(&t));
}
//============================//

void abrirChamado(Lista *l, Chamado dados) {
    if (l == NULL) {
        return;
    }
    dados.numero = proximoNumero++;

    insere_lista_final(l, dados);
}

void listarChamados(Lista *l) {
    if (l == NULL) {
        return;
    }
    imprime_lista(l);
}

void buscarPorNumero(Lista *l, int numero) {
    if (l == NULL) {
        return;
    }
    Chamado ch;
    consulta_lista_num(l, numero, &ch);
    chamadoInfo(ch);
}

void assumirChamado(Lista *l, char *tec){}

void resolverChamado(Lista *l, int numero){}

void listarPorStatus(Lista *l, char *status){}

void removerChamado(Lista *l, int numero) {
    if (l == NULL) {
        return;
    }

    remove_lista(l, numero);
}

void salvarEmArquivo(Lista *l){}

void carregarArquivo(Lista *l){}
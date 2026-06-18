#include "Chamados.h"
#include "ListaDinEncad.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int proximoNumero = 1;

//Miscelaneous
void clearInputBuffer() {
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
    int opcao = 0;
    printf("Solicitante: ");
    fgets(dados->solicitante, 100, stdin);
    removeEnter(dados->solicitante);

    printf("Descricao do chamado:\n");
    fgets(dados->descricao, 250, stdin);
    removeEnter(dados->descricao);

    printf("Categoria: 1- Hardware 2- Software 3- Rede 4- Acesso\n-> ");
    scanf("%d", &opcao);
    clearInputBuffer();
    switch (opcao) {
        case 1:
            strcpy(dados->categoria, "Hardware");
            break;
        case 2:
            strcpy(dados->categoria, "Software");
            break;
        case 3:
            strcpy(dados->categoria, "Rede");
            break;
        case 4:
            strcpy(dados->categoria, "Acesso");
            break;
        default:
            printf("Opcao invalida\n");
            break;
    }

    strcpy(dados->tecnico, "Nao atribuido");
    
    strcpy(dados->status, "Aberto");
    time_t t = time(NULL);
    strftime(dados->dataAbertura, 11, "%d/%m/%Y", localtime(&t));
}


void abrirChamado(Lista *l, Chamado dados) {
    if (l == NULL) {
        return;
    }
    dados.numero = proximoNumero++;

    if (insere_lista_final(l, dados)) {
        printf("Chamado solicitado com sucesso\n");
    }else {
        printf("Erro ao abrir chamado\n");
    }
}

void listarChamados(Lista *l) {
    if (l == NULL) {
        printf("Lista vazia.\n");
        return;
    }
    imprime_lista(l);
}

void buscarPorNumero(Lista *l, int numero) {
    if (l == NULL) {
        return;
    }
    Chamado ch;
    if (consulta_lista_num(l, numero, &ch)) {
        chamadoInfo(ch);
    }else {
        printf("Chamado nao encontrado\n");
    }
}

void assumirChamado(Lista *l, char *tec) {
    if (l == NULL) {
        return;
    }
    Chamado *ch;
    int numero;

    printf("Insira o numero do chamado: ");
    scanf("%d", &numero);
    clearInputBuffer();

    ch = consulta_lista_num_end(l, numero);

    if (ch == NULL) {
        printf("Chamado nao encontrado\n");
        return;
    }

    strcpy(ch->tecnico, tec);
    strcpy(ch->status, "Em andamento");

    chamadoInfo(*ch);

}

void resolverChamado(Lista *l, int numero) {
    if (l == NULL) {
        return;
    }
    Chamado *ch;
    ch = consulta_lista_num_end(l, numero);
    if (ch == NULL) {
        printf("Chamado nao encontrado\n");
        return;
    }
    strcpy(ch->status, "Resolvido");
    printf("Chamado resolvido com sucesso\n");
}

void listarPorStatus(Lista *l, char *status) {
    if (l == NULL) {
        return;
    }
    Elemento *atual = *l;
    while (atual != NULL) {
        if (strcmp(atual->dados.status, status) == 0) {
            chamadoInfo(atual->dados);
            printf("-------------------------------\n");
        }
        atual = atual->prox;
    }
}

void removerChamado(Lista *l, int numero) {
    if (l == NULL) {
        return;
    }

    remove_lista(l, numero);
}

void salvarEmArquivo(Lista *l) {
    if (l == NULL) {
        return;
    }
    FILE *arquivo = fopen("Chamados.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo\n");
        return;
    }

    Elemento *atual = *l;

    fprintf(arquivo, "%d\n", proximoNumero);
    while (atual != NULL) {
        fprintf(arquivo, "%d\n", atual->dados.numero);
        fprintf(arquivo, "%s\n", atual->dados.solicitante);
        fprintf(arquivo, "%s\n", atual->dados.descricao);
        fprintf(arquivo, "%s\n", atual->dados.categoria);
        fprintf(arquivo, "%s\n", atual->dados.status);
        fprintf(arquivo, "%s\n", atual->dados.tecnico);
        fprintf(arquivo, "%s\n", atual->dados.dataAbertura);
        atual = atual->prox;
    }
    fclose(arquivo);
}

void carregarArquivo(Lista *l) {
    if (l == NULL) {
        return;
    }
    FILE *arquivo = fopen("Chamados.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo\n");
        return;
    }

    Chamado temp;

    fscanf(arquivo, "%d", &proximoNumero);
    clearInputBuffer();

    while (fscanf(arquivo, "%d", &temp.numero) == 1){

        fgets(temp.solicitante, 100, arquivo);
        removeEnter(temp.solicitante);

        fgets(temp.descricao, 250, arquivo);
        removeEnter(temp.descricao);

        fgets(temp.categoria, 60, arquivo);
        removeEnter(temp.categoria);

        fgets(temp.status, 30, arquivo);
        removeEnter(temp.status);

        fgets(temp.tecnico, 80, arquivo);
        removeEnter(temp.tecnico);

        fgets(temp.dataAbertura, 30, arquivo);
        removeEnter(temp.dataAbertura);

        insere_lista_final(l, temp);
    }

    fclose(arquivo);
}

#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncad.h"
#include "Chamados.h"

int main(void) {
    Lista l = NULL;
    int opcao;
    Chamado dados;
    int numero;
    char tec[80];
    char status[30];

    carregarArquivo(&l);
    do {system("cls");
        printf("||###################################||\n");
        printf("||                                   ||\n");
        printf("||-*-*-* Gestor de Chamados -*-*-*-*-||\n");
        printf("||                                   ||\n");
        printf("||###################################||\n");

        printf("\t||============================||\n");
        printf("\t||     1 - Abrir chamado      ||\n");
        printf("\t||     2 - Listar chamados    ||\n");
        printf("\t||     3 - Buscar por numero  ||\n");
        printf("\t||     4 - Assumir chamado    ||\n");
        printf("\t||     5 - Resolver chamado   ||\n");
        printf("\t||     6 - Listar por status  ||\n");
        printf("\t||     7 - Remover chamado    ||\n");
        printf("\t||     0 - Sair               ||\n");
        printf("\t||============================||\n");

        printf("\t|| Digite a opcao desejada: ");
        scanf("%d", &opcao);
        clearInputBuffer();

        switch (opcao) {
            case 1:
                abrirChamado(&l, dados);
                break;
            case 2:
                listarChamados(&l);
                break;
            case 3:
                printf("Not complete\n");
                //buscarPorNumero(&l);
                break;
            case 4:
                printf("Not complete\n");
                //assumirChamado(&l, tec);
                break;
            case 5:
                printf("Not complete\n");
                //resolverChamado(&l, numero);
                break;
            case 6:
                printf("Not complete\n");
                //listarPorStatus(&l, status);
                break;
            case 7:
                printf("Not complete\n");
                //removerChamado();
                break;
            case 0:
                printf("Not complete\n");
                //salvarEmArquivo();
                break;
            default:
                break;
        }
    }while (opcao != 0);
    return 0;
}



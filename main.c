#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ListaDinEncad.h"
#include "Chamados.h"

int main(void) {
    Lista *l = cria_lista();
    int opcao;
    Chamado dados;
    int numero = 0;
    char tec[80];
    char status[30];
    char confirmar;

    carregarArquivo(l);

    do {

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

                printf("||###################################||\n");

                inputDados(&dados);
                abrirChamado(l, dados);

                break;
            case 2:

                printf("||###################################||\n");
                listarChamados(l);

                break;
            case 3:
                system("clear");
                printf("||###################################||\n");

                printf("Insira o numero do chamado\n");
                scanf("%d", &numero);
                clearInputBuffer();
                buscarPorNumero(l, numero);

                break;
            case 4:
                system("clear");
                printf("||###################################||\n");
                printf("Insira o nome do tecnico: ");
                fgets(tec, 80, stdin);
                removeEnter(tec);
                assumirChamado(l, tec);

                break;
            case 5:

                printf("||###################################||\n");
                printf("Insira o numero do chamado a ser finalizado: ");
                scanf("%d", &numero);
                resolverChamado(l, numero);

                break;
            case 6:

                printf("||###################################||\n");
                int statusSlct = 0;
                printf("Selecione: \n1 - Aberto\n2 - Em andamento\n3 - Resolvido\n->\n");
                scanf("%d", &statusSlct);
                switch (statusSlct) {
                    case 1:
                        strcpy(status, "Aberto");
                        listarPorStatus(l, status);
                        break;
                    case 2:
                        strcpy(status, "Em andamento");
                        listarPorStatus(l, status);
                        break;
                    case 3:
                        strcpy(status, "Resolvido");
                        listarPorStatus(l, status);
                        break;
                    default:
                        printf("Opcao invalida\n");
                        break;
                }

                break;
            case 7:

                printf("||###################################||\n");
                printf("Insira o numero do chamado: \n");
                scanf("%d", &numero);
                clearInputBuffer();

                buscarPorNumero(l, numero);
                do {
                    printf("Deseja realmente remover o chamado? (s/n) ");
                    scanf("%c", &confirmar);
                    clearInputBuffer();
                }while (confirmar != 's' && confirmar != 'n' && confirmar != 'S' && confirmar != 'N');

                if (confirmar == 's' || confirmar == 'S') {
                    removerChamado(l, numero);
                    printf("Chamado removido com sucesso\n");
                    break;
                }else if (confirmar == 'n' || confirmar == 'N') {
                    printf("Operacao cancelada\n");
                    break;
                }

                break;
            case 0:
                printf("Saindo e salvando...\n");
                salvarEmArquivo(l);
                break;
            default:
                break;
        }
    }while (opcao != 0);
    return 0;
}

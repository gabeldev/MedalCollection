#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cadastro.h"
#include "exportar_csv.h"

void menu(Medalhas *medalhas, int *num_medalhas) {
    int opcao;

    do {
        printf("\n======== MENU ========\n");
        printf("1. Inserir Medalha\n");
        printf("2. Listar Medalhas\n");
        printf("3. Buscar Medalha\n");
        printf("4. Alterar Medalha\n");
        printf("5. Excluir Medalha\n");
        printf("6. Exportar dados para CSV\n");
        printf("7. Sair\n");
        printf("======================\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserir_medalha(medalhas, num_medalhas);
                break;
            case 2:
                listar_medalhas(medalhas, *num_medalhas);
                break;
            case 3:
                buscar_medalha(medalhas, *num_medalhas);
                break;
            case 4:
                alterar_medalha(medalhas, *num_medalhas);
                break;
            case 5:
                excluir_medalha(medalhas, *num_medalhas);
                break;
            case 6:
                exportar_csv(medalhas, *num_medalhas);
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }//switch
    } while (opcao != 7);
}//menu
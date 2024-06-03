#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "structs.h"
#include "cadastro.h"
#include "tabelas.h"
#include "exportar_csv.h"


char* transformar_minusculo(char *str) {
    char *resultado = malloc(strlen(str) + 1); // +1 para o caractere nulo
    if (resultado == NULL) {
        return NULL; // Erro na alocação de memória
    }

    strcpy(resultado, str);

    for (int i = 0; resultado[i]; i++) { // Converte a string para minúsculo
        resultado[i] = tolower((char) resultado[i]);
    }
    return resultado;
}

void inserir_medalha(Medalhas *medalha, Bruto_tabela *tabela) { // Insere uma medalha para um atleta

    char nome_atleta[50];
    int contador2 = 0;
    char tipo_medalha;

    setbuf(stdin, NULL);
    printf("Digite o nome do atleta: ");
    fgets(nome_atleta, 50, stdin);
    nome_atleta[strcspn(nome_atleta, "\n")] = '\0';
    setbuf(stdin, NULL);

    for (int i = 0; i < 2395; i++) {
        if(strcmp(transformar_minusculo(nome_atleta), transformar_minusculo(medalha[i].nome_atleta)) == 0) { // Se o atleta já estiver cadastrado
            printf("Atleta encontrado\n");
            contador2 = 1;
            
            do { // Verifica se o tipo de medalha é válido
                printf("Ouro - G, Prata - S, Bronze - B\n");
                printf("Digite o tipo de medalha a ser adicionado: ");
                scanf("%c", &tipo_medalha);
                if (tipo_medalha != 'G' && tipo_medalha != 'S' && tipo_medalha != 'B') {
                    printf("Tipo de medalha inválido\n");
                }
            } while (tipo_medalha != 'G' && tipo_medalha != 'S' && tipo_medalha != 'B');
            
            
            switch (tipo_medalha) { // Adiciona a medalha
            case 'G':
                tabela[i].ouro++;
                break;
            
            case 'S':
                tabela[i].prata++;
                break;
            
            case 'B':
                tabela[i].bronze++;
                break;

            default:
                break;
            }//switch
            
            break;
        }//if
    }//for

    if (contador2 == 0) { // Se o atleta não foi encontrado
        printf("Atleta não encontrado\n");
    }//if
}//inserir_medalha

void listar_medalhas(Medalhas *medalha, Bruto_tabela *tabela) { // Lista as medalhas de um atleta

    char nome_atleta[50];
    int contador2 = 0;
    char tipo_medalha;

    setbuf(stdin, NULL);
    printf("Digite o nome do atleta: ");
    fgets(nome_atleta, 50, stdin);
    nome_atleta[strcspn(nome_atleta, "\n")] = '\0';
    setbuf(stdin, NULL);

    for (int i = 0; i < 2395; i++) {
        if(strcmp(transformar_minusculo(nome_atleta), transformar_minusculo(medalha[i].nome_atleta)) == 0) { // Se o atleta já estiver cadastrado
            printf("Atleta encontrado\n");
            contador2 = 1;
            
            printf("Nome do atleta: %s\n", medalha[i].nome_atleta);
            printf("Ouro: %d\n", tabela[i].ouro);
            printf("Prata: %d\n", tabela[i].prata);
            printf("Bronze: %d\n", tabela[i].bronze);
            
            break;
        }//if
    }//for

    if (contador2 == 0) { // Se o atleta não foi encontrado
        printf("Atleta não encontrado\n");
    }//if
}//listar_medalhas

void pesquisar_medalha(Medalhas *medalha, Bruto_tabela *tabela) { // Pesquisa as medalhas de um atleta

    char nome_atleta[50];
    int contador2 = 0;
    char tipo_medalha;

    setbuf(stdin, NULL);
    printf("Digite o nome do atleta: ");
    fgets(nome_atleta, 50, stdin);
    nome_atleta[strcspn(nome_atleta, "\n")] = '\0';
    setbuf(stdin, NULL);

    for (int i = 0; i < 2395; i++) { // Verifica se o atleta já está cadastrado
        if(strcmp(transformar_minusculo(nome_atleta), transformar_minusculo(medalha[i].nome_atleta)) == 0) { // Se o atleta já estiver cadastrado
            printf("Atleta encontrado\n");
            contador2 = 1;

            do { // Verifica se o tipo de medalha é válido
                printf("Ouro - G, Prata - S, Bronze - B\n");
                printf("Digite o tipo de medalha a ser pesquisado: ");
                scanf("%c", &tipo_medalha);
                if (tipo_medalha != 'G' && tipo_medalha != 'S' && tipo_medalha != 'B') {
                    printf("Tipo de medalha inválido\n");
                }
            } while (tipo_medalha != 'G' && tipo_medalha != 'S' && tipo_medalha != 'B');

            switch (tipo_medalha) { // Mostra as medalhas
                
                case 'G':
                    printf("Nome do atleta: %s\n", medalha[i].nome_atleta);
                    printf("Ouro: %d\n", tabela[i].ouro);
                    break;
                
                case 'S':
                    printf("Nome do atleta: %s\n", medalha[i].nome_atleta);
                    printf("Prata: %d\n", tabela[i].prata);
                    break;

                case 'B':
                    printf("Nome do atleta: %s\n", medalha[i].nome_atleta);
                    printf("Bronze: %d\n", tabela[i].bronze);
                    break;

                default:
                    break;
                }//switch
            
            break;
        }//if
    }//for

    if (contador2 == 0) { // Se o atleta não foi encontrado
        printf("Atleta não encontrado\n");
    }//if
}//pesquisar_medalha

void alterar_medalha(Medalhas *medalha, Bruto_tabela *tabela) { // Altera uma medalha de um atleta
    char nome_atleta[50];
    int contador2 = 0;
    char tipo_medalha;
    int altera_medalha;

    setbuf(stdin, NULL);
    printf("Digite o nome do atleta em que a medalha deve ser alterada: ");
    fgets(nome_atleta, 50, stdin);
    nome_atleta[strcspn(nome_atleta, "\n")] = '\0';
    setbuf(stdin, NULL);

    for (int i = 0; i < 2395; i++) {
        if(strcmp(transformar_minusculo(nome_atleta), transformar_minusculo(medalha[i].nome_atleta)) == 0) { // Se o atleta já estiver cadastrado
            printf("Atleta encontrado\n");
            contador2 = 1;
            
            do {
                printf("Ouro - G, Prata - S, Bronze - B\n");
                printf("Digite o tipo de medalha a ser alterado: ");
                scanf(" %c", &tipo_medalha);
                if (tipo_medalha != 'G' && tipo_medalha != 'S' && tipo_medalha != 'B') {
                    printf("Tipo de medalha inválido\n");
                }
            } while (tipo_medalha != 'G' && tipo_medalha != 'S' && tipo_medalha != 'B');
            
            printf("Digite a nova quantidade de medalhas: ");
            scanf("%d", &altera_medalha);
            
            switch (tipo_medalha) {
            case 'G':
                tabela[i].ouro = altera_medalha;
                printf("Medalha alterada\n");
                break;
            
            case 'S':
                tabela[i].prata = altera_medalha;
                printf("Medalha alterada\n");
                break;
            
            case 'B':
                tabela[i].bronze = altera_medalha;
                printf("Medalha alterada\n");
                break;

            default:
                break;
            }//switch
            
            break;
        }//if
    }//for

    if (contador2 == 0) {
        printf("Atleta não encontrado\n");
    }//if
}//alterar_medalha

void excluir_medalha(Medalhas *medalha, Bruto_tabela *tabela) { // Exclui uma medalha de um atleta
    char nome_atleta[50];
    int contador2 = 0;
    char tipo_medalha;

    setbuf(stdin, NULL);
    printf("Digite o nome do atleta na qual a medalha deve ser excluída: ");
    fgets(nome_atleta, 50, stdin);
    nome_atleta[strcspn(nome_atleta, "\n")] = '\0';
    setbuf(stdin, NULL);

    for (int i = 0; i < 2395; i++) {
        if(strcmp(transformar_minusculo(nome_atleta), transformar_minusculo(medalha[i].nome_atleta)) == 0) {
            printf("Atleta encontrado\n");
            contador2 = 1;
            
            do {
                printf("Ouro - G, Prata - S, Bronze - B\n");
                printf("Digite o tipo de medalha a ser excluído: ");
                scanf(" %c", &tipo_medalha);
                if (tipo_medalha != 'G' && tipo_medalha != 'S' && tipo_medalha != 'B') {
                    printf("Tipo de medalha inválido\n");
                }
                if(tipo_medalha == 'G' && tabela[i].ouro == 0) {
                    printf("Atleta não possui medalhas de ouro\n");
                }
                if(tipo_medalha == 'S' && tabela[i].prata == 0) {
                    printf("Atleta não possui medalhas de prata\n");
                }
                if(tipo_medalha == 'B' && tabela[i].bronze == 0) {
                    printf("Atleta não possui medalhas de bronze\n");
                }
            } while (tipo_medalha != 'G' && tipo_medalha != 'S' && tipo_medalha != 'B' && 
                    (tipo_medalha == 'B' && tabela[i].bronze == 0) && (tipo_medalha == 'S' && tabela[i].prata == 0) &&
                    (tipo_medalha == 'G' && tabela[i].ouro == 0));
            
            switch (tipo_medalha) {
            case 'G':
                tabela[i].ouro--;
                break;
            
            case 'S':
                tabela[i].prata--;
                break;
            
            case 'B':
                tabela[i].bronze--;
                break;

            default:
                break;
            }//switch
            
            break;
        }//if
    }//for

    if (contador2 == 0) {
        printf("Atleta não encontrado\n");
    }//if
}//excluir_medalha

void menu(Medalhas *medalhas, Bruto_tabela *total_medalhas) {
    int opcao;
    printf("\nBem-vindo ao Sistema de Gerenciamento de Medalhas\n");

    do {
        printf("\n======== MENU ========\n");
        printf("1. Inserir Medalha\n");
        printf("2. Listar Medalhas\n");
        printf("3. Buscar Medalha\n");
        printf("4. Alterar Medalha\n");
        printf("5. Excluir Medalha\n");
        printf("6. Exportar dados para CSV\n");
        printf("7. Exibir tabela\n");
        printf("8. Sair\n");
        printf("======================\n");
        printf("Escolha uma opção: ");
        setbuf(stdin, NULL);
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserir_medalha(medalhas, total_medalhas);
                break;
            case 2:
                listar_medalhas(medalhas, total_medalhas);
                break;
            case 3:
                pesquisar_medalha(medalhas, total_medalhas);
                break;
            case 4:
                alterar_medalha(medalhas, total_medalhas);
                break;
            case 5:
                excluir_medalha(medalhas, total_medalhas);
                break;
            case 6:
                exportar_para_csv(medalhas, total_medalhas);
                break;
            case 7:
                imprime_tabela(total_medalhas);
                break;
            case 8:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção invalida!\n");
                break;
        }//switch
    } while (opcao != 8);
}//menu
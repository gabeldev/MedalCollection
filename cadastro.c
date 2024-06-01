#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "Cadastro.h"
#include "tabelas.h"


char* transformar_minusculo(char *str) {
    char *resultado = malloc(strlen(str) + 1); // +1 para o caractere nulo
    if (resultado == NULL) {
        return NULL; // Erro na alocação de memória
    }

    strcpy(resultado, str);

    for (int i = 0; resultado[i]; i++) {
        resultado[i] = tolower((char) resultado[i]);
    }
    return resultado;
}

void inserir_medalha(Medalhas *medalha, Dados_tabela *tabela) {

    char nome_atleta[50];
    int contador2 = 0;
    char tipo_medalha;

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

void listar_medalhas(Medalhas *medalha, Dados_tabela *tabela) { // Lista as medalhas de um atleta

    char nome_atleta[50];
    int contador2 = 0;
    char tipo_medalha;

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

void pesquisar_medalha(Medalhas *medalha, Dados_tabela *tabela) { // Pesquisa as medalhas de um atleta

    char nome_atleta[50];
    int contador2 = 0;
    char tipo_medalha;

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

void alterar_medalha(Medalhas *medalha, Dados_tabela *tabela) {
    char nome_atleta[50];
    int contador2 = 0;
    char tipo_medalha;
    int altera_medalha;

    printf("Digite o nome do atleta em que a medalha deve ser alterada: ");
    fgets(nome_atleta, 50, stdin);
    nome_atleta[strcspn(nome_atleta, "\n")] = '\0';
    setbuf(stdin, NULL);

    for (int i = 0; i < 2395; i++) {
        if(strcmp(transformar_minusculo(nome_atleta), transformar_minusculo(medalha[i].nome_atleta)) == 0) {
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
            
            printf("Digite o novo tipo de medalha: ");
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

void excluir_medalha(Medalhas *medalha, Dados_tabela *tabela) {
    char nome_atleta[50];
    int contador2 = 0;
    char tipo_medalha;

    printf("Digite o nome do atleta a ser excluído: ");
    fgets(nome_atleta, 50, stdin);
    nome_atleta[strcspn(nome_atleta, "\n")] = '\0';
    setbuf(stdin, NULL);

    for (int i = 1; i <= 2394; i++) {
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
            } while (tipo_medalha != 'G' && tipo_medalha != 'S' && tipo_medalha != 'B');
            
            
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

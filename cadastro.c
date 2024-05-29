#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cadastro.h"
#include "tabelas.h"

void inserir_medalha(Medalhas *medalha, Dados_tabela *tabela) {

    char nome_atleta[50];
    int contador2 = 0;
    char tipo_medalha;

    printf("Digite o nome do atleta: ");
    fgets(nome_atleta, 50, stdin);
    nome_atleta[strcspn(nome_atleta, "\n")] = '\0';
    setbuf(stdin, NULL);

    for (int i = 1; i <= 2394; i++) {
        if(strcmp(nome_atleta, medalha[i].nome_atleta) == 0) {
            printf("Atleta encontrado\n");
            contador2 = i;
            
            do {
                printf("Ouro - G, Prata - S, Bronze - B\n");
                printf("Digite o tipo de medalha a ser adicionado: ");
                scanf(" %c", &tipo_medalha);
                if (tipo_medalha != 'G' || tipo_medalha != 'S' || tipo_medalha != 'B') {
                    printf("Tipo de medalha inválido\n");
                }
            } while (tipo_medalha != 'G' || tipo_medalha != 'S' || tipo_medalha != 'B');
            
            
            switch (tipo_medalha) {
            case 'G':
                tabela[contador2].ouro++;
                break;
            
            case 'S':
                tabela[contador2].prata++;
                break;
            
            case 'B':
                tabela[contador2].bronze++;
                break;

            default:
                break;
            }//switch
            
        }//if
        break;
        
    }//for

    if (contador2 == 0) {
        printf("Atleta não encontrado\n");
    }//if
}//inserir_medalha

void listar_medalhas(Medalhas *medalha, Dados_tabela *tabela) {
    printf("Lista de medalhas: \n");
    for (int i = 1; i <= 2394; i++) {
        printf("Nome do atleta: %s\n", medalha[i].nome_atleta);
        printf("Ouro: %d\n", tabela[i].ouro);
        printf("Prata: %d\n", tabela[i].prata);
        printf("Bronze: %d\n", tabela[i].bronze);
    }//for

}//listar_medalhas

void pesquisar_medalha(Medalhas *medalha, Dados_tabela *tabela) {
    char nome_atleta[50];
    int contador2 = 0;

    printf("Digite o nome do atleta a ser pesquisado: ");
    fgets(nome_atleta, 50, stdin);
    nome_atleta[strcspn(nome_atleta, "\n")] = '\0';
    setbuf(stdin, NULL);

    for (int i = 1; i <= 2394; i++) {
        if(strcmp(nome_atleta, medalha[i].nome_atleta) == 0) {
            printf("Atleta encontrado\n");
            contador2 = i;
            printf("Nome do atleta: %s\n", medalha[i].nome_atleta);
            printf("Ouro: %d\n", tabela[i].ouro);
            printf("Prata: %d\n", tabela[i].prata);
            printf("Bronze: %d\n", tabela[i].bronze);
        }//if
        break;
    }//for

    if (contador2 == 0) {
        printf("Atleta não encontrado\n");
    }//if
}//pesquisar_medalha

void alterar_medalha(Medalhas *medalha, Dados_tabela *tabela) {
    char nome_atleta[50];
    int contador2 = 0;
    char tipo_medalha;

    printf("Digite o nome do atleta a ser alterado: ");
    fgets(nome_atleta, 50, stdin);
    nome_atleta[strcspn(nome_atleta, "\n")] = '\0';
    setbuf(stdin, NULL);

    for (int i = 1; i <= 2394; i++) {
        if(strcmp(nome_atleta, medalha[i].nome_atleta) == 0) {
            printf("Atleta encontrado\n");
            contador2 = i;
            
            do {
                printf("Ouro - G, Prata - S, Bronze - B\n");
                printf("Digite o tipo de medalha a ser adicionado: ");
                scanf(" %c", &tipo_medalha);
                if (tipo_medalha != 'G' || tipo_medalha != 'S' || tipo_medalha != 'B') {
                    printf("Tipo de medalha inválido\n");
                }
            } while (tipo_medalha != 'G' || tipo_medalha != 'S' || tipo_medalha != 'B');
            
            
            switch (tipo_medalha) {
            case 'G':
                tabela[contador2].ouro++;
                break;
            
            case 'S':
                tabela[contador2].prata++;
                break;
            
            case 'B':
                tabela[contador2].bronze++;
                break;

            default:
                break;
            }//switch
            
        }//if
        break;
        
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
        if(strcmp(nome_atleta, medalha[i].nome_atleta) == 0) {
            printf("Atleta encontrado\n");
            contador2 = i;
            
            do {
                printf("Ouro - G, Prata - S, Bronze - B\n");
                printf("Digite o tipo de medalha a ser excluído: ");
                scanf(" %c", &tipo_medalha);
                if (tipo_medalha != 'G' || tipo_medalha != 'S' || tipo_medalha != 'B') {
                    printf("Tipo de medalha inválido\n");
                }
            } while (tipo_medalha != 'G' || tipo_medalha != 'S' || tipo_medalha != 'B');
            
            
            switch (tipo_medalha) {
            case 'G':
                tabela[contador2].ouro--;
                break;
            
            case 'S':
                tabela[contador2].prata--;
                break;
            
            case 'B':
                tabela[contador2].bronze--;
                break;

            default:
                break;
            }//switch
            
        }//if
        break;
        
    }//for

    if (contador2 == 0) {
        printf("Atleta não encontrado\n");
    }//if
}//excluir_medalha

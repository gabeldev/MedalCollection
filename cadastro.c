#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "structs.h"
#include "cadastro.h"
#include "tabelas.h"

char* transformar_minusculo(char *str) {

    char *resultado = malloc(strlen(str) + 1); // +1 para o caractere nulo
    if (resultado == NULL) {
        return NULL; // Erro na alocação de memória
    }//if

    strcpy(resultado, str);

    for (int i = 0; resultado[i]; i++) { // Converte a string para minúsculo
        resultado[i] = tolower((char) resultado[i]);
    }//for
    return resultado;
}//transformar_minusculo

void inserir_medalha(Medalhas *medalha, Bruto_tabela *tabela) { // Insere uma medalha para um atleta

    char nome_atleta[50];
    int contador2 = 0;
    char tipo_medalha;

    setbuf(stdin, NULL);
    printf("Digite o nome do atleta: ");
    fgets(nome_atleta, 50, stdin);
    nome_atleta[strcspn(nome_atleta, "\n")] = '\0';

    for (int i = 0; i < 2395; i++) {
        if(strcmp(transformar_minusculo(nome_atleta), transformar_minusculo(medalha[i].nome_atleta)) == 0) { // Se o atleta já estiver cadastrado
            printf("Atleta encontrado\n");
            contador2 = 1;
            
            do { // Verifica se o tipo de medalha é válido
                printf("Ouro - G, Prata - S, Bronze - B\n");
                printf("Digite o tipo de medalha a ser adicionado: ");
                setbuf(stdin, NULL);
                scanf("%c", &tipo_medalha);
                if ((tipo_medalha != 'G' && tipo_medalha !='g') && (tipo_medalha != 'S' && tipo_medalha != 's') && 
                    (tipo_medalha != 'B' && tipo_medalha != 'b')) {
                    printf("Tipo de medalha inválido\n");
                }//if
            } while ((tipo_medalha != 'G' && tipo_medalha !='g') && (tipo_medalha != 'S' && tipo_medalha != 's') && 
                    (tipo_medalha != 'B' && tipo_medalha != 'b'));
            
            switch (tipo_medalha) { // Adiciona a medalha
                case 'g':
                case 'G':
                    tabela[i].ouro++;
                    break;
                case 's':
                case 'S':
                    tabela[i].prata++;
                    break;
                case 'b':
                case 'B':
                    tabela[i].bronze++;
                    break;
            }//switch
            printf("Medalha inserida com sucesso!\n");
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

    setbuf(stdin, NULL);
    printf("Digite o nome do atleta: ");
    fgets(nome_atleta, 50, stdin);
    nome_atleta[strcspn(nome_atleta, "\n")] = '\0';

    for (int i = 0; i < 2395; i++) {
        if(strcmp(transformar_minusculo(nome_atleta), transformar_minusculo(medalha[i].nome_atleta)) == 0) { // Se o atleta já estiver cadastrado
            printf("Atleta encontrado\n");
            contador2 = 1;
            printf("Nome do atleta: %s\n", medalha[i].nome_atleta);
            printf("Genero: %c\n", medalha[i].genero);
            printf("Modalidade: %s\n", medalha[i].modalidade);
            printf("Cidade: %s\n", medalha[i].cidade);
            printf("Ano: %d\n", medalha[i].ano);
            printf("País de origem: %s\n", tabela[i].pais);
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

    for (int i = 0; i < 2395; i++) { // Verifica se o atleta já está cadastrado
        if(strcmp(transformar_minusculo(nome_atleta), transformar_minusculo(medalha[i].nome_atleta)) == 0) { // Se o atleta já estiver cadastrado
            printf("Atleta encontrado\n");
            contador2 = 1;

            do { // Verifica se o tipo de medalha é válido
                printf("Ouro - G, Prata - S, Bronze - B\n");
                printf("Digite o tipo de medalha a ser pesquisado: ");
                scanf("%c", &tipo_medalha);
                if ((tipo_medalha != 'G' && tipo_medalha !='g') && (tipo_medalha != 'S'&& tipo_medalha != 's') && 
                    (tipo_medalha != 'B'&& tipo_medalha != 'b')) {
                    printf("Tipo de medalha inválido\n");
                }//if
            } while ((tipo_medalha != 'G' && tipo_medalha !='g') && (tipo_medalha != 'S'&& tipo_medalha != 's') && 
                    (tipo_medalha != 'B'&& tipo_medalha != 'b'));

            switch (tipo_medalha) { // Mostra as medalhas
                case 'g':
                case 'G':
                    printf("Nome do atleta: %s\n", medalha[i].nome_atleta);
                    printf("Genero: %c\n", medalha[i].genero);
                    printf("Modalidade: %s\n", medalha[i].modalidade);
                    printf("Cidade: %s\n", medalha[i].cidade);
                    printf("Ano: %d\n", medalha[i].ano);
                    printf("Tipo de Medalha: %c\n", medalha[i].gbs);
                    printf("País de origem: %s\n", tabela[i].pais);
                    printf("Ouro: %d\n", tabela[i].ouro);
                    break;
                case 's':
                case 'S':
                    printf("Nome do atleta: %s\n", medalha[i].nome_atleta);
                    printf("Genero: %c\n", medalha[i].genero);
                    printf("Modalidade: %s\n", medalha[i].modalidade);
                    printf("Cidade: %s\n", medalha[i].cidade);
                    printf("Ano: %d\n", medalha[i].ano);
                    printf("Tipo de Medalha: %c\n", medalha[i].gbs);
                    printf("País de origem: %s\n", medalha[i].pais_origem);
                    printf("Prata: %d\n", tabela[i].prata);
                    break;
                case 'b':
                case 'B':
                    printf("Nome do atleta: %s\n", medalha[i].nome_atleta);
                    printf("Genero: %c\n", medalha[i].genero);
                    printf("Modalidade: %s\n", medalha[i].modalidade);
                    printf("Cidade: %s\n", medalha[i].cidade);
                    printf("Ano: %d\n", medalha[i].ano);
                    printf("Tipo de Medalha: %c\n", medalha[i].gbs);
                    printf("País de origem: %s\n", medalha[i].pais_origem);
                    printf("Bronze: %d\n", tabela[i].bronze);
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

    for (int i = 0; i < 2395; i++) {
        if(strcmp(transformar_minusculo(nome_atleta), transformar_minusculo(medalha[i].nome_atleta)) == 0) { // Se o atleta já estiver cadastrado
            printf("Atleta encontrado\n");
            contador2 = 1;
            
            do {
                printf("Ouro - G, Prata - S, Bronze - B\n");
                printf("Digite o tipo de medalha a ser alterado: ");
                scanf(" %c", &tipo_medalha);
                if ((tipo_medalha != 'G' && tipo_medalha !='g') && (tipo_medalha != 'S'&& tipo_medalha != 's') && 
                    (tipo_medalha != 'B'&& tipo_medalha != 'b')) {
                    printf("Tipo de medalha inválido\n");
                }//if
            } while ((tipo_medalha != 'G' &&tipo_medalha !='g') && (tipo_medalha != 'S'&& tipo_medalha != 's') && 
                    (tipo_medalha != 'B'&& tipo_medalha != 'b'));
            
        do{
            printf("Digite a nova quantidade de medalhas: ");
            setbuf(stdin, NULL);
            scanf("%d", &altera_medalha);
            if(altera_medalha < 0) {
                printf("Quantidade inválida\n");
                break;
            }//if
        } while(altera_medalha < 0);
            
            
            switch (tipo_medalha) {
                case 'g':
                case 'G':
                    tabela[i].ouro = altera_medalha;
                    break;
                case 's':
                case 'S':
                    tabela[i].prata = altera_medalha;
                    break;
                case 'b':
                case 'B':
                    tabela[i].bronze = altera_medalha;
                    break;
            }//switch
            printf("Medalha alterada com sucesso!\n");
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

    for (int i = 0; i < 2395; i++) {
        if(strcmp(transformar_minusculo(nome_atleta), transformar_minusculo(medalha[i].nome_atleta)) == 0) {
            printf("Atleta encontrado\n");
            contador2 = 1;
            
            do {
                printf("Ouro - G, Prata - S, Bronze - B\n");
                printf("Digite o tipo de medalha a ser excluído: ");
                setbuf(stdin, NULL);
                scanf(" %c", &tipo_medalha);
                if ((tipo_medalha != 'G' &&tipo_medalha !='g') && (tipo_medalha != 'S'&& tipo_medalha != 's') && 
                    (tipo_medalha != 'B'&& tipo_medalha != 'b')) {
                    printf("Tipo de medalha inválido\n");
                }//if
            } while ((tipo_medalha != 'G' &&tipo_medalha !='g') && (tipo_medalha != 'S'&& tipo_medalha != 's') && 
                    (tipo_medalha != 'B'&& tipo_medalha != 'b'));
            
            switch (tipo_medalha) {
                case 'g':
                case 'G':
                    if (tabela[i].ouro > 0) {
                        tabela[i].ouro--;
                        printf("Medalha excluída com sucesso!\n");
                    } else {
                        printf("Atleta não possui medalhas de ouro\n");
                    }//if else
                    break;
                case 's':   
                case 'S':
                    if (tabela[i].prata > 0) {
                        tabela[i].prata--;
                        printf("Medalha excluída com sucesso!\n");
                    } else {
                        printf("Atleta não possui medalhas de prata\n");
                    }//if else
                    break;
                case 'b':  
                case 'B':
                    if (tabela[i].bronze > 0) {
                        tabela[i].bronze--;
                        printf("Medalha excluída com sucesso!\n");
                    } else {
                        printf("Atleta não possui medalhas de bronze\n");
                    }//if else
                    break;
            }//switch
            break;
        }//if
    }//for

    if (contador2 == 0) {
        printf("Atleta não encontrado\n");
    }//if
}//excluir_medalha

void exportar_para_csv(Medalhas *medalha, Bruto_tabela *tabela) {
    
    FILE *file = fopen("medalhas_exportadas.csv", "w");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo para escrita!\n");
        exit(1);
    }//if

    // Itera sobre todas as medalhas 
    for (int i = 0; i < 2395; i++) {
        // Escreve uma linha para cada medalha de ouro
        for (int j = 0; j < tabela[i].ouro; j++) {
            fprintf(file, "%c,%s,%s,%d,G,%s,%s,%s\n", 
                    medalha[i].genero,
                    medalha[i].modalidade,
                    medalha[i].cidade,
                    medalha[i].ano,
                    medalha[i].nome_atleta,
                    medalha[i].pais_origem,
                    medalha[i].armazena_resultado);
            printf("%s\n", medalha[i].armazena_resultado);
        }//for

        // Escreve uma linha para cada medalha de prata
        for (int j = 0; j < tabela[i].prata; j++) {
            fprintf(file, "%c,%s,%s,%d,S,%s,%s,%s\n", 
                    medalha[i].genero,
                    medalha[i].modalidade,
                    medalha[i].cidade,
                    medalha[i].ano,
                    medalha[i].nome_atleta,
                    medalha[i].pais_origem,
                    medalha[i].armazena_resultado);
            printf("%s\n", medalha[i].armazena_resultado);
        }//for

        // Escreve uma linha para cada medalha de bronze
        for (int j = 0; j < tabela[i].bronze; j++) {
            fprintf(file, "%c,%s,%s,%d,B,%s,%s,%s\n", 
                    medalha[i].genero,
                    medalha[i].modalidade,
                    medalha[i].cidade,
                    medalha[i].ano,
                    medalha[i].nome_atleta,
                    medalha[i].pais_origem,
                    medalha[i].armazena_resultado);
            printf("%s\n", medalha[i].armazena_resultado);
        }//for
    }//for
    fclose(file);
    printf("Dados exportados com sucesso!\n");
}//exportar_para_csv

void menu(Medalhas *medalha, Bruto_tabela *tabela) {

    int opcao;
    printf("\nBem-vindo ao Sistema de Gerenciamento de Medalhas!\n");

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
                inserir_medalha(medalha, tabela); // Insere uma medalha
                break;
            case 2:
                listar_medalhas(medalha, tabela); // Lista as medalhas
                break;
            case 3:
                pesquisar_medalha(medalha, tabela); // Pesquisa uma medalha
                break;
            case 4:
                alterar_medalha(medalha, tabela); // Altera uma medalha
                break;
            case 5:
                excluir_medalha(medalha, tabela); // Exclui uma medalha
                break;
            case 6:
                exportar_para_csv(medalha, tabela); // Exporta os dados para um arquivo CSV
                break;
            case 7:
                imprime_tabela(tabela); // Exibe a tabela de medalhas
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
#include "tabelas.h"


void imprime_cabecalho(const Dados_tabela *tabela) {
    printf("\n\033[1;33m"); // Amarelo em negrito
    printf("--------------------------------------------------------\n");
    printf("|🎉 QUADRO DE MEDALHAS OLÍMPICAS - EDIÇÃO %d - %s 🎉|\n", tabela->ano, tabela->cidade_realizado);
    printf("--------------------------------------------------------\n");
    printf("\033[0m");
    printf("\n\033[1;25m"); // Resetar cores
    printf("| PAÍS       | 🥇OURO | 🥈PRATA |🥉BRONZE | TOTAL |\n");
    printf("---------------------------------------------------\n");
}

void imprime_linhas(const Dados_tabela *tabela) {
    printf("| %-10s |   %2d   |   %2d    |   %2d    |   %2d  |\n",
           tabela->pais, tabela->ouro, tabela->prata, tabela->bronze, tabela->total);
}













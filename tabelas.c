#include "tabelas.h"


void imprime_cabecalho(const Medalhas *medalha) {
    printf("\n\033[1;33m"); // Amarelo em negrito
    printf("--------------------------------------------------------\n");
    printf("|🎉 QUADRO DE MEDALHAS OLÍMPICAS - EDIÇÃO %d - %s 🎉|\n", medalha->ano, medalha->cidade);
    printf("--------------------------------------------------------\n");
    printf("\033[0m");
    printf("\n\033[1;25m"); // Resetar cores
    printf("| PAÍS       | 🥇OURO | 🥈PRATA |🥉BRONZE | TOTAL |\n");
    printf("---------------------------------------------------\n");
}

void imprime_linhas(const Medalhas *medalha) {
    printf("| %-10s |   %2d   |   %2d    |   %2d    |   %2d  |\n",
           medalha->nome, pais->ouro, pais->prata, pais->bronze, pais->total);
}













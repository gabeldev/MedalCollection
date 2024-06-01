#ifndef TABELAS_H
#define TABELAS_H

#include <stdio.h>

typedef struct {
    char pais[30];
    char cidade_realizado[30];
    int edicao;
    int ouro; 
    int prata;
    int bronze;
    int total;
    int ano;
}Dados_tabela;
void converte_tabela(Dados_tabela *tabela, Medalhas *medalha); // Converte os dados da estrutura Medalhas para a estrutura Dados_tabela

void imprime_tabela(Dados_tabela *tabela); // Imprime a tabela


#endif
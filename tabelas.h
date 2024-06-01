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

void imprime_cabecalho(const Dados_tabela *tabela); // Imprime o cabeçalho da tabela

void imprime_linhas(const Dados_tabela *tabela); // Imprime as linhas da tabela




#endif
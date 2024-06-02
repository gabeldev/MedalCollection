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
    int ano;
}Bruto_tabela;

typedef struct {
    char pais[30];
    char cidade_realizado[30];
    int edicao;
    int ouro; 
    int prata;
    int bronze;
    int total;
    int ano;
}Tratado_tabela;

void converte_tabela(Bruto_tabela *converte,  Medalhas *medalha); // Converte os dados da estrutura Medalhas para a estrutura Dados_tabela

void imprime_tabela(Bruto_tabela *converte); // Imprime a tabela

void imprime_linhas(Tratado_tabela *tabela); // Imprime as linhas da tabela


#endif
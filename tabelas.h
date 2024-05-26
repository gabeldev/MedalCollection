#ifndef TABELAS_H
#define TABELAS_H

#include <stdio.h>

typedef struct {
    int codigo;
    char genero;
    char modalidade[50];
    char cidade[50];
    int ano;
    char tipo_medalha;
    char nome_atleta[50];
    char pais_origem[50];
    float resultado;
}Medalhas;


void imprime_cabecalho(const Medalhas *medalha); // Imprime o cabeçalho da tabela

void imprime_linhas(const Medalhas *medalha); // Imprime as linhas da tabela




#endif
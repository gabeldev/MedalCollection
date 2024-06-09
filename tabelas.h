#ifndef TABELAS_H
#define TABELAS_H

#include <stdio.h>
#include "structs.h"
#include "cadastro.h"

void converte_tabela(Bruto_tabela *tabela,  Medalhas *medalha); // Converte os dados da estrutura Medalhas para a estrutura Dados_tabela

void imprime_tabela(Bruto_tabela *tabela); // Imprime a tabela

void imprime_linhas(Tratado_tabela *tabela_tratada); // Imprime as linhas da tabela


#endif
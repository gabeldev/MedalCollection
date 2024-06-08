#ifndef CADASTRO_H
#define CADASTRO_H

#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "tabelas.h"

char* transformar_minusculo(char *str);

void inserir_medalha(Medalhas *medalha, Bruto_tabela *tabela);

void listar_medalhas(Medalhas *medalha, Bruto_tabela *tabela);

void pesquisar_medalha(Medalhas *medalha, Bruto_tabela *tabela);

void alterar_medalha(Medalhas *medalha, Bruto_tabela *tabela);

void excluir_medalha(Medalhas *medalha, Bruto_tabela *tabela);

void exportar_para_csv(Medalhas *medalha, Bruto_tabela *tabela);

void menu(Medalhas *medalha, Bruto_tabela *tabela);

#endif
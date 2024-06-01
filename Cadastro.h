/**
 * @file Cadastro.h
 * @author Elder Nunes (eldernunes@alunos.utfpr.edu.br)
 * @brief 
 * @version 0.1
 * @date 2024-05-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef CADASTRO_H
#define CADASTRO_H

#include<stdio.h>
#include<stdlib.h>
#include "tabelas.h"

/*
Defina uma estrutura Medalha contendo: Código (contador inteiro), Gênero (char),
Modalidade(string), Cidade(string), Ano(int), Tipo Medalha GBS(char), Nome
Atleta(string), Pais Origem (string), Resultado (?). Deverá permitir cadastrar
(inserir/listar/pesquisar/alterar/excluir) as medalhas obtidas por cada atleta. Essa relação
deve aumentar e diminuir dinamicamente;
*/


//Estrutura Tempo
typedef struct {
    float hora;
    float minuto;
    float segundo;
    float milissegundo;
}Tempo;

//União Resultado
typedef union {
    Tempo tempo;
    float distancia;
    float pontos;
}Resultado;

//Estrutura Medalha
typedef struct{
    int contador;
    char genero;
    char modalidade[50];
    char cidade[50];
    int ano;
    char gbs;
    char nome_atleta[50];
    char pais_origem[3];
    Resultado resultado;
}Medalhas;

char* transformar_minusculo(char *str);

void inserir_medalha(Medalhas *medalha, Dados_tabela *tabela);

void listar_medalhas(Medalhas *medalha, Dados_tabela *tabela);

void pesquisar_medalha(Medalhas *medalha, Dados_tabela *tabela);

void alterar_medalha(Medalhas *medalha, Dados_tabela *tabela);

void excluir_medalha(Medalhas *medalha, Dados_tabela *tabela);

#endif
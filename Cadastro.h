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

/*
Defina uma estrutura Medalha contendo: Código (contador inteiro), Gênero (char),
Modalidade(string), Cidade(string), Ano(int), Tipo Medalha GBS(char), Nome
Atleta(string), Pais Origem (string), Resultado (?). Deverá permitir cadastrar
(inserir/listar/pesquisar/alterar/excluir) as medalhas obtidas por cada atleta. Essa relação
deve aumentar e diminuir dinamicamente;
*/

//Estrutura Medalha
typedef struct{
    int contador;
    char genero;
    char modalidade[50];
    char cidade[50];
    int ano;
    char gbs;
    char nome_atleta[50];
    char pais_origem[50];
    float resultado;
}Medalhas;

#endif
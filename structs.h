#ifndef STRUCTS_H
#define STRUCTS_H

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

#endif
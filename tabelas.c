#include <string.h>
#include <stdio.h>
#include "tabelas.h"
#include "Cadastro.h"


void converte_tabela(Dados_tabela *tabela, Medalhas *medalha) { // Converte os dados da estrutura Medalhas para a estrutura Dados_tabela
    
    tabela = realloc(tabela, 2395 * sizeof(Dados_tabela));

    for(int i = 0; i < 2395; i++) {
        strcpy(tabela[i].cidade_realizado, medalha[i].cidade);
        tabela[i].ano = medalha[i].ano;

        if (medalha[i].gbs == 'G') {
            tabela[i].ouro = 1;
            tabela[i].prata = 0;
            tabela[i].bronze = 0;
        } else if (medalha[i].gbs == 'S') { 
            tabela[i].ouro = 0;
            tabela[i].prata = 1;
            tabela[i].bronze = 0;
        } else if (medalha[i].gbs == 'B') {
            tabela[i].ouro = 0;
            tabela[i].prata = 0;
            tabela[i].bronze = 1;
        }

        switch (medalha[i].ano)
        {
        case 1896:
            tabela->edicao = 1;
            break;
        
        case 1900:
            tabela->edicao = 2;
            break;

        case 1904: 
            tabela->edicao = 3;
            break;
        
        case 1908:
            tabela->edicao = 4;
            break;
        
        case 1912:  
            tabela->edicao = 5;
            break;

        case 1920:
            tabela->edicao = 7;
            break;
        
        case 1924:  
            tabela->edicao = 8;
            break;
        
        case 1928:  
            tabela->edicao = 9;
            break;
        
        case 1932:
            tabela->edicao = 10;
            break;
        
        case 1936:
            tabela->edicao = 11;
            break;
        
        case 1948:
            tabela->edicao = 14;
            break;
        
        case 1952:
            tabela->edicao = 15;
            break;

        case 1956:
            tabela->edicao = 16;
            break;

        case 1960:
            tabela->edicao = 17;
            break;
        
        case 1964:
            tabela->edicao = 18;
            break;
        
        case 1968:
            tabela->edicao = 19;
            break;

        case 1972:
            tabela->edicao = 20;
            break;

        case 1976:
            tabela->edicao = 21;
            break;

        case 1980:
            tabela->edicao = 22;
            break;

        case 1984:
            tabela->edicao = 23;
            break;

        case 1988:
            tabela->edicao = 24;
            break;

        case 1992:
            tabela->edicao = 25;
            break;

        case 1996:
            tabela->edicao = 26;
            break;

        case 2000:
            tabela->edicao = 27;
            break;

        case 2004:
            tabela->edicao = 28;
            break;

        case 2008:
            tabela->edicao = 29;
            break;

        case 2012:
            tabela->edicao = 30;
            break;

        case 2016:
            tabela->edicao = 31;
            break;

        default:
            break;
        }

        if (strcmp(medalha[i].pais_origem, "BRA") == 0) {
            strcpy(tabela[i].pais, "Brasil");
        } else if (strcmp(medalha[i].pais_origem, "USA") == 0) {
            strcpy(tabela[i].pais, "Estados Unidos");
        } else if (strcmp(medalha[i].pais_origem, "CHN") == 0) {
            strcpy(tabela[i].pais, "China");
        } else if (strcmp(medalha[i].pais_origem, "RUS") == 0) {
            strcpy(tabela[i].pais, "Rússia");
        } else if (strcmp(medalha[i].pais_origem, "GER") == 0) {
            strcpy(tabela[i].pais, "Alemanha");
        } else if (strcmp(medalha[i].pais_origem, "JPN") == 0) {
            strcpy(tabela[i].pais, "Japão");
        } else if (strcmp(medalha[i].pais_origem, "FRA") == 0) {
            strcpy(tabela[i].pais, "França");
        } else if (strcmp(medalha[i].pais_origem, "GBR") == 0) {
            strcpy(tabela[i].pais, "Reino Unido");
        } else if (strcmp(medalha[i].pais_origem, "ITA") == 0) {
            strcpy(tabela[i].pais, "Itália");
        } else if (strcmp(medalha[i].pais_origem, "AUS") == 0) {
            strcpy(tabela[i].pais, "Austrália");
        } else if (strcmp(medalha[i].pais_origem, "CAN") == 0) {
            strcpy(tabela[i].pais, "Canadá");
        } else if (strcmp(medalha[i].pais_origem, "KOR") == 0) {
            strcpy(tabela[i].pais, "Coreia do Sul");
        } else if (strcmp(medalha[i].pais_origem, "NED") == 0) {
            strcpy(tabela[i].pais, "Holanda");
        } else if (strcmp(medalha[i].pais_origem, "HUN") == 0) {
            strcpy(tabela[i].pais, "Hungria");
        } else if (strcmp(medalha[i].pais_origem, "UKR") == 0) {
            strcpy(tabela[i].pais, "Ucrânia");
        } else if (strcmp(medalha[i].pais_origem, "ESP") == 0) {
            strcpy(tabela[i].pais, "Espanha");
        } else if (strcmp(medalha[i].pais_origem, "NZL") == 0) {
            strcpy(tabela[i].pais, "Nova Zelândia");
        } else if (strcmp(medalha[i].pais_origem, "CUB") == 0) {
            strcpy(tabela[i].pais, "Cuba");
        } else if (strcmp(medalha[i].pais_origem, "NOR") == 0) {
            strcpy(tabela[i].pais, "Noruega");
        } else if (strcmp(medalha[i].pais_origem, "BUL") == 0) {
            strcpy(tabela[i].pais, "Bulgária");
        } else if (strcmp(medalha[i].pais_origem, "POL") == 0) {
            strcpy(tabela[i].pais, "Polônia");
        } else if (strcmp(medalha[i].pais_origem, "SWE") == 0) {
            strcpy(tabela[i].pais, "Suécia");
        } else if (strcmp(medalha[i].pais_origem, "CZE") == 0) { 
            strcpy(tabela[i].pais, "República Tcheca");
        } else if (strcmp(medalha[i].pais_origem, "ETH") == 0) {
            strcpy(tabela[i].pais, "Etiópia");
        } else if (strcmp(medalha[i].pais_origem, "KEN") == 0) {
            strcpy(tabela[i].pais, "Quênia");
        } else if (strcmp(medalha[i].pais_origem, "RSA") == 0) {
            strcpy(tabela[i].pais, "África do Sul");
        } else if (strcmp(medalha[i].pais_origem, "JAM") == 0) {
            strcpy(tabela[i].pais, "Jamaica");
        } else if (strcmp(medalha[i].pais_origem, "TUR") == 0) {
            strcpy(tabela[i].pais, "Turquia");
        } else if (strcmp(medalha[i].pais_origem, "IRI") == 0) {
            strcpy(tabela[i].pais, "Irã");
        } else if (strcmp(medalha[i].pais_origem, "SVK") == 0) {
            strcpy(tabela[i].pais, "Eslováquia");
        } else if (strcmp(medalha[i].pais_origem, "BLR") == 0) {
            strcpy(tabela[i].pais, "Bielorrússia");
        } else if (strcmp(medalha[i].pais_origem, "ROU") == 0) {
            strcpy(tabela[i].pais, "Romênia");
        } else if (strcmp(medalha[i].pais_origem, "FIN") == 0) {
            strcpy(tabela[i].pais, "Finlândia");
        } else if (strcmp(medalha[i].pais_origem, "SUI") == 0) {
            strcpy(tabela[i].pais, "Suíça");
        } else if (strcmp(medalha[i].pais_origem, "DEN") == 0) {
            strcpy(tabela[i].pais, "Dinamarca");
        } else if (strcmp(medalha[i].pais_origem, "BEL") == 0) {
            strcpy(tabela[i].pais, "Bélgica");
        } else if (strcmp(medalha[i].pais_origem, "IND") == 0) {
            strcpy(tabela[i].pais, "Índia");
        } else if (strcmp(medalha[i].pais_origem, "POR") == 0) {
            strcpy(tabela[i].pais, "Portugal");
        } else if (strcmp(medalha[i].pais_origem, "GRE") == 0) {
            strcpy(tabela[i].pais, "Grécia");
        } else if (strcmp(medalha[i].pais_origem, "LAT") == 0) {
            strcpy(tabela[i].pais, "Letônia");
        } else if (strcmp(medalha[i].pais_origem, "MEX") == 0) {
            strcpy(tabela[i].pais, "México");
        } else if (strcmp(medalha[i].pais_origem, "ARG") == 0) {
            strcpy(tabela[i].pais, "Argentina");
        } else if (strcmp(medalha[i].pais_origem, "COL") == 0) {
            strcpy(tabela[i].pais, "Colômbia");
        } else if (strcmp(medalha[i].pais_origem, "CRO") == 0) {
            strcpy(tabela[i].pais, "Croácia");
        } else if (strcmp(medalha[i].pais_origem, "EST") == 0) {
            strcpy(tabela[i].pais, "Estônia");
        } else if (strcmp(medalha[i].pais_origem, "IRL") == 0) {
            strcpy(tabela[i].pais, "Irlanda");
        } else if (strcmp(medalha[i].pais_origem, "LTU") == 0) {
            strcpy(tabela[i].pais, "Lituânia");
        } else if (strcmp(medalha[i].pais_origem, "SLO") == 0) {
            strcpy(tabela[i].pais, "Eslovênia");
        } else if (strcmp(medalha[i].pais_origem, "TUN") == 0) {
            strcpy(tabela[i].pais, "Tunísia");
        } else if (strcmp(medalha[i].pais_origem, "VEN") == 0) { 
            strcpy(tabela[i].pais, "Venezuela");
        } else if (strcmp(medalha[i].pais_origem, "BAH") == 0) {
            strcpy(tabela[i].pais, "Bahamas");
        } else if (strcmp(medalha[i].pais_origem, "MAR") == 0) {
            strcpy(tabela[i].pais, "Marrocos");
        } else if (strcmp(medalha[i].pais_origem, "NGR") == 0) {
            strcpy(tabela[i].pais, "Nigéria");
        } else if (strcmp(medalha[i].pais_origem, "QAT") == 0) {
            strcpy(tabela[i].pais, "Catar");
        } else if (strcmp(medalha[i].pais_origem, "SIN") == 0) {
            strcpy(tabela[i].pais, "Singapura");
        } else if (strcmp(medalha[i].pais_origem, "SUD") == 0) {
            strcpy(tabela[i].pais, "Sudão");
        } else if (strcmp(medalha[i].pais_origem, "TPE") == 0) {
            strcpy(tabela[i].pais, "Taiwan");
        } else if (strcmp(medalha[i].pais_origem, "ALG") == 0) {
            strcpy(tabela[i].pais, "Argélia");
        } else if (strcmp(medalha[i].pais_origem, "BOT") == 0) {
            strcpy(tabela[i].pais, "Botsuana");
        } else if (strcmp(medalha[i].pais_origem, "BRN") == 0) {
            strcpy(tabela[i].pais, "Bahrein");
        } else if (strcmp(medalha[i].pais_origem, "DOM") == 0) {
            strcpy(tabela[i].pais, "República Dominicana");
        } else if (strcmp(medalha[i].pais_origem, "ECU") == 0) { 
            strcpy(tabela[i].pais, "Equador");
        } else if (strcmp(medalha[i].pais_origem, "GRN") == 0) {
            strcpy(tabela[i].pais, "Granada");
        } else if (strcmp(medalha[i].pais_origem, "KAZ") == 0) {
            strcpy(tabela[i].pais, "Cazaquistão");
        } else if (strcmp(medalha[i].pais_origem, "KSA") == 0) {
            strcpy(tabela[i].pais, "Arábia Saudita");
        } else if (strcmp(medalha[i].pais_origem, "NAM") == 0) {
            strcpy(tabela[i].pais, "Namíbia");
        } else if (strcmp(medalha[i].pais_origem, "AUT") == 0) {
            strcpy(tabela[i].pais, "Áustria");
        } else if (strcmp(medalha[i].pais_origem, "BDI") == 0) {
            strcpy(tabela[i].pais, "Burundi");
        } else if (strcmp(medalha[i].pais_origem, "CMR") == 0) {
            strcpy(tabela[i].pais, "Camarões");
        } else if (strcmp(medalha[i].pais_origem, "LUX") == 0) { 
            strcpy(tabela[i].pais, "Luxemburgo");
        } else if (strcmp(medalha[i].pais_origem, "MOZ") == 0) { 
            strcpy(tabela[i].pais, "Moçambique");
        } else if (strcmp(medalha[i].pais_origem, "PAN") == 0) { 
            strcpy(tabela[i].pais, "Panamá"); 
        } else if (strcmp(medalha[i].pais_origem, "TJK") == 0) { 
            strcpy(tabela[i].pais, "Tadjiquistão");
        } else if (strcmp(medalha[i].pais_origem, "TTO") == 0) { 
            strcpy(tabela[i].pais, "Trinidad e Tobago");
        } else if (strcmp(medalha[i].pais_origem, "UGA") == 0) { 
            strcpy(tabela[i].pais, "Uganda");
        } else if (strcmp(medalha[i].pais_origem, "URS") == 0) { 
            strcpy(tabela[i].pais, "União Soviética");
        } 

        

     }
}

void imprime_cabecalho(const Dados_tabela *tabela) { // Imprime o cabeçalho da tabela
    printf("\n\033[1;33m"); // Amarelo em negrito
    printf("--------------------------------------------------------\n");
    printf("|🎉 QUADRO DE MEDALHAS OLÍMPICAS - %dº EDIÇÃO - %s 🎉|\n", tabela->edicao, tabela->cidade_realizado); 
    printf("--------------------------------------------------------\n");
    printf("\033[0m");
    printf("\n\033[1;25m"); // Resetar cores
    printf("| PAÍS       | 🥇OURO | 🥈PRATA |🥉BRONZE | TOTAL |\n");
    printf("---------------------------------------------------\n");
}

void imprime_linhas(const Dados_tabela *tabela) { // Imprime as linhas da tabela
    printf("| %-10s |   %2d   |   %2d    |   %2d    |   %2d  |\n",
           tabela->pais, tabela->ouro, tabela->prata, tabela->bronze, tabela->total);
}
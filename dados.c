#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dados.h"
#include "structs.h"
#include "cadastro.h"

void Input_dados(Medalhas *dados_iniciais) {
    //dados_iniciais = (Medalhas*) malloc(2395 * sizeof(Medalhas)); // Aloca memória para 2395 medalhas
    FILE *dados; // Ponteiro para o arquivo
    char *filename = "medalhas.csv"; // Nome do arquivo
    char linha[200]; // Buffer para armazenar cada linha do arquivo
    char armazena_resultado[2395][50]; // Buffer para armazenar o resultado
    int k = 0; // Contador

    dados = fopen(filename, "r"); // Abre o arquivo para leitura 

    // Lê cada linha do arquivo
    while (fgets(linha, sizeof(linha), dados) != NULL) {
        if (linha[0] == '\n') continue; // Ignora linhas em branco
        
        dados_iniciais[k].contador = k + 1; // Armazena o contador
        dados_iniciais[k].genero = strtok(linha, ",")[0]; // Armazena o gênero
        strcpy(dados_iniciais[k].modalidade, strtok(NULL, ",")); // Armazena a modalidade
        strcpy(dados_iniciais[k].cidade, strtok(NULL, ",")); // Armazena a cidade
        dados_iniciais[k].ano = atoi(strtok(NULL, ",")); // Armazena o ano
        dados_iniciais[k].gbs = strtok(NULL, ",")[0];  // Armazena o tipo de medalha
        strcpy(dados_iniciais[k].nome_atleta, strtok(NULL, ",")); // Armazena o nome do atleta
        strcpy(dados_iniciais[k].pais_origem, strtok(NULL, ",")); // Armazena o país de origem
        strcpy(armazena_resultado[k], strtok(NULL, "\n")); // Armazena o resultado

        k++;
    }

    /*
    for (int i = 0; i < k; i++) { // Separa o resultado em tempo e distância
        if ( // Verifica se a modalidade é uma das que possuem tempo como resultado
            strcmp(dados_iniciais[i].modalidade, "10000M Men") == 0 ||
            strcmp(dados_iniciais[i].modalidade, "1500M Men") == 0 ||
            strcmp(dados_iniciais[i].modalidade, "20Km Race Walk Men") == 0 ||
            strcmp(dados_iniciais[i].modalidade, "3000M Steeplechase Men") == 0 ||
            strcmp(dados_iniciais[i].modalidade, "4X400M Relay Men") == 0 || 
            strcmp(dados_iniciais[i].modalidade, "5000M Men") == 0 || 
            strcmp(dados_iniciais[i].modalidade, "50Km Race Walk Men") == 0 || 
            strcmp(dados_iniciais[i].modalidade, "800M Men") == 0 ||  
            strcmp(dados_iniciais[i].modalidade, "Marathon Men") == 0 ||

            strcmp(dados_iniciais[i].modalidade, "10000M Women") == 0 || 
            strcmp(dados_iniciais[i].modalidade, "1500M Women") == 0 ||
            strcmp(dados_iniciais[i].modalidade, "20Km Race Walk Women") == 0 ||
            strcmp(dados_iniciais[i].modalidade, "3000M Steeplechase Women") == 0 ||
            strcmp(dados_iniciais[i].modalidade, "4X400M Relay Women") == 0 || 
            strcmp(dados_iniciais[i].modalidade, "5000M Women") == 0 || 
            strcmp(dados_iniciais[i].modalidade, "50Km Race Walk Women") == 0 || 
            strcmp(dados_iniciais[i].modalidade, "800M Women") == 0 ||  
            strcmp(dados_iniciais[i].modalidade, "Marathon Women") == 0 ) {

            if( // Verifica se a modalidade é uma das que possuem hora no resultado
                strcmp(dados_iniciais[i].modalidade, "50Km Race Walk Men") == 0 ||
                strcmp(dados_iniciais[i].modalidade, "20Km Race Walk Men") == 0 ||
                strcmp(dados_iniciais[i].modalidade, "Marathon Men") == 0 ||

                strcmp(dados_iniciais[i].modalidade, "50Km Race Walk Women") == 0 ||
                strcmp(dados_iniciais[i].modalidade, "20Km Race Walk Women") == 0 ||
                strcmp(dados_iniciais[i].modalidade, "Marathon Women") == 0) {

                dados_iniciais[i].resultado.tempo.hora = atof(strtok(armazena_resultado[i], ":"));
                dados_iniciais[i].resultado.tempo.minuto = atof(strtok(NULL, ":"));
                dados_iniciais[i].resultado.tempo.segundo = atof(strtok(NULL, "\0"));
                dados_iniciais[i].resultado.tempo.milissegundo = 0;
            } 
            
            else if(strcmp(armazena_resultado[i], "None") == 0) { // Verifica se o resultado é "None"
                dados_iniciais[i].resultado.tempo.hora = 0;
                dados_iniciais[i].resultado.tempo.minuto = 0;
                dados_iniciais[i].resultado.tempo.segundo = 0;
                dados_iniciais[i].resultado.tempo.milissegundo = 0;
            }
            
            else { // Caso contrário, armazena apenas minuto e segundo
                dados_iniciais[i].resultado.tempo.hora = 0;
                dados_iniciais[i].resultado.tempo.minuto = atof(strtok(armazena_resultado[i], ":"));
                dados_iniciais[i].resultado.tempo.segundo = atof(strtok(NULL, "."));
                dados_iniciais[i].resultado.tempo.milissegundo = atof(strtok(NULL, "\0"));
            }
        } 
        
        else if ( // Verifica se a modalidade é uma das que possuem distância como resultado
            strcmp(dados_iniciais[i].modalidade, "Discus Throw Men") == 0 ||
            strcmp(dados_iniciais[i].modalidade, "Hammer Throw Men") == 0 ||
            strcmp(dados_iniciais[i].modalidade, "High Jump Men") == 0 ||
            strcmp(dados_iniciais[i].modalidade, "Javelin Throw Men") == 0 ||
            strcmp(dados_iniciais[i].modalidade, "Long Jump Men") == 0 ||
            strcmp(dados_iniciais[i].modalidade, "Pole Vault Men") == 0 ||
            strcmp(dados_iniciais[i].modalidade, "Shot Put Men") == 0 ||
            strcmp(dados_iniciais[i].modalidade, "Triple Jump Men") == 0 ||
            
            strcmp(dados_iniciais[i].modalidade, "Discus Throw Women") == 0 ||
            strcmp(dados_iniciais[i].modalidade, "Hammer Throw Women") == 0 ||
            strcmp(dados_iniciais[i].modalidade, "High Jump Women") == 0 ||
            strcmp(dados_iniciais[i].modalidade, "Javelin Throw Women") == 0 ||
            strcmp(dados_iniciais[i].modalidade, "Long Jump Women") == 0 ||
            strcmp(dados_iniciais[i].modalidade, "Pole Vault Women") == 0 ||
            strcmp(dados_iniciais[i].modalidade, "Shot Put Women") == 0 ||
            strcmp(dados_iniciais[i].modalidade, "Triple Jump Women") == 0) { 
            
            dados_iniciais[i].resultado.distancia = atof(strtok(armazena_resultado[i], "\0"));

        } 
        
        else if ( // Verifica se a modalidade é uma das que possuem pontos como resultado
                 strcmp(dados_iniciais[i].modalidade, "Decathlon Men") == 0 || 
                 strcmp(dados_iniciais[i].modalidade, "Heptathlon Women") == 0) {

            dados_iniciais[i].resultado.pontos = atof(strtok(armazena_resultado[i], "\0")); 
        }

        else if(strcmp(armazena_resultado[i], "None") == 0) { // Verifica se o resultado é "None"
            dados_iniciais[i].resultado.tempo.hora = 0;
            dados_iniciais[i].resultado.tempo.minuto = 0;
            dados_iniciais[i].resultado.tempo.segundo = 0;
            dados_iniciais[i].resultado.tempo.milissegundo = 0;
        }

        else { // Caso contrário, armazena apenas segundo e milissegundo
            dados_iniciais[i].resultado.tempo.hora = 0;
            dados_iniciais[i].resultado.tempo.minuto = 0;
            dados_iniciais[i].resultado.tempo.segundo = atof(strtok(armazena_resultado[i], "."));
            dados_iniciais[i].resultado.tempo.milissegundo = atof(strtok(NULL, "\0"));
        }
    }
    */
}


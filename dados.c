#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dados.h"
#include "structs.h"
#include "cadastro.h"
 
void Input_dados(Medalhas *medalha) {
    FILE *dados; // Ponteiro para o arquivo
    char *filename = "medalhas.csv"; // Nome do arquivo
    char linha[200]; // Buffer para armazenar cada linha do arquivo
    char copia_para_resultados[2395][50]; // Buffer para armazenar o resultado
    int k = 0; // Contador

    dados = fopen(filename, "r"); // Abre o arquivo para leitura 

    // Lê cada linha do arquivo
    while (fgets(linha, sizeof(linha), dados) != NULL) {
        if (linha[0] == '\n') continue; // Ignora linhas em branco
        
        medalha[k].contador = k + 1; // Armazena o contador
        medalha[k].genero = strtok(linha, ",")[0]; // Armazena o gênero
        strcpy(medalha[k].modalidade, strtok(NULL, ",")); // Armazena a modalidade
        strcpy(medalha[k].cidade, strtok(NULL, ",")); // Armazena a cidade
        medalha[k].ano = atoi(strtok(NULL, ",")); // Armazena o ano
        medalha[k].gbs = strtok(NULL, ",")[0];  // Armazena o tipo de medalha
        strcpy(medalha[k].nome_atleta, strtok(NULL, ",")); // Armazena o nome do atleta
        strcpy(medalha[k].pais_origem, strtok(NULL, ",")); // Armazena o país de origem
        strcpy(medalha[k].armazena_resultado, strtok(NULL, "\n")); // Armazena o resultado

        k++;
    }

    
    for (int i = 0; i < k; i++) {
        strcpy(copia_para_resultados[i], medalha[i].armazena_resultado); // Copia o resultado para um buffer
    }
    
    for (int i = 0; i < k; i++) { // Separa o resultado em tempo e distância
        if ( // Verifica se a modalidade é uma das que possuem tempo como resultado
            strcmp(medalha[i].modalidade, "10000M Men") == 0 ||
            strcmp(medalha[i].modalidade, "1500M Men") == 0 ||
            strcmp(medalha[i].modalidade, "20Km Race Walk Men") == 0 ||
            strcmp(medalha[i].modalidade, "3000M Steeplechase Men") == 0 ||
            strcmp(medalha[i].modalidade, "4X400M Relay Men") == 0 || 
            strcmp(medalha[i].modalidade, "5000M Men") == 0 || 
            strcmp(medalha[i].modalidade, "50Km Race Walk Men") == 0 || 
            strcmp(medalha[i].modalidade, "800M Men") == 0 ||  
            strcmp(medalha[i].modalidade, "Marathon Men") == 0 ||

            strcmp(medalha[i].modalidade, "10000M Women") == 0 || 
            strcmp(medalha[i].modalidade, "1500M Women") == 0 ||
            strcmp(medalha[i].modalidade, "20Km Race Walk Women") == 0 ||
            strcmp(medalha[i].modalidade, "3000M Steeplechase Women") == 0 ||
            strcmp(medalha[i].modalidade, "4X400M Relay Women") == 0 || 
            strcmp(medalha[i].modalidade, "5000M Women") == 0 || 
            strcmp(medalha[i].modalidade, "50Km Race Walk Women") == 0 || 
            strcmp(medalha[i].modalidade, "800M Women") == 0 ||  
            strcmp(medalha[i].modalidade, "Marathon Women") == 0 ) {

            if( // Verifica se a modalidade é uma das que possuem hora no resultado
                strcmp(medalha[i].modalidade, "50Km Race Walk Men") == 0 ||
                strcmp(medalha[i].modalidade, "20Km Race Walk Men") == 0 ||
                strcmp(medalha[i].modalidade, "Marathon Men") == 0 ||

                strcmp(medalha[i].modalidade, "50Km Race Walk Women") == 0 ||
                strcmp(medalha[i].modalidade, "20Km Race Walk Women") == 0 ||
                strcmp(medalha[i].modalidade, "Marathon Women") == 0) {

                medalha[i].resultado.tempo.hora = atof(strtok(copia_para_resultados[i], ":"));
                medalha[i].resultado.tempo.minuto = atof(strtok(NULL, ":"));
                medalha[i].resultado.tempo.segundo = atof(strtok(NULL, "\0"));
                medalha[i].resultado.tempo.milissegundo = 0;
            } 
            
            else if(strcmp(copia_para_resultados[i], "None") == 0) { // Verifica se o resultado é "None"
                medalha[i].resultado.tempo.hora = 0;
                medalha[i].resultado.tempo.minuto = 0;
                medalha[i].resultado.tempo.segundo = 0;
                medalha[i].resultado.tempo.milissegundo = 0;
            }
            
            else { // Caso contrário, armazena apenas minuto e segundo
                medalha[i].resultado.tempo.hora = 0;
                medalha[i].resultado.tempo.minuto = atof(strtok(copia_para_resultados[i], ":"));
                medalha[i].resultado.tempo.segundo = atof(strtok(NULL, "."));
                medalha[i].resultado.tempo.milissegundo = atof(strtok(NULL, "\0"));
            }
        } 
        
        else if ( // Verifica se a modalidade é uma das que possuem distância como resultado
            strcmp(medalha[i].modalidade, "Discus Throw Men") == 0 ||
            strcmp(medalha[i].modalidade, "Hammer Throw Men") == 0 ||
            strcmp(medalha[i].modalidade, "High Jump Men") == 0 ||
            strcmp(medalha[i].modalidade, "Javelin Throw Men") == 0 ||
            strcmp(medalha[i].modalidade, "Long Jump Men") == 0 ||
            strcmp(medalha[i].modalidade, "Pole Vault Men") == 0 ||
            strcmp(medalha[i].modalidade, "Shot Put Men") == 0 ||
            strcmp(medalha[i].modalidade, "Triple Jump Men") == 0 ||
            
            strcmp(medalha[i].modalidade, "Discus Throw Women") == 0 ||
            strcmp(medalha[i].modalidade, "Hammer Throw Women") == 0 ||
            strcmp(medalha[i].modalidade, "High Jump Women") == 0 ||
            strcmp(medalha[i].modalidade, "Javelin Throw Women") == 0 ||
            strcmp(medalha[i].modalidade, "Long Jump Women") == 0 ||
            strcmp(medalha[i].modalidade, "Pole Vault Women") == 0 ||
            strcmp(medalha[i].modalidade, "Shot Put Women") == 0 ||
            strcmp(medalha[i].modalidade, "Triple Jump Women") == 0) { 
            
            medalha[i].resultado.distancia = atof(strtok(copia_para_resultados[i], "\0"));

        } 
        
        else if ( // Verifica se a modalidade é uma das que possuem pontos como resultado
                 strcmp(medalha[i].modalidade, "Decathlon Men") == 0 || 
                 strcmp(medalha[i].modalidade, "Heptathlon Women") == 0) {

            medalha[i].resultado.pontos = atof(strtok(copia_para_resultados[i], "\0")); 
        }

        else if(strcmp(copia_para_resultados[i], "None") == 0) { // Verifica se o resultado é "None"
            medalha[i].resultado.tempo.hora = 0;
            medalha[i].resultado.tempo.minuto = 0;
            medalha[i].resultado.tempo.segundo = 0;
            medalha[i].resultado.tempo.milissegundo = 0;
        }

        else { // Caso contrário, armazena apenas segundo e milissegundo
            medalha[i].resultado.tempo.hora = 0;
            medalha[i].resultado.tempo.minuto = 0;
            medalha[i].resultado.tempo.segundo = atof(strtok(copia_para_resultados[i], "."));
            medalha[i].resultado.tempo.milissegundo = atof(strtok(NULL, "\0"));
        }
    }
    
}


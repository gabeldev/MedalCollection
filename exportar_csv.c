#include <stdio.h>
#include <string.h>
#include "exportar_csv.h"

void exportar_para_csv(Medalhas *medalhas, int num_medalhas, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }//if

    // Cabeçalho do CSV
    fprintf(file, "Código,Gênero,Modalidade,Cidade,Ano,Tipo Medalha,Nome Atleta,Pais Origem,Resultado\n");

    for (int i = 0; i < num_medalhas; i++) {
        if (medalhas[i].contador != 0) { // Verifica se a medalha existe
            fprintf(file, "%d,%c,%s,%s,%d,%c,%s,%s,",
                    medalhas[i].contador,
                    medalhas[i].genero,
                    medalhas[i].modalidade,
                    medalhas[i].cidade,
                    medalhas[i].ano,
                    medalhas[i].gbs,
                    medalhas[i].nome_atleta,
                    medalhas[i].pais_origem);

            // Escrever resultado baseado no tipo de modalidade
            if (strstr(medalhas[i].modalidade, "M") || strstr(medalhas[i].modalidade, "Women")) {
                if (strstr(medalhas[i].modalidade, "Race Walk") || strstr(medalhas[i].modalidade, "Marathon")) {
                    fprintf(file, "%02.0f:%02.0f:%02.0f\n",
                            medalhas[i].resultado.tempo.hora,
                            medalhas[i].resultado.tempo.minuto,
                            medalhas[i].resultado.tempo.segundo);
                } else if (strstr(medalhas[i].modalidade, "Throw") || strstr(medalhas[i].modalidade, "Jump")) {
                    fprintf(file, "%.2f\n", medalhas[i].resultado.distancia);
                } else if (strstr(medalhas[i].modalidade, "Decathlon") || strstr(medalhas[i].modalidade, "Heptathlon")) {
                    fprintf(file, "%.2f\n", medalhas[i].resultado.pontos);
                } else {
                    fprintf(file, "%02.0f:%02.0f:%.3f\n",
                            medalhas[i].resultado.tempo.minuto,
                            medalhas[i].resultado.tempo.segundo,
                            medalhas[i].resultado.tempo.milissegundo);
                }
            }
        }
    }

    fclose(file);
    printf("Dados exportados com sucesso para %s\n", filename);
}//exportar_para_csv

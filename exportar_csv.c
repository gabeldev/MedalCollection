#include <stdio.h>
#include "exportar_csv.h"

void exportar_para_csv(Medalhas *medalhas, Bruto_tabela *total_medalhas) {
    
    FILE *csv_file;
    char *filename = "medalhas_exportadas.csv";

    csv_file = fopen(filename, "w");

    if (csv_file == NULL) {
        perror("Erro ao abrir o arquivo para escrita.\n");
        exit(EXIT_FAILURE);
    }//if

    // Cabeçalho do CSV
    fprintf(csv_file, "Código,Gênero,Modalidade,Cidade,Ano,Tipo Medalha,Nome Atleta,Pais Origem,Resultado\n");

    for (int i = 0; i < 2395; i++) {
        if (medalhas[i].contador != 0) { // Verifica se a medalha existe
            fprintf(csv_file, "%d,%c,%s,%s,%d,%c,%s,%s,",
                    medalhas[i].contador,
                    medalhas[i].genero,
                    medalhas[i].modalidade,
                    medalhas[i].cidade,
                    medalhas[i].ano,
                    medalhas[i].gbs,
                    medalhas[i].nome_atleta,
                    medalhas[i].pais_origem);
        }//if
    }//for

    fclose(csv_file);

    printf("Dados exportados com sucesso para %s\n", filename);
}//exportar_para_csv

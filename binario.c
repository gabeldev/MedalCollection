#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "tabelas.h"
#include "binario.h"

// Função para salvar os dados em um arquivo binário
void salvar_binario(Medalhas *medalha, Bruto_tabela *total_medalhas) {

    FILE *bin_file;
    char *filename = "medalhas.bin";

    bin_file = fopen(filename, "wb");
    if (bin_file == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }//if

    fwrite(&total_medalhas, sizeof(int), 1, bin_file);
    fwrite(medalha, sizeof(Medalhas), total_medalhas, bin_file);

    fclose(bin_file);
}//salvar_binario

// Função para carregar os dados do arquivo binário
Medalhas* carregar_binario(Bruto_tabela *total_medalhas) {
    FILE *bin_file;
    char *filename = "medalhas.bin";
    Medalhas *medalha;

    bin_file = fopen(filename, "rb");
    if (bin_file == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }//if

    fread(total_medalhas, sizeof(int), 1, bin_file);

    medalha = (Medalhas*)malloc(*total_medalhas * sizeof(Medalhas));
    if (medalha == NULL) {
        perror("Erro ao alocar memória");
        fclose(bin_file);
        exit(EXIT_FAILURE);
    }//if

    fread(medalha, sizeof(Medalhas), *total_medalhas, bin_file);

    fclose(bin_file);
    return medalha;
}//carregar_binario
#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "tabelas.h"
#include "binario.h"

// Função para salvar os dados em um arquivo binário
void salvar_binario(Medalhas *medalha, int *quantidadeMedalhas) {

    FILE *bin_file;
    char *filename = "medalhas.dat";

    bin_file = fopen(filename, "wb");
    if (bin_file == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }//if

    fwrite(&quantidadeMedalhas, sizeof(int), 1, bin_file);
    fwrite(medalha, sizeof(Medalhas), quantidadeMedalhas, bin_file);

    fclose(bin_file);
}//salvar_binario

// Função para carregar os dados do arquivo binário
Medalhas* carregar_binario(int *quantidadeMedalhas) {
    FILE *bin_file;
    char *filename = "medalhas.dat";
    Medalhas *medalha;

    bin_file = fopen(filename, "rb");
    if (bin_file == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }//if

    fread(quantidadeMedalhas, sizeof(int), 1, bin_file);

    medalha = (Medalhas*)malloc(*quantidadeMedalhas * sizeof(Medalhas));
    if (medalha == NULL) {
        perror("Erro ao alocar memória");
        fclose(bin_file);
        exit(EXIT_FAILURE);
    }//if

    fread(medalha, sizeof(Medalhas), quantidadeMedalhas, bin_file);

    fclose(bin_file);
    return medalha;
}//carregar_binario
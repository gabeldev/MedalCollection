#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "binario.h"

void salvar_binario(Medalhas *medalha, Bruto_tabela *tabela) {

    FILE *file = fopen("medalhas.dat", "wb");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo para escrita!\n");
        exit(1);
    }//if

    // Escreve os dados no arquivo binário
    fwrite(medalha, sizeof(Medalhas), 2395, file);
    fwrite(tabela, sizeof(Bruto_tabela), 2395, file);

    fclose(file);
    printf("Dados salvos com sucesso!\n");
}//salvar_binario

void carregar_binario(Medalhas *medalha, Bruto_tabela *tabela) {

    FILE *file = fopen("medalhas.dat", "rb");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo para leitura!\n");
        exit(1);
    }//if

    // Lê os dados do arquivo binário
    fread(medalha, sizeof(Medalhas), 2395, file);
    fread(tabela, sizeof(Bruto_tabela), 2395, file);

    fclose(file);
    printf("Dados carregados com sucesso!\n");
}//carregar_binario

int binario_existe() {
    
    int contador = 0;

    FILE *arquivo = fopen("medalhas.dat", "rb");
    if (arquivo != NULL) {
        // O arquivo existe, então fecha o arquivo e incrementa o contador
        fclose(arquivo);
        contador++;
    }//if

    return contador;
}//binario_existe

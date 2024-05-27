#include "cadastro.h"
#include "binario.h"

// Função para salvar os dados das medalhas em um arquivo binário
void salvarMedalhas (char *nomeArquivo, Medalha *medalhas, int quantidade) {

    FILE *arquivo = fopen (nomeArquivo, "wb");
    if (arquivo == NULL) {
        perror ("Erro ao abrir o arquivo para escrita");
        exit(EXIT_FAILURE);
    }//if

    fwrite (&quantidade, sizeof(int), 1, arquivo);
    fwrite (medalhas, sizeof(Medalha), quantidade, arquivo);

    fclose (arquivo);

}//salvarMedalhas

// Função para carregar os dados das medalhas de um arquivo binário
Medalha* carregarMedalhas (char *nomeArquivo, int *quantidade) {

    FILE *arquivo = fopen(nomeArquivo, "rb");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para leitura");
        exit(EXIT_FAILURE);
    }//if

    fread (quantidade, sizeof(int), 1, arquivo);
    Medalha *medalhas = (Medalha*) malloc(sizeof(Medalha) * (*quantidade));
    if (medalhas == NULL) {
        perror("Erro ao alocar memória");
        exit(EXIT_FAILURE);
    }//if

    fread (medalhas, sizeof(Medalha), *quantidade, arquivo);

    fclose (arquivo);

    return medalhas;
}//carregarMedalhas
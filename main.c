#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cadastro.h"
#include "dados.h"
#include "tabelas.h"
#include "binario.h"

int main() {

    // Inicializa variáveis
    Medalhas *dados_iniciais = (Medalhas*) malloc(2395 * sizeof(Medalhas));
    Bruto_tabela *tabela = malloc(2395 * sizeof(Bruto_tabela));
    Tratado_tabela *tabela_tratada = malloc(2395 * sizeof(Tratado_tabela));

    // Verifica se a alocação de memória foi bem sucedida
    if (dados_iniciais == NULL || tabela == NULL || tabela_tratada == NULL) {
        printf("Erro na alocação de memória\n");
        return EXIT_FAILURE;
    }//if

    // Verifica se existe um arquivo binário para carregar os dados
    if (binario_existe() != 0) {
        // Se o arquivo binário existir, carrega os dados do arquivo
        carregar_binario(dados_iniciais, tabela);
    } else {
        // Se o arquivo binário não existir, carrega os dados iniciais
        Input_dados(dados_iniciais);
        converte_tabela(tabela, dados_iniciais);
    }//if else

    menu(dados_iniciais, tabela);

    salvar_binario(dados_iniciais, tabela);

    free(dados_iniciais);
    free(tabela);
    free(tabela_tratada);

    return EXIT_SUCCESS;
}//main
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cadastro.h"
#include "dados.h"
#include "tabelas.h"
#include "exportar_csv.h"
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
    }

    
    Input_dados(dados_iniciais);
    converte_tabela(tabela, dados_iniciais);
    menu(dados_iniciais, tabela);




    return EXIT_SUCCESS;
}
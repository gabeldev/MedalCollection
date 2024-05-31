#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dados.h"
#include "Cadastro.h"

Medalhas* Input_dados(Medalhas *dados_iniciais) {
    FILE *dados;
    char *filename = "medalhas.csv"; // 

    dados = fopen(filename, "r"); // 

    if (dados == NULL) {
        perror("Erro ao abrir o arquivo");
        return EXIT_FAILURE;
    }

    

    

    fclose(dados); // Fecha o arquivo ao final
}


int main{
    Medalhas *dados_iniciais;
   
   
   
    dados_iniciais = Input_dados(dados_iniciais);
    
    
    
    
    
    
    return 0;}
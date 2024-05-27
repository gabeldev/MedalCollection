#ifndef ARQUIVOBINARIO_H
#define ARQUIVOBINARIO_H

#include <stdio.h>

// Funções para salvar e carregar os dados
void salvarMedalhas (char *nomeArquivo, Medalha *medalhas, int quantidade);
Medalha* carregarMedalhas (char *nomeArquivo, int *quantidade);

#endif // ARQUIVOBINARIO_H

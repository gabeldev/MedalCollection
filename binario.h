#ifndef BINARIO_H
#define BINARIO_H

#include <stdio.h>
#include "structs.h"

void salvar_binario(Medalhas *medalha, Bruto_tabela *tabela);
void carregar_binario(Medalhas *medalha, Bruto_tabela *tabela);
int binario_existe();

#endif
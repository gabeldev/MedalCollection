#ifndef EXPORTAR_CSV_H
#define EXPORTAR_CSV_H

#include <stdio.h>
#include "Cadastro.h"

// Declaração da função de exportação
void exportar_para_csv(Medalhas *medalhas, int num_medalhas, const char *filename);

#endif // EXPORTAR_CSV_H
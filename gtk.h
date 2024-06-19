#ifndef GTK_H
#define GTK_H

#include <gtk/gtk.h>
#include "structs.h"

// Função para inicializar a interface gráfica GTK
void gtk_initialize(int argc, char *argv[], Medalhas *medalhas, Bruto_tabela *tabela);

#endif // GTK_H

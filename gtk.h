#ifndef GTK_H
#define GTK_H
#include <gst/gst.h>
#include <gtk/gtk.h>
#include "structs.h"
#include "cadastro.h"
#include "dados.h"
#include "tabelas.h"
#include "binario.h"

typedef struct {
    Medalhas *medalhas;
    Bruto_tabela *tabela;
} AppData;

void gtk_initialize(int argc, char *argv[], Medalhas *medalhas, Bruto_tabela *tabela);

#endif // GTK_INTERFACE_H

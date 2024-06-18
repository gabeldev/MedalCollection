#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "cadastro.h"
#include "dados.h"
#include "tabelas.h"
#include "binario.h"

Medalhas medalhas[2395];
Bruto_tabela tabela[2395];

// Função para transformar string em minúsculo
char* transformar_minusculo(char *str);

// Funções de gerenciamento de medalhas (use as implementações fornecidas anteriormente)
void inserir_medalha(Medalhas *medalha, Bruto_tabela *tabela);
void listar_medalhas(Medalhas *medalha, Bruto_tabela *tabela);
void pesquisar_medalha(Medalhas *medalha, Bruto_tabela *tabela);
void alterar_medalha(Medalhas *medalha, Bruto_tabela *tabela);
void excluir_medalha(Medalhas *medalha, Bruto_tabela *tabela);
void exportar_para_csv(Medalhas *medalha, Bruto_tabela *tabela);

// Funções GTK para os callbacks
void on_insert_medal_clicked(GtkWidget *widget, gpointer data) {
    inserir_medalha(medalhas, tabela);
}

void on_list_medals_clicked(GtkWidget *widget, gpointer data) {
    listar_medalhas(medalhas, tabela);
}

void on_search_medal_clicked(GtkWidget *widget, gpointer data) {
    pesquisar_medalha(medalhas, tabela);
}

void on_update_medal_clicked(GtkWidget *widget, gpointer data) {
    alterar_medalha(medalhas, tabela);
}

void on_delete_medal_clicked(GtkWidget *widget, gpointer data) {
    excluir_medalha(medalhas, tabela);
}

void on_export_to_csv_clicked(GtkWidget *widget, gpointer data) {
    exportar_para_csv(medalhas, tabela);
}

void on_exit_clicked(GtkWidget *widget, gpointer data) {
    gtk_main_quit();
}

// Função principal GTK
int main(int argc, char *argv[]) {
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *insert_button, *list_button, *search_button, *update_button, *delete_button, *export_button, *exit_button;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Sistema de Gerenciamento de Medalhas");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    insert_button = gtk_button_new_with_label("Inserir Medalha");
    list_button = gtk_button_new_with_label("Listar Medalhas");
    search_button = gtk_button_new_with_label("Buscar Medalha");
    update_button = gtk_button_new_with_label("Alterar Medalha");
    delete_button = gtk_button_new_with_label("Excluir Medalha");
    export_button = gtk_button_new_with_label("Exportar para CSV");
    exit_button = gtk_button_new_with_label("Sair");

    gtk_grid_attach(GTK_GRID(grid), insert_button, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), list_button, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), search_button, 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), update_button, 0, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), delete_button, 0, 4, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), export_button, 0, 5, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), exit_button, 0, 6, 1, 1);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(insert_button, "clicked", G_CALLBACK(on_insert_medal_clicked), NULL);
    g_signal_connect(list_button, "clicked", G_CALLBACK(on_list_medals_clicked), NULL);
    g_signal_connect(search_button, "clicked", G_CALLBACK(on_search_medal_clicked), NULL);
    g_signal_connect(update_button, "clicked", G_CALLBACK(on_update_medal_clicked), NULL);
    g_signal_connect(delete_button, "clicked", G_CALLBACK(on_delete_medal_clicked), NULL);
    g_signal_connect(export_button, "clicked", G_CALLBACK(on_export_to_csv_clicked), NULL);
    g_signal_connect(exit_button, "clicked", G_CALLBACK(on_exit_clicked), NULL);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
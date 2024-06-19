#include <stdio.h>
#include <stdlib.h>
#include <gst/gst.h>
#include "gtk.h"
#include "tabelas.h"
#include "cadastro.h"
#include "structs.h"
#include "binario.h"
#include "dados.h"

// Declarações das funções
static GstElement *play_music(const char *file_path);
static void on_eos(GstBus *bus, GstMessage *message, gpointer data);
static void on_pad_added(GstElement *src, GstPad *new_pad, gpointer data);

// Definições de funções de callback para os botões GTK
static void on_insert_medal_clicked(GtkWidget *widget, gpointer data) {
    AppData *app_data = (AppData *)data;
    inserir_medalha(app_data->medalhas, app_data->tabela);
}

static void on_list_medals_clicked(GtkWidget *widget, gpointer data) {
    AppData *app_data = (AppData *)data;
    listar_medalhas(app_data->medalhas, app_data->tabela);
}

static void on_search_medal_clicked(GtkWidget *widget, gpointer data) {
    AppData *app_data = (AppData *)data;
    pesquisar_medalha(app_data->medalhas, app_data->tabela);
}

static void on_update_medal_clicked(GtkWidget *widget, gpointer data) {
    AppData *app_data = (AppData *)data;
    alterar_medalha(app_data->medalhas, app_data->tabela);
}

static void on_print_medal_clicked(GtkWidget *widget, gpointer data) {
    AppData *app_data = (AppData *)data;
    imprime_tabela(app_data->tabela);
}

static void on_delete_medal_clicked(GtkWidget *widget, gpointer data) {
    AppData *app_data = (AppData *)data;
    excluir_medalha(app_data->medalhas, app_data->tabela);
}

static void on_export_to_csv_clicked(GtkWidget *widget, gpointer data) {
    AppData *app_data = (AppData *)data;
    exportar_para_csv(app_data->medalhas, app_data->tabela);
}

static void on_exit_clicked(GtkWidget *widget, gpointer data) {
    gtk_main_quit();
}

// Variáveis globais para controle do pipeline e playlist
static GstElement *pipeline = NULL;
static const char *playlist[] = {"jogos_musica.mp3", "brasil.mp3", "estados_unidos.mp3", "sovietes.mp3", 
                                 "alemanha.mp3", "gales.mp3", "franca.mp3", "argentina.mp3"};
static int current_track = 0; // Índice da música atual na lista

// Função para inicializar o GStreamer e tocar música
static GstElement *play_music(const char *file_path) {
    g_print("Iniciando reprodução da música: %s\n", file_path);
    GstBus *bus;

    GstElement *pipeline = gst_pipeline_new("audio-player");
    GstElement *source = gst_element_factory_make("filesrc", "file-source");
    GstElement *decoder = gst_element_factory_make("decodebin", "decoder");
    GstElement *conv = gst_element_factory_make("audioconvert", "converter");
    GstElement *sink = gst_element_factory_make("autoaudiosink", "audio-output");

    if (!pipeline || !source || !decoder || !conv || !sink) {
        g_printerr("Um ou mais elementos GStreamer não puderam ser criados.\n");
        return NULL;
    }

    g_object_set(G_OBJECT(source), "location", file_path, NULL);

    gst_bin_add_many(GST_BIN(pipeline), source, decoder, conv, sink, NULL);

    // Conectar o decodebin dinamicamente
    g_signal_connect(decoder, "pad-added", G_CALLBACK(on_pad_added), conv);

    if (!gst_element_link_many(source, decoder, NULL)) {
        g_printerr("Falha ao linkar source e decoder.\n");
        return NULL;
    }

    if (!gst_element_link_many(conv, sink, NULL)) {
        g_printerr("Falha ao linkar converter e sink.\n");
        return NULL;
    }

    // Callback para o evento EOS (End of Stream)
    bus = gst_pipeline_get_bus(GST_PIPELINE(pipeline));
    gst_bus_add_signal_watch(bus);
    g_signal_connect(bus, "message::eos", G_CALLBACK(on_eos), NULL);
    gst_object_unref(bus);

    gst_element_set_state(pipeline, GST_STATE_PLAYING);

    return pipeline;
}

// Callback para conectar dinamicamente os pads do decodebin
static void on_pad_added(GstElement *src, GstPad *new_pad, gpointer data) {
    GstElement *sink = (GstElement *)data;
    GstPad *sink_pad = gst_element_get_static_pad(sink, "sink");
    if (gst_pad_link(new_pad, sink_pad) != GST_PAD_LINK_OK) {
        g_printerr("Falha ao linkar decodebin e converter.\n");
    }
    gst_object_unref(sink_pad);
}

// Função callback para o evento EOS (End of Stream)
static void on_eos(GstBus *bus, GstMessage *message, gpointer data) {
    g_print("End of stream reached for current track.\n");

    // Incrementa o índice da música atual ou reinicia se for a última música
    current_track = (current_track + 1) % (sizeof(playlist) / sizeof(playlist[0]));

    // Carrega e reproduz a próxima música
    GstElement *new_pipeline = play_music(playlist[current_track]);
    if (!new_pipeline) {
        g_printerr("Failed to play next track.\n");
        return;
    }

    // Limpa o pipeline anterior
    if (pipeline) {
        gst_element_set_state(pipeline, GST_STATE_NULL);
        gst_object_unref(pipeline);
    }

    pipeline = new_pipeline;
}

// Função para inicializar a interface gráfica GTK
void gtk_initialize(int argc, char *argv[], Medalhas *medalhas, Bruto_tabela *tabela) {
    AppData app_data = {medalhas, tabela};

    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *insert_button, *list_button, *search_button, *update_button, *print_button, *delete_button, *export_button, *exit_button;

    // Inicializa o GTK
    gtk_init(&argc, &argv);

    // Inicializa o GStreamer
    gst_init(&argc, &argv);

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
    print_button = gtk_button_new_with_label("Exibir Tabela");
    delete_button = gtk_button_new_with_label("Excluir Medalha");
    export_button = gtk_button_new_with_label("Exportar para CSV");
    exit_button = gtk_button_new_with_label("Sair");

    gtk_grid_attach(GTK_GRID(grid), insert_button, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), list_button, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), search_button, 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), update_button, 0, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), print_button, 0, 4, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), delete_button, 0, 5, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), export_button, 0, 6, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), exit_button, 0, 7, 1, 1);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(insert_button, "clicked", G_CALLBACK(on_insert_medal_clicked), &app_data);
    g_signal_connect(list_button, "clicked", G_CALLBACK(on_list_medals_clicked), &app_data);
    g_signal_connect(search_button, "clicked", G_CALLBACK(on_search_medal_clicked), &app_data);
    g_signal_connect(update_button, "clicked", G_CALLBACK(on_update_medal_clicked), &app_data);
    g_signal_connect(print_button, "clicked", G_CALLBACK(on_print_medal_clicked), &app_data);
    g_signal_connect(delete_button, "clicked", G_CALLBACK(on_delete_medal_clicked), &app_data);
    g_signal_connect(export_button, "clicked", G_CALLBACK(on_export_to_csv_clicked), &app_data);
    g_signal_connect(exit_button, "clicked", G_CALLBACK(on_exit_clicked), NULL);

    gtk_widget_show_all(window);

    // Inicializa o pipeline de música com a primeira faixa
    pipeline = play_music(playlist[current_track]);
    if (!pipeline) {
        g_printerr("Failed to start music playback.\n");
        return;
    }

    gtk_main();

    // Limpa o pipeline de música ao sair
    if (pipeline) {
        gst_element_set_state(pipeline, GST_STATE_NULL);
        gst_object_unref(pipeline);
    }

    // Finaliza o GStreamer
    gst_deinit();
}

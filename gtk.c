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
static void on_insert_medal_clicked(GtkWidget *widget, gpointer data) {//Função para inserir medalha
    AppData *app_data = (AppData *)data; //Ponteiro para a estrutura AppData
    setbuf(stdin, NULL); // Limpa o buffer de entrada
    inserir_medalha(app_data->medalhas, app_data->tabela); //Chama a função inserir_medalha
}

static void on_list_medals_clicked(GtkWidget *widget, gpointer data) {//Função para listar medalhas
    AppData *app_data = (AppData *)data;//Ponteiro para a estrutura AppData
    setbuf(stdin, NULL); // Limpa o buffer de entrada
    listar_medalhas(app_data->medalhas, app_data->tabela); //Chama a função listar_medalhas
}

static void on_search_medal_clicked(GtkWidget *widget, gpointer data) { //Função para pesquisar medalha
    AppData *app_data = (AppData *)data; //Ponteiro para a estrutura AppData
    setbuf(stdin, NULL); // Limpa o buffer de entrada
    pesquisar_medalha(app_data->medalhas, app_data->tabela); //Chama a função pesquisar_medalha
}

static void on_update_medal_clicked(GtkWidget *widget, gpointer data) { //Função para alterar medalha
    AppData *app_data = (AppData *)data; //Ponteiro para a estrutura AppData
    setbuf(stdin, NULL); // Limpa o buffer de entrada
    alterar_medalha(app_data->medalhas, app_data->tabela); //Chama a função alterar_medalha
}

static void on_print_medal_clicked(GtkWidget *widget, gpointer data) { //Função para exibir tabela
    AppData *app_data = (AppData *)data; //Ponteiro para a estrutura AppData
    setbuf(stdin, NULL); // Limpa o buffer de entrada
    imprime_tabela(app_data->tabela); //Chama a função imprime_tabela
}

static void on_delete_medal_clicked(GtkWidget *widget, gpointer data) {//Função para excluir medalha
    AppData *app_data = (AppData *)data; //Ponteiro para a estrutura AppData
    setbuf(stdin, NULL); // Limpa o buffer de entrada
    excluir_medalha(app_data->medalhas, app_data->tabela); //Chama a função excluir_medalha
}

static void on_export_to_csv_clicked(GtkWidget *widget, gpointer data) { //Função para exportar para CSV
    AppData *app_data = (AppData *)data; //Ponteiro para a estrutura AppData
    setbuf(stdin, NULL); // Limpa o buffer de entrada
    exportar_para_csv(app_data->medalhas, app_data->tabela); //Chama a função exportar_para_csv
}

static void on_exit_clicked(GtkWidget *widget, gpointer data) { //Função para sair
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

    GstElement *pipeline = gst_pipeline_new("audio-player"); // Cria um pipeline
    GstElement *source = gst_element_factory_make("filesrc", "file-source"); // Cria um elemento de arquivo
    GstElement *decoder = gst_element_factory_make("decodebin", "decoder"); // Cria um elemento de decodificação
    GstElement *conv = gst_element_factory_make("audioconvert", "converter"); // Cria um elemento de conversão de áudio
    GstElement *sink = gst_element_factory_make("autoaudiosink", "audio-output"); // Cria um elemento de saída de áudio

    if (!pipeline || !source || !decoder || !conv || !sink) { // Verifica se todos os elementos foram criados
        g_printerr("Um ou mais elementos GStreamer não puderam ser criados.\n");
        return NULL;
    }

    g_object_set(G_OBJECT(source), "location", file_path, NULL); // Define o arquivo de origem

    gst_bin_add_many(GST_BIN(pipeline), source, decoder, conv, sink, NULL); // Adiciona os elementos ao pipeline

    // Conectar o decodebin dinamicamente
    g_signal_connect(decoder, "pad-added", G_CALLBACK(on_pad_added), conv); // Conecta o decoder ao converter

    if (!gst_element_link_many(source, decoder, NULL)) { // Linka os elementos
        g_printerr("Falha ao linkar source e decoder.\n"); // Mensagem de erro
        return NULL;
    }

    if (!gst_element_link_many(conv, sink, NULL)) { // Linka os elementos
        g_printerr("Falha ao linkar converter e sink.\n"); // Mensagem de erro
        return NULL;
    }

    // Callback para o evento EOS (End of Stream)
    bus = gst_pipeline_get_bus(GST_PIPELINE(pipeline)); // Obtém o barramento do pipeline
    gst_bus_add_signal_watch(bus); // Adiciona um observador de sinais ao barramento
    g_signal_connect(bus, "message::eos", G_CALLBACK(on_eos), NULL); // Conecta o callback ao evento EOS
    gst_object_unref(bus); // Libera o barramento

    gst_element_set_state(pipeline, GST_STATE_PLAYING); // Inicia a reprodução

    return pipeline;
}

// Callback para conectar dinamicamente os pads do decodebin
static void on_pad_added(GstElement *src, GstPad *new_pad, gpointer data) {//Função para adicionar pad
    GstElement *sink = (GstElement *)data; //Ponteiro para o elemento sink
    GstPad *sink_pad = gst_element_get_static_pad(sink, "sink"); //Obtém o pad estático do sink
    if (gst_pad_link(new_pad, sink_pad) != GST_PAD_LINK_OK) { //Linka os pads
        g_printerr("Falha ao linkar decodebin e converter.\n"); //Mensagem de erro
    }
    gst_object_unref(sink_pad); //Libera o pad do sink
}

// Função callback para o evento EOS (End of Stream)
static void on_eos(GstBus *bus, GstMessage *message, gpointer data) { //Função para fim de stream
    g_print("End of stream reached for current track.\n"); //Mensagem de fim de stream

    // Incrementa o índice da música atual ou reinicia se for a última música
    current_track = (current_track + 1) % (sizeof(playlist) / sizeof(playlist[0])); //Incrementa o índice da música atual

    // Carrega e reproduz a próxima música
    GstElement *new_pipeline = play_music(playlist[current_track]); //Carrega e reproduz a próxima música
    if (!new_pipeline) { //Verifica se a nova pipeline foi criada
        g_printerr("Failed to play next track.\n"); //Mensagem de erro
        return;
    }

    // Limpa o pipeline anterior
    if (pipeline) { //Verifica se a pipeline existe
        gst_element_set_state(pipeline, GST_STATE_NULL); //Define o estado da pipeline como nulo
        gst_object_unref(pipeline); //Libera a pipeline
    }

    pipeline = new_pipeline; //Define a nova pipeline
}

// Função para inicializar a interface gráfica GTK
void gtk_initialize(int argc, char *argv[], Medalhas *medalhas, Bruto_tabela *tabela) { //Função para inicializar GTK
    AppData app_data = {medalhas, tabela}; //Estrutura AppData

    GtkWidget *window; //Janela
    GtkWidget *grid; //Grid
    GtkWidget *insert_button, *list_button, *search_button, *update_button, *print_button, *delete_button, *export_button, *exit_button; //Botões

    // Inicializa o GTK
    gtk_init(&argc, &argv); //Inicializa o GTK

    // Inicializa o GStreamer
    gst_init(&argc, &argv); //Inicializa o GStreamer

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL); //Cria uma janela
    gtk_window_set_title(GTK_WINDOW(window), "Sistema de Gerenciamento de Medalhas"); //Define o título da janela
    gtk_container_set_border_width(GTK_CONTAINER(window), 10); //Define a largura da borda da janela
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200); //Define o tamanho padrão da janela

    grid = gtk_grid_new(); //Cria um grid
    gtk_container_add(GTK_CONTAINER(window), grid); //Adiciona o grid à janela

    insert_button = gtk_button_new_with_label("Inserir Medalha"); //Cria um botão com o rótulo "Inserir Medalha"
    list_button = gtk_button_new_with_label("Listar Medalhas"); //Cria um botão com o rótulo "Listar Medalhas"
    search_button = gtk_button_new_with_label("Buscar Medalha"); //Cria um botão com o rótulo "Buscar Medalha"
    update_button = gtk_button_new_with_label("Alterar Medalha"); //Cria um botão com o rótulo "Alterar Medalha"
    print_button = gtk_button_new_with_label("Exibir Tabela"); //Cria um botão com o rótulo "Exibir Tabela"
    delete_button = gtk_button_new_with_label("Excluir Medalha"); //Cria um botão com o rótulo "Excluir Medalha"
    export_button = gtk_button_new_with_label("Exportar para CSV"); //Cria um botão com o rótulo "Exportar para CSV"
    exit_button = gtk_button_new_with_label("Sair"); //Cria um botão com o rótulo "Sair"

    gtk_grid_attach(GTK_GRID(grid), insert_button, 0, 0, 1, 1); //Anexa o botão de inserir ao grid
    gtk_grid_attach(GTK_GRID(grid), list_button, 0, 1, 1, 1); //Anexa o botão de listar ao grid
    gtk_grid_attach(GTK_GRID(grid), search_button, 0, 2, 1, 1); //Anexa o botão de buscar ao grid
    gtk_grid_attach(GTK_GRID(grid), update_button, 0, 3, 1, 1); //Anexa o botão de alterar ao grid
    gtk_grid_attach(GTK_GRID(grid), print_button, 0, 4, 1, 1); //Anexa o botão de exibir ao grid
    gtk_grid_attach(GTK_GRID(grid), delete_button, 0, 5, 1, 1); //Anexa o botão de excluir ao grid
    gtk_grid_attach(GTK_GRID(grid), export_button, 0, 6, 1, 1); //Anexa o botão de exportar ao grid
    gtk_grid_attach(GTK_GRID(grid), exit_button, 0, 7, 1, 1); //Anexa o botão de sair ao grid

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL); //Conecta o sinal de destruição da janela ao gtk_main_quit
    g_signal_connect(insert_button, "clicked", G_CALLBACK(on_insert_medal_clicked), &app_data); // Conecta o sinal de clique do botão de inserir à função on_insert_medal_clicked
    g_signal_connect(list_button, "clicked", G_CALLBACK(on_list_medals_clicked), &app_data); // Conecta o sinal de clique do botão de listar à função on_list_medals_clicked
    g_signal_connect(search_button, "clicked", G_CALLBACK(on_search_medal_clicked), &app_data); // Conecta o sinal de clique do botão de buscar à função on_search_medal_clicked
    g_signal_connect(update_button, "clicked", G_CALLBACK(on_update_medal_clicked), &app_data); // Conecta o sinal de clique do botão de alterar à função on_update_medal_clicked
    g_signal_connect(print_button, "clicked", G_CALLBACK(on_print_medal_clicked), &app_data); // Conecta o sinal de clique do botão de exibir à função on_print_medal_clicked
    g_signal_connect(delete_button, "clicked", G_CALLBACK(on_delete_medal_clicked), &app_data); // Conecta o sinal de clique do botão de excluir à função on_delete_medal_clicked
    g_signal_connect(export_button, "clicked", G_CALLBACK(on_export_to_csv_clicked), &app_data); // Conecta o sinal de clique do botão de exportar à função on_export_to_csv_clicked
    g_signal_connect(exit_button, "clicked", G_CALLBACK(on_exit_clicked), NULL); // Conecta o sinal de clique do botão de sair à função on_exit_clicked

    gtk_widget_show_all(window); //Exibe todos os widgets da janela

    // Inicializa o pipeline de música com a primeira faixa
    pipeline = play_music(playlist[current_track]); //Inicializa o pipeline de música com a primeira faixa
    if (!pipeline) { //Verifica se a pipeline foi criada
        g_printerr("Failed to start music playback.\n"); //Mensagem de erro
        return;
    }

    gtk_main(); //Inicia o loop principal do GTK

    // Limpa o pipeline de música ao sair
    if (pipeline) {
        gst_element_set_state(pipeline, GST_STATE_NULL); //Define o estado da pipeline como nulo
        gst_object_unref(pipeline); //Libera a pipeline
    }

    // Finaliza o GStreamer
    gst_deinit();
}

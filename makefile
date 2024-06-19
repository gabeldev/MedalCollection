# Nome do executável
TARGET = MedalCollection

# Compilador
CC = gcc

# Flags de compilação
CFLAGS = `pkg-config --cflags gtk+-3.0 gstreamer-1.0` -Wall -g

# Bibliotecas necessárias
LIBS = `pkg-config --libs gtk+-3.0 gstreamer-1.0`

# Arquivos fontes
SRCS = $(wildcard *.c)

# Arquivos objetos
OBJS = $(SRCS:.c=.o)

# Regra padrão
all: $(TARGET)

# Regra para construir o executável
$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LIBS)

# Regra para compilar arquivos .c em .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para executar o programa
run: $(TARGET)
	./$(TARGET)

# Limpeza dos arquivos objetos e executável
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets (não correspondem a arquivos reais)
.PHONY: all clean run

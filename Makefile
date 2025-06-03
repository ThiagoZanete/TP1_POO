# Compilador e flags
CC := g++
CFLAGS := -Wall -Wextra -Iinclude -std=c++17

# Diretórios
SRC_DIR := src
INC_DIR := include
BUILD_DIR := build
BIN_DIR := bin

# Arquivos fonte e objetos
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Executável final
TARGET := $(BIN_DIR)/app

# Regra padrão
all: $(TARGET)

# Linkagem
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(OBJS) -o $@

# Compilação dos arquivos .cpp para .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

# Alvos que não são arquivos
.PHONY: all clean

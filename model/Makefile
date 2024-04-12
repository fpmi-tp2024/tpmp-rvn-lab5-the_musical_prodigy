# Paths
SRC_DIR := src
INCLUDE_DIR := include
OBJ_DIR := obj
BIN_DIR := bin

# Compiler settings
CC := g++.exe
CFLAGS := -I$(INCLUDE_DIR) -I"D:\vcpkg\vcpkg\installed\x64-windows\include"
LDFLAGS := -L"D:\vcpkg\vcpkg\installed\x64-windows\lib" -lSQLiteCpp

# Source files
SOURCES := $(wildcard $(SRC_DIR)/*.cpp)
HEADERS := $(wildcard $(INCLUDE_DIR)/*.h)

# Executable name
EXECUTABLE := $(BIN_DIR)/music_app.exe

# Объектные файлы
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES))

# Правила сборки
all: directories $(EXECUTABLE)

directories:
	@if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
	@if not exist $(BIN_DIR) mkdir $(BIN_DIR)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(EXECUTABLE) $(OBJECTS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@if exist $(OBJ_DIR) rmdir /s /q $(OBJ_DIR)
	@if exist $(BIN_DIR) rmdir /s /q $(BIN_DIR)

.PHONY: all directories clean
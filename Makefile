CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
SRC_DIR = src
OBJ_DIR = src
TARGET = hsh
SRC = $(SRC_DIR)/main.c $(SRC_DIR)/builtins.c $(SRC_DIR)/command_exec.c \
      $(SRC_DIR)/logic_op.c $(SRC_DIR)/pipe.c $(SRC_DIR)/redirec.c $(SRC_DIR)/utils.c
OBJ = $(OBJ_DIR)/main.o $(OBJ_DIR)/builtins.o $(OBJ_DIR)/command_exec.o \
      $(OBJ_DIR)/logic_op.o $(OBJ_DIR)/pipe.o $(OBJ_DIR)/redirec.o $(OBJ_DIR)/utils.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)

.PHONY: all clean


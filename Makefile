CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
SRC_DIR = src
TARGET = hsh
SRC = $(SRC_DIR)/main.c $(SRC_DIR)/builtins.c $(SRC_DIR)/command_exec.c \
      $(SRC_DIR)/logic_op.c $(SRC_DIR)/pipe.c $(SRC_DIR)/redirec.c $(SRC_DIR)/utils.c \
      $(SRC_DIR)/env.c
OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean


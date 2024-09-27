# Makefile for the shell project

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Werror -g

# Source files
SRCS = main.c builtins.c command_exec.c logic_op.c pipe.c redirec.c utils.c env.c

# Object files
OBJS = $(SRCS:.c=.o)

# Target executable
TARGET = hsh

# Default target
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile source files into object files
%.o: %.c shell.h
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean


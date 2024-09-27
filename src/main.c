#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"

#define MAX_COMMAND_LENGTH 1024

void display_prompt() {
    printf("shell> ");
}

char *read_input() {
    char *input = NULL;
    size_t len = 0;
    getline(&input, &len, stdin);
    return input;
}

char **parse_input(char *input) {
    char **args = malloc(MAX_COMMAND_LENGTH * sizeof(char *));
    char *token;
    int position = 0;

    token = strtok(input, " \n");
    while (token != NULL) {
        args[position] = token;
        position++;
        token = strtok(NULL, " \n");
    }
    args[position] = NULL;
    return args;
}

void execute_command(char **args) {
    if (args[0] == NULL) {
        return;
    }

    if (strcmp(args[0], "exit") == 0) {
        exit_shell();
    } else if (strcmp(args[0], "cd") == 0) {
        change_directory(args[1]);
    } else if (strcmp(args[0], "env") == 0) {
        print_environment();
    } else {
        pid_t pid = fork();
        if (pid == 0) {
            if (execvp(args[0], args) == -1) {
                perror("shell");
            }
            exit(EXIT_FAILURE);
        } else if (pid < 0) {
            perror("shell");
        } else {
            wait(NULL);
        }
    }
}

int main() {
    char *input;
    char **args;

    while (1) {
        display_prompt();
        input = read_input();
        args = parse_input(input);
        execute_command(args);
        free(input);
        free(args);
    }

    return 0;
}

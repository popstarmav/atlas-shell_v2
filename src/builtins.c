#include "shell.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

void exit_shell() {
    exit(0);
}

void change_directory(char *command) {
    char *directory = extract_directory_from_command(command);
    if (chdir(directory) != 0) {
        perror("cd error");
    }
}

void print_environment() {
    extern char **environ;
    for (int i = 0; environ[i] != NULL; i++) {
        printf("%s\n", environ[i]);
    }
}


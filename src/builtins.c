#include "shell.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void exit_shell() {
    exit(0);
}

int change_directory(char *command) {
    char *home_dir;

    if (command == NULL || compare_strings(command, "") == 0) {
        home_dir = getenv("HOME");
        if (home_dir == NULL) {
            fprintf(stderr, "cd error: HOME environment variable not set\n");
            return -1;
        }
        command = home_dir;
    }

    if (chdir(command) != 0) {
        perror("cd error");
        return -1;
    }

    return 0;
}

void print_environment() {
    extern char **environ;
    for (int i = 0; environ[i] != NULL; i++) {
        printf("%s\n", environ[i]);
    }
}


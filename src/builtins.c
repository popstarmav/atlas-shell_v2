#include "shell.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void exit_shell() {
    exit(0);
}

int change_directory(char *command) {
    if (command == NULL || custom_strcmp(command, "") == 0) {
        fprintf(stderr, "cd error: No directory specified\n");
        return -1;
    }
    if (chdir(command) != 0) {
        perror("cd error");
    } else {
        char cwd[1024];
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            printf("Changed directory to: %s\n", cwd);
        } else {
            perror("getcwd error");
        }
    }
    return 0;
}

void print_environment() {
    extern char **environ;
    for (int i = 0; environ[i] != NULL; i++) {
        printf("%s\n", environ[i]);
    }
}


#include "shell.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void exit_shell() {
    exit(0);
}

int change_directory(char *command) {
    char *directory = extract_directory_from_command(command);

    if (directory == NULL) {
        fprintf(stderr, "cd error: No directory specified\n");
        return -1; // Return -1 to indicate failure
    }

    if (chdir(directory) != 0) {
        perror("cd error");
        free(directory);
        return -1; // Return -1 to indicate failure
    } else {
        char cwd[1024];
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            printf("Changed directory to: %s\n", cwd);
        } else {
            perror("getcwd error");
        }
    }

    free(directory);
    return 0; // Return 0 to indicate success
}

void print_environment() {
    extern char **environ;
    for (int i = 0; environ[i] != NULL; i++) {
        printf("%s\n", environ[i]);
    }
}


#include "shell.h"
#include <string.h>
#include <stdlib.h>

char *extract_directory_from_command(char *command) {
    if (strcmp(command, "cd") == 0) {
        return getenv("HOME");
    }

    char *token = strtok(command, " ");
    token = strtok(NULL, " ");
    if (token) {
        return strdup(token);
    }

    return NULL;
}

void free_array(char **arr) {
    for (int i = 0; arr[i] != NULL; i++) {
        free(arr[i]);
    }
    free(arr);
}


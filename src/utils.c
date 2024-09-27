#include <string.h>
#include <stdlib.h>

char *extract_directory_from_command(char *command) {
    char *token = strtok(command, " ");
    token = strtok(NULL, " ");
    return (token);
}

void free_array(char **arr) {
    for (int i = 0; arr[i] != NULL; i++) {
        free(arr[i]);
    }
    free(arr);
}


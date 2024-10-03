#include "shell.h"
#include <string.h>
#include <stdlib.h>

int compare_strings(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}

char *extract_directory_from_command(char *command) {
    if (compare_strings(command, "cd") == 0) {
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


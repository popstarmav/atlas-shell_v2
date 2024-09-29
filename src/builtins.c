#include "shell.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void exit_shell() {
    exit(0);
}

void print_environment() {
    extern char **environ;
    for (int i = 0; environ[i] != NULL; i++) {
        printf("%s\n", environ[i]);
    }
}


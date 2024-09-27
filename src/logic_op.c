#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void handle_logical_operators(char **args) {
    int status;
    for (int i = 0; args[i] != NULL; i++) {
        if (strcmp(args[i], "&&") == 0) {
            args[i] = NULL;
            pid_t pid = fork();
            if (pid == 0) {
                execvp(args[0], args);
                perror("execvp failed");
                exit(EXIT_FAILURE);
            } else if (pid < 0) {
                perror("fork failed");
                exit(EXIT_FAILURE);
            }
            wait(&status);
            if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
                execvp(args[i + 1], &args[i + 1]);
                perror("execvp failed");
            }
            break;
        } else if (strcmp(args[i], "||") == 0) {
            args[i] = NULL;
            pid_t pid = fork();
            if (pid == 0) {
                execvp(args[0], args);
                perror("execvp failed");
                exit(EXIT_FAILURE);
            } else if (pid < 0) {
                perror("fork failed");
                exit(EXIT_FAILURE);
            }
            wait(&status);
            if (!(WIFEXITED(status) && WEXITSTATUS(status) == 0)) {
                execvp(args[i + 1], &args[i + 1]);
                perror("execvp failed");
            }
            break;
        }
    }
}


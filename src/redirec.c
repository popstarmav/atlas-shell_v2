#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

void handle_redirection(char **args, char *file, int redirection_type) {
    pid_t pid = fork();
    if (pid == 0) {
        int fd;
        if (redirection_type == 0) { // Output redirection
            fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if (fd == -1) {
                perror("Error opening file for writing");
                exit(EXIT_FAILURE);
            }
            dup2(fd, STDOUT_FILENO);
        } else { // Input redirection
            fd = open(file, O_RDONLY);
            if (fd == -1) {
                perror("Error opening file for reading");
                exit(EXIT_FAILURE);
            }
            dup2(fd, STDIN_FILENO);
        }
        close(fd);

        if (execvp(args[0], args) == -1) {
            perror("Execution error");
            exit(EXIT_FAILURE);
        }
    } else if (pid > 0) {
        wait(NULL);
    } else {
        perror("Fork error");
    }
}


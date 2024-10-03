#ifndef SHELL_H
#define SHELL_H

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* Maximum command length */
#define MAX_COMMAND_LENGTH 1024

/* Function prototypes */
int compare_strings(const char *str1, const char *str2);

/* main.c */
void display_prompt(void);
char *read_input(void);
char **parse_input(char *input);
void execute_command(char **args);

/* builtins.c */
int change_directory(char *command);
void print_environment(void);

/* command_exec.c */
void ex_command(char **args);

/* pipe.c */
void execute_pipe(char **args1, char **args2);

/* redirec.c */
void handle_redirection(char **args, char *file, int redirection_type);

/* utils.c */
void print_error(const char *message);

#endif /* SHELL_H */


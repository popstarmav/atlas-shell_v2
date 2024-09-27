#ifndef SHELL_H
#define SHELL_H


void exit_shell();
void change_directory(char *command);
void print_environment();
char *extract_directory_from_command(char *command);

#endif /* SHELL_H */


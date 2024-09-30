#ifndef SHELL_H
#define SHELL_H

void exit_shell();
int change_directory(char *command);
char *extract_directory_from_command(char *command);
void print_environment();

#endif /* SHELL_H */


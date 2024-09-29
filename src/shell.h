#ifndef SHELL_H
#define SHELL_H

void exit_shell();
int change_directory(const char *command); // Declaration, no implementation here
void print_environment();
char *extract_directory_from_command(const char *command);

#endif /* SHELL_H */


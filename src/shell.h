#ifndef SHELL_H
#define SHELL_H


/* Constants */
#define BUFFER_SIZE 1024
#define TOKEN_DELIM " \t\r\n\a"

/* Function prototypes */

/* Shell initialization functions */
void shell_loop(void); 
char *read_line(void);
char **split_line(char *line); 
int execute(char **args)

/* Built-in shell commands */
int shell_cd(char **args);
int shell_help(char **args);
int shell_exit(char **args);

/* Command execution helpers */
int launch_process(char **args);
int num_builtins(void);

/* Built-in command list */
extern char *builtin_str[];
extern int (*builtin_func[])(char **);

#endif /* SHELL_H */


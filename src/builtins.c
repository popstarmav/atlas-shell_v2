#include <shell.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int shell_cd(char **args)
{
    if (args[1] == NULL) 
    {
        if (chdir(getenv("HOME")) != 0) {
            perror("shell");
        }
    } else {
        if (chdir(args[1]) != 0) {
            perror("shell");
        }
    }
    return 1;
}

int shell_exit(char **args)
{
    return 0;
}

int shell_env(char **args)
{
    extern char **environ;
    for (int i = 0; environ[i] != NULL; i++) {
        printf("%s\n", environ[i]);
    }
    return 1;
}

char *builtin_str[] = {
    "cd",
    "exit",
    "env"
};

int (*builtin_func[]) (char **) = {
    &shell_cd,
    &shell_exit,
    &shell_env
};

int shell_num_builtins()
{
    return sizeof(builtin_str) / sizeof(char *);
}

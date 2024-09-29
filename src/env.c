#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

void print_enviroment()
{
        extern char **environ;
        for (int i = 0; environ[i] != NULL; i++)
        {
                printf("%s\n", environ[i]);
        }
}

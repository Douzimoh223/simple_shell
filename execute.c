#include "shell.h"
/**
 * execmd -  expects the command path, the array of command-line
 * arguments (argv), and the environment variables
 * @command - it is a number of arguments
 * Returns -1 an error or nothing in succes
 */
void execmd(char **argv)
{
char *command = NULL;
if (argv)
{
/* get the command */
command = argv[0];

/* execute the command with execve */
if (execve(command, argv, NULL) == -1)
{
perror("Error:");
}
}
}

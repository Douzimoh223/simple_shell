#include "shell.h"
/**
 * The code then proceeds to tokenize the input line into
 * individual words using strtok and stores them in the argv array.
 * execmd - execmd function is called to execute the command
 * represented by the argv array. 
 * Returns: 0 or  Nothing.
 */

int main(int ac, char **argv)
{
char *prompt = "(Shell) $ ";
char *lineptr = NULL, *lineptr_copy = NULL;
size_t n = 0;
ssize_t c;
const char *delim = " \n";
int num_tokens = 0;
char *token;
int i;
int exit_shell = 0;
(void)ac;
 while (!exit_shell)
{
printf("%s", prompt);
c = getline(&lineptr, &n, stdin);
/* check if the getline function failed */
if (c == -1)
{
printf("Exiting....\n");
break;  /* Exit the loop if getline fails */
}
/* Checking for "exit" command */
if (strcmp(lineptr, "exit\n") == 0)
{
printf("Exiting shell....\n");
exit_shell = 1;  /* Set exit_shell to true to exit the loop */
continue;  /* Move to the next iteration of the loop */
}
/* allocate space for a copy of the lineptr */
lineptr_copy = malloc(sizeof(char) * c);
if (lineptr_copy== NULL)
{
perror("Memory allocation error");
return (-1);
}
/* copy lineptr to lineptr_copy */
strcpy(lineptr_copy, lineptr);
/* split the string (lineptr) into an array of words */
/* calculate the sum of  number of tokens */
token = strtok(lineptr, delim);
while (token != NULL)
{
num_tokens++;
token = strtok(NULL, delim);
}
num_tokens++;
/* Allocate space to hold the array of strings */
argv = malloc(sizeof(char *) * num_tokens);
/* Store each token in the argv array */
token = strtok(lineptr_copy, delim);
for (i = 0; token != NULL; i++)
{
argv[i] = malloc(sizeof(char) * strlen(token));
strcpy(argv[i], token);
token = strtok(NULL, delim);
}
argv[i] = NULL;
execmd(argv);/* execute the command */
} 
/* allocated memory */ 
free(lineptr_copy);
lineptr = NULL;
free(lineptr);
return (0);
}

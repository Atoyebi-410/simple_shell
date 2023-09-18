#include "shell.h"


/**
 * builtin_env - this shows the environment where the shell runs
 * @data: this is the structure for the program's data
 * Return: this returns zero if success
 */

int builtin_env(data_of_program *data)
{
int i;
char cpname[50] = {'\0'};
char *var_copy = NULL;

/* this is if else arguments */
if (data->tokens[1] == NULL)
print_environ(data);
else
{
for (i = 0; data->tokens[1][i]; i++)
{/* checks if exists a char = */
if (data->tokens[1][i] == '=')
{/* this checks if exists a var with the same name and change its value*/
var_copy = str_duplicate(env_get_key(cpname, data));
if (var_copy != NULL)
env_set_key(cpname, data->tokens[1] + i + 1, data);

/* this print the environ */
print_environ(data);
if (env_get_key(cpname, data) == NULL)
{/* this print the variable if it does not exist in the environ */
_print(data->tokens[1]);
_print("\n");
}
else
{/* this return the old value of the variable*/
env_set_key(cpname, var_copy, data);
free(var_copy);
}
return (0);
}
cpname[i] = data->tokens[1][i];
}
errno = 2;
perror(data->command_name);
errno = 127;
}
return (0);
}


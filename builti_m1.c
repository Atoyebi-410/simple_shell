#include "shell.h"


/**
 * set_work_directory - this is to set the work directory
 * @data: this is the structure for the program's data
 * @new_dir: this is the path to be set as work directory
 * Return: return zero if successful, or other number if its declared
 */


int set_work_directory(data_of_program *data, char *new_dir)
{
char old_dir[128] = {0};
int err_code = 0;

getcwd(old_dir, 128);

if (!str_compare(old_dir, new_dir, 0))
{
err_code = chdir(new_dir);
if (err_code == -1)
{
errno = 2;
return (3);
}
env_set_key("PWD", new_dir, data);
}
env_set_key("OLDPWD", old_dir, data);
return (0);
}



/**
 * builtin_help - This shows the environment where the shell will run
 * @data: This is structure for the program's data
 * Return: return zero if successful, or other number if its declared
 */

int builtin_help(data_of_program *data)
{
int i, length = 0;
char *mensajes[6] = {NULL};

mensajes[0] = HELP_MSG;

/* validate args */
if (data->tokens[1] == NULL)
{
_print(mensajes[0] + 6);
return (1);
}
if (data->tokens[2] != NULL)
{
errno = E2BIG;
perror(data->command_name);
return (5);
}
mensajes[1] = HELP_EXIT_MSG;
mensajes[2] = HELP_ENV_MSG;
mensajes[3] = HELP_SETENV_MSG;
mensajes[4] = HELP_UNSETENV_MSG;
mensajes[5] = HELP_CD_MSG;

for (i = 0; mensajes[i]; i++)
{
/*print the length of string */
length = str_length(data->tokens[1]);
if (str_compare(data->tokens[1], mensajes[i], length))
{
_print(mensajes[i] + length + 1);

return (1);
}
}
/*if there is no match, print error and return -1 */
errno = EINVAL;
perror(data->command_name);
return (0);
}

/**
 * builtin_alias - This is to add, remove or show aliases
 * @data: This is the structure for the program's data
 * Return: zero if sucess, or other number if its declared in the arguments
 */


int builtin_alias(data_of_program *data)
{
int i = 0;

/* this will print all environment if there is no argument */
if (data->tokens[1] == NULL)
return (print_alias(data, NULL));

while (data->tokens[++i])
{/* if there are arguments, print env variable*/
if (count_characters(data->tokens[i], "="))
set_alias(data->tokens[i], data);
else
print_alias(data, data->tokens[i]);
}

return (0);
}

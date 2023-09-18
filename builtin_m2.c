#include "shell.h"

/**
 * builtin_exit - this is the exit of the program with the status
 * @data: This is the structure for the program's data
 * Return: return zero if successful
 */

int builtin_exit(data_of_program *data)
{
int i;

if (data->tokens[1] != NULL)
{/*check if the argument is a number if it exists*/
for (i = 0; data->tokens[1][i]; i++)
if ((data->tokens[1][i] < '0' || data->tokens[1][i] > '9')
&& data->tokens[1][i] != '+')
{/*if it's not a number*/
errno = 2;
return (2);
}
errno = _atoi(data->tokens[1]);
}
free_all_data(data);
exit(errno);
}

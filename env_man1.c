#include "shell.h"


/**
 * env_remove_key - This will remove a key from the environment
 * @key: This is the key to remove
 * @data: This is the structure of the program's data
 * Return: return 1 if the key was removed successfully
 */

int env_remove_key(char *key, data_of_program *data)
{
int i, key_length = 0;

/* this will validate the arg */
if (key == NULL || data->env == NULL)
return (0);

/* this will obtain the len of the variable requested */
key_length = str_length(key);

for (i = 0; data->env[i]; i++)
{/* this loops through the environ and checks for coincidences */
if (str_compare(key, data->env[i], key_length) &&
data->env[i][key_length] == '=')
{/* this will remove the key if already exists */
free(data->env[i]);
/* this will move the other key down in one position */
i++;
for (; data->env[i]; i++)
{
data->env[i - 1] = data->env[i];
}
/* put the NULL value at the new end of the list */
data->env[i - 1] = NULL;
return (1);
}
}
return (0);
}


/**
 * print_environ - this prints the current env
 * @data: this is the structure for the program's data
 * Return: 0
 */

void print_environ(data_of_program *data)
{
int j;

for (j = 0; data->env[j]; j++)
{
_print(data->env[j]);
_print("\n");
}
}


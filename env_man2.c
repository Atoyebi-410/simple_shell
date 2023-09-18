#include "shell.h"

/**
 * env_get_key - This gets the value of an env variable
 * @key: This is the environment variable of interest
 * @data: This is the structure of the program's data
 * Return: returns a pointer to the value of the variable
 */


char *env_get_key(char *key, data_of_program *data)
{
int i, key_length = 0;

/*This will validate the arg */
if (key == NULL || data->env == NULL)
return (NULL);

/* This will obtain the len of the variable requested */
key_length = str_length(key);

for (i = 0; data->env[i]; i++)
{/* this will loop through the environ and check for coincidence of the vame */
if (str_compare(key, data->env[i], key_length) &&
data->env[i][key_length] == '=')
{/* this will return the value of the key NAME=  when find it*/
return (data->env[i] + key_length + 1);
}
}
/* it will return NULL if key is not found */
return (NULL);
}



/**
 * env_set_key - This will overwrite the value of the env variable
 * or create if does not exist.
 * @key: This is the name of the variable to set
 * @value: This is the new value
 * @data: This is the structure of the program's data
 * Return: return 1 if the parameters are NULL
 */

int env_set_key(char *key, char *value, data_of_program *data)
{
int i, key_length = 0, is_new_key = 1;

/* this will validate the arg */
if (key == NULL || value == NULL || data->env == NULL)
return (1);

/* this will get the len of the variable requested */
key_length = str_length(key);

for (i = 0; data->env[i]; i++)
{/* this will loop through the environ and check for coincidence of the vame */
if (str_compare(key, data->env[i], key_length) &&
data->env[i][key_length] == '=')
{/* This checks if key exists */
is_new_key = 0;
/* this frees the entire variable, it is new created below */
free(data->env[i]);
break;
}
}
/* this is to make a string of the form key=value */
data->env[i] = str_concat(str_duplicate(key), "=");
data->env[i] = str_concat(data->env[i], value);

if (is_new_key)
{/*checks if the variable is new, it is create at end*/
data->env[i + 1] = NULL;
}
return (0);
}


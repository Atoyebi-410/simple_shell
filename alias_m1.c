#include "shell.h"


/**
 * get_alias - this is to add, remove or show aliases
 * @data: this is the structure for the program's data
 * @name: this is the name of the requested alias.
 * Return: if successful, return 0, or other number if in the args
 */

char *get_alias(data_of_program *data, char *name)
{
	int i, alias_length;

	/* this is to validate the args */
	if (name == NULL || data->alias_list == NULL)
		return (NULL);

	alias_length = str_length(name);

	for (i = 0; data->alias_list[i]; i++)
	{/* this loops through the environ and check for coincidence of the varname */
		if (str_compare(name, data->alias_list[i], alias_length) &&
			data->alias_list[i][alias_length] == '=')
		{/* this returns the val of the key when found */
			return (data->alias_list[i] + alias_length + 1);
		}
	}
	/* returns NULL if not found */
	return (NULL);

}


/**
 * print_alias - this is to add, remove or show aliases
 * @data: this is the structure for the program's data
 * @alias: this is the name of the alias to be printed
 * Return: 0 if sucessful, or other number if its declared in the arguments
 */

int print_alias(data_of_program *data, char *alias)
{
	int i, j, alias_length;
	char buffer[250] = {'\0'};

	if (data->alias_list)
	{
		alias_length = str_length(alias);
		for (i = 0; data->alias_list[i]; i++)
		{
			if (!alias || (str_compare(data->alias_list[i], alias, alias_length)
				&&	data->alias_list[i][alias_length] == '='))
			{
				for (j = 0; data->alias_list[i][j]; j++)
				{
					buffer[j] = data->alias_list[i][j];
					if (data->alias_list[i][j] == '=')
						break;
				}
				buffer[j + 1] = '\0';
				buffer_add(buffer, "'");
				buffer_add(buffer, data->alias_list[i] + j + 1);
				buffer_add(buffer, "'\n");
				_print(buffer);
			}
		}
	}

	return (0);
}

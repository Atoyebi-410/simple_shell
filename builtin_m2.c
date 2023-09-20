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
{/*check if it's not a number*/
errno = 2;
return (2);
}
errno = _atoi(data->tokens[1]);
}
free_all_data(data);
exit(errno);
}

/**
 * builtin_cd - this is to change the current directory
 * @data: this is the the struct for the program's data
 * Return: 0 if sucess, or other number arguments
 */

int builtin_cd(data_of_program *data)
{
	char *dir_home = env_get_key("HOME", data), *dir_old = NULL;
	char old_dir[128] = {0};
	int error_code = 0;

	if (data->tokens[1])
	{
		if (str_compare(data->tokens[1], "-", 0))
		{
			dir_old = env_get_key("OLDPWD", data);
			if (dir_old)
				error_code = set_work_directory(data, dir_old);
			_print(env_get_key("PWD", data));
			_print("\n");

			return (error_code);
		}
		else
		{
			return (set_work_directory(data, data->tokens[1]));
		}
	}
	else
	{
		if (!dir_home)
			dir_home = getcwd(old_dir, 128);

		return (set_work_directory(data, dir_home));
	}
	return (0);
}

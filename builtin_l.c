#include "shell.h"



/**
 * builtins_list - this searches for match and execute the associated builtin
 * @data: this is the structure for the program's data
 * Return: this returns the return of the function executed
 * otherwise -1 will be returned.
 **/

int builtins_list(data_of_program *data)
{
int iterator;
builtins options[] = {
{"exit", builtin_exit},
{"help", builtin_help},
{"cd", builtin_cd},
{"alias", builtin_alias},
{"env", builtin_env},
{"setenv", builtin_set_env},
{"unsetenv", builtin_unset_env},
{NULL, NULL}
};

/*this loops through the structure*/
for (iterator = 0; options[iterator].builtin != NULL; iterator++)
{
/*check for a match between the given command and a builtin,*/
if (str_compare(options[iterator].builtin, data->command_name, 0))
{
/*this executes the function, and returns the returned value of the func*/
return (options[iterator].function(data));
		}
/*return -1 if there is no match*/
}
return (-1);
}

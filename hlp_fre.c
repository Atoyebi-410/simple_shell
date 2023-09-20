#include "shell.h"


/**
 * free_recurrent_data - this frees the fields needed for each loop
 * @data: This is the structure of the program's data
 * Return: 0
 */

void free_recurrent_data(data_of_program *data)
{
	if (data->tokens)
		free_array_of_pointers(data->tokens);
	if (data->input_line)
		free(data->input_line);
	if (data->command_name)
		free(data->command_name);

	data->input_line = NULL;
	data->command_name = NULL;
	data->tokens = NULL;
}



/**
 * free_all_data - this frees all field of the data
 * @data: this is the structure of the program's data
 * Return: 0
 */

void free_all_data(data_of_program *data)
{
	if (data->file_descriptor != 0)
	{
		if (close(data->file_descriptor))
			perror(data->program_name);
	}
	free_recurrent_data(data);
	free_array_of_pointers(data->env);
	free_array_of_pointers(data->alias_list);
}



/**
 * free_array_of_pointers - this free pointer of an array of pointers and the
 * array
 * @array: this is an array of pointers
 * Return: 0
 */

void free_array_of_pointers(char **array)
{
	int i;

	if (array != NULL)
	{
		for (i = 0; array[i]; i++)
			free(array[i]);

		free(array);
		array = NULL;
	}
}

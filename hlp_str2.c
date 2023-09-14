#include "shell.h"


/**
 * str_length - this returns the len of a str.
 * @string: this is a pointer to str.
 * Return: return the len of str.
 */

int str_length(char *string)
{
	int length = 0;

	if (string == NULL)
		return (0);

	while (string[length++] != '\0')
	{
	}
	return (--length);
}



/**
 * str_duplicate - This duplicates a str
 * @string: This is the str to be copied
 * Return: This is the pointer to an array
 */

char *str_duplicate(char *string)
{
	char *result;
	int length, i;

	if (string == NULL)
		return (NULL);

	length = str_length(string) + 1;

	result = malloc(sizeof(char) * length);

	if (result == NULL)
	{
		errno = ENOMEM;
		perror("Error");
		return (NULL);
	}
	for (i = 0; i < length ; i++)
	{
		result[i] = string[i];
	}

	return (result);
}

/**
 * str_compare - Compare two strings
 * @string1: This is the 1st str, or the shorter one
 * @string2: This is the 2nd str, or the longer one
 * @number: this is the num of chars to be compared, 0 if infinite
 * Return: returns 1 if the str are equals,and 0 if the str are different
 */


int str_compare(char *string1, char *string2, int number)
{
	int iterator;

	if (string1 == NULL && string2 == NULL)
		return (1);

	if (string1 == NULL || string2 == NULL)
		return (0);

	if (number == 0)
	{
		if (str_length(string1) != str_length(string2))
			return (0);
		for (iterator = 0; string1[iterator]; iterator++)
		{
			if (string1[iterator] != string2[iterator])
				return (0);
		}
		return (1);
	}
	else /* this checks if there is a number of characters to be compared */
	{
		for (iterator = 0; iterator < number ; iterator++)
		{
			if (string1[iterator] != string2[iterator])
			return (0);
		}
		return (1);
	}
}

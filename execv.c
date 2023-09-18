#include "shell.h"



/**
 * execute - This executes a command with its entire path var.
 * @data: this is a pointer to the program's data
 * Return: If sucess returns 0, otherwise, return -1.
 */

int execute(data_of_program *data)
{
int retval = 0, status;
pid_t pidd;

/* this checks for program in built ins */
retval = builtins_list(data);
if (retval != -1)/* checks if the program was found in built ins */
return (retval);

/* this checks for the program file system */
retval = find_program(data);
if (retval)
{/* this checks if program is not found */
return (retval);
}
else
{/* this checks if program was found */
pidd = fork(); /* this is used to create a child process */
if (pidd == -1)
{ /* checks if the fork call failed */
perror(data->command_name);
exit(EXIT_FAILURE);
}
if (pidd == 0)
{/* this is the child process, it executes the program*/
retval = execve(data->tokens[0], data->tokens, data->env);
if (retval == -1) /* if error when execve*/
perror(data->command_name), exit(EXIT_FAILURE);
}
else
{/* This is the father process, it waits and check the exit status */
wait(&status);
if (WIFEXITED(status))
errno = WEXITSTATUS(status);
else if (WIFSIGNALED(status))
errno = 128 + WTERMSIG(status);
}
}
return (0);
}


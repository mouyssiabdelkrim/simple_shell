#include "main.h"

/**
 * check_cmd - checks if cmd is builtin cmd
 *
 * @command: command to be checked
 * Return: returns 0 if true, else -1
 */

int check_cmd(char *command)
{
	int ii = 0;
	char *array_command[] = {"exit", "env", "clear", NULL};

	while (array_command[ii])
	{
		if (_strcmp(array_command[ii], command) == 0)
			return (0);

		ii++;
	}
	return (-1);
}

/**
 * exec_builtin - execs builtin commands
 * @command: cmd to be executed
 * @counter: cmd number
 * @argv: arg vector
 * Return: returns 0 on success, -1 otherwise
 */

int exec_builtin(char **command, int counter, char *argv)
{
	int ii = 0;
	built_ins selector[] = {
		{"exit", __exit},
		{"env", _env},
		{"clear", clear},
		{NULL, NULL}
	};

	while ((selector + ii)->command)
	{
		if (_strcmp((selector + ii)->command, command[0]) == 0)
			return ((selector + ii)->func(command, counter, argv));
		ii++;
	}
	return (-1);
}

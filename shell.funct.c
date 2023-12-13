#include "main.h"

/**
 * __exit - exits shell
 * @cmd: cmd
 * @counter: no cmd executed
 * @argv: arg vector
 * Return: returns 0 on success, else -1
 */

int __exit(char **cmd, int counter, char *argv)
{
	int ii = 0, stat = 0;
	char *pointer;

	if (!cmd[1])
	{
		free(cmd);
		exit(0);
		return (0);
	}

	while (cmd[1][ii])
	{
		if (_isdigit(cmd[1][ii]) == 0)
		{
			write(2, argv, _strlen(argv));
			write(2, ": ", 2);
			pointer = _itoa(counter);
			write(2, pointer, _strlen(pointer));
			write(2, ": ", 2);
			write(2, cmd[0], _strlen(cmd[0]));
			write(2, ": Illegal number: ", 18);
			write(2, cmd[1], _strlen(cmd[1]));
			write(2, "\n", 1);
			return (-1);
		}
	ii++;
	}
	stat = _atoi(cmd[1]);
	free(cmd);
	exit(stat);
	return (0);
}

/**
 * _env - prints current env
 * @cmd: cmd
 * @counter: cmd number
 * @argv: arg vector
 * Return: returns 0 on success, else -1
 */

int _env(char **cmd, int counter, char *argv)
{
	int ii = 0;
	(void)cmd;
	(void)counter;
	(void)argv;

	while (environ[ii])
	{
		write(1, environ[ii], _strlen(environ[ii]));
		write(1, "\n", 1);
		ii++;
	}
	return (0);
}


/**
 * clear - clears terminal window
 * @cmd: cmd
 * @counter: cmd number
 * @argv: arg vector
 * Return: returns 0 on success, else -1
 */

int clear(char **cmd, int counter, char *argv)
{
	(void)cmd;
	(void)counter;
	(void)argv;

	write(1, "\033[1;1H\033[2J", 10);

	return (0);
}

#include "main.h"

/**
 * main - an example of execve
 *
 *@argc: no of args
 *@argv: arg vectors
 * Return: returns 0.
 */

int main(int argc, char **argv)
{
	char *buff, **array, cc;
	int count = 0;

	(void)argc;
	while (1)
	{
		count++;
		if (isatty(STDIN_FILENO))
			write(1, "$ ", 2);

		buff = _getline();

		cc = buff[0];

		if (cc == '\0')
			continue;
		array = parser(buff);
		if (check_cmd(array[0]) == 0)
		{
			exec_builtin(array, count, argv[0]);
			free(array);
			free(buff);
			array = NULL;
			buff = NULL;
			continue;
		}
		else
			execute(array, count, argv, buff);
		free(array);
		free(buff);
	}
	return (0);
}
/**
*parser- parse cmd input
*
*@buffer: string with cmd
*
*Return: returns parsed command
*/

char **parser(char *buffer)
{
	char **command, *tok;
	int ii;

	if (buffer == NULL)
		return (NULL);

	tok = strtok(buffer, " \n");
	if (tok == NULL)
		return (NULL);

	command = malloc(sizeof(char *) * 1024);

	ii = 0;
	while (tok)
	{
		command[ii++] = tok;
		tok = strtok(NULL, " \n");
	}
	command[ii] = NULL;
	return (command);
}

/**
*execute - execute cmds within shell
*
*@array: the parsed cmd
*@counter: cmd number
*@argv: commandline args
*@buffer: the buffer containing input
*/

void execute(char **array, int counter, char **argv, char *buffer)
{
	int stat;

	if (fork() != 0)
	{
		wait(&stat);
	}
	else
	{
		if (_strncmp(array[0], "./", 2) != 0 && _strncmp(array[0], "/", 1) != 0)
			path_finder(&array[0]);

		if (execve(*array, array, environ) == -1)
		{
			printE(counter, array[0], argv[0]);
			free(array);
			free(buffer);
			exit(EXIT_FAILURE);
		}
	}
}

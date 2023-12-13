#include "main.h"

/**
 * path_finder -  search in $PATH for executable cmd
 * @cmd: parsed input
 * Return: returns 1  Failure, else 0 on success.
 */

void path_finder(char **cmd)
{
	char *path_t, *val, *command_path;
	struct stat buf;

	path_t = _getenv("PATH");
	val = strtok(path_t, ":");
	while (val != NULL)
	{
		command_path = build(*cmd, val);
		if (stat(command_path, &buf) == 0)
		{
			*cmd = _strdup(command_path);
			free(command_path);
			break;
		}
		free(command_path);
		val = strtok(NULL, ":");
	}
	free(path_t);
}

/**
 * build - build cmd
 * @token: executable cmd
 * @value: dir containing cmd
 *
 * Return: return parsed full path of cmd or NULL case failes
 */

char *build(char *token, char *value)
{
	char *command;
	size_t leng;

	leng = _strlen(value) + _strlen(token) + 2;
	command = malloc(sizeof(char) * leng);
	if (command == NULL)
	{
		return (NULL);
	}

	memset(command, 0, leng);

	command = _strcat(command, value);
	command = _strcat(command, "/");
	command = _strcat(command, token);

	return (command);
}

/**
 * _getenv - get value of env var by name
 * @name: name of env var
 * Return: returns value of env var else NULL.
 */

char *_getenv(char *name)
{
	size_t null, vll;
	char *val;
	int ii, xx, jj;

	null = _strlen(name);
	for (ii = 0 ; environ[ii]; ii++)
	{
		if (_strncmp(name, environ[ii], null) == 0)
		{
			vll = _strlen(environ[ii]) - null;
			val = malloc(sizeof(char) * vll);
			if (!val)
			{
				free(val);
				perror("unable to alloc");
				return (NULL);
			}

			jj = 0;
			for (xx = null + 1; environ[ii][xx]; xx++, jj++)
			{
				val[jj] = environ[ii][xx];
			}
			val[jj] = '\0';

			return (val);
		}
	}

	return (NULL);
}

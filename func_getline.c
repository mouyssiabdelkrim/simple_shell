#include "main.h"
/**
*_getline - read input by user from stdin
* Return: return input
*/

char *_getline()
{
	int ii, buffer_size = 1024, rd;
	char cc = 0;
	char *buffer = malloc(buffer_size);

	if (buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}

	for (ii = 0; cc != EOF && cc != '\n'; ii++)
	{
		fflush(stdin);
		rd = read(STDIN_FILENO, &cc, 1);
		if (rd == 0)
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		buffer[ii] = cc;
		if (buffer[0] == '\n')
		{
			free(buffer);
			return ("\0");
		}
		if (ii >= buffer_size)
		{
			buffer = realloc(buffer, buffer_size + 1);
			if (buffer == NULL)
			{
				return (NULL);
			}
		}
	}
	buffer[ii] = '\0';
	hashtag_handle(buffer);
	return (buffer);
}

/**
 * hashtag_handle - remove everything after #
 * @buffer: input
 * Return: returns void
 */

void hashtag_handle(char *buffer)
{
	int ii;

		for (ii = 0; buffer[ii] != '\0'; ii++)
		{
			if (buffer[ii] == '#')
			{
			buffer[ii] = '\0';
			break;
			}
	}
}

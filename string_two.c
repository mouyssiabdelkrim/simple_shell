#include "main.h"

/**
 * _strncmp - compare amt (n) Of chars of 2 strngs.
 * @s1: String.
 * @s2: String.
 * @n: returns amount of chars to compare
 *
 * Return: returns 1 if strings don't match else 0
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t ii;

	if (s1 == NULL)
		return (-1);
	for (ii = 0; ii < n && s2[ii]; ii++)
	{
		if (s1[ii] != s2[ii])
		{
			return (1);
		}
	}
	return (0);
}

/**
*_strdup - duplicates str
*
*@str: string param
*
*Return: ptr to a duplicate of str
*/

char *_strdup(char *str)
{
	char *ss;
	size_t ii = 0, leng = 0;

	leng = _strlen(str);

	ss = malloc(sizeof(char) * (leng + 1));

	if (ss == NULL)
	{
		free(ss);
		return (NULL);
	}

	while (ii <= leng)
	{
		ss[ii] = str[ii];
		ii++;
	}
	return (ss);
}

/**
*_isdigit - checks if is digit
*@c: param int to test
*Return: return 1 if -9 else 0
*/

int _isdigit(char c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
*_atoi - converts str to int
*@s: ptrto str
*Return: int from string
*/

int _atoi(char *s)
{
	unsigned int number = 0, nn, ii;
	int sign = 1;

	for (nn = 0; *(s + nn) != '\0'; nn++)
	{
	}

	for (ii = 0; ii < nn; ii++)
	{
		if (s[ii] == '-')
			sign *= -1;

		else if (s[ii] >= '0' && s[ii] <= '9')
		number = number * 10 + (s[ii] - 48);

		else if (number > 0)
			break;
	}

	return (number * sign);
}

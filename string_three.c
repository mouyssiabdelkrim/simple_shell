#include "main.h"

/**
 * *_memcpy - copies mem area
 * @dest: dest string
 * @src: src string
 * @n: no of bytes
 * Return: returns ptr to dest
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int ii;

	for (ii = 0; ii < n; ii++)
	{
		dest[ii] = src[ii];
	}
	return (dest);
}

/**
 * *_memset - fills mem with constant byte
 * @s: ptr to string s
 * @b: constant byte
 * @n: no of bytes of mem
 * Return: returns ptr to s
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int ii;

	for (ii = 0; ii < n; ii++)
	{
		s[ii] = b;
	}
	return (s);
}

/**
 * _itoa - convert int to char
 * @n: int to be converted
 * Return: returns char ptr
 */

char *_itoa(unsigned int n)
{
	int leng = 0, ii = 0, number;
	char *ss;
	char tempo;

	number = n;
	while (number != 0)
	{
		leng++;
		number /= 10;
	}
	ss = malloc(leng + 1);
	if (!ss)
		return (NULL);
	*ss = '\0';
	while (n / 10)
	{
		ss[ii] = (n % 10) + '0';
		n /= 10;
		ii++;
	}
	ss[ii] = (n % 10) + '0';

	for (ii = 0; ii < (leng / 2); ii++)
	{
		tempo = ss[ii];
		ss[ii] = ss[(leng - 1) - ii];
		ss[(leng - 1) - ii] = tempo;
	}
	ss[ii + 1] = '\0';
	return (ss);
}

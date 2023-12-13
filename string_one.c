#include "main.h"

/**
 * *_strcpy - copies str pointed to by src including null byte(\0)
 *            to buffer pointed to by dest
 * @src: source of str to be copied
 * @dest: dest of string to be copied
 * Return: ptr to dest
 */

char *_strcpy(char *dest, char *src)
{
	int i, j = 0;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[j] = src[i];
		j++;
	}
	dest[j] = '\0';

	return (dest);
}

/**
 * _strcat - append src str to dest string
 * @src: the first string
 * @dest: the second string
 *
 * Return: returns a pointer to the resulting string dest
 */

char *_strcat(char *dest, char *src)
{
	int leng_dest = 0;
	int leng_src = 0;

	for (; dest[leng_dest] != '\0'; leng_dest++)
		;

	for (; src[leng_src] != '\0' ;)
		dest[leng_dest++] = src[leng_src++];

	dest[leng_dest] = '\0';
	return (dest);
}

/**
 * _strcmp - makes a comparison btwn 2 strings
 *
 * @s1: first string
 * @s2: second string
 * Return: 0 if identical
 *         <0 if 1st char in s1's ASCII value less than that of s2
 *         >0 if 1st charin s2's ASCII value greater than that of s2
 */

int _strcmp(char *s1, char *s2)
{
	int ii = 0;

	while (s1[ii] == s2[ii])
	{
		if (s1[ii] == '\0')
			return (0);
		ii++;
	}

	return (s1[ii] - s2[ii]);
}

/**
 * _strlen - return length of string
 * @s: string whose length is to be determined
 * Return: Always return 0
 */

int _strlen(char *s)
{
	int b;

	for (b = 0; *s != '\0'; s++)
		b++;

	return (b);
}

/**
 * *_strncpy - copies string
 * @dest: dest string
 * @src: src string
 * @n: no of bytes to be copied
 * Return: ptr to dest
 */

char *_strncpy(char *dest, char *src, int n)
{
	int a = 0;

	while (src[a] != '\0' && a < n)
	{
		dest[a] = src[a];
		a++;
	}

	while (a < n)
	{
		dest[a] = '\0';
		a++;
	}

	return (dest);
}

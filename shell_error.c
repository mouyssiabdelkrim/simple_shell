#include "main.h"
/**
*printE - this function prints an error message
*
*@counter: cmd number
*@cmd: cmd input
*@argv: cmd line arg
*/

void printE(int counter, char *cmd, char *argv)
{
	char *pointer;

	write(2, argv, _strlen(argv));
	write(2, ": ", 2);
	pointer = _itoa(counter);
	write(2, pointer, _strlen(pointer));
	write(2, ": ", 2);
	write(2, cmd, _strlen(cmd));
	write(2, ": not found\n", 12);
}

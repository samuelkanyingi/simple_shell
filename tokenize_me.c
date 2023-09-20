#include "listme.h"

/**
 * tokenize - function to tokenize a string
 * @linestring: string to tokenize
 * @args: store here tokenized string
 * @argc: number of argument count
 */
void tokenize(char *linestring, char *args[], int *argc)
{
	char *mytokens;

	mytokens = strtok(linestring, " ");
	for (; mytokens != NULL && *argc < MAX - 1; (*argc)++)
	{
		args[(*argc)] = mytokens;
		mytokens = strtok(NULL, " ");
	}
}

#include "listme.h"

/**
 * tokenize_tok - function to tokenize a string
 * @linestring: string to tokenize
 * @args: store here tokenized string
 * @argc: argument count to keep track
 */
void tokenize_tok(char *linestring, char *args[], int *argc)
{
	char *mytokens;

	mytokens = strtok(linestring, " ");
	while (mytokens != NULL)
	{
		args[(*argc)++] = mytokens;
		mytokens = strtok(NULL, " ");
	}
}

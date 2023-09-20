#include "listme.h"
#include <stdbool.h>
/**
 * main- entry of program
 * Return: 0 if success
 */
int main(void)
{
	char *buff_lineptr = NULL;
	size_t len = 0;
	ssize_t read_getline;
	char *args[MAX];
	int argc = 0;
	char *message = "#cisfun$ ";
	bool is_intera = isatty(STDIN_FILENO);

	while (1)
	{
		if (is_intera)
		{
			write(STDOUT_FILENO, message, custom_strlen(message));
		}
	read_getline = getline(&buff_lineptr, &len, stdin);
	if (read_getline == -1)
	{
		break;
	}
	if (read_getline > 0 && buff_lineptr[read_getline - 1] == '\n')
	{
		buff_lineptr[read_getline - 1] = '\0';
	}
	if (is_intera)
	{
	if (custom_strlen(buff_lineptr) == 0)
	{
		break;
	}
	}
	tokenize(buff_lineptr, args, &argc);
	if (argc > 0)
	{
		args[argc] = NULL;
		handle_me(args);
		argc = 0;
	}
	}
free(buff_lineptr);
	return (0);
}
/**
 * handle_me- handle user commands
 * @args : array of string having command and args
 */
void handle_me(char *args[])
{
	if (custom_strcmp(args[0], "exit") == 0)
	{
		if (args[1] != NULL)
		{
			int exit_status = custom_atoi(args[1]);

			exit(exit_status);
		}
		else
		{
			exit(0);
		}
	}
	else if (custom_strcmp(args[0], "env") == 0)
	{
		print_env();
	}
	else
	{
		childprocess(args[0], args);
	}
}

/**
 * print_env - print user environment
 */

void print_env(void)
{
	char **env;

	for (env = environ; *env != NULL; ++env)
	{
		write(STDOUT_FILENO, *env, custom_strlen(*env));
		write(1, "\n", 1);
	}
}

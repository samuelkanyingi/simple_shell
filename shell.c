#include "listme.h"
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
	bool interactive_mode = isatty(STDIN_FILENO);

	while (1)
	{
		if (interactive_mode)
		{
			write(STDOUT_FILENO, message, custom_mystrlen(message));
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
	if (interactive_mode)
	{
	if (custom_mystrlen(buff_lineptr) == 0)
	{
		break;
	}
	}
	tokenize_tok(buff_lineptr, args, &argc);
	if (argc > 0)
	{
		args[argc] = NULL;
		handle_me_proper(args);
		argc = 0;
	}
	}
free(buff_lineptr);
	return (0);
}
/**
 * handle_me_proper- handle user commands
 * @args : array of string having command and args
 */
void handle_me_proper(char *args[])
{
	if (custom_strcompare(args[0], "exit") == 0)
	{
		if (args[1] != NULL)
		{
			int exit_stat = mycustom_atoi(args[1]);

			exit(exit_stat);
		}
		else
		{
			exit(0);
		}
	}
	else if (custom_strcompare(args[0], "env") == 0)
	{
		print_env_list();
	}
	else
	{
		childprocess(args[0], args);
	}
}

/**
 * print_env_list - print user environment
 */

void print_env_list(void)
{
	char **env;

	for (env = environ; *env != NULL; env++)
	{
		write(STDOUT_FILENO, *env, custom_mystrlen(*env));
		write(1, "\n", 1);
	}
}

#include <string.h>
#include <unistd.h>
#include <stdio.h>
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
	/*char *command;*/
	char *message = "$ ";
	char *ctrl_d = "\n";

	while (1)
	{
	write(1, message, custom_strlen(message));
	read_getline = getline(&buff_lineptr, &len, stdin);
	if (read_getline == -1)
	{
		write(1, ctrl_d, strlen(ctrl_d));
		break;
	}
	if (buff_lineptr[read_getline - 1] == '\n')
	{
		buff_lineptr[read_getline - 1] = '\0';
	}
	tokenize(buff_lineptr, args, &argc);
	if (argc > 0)
	{
		args[argc] = NULL;
		/*childprocess(args[0], args);*/
		handle_me(args);
		/*handle_semicolon(args, &argc);*/
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
	/*else if(custom_strcmp(args[0], "setenv") == 0 || argc > 0)*/
	/*{*/
		/*setenvme(argc,args);*/
	/*}*/
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
	int i;
	const char *limit[] = {
		"USER",
		"LANG",
		"SESSION",
		"COMPIZ_CONFIG_PROFILE",
		"SHLVL",
		"HOME",
		"C_IS",
		"DESKTOP_SESSION",
		"LOGNAME",
		"TERM",
		"PATH",
		"DISPLAY",
		NULL
	};
	for (env = environ; *env != NULL; ++env)
	{
		for (i = 0; limit[i] != NULL; i++)
		{
			if (mycustom_strstr(*env, limit[i]) == *env)
			{
				write(1, *env, custom_strlen(*env));
				write(1, "\n", 1);
				break;
			}
		}
	}
}

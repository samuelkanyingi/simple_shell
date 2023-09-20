#include "listme.h"
/**
 * no_argument - function that execute command without argument
 * @command : command to be executed
 */
void no_argument(char *command)
{
	char *programname = "./shell";
	int status;
	pid_t child;
	char *args[1];
	/*if (access(command, X_OK) != 0)*/
	/*{*/
	/*write(1,"command not found", strlen("command not found"));*/
	/*}*/
	child = fork();
	if (child == 0)
	{
		args[0] = command;
		args[1] = NULL;
		if (execve(command, args, environ) == -1)
		{
			perror(programname);
			exit(1);
		}
	}
	else if (child < 0)
	{
		perror(programname);
	}
	else
	{
		waitpid(child, &status, 0);
	}
return;
}

#include "listme.h"
#include <unistd.h>
/**
 * childprocess - function to execute a child like forking
 * @command:command to be executed
 * @args:array of args to be executed
 */
void childprocess(char *command, char *args[])
{
char *programname = "./shell";
pid_t child_fork;

child_fork = fork();

if (child_fork == 0)
{
	if (execve(command, args, environ) == -1)
	{
		perror(programname);
		exit(2);
	}
}
else if (child_fork < 0)
{
	perror(programname);
}
else
{
	wait(NULL);
}
}

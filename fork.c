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
pid_t child;

/*if (access(command, X_OK) != 0)*/
/*{*/
/*write(1,"command not found", strlen("command not found"))*/
/*return;*/
/*}*/
child = fork();

if (child == 0)
{
	if (execve(command, args, environ) == -1)
	{
		perror(programname);
		exit(0);
	}
}
else if (child < 0)
{
	perror(programname);
}
else
{
	wait(NULL);
}
}

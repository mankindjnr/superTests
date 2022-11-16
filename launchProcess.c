#include "main.h"

/**
 *shell_launch - launch a program and wait for it to terminate
 *@args: arguments entered  by user
 *Return: 1 to signal to continue execution
 */
int shell_launch(char **args)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == 0)
	{
		/*child process*/
		if (execve(args[0], args, NULL) == -1)
		{
			perror("shell");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("shell"); /*error forking*/
	}
	else
	{
		/*parent process*/
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}

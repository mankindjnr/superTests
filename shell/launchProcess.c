#include "main.h"

/**
 *launch - launches the process called by the arguments
 *entered by user
 *@arguments: the arguments that launch process
 *Return: 1- signal for promp
 */
int launch(char  **arguments)
{
	pid_t pid, wpid;
	int status;

	pid = fork();

	if (pid == 0)
	{
		if (execvp(arguments[0], arguments) == -1)
		{
			perror("shell");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("shell");
	}
	else
	{
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}

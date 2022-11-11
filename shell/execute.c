#include "main.h"

/**
 *shell_execute - this function will either launch a
 *process or a builting
 *@arguments: argumnets
 *Return: the processes - execution of args
 */
int shell_execute(char **arguments)
{
	int i;

	if (args[0] == NULL)
	{
		return (1);
	}

	return (launch(arguments));
}

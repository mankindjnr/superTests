#include "main.h"

/**
 *shell - entry point for the shell project
 */
int main(int argc, char **argv)
{
	char *getline;
	char **arguments;
	int status;

	do {
		printf("$ ");
		getline = read_line();
		arguments = split_line(getline);
		status = shell_execute(arguments);

		free(getline);
		free(arguments);
	} while (status);

	return (EXIT_SUCCESS);
}

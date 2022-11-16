#include "main.h"

/**
 *shell_loop - getting input and executing it
 */
void shell_loop(void)
{
	char *line;
	char **args;
	int status;

	do {
		_putchar('$');
		_putchar(' ');
		line = read_line();
		args = split_line(line);
		status = shell_execute(args);

		free(line);
		free(args);
	} while (status);
}

#include "main.h"

/**
 *read_line - reads characters entered by the user
 *EOF - indicates the end of input
 */

char *read_line(void)
{
	int bufsize = RL_BUFSIZE;
	int position = 0, ch;
	char *buffer = malloc(sizeof(char) * bufsize);

	if (!buffer)
	{
		fprintf(stderr, "shell: allocation error\n");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		ch = getchar(); /*reads character*/

		if (ch == EOF || ch == '\n')
		{
			buffer[position] = '\n';
			return (buffer);
		}
		else
		{
			buffer[position] = ch;
		}
		position++;

		if (position >= bufsize)
		{
			bufsize += RL_BUFSIZE;
			buffer = realloc(buffer, bufsize);

			if (!buffer)
			{
				fprintf(stderr, "shell: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}

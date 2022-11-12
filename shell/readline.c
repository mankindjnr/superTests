#include "main.h"

/**
 *read_line - reads the user input char by char
 *Return: the line from input null terminated
 */
char *read_line(void)
{
#define SHELL_BUFSIZE 1024

	int bufsize = SHELL_BUFSIZE;
	int position = 0;
	char *buffer = malloc(sizeof(char) * bufsize);
	int c;

	if (!buffer)
	{
		fprintf(stderr, "shell: allocation error\n");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		c = getchar();

		if (c == EOF)
		{
			exit(EXIT_SUCCESS);
		}
		else if (c == '\n')
		{
			buffer[position] = '\0';
			return (buffer);
		}
		else
		{
			buffer[position] = c;
		}
		position++;

		if (position >= bufsize)
		{
			bufsize += SHELL_BUFSIZE;
			buffer = realloc(buffer, bufsize);

			if (!buffer)
			{
				fprintf(stderr, "shell: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}

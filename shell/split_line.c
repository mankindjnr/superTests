#include "main.h"

/**
 *split_line - will split the entered line to single argumnets
 *@getline: the line entered
 *Return: the single arguments
 */

char **split_line(char *getline)
{
	int bufsize = TOKEN_BUFSIZE, position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "shell: allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(getline, DELIMITER);

	while (token != NULL)
	{
		tokens[position] = tokens;
		position++;

		if (position >= bufsize)
		{
			bufsize += TOKEN_BUFSIZE;
			tokens = realloc(tokens, bufsize * sizeof(char *));

			if (!tokens)
			{
				fprintf(stderr, "shell: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, DELIMITER);
	}
	tokens[position] = NULL;
	return (tokens);
}

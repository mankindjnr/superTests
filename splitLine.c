#include "main.h"

#define TOKEN_BUFSIZE 64
#define DELIMITER " \t\r\n\a"

/**
 *split_line - split line into tokens
 *@line: the line to split
 *Return: a null terminated array of tokens
 */
char **split_line(char *line)
{
	int bufsize = TOKEN_BUFSIZE, position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token, **tokens_backup;

	if (!tokens)
	{
		perror("shell: allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, DELIMITER);

	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= bufsize)
		{
			bufsize += TOKEN_BUFSIZE;
			tokens_backup = tokens;
			tokens = realloc(tokens, bufsize * sizeof(char *));

			if (!tokens)
			{
				free(tokens_backup);
				perror("shell: allocatio error\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, DELIMITER);
	}
	tokens[position] = NULL;
	return (tokens);
}

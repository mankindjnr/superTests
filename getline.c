#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *buffer = NULL;
	size_t bufsize = 32;

	printf("$ ");
	getline(&buffer, &bufsize, stdin);
	printf("%s\n", buffer);

	return (0);
}

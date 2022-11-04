#include <stdio.h>
#include <string.h>

int main(int ac __attribute__((unused)), char **av)
{
	int i;

	for (i = 0; av[i] != NULL; i++)
	{
		printf("av[%d] : %s\n", i, av[i]);
	}
	return (0);
}

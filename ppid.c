#include <stdio.h>
#include <unistd.h>

int main(void)
{
	int pid;
	pid = fork();

	if (pid == 0)
	{
		printf("Parent Process id : %u\n ", getpid());
		printf("child process with parent id : %u\n", getppid());
	}
	return (0);
}

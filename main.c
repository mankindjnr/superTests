#include "main.h"

/**
 *main - entry point
 *@argc: number of argumnts entered in the command line
 *@argv: the arguments
 *Return: success
 */
int main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	shell_loop();

	return (EXIT_SUCCESS);
}

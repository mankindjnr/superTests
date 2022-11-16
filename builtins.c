#include "main.h"

/*function declarations for builtin shell commands*/
int shell_cd(char **args);
int shell_help(char **args);
int shell_exit(char **args);

/*list of builtin commands*/
char *builtin_str[] = {
	"cd",
	"help",
	"exit"
};

int (*builtin_func[]) (char **) = {
	&shell_cd,
	&shell_help,
	&shell_exit
};

/**
 *num_of_builtins - number of builtins declared
 *Return: the size of the builtins array
 */
int num_of_builtins(void)
{
	return (sizeof(builtin_str) / sizeof(char *));
}

/**
 *shell_cd - the cd function
 *@args: the argument cd
 *Return: 1 to continue executing
 */
int shell_cd(char **args)
{
	if (args[1] == NULL)
	{
		perror("shell: expected argumnent to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("shell");
		}
	}
	return (1);
}

/**
 *shell_help - the help builtin
 *@args: the argument help
 *Return: 1 to signal continuation
 */
int shell_help(char **args __attribute__((unused)))
{
	int i;
	char *placeholder;

	char *owners = "AMOS & ISAAC SHELL";
	char *builtins = "program names";

	write(STDOUT_FILENO, owners, strlen(owners));
	_putchar('\n');
        write(STDOUT_FILENO, builtins, strlen(builtins));
	_putchar('\n');

	for (i = 0; i < num_of_builtins(); i++)
	{
		placeholder = builtin_str[i];

		write(STDOUT_FILENO, placeholder, strlen(placeholder));
		_putchar('\n');
	}

	return (1);
}


/**
 *shell_exit - exit the builtin
 *@args: the argument
 *Return: 0
 */
int shell_exit(char **args __attribute__((unused)))
{
	return (0);
}


/**
 *shell_execute - execute builtin or launch program
 *@args: the arguments to launch programs
 *Return: 1 shell continue, 0 shell terminate
 */
int shell_execute(char **args)
{
	int i;

	if (args[0] == NULL)
	{
		return (1); /*an empty command was entered*/
	}

	for (i = 0; i < num_of_builtins(); i++)
	{
		if (strcmp(args[0], builtin_str[i]) == 0)
		{
			return ((*builtin_func[i])(args));
		}
	}
	return (shell_launch(args));
}

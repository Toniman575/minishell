//#include "minishell.h"
#include <stdio.h>
#include <stdlib.h> 
#include <readline/readline.h>
#include <readline/history.h>

void	exit_error(char *s)
{
	// TODO: forbidden function
	fprintf(stderr, "error: \n");
	fprintf(stderr, "%s", s);
	exit(1);
}

int	main()
{
	char *line;

	while (1)
	{
		line = readline("$ ");
		if (line == NULL)
			exit_error("readline");
		if (*line == '\0')
			continue;
		printf("Line is %s\n", line);
		add_history(line);
		free(line);
	}
}

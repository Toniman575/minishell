/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 14:05:17 by asadik            #+#    #+#             */
/*   Updated: 2026/06/29 14:29:25 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "execution/execution.h"

int	main(int argc, char **argv, char **envp)
{
	t_state	state;

	(void)argc;
	(void)argv;
	for (char **env = envp; *env; env++)
		printf("%s\n", *env);
	state.symbols = malloc(sizeof(t_symbol_lst *));
	*state.symbols = malloc(sizeof(t_symbol_lst));
	t_symbol_lst *test = *state.symbols;
	t_command blubb;
	blubb.name = malloc(sizeof(char) * 3);
	blubb.name = "ls";
	blubb.args = malloc(sizeof(char *) * 2);
	blubb.args[0] = "ls";
	blubb.args[1] = NULL;
	test->type = COMMAND;
	test->value.command = blubb;
	state.envp = envp;
	bla(&state);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 11:39:40 by asadik            #+#    #+#             */
/*   Updated: 2026/06/26 15:20:37 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../utils.h"
#include "../libft/libft.h"

void	bla(t_state *state)
{
	char			**argv;
	int				commands_n;
	t_symbol_lst	*current;

	current = *state->symbols;
	while (current->next)
		current = current->next;
	if (current->type == COMMAND)
	{
		if (ft_strncmp(current->value.command.name, "ls", 2))
		{
			execve();
		}
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 14:26:51 by asadik            #+#    #+#             */
/*   Updated: 2026/07/29 14:47:37 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "execution/hashmap.h"

typedef enum e_symbol_type
{
	COMMAND,
	REDIRECTION,
}		t_symbol_type;

typedef struct s_command
{
	char	*name;
	char	**args;
}		t_command;

typedef struct s_redirection
{
	char	*name;
}		t_redirection;

typedef union u_value
{
	t_command		command;
	t_redirection	redirection;
	char			*str;
}		t_symbol_value;

typedef struct s_symbol_lst
{
	t_symbol_type		type;
	t_symbol_value		value;
	struct s_symbol_lst	*next;
}		t_symbol_lst;

typedef struct s_state
{
	t_symbol_lst	**symbols;
	t_hashmap		envp;
}		t_state;

#endif
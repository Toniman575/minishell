/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 09:05:19 by asadik            #+#    #+#             */
/*   Updated: 2026/06/26 14:38:54 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLING_H
# define ERROR_HANDLING_H

typedef enum e_rtype
{
	ERROR,
	INT,
}	t_rtype;

typedef union u_rreturn
{
	char	*error;
	int		n;
}	t_rreturn;

typedef struct s_result
{
	t_rtype		type;
	t_rreturn	value;
}	t_result;

#endif
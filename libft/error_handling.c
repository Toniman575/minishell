/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 09:57:51 by asadik            #+#    #+#             */
/*   Updated: 2026/08/03 10:11:55 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_handling.h"

t_result	result_string(char *string)
{
	t_result	result;

	result.type = STRING;
	result.value.string = string;
	return (result);
}

t_result	result_error(char *string)
{
	t_result	result;

	result.type = ERROR;
	result.value.error = string;
	return (result);
}

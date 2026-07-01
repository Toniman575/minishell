/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 15:50:26 by asadik            #+#    #+#             */
/*   Updated: 2026/07/29 14:45:25 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHMAP_H
# define HASHMAP_H

# include "../libft/libft.h"

typedef struct s_node
{
	char		*key;
	char		*value;
}		t_node;

typedef struct s_hashmap
{
	int			bucket_n;
	int			base_hash;
	t_list		*hashmap[211];
}		t_hashmap;
#endif
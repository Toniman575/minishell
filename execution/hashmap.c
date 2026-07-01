/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 15:50:05 by asadik            #+#    #+#             */
/*   Updated: 2026/08/03 10:10:15 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"
#include "../utils.h"
#include <stdlib.h>

int	hash(char *key, t_hashmap *map)
{
	int		hash;
	t_node	new;
	int		i;
	int		index;

	i = 0;
	hash = map->base_hash;
	while (key[i])
	{
		hash = hash * 33 + key[i];
		i++;
	}
	index = hash % map->bucket_n;
	return (index);
}

t_node	*traverse(t_hashmap *map, int index,
		int (*stop)(t_node *node, void *arg), void *arg)
{
	t_list	*current;
	t_node	*node;

	current = map->hashmap[index];
	while (current)
	{
		node = current->content;
		if (stop(node, arg))
			return (node);
		current = current->next;
	}
	return (NULL);
}

static int	match_key(t_node *node, void *arg)
{
	char	*key;

	key = arg;
	return (ft_strncmp(node->key, key, ft_strlen(key) + 1) == 0);
}

t_result	map_insert(char *key, char *value, t_hashmap *envp)
{
	int			index;
	t_node		*old_node;
	t_result	old_value;
	t_node		*node;

	index = hash(key, envp);
	old_node = traverse(envp, index, match_key, key);
	if (old_node)
	{
		old_value = result_string(old_node->value);
		old_node->value = value;
		return (old_value);
	}
	node = malloc(sizeof(t_node));
	if (!node)
		return (result_error("Malloc failed allocation"));
	node->key = key;
	node->value = value;
	if (envp->hashmap[index] == NULL)
		envp->hashmap[index] = ft_lstnew(node);
	else
		ft_lstadd_back(&envp->hashmap[index], ft_lstnew(node));
	return (old_value);
}

void	hashmap_init(char **envp, t_state *state)
{
	char	**imagine;
	int		i;

	i = 0;
	state->envp.base_hash = 5381;
	state->envp.bucket_n = 211;
	while (i < state->envp.bucket_n)
	{
		state->envp.hashmap[i] = NULL;
		i++;
	}
	i = 0;
	while (envp[i])
	{
		imagine = ft_split(envp[i], '=');
		map_insert(imagine[0], imagine[1], &state->envp);
		i++;
	}
}

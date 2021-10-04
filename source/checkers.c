/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maearly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 14:34:08 by maearly           #+#    #+#             */
/*   Updated: 2021/09/27 14:34:10 by maearly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	check_overflow_splited(long l, char **splited, t_env *env, int size)
{
	int	i;

	if (l > INT_MAX || l < INT_MIN)
	{
		i = -1;
		while (++i < size)
			free(splited[i]);
		free(splited);
		freemem_error(env, "Error: Some value greater or less than int!");
	}
	return (true);
}

bool	check_overflow(long l, t_env *env)
{
	if (l > INT_MAX || l < INT_MIN)
		freemem_error(env, "Error: Some value greater or less than int!");
	return (true);
}

bool	check_args_number(int argc)
{
	if (argc < 2)
		error("Error: Wrong number of argument!");
	return (true);
}

void	check_duplicate(t_env *env)
{
	t_node	*node_a;
	t_node	*node_b;
	int		i;

	i = -1;
	node_a = env->a_head;
	while (++i < env->a_size)
	{
		node_b = node_a->next;
		while (node_a != node_b)
		{
			if (node_a->value == node_b->value)
				freemem_error(env, "Error: There are duplicates!");
			node_b = node_b->next;
		}
		node_a = node_a->next;
	}
}

bool	check_final_sorting(t_env *env)
{
	int		i;
	t_node	*head;

	head = env->a_head;
	i = -1;
	while (++i < env->a_size)
	{
		if (env->sorted[i] != env->a_head->value)
		{
			env->a_head = head;
			return (false);
		}
		env->a_head = env->a_head->next;
	}
	return (true);
}

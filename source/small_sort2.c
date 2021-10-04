/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maearly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 20:04:41 by maearly           #+#    #+#             */
/*   Updated: 2021/09/30 20:04:43 by maearly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	is_stack_sorted(t_node *head, int size)
{
	int		*array;
	int		i;

	array = malloc(sizeof(int) * size);
	i = -1;
	while (++i < size)
	{
		array[i] = head->value;
		head = head->next;
	}
	array = sort_array(array, size);
	i = -1;
	while (++i < size)
	{
		if (array[i] != head->value)
		{
			free(array);
			return (false);
		}
		head = head->next;
	}
	free(array);
	return (true);
}

int	get_mid_of_three(t_node *head, int size, int min, int max)
{
	int	mid;
	int	i;

	i = -1;
	while (++i < size)
	{
		if (head->value != min && head->value != max)
			mid = head->value;
		head = head->next;
	}
	return (mid);
}

int	get_min_of_three(t_node *head, int size)
{
	int	min;
	int	i;

	min = head->value;
	i = -1;
	while (++i < size)
	{
		if (min > head->value)
			min = head->value;
		head = head->next;
	}
	return (min);
}

int	get_max_of_three(t_node *head, int size)
{
	int	max;
	int	i;

	max = head->value;
	i = -1;
	while (++i < size)
	{
		if (max < head->value)
			max = head->value;
		head = head->next;
	}
	return (max);
}

bool	is_max(t_env *env, int max)
{
	int	i;
	int	this;

	this = env->a_head->value;
	i = -1;
	while (++i < env->a_size)
	{
		if (this < env->a_head->value)
			this = env->a_head->value;
		env->a_head = env->a_head->next;
	}
	if (this > max)
		return (false);
	return (true);
}

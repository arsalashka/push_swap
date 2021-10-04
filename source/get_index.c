/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maearly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 19:52:50 by maearly           #+#    #+#             */
/*   Updated: 2021/09/24 19:52:51 by maearly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*fill_array(int *array, t_env *env)
{
	t_env	tmp;
	int		i;

	array = malloc(sizeof(int) * (env->a_size + 1));
	if (NULL == array)
		freemem_error(env, "Error: Malloc error!");
	tmp = *env;
	i = -1;
	while (++i < tmp.a_size)
	{
		array[i] = tmp.a_head->value;
		tmp.a_head = tmp.a_head->next;
	}
	array[env->a_size] = '\0';
	return (array);
}

int	*sort_array(int *array, int size)
{
	int	i;
	int	k;
	int	tmp;

	i = 0;
	while (++i < size)
	{
		k = i;
		while (k > 0 && array[k - 1] > array[k])
		{
			tmp = array[k];
			array[k] = array[k - 1];
			array[k - 1] = tmp;
			k--;
		}
	}
	return (array);
}

int	*get_index(t_env *env)
{
	int	*array;

	array = fill_array(array, env);
	array = sort_array(array, env->a_size);
	return (array);
}

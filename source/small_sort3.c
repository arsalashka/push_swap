/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maearly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 20:35:07 by maearly           #+#    #+#             */
/*   Updated: 2021/09/30 20:35:09 by maearly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_ra_cnt_small_sort(t_env *env)
{
	int	i;

	i = 0;
	while (env->min_value != env->a_head->value)
	{
		env->a_head = env->a_head->next;
		i++;
	}
	return (i);
}

int	get_rra_cnt_small_sort(t_env *env)
{
	int	i;

	i = 0;
	while (env->min_value != env->a_head->value)
	{
		env->a_head = env->a_head->prev;
		i++;
	}
	return (i);
}

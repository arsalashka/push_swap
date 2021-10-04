/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maearly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:21:57 by maearly           #+#    #+#             */
/*   Updated: 2021/09/29 14:21:59 by maearly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_median(t_env *env, t_node *head, int size)
{
	int	mid;
	int	*array;
	int	i;

	array = malloc(sizeof(int) * size);
	if (!array)
		freemem_error(env, "Error: Malloc error!\n");
	i = -1;
	while (++i < size)
	{
		array[i] = head->value;
		head = head->next;
	}
	array = sort_array(array, size);
	mid = array[size / 2];
	free(array);
	return (mid);
}

void	pb_with_mid(t_env *env)
{
	int	mid;

	mid = get_median(env, env->a_head, env->a_size);
	while (env->a_size != 2)
	{
		if (env->a_head->value != env->min_value
			&& env->a_head->value != env->max_value)
		{
			if (env->a_head->value < mid)
				pb(env);
			else
			{
				pb(env);
				rb(env);
			}
		}
		else
			ra(env);
	}
}

int	get_ra_cnt(t_env *env, t_node *node)
{
	int	ra_cnt;
	int	i;

	i = -1;
	while (++i < env->a_size)
	{
		if (node->value < env->a_head->value
			&& node->value > env->a_head->prev->value)
			ra_cnt = i;
		env->a_head = env->a_head->next;
	}
	return (ra_cnt);
}

int	get_rra_cnt(t_env *env, t_node *node)
{
	int	rra_cnt;
	int	i;

	i = -1;
	while (++i < env->a_size)
	{
		if (node->value < env->a_head->value
			&& node->value > env->a_head->prev->value)
			rra_cnt = i;
		env->a_head = env->a_head->prev;
	}
	return (rra_cnt);
}

void	set_rate_to_node(t_env *env, t_node *node, int rb_cnt)
{
	int		rrb_cnt;
	int		ra_cnt;
	int		rra_cnt;
	int		rate;

	rrb_cnt = env->b_size - rb_cnt;
	if (rrb_cnt < rb_cnt)
		rate = rrb_cnt;
	else
		rate = rb_cnt;
	ra_cnt = get_ra_cnt(env, node);
	rra_cnt = get_rra_cnt(env, node);
	if (ra_cnt < rra_cnt)
		rate += ra_cnt;
	else
		rate += rra_cnt;
	node->rate = rate;
}

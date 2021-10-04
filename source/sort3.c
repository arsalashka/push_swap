/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maearly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 21:41:23 by maearly           #+#    #+#             */
/*   Updated: 2021/09/30 21:41:24 by maearly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa_best_node(t_env *env, t_node *best)
{
	if (best->rate == 0)
		pa(env);
	else if (env->b_head->value == best->value)
	{
		rotate_a(env, best->rate);
		pa(env);
	}
	else
	{
		rotate_b(env, best);
		rotate_a(env, best->rate);
		pa(env);
	}
}

void	last_rotate(t_env *env)
{
	t_node	*head;
	int		i;
	int		rotate_cnt;

	head = env->a_head;
	i = -1;
	while (++i < env->a_size)
	{
		if (env->min_value == env->a_head->value)
			break ;
		env->a_head = env->a_head->next;
	}
	rotate_cnt = i;
	env->a_head = head;
	if (rotate_cnt < env->a_size / 2)
	{
		while (env->min_value != env->a_head->value)
			ra(env);
	}
	else
	{
		while (env->min_value != env->a_head->value)
			rra(env);
	}
}

void	stack_sort(t_env *env)
{
	t_node	*best_node;

	if (is_stack_sorted(env->a_head, env->a_size))
		return ;
	pb_with_mid(env);
	while (env->b_size != 0)
	{
		best_node = set_rates(env);
		pa_best_node(env, best_node);
	}
	last_rotate(env);
}

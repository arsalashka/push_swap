/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maearly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 20:41:49 by maearly           #+#    #+#             */
/*   Updated: 2021/09/30 20:41:50 by maearly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*set_rates(t_env *env)
{
	t_node	*best_node;
	int		i;

	i = -1;
	while (++i < env->b_size)
	{
		set_rate_to_node(env, env->b_head, i);
		env->b_head = env->b_head->next;
	}
	best_node = env->b_head;
	i = -1;
	while (++i < env->b_size)
	{
		if (best_node->rate > env->b_head->rate)
			best_node = env->b_head;
		env->b_head = env->b_head->next;
	}
	return (best_node);
}

void	rotate_a_rra(t_env *env, t_node *a_head, int rate)
{
	int	i;

	i = -1;
	while (++i < rate)
		env->a_head = env->a_head->prev;
	if (env->b_head->value < env->a_head->value
		&& env->b_head->value > env->a_head->prev->value)
	{
		env->a_head = a_head;
		i = -1;
		while (++i < rate)
			rra(env);
	}
}

void	rotate_a(t_env *env, int rate)
{
	t_node	*a_head;
	int		i;

	if (rate == 0)
		return ;
	a_head = env->a_head;
	i = -1;
	while (++i < rate)
		env->a_head = env->a_head->next;
	if (env->b_head->value < env->a_head->value
		&& env->b_head->value > env->a_head->prev->value)
	{
		env->a_head = a_head;
		i = -1;
		while (++i < rate)
			ra(env);
		return ;
	}
	env->a_head = a_head;
	rotate_a_rra(env, a_head, rate);
}

void	rotate_b_rb_or_rrb(t_env *env, t_node *best, int rate, int i)
{
	if (rate <= i)
	{
		i = -1;
		while (++i < rate)
		{
			rb(env);
			best->rate--;
		}
		return ;
	}
	else
	{
		rate = i;
		i = -1;
		while (++i < rate)
		{
			rrb(env);
			best->rate--;
		}
	}
}

void	rotate_b(t_env *env, t_node *best)
{
	t_node	*head;
	int		i;
	int		rate;

	head = env->b_head;
	i = 0;
	while (best->value != env->b_head->value)
	{
		env->b_head = env->b_head->next;
		i++;
	}
	rate = i;
	env->b_head = head;
	i = 0;
	while (best->value != env->b_head->value)
	{
		env->b_head = env->b_head->prev;
		i++;
	}
	env->b_head = head;
	rotate_b_rb_or_rrb(env, best, rate, i);
}

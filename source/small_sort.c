/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maearly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 15:56:42 by maearly           #+#    #+#             */
/*   Updated: 2021/09/28 15:56:44 by maearly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_a_stack_of_three(t_env *env)
{
	int	min;
	int	max;
	int	mid;

	min = get_min_of_three(env->a_head, env->a_size);
	max = get_max_of_three(env->a_head, env->a_size);
	mid = get_mid_of_three(env->a_head, env->a_size, min, max);
	if (env->a_head->value == max)
		ra(env);
	if (env->a_head->value == mid)
	{
		if (env->a_head->next->value == max)
			rra(env);
		else
			sa(env);
		return ;
	}
	if (env->a_head->next->value == max)
	{
		rra(env);
		sa(env);
	}
}

void	sort_b_stack_of_three(t_env *env)
{
	int	min;
	int	max;
	int	mid;

	min = get_min_of_three(env->b_head, env->b_size);
	max = get_max_of_three(env->b_head, env->b_size);
	mid = get_mid_of_three(env->b_head, env->b_size, min, max);
	if (env->b_head->value == max)
		rb(env);
	if (env->b_head->value == mid)
	{
		if (env->b_head->next->value == max)
			rrb(env);
		else
			sb(env);
		return ;
	}
	if (env->b_head->next->value == max)
	{
		rrb(env);
		sb(env);
	}
}

void	how_many_rotations(t_env *env)
{
	int		ra_cnt;
	int		rra_cnt;
	t_node	*head;

	head = env->a_head;
	ra_cnt = get_ra_cnt_small_sort(env);
	rra_cnt = get_rra_cnt_small_sort(env);
	env->a_head = head;
	if (ra_cnt > rra_cnt)
		while (ra_cnt--)
			ra(env);
	else
		while (rra_cnt--)
			rra(env);
}

void	join_stacks(t_env *env)
{
	while (env->b_size != 0)
	{
		if (env->b_head->value < env->a_head->value)
			pa(env);
		else if (is_max(env, env->b_head->value)
			&& env->a_head->value == env->min_value)
			pa(env);
		ra(env);
	}
	if (is_stack_sorted(env->a_head, env->a_size))
		return ;
	else
		how_many_rotations(env);
}

void	small_stack_sort(t_env *env)
{
	if (is_stack_sorted(env->a_head, env->a_size))
		return ;
	if (env->a_size == 2)
	{
		sa(env);
		return ;
	}
	while (env->a_size > 3)
		pb(env);
	sort_a_stack_of_three(env);
	if (env->b_size == 2 && !is_stack_sorted(env->b_head, env->b_size))
		sb(env);
	else if (env->b_size == 3)
		sort_b_stack_of_three(env);
	join_stacks(env);
}

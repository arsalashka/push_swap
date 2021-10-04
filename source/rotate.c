/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maearly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 19:06:37 by maearly           #+#    #+#             */
/*   Updated: 2021/09/27 19:06:39 by maearly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_env *env)
{
	if (env->a_head == NULL)
		return ;
	env->a_head = env->a_head->next;
	print(env, "ra\n");
	env->instruc_cnt++;
}

void	rb(t_env *env)
{
	if (env->b_head == NULL)
		return ;
	env->b_head = env->b_head->next;
	print(env, "rb\n");
	env->instruc_cnt++;
}

void	rra(t_env *env)
{
	if (env->a_head == NULL)
		return ;
	env->a_head = env->a_head->prev;
	print(env, "rra\n");
	env->instruc_cnt++;
}

void	rrb(t_env *env)
{
	if (env->b_head == NULL)
		return ;
	env->b_head = env->b_head->prev;
	print(env, "rrb\n");
	env->instruc_cnt++;
}

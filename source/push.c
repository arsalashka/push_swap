/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maearly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 18:55:08 by maearly           #+#    #+#             */
/*   Updated: 2021/09/27 18:55:10 by maearly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_node_to_empty_stack(t_env *env, t_node *tmp)
{
	if (env->b_head == NULL)
	{
		tmp = env->a_head;
		env->a_head->prev->next = env->a_head->next;
		env->a_head->next->prev = env->a_head->prev;
		env->a_head = env->a_head->next;
		env->a_size--;
		env->b_head = tmp;
		env->b_head->next = env->b_head;
		env->b_head->prev = env->b_head;
		env->b_size++;
	}
	else if (env->a_head == NULL)
	{
		tmp = env->b_head;
		env->b_head->prev->next = env->b_head->next;
		env->b_head->next->prev = env->b_head->prev;
		env->b_head = env->b_head->next;
		env->b_size--;
		env->a_head = tmp;
		env->a_head->next = env->a_head;
		env->a_head->prev = env->a_head;
		env->a_size++;
	}
}

void	pb(t_env *env)
{
	t_node	*tmp;

	if (env->a_size == 0)
		return ;
	if (env->b_head == NULL)
		push_node_to_empty_stack(env, env->a_head);
	else
	{
		tmp = env->a_head;
		env->a_head->prev->next = env->a_head->next;
		env->a_head->next->prev = env->a_head->prev;
		env->a_head = env->a_head->next;
		env->a_size--;
		if (env->a_size == 0)
			env->a_head = NULL;
		env->b_head->prev->next = tmp;
		tmp->next = env->b_head;
		tmp->prev = env->b_head->prev;
		env->b_head->prev = tmp;
		env->b_head = tmp;
		env->b_size++;
	}
	print(env, "pb\n");
	env->instruc_cnt++;
}

void	pa(t_env *env)
{
	t_node	*tmp;
	t_node	*tail;

	if (env->b_size == 0)
		return ;
	tmp = env->b_head;
	tail = env->b_head->prev;
	tail->next = env->b_head->next;
	env->b_head = env->b_head->next;
	env->b_head->prev = tail;
	env->b_size--;
	if (env->b_size == 0)
		env->b_head = NULL;
	env->a_head->prev->next = tmp;
	tmp->prev = env->a_head->prev;
	tmp->next = env->a_head;
	env->a_head->prev = tmp;
	env->a_head = tmp;
	env->a_size++;
	print(env, "pa\n");
	env->instruc_cnt++;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maearly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 15:02:33 by maearly           #+#    #+#             */
/*   Updated: 2021/09/28 15:02:36 by maearly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_env *env)
{
	t_node	*second_node;
	t_node	*tail;

	if (env->a_head == NULL)
		freemem_error(env, "Error: A-stack is empty!\n");
	tail = env->a_head->prev;
	second_node = env->a_head->next;
	tail->next = second_node;
	second_node->prev = tail;
	second_node->next->prev = env->a_head;
	env->a_head->prev = second_node;
	env->a_head->next = second_node->next;
	second_node->next = env->a_head;
	env->a_head = second_node;
	print(env, "sa\n");
	env->instruc_cnt++;
}

void	sb(t_env *env)
{
	t_node	*second_node;
	t_node	*tail;

	if (env->b_head == NULL)
		freemem_error(env, "Error: B-stack is empty!\n");
	tail = env->b_head->prev;
	second_node = env->b_head->next;
	tail->next = second_node;
	second_node->prev = tail;
	second_node->next->prev = env->b_head;
	env->b_head->prev = second_node;
	env->b_head->next = second_node->next;
	second_node->next = env->b_head;
	env->b_head = second_node;
	print(env, "sb\n");
	env->instruc_cnt++;
}

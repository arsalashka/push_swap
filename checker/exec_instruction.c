/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maearly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 17:15:44 by maearly           #+#    #+#             */
/*   Updated: 2021/10/03 17:15:46 by maearly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	exec_1(t_env *env, char *line)
{
	if (!ft_strcmp(line, "pa"))
		pa(env);
	else if (!ft_strcmp(line, "pb"))
		pb(env);
	else if (!ft_strcmp(line, "sa"))
		sa(env);
	else if (!ft_strcmp(line, "sb"))
		sb(env);
	else if (!ft_strcmp(line, "ss"))
	{
		sa(env);
		sb(env);
	}
}

void	exec_2(t_env *env, char *line)
{
	if (!ft_strcmp(line, "ra"))
		ra(env);
	else if (!ft_strcmp(line, "rb"))
		rb(env);
	else if (!ft_strcmp(line, "rr"))
	{
		ra(env);
		rb(env);
	}
	else if (!ft_strcmp(line, "rra"))
		rra(env);
	else if (!ft_strcmp(line, "rrb"))
		rrb(env);
	else if (!ft_strcmp(line, "rrr"))
	{
		rra(env);
		rrb(env);
	}
}

void	exec_instruction(t_env *env, char *line)
{
	if (!ft_strcmp(line, "pb") || !ft_strcmp(line, "pa")
		|| !ft_strcmp(line, "sa") || !ft_strcmp(line, "sb")
		|| !ft_strcmp(line, "ss"))
		exec_1(env, line);
	else if (!ft_strcmp(line, "rr") || !ft_strcmp(line, "ra")
		|| !ft_strcmp(line, "rb") || !ft_strcmp(line, "rrb")
		|| !ft_strcmp(line, "rra") || !ft_strcmp(line, "rrr"))
		exec_2(env, line);
}

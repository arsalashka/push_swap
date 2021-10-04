/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maearly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 19:47:21 by maearly           #+#    #+#             */
/*   Updated: 2021/09/23 19:47:25 by maearly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack(t_node *head, int size)
{
	t_node	*tmp;

	head->prev->next = NULL;
	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

void	freemem_error(t_env *env, char *str)
{
	if (env->a_head)
		free_stack(env->a_head, env->a_size);
	if (env->b_head)
		free_stack(env->b_head, env->b_size);
	if (env->sorted)
		free(env->sorted);
	if (env->instruc)
		free(env->instruc);
	free(env);
	if (str)
		error(str);
}

/* mem for env->a_head not allocated yet */

void	free_mem_exit(t_env *env, char **line, int size)
{
	int	cnt;

	cnt = -1;
	while (++cnt < size)
		free(line[cnt]);
	free(line);
	freemem_error(env, "Error: Some arguments aren’t integers!");
}

bool	is_number_splited(t_env *env, char *arg, char **splited, int size)
{
	int	i;

	i = -1;
	while (arg[++i])
	{
		if (!ft_isdigit(arg[i]))
		{
			if ((arg[i] == '-') && ft_isdigit(arg[i + 1]))
				return (true);
			free_mem_exit(env, splited, size);
		}
	}
	return (true);
}

bool	is_number(t_env *env, char *arg)
{
	int	i;

	i = -1;
	while (arg[++i])
	{
		if (!ft_isdigit(arg[i]))
		{
			if ((arg[i] == '-') && ft_isdigit(arg[i + 1]))
				return (true);
			freemem_error(env, "Error: Some arguments aren’t integers!");
		}
	}
	return (true);
}

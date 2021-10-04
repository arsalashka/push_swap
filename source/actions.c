/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maearly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:15:30 by maearly           #+#    #+#             */
/*   Updated: 2021/09/27 15:15:31 by maearly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	action(t_env *env)
{
	if (env->a_head == NULL || env->a_size == 0)
		freemem_error(env, "Error: A-stack is empty!\n");
	if (env->a_size <= SMALL_STACK)
		small_stack_sort(env);
	else
		stack_sort(env);
}

bool	check_prev_instruc(t_env *env, char *str, int cnt)
{
	int	i;

	if (env->instruc != NULL)
	{
		if (env->instruc[cnt - 1] != '\n')
			return (false);
	}
	i = -1;
	while (++i < ft_strlen(str))
	{
		if (env->instruc[cnt + i] != str[i])
			return (false);
	}
	return (true);
}

void	change_last_instruc(t_env *env, char *str, int cnt)
{
	char	*new;
	int		i;

	if (!ft_strcmp(str, "ra\n") || !ft_strcmp(str, "rb\n"))
		new = "rr\n";
	else if (!ft_strcmp(str, "rra\n") || !ft_strcmp(str, "rrb\n"))
		new = "rrr\n";
	else if (!ft_strcmp(str, "sa\n") || !ft_strcmp(str, "sb\n"))
		new = "ss\n";
	i = -1;
	while (++i < ft_strlen(str))
		env->instruc[cnt + i] = new[i];
}

void	just_add_instruc(t_env *env, char *tmp, char *str)
{
	tmp = env->instruc;
	env->instruc = ft_strjoin(env->instruc, str);
	free(tmp);
}

void	print(t_env *env, char *str)
{
	int		cnt;
	char	*tmp;

	if (env->instruc == NULL)
	{
		tmp = env->instruc;
		env->instruc = ft_strjoin(env->instruc, str);
		free(tmp);
		return ;
	}
	cnt = ft_strlen(env->instruc) - ft_strlen(str);
	if (!ft_strcmp(str, "ra\n") && check_prev_instruc(env, "rb\n", cnt))
		change_last_instruc(env, str, cnt);
	else if (!ft_strcmp(str, "rb\n") && check_prev_instruc(env, "ra\n", cnt))
		change_last_instruc(env, str, cnt);
	else if (!ft_strcmp(str, "rrb\n") && check_prev_instruc(env, "rra\n", cnt))
		change_last_instruc(env, str, cnt);
	else if (!ft_strcmp(str, "rra\n") && check_prev_instruc(env, "rrb\n", cnt))
		change_last_instruc(env, str, cnt);
	else if (!ft_strcmp(str, "sa\n") && check_prev_instruc(env, "sb\n", cnt))
		change_last_instruc(env, str, cnt);
	else if (!ft_strcmp(str, "sb\n") && check_prev_instruc(env, "sa\n", cnt))
		change_last_instruc(env, str, cnt);
	else
		just_add_instruc(env, tmp, str);
}

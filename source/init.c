/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maearly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 19:53:03 by maearly           #+#    #+#             */
/*   Updated: 2021/09/23 19:53:05 by maearly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*create_node(t_env *env, int value)
{
	t_node	*node;

	node = NULL;
	node = malloc(sizeof(t_node));
	if (!node)
		freemem_error(env, "Error: Malloc error!");
	node->value = value;
	node->rate = -1;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	add_node(t_env *env, t_node *node)
{
	t_node	*tail;

	if (env->a_head == NULL)
	{
		env->a_head = node;
		env->a_head->prev = env->a_head;
		env->a_head->next = env->a_head;
		env->max_value = node->value;
		env->min_value = node->value;
	}
	else
	{
		tail = env->a_head->prev;
		tail->next = node;
		node->prev = tail;
		node->next = env->a_head;
		env->a_head->prev = node;
		if (env->max_value < node->value)
			env->max_value = node->value;
		if (env->min_value > node->value)
			env->min_value = node->value;
	}
	env->a_size++;
}

void	parse_string(t_env *env, char *str)
{
	char	**splited;
	int		i;
	long	tmp;
	int		cnt;

	splited = ft_split(str, ' ');
	if (splited == NULL)
		freemem_error(env, "Error: Malloc error\n");
	cnt = 0;
	while (splited[cnt] != NULL)
		cnt++;
	i = -1;
	while (splited[++i])
	{
		is_number_splited(env, splited[i], splited, cnt);
		tmp = ft_atol(splited[i]);
		check_overflow_splited(tmp, splited, env, cnt);
		add_node(env, create_node(env, (int)tmp));
	}
	i = -1;
	while (++i < env->a_size)
		free(splited[i]);
	free(splited);
	if (env->a_size < 1)
		freemem_error(env, "Error: Size of stack less than 1!\n");
}

void	parse_argv(t_env *env, int argc, char **argv)
{
	int		i;
	long	tmp;
	t_node	*new;

	i = 0;
	while (++i < argc)
	{
		is_number(env, argv[i]);
		tmp = ft_atol(argv[i]);
		check_overflow(tmp, env);
		new = create_node(env, (int)tmp);
		add_node(env, new);
	}
}

t_env	*init(int argc, char **argv)
{
	t_env	*env;

	check_args_number(argc);
	env = malloc(sizeof(t_env));
	if (!env)
		error("Error: Malloc error!");
	env->a_head = NULL;
	env->b_head = NULL;
	env->a_size = 0;
	env->b_size = 0;
	env->sorted = NULL;
	env->instruc_cnt = 0;
	env->instruc = NULL;
	if (argc == 2)
		parse_string(env, argv[1]);
	else
		parse_argv(env, argc, argv);
	check_duplicate(env);
	env->sorted = get_index(env);
	return (env);
}

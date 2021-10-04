/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maearly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 18:23:28 by maearly           #+#    #+#             */
/*   Updated: 2021/09/22 18:23:30 by maearly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error(char *str)
{
	write(2, RED, ft_strlen(RED));
	ft_putendl_fd(str, 2);
	write(2, RESET, ft_strlen(RESET));
	exit(1);
}

int	main(int argc, char **argv)
{
	t_env	*env;

	env = init(argc, argv);
	action(env);
	write(1, env->instruc, ft_strlen(env->instruc));
	freemem_error(env, NULL);
	return (0);
}

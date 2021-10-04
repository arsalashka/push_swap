/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maearly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 18:26:56 by maearly           #+#    #+#             */
/*   Updated: 2021/10/02 18:26:58 by maearly          ###   ########.fr       */
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

bool	check_line(char *line)
{
	if (!ft_strcmp(line, "pb") || (!ft_strcmp(line, "pa"))
		|| (!ft_strcmp(line, "sa")) || (!ft_strcmp(line, "sb"))
		|| (!ft_strcmp(line, "ss")) || (!ft_strcmp(line, "rr"))
		|| (!ft_strcmp(line, "ra")) || (!ft_strcmp(line, "rb"))
		|| (!ft_strcmp(line, "rrb")) || (!ft_strcmp(line, "rra"))
		|| (!ft_strcmp(line, "rrr")))
		return (true);
	return (false);
}

void	final_sorting(t_env *env)
{
	if (check_final_sorting(env))
		write(1, "OK\n", ft_strlen("OK\n"));
	else
		write(1, "KO\n", ft_strlen("KO\n"));
}

int	main(int argc, char **argv)
{
	t_env	*env;
	char	*line;
	int		gnl;

	env = init(argc, argv);
	gnl = -1;
	while (gnl != 0)
	{
		gnl = get_next_line(STDIN_FILENO, &line);
		if (gnl == 1 && check_line(line))
			exec_instruction(env, line);
		else if (!ft_strcmp(line, ""))
			gnl = 0;
		else
			freemem_error(env, "Error: Wrong instruction!\n");
		if (gnl == -1)
			freemem_error(env, "Error: Wrong instruction!\n");
		if (line != NULL)
			free(line);
	}
	final_sorting(env);
	freemem_error(env, NULL);
	return (0);
}

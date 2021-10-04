/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maearly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:53:27 by maearly           #+#    #+#             */
/*   Updated: 2021/09/23 16:53:33 by maearly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "libft.h"

# define RED "\033[0;31m"
# define WHITE "\033[1;97m"
# define BLUE "\033[1;94m"
# define PURPLE "\033[1;35m"
# define CYAN "\033[1;36m"
# define YELLOW "\033[1;33m"
# define RESET "\033[0m"
# define SMALL_STACK 6
# define BUFFER_SIZE 3

typedef struct s_node
{
	int				value;
	int				rate;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_env
{
	t_node	*a_head;
	t_node	*b_head;
	int		max_value;
	int		min_value;
	int		a_size;
	int		b_size;
	int		*sorted;
	int		instruc_cnt;
	char	*instruc;
}	t_env;

bool	check_overflow_splited(long l, char **splited, t_env *env, int size);
bool	check_overflow(long l, t_env *env);
void	freemem_error(t_env *env, char *str);
void	error(char *str);
t_env	*init(int argc, char **argv);
bool	is_number_splited(t_env *env, char *arg, char **splited, int size);
bool	is_number(t_env *env, char *arg);
bool	check_args_number(int argc);
void	check_duplicate(t_env *stack);
int		*get_index(t_env *stack);
int		*sort_array(int *array, int size);
void	action(t_env *env);
void	pa(t_env *env);
void	pb(t_env *env);
void	ra(t_env *env);
void	rb(t_env *env);
void	rra(t_env *env);
void	rrb(t_env *env);
void	sa(t_env *env);
void	sb(t_env *env);
void	small_stack_sort(t_env *env);
void	stack_sort(t_env *env);
bool	check_final_sorting(t_env *env);
bool	is_stack_sorted(t_node *head, int size);
void	sort_a_stack_of_three(t_env *env);
void	sort_b_stack_of_three(t_env *env);
int		get_mid_of_three(t_node *head, int size, int min, int max);
int		get_min_of_three(t_node *head, int size);
int		get_max_of_three(t_node *head, int size);
bool	is_max(t_env *env, int max);
int		get_ra_cnt_small_sort(t_env *env);
int		get_rra_cnt_small_sort(t_env *env);
void	pb_with_mid(t_env *env);
void	set_rate_to_node(t_env *env, t_node *node, int rb_cnt);
t_node	*set_rates(t_env *env);
void	rotate_a(t_env *env, int rate);
void	rotate_b(t_env *env, t_node *best);
void	print(t_env *env, char *str);
int		get_next_line(int fd, char **line);
void	exec_instruction(t_env *env, char *line);

#endif

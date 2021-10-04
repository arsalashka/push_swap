/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maearly <maearly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 13:32:19 by maearly           #+#    #+#             */
/*   Updated: 2021/01/21 17:52:56 by maearly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*ft_remainder(char *stat, char **line, int *flag)
{
	char	*remainder;
	char	*ptr;

	remainder = NULL;
	if (stat)
	{
		ptr = ft_strchr(stat, '\n');
		if (ptr)
		{
			*ptr = '\0';
			*flag = 1;
			remainder = ft_strdup(++ptr);
		}
	}
	*line = ft_strdup(stat);
	free(stat);
	return (remainder);
}

char	*ft_lets_read(int fd, char *stat)
{
	char	buf[BUFFER_SIZE + 1];
	int		bytes;
	char	*tmp;

	bytes = 1;
	while (bytes)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		buf[bytes] = '\0';
		tmp = stat;
		stat = ft_strjoin(stat, buf);
		free(tmp);
		if (ft_strchr(stat, '\n'))
			break ;
	}
	return (stat);
}

int	get_next_line(int fd, char **line)
{
	static char	*stat;
	int			flag;

	flag = 0;
	if (!line || BUFFER_SIZE <= 0 || fd < 0 || read(fd, stat, 0))
		return (-1);
	if (!stat)
		stat = ft_strdup("");
	if (stat && ft_strchr(stat, '\n'))
	{
		stat = ft_remainder(stat, line, &flag);
		return (flag);
	}
	stat = ft_lets_read(fd, stat);
	stat = ft_remainder(stat, line, &flag);
	return (flag);
}

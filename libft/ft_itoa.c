/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maearly <maearly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 13:24:28 by maearly           #+#    #+#             */
/*   Updated: 2020/10/30 19:29:43 by maearly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_getsize(unsigned int n)
{
	int	res;

	res = 1;
	while (n >= 10)
	{
		n /= 10;
		++res;
	}
	return (res);
}

char		*ft_itoa(int n)
{
	unsigned int	value;
	unsigned int	size;
	char			*str;

	if (n < 0)
		value = (unsigned int)(n * -1);
	else
		value = (unsigned int)n;
	size = ft_getsize(value);
	str = (char *)malloc(sizeof(char) * (n < 0 ? (size += 2) : (++size)));
	if (NULL == str)
		return (NULL);
	str[--size] = '\0';
	(n < 0) ? (str[0] = '-') : 0;
	while (value >= 10)
	{
		str[--size] = value % 10 + '0';
		value /= 10;
	}
	str[--size] = value % 10 + '0';
	return (str);
}

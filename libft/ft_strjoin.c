/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maearly <maearly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 13:24:28 by maearly           #+#    #+#             */
/*   Updated: 2021/01/22 14:57:42 by maearly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	if ((!s1 && !s2) || !(str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	*str = '\0';
	i = -1;
	while (s1[++i] && s1)
		str[i] = s1[i];
	j = -1;
	while (s2[++j] && s2)
		str[i + j] = s2[j];
	str[i + j] = '\0';
	return (str);
}

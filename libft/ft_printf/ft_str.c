/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:39:01 by francoma          #+#    #+#             */
/*   Updated: 2023/02/24 07:15:06 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"
#include <unistd.h>
#include <stdlib.h>

int	nth_in_str(char c, char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	in_str(char c, char *str)
{
	return (nth_in_str(c, str) != -1);
}

int	ft_isupper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int	putstrn(char *s, int n)
{
	return (write(1, s, n));
}

int	putpadn(char pad, int n)
{
	char	*str;
	int		i;
	int		res;

	str = malloc(sizeof(str) * n);
	if (!str)
		return (-1);
	i = 0;
	while (i < n)
		str[i++] = pad;
	res = write(1, str, n);
	free(str);
	return (res);
}

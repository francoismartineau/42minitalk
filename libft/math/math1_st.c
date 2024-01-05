/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math1_st.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 07:56:24 by francoma          #+#    #+#             */
/*   Updated: 2023/02/09 08:00:03 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 08:32:02 by francoma          #+#    #+#             */
/*   Updated: 2023/02/09 07:55:22 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_abs_st(int n)
{
	if (n < 0)
		return (-(size_t)n);
	return (n);
}

size_t	ft_min_st(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

size_t	ft_max_st(size_t a, size_t b)
{
	if (a > b)
		return (a);
	return (b);
}

size_t	ft_pow_st(size_t n, size_t pow)
{
	size_t	res;
	size_t	i;

	res = 1;
	i = 0;
	while (i < pow)
	{
		res *= n;
		i++;
	}
	return (res);
}

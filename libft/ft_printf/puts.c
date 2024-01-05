/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:44:39 by francoma          #+#    #+#             */
/*   Updated: 2023/02/24 09:53:42 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ftprintf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	return (write(1, s, ft_strlen(s)));
}

int	put_sign(t_aconsumer *ac)
{
	int	res;

	res = 0;
	if (!is_signed_int(ac->type))
		return (res);
	if (ac->is_negative_number)
		res = ft_putchar('-');
	else if (ac->flags[f_plus])
		res = ft_putchar('+');
	else if (ac->flags[f_space])
		res = ft_putchar(' ');
	return (res);
}

int	put_hex_prefix(t_aconsumer *ac, size_t n)
{
	char	*prefix;
	int		res;

	res = 0;
	if (((is_hex(ac->type) || is_bin(ac->type)) && ac->flags[f_hash])
		|| (ac->type == 'p' && n != 0))
	{
		prefix = malloc(sizeof(*prefix) * 2);
		if (!prefix)
			return (-1);
		prefix[0] = '0';
		if (ac->type == 'p')
			prefix[1] = 'x';
		else
			prefix[1] = ac->type;
		res = write(1, prefix, 2);
	}
	return (res);
}

int	put_numbern(size_t n, int num_n, size_t base, char type)
{
	char	*digits;
	char	dgt;
	int		i;
	int		dgt_count;
	int		err;

	err = 0;
	dgt_count = count_digits(n, base);
	i = num_n;
	while (--i >= dgt_count && err != -1)
		err = ft_putchar('0');
	digits = DIGITS;
	while (i >= 0 && err != -1)
	{
		dgt = digits[n / ft_pow_st(base, i) % base];
		if (ft_isupper(type))
			dgt = ft_toupper(dgt);
		err = ft_putchar(dgt);
		i--;
	}
	if (err == -1)
		return (-1);
	return (num_n);
}

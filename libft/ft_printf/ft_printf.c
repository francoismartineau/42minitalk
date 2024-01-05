/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 08:51:20 by francoma          #+#    #+#             */
/*   Updated: 2023/02/24 09:53:30 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ftprintf.h"
#include <unistd.h>

static int	is_aconsumer(char const *format)
{
	return (*format == '%' && *(format + 1));
}

static int	consume_a(t_aconsumer *ac, va_list ap)
{
	int	count;

	if (ac->type == 'c')
		count = display_char(ac, va_arg(ap, int));
	else if (ac->type == 's')
		count = display_str(ac, va_arg(ap, char *));
	else if (ac->type == 'p')
		count = display_ptr(ac, va_arg(ap, size_t));
	else if (is_signed_int(ac->type))
		count = display_number(ac, va_arg(ap, int));
	else if (is_unsigned_int(ac->type))
		count = display_u_number(ac, va_arg(ap, unsigned int));
	else if (ac->type == '%')
		count = display_percent(ac);
	else
		count = 0;
	return (count);
}

static int	reg_str_len(char const *str)
{
	int	len;

	len = 0;
	while (str[len] && !is_aconsumer(str + len))
		len++;
	return (len);
}

static int	_ft_printf(const char *format, va_list ap)
{
	t_aconsumer	ac;
	int			count;
	int			temp_count;

	count = 0;
	temp_count = 0;
	while (*format)
	{
		if (is_aconsumer(format))
		{
			format += parse_aconsumer(format, &ac);
			temp_count = consume_a(&ac, ap);
		}
		else
		{
			temp_count = write(1, format, reg_str_len(format));
			format += temp_count;
		}
		if (temp_count == -1)
			return (-1);
		count += temp_count;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			count;

	if (!format)
		return (0);
	va_start(ap, format);
	count = _ft_printf(format, ap);
	va_end(ap);
	return (count);
}

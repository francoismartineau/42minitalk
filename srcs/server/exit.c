/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 09:54:31 by francoma          #+#    #+#             */
/*   Updated: 2023/02/23 16:42:27 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "libft.h"

void	exit_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	remove_msg();
	exit(EXIT_FAILURE);
}

void	exit_success(char *msg)
{
	ft_putstr_fd(msg, 1);
	remove_msg();
	exit(EXIT_SUCCESS);
}

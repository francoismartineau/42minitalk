/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 08:01:46 by francoma          #+#    #+#             */
/*   Updated: 2023/02/23 14:53:07 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "server.h"

static void	display_pid(void)
{
	ft_printf("PID: %i\n", getpid());
}

int	main(void)
{
	display_pid();
	init_sigactions();
	while (1)
		;
}

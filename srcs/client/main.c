/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 09:53:07 by francoma          #+#    #+#             */
/*   Updated: 2023/02/23 16:47:19 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static pid_t	check_server_pid(char const *arg)
{
	pid_t	*server_pid;

	server_pid = get_server_pid();
	*server_pid = ft_atoi(arg);
	if (kill(*server_pid, 0) == -1)
		return (FAILURE);
	return (SUCCESS);
}

char	**get_msg(void)
{
	static char	*msg = NULL;

	return (&msg);
}

static void	set_msg(char *msg)
{
	*(get_msg()) = msg;
}

static void	send_msg(void)
{
	handler(SERVER_READY, NULL, NULL);
}

int	main(int argc, char *argv[])
{
	if (argc != 3)
		exit_error(ARG_COUNT_ERROR_MSG);
	if (check_server_pid(argv[1]) == FAILURE)
		exit_error(WRONG_PID_ERROR_MSG);
	set_msg(argv[2]);
	init_sigactions();
	send_msg();
	while (1)
		;
	return (0);
}

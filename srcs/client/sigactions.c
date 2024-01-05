/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigactions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 05:03:39 by francoma          #+#    #+#             */
/*   Updated: 2023/03/02 15:48:55 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void	send_bit(pid_t server_pid, char *msg, int i)
{
	int	signo;

	if ((msg)[i / 8] & (1 << i % 8))
		signo = BIT_1;
	else
		signo = BIT_0;
	if (kill(server_pid, signo) == FAILURE)
		exit_error(SERVER_FAILURE_MSG);
}

void	handler(int signo, siginfo_t *info, void *context)
{
	pid_t			server_pid;
	char			*msg;
	static int		i = 0;

	(void) signo;
	(void) context;
	(void) info;
	server_pid = *(get_server_pid());
	if (signo == MSG_RECEIVED)
	{
		ft_printf(SERVER_SUCCESS_MSG);
		exit(EXIT_SUCCESS);
	}
	else if (signo == SERVER_READY)
	{
		msg = *(get_msg());
		if (!(i / 8) || msg[(i / 8) - 1])
			send_bit(server_pid, msg, i++);
		else
			send_bit(server_pid, "\0", 0);
	}
}

void	init_sigactions(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SERVER_READY);
	sigaddset(&sa.sa_mask, MSG_RECEIVED);
	sa.sa_flags = SIGACTION_FLAGS;
	if (sigaction(SERVER_READY, &sa, NULL) == FAILURE)
		exit_error(SIG_INIT_ERROR_MSG);
	if (sigaction(MSG_RECEIVED, &sa, NULL) == FAILURE)
		exit_error(SIG_INIT_ERROR_MSG);
}

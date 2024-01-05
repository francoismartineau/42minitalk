/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigactions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:48:09 by francoma          #+#    #+#             */
/*   Updated: 2023/03/02 15:53:13 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void	receive_bit(int signo, siginfo_t *info, void *context)
{
	static pid_t	prev_pid = 0;

	(void) signo;
	(void) context;
	if (!info->si_pid)
		info->si_pid = prev_pid;
	else if (info->si_pid != prev_pid)
		remove_msg();
	prev_pid = info->si_pid;
	write_to_msg(info->si_pid, signo == BIT_1);
}

void	init_sigactions(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, BIT_0);
	sigaddset(&sa.sa_mask, BIT_1);
	sa.sa_flags = SIGACTION_FLAGS;
	sa.sa_sigaction = receive_bit;
	if (sigaction(BIT_0, &sa, NULL) == FAILURE)
		exit_error(SIG_INIT_ERROR_MSG);
	if (sigaction(BIT_1, &sa, NULL) == FAILURE)
		exit_error(SIG_INIT_ERROR_MSG);
}

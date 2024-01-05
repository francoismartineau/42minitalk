/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 10:05:41 by francoma          #+#    #+#             */
/*   Updated: 2023/02/23 16:48:44 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>	// EXIT_SUCCESS
# include "common.h"
# include "libft.h"

# define ARG_COUNT_ERROR_MSG "Two arguments are required:\n\
\t1. The PID of the server\n\
\t2. The message to send\n"
# define WRONG_PID_ERROR_MSG "Invalid PID provided\n"
# define SERVER_SUCCESS_MSG "The server has succesfully received the message.\n"
# define SERVER_FAILURE_MSG "The server has encountered a problem.\n"
# define SERVER_TIMEOUT 3

pid_t	*get_server_pid(void);
char	**get_msg(void);
void	handler(int signo, siginfo_t *info, void *context);

#endif
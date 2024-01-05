/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:31:54 by francoma          #+#    #+#             */
/*   Updated: 2023/02/23 16:48:41 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# define SIG_INIT_ERROR_MSG "The server encountered a problem while \
initializing signal reception.\n"

# define BIT_0 SIGUSR2
# define BIT_1 SIGUSR1

# define SERVER_READY SIGUSR1
# define MSG_RECEIVED SIGUSR2

# define FAILURE -1
# define SUCCESS 0

# define USLEEP_DELAY 10

# define SIGACTION_FLAGS SA_SIGINFO

void	init_sigactions(void);
void	exit_error(char *msg);
void	exit_success(char *msg);

#endif
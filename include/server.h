/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:39:32 by francoma          #+#    #+#             */
/*   Updated: 2023/02/23 16:45:27 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <unistd.h>	// getpid, pause
# include <signal.h>
# include <stdlib.h>	// free
# include "libft.h"
# include "common.h"

# define BUFFER_SIZE 16
# define INIT_CLIENT_ERROR_MSG "Encountered a problem while initializing \
a client message.\n\
Exiting now.\n"
# define EXPAND_CLIENT_ERROR_MSG "Encountered a problem while expanding \
client message capacity.\n\
Exiting now.\n"
# define STOP_SERVER_REQUEST_MSG "A client has requested to stop the server.\n"
# define STOP_SERVER_REQUEST "quit"

typedef struct s_msg
{
	int		bit_index;
	char	*msg;
	int		capacity;
}	t_msg;

t_msg			**get_msg(void);
void			write_to_msg(int client_pid, int bit);

void			remove_msg(void);
void			handle_complete_msg(int client_pid, char *msg);

#endif
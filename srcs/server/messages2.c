/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:22:16 by francoma          #+#    #+#             */
/*   Updated: 2023/02/23 16:44:30 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	remove_msg(void)
{
	t_msg	**msg;

	msg = get_msg();
	if (!*msg)
		return ;
	free((*msg)->msg);
	free(*msg);
	*msg = NULL;
}

static int	is_stop_server_request(char *msg)
{
	return (ft_strcmp(msg, STOP_SERVER_REQUEST) == 0);
}

void	handle_complete_msg(int client_pid, char *msg)
{
	kill(client_pid, MSG_RECEIVED);
	if (is_stop_server_request(msg))
		exit_success(STOP_SERVER_REQUEST_MSG);
	ft_printf("Client %5i says: \n%s\n", client_pid, msg);
	remove_msg();
}

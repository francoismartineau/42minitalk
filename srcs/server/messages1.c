/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:19:28 by francoma          #+#    #+#             */
/*   Updated: 2023/02/24 11:12:54 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "common.h"

static t_msg	*new_msg(void)
{
	t_msg	*msg;

	msg = ft_calloc(1, sizeof(*msg));
	if (!msg)
		return (NULL);
	msg->msg = ft_calloc(BUFFER_SIZE, sizeof(*msg->msg));
	if (!msg->msg)
	{
		free(msg);
		return (NULL);
	}
	msg->capacity = BUFFER_SIZE;
	return (msg);
}

t_msg	**get_msg(void)
{
	static t_msg	*msg = NULL;

	if (!msg)
		msg = new_msg();
	return (&msg);
}

static int	expand_msg(t_msg *msg)
{
	char	*str;

	str = ft_calloc(msg->capacity * 2, sizeof(*str));
	if (!str)
		return (FAILURE);
	ft_memmove(str, msg->msg, msg->capacity);
	msg->capacity *= 2;
	free(msg->msg);
	msg->msg = str;
	return (SUCCESS);
}

static int	msg_terminated(char *msg, int index, int bit_index)
{
	return (msg[index] == '\0'
		&& bit_index % 8 == 0
		&& bit_index != 0);
}

void	write_to_msg(int client_pid, int bit)
{
	t_msg	*msg;
	int		index;

	msg = *(get_msg());
	if (!msg)
		exit_error(INIT_CLIENT_ERROR_MSG);
	index = msg->bit_index / 8;
	if (index >= msg->capacity
		&& expand_msg(msg) == FAILURE)
		exit_error(EXPAND_CLIENT_ERROR_MSG);
	msg->msg[index] |= bit << (msg->bit_index++ % 8);
	if (msg_terminated(msg->msg, index, msg->bit_index))
		handle_complete_msg(client_pid, msg->msg);
	else
		kill(client_pid, SERVER_READY);
}

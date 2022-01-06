/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 20:37:24 by seomoon           #+#    #+#             */
/*   Updated: 2021/06/24 16:39:11 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void		exit_error(char *message)
{
	write(STDOUT_FILENO, message, ft_strlen(message));
	write(STDOUT_FILENO, "\n", 1);
	exit(1);
}

void		send_char(int pid, char byte)
{
	int		i;
	int		result;

	i = 0b10000000;
	while (i)
	{
		if (i & byte)
			result = kill(pid, SIGUSR1);
		else
			result = kill(pid, SIGUSR2);
		if (result == -1)
			exit_error("Error: wrong PID");
		i >>= 1;
		usleep(100);
	}
}

void		send_message(char *str_pid, char *message)
{
	int		pid;

	pid = ft_atoi(str_pid);
	while (*message)
	{
		send_char(pid, *message);
		message++;
	}
	send_char(pid, *message);
}

int			main(int argc, char **argv)
{
	if (argc != 3)
		exit_error("Usage: ./client [server_pid] [msg_to_send]");
	send_message(argv[1], argv[2]);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 20:37:17 by seomoon           #+#    #+#             */
/*   Updated: 2021/06/24 16:38:20 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void		print_pid(void)
{
	pid_t	pid;

	pid = getpid();
	write(STDOUT_FILENO, "Server PID: ", 12);
	write(STDOUT_FILENO, ft_itoa(pid), ft_strlen(ft_itoa(pid)));
	write(STDOUT_FILENO, "\n", 1);
}

void		receive_bit(int signum)
{
	static int	character;
	static int	bit;

	if (signum == SIGUSR1)
		character += (1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		if (character == '\0')
			write(STDOUT_FILENO, "\n", 1);
		else
			write(STDOUT_FILENO, &character, 1);
		bit = 0;
		character = 0;
	}
}

int			main(void)
{
	print_pid();
	signal(SIGUSR1, receive_bit);
	signal(SIGUSR2, receive_bit);
	while (1)
		pause();
}

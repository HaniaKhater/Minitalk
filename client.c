/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhater <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 01:29:22 by hkhater           #+#    #+#             */
/*   Updated: 2022/05/20 02:04:41 by hkhater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_sig(int pid, char c)
{
	int	bit;

	bit = 8;
	while (bit--)
	{
		if ((c >> bit & 1) == 0)
			kill(pid, SIGUSR1);
		else if ((c >> bit & 1) == 1)
			kill(pid, SIGUSR2);
		usleep(200);
	}
}

void	ft_transmit(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_send_sig(pid, str[i]);
		i++;
	}
	ft_send_sig(pid, '\0');
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid <= 0)
			error_msg_pid();
		ft_transmit(pid, av[2]);
	}
	else
		error_msg_arg();
	return (0);
}

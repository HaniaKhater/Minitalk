/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhater <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 01:29:48 by hkhater           #+#    #+#             */
/*   Updated: 2022/05/12 23:19:13 by hkhater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void	assemble_char(int sig)
{
	static int	c;
	static int	i;

	i++;
	c = c << 1;
	if (sig == SIGUSR2)
		c++;
	if (i == 8)
	{
		ft_putchar(c);
		i = 0;
		c = 0x0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	if (pid > 100)
	{
		ft_putnbr(pid);
		ft_putchar('\n');
		while (1)
		{
			signal(SIGUSR1, assemble_char);
			signal(SIGUSR2, assemble_char);
			pause();
		}
	}
	else
		error_msg_pid();
	return (0);
}

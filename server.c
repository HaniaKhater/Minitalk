/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhater <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 01:29:48 by hkhater           #+#    #+#             */
/*   Updated: 2022/05/20 02:08:07 by hkhater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

char	*g_str;

void	print_free(void)
{
	ft_putstr(g_str);
	free(g_str);
	g_str = NULL;
}

char	*ft_addchar(char *s1, char c)
{
	char		*s2;
	int			i;

	i = 0;
	if (!s1)
		return (0);
	s2 = malloc(sizeof(char) * (ft_strlen(s1) + 2));
	if (!s2)
		return (0);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = c;
	i++;
	s2[i] = '\0';
	free(s1);
	return (s2);
}

void	assemble_str(char c)
{
	if (c == '\0')
	{
		print_free();
		return ;
	}
	if (g_str == 0)
	{
		g_str[0] = c;
		g_str[1] = '\0';
		return ;
	}
	g_str = ft_addchar(g_str, c);
}

void	assemble_char(int sig)
{
	static int	c;
	static int	b;

	b++;
	c = c << 1;
	if (sig == SIGUSR2)
		c++;
	if (b == 8)
	{
		assemble_str(c);
		b = 0;
		c = 0x0;
	}
}

int	main(void)
{
	int	pid;

	g_str = malloc(sizeof(char) * 1);
	g_str[0] = '\0';
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

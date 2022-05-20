/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhater <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 01:29:48 by hkhater           #+#    #+#             */
/*   Updated: 2022/05/20 04:48:15 by hkhater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*g_str;

void	print_free(void)
{
	ft_putstr(g_str);
	free(g_str);
	g_str = NULL;
}

void	ft_addchar(char c)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strdup(g_str);
	free(g_str);
	g_str = malloc(sizeof(char) * (ft_strlen(tmp) + 2));
	while (tmp[i])
	{
		g_str[i] = tmp[i];
		i++;
	}
	g_str[i] = c;
	i++;
	g_str[i] = '\0';
	free(tmp);
}

void	assemble_str(char c)
{
	if (c == '\0')
	{
		print_free();
		return ;
	}
	if (g_str == NULL)
	{
		malloc(sizeof(char) * 2);
		g_str[0] = c;
		g_str[1] = '\0';
		return ;
	}
	ft_addchar(c);
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

	pid = getpid();
	g_str = NULL;
	if (pid > 100)
	{
		ft_putnbr(pid);
		ft_putchar('\n');
		g_str = malloc(sizeof(char) * 1);
		g_str[0] = '\0';
		signal(SIGUSR1, assemble_char);
		signal(SIGUSR2, assemble_char);
		while (1)
			pause();
	}
	else
		error_msg_pid();
	return (0);
}

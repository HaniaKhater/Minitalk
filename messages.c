/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhater <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 01:30:04 by hkhater           #+#    #+#             */
/*   Updated: 2022/05/20 00:17:00 by hkhater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	len;

	len = ft_strlen(s);
	if (s)
		write(1, s, len);
}

void	error_msg_pid(void)
{
	ft_putstr("**************************\n");
	ft_putstr("******** PID ERROR *******\n");
	ft_putstr("**************************\n");
}

void	error_msg_arg(void)
{
	ft_putstr("**************************\n");
	ft_putstr("**** INVALID ARGUMENT ****\n");
	ft_putstr("**************************\n");
	ft_putstr("** Correct format: *******\n");
	ft_putstr("** ./client [PID] [MSG] **\n");
	ft_putstr("**************************\n");
}

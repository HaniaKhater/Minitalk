/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhater <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 01:30:04 by hkhater           #+#    #+#             */
/*   Updated: 2022/04/23 01:30:12 by hkhater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minitalk.h"

void	error_msg_pid(void)
{
	ft_printf("**************************\n");
	ft_printf("******** PID ERROR *******\n");
	ft_printf("**************************\n");
}

void	error_msg_arg(void)
{
	ft_printf("**************************\n");
	ft_printf("**** INVALID ARGUMENT ****\n");
	ft_printf("**************************\n");
	ft_printf("** Correct format: *******\n");
	ft_printf("** ./client [PID] [MSG] **\n");
	ft_printf("**************************\n");
}

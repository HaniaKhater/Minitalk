/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhater <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 01:30:27 by hkhater           #+#    #+#             */
/*   Updated: 2022/04/23 01:40:24 by hkhater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include <signal.h>
#include <unistd.h>
#include "../libft/inc/libft.h"
#include "../libft/inc/ft_printf.h"

void	error_msg_pid(void);
void	error_msg_arg(void);
int     ft_atoi(const char *str);
void    ft_putstr_fd(char *s, int fd);

#endif

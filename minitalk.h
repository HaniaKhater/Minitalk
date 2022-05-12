/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhater <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 01:30:27 by hkhater           #+#    #+#             */
/*   Updated: 2022/05/12 23:21:21 by hkhater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>

void	error_msg_pid(void);
void	error_msg_arg(void);
int		ft_atoi(const char *str);
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putnbr(int nb);
#endif

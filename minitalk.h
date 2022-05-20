/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhater <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 01:30:27 by hkhater           #+#    #+#             */
/*   Updated: 2022/05/20 01:44:30 by hkhater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

void	error_msg_pid(void);
void	error_msg_arg(void);
int		ft_atoi(const char *str);
void	ft_putchar(char c);
int		ft_strlen(char *s);
void	ft_putstr(char *s);
char	*ft_strjoin(char const *s1, char *s2);
char	*ft_addchar(char *s1, char c);
void	ft_putnbr(int nb);
#endif

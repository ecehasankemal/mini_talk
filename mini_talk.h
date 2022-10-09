/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_talk.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece  <hece@student.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 22:10:30 by hece              #+#    #+#             */
/*   Updated: 2022/10/09 22:10:32 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_TALK_H
# define MINI_TALK_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
int		ft_pow(int nb, int power);
void	ft_putnbr_fd(int nb, int fd);
int		ft_atoi(const char *str);
void	interpret(int signal);
void	send_signal(int *binary, int pid);
int		*convert_binary(unsigned char c);

#endif

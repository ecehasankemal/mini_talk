/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece  <hece@student.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 22:08:49 by hece              #+#    #+#             */
/*   Updated: 2022/10/09 22:08:50 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

// interpret fonksiyonu sinyalı byte olarak okur 8 bit oldugunda yani
// 1 byte olduğunda yazdırır ...

void	interpret(int signal)
{
	static int	iter;
	static int	chr;

	if (signal == SIGUSR1)
		iter++;
	else if (signal == SIGUSR2)
	{
		chr += ft_pow(2, iter);
		iter++;
	}
	if (iter == 8)
	{
		ft_putchar_fd(chr, 1);
		chr = 0;
		iter = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putstr_fd("process_id => ", 1);
	ft_putnbr_fd(pid, 1);
	signal(SIGUSR1, interpret);
	signal(SIGUSR2, interpret);
	ft_putchar_fd('\n', 1);
	while (42)
		pause();
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece  <hece@student.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 22:07:59 by hece              #+#    #+#             */
/*   Updated: 2022/10/09 22:08:01 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

// bu fonksiyonda 1 bytelık değerimizi 2lik sisteme dönüştürüyoruz

int	*convert_binary(unsigned char c)
{
	int	iter;
	int	*converted;

	converted = malloc(sizeof(int) * 8);
	iter = 0;
	while (iter < 8)
	{
		converted[iter] = (c % 2);
		c /= 2;
		iter++;
	}
	return (converted);
}

// burda ise kill komutu ile pid kullanan process e 1 bytelık
// değeri gönderiyor vesselam...

void	send_signal(int *binary, int pid)
{
	int	iter;

	iter = 0;
	while (iter < 8)
	{
		if (binary[iter] == 0)
			kill(pid, SIGUSR1);
		else if (binary[iter] == 1)
			kill(pid, SIGUSR2);
		usleep(400);
		iter++;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	iter;
	int	*binary;

	iter = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		while (av[2][iter])
		{
			binary = convert_binary((unsigned char)(av[2][iter]));
			send_signal(binary, pid);
			free(binary);
			iter++;
		}
	}
	else
		ft_putstr_fd("Mal mısın aq ! Düzgün gir", 1);
}	

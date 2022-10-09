/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_talk_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece  <hece@student.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 22:09:27 by hece              #+#    #+#             */
/*   Updated: 2022/10/09 22:09:28 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

// fd ye 1 bytelık karakter yazdırır

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// bir stringi yazdırır

void	ft_putstr_fd(char *str, int fd)
{
	int	iter;

	iter = 0;
	while (str[iter] != '\0')
	{
		write(fd, &str[iter], 1);
		iter++;
	}
}

// üst alma fonksiyonu nb yi power kadar çarpar

int	ft_pow(int nb, int power)
{
	int	iter;
	int	result;

	iter = 0;
	result = 1;
	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	while (iter < power)
	{
		result = result * nb;
		iter++;
	}
	return (result);
}

// n sayısını fd dosyasına yazar vesselam...

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		nb = 147483648;
		ft_putnbr_fd(nb, fd);
	}
	else if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = nb * -1;
		ft_putnbr_fd(nb, fd);
	}
	else if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
	else
		ft_putchar_fd(nb + '0', fd);
}

// Girilen char bir stringin sayı olan kısmını
// int bir değere dönüştürme işlemi yapar
// örnek vermek gerekirse eğer
// "     -213dsfıjsdf" olan stringimden int -213
// sonucunu alırım vesselam...

int	ft_atoi(const char *str)
{
	int	index;
	int	carp;
	int	result;

	index = 0;
	carp = 1;
	result = 0;
	while ((str[index] >= '\t' && str[index] <= '\r') || str[index] == ' ')
		index++;
	if (str[index] == '+' || str[index] == '-')
	{
		if (str[index] == '-')
		{
			carp *= -1;
		}
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9' && str[index] != '\0')
	{
		result = ((str[index] - '0') + (result * 10));
		index++;
	}
	return (result * carp);
}

/*#include <stdio.h>
int	main(void)
{
	printf("org : %d, my : %d", atoi("-125"), ft_atoi("-125"));
}*/

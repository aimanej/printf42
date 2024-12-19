/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aijadid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:05:09 by aijadid           #+#    #+#             */
/*   Updated: 2024/12/12 16:11:56 by aijadid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"


void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	intlen(int n)
{
	int	t;

	t = 0;
	if (n < 0)
	{
		t += 1;
		n *= -1;
	}
	while (n > 0)
	{
		n = n / 10;
		t++;
	}
	return (t);
}

int	ft_putnbr(int n)
{
	int i;

	i = intlen(n);
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return i;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
	}
	ft_putchar((n % 10) + 48);
	return (i);
}

unsigned long     ft_putadd(unsigned long n)
{
    int i;
	unsigned long o;
	char base[] = "0123456789abcdef";

        i = intlen(n);
	if (n >= 16)
        {
                ft_putadd(n / 16);
        }
 	ft_putchar(base[n % 16]);

        return (i);
}


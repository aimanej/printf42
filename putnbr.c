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

int	ft_putu(unsigned int n)
{
	int i;

	i = intlen(n);
	if (n > 9)
	{
		ft_putnbr(n / 10);
	}
	ft_putchar((n % 10) + 48);
	return (i);
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
	ft_putchar('0');
	ft_putchar('x');
	if (n >= 16)
        {
                ft_putadd(n / 16);
        }
 	ft_putchar(base[n % 16]);

        return (i);
}

unsigned int    ft_putx(unsigned int n)
{
    int i;
	char base[] = "0123456789abcdef";

        i = intlen(n);
	if (n >= 16)
        {
                ft_putx(n / 16);
        }
    ft_putchar(base[n % 16]);

        return (i);
}

unsigned int    ft_putX(unsigned int n)
{
    int i;
    char base[] = "0123456789ABCDEF";

        i = intlen(n);
	if (n >= 16)
        {
                ft_putX(n / 16);
        }
    ft_putchar(base[n % 16]);

        return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aijadid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:05:09 by aijadid           #+#    #+#             */
/*   Updated: 2024/12/25 20:47:11 by aijadid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

void	ft_putu(unsigned int n, int *r)
{
	if (n == 0)
	{
		ft_putchar('0', r);
		return ;
	}
	if (n > 9)
	{
		ft_putnbr((n / 10), r);
	}
	ft_putchar(((n % 10) + 48), r);
}

void	ft_putnbr(int n, int *r)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*r) += 11;
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-', r);
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr((n / 10), r);
		ft_putnbr((n % 10), r);
	}
	else
		ft_putchar((n + 48), r);
}

void	ft_putadd(unsigned long n, int *r)
{
	char	*base;
	char	s[19];
	int		i;

	i = 0;
	base = "0123456789abcdef";
	if (n == 0)
	{
		ft_putstr("(nil)", r);
		return ;
	}
	write(1, "0x", 2);
	(*r) += 2;
	while (n != 0)
	{
		s[i] = base[n % 16];
		n /= 16;
		i++;
	}
	while (i--)
		ft_putchar(s[i], r);
}

void	ft_putx(unsigned int n, int *r)
{
	char	*base;

	base = "0123456789abcdef";
	if (n >= 16)
	{
		ft_putx((n / 16), r);
	}
	ft_putchar(base[n % 16], r);
}

void	ft_putupperx(unsigned int n, int *r)
{
	char	*base2;

	base2 = "0123456789ABCDEF";
	if (n >= 16)
	{
		ft_putupperx((n / 16), r);
	}
	ft_putchar(base2[n % 16], r);
}

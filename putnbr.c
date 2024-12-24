/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aijadid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:05:09 by aijadid           #+#    #+#             */
/*   Updated: 2024/12/24 17:18:29 by aijadid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"
#include <stdio.h>

void	ft_putu(unsigned int n, int *r)
{
	int i;

	i = addlen(n);
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
		(*r)+= 11;
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

void   ft_putadd(unsigned long n, int *r)
{
	char base[] = "0123456789abcdef";

	if (n >= 16)
        {
                ft_putadd((n / 16), r);
        }
 	ft_putchar(base[n % 16], r);
}

void   ft_putx(unsigned int n, int *r)
{

	char base[] = "0123456789abcdef";
	if (n >= 16)
        {
                ft_putx((n / 16), r);
        }
    ft_putchar(base[n % 16], r);
}

void   ft_putX(unsigned int n, int *r)
{
    char base2[] = "0123456789ABCDEF";

	if (n >= 16)
        {
                ft_putX((n / 16), r);
        }
    ft_putchar(base2[n % 16], r);
}

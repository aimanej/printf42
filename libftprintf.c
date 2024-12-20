/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aijadid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:48:03 by aijadid           #+#    #+#             */
/*   Updated: 2024/12/12 16:27:18 by aijadid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"
#include <stdio.h>

int ft_printf(const char *fixed, ...)
{
	va_list args;
	int	t;
	int	i;
	int	r;
	unsigned long p;

	t = 0;
	r = 0;
	p = 0;
	va_start(args, fixed);
	while(fixed[t])
	{
		while(fixed[t] != 37 && fixed[t])
		{
			ft_putchar(fixed[t]);
			r += 1;
			t++;
		}
		t++;
		if(fixed[t] == 'd' || fixed[t] == 'i')
		{
			ft_putnbr(va_arg(args, int));
		}
		if (fixed[t] == 'c')
		{
			ft_putchar(va_arg(args, int));
		}
		if (fixed[t] == 'p')
		{
			ft_putadd(va_arg(args, unsigned long));
		}
		if(fixed[t] == 'x' || fixed[t] == 'X')
        {
            if(fixed[t] == 'x')
                ft_putx(va_arg(args, unsigned int));
            else
                ft_putX(va_arg(args, unsigned int));
		}
		if (fixed[t] == 's')
		{
			ft_putstr(va_arg(args, char *));
		}
		if (fixed[t] == 'u')
		{
			ft_putu(va_arg(args, unsigned int));
		}
		t++;
	}
	va_end(args);
	return r;
}
int main()
{
	int t = 500;
	char u = 'a';
	int *p = &t;
	char str[] = "aim,ane jadid";
	ft_printf(" %c : %d  %p, %x, %X, %s, %u", u, t, p, t, t, str, t);
	printf("\n %c  : %d , %p, %x, %X, %s, %u", u, t, p, t, t, str, t);
}

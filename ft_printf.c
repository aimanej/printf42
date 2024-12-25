/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aijadid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:48:03 by aijadid           #+#    #+#             */
/*   Updated: 2024/12/24 17:38:48 by aijadid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"
#include <stdio.h>

void   checker(char c , va_list *args, int *r)
{
		if(c == 'd' || c == 'i')
			ft_putnbr(va_arg(*args, int), r);
		if (c == 'c')
			ft_putchar(va_arg(*args, int), r);
		if (c == 'p')
		{
			ft_putadd(va_arg(*args, unsigned long), r);
		}
		if(c == 'x')
	        	ft_putx(va_arg(*args, unsigned int), r);
        	if(c == 'X')
            		ft_putX(va_arg(*args, unsigned int), r);
		if (c == 's')
			ft_putstr(va_arg(*args, char *), r);
		if (c == 'u')
			ft_putu(va_arg(*args, unsigned int), r);
		if (c == 37)
			ft_putchar('%', r);
}

int ft_printf(const char *fixed, ...)
{
	va_list args;
	int	t;
	int	r;

	t = 0;
	r = 0;
	va_start(args, fixed);
	if(!fixed)
	{
		ft_putstr("(NULL)", &r);
		return 0;
	}
	while(fixed[t])
	{
		while(fixed[t] != 37 && fixed[t])
		{
			ft_putchar(fixed[t], &r);
			t++;
		}
		if (!fixed[t])
			break ;
		t++;
		checker(fixed[t], &args, &r);
		t++;
	}
	va_end(args);
	return r;
}
/*
int main()
{
 	printf("%d", ft_printf("%d", -2147));
 	printf("\n%d", -21474);
//	printf("\n%d is great", t);
}*/

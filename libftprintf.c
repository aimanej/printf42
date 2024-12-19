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

void    ft_putchar(char c);
int     intlen(int n);
int     ft_putnbr(int n);

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
			i = va_arg(args, int);
			r += ft_putnbr(i);
		}
		if (fixed[t] == 'c')
		{
			i = va_arg(args, int);
			ft_putchar(i);
			r += 1;
		}
		if (fixed[t] == 'p')
		{
			p = va_arg(args, unsigned long);
		//	printf("'%p'\n", (void *)p);
			ft_putchar('0');
			ft_putchar('x');
			ft_putadd(p);
			r += 1;
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
	ft_printf("and i wonder %c ifyou know : %d what it means %p", u, t, p);
	printf("\n\nand i wonder %c ifyou know : %d what it means %p", u, t, p);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aijadid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:48:03 by aijadid           #+#    #+#             */
/*   Updated: 2024/12/11 20:34:37 by aijadid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"

void    ft_putchar(char c);
int     intlen(int n);
int     ft_putnbr(int n);

int ft_printf(const char *fixed, ...)
{
	va_list args;
	int	t;
	int	i;
	int	r;
	char	c;

	t = 0;
	r = 0;
	va_start(args, fixed);
	while(fixed[t])
	{
		while(fixed[t] != 37)
		{
			ft_putchar(fixed[t]);
			r += 1;
			t++;
		}
		if(fixed[t + 1] == 'd')
		{
			i = va_arg(args, int);
			r += ft_putnbr(i);
		}
		else if (fixed[t + 1] == 'c')
		{
			c = va_arg(args, char);
			ft_putchar(c);
			r += 1;
		}
	}
	va_end(args);
	return r;
}
int main()
{
	int t = 400;
	char c = 'a';
	ft_printf("and i wonder %d if he knows : %c", t, c);
}

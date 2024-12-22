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

	t = 0;
	r = 0;
	va_start(args, fixed);
	while(fixed[t])
	{
		while(fixed[t] != 37 && fixed[t])
		{
			r += ft_putchar(fixed[t]);
			t++;
		}
		t++;
		if(fixed[t] == 'd' || fixed[t] == 'i')
			r += ft_putnbr(va_arg(args, int));
		if (fixed[t] == 'c')
			r += ft_putchar(va_arg(args, int));
		if (fixed[t] == 'p')
		{

			r += ft_putchar('0');
			r += ft_putchar('x');
			r += ft_putadd(va_arg(args, unsigned long));
			
		}
		if(fixed[t] == 'x')
          r += ft_putx(va_arg(args, unsigned int));
		   
        if(fixed[t] == 'X')
            r += ft_putX(va_arg(args, unsigned int));
		if (fixed[t] == 's')
			r += ft_putstr(va_arg(args, char *));
		if (fixed[t] == 'u')
			r += ft_putu(va_arg(args, unsigned int));
		t++;
	}
	va_end(args);
	return r;
}
int main()
{
	int t = 500;
	int l = 411;
	char u = 'a';
	int *p = &t;
	char str[] = "aim,ane jadid";
 	printf("\n %d\n", ft_printf("ride to it %p,  %c, %d, %s, %x, %X, %u", p, u, t, str, t, l, t));
	printf("\n %d\n", printf("ride to it %p,  %c, %d, %s, %x, %X, %u", p, u, t, str, t, l, t));

}

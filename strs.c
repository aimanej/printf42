#include <unistd.h>
#include "ft_printf.h"
#include <stdio.h>

void	ft_putchar(char c, int *r)
{
	write(1, &c, 1);
	(*r)++;
}


void ft_putstr(char *str, int *r)
{
	if (!str)
	{
		write (1, "(null)", 6);
		(*r) += 6;
		return ;
	}
    while(*str)
    {
        ft_putchar(*str, r);
        str++;
    }
}

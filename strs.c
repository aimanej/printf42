#include <unistd.h>
#include "ft_printf.h"
#include <stdio.h>

void	ft_putchar(char c, int *r)
{
	write(1, &c, 1);
	(*r)++;
}

int	intlen(int n)
{
	int	t;

	t = 0;
	if ( n == -2147483648)
		return 11;
	if (n == 0)
		return 1;
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
int     ulen(unsigned long n)
{
        int     t;

        t = 0;
        while (n > 0)
        {
                n = n / 10;
                t++;
        }
        return (t);
}

int	addlen(unsigned long n)
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
		n = n / 16;
		t++;
	}
	return (t);
}
void ft_putstr(char *str, int *r)
{
	if (!str)
	{
		write (1, "(NULL)", 6);
		(*r) += 6;
	}
    while(*str)
    {
        ft_putchar(*str, r);
        str++;
    }
}

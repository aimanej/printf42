#include <unistd.h>
#include "ft_printf.h"
#include <stdio.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return 1;
}

int	intlen(int n)
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
int ft_putstr(char *str)
{
	int t;

	t = 0;
    while(*str)
    {
        t += ft_putchar(*str);
        str++;
    }

	return t;
}
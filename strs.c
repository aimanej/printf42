#include <unistd.h>
#include "ft_printf.h"


void	ft_putchar(char c)
{
	write(1, &c, 1);
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

void ft_putstr(char *str)
{
    while(*str)
    {
        ft_putchar(*str);
        str++;
    }
}
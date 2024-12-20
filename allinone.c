#include <unistd.h>
#include "ft_printf.h"

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

void    ft_putchar_fd(char c);
int     intlen(int n);
int     ft_putnbr(int n);
int ft_printf(const char *fixed, ...);
unsigned long     ft_putadd(unsigned long n);

# endif

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

int	ft_putnbr(int n)
{
	int i;

	i = intlen(n);
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return i;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
	}
	ft_putchar((n % 10) + 48);
	return (i);
}

unsigned int    ft_putX(unsigned int n)
{
    int i;
    char base[] = "0123456789ABCDEF";

        i = intlen(n);
	if (n >= 16)
        {
                ft_putX(n / 16);
        }
    ft_putchar(base[n % 16]);

        return (i);
}

unsigned int    ft_putx(unsigned int n)
{
    int i;
	char base[] = "0123456789abcdef";

        i = intlen(n);
	if (n >= 16)
        {
                ft_putx(n / 16);
        }
    ft_putchar(base[n % 16]);

        return (i);
}

unsigned long     ft_putadd(unsigned long n)
{
    int i;
	unsigned long o;
	char base[] = "0123456789abcdef";

        i = intlen(n);
	if (n >= 16)
        {
                ft_putadd(n / 16);
        }
    ft_putchar(base[n % 16]);

        return (i);
}
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
    unsigned int x;

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
        if(fixed[t] == 'x' || fixed[t] == 'X')
        {
            x = va_arg(args, unsigned int);
            if(fixed[t] == 'x')
                ft_putx(x);
            else
                ft_putX(x);
        }
		t++;
	}
	va_end(args);
	return r;
}
int main()
{
	int t = 7894;
	char u = 'a';
	int *p = &t;
	ft_printf(" %c  : %d   %p  %x,  %X", u, t, p, t, t);
	printf("\n %c : %d  %p, %x, %X", u, t, p, t, t);
}
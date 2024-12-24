#include <unistd.h>
#include <stdarg.h>

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
int	ft_putnbr(int n)
{
	int i;

	i = intlen(n);
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		i += 11;
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
		ft_putnbr(n % 10);
	}
	ft_putchar(n + 48);
	return (i);
}


void   checker(char c , va_list *args, int *r)
{
		if(c == 'd' || c == 'i')
			*r += ft_putnbr(va_arg(*args, int));
		// if (c == 'c')
		// 	*r += ft_putchar(va_arg(*args, int));
		// if (c == 'p')
		// {
		// 	*r += ft_putchar('0');
		// 	*r += ft_putchar('x');
		// 	*r += ft_putadd(va_arg(*args, unsigned long));
		// }
		// if(c == 'x')
	    //     	*r += ft_putx(va_arg(*args, unsigned int));
        // 	if(c == 'X')
        //     		*r += ft_putX(va_arg(*args, unsigned int));
		// if (c == 's')
		// 	*r += ft_putstr(va_arg(*args, char *));
		// if (c == 'u')
		// 	*r += ft_putu(va_arg(*args, unsigned int));
		// if (c == 37)
		// 	ft_putchar('%');
}

int ft_printf(const char *fixed, ...)
{
	va_list args;
	int	t;
	int	r;

	t = 0;
	r = 0;
	va_start(args, fixed);
	if(!fixed[t])
		return 0;
	while(fixed[t])
	{
		while(fixed[t] != 37 && fixed[t])
		{
			r += ft_putchar(fixed[t]);
			t++;
		}
		t++;
		checker(fixed[t], &args, &r);
		t++;
	}
	va_end(args);
	return r;
}

int main()
{
	int t = -2147483648;
	int l = 411;
	char u = 'a';
	int *p = &t;
	char str[] = "aim,ane jadid";
 	ft_printf("%d", 42);
//	printf("\n%d is great", t);
}
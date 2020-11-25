#include "libft/libft.h"
#include <stdarg.h>

void	ft_putnbr_base(int n);

void	ft_putnbr_up(unsigned int n);

void	ft_putnbr_p(unsigned long nu);

int		ft_printf(const char *str, ...)
{
	va_list		nxtarg;
	int			i;
	int			r;

	va_start (nxtarg, str);
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '%' && str[i] != '\0')
		{
			write (1, &str[i], 1);
			i++;
		}
		if (str[i] == '\0')
			break;
		if (str[i + 1] == 's')
			ft_putstr_fd(va_arg(nxtarg, char*), 1);
		else if (str[i + 1] == 'd' || str[i + 1] == 'i')
			ft_putnbr_fd(va_arg(nxtarg, int), 1);
		else if (str[i + 1] == 'c')
		{
			r = va_arg(nxtarg, int);
			write(1, &r, 1);
		}
		else if (str[i + 1] == 'x')
			ft_putnbr_base(va_arg(nxtarg, int));
		else if (str[i + 1] == 'X')
			ft_putnbr_up(va_arg(nxtarg, int));
		else if (str[i + 1] == 'p')
		{
			write (1, "0x", 2);
			ft_putnbr_p((unsigned long)va_arg(nxtarg, void*));
		}
		if (str[i] == '\0' || str[i + 1] == '\0' || str[i + 2] == '\0')
			break;
		i = i + 2;
	}
	va_end (nxtarg);
	return (0);
}

void	ft_putnbr_base(int n)
{
	char			c;
	unsigned int	nu;

	nu = (unsigned int)n;
	if (nu > 9)
	{
		if (nu % 16 >= 0 && nu % 16 <= 9)
			c = nu % 16 + '0';
		else
			c = 97 + (nu % 16 - 10);
		ft_putnbr_base(nu / 16);
		write(1, &c, 1);
	}
	if (nu <= 9 && nu > 0)
	{
		c = nu + '0';
		write(1, &c, 1);
	}
}

void	ft_putnbr_up(unsigned int n)
{
	char			c;
	unsigned int	nu;

	nu = (unsigned int)n;
	if (nu > 9)
	{
		if (nu % 16 >= 0 && nu % 16 <= 9)
			c = nu % 16 + '0';
		else
			c = 65 + ((nu % 16) - 10);
		ft_putnbr_up(nu / 16);
		write(1, &c, 1);
	}
	if (nu <= 9 && nu > 0)
	{
		c = nu + '0';
		write(1, &c, 1);
	}
}

void	ft_putnbr_p(unsigned long nu)
{
	char			c;

	if (nu > 9)
	{
		if (nu % 16 >= 0 && nu % 16 <= 9)
			c = nu % 16 + '0';
		else
			c = 97 + (nu % 16 - 10);
		ft_putnbr_p(nu / 16);
		write(1, &c, 1);
	}
	if (nu <= 9 && nu > 0)
	{
		c = nu + '0';
		write(1, &c, 1);
	}
}


#include <stdio.h>
int		main(void)
{
	char *a = "100";
	ft_printf("%p\n", &a);
	printf("%p\n", &a);
}

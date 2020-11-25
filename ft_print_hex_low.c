/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_low.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehillman <ehillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 19:19:55 by ehillman          #+#    #+#             */
/*   Updated: 2020/11/25 20:01:36 by ehillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_base(int n)
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

static int			ft_len_hex(long long int n)
{
	int				len;

	len = 0;
	while (n > 1)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static void		ft_print_spaces(int num, t_struct *info, int arg)
{
	int			tmp;

	if (info->accur < ft_len_hex(arg) && ft_mod(info->width) < ft_len_hex(arg))
		return ;
	if (info->accur >= info->width && info->accur > ft_len_hex(arg))
		ft_put_zero(info->accur - ft_len_hex(arg));
	else if (info->accur < info->width && info->accur > ft_len_hex(arg))
	{
			tmp = info->width - info->accur;
			ft_put_space(tmp);
			ft_put_zero(num - tmp);
	}
	else if (info->is_zero == 1)
		ft_put_zero(num);
	else
		ft_put_space(num);
}

void			ft_print_hex_low(t_struct *info)
{
	int			i;
	int			arg;

	i = 0;
	if (info->width > 0 || info->accur > ft_mod(info->width))
	{
		arg = va_arg(info->argument, int);
		ft_print_spaces(info->width - ft_len_hex(arg), info, arg);
		ft_putnbr_base(arg);
		return ;
	}
	if (info->width < 0)
	{
		arg = va_arg(info->argument, int);
		ft_putnbr_base(arg);
		ft_print_spaces(-info->width - ft_len_hex(arg), info, arg);
		return ;
	}
	ft_putnbr_base(va_arg(info->argument, int));
}


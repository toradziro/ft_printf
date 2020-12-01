/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_up.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehillman <ehillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 21:20:49 by ehillman          #+#    #+#             */
/*   Updated: 2020/12/01 20:35:35 by ehillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include "ft_printf.h"

static void	ft_putnbr_base(unsigned int n)
{
	char			c;
	unsigned int	nu;

	nu = (unsigned int)n;
	if (nu > 9)
	{
		if (nu % 16 >= 0 && nu % 16 <= 9)
			c = nu % 16 + '0';
		else
			c = 65 + (nu % 16 - 10);
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

static void		ft_print_spaces_int(int num, int arg, int edge) //edge 0 - +width, edge 1 - -width
{
	if (!edge)
	{
		ft_put_space(num);
		if (arg == 0)
			write(1, "0", 1);
		else
			ft_putnbr_base(arg);
	}
	else
	{
		if (arg == 0)
			write(1, "0", 1);
		else
			ft_putnbr_base(arg);
		ft_put_space(num);
	}
}

static void		ft_print_zeros_int(int num, int arg, int edge)
{
	if (!edge)
	{
		ft_put_zero(num);
		if (arg == 0)
			write(1, "0", 1);
		else
			ft_putnbr_base(arg);
	}
	else
	{
		if (arg == 0)
			write(1, "0", 1);
		else
			ft_putnbr_base(arg);
		ft_put_zero(num);
	}

}

static void		ft_print_positive_hex(t_struct *info, unsigned int arg, int len)
{
	if (info->width > 0 && info->accur < len && info->width > len)
	{
		if (info->is_zero == 1 && info->accur < 0)
			ft_print_zeros_int(info->width - len, arg, 0);
		else
			ft_print_spaces_int(info->width - len, arg, 0);
		return ;
	}
	else if (info->accur > len && info->width > info->accur)
	{
		ft_put_space(info->width - info->accur);
		ft_put_zero(info->accur - len);
		ft_putnbr_base(arg);
	}
	else if (info->accur > ft_mod(info->width) && info->accur > len)
	{
		if (info->width == 0)
			ft_print_zeros_int(info->accur - len - 1, arg, 0);
		else
			ft_print_zeros_int(info->accur - len, arg, 0);
	}
	else if (info->width < 0 && info->accur < len)
	{
		ft_print_spaces_int(ft_mod(info->width) - len, arg, 1);
	}
	else if (info->width < 0 && info->accur > len)
	{
		ft_put_zero(info->accur - len);
		ft_putnbr_base(arg);
		ft_put_space(ft_mod(info->width) - info->accur);
	}
	else
		ft_putnbr_base(arg);

}

static void		ft_print_zero_hex(t_struct *info, unsigned int arg)
{
	if (info->accur == -2)
	{
		ft_put_space(ft_mod(info->width));
		return ;
	}
	else if (info->width > 0 && info->accur <= 1)
	{
		if (info->is_zero)
			ft_print_zeros_int(info->width - 1, arg, 0);
		else if (info->accur)
			ft_print_spaces_int(info->width - 1, arg, 0);
		else
			ft_put_space(info->width);
	}
	else if (info->width < 0 && info->accur == 0)
		ft_put_space(ft_mod(info->width));
	else if (info->width < 0 && info->accur < 1)
		ft_print_spaces_int(ft_mod(info->width) - 1, arg, 1);
	else if (info->accur > 1 && info->width > info->accur)
	{
		ft_put_space(info->width - info->accur);
		ft_put_zero(info->accur - 1);
		write(1, "0", 1);
	}
	else if (info->accur > ft_mod(info->width) && info->accur > 1)
		ft_print_zeros_int(info->accur - 1, ft_mod(arg), 0);
	else if (info->width < 0 && info->accur > 1)
	{
		ft_print_zeros_int(info->accur - 1, arg, 0);
		ft_put_space(ft_mod(info->width) - info->accur);
	}
	else if (info->accur == 0)
		return ;
	else
		write(1, "0", 1);
}

void			ft_print_hex_up(t_struct *info)
{
	unsigned int			arg;
	int						len;

	arg = va_arg(info->argument, int);
	len = ft_len_hex(arg);
	if (arg > 0)
		ft_print_positive_hex(info, arg, len);
	else
		ft_print_zero_hex(info, arg);
}

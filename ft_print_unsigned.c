/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehillman <ehillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 21:52:33 by ehillman          #+#    #+#             */
/*   Updated: 2020/12/01 22:04:07 by ehillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_putnbr_u_fd(unsigned int n)
{
	char			c;
	unsigned int	nu;

	nu = n;
	if (nu > 9)
	{
		c = nu % 10 + '0';
		ft_putnbr_u_fd(nu / 10);
		write(1, &c, 1);
	}
	if (nu <= 9)
	{
		c = nu + '0';
		write(1, &c, 1);
	}
}

static void		ft_print_spaces_int(int num, unsigned int arg, int edge) //edge 0 - +width, edge 1 - -width
{
	if (!edge)
	{
		ft_put_space(num);
		ft_putnbr_u_fd(arg);
	}
	else
	{
		ft_putnbr_u_fd(arg);
		ft_put_space(num);
	}
}

static void		ft_print_zeros_int(int num, unsigned int arg, int edge)
{
	if (!edge)
	{
		ft_put_zero(num);
		ft_putnbr_u_fd(arg);
	}
	else
	{
		ft_putnbr_u_fd(arg);
		ft_put_zero(num);
	}

}

static void		ft_print_positive_int(t_struct *info, unsigned int arg, int len)
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
		ft_putnbr_u_fd(arg);
	}
	else if (info->accur > ft_mod(info->width) && info->accur > len)
	{
									//  ft_putnbr_fd(info->width, 1);
									//  write(1, "\n", 1);
		ft_print_zeros_int(info->accur - len, arg, 0);
	}
	else if (info->width < 0 && info->accur < len)
	{
		ft_print_spaces_int(ft_mod(info->width) - len, arg, 1);
	}
	else if (info->width < 0 && info->accur > len)
	{
		ft_put_zero(info->accur - len);
		ft_putnbr_u_fd(arg);
		ft_put_space(ft_mod(info->width) - info->accur);
	}
	else
		ft_putnbr_u_fd(arg);

}

static void		ft_print_zero_int(t_struct *info, unsigned int arg)
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
		ft_putnbr_u_fd(arg);
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
		ft_putnbr_u_fd(arg);
}

void			ft_print_unsigned(t_struct *info)
{
	unsigned int	arg;
	int				len;

	arg = va_arg(info->argument, unsigned int);
	len = ft_len(arg);
	if (arg > 0)
		ft_print_positive_int(info, arg, len);
	else
		ft_print_zero_int(info, arg);
}

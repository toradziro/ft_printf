/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_low.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehillman <ehillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 19:19:55 by ehillman          #+#    #+#             */
/*   Updated: 2020/12/04 21:04:30 by ehillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_print_positive_hex_n(t_struct *info,
					unsigned int arg, int len)
{
	if (info->accur > len && info->width >= info->accur)
	{
		ft_put_space(info->width - info->accur, info);
		ft_put_zero(info->accur - len, info);
		ft_putnbr_base(arg, info, 97);
	}
	else if (info->accur > ft_mod(info->width) && info->accur > len)
		ft_print_zeros_hex_l(info->accur - len, arg, 0, info);
	else if (info->width < 0 && info->accur <= len)
		ft_print_spaces_hex_l(ft_mod(info->width) - len, arg, 1, info);
	else if (info->width < 0 && info->accur > len)
	{
		ft_put_zero(info->accur - len, info);
		ft_putnbr_base(arg, info, 97);
		ft_put_space(ft_mod(info->width) - info->accur, info);
	}
	else
		ft_putnbr_base(arg, info, 97);
}

static void			ft_print_positive_hex(t_struct *info,
					unsigned int arg, int len)
{
	if (info->width > 0 && info->accur <= len && info->width > len)
	{
		if (info->is_zero == 1 && info->accur < 0)
			ft_print_zeros_hex_l(info->width - len, arg, 0, info);
		else
			ft_print_spaces_hex_l(info->width - len, arg, 0, info);
		return ;
	}
	else
		ft_print_positive_hex_n(info, arg, len);
}

static void			ft_print_zero_hex_n(t_struct *info, unsigned int arg)
{
	if (info->width < 0 && info->accur == 0)
		ft_put_space(ft_mod(info->width), info);
	else if (info->width < 0 && info->accur <= 1)
		ft_print_spaces_hex_l(ft_mod(info->width) - 1, arg, 1, info);
	else if (info->accur > 1 && info->width >= info->accur)
	{
		ft_put_space(info->width - info->accur, info);
		ft_put_zero(info->accur - 1, info);
		ft_putnbr(arg, 1, info);
	}
	else if (info->accur > ft_mod(info->width) && info->accur > 1)
		ft_print_zeros_hex_l(info->accur - 1, ft_mod(arg), 0, info);
	else if (info->width < 0 && info->accur > 1)
	{
		ft_print_zeros_hex_l(info->accur - 1, arg, 0, info);
		ft_put_space(ft_mod(info->width) - info->accur, info);
	}
	else if (info->accur == 0)
		return ;
	else
		ft_putnbr(arg, 1, info);
}

static void			ft_print_zero_hex(t_struct *info, unsigned int arg)
{
	if (info->accur == 0)
	{
		ft_put_space(ft_mod(info->width), info);
		return ;
	}
	if (info->width > 0 && info->accur <= 1)
	{
		if (info->is_zero && (info->accur <= 0))
			ft_print_zeros_hex_l(info->width - 1, arg, 0, info);
		else if (info->accur)
			ft_print_spaces_hex_l(info->width - 1, arg, 0, info);
		else
			ft_put_space(info->width, info);
	}
	else
		ft_print_zero_hex_n(info, arg);
}

void				ft_print_hex_low(t_struct *info)
{
	unsigned int	arg;
	int				len;

	arg = va_arg(info->argument, int);
	len = ft_len_hex(arg);
	if (arg > 0)
		ft_print_positive_hex(info, arg, len);
	else
		ft_print_zero_hex(info, arg);
}

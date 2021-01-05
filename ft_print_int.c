/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehillman <ehillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 22:04:10 by ehillman          #+#    #+#             */
/*   Updated: 2020/12/04 23:12:25 by ehillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_print_negative_int_next(t_struct *info, int arg, int len)
{
	if (info->accur > ft_mod(info->width) && info->accur >= len)
	{
		info->p_len += write(1, "-", 1);
		ft_print_zeros_int(info->accur - len + 1, ft_mod(arg), 0, info);
	}
	else if (info->width < 0 && info->accur < len)
	{
		info->p_len += write(1, "-", 1);
		ft_print_spaces_int(ft_mod(info->width) - ft_mod(len), ft_mod(arg),
							1, info);
	}
	else if (info->width <= 0 && info->accur >= len)
	{
		info->p_len += write(1, "-", 1);
		ft_print_zeros_int(info->accur - len + 1, ft_mod(arg), 0, info);
		ft_put_space(ft_mod(info->width) - info->accur - 1, info);
	}
	else
		ft_putnbr(arg, 1, info);
}

static void		ft_print_negative_int(t_struct *info, int arg, int len)
{
	if (info->accur >= len && info->width >= info->accur)
	{
		ft_put_space(info->width - info->accur - 1, info);
		info->p_len += write(1, "-", 1);
		ft_put_zero(info->accur - len + 1, info);
		ft_putnbr(ft_mod(arg), 1, info);
	}
	else if (info->width > 0 && info->accur <= len &&
			info->width > len && info->accur != info->width)
	{
		if (info->is_zero && (info->accur >= len || info->accur < 0))
		{
			info->p_len += write(1, "-", 1);
			ft_print_zeros_int(info->width - len, ft_mod(arg), 0, info);
		}
		else
			ft_print_spaces_int(info->width - len, arg, 0, info);
	}
	else
		ft_print_negative_int_next(info, arg, len);
}

static void		ft_print_zero_int_next(t_struct *info, int arg)
{
	if (info->width < 0 && info->accur == 0)
		ft_put_space(ft_mod(info->width), info);
	else if (info->width < 0 && info->accur <= 1)
		ft_print_spaces_int(ft_mod(info->width) - 1, arg, 1, info);
	else if (info->accur > 1 && info->width >= info->accur)
	{
		ft_put_space(info->width - info->accur, info);
		ft_put_zero(info->accur - 1, info);
		ft_putnbr(arg, 1, info);
	}
	else if (info->accur > ft_mod(info->width) && info->accur > 1)
		ft_print_zeros_int(info->accur - 1, ft_mod(arg), 0, info);
	else if (info->width < 0 && info->accur > 1)
	{
		ft_print_zeros_int(info->accur - 1, arg, 0, info);
		ft_put_space(ft_mod(info->width) - info->accur, info);
	}
	else if (info->accur == 0)
		return ;
	else
		ft_putnbr(arg, 1, info);
}

static void		ft_print_zero_int(t_struct *info, int arg)
{
	if (info->accur == 0)
	{
		ft_put_space(ft_mod(info->width), info);
		return ;
	}
	if (info->width > 0 && info->accur <= 1)
	{
		if (info->is_zero && (info->accur <= 0))
			ft_print_zeros_int(info->width - 1, arg, 0, info);
		else if (info->accur)
			ft_print_spaces_int(info->width - 1, arg, 0, info);
		else
			ft_put_space(info->width, info);
	}
	else
		ft_print_zero_int_next(info, arg);
}

void			ft_print_int(t_struct *info)
{
	int			arg;
	int			len;

	arg = va_arg(info->argument, int);
	len = ft_len(arg);
	if (arg > 0)
		ft_print_positive_int(info, arg, len);
	else if (arg < 0)
		ft_print_negative_int(info, arg, len);
	else
		ft_print_zero_int(info, arg);
}

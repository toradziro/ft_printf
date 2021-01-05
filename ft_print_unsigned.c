/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehillman <ehillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 21:52:33 by ehillman          #+#    #+#             */
/*   Updated: 2020/12/04 21:30:18 by ehillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_print_positive_u_n(t_struct *info, unsigned int arg, int len)
{
	if (info->accur > ft_mod(info->width) && info->accur > len)
		ft_print_zeros_u(info->accur - len, arg, 0, info);
	else if (info->width < 0 && info->accur <= len)
		ft_print_spaces_u(ft_mod(info->width) - len, arg, 1, info);
	else if (info->width < 0 && info->accur > len)
	{
		ft_put_zero(info->accur - len, info);
		ft_putnbr_u_fd(arg, info);
		ft_put_space(ft_mod(info->width) - info->accur, info);
	}
	else
		ft_putnbr_u_fd(arg, info);
}

static void		ft_print_positive_u(t_struct *info, unsigned int arg, int len)
{
	if (info->width > 0 && info->accur <= len && info->width > len)
	{
		if (info->is_zero == 1 && info->accur < 0)
			ft_print_zeros_u(info->width - len, arg, 0, info);
		else
			ft_print_spaces_u(info->width - len, arg, 0, info);
		return ;
	}
	else if (info->accur > len && info->width >= info->accur)
	{
		ft_put_space(info->width - info->accur, info);
		ft_put_zero(info->accur - len, info);
		ft_putnbr_u_fd(arg, info);
	}
	else
		ft_print_positive_u_n(info, arg, len);
}

static void		ft_print_zero_u_n(t_struct *info, int arg)
{
	if (info->width < 0 && info->accur == 0)
		ft_put_space(ft_mod(info->width), info);
	else if (info->width < 0 && info->accur <= 1)
		ft_print_spaces_u(ft_mod(info->width) - 1, arg, 1, info);
	else if (info->accur > 1 && info->width >= info->accur)
	{
		ft_put_space(info->width - info->accur, info);
		ft_put_zero(info->accur - 1, info);
		ft_putnbr(arg, 1, info);
	}
	else if (info->accur > ft_mod(info->width) && info->accur > 1)
		ft_print_zeros_u(info->accur - 1, ft_mod(arg), 0, info);
	else if (info->width < 0 && info->accur > 1)
	{
		ft_print_zeros_u(info->accur - 1, arg, 0, info);
		ft_put_space(ft_mod(info->width) - info->accur, info);
	}
	else if (info->accur == 0)
		return ;
	else
		ft_putnbr(arg, 1, info);
}

static void		ft_print_zero_u(t_struct *info, int arg)
{
	if (info->accur == 0)
	{
		ft_put_space(ft_mod(info->width), info);
		return ;
	}
	if (info->width > 0 && info->accur <= 1)
	{
		if (info->is_zero && (info->accur <= 0))
			ft_print_zeros_u(info->width - 1, arg, 0, info);
		else if (info->accur)
			ft_print_spaces_u(info->width - 1, arg, 0, info);
		else
			ft_put_space(info->width, info);
	}
	else
		ft_print_zero_u_n(info, arg);
}

void			ft_print_unsigned(t_struct *info)
{
	unsigned int	arg;
	int				len;

	arg = va_arg(info->argument, unsigned int);
	len = ft_len(arg);
	if (arg > 0)
		ft_print_positive_u(info, arg, len);
	else
		ft_print_zero_u(info, arg);
}

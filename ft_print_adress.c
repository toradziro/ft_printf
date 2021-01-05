/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_adress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehillman <ehillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 21:52:41 by ehillman          #+#    #+#             */
/*   Updated: 2020/12/04 23:15:58 by ehillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_print_positive_adr_n(t_struct *info,
					unsigned long arg, int len)
{
	if (info->accur > ft_mod(info->width) && info->accur > len)
	{
		if (info->width == 0)
			ft_print_zeros_p(info->accur - len - 3, arg, 0, info);
	}
	else if (info->width < 0 && info->accur < len)
		ft_print_spaces_p(ft_mod(info->width) - len - 2, arg, 1, info);
	else if (info->width < 0 && info->accur > len)
	{
		ft_put_zero(info->accur - len, info);
		info->p_len += write(1, "0x", 2);
		ft_putnbr_p(arg, info);
		ft_put_space(ft_mod(info->width) - 3 - info->accur, info);
	}
	else
	{
		info->p_len += write(1, "0x", 2);
		ft_putnbr_p(arg, info);
	}
}

static void			ft_print_positive_adr(t_struct *info,
					unsigned long arg, int len)
{
	if (info->width > 0 && info->accur < len && info->width > len)
	{
		if (info->is_zero == 1 && info->accur < 0)
			ft_print_zeros_p(info->width - len - 3, arg, 0, info);
		else
			ft_print_spaces_p(info->width - len - 2, arg, 0, info);
		return ;
	}
	else if (info->accur > len && info->width > info->accur)
	{
		ft_put_space(info->width - info->accur - 3, info);
		ft_put_zero(info->accur - len, info);
		ft_putnbr_p(arg, info);
	}
	else
		ft_print_positive_adr_n(info, arg, len);
}

static void			ft_print_zero_adr_n(t_struct *info, unsigned long arg)
{
	if (info->width < 0 && info->accur < 1)
		ft_print_spaces_p(ft_mod(info->width) - 3, arg, 1, info);
	else if (info->accur > 1 && info->width > info->accur)
	{
		ft_put_space(info->width - info->accur - 3, info);
		ft_put_zero(info->accur, info);
		info->p_len += write(1, "0x0", 3);
	}
	else if (info->accur > ft_mod(info->width) && info->accur > 1)
		ft_print_zeros_p(info->accur - 1, ft_mod(arg), 0, info);
	else if (info->width < 0 && info->accur > 1)
	{
		ft_print_zeros_p(info->accur - 1, arg, 0, info);
		ft_put_space(ft_mod(info->width) - 3 - info->accur, info);
	}
	else if (info->accur == 0)
		return ;
	else
		info->p_len += write(1, "0x0", 3);
}

static void			ft_print_zero_adr(t_struct *info, unsigned long arg)
{
	if (info->accur == 0)
	{
		ft_put_space(ft_mod(info->width) - 3, info);
		info->p_len += write(1, "0x", 2);
		return ;
	}
	else if (info->width > 0 && info->accur <= 1)
	{
		if (info->is_zero)
			ft_print_zeros_p(info->width - 3, arg, 0, info);
		else if (info->accur)
			ft_print_spaces_p(info->width - 3, arg, 0, info);
		else
			ft_put_space(info->width - 3, info);
	}
	else if (info->width < 0 && info->accur == 0)
		ft_put_space(ft_mod(info->width), info);
	else
		ft_print_zero_adr_n(info, arg);
}

void				ft_print_adress(t_struct *info)
{
	void			*f_arg;
	int				len;
	unsigned long	arg;

	f_arg = (va_arg(info->argument, void*));
	arg = (unsigned long)f_arg;
	len = ft_len_hex(arg);
	if (arg > 0)
		ft_print_positive_adr(info, arg, len);
	else
		ft_print_zero_adr(info, arg);
}

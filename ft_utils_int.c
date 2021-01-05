/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehillman <ehillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 23:11:49 by ehillman          #+#    #+#             */
/*   Updated: 2020/12/04 23:12:51 by ehillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_spaces_int(int num, long arg, int edge, t_struct *info)
{
	if (!edge)
	{
		ft_put_space(num, info);
		ft_putnbr(arg, 1, info);
	}
	else
	{
		ft_putnbr(arg, 1, info);
		ft_put_space(num, info);
	}
}

void		ft_print_zeros_int(int num, long arg, int edge, t_struct *info)
{
	if (!edge)
	{
		ft_put_zero(num, info);
		ft_putnbr(arg, 1, info);
	}
	else
	{
		ft_putnbr(arg, 1, info);
		ft_put_zero(num, info);
	}
}

void		ft_print_positive_int_next(t_struct *info, int arg, int len)
{
	if (info->accur > ft_mod(info->width) && info->accur > len)
		ft_print_zeros_int(info->accur - len, arg, 0, info);
	else if (info->width < 0 && info->accur <= len)
	{
		ft_print_spaces_int(ft_mod(info->width) - len, arg, 1, info);
	}
	else if (info->width < 0 && info->accur > len)
	{
		ft_put_zero(info->accur - len, info);
		ft_putnbr(arg, 1, info);
		ft_put_space(ft_mod(info->width) - info->accur, info);
	}
	else
		ft_putnbr(arg, 1, info);
}

void		ft_print_positive_int(t_struct *info, int arg, int len)
{
	if (info->width > 0 && info->accur <= len && info->width > len)
	{
		if (info->is_zero == 1 && info->accur < 0)
			ft_print_zeros_int(info->width - len, arg, 0, info);
		else
			ft_print_spaces_int(info->width - len, arg, 0, info);
		return ;
	}
	else if (info->accur > len && info->width >= info->accur)
	{
		ft_put_space(info->width - info->accur, info);
		ft_put_zero(info->accur - len, info);
		ft_putnbr(arg, 1, info);
	}
	else
		ft_print_positive_int_next(info, arg, len);
}

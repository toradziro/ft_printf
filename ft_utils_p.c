/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehillman <ehillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 23:06:37 by ehillman          #+#    #+#             */
/*   Updated: 2020/12/04 23:16:23 by ehillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_putnbr_p(unsigned long nu, t_struct *info)
{
	char		c;

	if (nu > 9)
	{
		if (nu % 16 >= 0 && nu % 16 <= 9)
			c = nu % 16 + '0';
		else
			c = 97 + (nu % 16 - 10);
		ft_putnbr_p(nu / 16, info);
		info->p_len += write(1, &c, 1);
	}
	if (nu <= 9 && nu > 0)
	{
		c = nu + '0';
		info->p_len += write(1, &c, 1);
	}
}

void			ft_print_spaces_p(int num, unsigned long arg, int edge,
					t_struct *info)
{
	if (!edge)
	{
		ft_put_space(num, info);
		if (arg == 0)
			info->p_len += write(1, "0x0", 3);
		else
		{
			info->p_len += write(1, "0x", 2);
			ft_putnbr_p(arg, info);
		}
	}
	else
	{
		if (arg == 0)
			info->p_len += write(1, "0x0", 3);
		else
		{
			info->p_len += write(1, "0x", 2);
			ft_putnbr_p(arg, info);
		}
		ft_put_space(num, info);
	}
}

void			ft_print_zeros_p(int num, unsigned long arg, int edge,
								t_struct *info)
{
	if (!edge)
	{
		ft_put_zero(num, info);
		if (arg == 0)
			info->p_len += write(1, "0x0", 3);
		else
		{
			info->p_len += write(1, "0x", 2);
			ft_putnbr_p(arg, info);
		}
	}
	else
	{
		if (arg == 0)
			info->p_len += write(1, "0x0", 3);
		else
		{
			info->p_len += write(1, "0x", 2);
			ft_putnbr_p(arg, info);
		}
		ft_put_zero(num, info);
	}
}

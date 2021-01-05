/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehillman <ehillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 20:01:27 by ehillman          #+#    #+#             */
/*   Updated: 2020/12/04 20:57:24 by ehillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_len_hex(long long int n)
{
	int		len;

	len = 0;
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

void	ft_print_spaces_hex_l(int num, int arg, int edge, t_struct *info)
{
	if (!edge)
	{
		ft_put_space(num, info);
		if (arg == 0)
			info->p_len += write(1, "0", 1);
		else
			ft_putnbr_base(arg, info, 97);
	}
	else
	{
		if (arg == 0)
			info->p_len += write(1, "0", 1);
		else
			ft_putnbr_base(arg, info, 97);
		ft_put_space(num, info);
	}
}

void	ft_print_zeros_hex_l(int num, int arg, int edge, t_struct *info)
{
	if (!edge)
	{
		ft_put_zero(num, info);
		if (arg == 0)
			info->p_len += write(1, "0", 1);
		else
			ft_putnbr_base(arg, info, 97);
	}
	else
	{
		if (arg == 0)
			info->p_len += write(1, "0", 1);
		else
			ft_putnbr_base(arg, info, 97);
		ft_put_zero(num, info);
	}
}

void	ft_print_spaces_hex_u(int num, int arg, int edge, t_struct *info)
{
	if (!edge)
	{
		ft_put_space(num, info);
		if (arg == 0)
			info->p_len += write(1, "0", 1);
		else
			ft_putnbr_base(arg, info, 65);
	}
	else
	{
		if (arg == 0)
			info->p_len += write(1, "0", 1);
		else
			ft_putnbr_base(arg, info, 65);
		ft_put_space(num, info);
	}
}

void	ft_print_zeros_hex_u(int num, int arg, int edge, t_struct *info)
{
	if (!edge)
	{
		ft_put_zero(num, info);
		if (arg == 0)
			info->p_len += write(1, "0", 1);
		else
			ft_putnbr_base(arg, info, 65);
	}
	else
	{
		if (arg == 0)
			info->p_len += write(1, "0", 1);
		else
			ft_putnbr_base(arg, info, 65);
		ft_put_zero(num, info);
	}
}

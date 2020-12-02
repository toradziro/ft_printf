/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_adress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehillman <ehillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 21:52:41 by ehillman          #+#    #+#             */
/*   Updated: 2020/12/01 23:13:32 by ehillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_p(unsigned long nu, t_struct *info)
{
	char			c;

	if (nu > 9)
	{
		if (nu % 16 >= 0 && nu % 16 <= 9)
			c = nu % 16 + '0';
		else
			c = 97 + (nu % 16 - 10);
		ft_putnbr_p(nu / 16, info);
		info->p_len += write(1, &c, 1);
	}
	if (nu <= 9)
	{
		c = nu + '0';
		info->p_len += write(1, &c, 1);
	}
}

static int			ft_len_hex(unsigned long n)
{
	unsigned int	len;

	len = 0;
	while (n > 1)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static void		ft_print_spaces_int(int num, unsigned long arg, int edge,
								 t_struct *info)
//edge 0 - +width, edge 1 - -width
{
	if (!edge)
	{
		ft_put_space(num);
		if (arg == 0)
			info->p_len += write(1, "0x0", 3);
		else
		{
			info->p_len += write(1, "0x", 2);
			ft_putnbr_p(arg);
		}
	}
	else
	{
		if (arg == 0)
			info->p_len += write(1, "0x0", 3);
		else
		{
			info->p_len += write(1, "0x", 2);
			ft_putnbr_p(arg);
		}
		ft_put_space(num);
	}
}

static void		ft_print_zeros_int(int num, unsigned long arg, int edge,
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

static void		ft_print_positive_hex(t_struct *info, unsigned long arg, int len)
{
	if (info->width > 0 && info->accur < len && info->width > len)
	{
		if (info->is_zero == 1 && info->accur < 0)
			ft_print_zeros_int(info->width - len - 3, arg, 0, info);
		else
			ft_print_spaces_int(info->width - len - 3, arg, 0, info);
		return ;
	}
	else if (info->accur > len && info->width > info->accur)
	{
		ft_put_space(info->width - info->accur - 3, info);
		ft_put_zero(info->accur - len, info);
		ft_putnbr_p(arg, info);
	}
	else if (info->accur > ft_mod(info->width) && info->accur > len)
	{
		if (info->width == 0)
			ft_print_zeros_int(info->accur - len - 3, arg, 0, info);
		else
			ft_print_zeros_int(info->accur - len - 3, arg, 0, info);
	}
	else if (info->width < 0 && info->accur < len)
		ft_print_spaces_int(ft_mod(info->width) - len - 3, arg, 1, info);
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

static void		ft_print_zero_hex(t_struct *info, unsigned long arg)
{
	if (info->accur == -2)
	{
		ft_put_space(ft_mod(info->width - 3), info);
		return ;
	}
	else if (info->width > 0 && info->accur <= 1)
	{
		if (info->is_zero)
			ft_print_zeros_int(info->width - 3, arg, 0, info);
		else if (info->accur)
			ft_print_spaces_int(info->width - 3, arg, 0, info);
		else
			ft_put_space(info->width - 3, info);
	}
	else if (info->width < 0 && info->accur == 0)
		ft_put_space(ft_mod(info->width), info);
	else if (info->width < 0 && info->accur < 1)
		ft_print_spaces_int(ft_mod(info->width) - 3, arg, 1, info);
	else if (info->accur > 1 && info->width > info->accur)
	{
		ft_put_space(info->width - info->accur - 3, info);
		ft_put_zero(info->accur, info);
		info->p_len += write(1, "0x0", 3);
	}
	else if (info->accur > ft_mod(info->width) && info->accur > 1)
		ft_print_zeros_int(info->accur - 1, ft_mod(arg), 0, info);
	else if (info->width < 0 && info->accur > 1)
	{
		ft_print_zeros_int(info->accur - 1, arg, 0, info);
		ft_put_space(ft_mod(info->width) - 3 - info->accur, info);
	}
	else if (info->accur == 0)
		return ;
	else
		info->p_len += write(1, "0x0", 3);
}

void			ft_print_adress(t_struct *info)
{
	unsigned long			arg;
	int						len;

	arg = ((unsigned long)va_arg(info->argument, void*));
	len = ft_len_hex(arg);
//	ft_putnbr_fd(len, 1);
//	write(1, "\n", 1);
	if (arg > 0)
		ft_print_positive_hex(info, arg, len);
	else
		ft_print_zero_hex(info, arg);
}

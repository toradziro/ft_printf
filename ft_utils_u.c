/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehillman <ehillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 21:26:07 by ehillman          #+#    #+#             */
/*   Updated: 2020/12/04 21:26:51 by ehillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putnbr_u_fd(unsigned int n, t_struct *info)
{
	char			c;
	unsigned int	nu;

	nu = n;
	if (nu > 9)
	{
		c = nu % 10 + '0';
		ft_putnbr_u_fd(nu / 10, info);
		info->p_len += write(1, &c, 1);
	}
	if (nu <= 9)
	{
		c = nu + '0';
		info->p_len += write(1, &c, 1);
	}
}

void		ft_print_spaces_u(int num, unsigned int arg, int edge,
									t_struct *info)
{
	if (!edge)
	{
		ft_put_space(num, info);
		ft_putnbr_u_fd(arg, info);
	}
	else
	{
		ft_putnbr_u_fd(arg, info);
		ft_put_space(num, info);
	}
}

void		ft_print_zeros_u(int num, unsigned int arg, int edge,
								t_struct *info)
{
	if (!edge)
	{
		ft_put_zero(num, info);
		ft_putnbr_u_fd(arg, info);
	}
	else
	{
		ft_putnbr_u_fd(arg, info);
		ft_put_zero(num, info);
	}
}

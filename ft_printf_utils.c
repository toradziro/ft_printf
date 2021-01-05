/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehillman <ehillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 14:09:40 by ehillman          #+#    #+#             */
/*   Updated: 2020/12/04 21:05:20 by ehillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_put_zero(int n, t_struct *info)
{
	while (n > 0)
	{
		info->p_len += write(1, "0", 1);
		n--;
	}
}

void				ft_put_space(int n, t_struct *info)
{
	while (n > 0)
	{
		info->p_len += write(1, " ", 1);
		n--;
	}
}

long				ft_mod(long n)
{
	return ((n > 0) ? n : -n);
}

int					ft_find_elem(char c)
{
	const char		flags[] = "cspdiuxX%\0";
	int				i;

	i = 0;
	while (flags[i] != '\0')
	{
		if (c == flags[i])
			return ((int)flags[i]);
		i++;
	}
	return (0);
}

void				ft_putnbr_base(unsigned int n, t_struct *info, int alpha)
{
	char			c;
	unsigned int	nu;

	nu = (unsigned int)n;
	if (nu > 9)
	{
		if (nu % 16 >= 0 && nu % 16 <= 9)
			c = nu % 16 + '0';
		else
			c = alpha + (nu % 16 - 10);
		ft_putnbr_base(nu / 16, info, alpha);
		info->p_len += write(1, &c, 1);
	}
	if (nu <= 9 && nu > 0)
	{
		c = nu + '0';
		info->p_len += write(1, &c, 1);
	}
}

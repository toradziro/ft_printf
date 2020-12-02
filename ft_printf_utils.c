/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehillman <ehillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 14:09:40 by ehillman          #+#    #+#             */
/*   Updated: 2020/11/27 21:25:22 by ehillman         ###   ########.fr       */
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

int			ft_len(long long int n)
{
	int				len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int				ft_mod(int n)
{
	return ((n > 0) ? n : -n);
}

int		ft_find_elem(char c)
{
	char	*flags;
	int		i;

	flags = "cspdiuxX%\0";
	i = 0;
	while (flags[i] != '\0')
	{
		if (c == flags[i])
			return ((int)flags[i]);
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehillman <ehillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 14:09:40 by ehillman          #+#    #+#             */
/*   Updated: 2020/11/25 21:26:51 by ehillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_put_zero(int n)
{
	while (n--)
		write(1, "0", 1);
}

void				ft_put_space(int n)
{
	while (n--)
		write(1, " ", 1);
}

int			ft_len(long long int n)
{
	int				len;

	len = 0;
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

	flags = "cspdiuxX%";
	i = 0;
	while (flags[i] != '\0')
	{
		if (c == flags[i])
			return ((int)flags[i]);
		i++;
	}
	return (0);
}

void	ft_putstr(char *s, int n)
{
	if (n == -1)
		while (*s)
		{
			write(1, s, 1);
			s++;
		}
	while (*s && n--)
	{
		write(1, s, 1);
		s++;
	}
}

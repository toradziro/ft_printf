/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehillman <ehillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 13:21:50 by ehillman          #+#    #+#             */
/*   Updated: 2020/11/22 15:02:09 by ehillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static void		ft_print_spaces(int num)
{
	ft_put_space(num);
}

void			ft_print_str(t_struct *info)
{
	int			i;
	char		*arg;

	i = 0;
	arg = va_arg(info->argument, char*);
	if (info->width < ft_strlen(arg))
		ft_putstr(arg, info->accur);
	else if (info->width > 0)
	{
		if (info->accur < ft_strlen(arg))
			ft_print_spaces(info->width - info->accur);
		else
			ft_print_spaces(info->width - ft_strlen(arg));
		ft_putstr(arg, info->accur);
		return ;
	}
	if (info->width < 0)
	{
		ft_putstr(arg, info->accur);
		if (info->accur < ft_strlen(arg))
			ft_print_spaces(-info->width - info->accur);
		else
			ft_print_spaces(-info->width - ft_strlen(arg));
		return ;
	}
}

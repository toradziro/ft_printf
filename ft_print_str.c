/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehillman <ehillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 13:21:50 by ehillman          #+#    #+#             */
/*   Updated: 2020/11/27 00:47:56 by ehillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_print_spaces(int num)
{
	ft_put_space(num);
}

void	ft_putstr(char *s, int n)
{
	if (n == -1)
	{
		while (*s)
		{
			write(1, s, 1);
			s++;
		}
		return ;
	}
	while (*s && n--)
	{
		write(1, s, 1);
		s++;
	}
}

void			ft_print_null(t_struct *info)
{
	if (info->accur == -2)
	{
		ft_print_spaces(ft_mod(info->width));
		return ;
	}
	if (info->width > 0)
	{
		if (info->width > info->accur && info->accur != -1 && info->accur < (int)ft_strlen("(null)"))
			ft_print_spaces(info->width - info->accur);
		else if (info->accur < (int)ft_strlen("(null)"))
			ft_print_spaces(info->width - info->accur - (int)ft_strlen("(null)") - 1);
		else
			ft_print_spaces(info->width - (int)ft_strlen("(null)"));
		ft_putstr("(null)", info->accur);
		return ;
	}
	else if (info->width < 0)
	{
		ft_putstr("(null)", info->accur);
		if (ft_mod(info->width) > info->accur && info->accur != -1 && info->accur < (int)ft_strlen("(null)"))
			ft_print_spaces(ft_mod(info->width) - info->accur);
		else if (info->accur < (int)ft_strlen("(null)"))
			ft_print_spaces(-info->width - info->accur - (int)ft_strlen("(null)") - 1);
		else
			ft_print_spaces(-info->width - (int)ft_strlen("(null)"));
		return ;
	}
	ft_putstr("(null)", info->accur);
}

void			ft_print_str(t_struct *info)
{
	int			i;
	char		*arg;

	i = 0;
	if (!(arg = va_arg(info->argument, char*)))
	{
		ft_print_null(info);
		return ;
	}
	if ((info->accur == -1 && info->width == -1) || info->accur == 0)
		return ;
	if (ft_strlen(arg) == 0 || info->accur == -2)
	{
		ft_print_spaces(ft_mod(info->width));
			return ;
	}
	else if (info->width > 0)
	{
		if (info->width > info->accur && info->accur > 0 && info->accur < (int)ft_strlen(arg))
			ft_print_spaces(info->width - info->accur);
		else if (info->accur < (int)ft_strlen(arg))
			ft_print_spaces(info->width - info->accur - (int)ft_strlen(arg) - 1);
		else
			ft_print_spaces(info->width - (int)ft_strlen(arg));
		ft_putstr(arg, info->accur);
		return ;
	}
	else if (info->width < 0)
	{
		ft_putstr(arg, info->accur);
		if (ft_mod(info->width) > info->accur && info->accur != -1 && info->accur < (int)ft_strlen(arg))
			ft_print_spaces(ft_mod(info->width) - info->accur);
		else if (info->accur < (int)ft_strlen(arg))
			ft_print_spaces(-info->width - info->accur - (int)ft_strlen(arg) - 1);
		else
			ft_print_spaces(-info->width - (int)ft_strlen(arg));
		return ;
	}
	ft_putstr(arg, info->accur);
}

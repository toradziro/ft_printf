/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehillman <ehillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 13:21:50 by ehillman          #+#    #+#             */
/*   Updated: 2020/12/04 21:23:51 by ehillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_print_null_n(t_struct *info, char *a)
{
	if (info->width < 0)
	{
		ft_putstr(a, info->accur, info);
		if (ft_mod(info->width) > info->accur && info->accur != -1 &&
		info->accur < (int)ft_strlen(a))
			ft_put_space(ft_mod(info->width) - info->accur, info);
		else if (info->accur < (int)ft_strlen(a))
			ft_put_space(-info->width - info->accur - (int)ft_strlen(a) -
			1, info);
		else
			ft_put_space(-info->width - (int)ft_strlen(a), info);
		return ;
	}
	ft_putstr(a, info->accur, info);
}

static void		ft_print_null(t_struct *info, char *a)
{
	if (info->accur == 0)
	{
		ft_put_space(ft_mod(info->width), info);
		return ;
	}
	if (info->width > 0)
	{
		if (info->width > info->accur && info->accur != -1 && info->accur <
		(int)ft_strlen(a))
			ft_put_space(info->width - info->accur, info);
		else if (info->accur < (int)ft_strlen(a))
			ft_put_space(info->width - info->accur - (int)ft_strlen(a) -
			1, info);
		else
			ft_put_space(info->width - (int)ft_strlen(a), info);
		ft_putstr(a, info->accur, info);
		return ;
	}
	else
		ft_print_null_n(info, a);
}

static void		ft_print_str_n(t_struct *info, char *arg)
{
	if (info->width < 0)
	{
		ft_putstr(arg, info->accur, info);
		if (ft_mod(info->width) > info->accur && info->accur > -1
		&& info->accur < (int)ft_strlen(arg))
			ft_put_space(ft_mod(info->width) - info->accur, info);
		else if (info->accur < (int)ft_strlen(arg) && info->accur > -1)
			ft_put_space(ft_mod(info->width) - info->accur - (int)
			ft_strlen(arg) - 1, info);
		else
			ft_put_space(ft_mod(info->width) - (int)ft_strlen(arg), info);
		return ;
	}
	else
		ft_putstr(arg, info->accur, info);
}

void			ft_print_str(t_struct *info)
{
	int			i;
	char		*arg;

	i = 0;
	if (!(arg = va_arg(info->argument, char*)))
		ft_print_null(info, "(null)");
	else if (ft_strlen(arg) == 0 || info->accur == 0)
		ft_put_space(ft_mod(info->width), info);
	else if (info->width > 0)
	{
		if (info->width > info->accur && info->accur > 0
		&& info->accur < (int)ft_strlen(arg))
			ft_put_space(info->width - info->accur, info);
		else if (info->accur < (int)ft_strlen(arg) && info->accur > 0)
			ft_put_space(info->width - info->accur -
			(int)ft_strlen(arg) - 1, info);
		else
			ft_put_space(info->width - (int)ft_strlen(arg), info);
		ft_putstr(arg, info->accur, info);
		return ;
	}
	else
		ft_print_str_n(info, arg);
}

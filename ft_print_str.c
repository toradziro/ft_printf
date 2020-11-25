/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehillman <ehillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 13:21:50 by ehillman          #+#    #+#             */
/*   Updated: 2020/11/25 19:58:32 by ehillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_print_spaces(int num)
{
	ft_put_space(num);
}

void			ft_print_str(t_struct *info)
{
	int			i;
	char		*arg;

	i = 0;
	if ((arg = va_arg(info->argument, char*)) == NULL)
		return ;
	if (info->width < (int)ft_strlen(arg))
		ft_putstr(arg, info->accur);
	else if (info->width > 0)
	{
		if (info->accur < (int)ft_strlen(arg))
			ft_print_spaces(info->width - info->accur);
		else
			ft_print_spaces(info->width - (int)ft_strlen(arg));
		ft_putstr(arg, info->accur);
		return ;
	}
	if (info->width < 0)
	{
		ft_putstr(arg, info->accur);
		if (info->accur < (int)ft_strlen(arg))
			ft_print_spaces(-info->width - info->accur);
		else
			ft_print_spaces(-info->width - (int)ft_strlen(arg));
		return ;
	}
}

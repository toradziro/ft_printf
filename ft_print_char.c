/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehillman <ehillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 19:04:40 by ehillman          #+#    #+#             */
/*   Updated: 2020/11/25 20:01:03 by ehillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_print_spaces(int num, t_struct *info)
{
	ft_put_space(num, info);
}

void			ft_print_char(t_struct *info)
{
	int			i;
	char		arg;

	i = 0;
	arg = (char)va_arg(info->argument, int);
	if (info->width > 0)
	{
		ft_print_spaces(info->width - 1, info);
		info->p_len += write(1, &arg, 1);
		return ;
	}
	else if (info->width < 0)
	{
		info->p_len += write(1, &arg, 1);
		ft_print_spaces(ft_mod(info->width) - 1, info);
		return ;
	}
	else
		info->p_len += write(1, &arg, 1);
}

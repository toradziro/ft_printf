/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehillman <ehillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 22:04:10 by ehillman          #+#    #+#             */
/*   Updated: 2020/11/22 14:10:35 by ehillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Если точность больше длины числа и больше или равна ширине, то заполнить не-
 * значащими нулями пространство перед выводимым числом
 * Если точность меньше ширины, но больше длины числа, то заполнить на разницу
 * ширины и точности " " и на разницу точности и длины числа незначащими нулями
 * Ширина 0, точность 15 - заполнение незначащими нулями на точность - длину
*/
#include "ft_printf.h"

static void		ft_print_spaces(int num, t_struct *info, int arg)
{
	int			tmp;

	if (info->accur < ft_len(arg) && num < ft_len(arg))
		return ;
	if (info->accur >= info->width && info->accur > ft_len(arg))
		ft_put_zero(info->accur - ft_len(arg));
	else if (info->accur < info->width && info->accur > ft_len(arg))
	{
			tmp = num - info->accur - ft_len(arg);
			ft_put_space(tmp);
		ft_put_zero(num - tmp);
	}
	else if (info->is_zero == 1)
		ft_put_zero(num);
	else
		ft_put_space(num);
}

void			ft_print_int(t_struct *info)
{
	int			i;
	int			len;
	int			arg;

	i = 0;
	if (info->width > 0 || info->accur > ft_mod(info->width))
	{
		arg = va_arg(info->argument, int);
		ft_print_spaces(info->width - ft_len(arg), info, arg);
		ft_putnbr_fd(arg, 1);
		return ;
	}
	if (info->width < 0)
	{
		arg = va_arg(info->argument, int);
		ft_putnbr_fd(arg, 1);
		ft_print_spaces(-info->width - ft_len(arg), info, arg);
		return ;
	}
	ft_putnbr_fd(va_arg(info->argument, int), 1);
}

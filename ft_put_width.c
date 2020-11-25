/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehillman <ehillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 22:04:10 by ehillman          #+#    #+#             */
/*   Updated: 2020/11/22 11:32:01 by ehillman         ###   ########.fr       */
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

//static int			ft_len(long long int n);

static void		ft_print_spaces(int num, t_struct *info, int arg)
{
	if (info->accur < ft_len(arg) && num < ft_len(arg))
		return ;
	if (info->accur >= info->width && info->accur > ft_len(arg))
	{
		num = info->accur - ft_len(arg);
		while (num--)
			write(1, "0", 1);
	}
	else if (info->accur < info->width && info->accur > ft_len(arg))
	{
		while (num > info->accur - ft_len(arg))
		{
			write(1, " ", 1);
			num--;
		}
		while (num--)
			write(1, "0", 1);
	}
	else if (info->is_zero == 1)
		while (num--)
			write(1, "0", 1);
	else
		while (num--)
			write(1, " ", 1);
}

//static int			ft_len(long long int n)
//{
//	int				len;
//
//	len = 0;
//	if (n < 0)
//		len++;
//	while (n != 0)
//	{
//		n /= 10;
//		len++;
//	}
//	return (len);
//}

//static int			ft_mod(int n)
//{
//	return ((n > 0) ? n : -n);
//}

void			ft_put_width(t_struct *info)
{
	int			i;
	int			len;
	int			arg;

	i = 0;
	if (info->flag == 'd' || info->flag == 'i')
	{
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
}

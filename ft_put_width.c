/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehillman <ehillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 22:04:10 by ehillman          #+#    #+#             */
/*   Updated: 2020/11/18 23:39:50 by ehillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_print_spaces(int num)
{
	while (num--)
		write(1, " ", 1);
}

static int			ft_len(long long int n)
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

void			ft_put_width(va_list argument, t_struct info)
{
	int			i;
	int			len;
	int			arg;

	i = 0;
	if (info.flag == 'd' || info.flag == 'i')
	{
		if (info.width > 0)
		{
			arg = va_arg(argument, int);
			ft_print_spaces(info.width - ft_len(arg));
			ft_putnbr_fd(arg, 1);
			return ;
		}
		if (info.width < 0)
		{
			arg = va_arg(argument, int);
			ft_putnbr_fd(arg, 1);
			ft_print_spaces(-info.width - ft_len(arg));
			return ;
		}
		ft_putnbr_fd(va_arg(argument, int), 1);
	}
}
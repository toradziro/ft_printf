/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehillman <ehillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 20:20:24 by ehillman          #+#    #+#             */
/*   Updated: 2020/12/05 00:44:41 by ehillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_wr_to_sp(const char *str, int i, t_struct *info)
{
	while (str[i] != '%' && str[i] != '\0')
	{
		info->p_len += write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int				ft_printf(const char *str, ...)
{
	int			i;
	t_struct	info;

	i = 0;
	info.p_len = 0;
	va_start(info.argument, str);
	while (str[i] != '\0')
	{
		i = ft_wr_to_sp(str, i, &info);
		if (str[i] == '\0')
			break ;
		if (str[i] == '%')
		{
			i++;
			info = ft_parse(&str[i], &info);
			ft_check_spec(&info);
		}
		while (!ft_find_elem(str[i]) && str[i + 1] != '\0')
			i++;
		i++;
	}
	va_end(info.argument);
	return (info.p_len);
}

void			ft_check_spec(t_struct *info)
{
	if (info->flag == 'i' || info->flag == 'd')
		ft_print_int(info);
	else if (info->flag == 's')
		ft_print_str(info);
	else if (info->flag == 'c')
		ft_print_char(info);
	else if (info->flag == 'x')
		ft_print_hex_low(info);
	else if (info->flag == 'X')
		ft_print_hex_up(info);
	else if (info->flag == 'p')
		ft_print_adress(info);
	else if (info->flag == 'u')
		ft_print_unsigned(info);
	else if (info->flag == '%')
		ft_print_percent(info);
}
